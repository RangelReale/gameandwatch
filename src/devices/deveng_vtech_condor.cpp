#include "devices/deveng_vtech_condor.h"

GW_GameEngine_VTech_Condor::GW_GameEngine_VTech_Condor(int options) :
    GW_Game(), options_(options), mode_(MODE_OFF), gameover_(true)
{
    // "CONDOR" is default

    gamepath_set("condor");
    size_set(562, 373);

    // game screen position
    GW_PLATFORM_RECT(gr, 151, 52, 257, 192);
    gamerect_set(gr);

    char sname[50];

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // bg
    data().
        image_add(IM_BG, GW_INDEX_DEFAULT, "bg.bmp", &tcolor_bg);

    // character
    data().
        position_add(PS_CHAR, 1, 206, 200, IM_CHAR, 1, "char_1.bmp", &tcolor_img)->
        position_add(PS_CHAR, 2, 250, 200, IM_CHAR, 2, "char_2.bmp", &tcolor_img)->
        position_add(PS_CHAR, 3, 315, 203, IM_CHAR, 3, "char_3.bmp", &tcolor_img);

    // item
    if ((options_&GO_HAVEITEM0)==GO_HAVEITEM0)
        data().
            position_add(PS_ITEM, 0, 352, 93, IM_ITEM, 0, "item_00.bmp", &tcolor_img);

    data().
        position_add(PS_ITEM, 1, 345, 107, IM_ITEM, 1, "item_01.bmp", &tcolor_img)->
        position_add(PS_ITEM, 2, 342, 118, IM_ITEM, 2, "item_02.bmp", &tcolor_img)->
        position_add(PS_ITEM, 3, 342, 131, IM_ITEM, 3, "item_03.bmp", &tcolor_img)->
        position_add(PS_ITEM, 4, 342, 146, IM_ITEM, 4, "item_04.bmp", &tcolor_img)->
        position_add(PS_ITEM, 5, 341, 153, IM_ITEM, 5, "item_05.bmp", &tcolor_img)->
        position_add(PS_ITEM, 6, 337, 165, IM_ITEM, 6, "item_06.bmp", &tcolor_img)->
        position_add(PS_ITEM, 7, 335, 182, IM_ITEM, 7, "item_07.bmp", &tcolor_img)->
        position_add(PS_ITEM, 8, 318, 166, IM_ITEM, 8, "item_08.bmp", &tcolor_img)->
        position_add(PS_ITEM, 9, 307, 135, IM_ITEM, 9, "item_09.bmp", &tcolor_img)->
        position_add(PS_ITEM, 10, 297, 119, IM_ITEM, 10, "item_10.bmp", &tcolor_img)->
        position_add(PS_ITEM, 11, 295, 100, IM_ITEM, 11, "item_11.bmp", &tcolor_img)->
        position_add(PS_ITEM, 12, 277, 88, IM_ITEM, 12, "item_12.bmp", &tcolor_img)->
        position_add(PS_ITEM, 13, 274, 111, IM_ITEM, 13, "item_13.bmp", &tcolor_img)->
        position_add(PS_ITEM, 14, 272, 127, IM_ITEM, 14, "item_14.bmp", &tcolor_img)->
        position_add(PS_ITEM, 15, 275, 143, IM_ITEM, 15, "item_15.bmp", &tcolor_img)->
        position_add(PS_ITEM, 16, 278, 159, IM_ITEM, 16, "item_16.bmp", &tcolor_img)->
        position_add(PS_ITEM, 17, 255, 170, IM_ITEM, 17, "item_17.bmp", &tcolor_img)->
        position_add(PS_ITEM, 18, 246, 142, IM_ITEM, 18, "item_18.bmp", &tcolor_img)->
        position_add(PS_ITEM, 19, 240, 114, IM_ITEM, 19, "item_19.bmp", &tcolor_img)->
        position_add(PS_ITEM, 20, 225, 100, IM_ITEM, 20, "item_20.bmp", &tcolor_img)->
        position_add(PS_ITEM, 21, 222, 133, IM_ITEM, 21, "item_21.bmp", &tcolor_img)->
        position_add(PS_ITEM, 22, 217, 146, IM_ITEM, 22, "item_22.bmp", &tcolor_img)->
        position_add(PS_ITEM, 23, 220, 168, IM_ITEM, 23, "item_23.bmp", &tcolor_img)->
        position_add(PS_ITEM, 24, 198, 171, IM_ITEM, 24, "item_24.bmp", &tcolor_img)->
        position_add(PS_ITEM, 25, 194, 145, IM_ITEM, 25, "item_25.bmp", &tcolor_img)->
        position_add(PS_ITEM, 26, 196, 121, IM_ITEM, 26, "item_26.bmp", &tcolor_img)->
        position_add(PS_ITEM, 27, 188, 102, IM_ITEM, 27, "item_27.bmp", &tcolor_img)->
        position_add(PS_ITEM, IDX_MISS_1, 167, 191, IM_ITEM, IDX_MISS_1, "miss_1.bmp", &tcolor_img)->
        position_add(PS_ITEM, IDX_MISS_2, 277, 186, IM_ITEM, IDX_MISS_2, "miss_2.bmp", &tcolor_img)->
        position_add(PS_ITEM, IDX_MISS_3, 354, 189, IM_ITEM, IDX_MISS_3, "miss_3.bmp", &tcolor_img);

    // item left
    if ((options_&GO_HAVELEFT0)==GO_HAVELEFT0)
        data().
            position_add(PS_ITEMLEFT, 0, 210, 221, IM_ITEMLEFT, 0, "item_left_0.bmp", &tcolor_img);
    data().
        position_add(PS_ITEMLEFT, 1, 158, 144, IM_ITEMLEFT, 1, "item_left_1.bmp", &tcolor_img)->
        position_add(PS_ITEMLEFT, 2, 159, 94, IM_ITEMLEFT, 2, "item_left_2.bmp", &tcolor_img);

    // item right
    if ((options_&GO_HAVERIGHT1A)==GO_HAVERIGHT1A)
    {
        data().
            position_add(PS_ITEMRIGHT, 1, 210, 221, IM_ITEMRIGHT, 1, "item_right_1a.bmp", &tcolor_img)->
            position_add(PS_ITEMRIGHT, IDX_RIGTH_1B, 210, 221, IM_ITEMRIGHT, IDX_RIGTH_1B, "item_right_1b.bmp", &tcolor_img);
    }
    else
        data().
            position_add(PS_ITEMRIGHT, 1, 374, 117, IM_ITEMRIGHT, 1, "item_right_1.bmp", &tcolor_img);

    data().
        position_add(PS_ITEMRIGHT, 2, 389, 106, IM_ITEMRIGHT, 2, "item_right_2.bmp", &tcolor_img)->
        position_add(PS_ITEMRIGHT, 3, 384, 105, IM_ITEMRIGHT, 3, "item_right_3.bmp", &tcolor_img)->
        position_add(PS_ITEMRIGHT, 4, 375, 106, IM_ITEMRIGHT, 4, "item_right_4.bmp", &tcolor_img);

    if ((options_&GO_HAVERIGHT6)==GO_HAVERIGHT6)
        data().
            position_add(PS_ITEMRIGHT, 5, 210, 221, IM_ITEMRIGHT, 5, "item_right_5.bmp", &tcolor_img)->
            position_add(PS_ITEMRIGHT, 6, 210, 221, IM_ITEMRIGHT, 6, "item_right_6.bmp", &tcolor_img);


    // numbers
    data().
        position_add(PS_NUMBER, 1, 248, 54)->
        position_add(PS_NUMBER, 2, 263, 54)->
        position_add(PS_NUMBER, 3, 283, 54)->
        position_add(PS_NUMBER, 4, 298, 54)->
        position_add(PS_SEMICOLON, 0, 278, 59, IM_SEMICOLON, 0, "panel_time_semicolon.bmp", &tcolor_img);

    for (int i=0; i<10; i++)
    {
        sprintf(sname, "panel_number_%d.bmp", i);
        data().image_add(IM_NUMBER, i, sname, &tcolor_img);
    }

    display_number(1, 8, false);
    display_number(2, 8, false);
    display_number(3, 8, false);
    display_number(4, 8, false);

    // miss
    data().image_add(IM_MISS, 0, "panel_miss.bmp", &tcolor_img);

    data().
        position_add(PS_MISS, 1, 336, 51, IM_MISS)->
        position_add(PS_MISS, 2, 349, 51, IM_MISS)->
        position_add(PS_MISS, 3, 362, 51, IM_MISS)->
        position_add(PS_MISS, 4, 375, 51, IM_MISS)->
        position_add(PS_MISS, 5, 388, 51, IM_MISS)->
        position_add(PS_MISS, 6, 336, 67, IM_MISS)->
        position_add(PS_MISS, 7, 349, 67, IM_MISS)->
        position_add(PS_MISS, 8, 362, 67, IM_MISS)->
        position_add(PS_MISS, 9, 375, 67, IM_MISS)->
        position_add(PS_MISS, 10, 388, 67, IM_MISS);

    // options
    data().
        position_add(PS_GAMEA, 0, 158, 54, IM_GAMEA, GW_INDEX_DEFAULT, "panel_game_a.bmp", &tcolor_img)->
        position_add(PS_GAMEB, 0, 158, 70, IM_GAMEB, GW_INDEX_DEFAULT, "panel_game_b.bmp", &tcolor_img)->
        position_add(PS_ALARM, 0, 200, 70, IM_ALARM, GW_INDEX_DEFAULT, "panel_alarm.bmp", &tcolor_img)->
        position_add(PS_BELL, 0, 184, 56, IM_BELL, GW_INDEX_DEFAULT, "panel_bell.bmp", &tcolor_img)->
        position_add(PS_CHRONO, 0, 218, 70, IM_CHRONO, GW_INDEX_DEFAULT, "panel_chrono.bmp", &tcolor_img)->
        position_add(PS_DATE, 0, 231, 70, IM_DATE, GW_INDEX_DEFAULT, "panel_date.bmp", &tcolor_img)->
        position_add(PS_TIME1, 0, 224, 54, IM_TIME1, GW_INDEX_DEFAULT, "panel_time_1.bmp", &tcolor_img)->
        position_add(PS_TIME2, 0, 201, 54, IM_TIME2, GW_INDEX_DEFAULT, "panel_time_2.bmp", &tcolor_img)->
        position_add(PS_AM, 0, 318, 54, IM_AM, GW_INDEX_DEFAULT, "panel_time_am.bmp", &tcolor_img)->
        position_add(PS_PM, 0, 318, 69, IM_PM, GW_INDEX_DEFAULT, "panel_time_pm.bmp", &tcolor_img);

    // sounds
    data().
        sound_add(SND_GAMEOVER, "Gameover.wav")->
        sound_add(SND_GOT, "Got.wav")->
        sound_add(SND_MISS, "Miss.wav")->
        sound_add(SND_MOVE, "Move.wav")->
        sound_add(SND_START, "Start.wav");

    // timers
    data().
        timer_add(TMR_GAME, 250, true)->
        timer_add(TMR_GAMESTART, 1800, false)->
        timer_add(TMR_HIT, 100, false)->
        timer_add(TMR_REPRISE, 1100, false)->
        timer_add(TMR_GAMEOVER, 100, false)->
        timer_add(TMR_GAMEOVERSOUND, 3500, false)->
        timer_add(TMR_GAMEOVERWAIT, 30000, false);
}

