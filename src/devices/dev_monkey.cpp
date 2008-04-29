#include "devices/dev_monkey.h"

GW_Game_Monkey::GW_Game_Monkey() :
    GW_Game(), mode_(MODE_OFF)
{
    gamepath_set("monkey");
    size_set(561, 347);
    SDL_Rect gr;
    gr.x=152; gr.y=53; gr.w=257; gr.h=192;
    gamerect_set(gr);

    char sname[50];

    // character
    data().
        position_add(PS_CHAR_1, 1, 240, 97, IM_CHAR_1, 1, "im_char_1_1.bmp")->
        position_add(PS_CHAR_1, 2, 228, 92, IM_CHAR_1, 2, "im_char_1_2.bmp")->
        position_add(PS_CHAR_1, 3, 213, 116, IM_CHAR_1, 3, "im_char_1_3.bmp");
    data().
        position_add(PS_CHAR_2, 1, 273, 110, IM_CHAR_2, 1, "im_char_2_1.bmp")->
        position_add(PS_CHAR_2, 2, 269, 102, IM_CHAR_2, 2, "im_char_2_2.bmp")->
        position_add(PS_CHAR_2, 3, 260, 127, IM_CHAR_2, 3, "im_char_2_3.bmp");
    data().
        position_add(PS_CHAR_3, 1, 297, 104, IM_CHAR_3, 1, "im_char_3_1.bmp")->
        position_add(PS_CHAR_3, 2, 318, 100, IM_CHAR_3, 2, "im_char_3_2.bmp")->
        position_add(PS_CHAR_3, 3, 319, 121, IM_CHAR_3, 3, "im_char_3_3.bmp");

    // item (monkey)
    //spr_l1=sprites().sprites_add(SP_ITEM);
    data().
        position_add(PS_ITEM_1, 1, 210, 221, PS_ITEM_1, 1, "im_item_1_1.bmp")->
        position_add(PS_ITEM_1, 2, 171, 216, PS_ITEM_1, 2, "im_item_1_2.bmp")->
        position_add(PS_ITEM_1, 3, 171, 194, PS_ITEM_1, 3, "im_item_1_3.bmp")->
        position_add(PS_ITEM_1, 4, 172, 169, PS_ITEM_1, 4, "im_item_1_4.bmp")->
        position_add(PS_ITEM_1, 5, 174, 134, PS_ITEM_1, 5, "im_item_1_5.bmp")->
        position_add(PS_ITEM_1, IDX_GOT, 207, 184, PS_ITEM_1, IDX_GOT, "im_item_1_got.bmp")->
        position_add(PS_ITEM_1, IDX_MISS, 210, 150, PS_ITEM_1, IDX_MISS, "im_item_1_miss.bmp")->
        position_add(PS_ITEM_1, IDX_TARGET, 189, 126, PS_ITEM_1, IDX_TARGET, "im_item_1_target.bmp");
    data().
        position_add(PS_ITEM_2, 1, 239, 221, PS_ITEM_2, 1, "im_item_2_1.bmp")->
        position_add(PS_ITEM_2, 2, 269, 221, PS_ITEM_2, 2, "im_item_2_2.bmp")->
        position_add(PS_ITEM_2, 3, 273, 194, PS_ITEM_2, 3, "im_item_2_3.bmp")->
        position_add(PS_ITEM_2, 4, 269, 170, PS_ITEM_2, 4, "im_item_2_4.bmp")->
        position_add(PS_ITEM_2, 5, 270, 142, PS_ITEM_2, 5, "im_item_2_5.bmp")->
        position_add(PS_ITEM_2, IDX_GOT, 241, 187, PS_ITEM_2, IDX_GOT, "im_item_2_got.bmp")->
        position_add(PS_ITEM_2, IDX_MISS, 238, 158, PS_ITEM_2, IDX_MISS, "im_item_2_miss.bmp")->
        position_add(PS_ITEM_2, IDX_TARGET, 277, 134, PS_ITEM_2, IDX_TARGET, "im_item_2_target.bmp");
    data().
        position_add(PS_ITEM_3, 1, 328, 222, PS_ITEM_3, 1, "im_item_3_1.bmp")->
        position_add(PS_ITEM_3, 2, 352, 221, PS_ITEM_3, 2, "im_item_3_2.bmp")->
        position_add(PS_ITEM_3, 3, 354, 194, PS_ITEM_3, 3, "im_item_3_3.bmp")->
        position_add(PS_ITEM_3, 4, 352, 171, PS_ITEM_3, 4, "im_item_3_4.bmp")->
        position_add(PS_ITEM_3, 5, 342, 138, PS_ITEM_3, 5, "im_item_3_5.bmp")->
        position_add(PS_ITEM_3, IDX_GOT, 310, 183, PS_ITEM_3, IDX_GOT, "im_item_3_got.bmp")->
        position_add(PS_ITEM_3, IDX_MISS, 316, 145, PS_ITEM_3, IDX_MISS, "im_item_3_miss.bmp")->
        position_add(PS_ITEM_3, IDX_TARGET, 351, 130, PS_ITEM_3, IDX_TARGET, "im_item_3_target.bmp");

    // numbers
    data().
        position_add(PS_NUMBER, 1, 250, 61)->
        position_add(PS_NUMBER, 2, 265, 61)->
        position_add(PS_NUMBER, 3, 284, 61)->
        position_add(PS_NUMBER, 4, 299, 61)->
        position_add(PS_SEMICOLON, 0, 280, 67, IM_SEMICOLON, 0, "im_time_semicolon.bmp");

    for (int i=0; i<10; i++)
    {
        sprintf(sname, "im_number_%d.bmp", i);
        data().image_add(IM_NUMBER, i, sname);
    }

    data().position_get(PS_NUMBER, 1)->image_set(IM_NUMBER, 8);
    data().position_get(PS_NUMBER, 2)->image_set(IM_NUMBER, 8);
    data().position_get(PS_NUMBER, 3)->image_set(IM_NUMBER, 8);
    data().position_get(PS_NUMBER, 4)->image_set(IM_NUMBER, 8);


    // miss
    data().image_add(IM_MISS, 0, "im_miss.bmp");

    data().
        position_add(PS_MISS, 1, 330, 62, IM_MISS)->
        position_add(PS_MISS, 2, 343, 62, IM_MISS)->
        position_add(PS_MISS, 3, 356, 62, IM_MISS)->
        position_add(PS_MISS, 4, 371, 62, IM_MISS)->
        position_add(PS_MISS, 5, 385, 62, IM_MISS)->
        position_add(PS_MISS, 6, 329, 80, IM_MISS)->
        position_add(PS_MISS, 7, 344, 80, IM_MISS)->
        position_add(PS_MISS, 8, 356, 80, IM_MISS)->
        position_add(PS_MISS, 9, 371, 80, IM_MISS)->
        position_add(PS_MISS, 10, 383, 80, IM_MISS);

    // options
    data().
        position_add(PS_GAMEA, 0, 153, 61, IM_GAMEA, GW_INDEX_DEFAULT, "im_game_a.bmp")->
        position_add(PS_GAMEB, 0, 153, 76, IM_GAMEB, GW_INDEX_DEFAULT, "im_game_b.bmp")->
        position_add(PS_ALARM, 0, 200, 77, IM_ALARM, GW_INDEX_DEFAULT, "im_alarm.bmp")->
        position_add(PS_BELL, 0, 179, 63, IM_BELL, GW_INDEX_DEFAULT, "im_bell.bmp")->
        position_add(PS_CHRONO, 0, 217, 77, IM_CHRONO, GW_INDEX_DEFAULT, "im_chrono.bmp")->
        position_add(PS_DATE, 0, 232, 77, IM_DATE, GW_INDEX_DEFAULT, "im_date.bmp")->
        position_add(PS_TIME1, 0, 223, 61, IM_TIME1, GW_INDEX_DEFAULT, "im_time_1.bmp")->
        position_add(PS_TIME2, 0, 200, 61, IM_TIME2, GW_INDEX_DEFAULT, "im_time_2.bmp")->
        position_add(PS_AM, 0, 315, 61, IM_AM, GW_INDEX_DEFAULT, "im_time_am.bmp")->
        position_add(PS_PM, 0, 314, 76, IM_PM, GW_INDEX_DEFAULT, "im_time_pm.bmp");

    // sounds
    data().
        sound_add(SND_GAMEOVER, "Gameover.wav")->
        sound_add(SND_GOT, "Got.wav")->
        sound_add(SND_MISS, "Miss.wav")->
        sound_add(SND_MOVE, "Move.wav")->
        sound_add(SND_START, "Start.wav");
}

