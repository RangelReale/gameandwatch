#include "devices/dev_dkong.h"

GW_Game *GW_Game_DKong_Info::create()
{
    return new GW_Game_DKong;
}


GW_Game_DKong::GW_Game_DKong() :
    GW_Game()
{
    gamepath_set("dkong");
    size_set(464, 571);

    // game screen position
    //GW_PLATFORM_RECT(gr, 125, 78, 212, 412);
    GW_PLATFORM_RECT(gr, 125, 349, 214, 139);
    gamerect_set(gr);

/*
    // second screen
    GW_PLATFORM_RECT(gr, 125, 177, 213, 139);
    gamerect_set(gr);
*/
    char sname[50];


    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // bg
    data().
        image_add(IM_BG, GW_INDEX_DEFAULT, "bg.bmp", &tcolor_bg);

    // numbers
    data().
        position_add(PS_NUMBER, 1, 274, 468)->
        position_add(PS_NUMBER, 2, 286, 468)->
        position_add(PS_NUMBER, 3, 304, 468)->
        position_add(PS_NUMBER, 4, 316, 468)->
        position_add(PS_SEMICOLON, 0, 298, 472, IM_SEMICOLON, 0, "time_pp.bmp", &tcolor_img);

    for (int i=0; i<10; i++)
    {
        sprintf(sname, "num%d.bmp", i);
        data().image_add(IM_NUMBER, i, sname, &tcolor_img);
    }

    display_number(1, 1, false);
    display_number(2, 2, false);
    display_number(3, 9, false);
    display_number(4, 9, false);

    // options
    data().
        position_add(PS_GAMEA, GW_INDEX_DEFAULT, 302, 384, IM_GAMEA, GW_INDEX_DEFAULT, "game_a.bmp", &tcolor_img)->
        position_add(PS_GAMEB, GW_INDEX_DEFAULT, 302, 394, IM_GAMEB, GW_INDEX_DEFAULT, "game_b.bmp", &tcolor_img)->
        position_add(PS_ALARM, GW_INDEX_DEFAULT, 302, 402, IM_ALARM, GW_INDEX_DEFAULT, "alarm.bmp", &tcolor_img)->
        position_add(PS_AM, GW_INDEX_DEFAULT, 263, 468, IM_AM, GW_INDEX_DEFAULT, "time_am.bmp", &tcolor_img)->
        position_add(PS_PM, GW_INDEX_DEFAULT, 263, 478, IM_PM, GW_INDEX_DEFAULT, "time_pm.bmp", &tcolor_img);

    // sounds
    data().
        sound_add(SND_BARREL, "barrel.wav")->
        sound_add(SND_BONUS, "bonus.wav")->
        sound_add(SND_FALL, "fall.wav")->
        sound_add(SND_JUMP, "jump.wav")->
        sound_add(SND_KONGFALL, "kongfall.wav")->
        sound_add(SND_MISS, "miss.wav")->
        sound_add(SND_OVER, "over.wav")->
        sound_add(SND_STEP, "step.wav");

    // timers
/*
    data().
        timer_add(TMR_GAME, 250, true)->
        timer_add(TMR_GAMESTART, 1800, false)->
        timer_add(TMR_REPRISE, 1100, false)->
        timer_add(TMR_GAMEOVER, 100, false)->
        timer_add(TMR_GAMEOVERSOUND, 3500, false)->
        timer_add(TMR_GAMEOVERWAIT, 30000, false);
*/
}

void GW_Game_DKong::Event(GW_Platform_Event *event)
{
    GW_Game::Event(event);
}

void GW_Game_DKong::do_turnon()
{
    SetMode(MODE_IDLE);
}

void GW_Game_DKong::do_turnoff()
{
    SetMode(MODE_OFF);
}

bool GW_Game_DKong::do_setmode(int mode)
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
        display_number(1, 1, false);
        display_number(2, 2, false);
        display_number(3, 0, false);
        display_number(4, 0, false);
        break;
    case MODE_GAMEA:
    case MODE_GAMEB:
/*
        if ((GetMode()!=MODE_GAMEA&&GetMode()!=MODE_GAMEB))
            do_game_start(mode);
*/
        break;
    case MODE_TIME:
        data_stopalltimers();
        data_hideall(true);
        //data().position_get(PS_TIME1)->show();
        clock_update(mode);
        break;
    case MODE_ALARM:
        data_stopalltimers();
        data_hideall(true);
        data().position_get(PS_ALARM)->show();
        clock_update(mode);
        break;
    default:
        return false;
        break;
    }
    return true;
}

void GW_Game_DKong::do_update()
{
    if (GetMode()==MODE_TIME)
        clock_update();
}

void GW_Game_DKong::clock_update(int mode)
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

    data().position_get(PS_SEMICOLON)->visible_set(time.s % 2 == 0);
    if (mode==MODE_TIME)
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
    }
}

void GW_Game_DKong::setnumber(int n, int ps1, int ps2, bool leadzero)
{
    // set a number on the display
    if (n>=0 && n<=99)
    {
        if (n>10)
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

void GW_Game_DKong::display_number(int pos, int n, bool show)
{
    if (n>=0 && n<=9)
    {
        if (show)
            data().position_get(PS_NUMBER, pos)->show();
        data().position_get(PS_NUMBER, pos)->image_set(IM_NUMBER, n);
    }
    else if (show)
        data().position_get(PS_NUMBER, pos)->hide();
}