void GW_GameEngine_VTech_Condor::Event(GW_Platform_Event *event)
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
        case GPK_LEFT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_)
            {
                char_position_-=1;
                if (char_position_<0) char_position_=0;
                char_update(char_position_, false);
                //game_update();
            }
            break;
        case GPK_RIGHT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_)
            {
                char_position_+=1;
                if (char_position_>2) char_position_=2;
                char_update(char_position_, false);
                //game_update();
            }
            break;
        }
    }
}

void GW_GameEngine_VTech_Condor::do_timer(int timerid)
{
    switch (timerid)
    {
    case TMR_GAMESTART:
        data_starttimer(TMR_GAME);
        break;
    case TMR_GAME:
        game_tick();
        break;
    case TMR_HIT:
        char_update(char_position_, false);
        break;
    case TMR_REPRISE:
        showall_miss(false);
        showall_target(true);
        canmove_=true;
        data_starttimer(TMR_GAME);
        break;
    case TMR_GAMEOVER:
        // game is over: play "Game Over" tune, then freeze for 30 seconds, and finally
        // change mode to "Time 1", if no button is pressed
        data_playsound(SND_GAMEOVER);
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

void GW_GameEngine_VTech_Condor::do_update()
{
    if (GetMode()==MODE_TIME1 || GetMode()==MODE_TIME2 || GetMode()==MODE_ALARM || GetMode()==MODE_DATE)
        clock_update();
}

void GW_GameEngine_VTech_Condor::do_turnon()
{
    SetMode(MODE_IDLE);
}

void GW_GameEngine_VTech_Condor::do_turnoff()
{
    SetMode(MODE_OFF);
}

void GW_GameEngine_VTech_Condor::game_start(int mode)
{
    data_hideall();

    score_=0;
    char_position_=1; // middle

    data().position_get((mode==MODE_GAMEA?PS_GAMEA:PS_GAMEB))->show();

    if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
    {
        data().position_get(PS_ITEM, IDX_TARGET)->show();
        data().position_get(PS_ITEM, IDX_TARGET)->show();
        data().position_get(PS_ITEM, IDX_TARGET)->show();
    }

    game_update();
    score_update();

    tick_=0;
    maxonscreen_=1;
    misses_=0;
    canmove_=true;
    gameover_=false;

    char_update(char_position_, false);
    miss_update();
    level_update(mode);

    data_playsound(SND_START);
    data_starttimer(TMR_GAMESTART);
}

void GW_GameEngine_VTech_Condor::game_update()
{
    //char_update(char_position_, false);
}

void GW_GameEngine_VTech_Condor::game_tick()
{
    // blink the semicolon on tick
    //data().position_get(PS_SEMICOLON)->visible_set(!data().position_get(PS_SEMICOLON)->visible_get());

    int iMistake=-1, iGot=-1, iMoved=0;

    // current tick
    int prevtick=tick_-1;
    if (prevtick<0) prevtick=2;

    // keeps and then removes "got" items
    for (int i=PS_ITEM; i<=PS_ITEM; i++)
    {
        if (data().position_get(i, IDX_GOT)->visible_get())
            data().position_get(i, IDX_GOT)->hide();
        if (data().position_get(i, IDX_HIT)->visible_get())
        {
            data().position_get(i, IDX_HIT)->hide();
            data().position_get(i, IDX_GOT)->show();
        }
        else
            data().position_get(i, IDX_GOT)->hide();
    }

    // checks for mistakes
    for (int i=PS_ITEM; i<=PS_ITEM; i++)
    {
        if (data().position_get(i, IDX_MAX)->visible_get() && char_position_ != i-PS_ITEM)
        {
            data().position_get(i, IDX_MAX)->hide();
            data().position_get(i, IDX_MISS)->hide();
            iMistake=i-PS_ITEM;
        }
    }

    // checks for collisions character-items on certain positions and manages 'hit' animation of main character
    if (iMistake==-1 && data().position_get(PS_ITEM+char_position_, IDX_MAX)->visible_get())
    {
        char_update(char_position_, true);
        data_starttimer(TMR_HIT);
        data().position_get(PS_ITEM+char_position_, IDX_MAX)->hide();
        data().position_get(PS_ITEM+char_position_, IDX_GOT)->hide();
        data().position_get(PS_ITEM+char_position_, IDX_HIT)->show();
        score_++;
        if (score_>9999) score_-=10000;
        score_update();
        level_update();
        iGot=char_position_;
        data_delaytimer(TMR_GAME, 60); // when hit, delay the game a little to allow for moving
    }

    // moves and generates items
    if (iMistake==-1)
    {
        // moves items
        for (int i=5; i>1; i--)
            data().position_get(PS_ITEM+tick_, i)->visible_set(data().position_get(PS_ITEM+tick_, i-1)->visible_get());
        data().position_get(PS_ITEM+tick_, 1)->hide();

        // generates new items
        int iOnScreen=0;
        for (int i=PS_ITEM; i<=PS_ITEM; i++)                                   // counts items on screen
            for (int j=1; j<=IDX_MAX; j++)
                if (data().position_get(i, j)->visible_get())
                    iOnScreen++;
        if (rand() % 4 == 0) data().position_get(PS_ITEM+tick_, 1)->show();      // generates randomly
        else data().position_get(PS_ITEM+tick_, 1)->hide();
        if (iOnScreen == 0) data().position_get(PS_ITEM+tick_, 1)->show();       // generates if none on screen
        if (data().position_get(PS_ITEM+tick_, 2)->visible_get())                // prevents from generating if one just appeared on the same column
            data().position_get(PS_ITEM+tick_, 1)->hide();

        if (data().position_get(PS_ITEM+prevtick, 1)->visible_get())             // prevents from generating if one just appeared on previous column
            data().position_get(PS_ITEM+tick_, 1)->hide();
        if (iOnScreen>=maxonscreen_)                                               // prevents from generating if more onscreen items than allowed
            data().position_get(PS_ITEM+tick_, 1)->hide();

        // gets ready to play "MOVE" sound
        for (int i=1; i<=IDX_MAX; i++)
            if (data().position_get(PS_ITEM+tick_, i)->visible_get())
                iMoved++;
    }

    // executes miss routine, counts misses and reprises or goes to "game over"
    if (iMistake!=-1)    // checks if any miss just occured
    {
        canmove_=false;
        data_stopalltimers();

        data().position_get(PS_ITEM+iMistake, IDX_MISS)->show();
        if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
            data().position_get(PS_ITEM+iMistake, IDX_TARGET)->hide();
        misses_++;
        miss_update();
        if (misses_<5)          // checks how many misses were done
        {
            // game continues if misses<5
            data_starttimer(TMR_REPRISE);
        }
        else
        {
            // game is over if misses=5
            tick_=0; // becomes 1 before the end of this procedure
            data_starttimer(TMR_GAMEOVER);
        }
    }
    else
    {
        tick_++;
        if (tick_>2) tick_=0;
    }

    // renders moveable items on screen

    // renders 'got' items on screen

    // plays correct sound (miss, got, move)
    if (iMistake>=0)
        data_playsound(SND_MISS);
    else if (iGot>=0)
        data_playsound(SND_GOT);
    else if (iMoved>0)
        data_playsound(SND_MOVE);

}

void GW_GameEngine_VTech_Condor::char_update(int pos, bool hit)
{
    for (int i=PS_CHAR; i<=PS_CHAR; i++)
    {
        data().position_get(i, 1)->visible_set(i-PS_CHAR==pos);
        data().position_get(i, 2)->visible_set(i-PS_CHAR==pos && !hit);
        data().position_get(i, 3)->visible_set(i-PS_CHAR==pos && hit);
    }
}

void GW_GameEngine_VTech_Condor::score_update()
{
    int p=score_;
    while (p>=10000) p-=10000;
    for (int i=1; i<=4; i++) data().position_get(PS_NUMBER, i)->hide();

    if (p>999) display_number(1, p / 1000);
    if (p>99) display_number(2, p / 100 % 10);
    if (p>9) display_number(3, p / 10 % 10);
    if (p>=0) display_number(4, p % 10 % 10);
}

void GW_GameEngine_VTech_Condor::level_update(int mode)
{
    if (mode==-1) mode=GetMode();
    int i=score_;
    while (i>199) i-=200;
    switch (mode)
    {
    case MODE_GAMEA:
        // maximum moveable items on screen
        if (i>=0 && i<4) maxonscreen_=1;
        else if (i>=4 && i<50) maxonscreen_=3;
        else if (i>=51 && i<100) maxonscreen_=4;
        else if (i>=100 && i<200) maxonscreen_=5;

        // game speed
        if (i>=0 && i<99) data().timer_get(TMR_GAME)->time_set(250);
        else if (i>=100 && i<199) data().timer_get(TMR_GAME)->time_set(215);
        break;
    case MODE_GAMEB:
        // maximum moveable items on screen
        if (i>=0 && i<4) maxonscreen_=1;
        else if (i>=4 && i<50) maxonscreen_=4;
        else if (i>=51 && i<100) maxonscreen_=5;
        else if (i>=100 && i<200) maxonscreen_=6;

        // game speed
        if (i>=0 && i<99) data().timer_get(TMR_GAME)->time_set(215);
        else if (i>=100 && i<199) data().timer_get(TMR_GAME)->time_set(185);
        break;
    default:
        break;
    }
}

void GW_GameEngine_VTech_Condor::miss_update()
{
    for (int i=1; i<=10; i++)
    {
        data().position_get(PS_MISS, i)->visible_set(misses_>=i);
    }
}

void GW_GameEngine_VTech_Condor::showall_target(bool b)
{
    if (!(options_&GO_HAVETARGET)==GO_HAVETARGET) return;

    for (int i=PS_ITEM; i<=PS_ITEM; i++)
        data().position_get(i, IDX_TARGET)->visible_set(b);
}

void GW_GameEngine_VTech_Condor::showall_miss(bool b)
{
    for (int i=PS_ITEM; i<=PS_ITEM; i++)
        data().position_get(i, IDX_MISS)->visible_set(b);
}

void GW_GameEngine_VTech_Condor::showall_got(bool b)
{
    for (int i=PS_ITEM; i<=PS_ITEM; i++)
        data().position_get(i, IDX_GOT)->visible_set(b);
}

bool GW_GameEngine_VTech_Condor::do_setmode(int mode)
{
    switch (mode)
    {
    case MODE_OFF:
        data_stopalltimers();
        data_stopallsounds();
        data_hideall();
        break;
    case MODE_IDLE:
        data_stopalltimers();
        data_showall();
        gameover_=true;
        break;
    case MODE_GAMEA:
    case MODE_GAMEB:
        if ((GetMode()!=MODE_GAMEA&&GetMode()!=MODE_GAMEB)||gameover_)
            game_start(mode);
        break;
    case MODE_TIME1:
        data_stopalltimers();
        data_hideall();
        data().position_get(PS_TIME1)->show();
        clock_update(mode);
        break;
    case MODE_TIME2:
        data_stopalltimers();
        data_hideall();
        data().position_get(PS_TIME2)->show();
        clock_update(mode);
        break;
    case MODE_ALARM:
        data_stopalltimers();
        data_hideall();
        data().position_get(PS_ALARM)->show();
        clock_update(mode);
        break;
    case MODE_CHRONO:
        data_stopalltimers();
        data_hideall();
        data().position_get(PS_CHRONO)->show();
        clock_update(mode);
        break;
    case MODE_DATE:
        data_stopalltimers();
        data_hideall();
        data().position_get(PS_DATE)->show();
        clock_update(mode);
        break;
    default:
        return false;
        break;
    }
    return true;
}


void GW_GameEngine_VTech_Condor::clock_update(int mode)
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

void GW_GameEngine_VTech_Condor::setnumber(int n, int ps1, int ps2, bool leadzero)
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

void GW_GameEngine_VTech_Condor::display_number(int pos, int n, bool show)
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