void GW_Game_Monkey::DefaultKey(defkeys_t key)
{
    switch (key)
    {
    case DK_GAMEA:
        if (GetMode()==MODE_IDLE)
            SetMode(MODE_TIME1);
        else
            SetMode(MODE_GAMEA);
        break;
    case DK_GAMEB:
        SetMode(MODE_GAMEB);
        break;
    case DK_TIME:
        if (GetMode()==MODE_TIME1)
            SetMode(MODE_TIME2);
        else if (GetMode()==MODE_TIME2)
            SetMode(MODE_ALARM);
        else if (GetMode()==MODE_ALARM)
            SetMode(MODE_CHRONO);
        else if (GetMode()==MODE_CHRONO)
            SetMode(MODE_DATE);
        else
            SetMode(MODE_TIME1);
        break;
    case DK_LEFT:
        char_position_-=1;
        if (char_position_<0) char_position_=0;
        game_update();
        break;
    case DK_RIGHT:
        char_position_+=1;
        if (char_position_>2) char_position_=2;
        game_update();
        break;
    default:
        break;
    }
}

unsigned int GW_Game_Monkey::TickTime()
{
    return 250;
}

void GW_Game_Monkey::Tick()
{
    if (GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB)
    {
        game_tick();
    }
}

void GW_Game_Monkey::Update()
{
    if (GetMode()==MODE_TIME1 || GetMode()==MODE_TIME2)
        clock_update();
}

