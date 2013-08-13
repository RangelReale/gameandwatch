#ifdef GW_DEVEL_DEVICE

#include "devices/dev_dkong.h"

#include <cstdio>

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
    GW_PLATFORM_RECT(gr, 125, 78, 212, 412); // full screen
    //GW_PLATFORM_RECT(gr, 125, 349, 214, 139); // first screen
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

    // life
    data().
        position_add(PS_LIFE, 1, 216, 470, IM_LIFE, 1, "vite.bmp", &tcolor_img)->
        position_add(PS_LIFE, 2, 229, 470, IM_LIFE, 1)->
        position_add(PS_LIFE, 3, 242, 470, IM_LIFE, 1);

    // bg
    data().
        image_add(IM_BG, GW_INDEX_DEFAULT, "bg.bmp", &tcolor_bg);

    // barrel
    data().
        position_add(PS_BARREL, 1, 137, 200, IM_BARREL, 1, "bar_14.bmp", &tcolor_img)->
        //position_add(PS_BARREL, 2, 136, 372, IM_LIFE, 1)-> // 15
        position_add(PS_BARREL, 3, 136, 397, IM_BARREL, 2, "bar_16.bmp", &tcolor_img)->
        position_add(PS_BARREL, 4, 136, 461, IM_BARREL, 3, "bar_17.bmp", &tcolor_img)->
        position_add(PS_BARREL, 5, 169, 197, IM_BARREL, 4, "bar_24.bmp", &tcolor_img)->
        position_add(PS_BARREL, 6, 169, 400, IM_BARREL, 1)-> // 26
        position_add(PS_BARREL, 7, 169, 457, IM_BARREL, 6, "bar_36.bmp", &tcolor_img)-> // 27
        position_add(PS_BARREL, 8, 189, 196, IM_BARREL, 5, "bar_34.bmp", &tcolor_img)->
        position_add(PS_BARREL, 9, 202, 403, IM_BARREL, 6, "bar_36.bmp", &tcolor_img)->
        position_add(PS_BARREL, 10, 202, 454, IM_BARREL, 8, "bar_46.bmp", &tcolor_img)-> // 37
        position_add(PS_BARREL, 11, 208, 195, IM_BARREL, 7, "bar_44.bmp", &tcolor_img)->
        position_add(PS_BARREL, 12, 233, 406, IM_BARREL, 8, "bar_46.bmp", &tcolor_img)->
        position_add(PS_BARREL, 13, 233, 452, IM_BARREL, 2)-> // 47
        position_add(PS_BARREL, 14, 228, 194, IM_BARREL, 9, "bar_54.bmp", &tcolor_img)->
        position_add(PS_BARREL, 15, 263, 409, IM_BARREL, 2)-> // 56
        position_add(PS_BARREL, 16, 264, 450, IM_BARREL, 1)-> // 57
        position_add(PS_BARREL, 17, 245, 193, IM_BARREL, 4)-> // 64
        position_add(PS_BARREL, 18, 294, 413, IM_BARREL, 9)-> // 66
        position_add(PS_BARREL, 19, 294, 447, IM_BARREL, 6); // 67

    // barrel fall
    data().
        position_add(PS_BARRELFALL, 1, 167, 127, IM_BARRELFALL, 1, "bar_f21.bmp", &tcolor_img)->
        position_add(PS_BARRELFALL, 2, 168, 149, IM_BARRELFALL, 2, "bar_f22.bmp", &tcolor_img)->
        position_add(PS_BARRELFALL, 3, 169, 177, IM_BARRELFALL, 3, "bar_f23.bmp", &tcolor_img)->
        position_add(PS_BARRELFALL, 4, 206, 127, IM_BARRELFALL, 1)-> // 41
        position_add(PS_BARRELFALL, 5, 207, 148, IM_BARRELFALL, 4, "bar_f42.bmp", &tcolor_img)->
        position_add(PS_BARRELFALL, 6, 209, 178, IM_BARRELFALL, 5, "bar_f43.bmp", &tcolor_img)->
        //position_add(PS_BARRELFALL, 7, 302, 384, IM_BARRELFALL, 6, "bar_f44.bmp", &tcolor_img)->
        position_add(PS_BARRELFALL, 8, 243, 127, IM_BARRELFALL, 1)-> // 61
        position_add(PS_BARRELFALL, 9, 244, 147, IM_BARRELFALL, 6, "bar_f44.bmp", &tcolor_img)-> // 62
        position_add(PS_BARRELFALL, 10, 245, 178, IM_BARRELFALL, 7, "bar_f63.bmp", &tcolor_img);

    // hook
    data().
        position_add(PS_HOOK, 1, 275, 128, IM_HOOK, 1, "gancio1.bmp", &tcolor_img)->
        position_add(PS_HOOK, 2, 283, 131, IM_HOOK, 2, "gancio2.bmp", &tcolor_img)->
        position_add(PS_HOOK, 3, 293, 132, IM_HOOK, 3, "gancio3.bmp", &tcolor_img)->
        position_add(PS_HOOK, 4, 298, 134, IM_HOOK, 4, "gancio4.bmp", &tcolor_img)->
        position_add(PS_HOOK, 5, 304, 135, IM_HOOK, 5, "gancio5.bmp", &tcolor_img);

    // crane
    data().
        position_add(PS_CRANE, 1, 306, 151, IM_CRANE, 1, "gru1.bmp", &tcolor_img)->
        position_add(PS_CRANE, 2, 294, 125, IM_CRANE, 2, "gru2.bmp", &tcolor_img)->
        position_add(PS_CRANE, 3, 288, 88, IM_CRANE, 3, "gru3.bmp", &tcolor_img);

    // heart
    data().
        position_add(PS_HEART, 1, 144, 91, IM_HEART, 1, "heart1.bmp", &tcolor_img)->
        position_add(PS_HEART, 2, 149, 85, IM_HEART, 2, "heart2.bmp", &tcolor_img);

    // key
    data().
        position_add(PS_KEY, 1, 266, 102, IM_KEY, 1, "key1.bmp", &tcolor_img)->
        position_add(PS_KEY, 2, 271, 102, IM_KEY, 2, "key2.bmp", &tcolor_img)->
        position_add(PS_KEY, 3, 276, 102, IM_KEY, 3, "key3.bmp", &tcolor_img)->
        position_add(PS_KEY, 4, 280, 192, IM_KEY, 4, "key4.bmp", &tcolor_img);

    // kong up
    data().
        position_add(PS_KONGUP, 1, 160, 84, IM_KONGUP, 1, "kong2up.bmp", &tcolor_img)->
        position_add(PS_KONGUP, 2, 200, 84, IM_KONGUP, 2, "kong4up.bmp", &tcolor_img)->
        position_add(PS_KONGUP, 3, 232, 84, IM_KONGUP, 3, "kong6up.bmp", &tcolor_img);

    // kong down
    data().
        position_add(PS_KONGDOWN, 1, 154, 96, IM_KONGDOWN, 1, "kong2dwn.bmp", &tcolor_img)->
        position_add(PS_KONGDOWN, 2, 193, 95, IM_KONGDOWN, 2, "kong4dwn.bmp", &tcolor_img)->
        position_add(PS_KONGDOWN, 3, 228, 95, IM_KONGDOWN, 3, "kong6dwn.bmp", &tcolor_img);

    // kong fall
    data().
        position_add(PS_KONGFALL, GW_INDEX_DEFAULT, 258, 180, IM_KONGFALL, GW_INDEX_DEFAULT, "kongfall.bmp", &tcolor_img);

    // lever
    data().
        position_add(PS_LEVER, 1, 149, 172, IM_LEVER, 1, "leva_giu.bmp", &tcolor_img)->
        position_add(PS_LEVER, 2, 145, 162, IM_LEVER, 2, "leva_su.bmp", &tcolor_img);

    // mario
    data().
        position_add(PS_MARIO, 1, 153, 155, IM_MARIO, 1, "mario22a.bmp", &tcolor_img)->
        position_add(PS_MARIO, 2, 157, 155, IM_MARIO, 2, "mario22b.bmp", &tcolor_img)->
        position_add(PS_MARIO, 3, 150, 187, IM_MARIO, 3, "mario24.bmp", &tcolor_img)->
        position_add(PS_MARIO, 4, 149, 371, IM_MARIO, 4, "mario25.bmp", &tcolor_img)->
        position_add(PS_MARIO, 5, 149, 389, IM_MARIO, 5, "mario26.bmp", &tcolor_img)->
        position_add(PS_MARIO, 6, 148, 450, IM_MARIO, 6, "mario27.bmp", &tcolor_img)->
        position_add(PS_MARIO, 7, 151, 431, IM_MARIO, 7, "mario27j.bmp", &tcolor_img)->
        position_add(PS_MARIO, 8, 181, 391, IM_MARIO, 8, "mario36.bmp", &tcolor_img)->
        position_add(PS_MARIO, 9, 183, 446, IM_MARIO, 9, "mario37.bmp", &tcolor_img)->
        position_add(PS_MARIO, 10, 203, 156, IM_MARIO, 10, "mario42.bmp", &tcolor_img)->
        position_add(PS_MARIO, 11, 213, 395, IM_MARIO, 11, "mario46.bmp", &tcolor_img)->
        position_add(PS_MARIO, 12, 214, 376, IM_MARIO, 12, "mario46j.bmp", &tcolor_img)->
        position_add(PS_MARIO, 13, 214, 444, IM_MARIO, 13, "mario47.bmp", &tcolor_img)->
        position_add(PS_MARIO, 14, 245, 397, IM_MARIO, 14, "mario56.bmp", &tcolor_img)->
        position_add(PS_MARIO, 15, 245, 380, IM_MARIO, 15, "mario56j.bmp", &tcolor_img)->
        position_add(PS_MARIO, 16, 245, 441, IM_MARIO, 16, "mario57.bmp", &tcolor_img)->
        position_add(PS_MARIO, 17, 245, 423, IM_MARIO, 17, "mario57j.bmp", &tcolor_img)->
        position_add(PS_MARIO, 18, 234, 154, IM_MARIO, 18, "mario62.bmp", &tcolor_img)->
        position_add(PS_MARIO, 19, 257, 136, IM_MARIO, 19, "mario62a.bmp", &tcolor_img)->
        position_add(PS_MARIO, 20, 284, 151, IM_MARIO, 20, "mario62b.bmp", &tcolor_img)->
        position_add(PS_MARIO, 21, 273, 164, IM_MARIO, 21, "mario62c.bmp", &tcolor_img)->
        position_add(PS_MARIO, 22, 286, 188, IM_MARIO, 22, "mario62d.bmp", &tcolor_img)->
        position_add(PS_MARIO, 23, 309, 187, IM_MARIO, 23, "mario62e.bmp", &tcolor_img)->
        position_add(PS_MARIO, 24, 272, 400, IM_MARIO, 24, "mario66.bmp", &tcolor_img)->
        position_add(PS_MARIO, 25, 274, 439, IM_MARIO, 25, "mario67.bmp", &tcolor_img);

    // platform
    data().
        position_add(PS_PLAT, 1, 137, 130, IM_PLAT, 1, "sbarregi.bmp", &tcolor_img)->
        position_add(PS_PLAT, 2, 152, 122, IM_PLAT, 2, "sbarresu.bmp", &tcolor_img);

    // binder
    data().
        position_add(PS_BINDER, 1, 148, 359, IM_BINDER, 1, "trave2.bmp", &tcolor_img)->
        position_add(PS_BINDER, 2, 177, 362, IM_BINDER, 2, "trave3.bmp", &tcolor_img)->
        position_add(PS_BINDER, 3, 209, 365, IM_BINDER, 3, "trave4.bmp", &tcolor_img)->
        position_add(PS_BINDER, 4, 239, 368, IM_BINDER, 4, "trave5.bmp", &tcolor_img)->
        position_add(PS_BINDER, 5, 271, 370, IM_BINDER, 5, "trave6.bmp", &tcolor_img);


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

#endif //GW_DEVEL_DEVICE
