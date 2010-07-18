#include <cstdio>
#include "devices/deveng_vtech.h"

GW_GameEngine_VTech::GW_GameEngine_VTech(int engineoptions) :
    GW_Game(), engineoptions_(engineoptions), mode_(MODE_OFF), gameover_(true)
{
    char sname[50];

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // bg
    data().
        image_add(IM_BG, GW_INDEX_DEFAULT, "bg.bmp", &tcolor_bg);

    // numbers
    data().
        position_add(PS_NUMBER, 1, 250, 61)->
        position_add(PS_NUMBER, 2, 265, 61)->
        position_add(PS_NUMBER, 3, 284, 61)->
        position_add(PS_NUMBER, 4, 299, 61)->
        position_add(PS_SEMICOLON, 0, 280, 67, IM_SEMICOLON, 0, "im_time_semicolon.bmp", &tcolor_img);

    int nmax=10;
    if ((engineoptions_&EO_NUMBERSEPARATED)==EO_NUMBERSEPARATED)
        nmax=40;

    for (int i=0; i<nmax; i++)
    {
        if ((engineoptions_&EO_NUMBERSEPARATED)==EO_NUMBERSEPARATED)
            sprintf(sname, "im_number_%d_%d.bmp", (i/10)+1, i%10);
        else
            sprintf(sname, "im_number_%d.bmp", i);
        data().image_add(IM_NUMBER, i, sname, &tcolor_img);
    }

    display_number(1, 8, false);
    display_number(2, 8, false);
    display_number(3, 8, false);
    display_number(4, 8, false);

    // miss
    data().
        position_add(PS_MISS, 1, 330, 62)->
        position_add(PS_MISS, 2, 343, 62)->
        position_add(PS_MISS, 3, 356, 62)->
        position_add(PS_MISS, 4, 371, 62)->
        position_add(PS_MISS, 5, 385, 62)->
        position_add(PS_MISS, 6, 329, 80)->
        position_add(PS_MISS, 7, 344, 80)->
        position_add(PS_MISS, 8, 356, 80)->
        position_add(PS_MISS, 9, 371, 80)->
        position_add(PS_MISS, 10, 383, 80);

    if ((engineoptions_&EO_MISSSEPARATED)!=EO_MISSSEPARATED)
        data().image_add(IM_MISS, GW_INDEX_DEFAULT, "im_miss.bmp", &tcolor_img);

    for (int i=1; i<=10; i++)
    {
        if ((engineoptions_&EO_MISSSEPARATED)==EO_MISSSEPARATED)
        {
            sprintf(sname, "im_miss_%02d.bmp", i);
            data().image_add(IM_MISS, i, sname, &tcolor_img);
        }
        data().position_get(PS_MISS, i)->image_set(IM_MISS, ((engineoptions_&EO_MISSSEPARATED)==EO_MISSSEPARATED?i:GW_INDEX_DEFAULT));
    }

    // options
    data().
        position_add(PS_GAMEA, 0, 153, 61, IM_GAMEA, GW_INDEX_DEFAULT, "im_game_a.bmp", &tcolor_img)->
        position_add(PS_GAMEB, 0, 153, 76, IM_GAMEB, GW_INDEX_DEFAULT, "im_game_b.bmp", &tcolor_img)->
        position_add(PS_ALARM, 0, 200, 77, IM_ALARM, GW_INDEX_DEFAULT, "im_alarm.bmp", &tcolor_img)->
        position_add(PS_BELL, 0, 179, 63, IM_BELL, GW_INDEX_DEFAULT, "im_bell.bmp", &tcolor_img)->
        position_add(PS_CHRONO, 0, 217, 77, IM_CHRONO, GW_INDEX_DEFAULT, "im_chrono.bmp", &tcolor_img)->
        position_add(PS_DATE, 0, 232, 77, IM_DATE, GW_INDEX_DEFAULT, "im_date.bmp", &tcolor_img)->
        position_add(PS_TIME1, 0, 223, 61, IM_TIME1, GW_INDEX_DEFAULT, "im_time_1.bmp", &tcolor_img)->
        position_add(PS_TIME2, 0, 200, 61, IM_TIME2, GW_INDEX_DEFAULT, "im_time_2.bmp", &tcolor_img)->
        position_add(PS_AM, 0, 315, 61, IM_AM, GW_INDEX_DEFAULT, "im_time_am.bmp", &tcolor_img)->
        position_add(PS_PM, 0, 314, 76, IM_PM, GW_INDEX_DEFAULT, "im_time_pm.bmp", &tcolor_img);

    // timers
    data().
        timer_add(TMR_GAME, 250, true)->
        timer_add(TMR_GAMESTART, 1800, false)->
        timer_add(TMR_REPRISE, 1100, false)->
        timer_add(TMR_GAMEOVER, 100, false)->
        timer_add(TMR_GAMEOVERSOUND, 3500, false)->
        timer_add(TMR_GAMEOVERWAIT, 30000, false);
}