void GW_Game_Monkey::do_turnon()
{
    SetMode(MODE_IDLE);
}

void GW_Game_Monkey::do_turnoff()
{
    SetMode(MODE_OFF);
}

void GW_Game_Monkey::game_start(bool gamea)
{
    data_hideall();

    score_=0;
    char_position_=1; // middle

    data().position_get((gamea?PS_GAMEA:PS_GAMEB))->show();

    data().position_get(PS_ITEM_1, IDX_TARGET)->show();
    data().position_get(PS_ITEM_2, IDX_TARGET)->show();
    data().position_get(PS_ITEM_3, IDX_TARGET)->show();

    game_update();
    score_update();

    data_playsound(SND_START);
}

void GW_Game_Monkey::game_update()
{
    char_update(char_position_, false);
}

void GW_Game_Monkey::game_tick()
{
    data().position_get(PS_SEMICOLON)->visible_set(!data().position_get(PS_SEMICOLON)->visible_get());
    game_update();
}

void GW_Game_Monkey::char_update(int pos, bool hit)
{
    for (int i=PS_CHAR_1; i<=PS_CHAR_3; i++)
    {
        data().position_get(i, 1)->visible_set(i-PS_CHAR_1==pos);
        data().position_get(i, 2)->visible_set(i-PS_CHAR_1==pos && !hit);
        data().position_get(i, 3)->visible_set(i-PS_CHAR_1==pos && hit);
    }
}

void GW_Game_Monkey::score_update()
{
    if (score_>=0 && score_<=99)
    {
        data().position_get(PS_NUMBER, 4)->image_set(IM_NUMBER, score_ % 10);
        data().position_get(PS_NUMBER, 4)->show();

        data().position_get(PS_NUMBER, 3)->hide();
        if (score_>9)
        {
            data().position_get(PS_NUMBER, 3)->image_set(IM_NUMBER, score_ / 10);
            data().position_get(PS_NUMBER, 3)->show();
        }
    }
    else
    {
        data().position_get(PS_NUMBER, 3)->hide();
        data().position_get(PS_NUMBER, 4)->hide();
    }
}

bool GW_Game_Monkey::do_setmode(int mode)
{
    switch (mode)
    {
    case MODE_OFF:
        data_hideall();
        break;
    case MODE_IDLE:
        data_showall();
        break;
    case MODE_GAMEA:
        game_start(true);
        break;
    case MODE_GAMEB:
        game_start(false);
        break;
    case MODE_TIME1:
        data_hideall();
        data().position_get(PS_TIME1)->show();
        clock_update();
        break;
    case MODE_TIME2:
        data_hideall();
        data().position_get(PS_TIME2)->show();
        break;
    case MODE_ALARM:
        data_hideall();
        data().position_get(PS_ALARM)->show();
        break;
    case MODE_CHRONO:
        data_hideall();
        data().position_get(PS_CHRONO)->show();
        break;
    case MODE_DATE:
        data_hideall();
        data().position_get(PS_DATE)->show();
        break;
    default:
        return false;
    }
    return true;
}


void GW_Game_Monkey::clock_update()
{
    data().position_get(PS_NUMBER, 1)->show();
    data().position_get(PS_NUMBER, 2)->show();
    data().position_get(PS_NUMBER, 3)->show();
    data().position_get(PS_NUMBER, 4)->show();

    GW_Device::devtime_t time;
    device_get()->GetTime(&time);

    data().position_get(PS_SEMICOLON)->visible_set(time.s % 2 == 0);
    data().position_get(PS_AM)->visible_set(time.h<12);
    data().position_get(PS_PM)->visible_set(time.h>=12);

    setnumber((time.h>12?time.h-12:time.h), 1, 2);
    setnumber(time.m, 3, 4);
}

void GW_Game_Monkey::setnumber(int n, int ps1, int ps2)
{
    if (n>=0 && n<=99)
    {
        if (n>10)
        {
            data().position_get(PS_NUMBER, ps1)->image_set(IM_NUMBER, n / 10);
            data().position_get(PS_NUMBER, ps2)->image_set(IM_NUMBER, n % 10);
        }
        else
        {
            data().position_get(PS_NUMBER, ps1)->image_set(IM_NUMBER, 0);
            data().position_get(PS_NUMBER, ps2)->image_set(IM_NUMBER, n);
        }
    }
}