void GW_GameEngine_VTech::Event(GW_Platform_Event *event)
{
    if (event->id==GPE_KEYDOWN)
    {
        switch (event->data)
        {
        case GPK_GAMEA:
            if (GetMode()==MODE_IDLE)
                SetMode(MODE_TIME1);
            else
                SetMode(MODE_GAMEA);
            break;
        case GPK_GAMEB:
            if (GetMode()==MODE_IDLE)
                SetMode(MODE_TIME1);
            else
                SetMode(MODE_GAMEB);
            break;
        case GPK_TIME:
            if (GetMode()==MODE_TIME1)
                SetMode(MODE_TIME2);
            else if (GetMode()==MODE_TIME2)
                SetMode(MODE_ALARM);
            else if (GetMode()==MODE_ALARM)
                SetMode(MODE_CHRONO);
            else if (GetMode()==MODE_CHRONO)
                SetMode(MODE_DATE);
            else if (GetMode()==MODE_DATE||gameover_)
                SetMode(MODE_TIME1);
            break;
        }
    }
}

void GW_GameEngine_VTech::do_timer(int timerid)
{
    switch (timerid)
    {
    case TMR_GAMESTART:
        data_starttimer(TMR_GAME);
        break;
    case TMR_GAME:
        game_tick();
        break;
    case TMR_REPRISE:
        game_reprise();
        canmove_=true;
        data_starttimer(TMR_GAME);
        break;
    case TMR_GAMEOVER:
        // game is over: play "Game Over" tune, then freeze for 30 seconds, and finally
        // change mode to "Time 1", if no button is pressed
        game_over();


        data_starttimer(TMR_GAMEOVERSOUND);
        data_starttimer(TMR_GAMEOVERWAIT);
        break;
    case TMR_GAMEOVERSOUND:
        gameover_=true;
        break;
    case TMR_GAMEOVERWAIT:
        //gameover_=true;
        SetMode(MODE_TIME1);
        break;
    }
}

void GW_GameEngine_VTech::do_update()
{
    if (GetMode()==MODE_TIME1 || GetMode()==MODE_TIME2 || GetMode()==MODE_ALARM || GetMode()==MODE_DATE)
        clock_update();
}

void GW_GameEngine_VTech::do_turnon()
{
    SetMode(MODE_IDLE);
}

void GW_GameEngine_VTech::do_turnoff()
{
    SetMode(MODE_OFF);
}

void GW_GameEngine_VTech::do_game_start(int mode)
{
    data_hideall(true);

    score_=0;

    data().position_get((mode==MODE_GAMEA?PS_GAMEA:PS_GAMEB))->show();

    score_update();

    misses_=0;
    canmove_=true;
    gameover_=false;

    miss_update();
    level_update(mode);

    game_start(mode);

    data_starttimer(TMR_GAMESTART);
}

void GW_GameEngine_VTech::game_tick()
{

}

void GW_GameEngine_VTech::score_update()
{
    int p=score_;
    while (p>=10000) p-=10000;
    for (int i=1; i<=4; i++) data().position_get(PS_NUMBER, i)->hide();

    if (p>999) display_number(1, p / 1000);
    if (p>99) display_number(2, p / 100 % 10);
    if (p>9) display_number(3, p / 10 % 10);
    if (p>=0) display_number(4, p % 10 % 10);
}

void GW_GameEngine_VTech::level_update(int mode)
{
}

void GW_GameEngine_VTech::miss_update()
{
    for (int i=1; i<=10; i++)
    {
        data().position_get(PS_MISS, i)->visible_set(misses_>=i);
    }
}

bool GW_GameEngine_VTech::do_setmode(int mode)
{
    switch (mode)
    {
    case MODE_OFF:
        data_stopalltimers();
        data_stopallsounds();
        data_hideall(true);
        break;
    case MODE_IDLE:
        data_stopalltimers();
        data_showall();
        // reset numbers
        display_number(1, 8, false);
        display_number(2, 8, false);
        display_number(3, 8, false);
        display_number(4, 8, false);
        gameover_=true;
        break;
    case MODE_GAMEA:
    case MODE_GAMEB:
        if ((GetMode()!=MODE_GAMEA&&GetMode()!=MODE_GAMEB)||gameover_)
            do_game_start(mode);
        break;
    case MODE_TIME1:
        data_stopalltimers();
        data_hideall(true);
        data().position_get(PS_TIME1)->show();
        clock_update(mode);
        break;
    case MODE_TIME2:
        data_stopalltimers();
        data_hideall(true);
        data().position_get(PS_TIME2)->show();
        clock_update(mode);
        break;
    case MODE_ALARM:
        data_stopalltimers();
        data_hideall(true);
        data().position_get(PS_ALARM)->show();
        clock_update(mode);
        break;
    case MODE_CHRONO:
        data_stopalltimers();
        data_hideall(true);
        data().position_get(PS_CHRONO)->show();
        clock_update(mode);
        break;
    case MODE_DATE:
        data_stopalltimers();
        data_hideall(true);
        data().position_get(PS_DATE)->show();
        clock_update(mode);
        break;
    default:
        return false;
        break;
    }
    return true;
}


void GW_GameEngine_VTech::clock_update(int mode)
{
    if (mode==-1) mode=GetMode();

    // display clock
    data().position_get(PS_NUMBER, 1)->show();
    data().position_get(PS_NUMBER, 2)->show();
    data().position_get(PS_NUMBER, 3)->show();
    data().position_get(PS_NUMBER, 4)->show();


    GW_Platform_Time time=platform_get()->time_get();

    //GW_Device::devtime_t time;
    //device_get()->GetTime(&time);

    if (mode!=MODE_CHRONO)
        data().position_get(PS_SEMICOLON)->visible_set(time.s % 2 == 0);
    if (mode==MODE_TIME1 || mode==MODE_TIME2)
    {
        // show current time
        data().position_get(PS_AM)->visible_set(time.h<12);
        data().position_get(PS_PM)->visible_set(time.h>=12);

        setnumber((time.h>12?time.h-12:time.h), 1, 2, false);
        setnumber(time.n, 3, 4);
    } else if (mode==MODE_ALARM) {
        // show 12:00 AM
        data().position_get(PS_AM)->show();
        setnumber(12, 1, 2);
        setnumber(0, 3, 4);
    } else if (mode==MODE_CHRONO) {
        // show 00:00
        data().position_get(PS_SEMICOLON)->show();
        setnumber(0, 1, 2);
        setnumber(0, 3, 4);
    } else if (mode==MODE_DATE) {
        // show day and month
        setnumber(time.d, 1, 2, false);
        setnumber(time.m, 3, 4, false);
    }
}

void GW_GameEngine_VTech::setnumber(int n, int ps1, int ps2, bool leadzero)
{
    // set a number on the display
    if (n>=0 && n<=99)
    {
        if (n>=10)
        {
            display_number(ps1, n / 10);
            display_number(ps2, n % 10);
        }
        else
        {
            if (leadzero)
                display_number(ps1, 0);
            else
                display_number(ps1, -1);
            display_number(ps2, n);
        }
    }
}

void GW_GameEngine_VTech::display_number(int pos, int n, bool show)
{
    if (n>=0 && n<=9)
    {
        if ((engineoptions_&EO_NUMBERSEPARATED)==EO_NUMBERSEPARATED)
            n=n+((pos-1)*10);

        if (show)
            data().position_get(PS_NUMBER, pos)->show();
        data().position_get(PS_NUMBER, pos)->image_set(IM_NUMBER, n);
    }
    else if (show)
        data().position_get(PS_NUMBER, pos)->hide();
}

void GW_GameEngine_VTech::score_add(int count)
{
    score_+=count;
    if (score_>9999) score_-=10000;
    score_update();
    level_update();
}

void GW_GameEngine_VTech::misses_add(int count)
{
    misses_+=count;
    miss_update();
}
