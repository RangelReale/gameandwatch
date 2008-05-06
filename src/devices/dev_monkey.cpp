#include "devices/dev_monkey.h"

GW_Game_Monkey::GW_Game_Monkey() :
    GW_Game(), START_DELAY_VALUE(1900), items_(), mode_(MODE_OFF)
{
    gamepath_set("monkey");
    size_set(561, 347);
    // game screen position
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
    data().
        position_add(PS_ITEM_1, 1, 210, 221, PS_ITEM_1, 1, "im_item_1_1.bmp")->
        position_add(PS_ITEM_1, 2, 171, 216, PS_ITEM_1, 2, "im_item_1_2.bmp")->
        position_add(PS_ITEM_1, 3, 171, 194, PS_ITEM_1, 3, "im_item_1_3.bmp")->
        position_add(PS_ITEM_1, 4, 172, 169, PS_ITEM_1, 4, "im_item_1_4.bmp")->
        position_add(PS_ITEM_1, 5, 174, 134, PS_ITEM_1, 5, "im_item_1_5.bmp")->
        position_add(PS_ITEM_1, IDX_GOT, 207, 184, PS_ITEM_1, IDX_GOT, "im_item_1_got.bmp")->
        position_add(PS_ITEM_1, IDX_MISS, 210, 150, PS_ITEM_1, IDX_MISS, "im_item_1_miss.bmp")->
        position_add(PS_ITEM_1, IDX_TARGET, 189, 126, PS_ITEM_1, IDX_TARGET, "im_item_1_target.bmp")->
        position_add(PS_ITEM_1, IDX_HIT, 174, 134, PS_ITEM_1, 5); // same image as 5
    data().
        position_add(PS_ITEM_2, 1, 239, 221, PS_ITEM_2, 1, "im_item_2_1.bmp")->
        position_add(PS_ITEM_2, 2, 269, 221, PS_ITEM_2, 2, "im_item_2_2.bmp")->
        position_add(PS_ITEM_2, 3, 273, 194, PS_ITEM_2, 3, "im_item_2_3.bmp")->
        position_add(PS_ITEM_2, 4, 269, 170, PS_ITEM_2, 4, "im_item_2_4.bmp")->
        position_add(PS_ITEM_2, 5, 270, 142, PS_ITEM_2, 5, "im_item_2_5.bmp")->
        position_add(PS_ITEM_2, IDX_GOT, 241, 187, PS_ITEM_2, IDX_GOT, "im_item_2_got.bmp")->
        position_add(PS_ITEM_2, IDX_MISS, 238, 158, PS_ITEM_2, IDX_MISS, "im_item_2_miss.bmp")->
        position_add(PS_ITEM_2, IDX_TARGET, 277, 134, PS_ITEM_2, IDX_TARGET, "im_item_2_target.bmp")->
        position_add(PS_ITEM_2, IDX_HIT, 270, 142, PS_ITEM_2, 5); // same image as 5
    data().
        position_add(PS_ITEM_3, 1, 328, 222, PS_ITEM_3, 1, "im_item_3_1.bmp")->
        position_add(PS_ITEM_3, 2, 352, 221, PS_ITEM_3, 2, "im_item_3_2.bmp")->
        position_add(PS_ITEM_3, 3, 354, 194, PS_ITEM_3, 3, "im_item_3_3.bmp")->
        position_add(PS_ITEM_3, 4, 352, 171, PS_ITEM_3, 4, "im_item_3_4.bmp")->
        position_add(PS_ITEM_3, 5, 342, 138, PS_ITEM_3, 5, "im_item_3_5.bmp")->
        position_add(PS_ITEM_3, IDX_GOT, 310, 183, PS_ITEM_3, IDX_GOT, "im_item_3_got.bmp")->
        position_add(PS_ITEM_3, IDX_MISS, 316, 145, PS_ITEM_3, IDX_MISS, "im_item_3_miss.bmp")->
        position_add(PS_ITEM_3, IDX_TARGET, 351, 130, PS_ITEM_3, IDX_TARGET, "im_item_3_target.bmp")->
        position_add(PS_ITEM_3, IDX_HIT, 342, 138, PS_ITEM_3, 5);

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

    // timers
    data().
        timer_add(TMR_GAME, 250, true)->
        timer_add(TMR_GAMESTART, 1800, false)->
        timer_add(TMR_HIT, 100, false)->
        timer_add(TMR_REPRISE, 1100, false)->
        timer_add(TMR_GAMEOVER, 100, false)->
        timer_add(TMR_GAMEOVERWAIT, 30000, false);
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
        if (canmove_)
        {
            char_position_-=1;
            if (char_position_<0) char_position_=0;
            char_update(char_position_, false);
            //game_update();
        }
        break;
    case DK_RIGHT:
        if (canmove_)
        {
            char_position_+=1;
            if (char_position_>2) char_position_=2;
            char_update(char_position_, false);
            //game_update();
        }
        break;
    default:
        break;
    }
}

void GW_Game_Monkey::do_timer(int timerid)
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
        data_starttimer(TMR_GAMEOVERWAIT);
        break;
    case TMR_GAMEOVERWAIT:
        SetMode(MODE_TIME1);
        break;
    }
}

void GW_Game_Monkey::do_update()
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

    startdelay_=SDL_GetTicks();
    tick_=0;
    maxonscreen_=1;
    misses_=0;
    ticksum_=0;
    canmove_=true;
    items_.clear();

    //item_add(1);

    char_update(char_position_, false);
    item_update();
    miss_update();
    level_update();

    data_playsound(SND_START);
    data_starttimer(TMR_GAMESTART);
}

void GW_Game_Monkey::game_update()
{
    //char_update(char_position_, false);
}

void GW_Game_Monkey::game_tick()
{
    //data().position_get(PS_SEMICOLON)->visible_set(!data().position_get(PS_SEMICOLON)->visible_get());

    int iMistake=-1, iGot=-1, iMoved=0;

    // current tick
    int prevtick=tick_-1;
    if (prevtick<0) prevtick=2;

    // keeps and then removes "got" items
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
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
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
    {
        if (data().position_get(i, IDX_MAX)->visible_get() && char_position_ != i-PS_ITEM_1)
        {
            data().position_get(i, IDX_MAX)->hide();
            data().position_get(i, IDX_MISS)->hide();
            iMistake=i-PS_ITEM_1;
        }
    }

    // checks for collisions character-items on certain positions and manages 'hit' animation of main character
    if (iMistake==-1 && data().position_get(PS_ITEM_1+char_position_, IDX_MAX)->visible_get())
    {
        char_update(char_position_, true);
        data_starttimer(TMR_HIT);
        data().position_get(PS_ITEM_1+char_position_, IDX_MAX)->hide();
        data().position_get(PS_ITEM_1+char_position_, IDX_GOT)->hide();
        data().position_get(PS_ITEM_1+char_position_, IDX_HIT)->show();
        score_++;
        if (score_>9999) score_-=10000;
        score_update();
        level_update();
        iGot=char_position_;
    }

    // moves and generates items
    if (iMistake==-1)
    {
        // moves items
        for (int i=5; i>1; i--)
            data().position_get(PS_ITEM_1+tick_, i)->visible_set(data().position_get(PS_ITEM_1+tick_, i-1)->visible_get());
        data().position_get(PS_ITEM_1+tick_, 1)->hide();

        // generates new items
        int iOnScreen=0;
        for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)                                   // counts items on screen
            for (int j=1; j<=IDX_MAX; j++)
                if (data().position_get(i, j)->visible_get())
                    iOnScreen++;
        if (rand() % 4 == 0) data().position_get(PS_ITEM_1+tick_, 1)->show();      // generates randomly
        else data().position_get(PS_ITEM_1+tick_, 1)->hide();
        if (iOnScreen == 0) data().position_get(PS_ITEM_1+tick_, 1)->show();       // generates if none on screen
        if (data().position_get(PS_ITEM_1+tick_, 2)->visible_get())                // prevents from generating if one just appeared on the same column
            data().position_get(PS_ITEM_1+tick_, 1)->hide();

        if (data().position_get(PS_ITEM_1+prevtick, 1)->visible_get())             // prevents from generating if one just appeared on previous column
            data().position_get(PS_ITEM_1+tick_, 1)->hide();
        if (iOnScreen>=maxonscreen_)                                               // prevents from generating if more onscreen items than allowed
            data().position_get(PS_ITEM_1+tick_, 1)->hide();

        // gets ready to play "MOVE" sound
        for (int i=1; i<=IDX_MAX; i++)
            if (data().position_get(PS_ITEM_1+tick_, i)->visible_get())
                iMoved++;
    }

    // executes miss routine, counts misses and reprises or goes to "game over"
    if (iMistake!=-1)    // checks if any miss just occured
    {
        canmove_=false;
        data_stopalltimers();

        data().position_get(PS_ITEM_1+iMistake, IDX_MISS)->show();
        data().position_get(PS_ITEM_1+iMistake, IDX_TARGET)->hide();
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

/*
    ticksum_++;
    if ((ticksum_-tick_) % 12 == 0 && (rand() % 4 == 3))
        item_add(tick_);
    item_tick();
*/

    //game_update();
}

void GW_Game_Monkey::item_add(int id)
{
    GW_Game_Monkey_Item ni;
    ni.id=id;
    ni.position=0;
    items_.push_back(ni);

    //data_playsound(SND_MOVE);
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

void GW_Game_Monkey::item_tick()
{
    for (list<GW_Game_Monkey_Item>::iterator i=items_.begin(); i!=items_.end();)
    {
        if (i->id == tick_)
        {
            i->position++;
            if (i->position>=IDX_MISS)
            {
                i=items_.erase(i);
            } else {
                i++;
                data_playsound(SND_MOVE);
            }
        } else
            i++;
    }
    item_update();
}

void GW_Game_Monkey::item_update()
{
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
    {
        for (int j=1; j<=IDX_MISS; j++)
            data().position_get(i, j)->hide();
    }

    for (list<GW_Game_Monkey_Item>::const_iterator i=items_.begin(); i!=items_.end(); i++)
    {
        data().position_get(IM_ITEM_1+(i->id), i->position)->show();
    }
}

void GW_Game_Monkey::score_update()
{
    int p=score_;
    while (p>=10000) p-=10000;
    for (int i=1; i<=4; i++) data().position_get(PS_NUMBER, i)->hide();

    if (p>999) data().position_get(PS_NUMBER, 1)->image_set(IM_NUMBER, p / 1000, true);
    if (p>99) data().position_get(PS_NUMBER, 2)->image_set(IM_NUMBER, p / 100 % 10, true);
    if (p>9) data().position_get(PS_NUMBER, 3)->image_set(IM_NUMBER, p / 10 % 10, true);
    if (p>=0) data().position_get(PS_NUMBER, 4)->image_set(IM_NUMBER, p % 10 % 10, true);
}

void GW_Game_Monkey::level_update()
{
    int i=score_;
    while (i>199) i+=200;
    switch (GetMode())
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
        break;
    default:
        break;
    }
}

void GW_Game_Monkey::miss_update()
{
    for (int i=1; i<=10; i++)
    {
        data().position_get(PS_MISS, i)->visible_set(misses_>=i);
    }
}

void GW_Game_Monkey::showall_target(bool b)
{
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
        data().position_get(i, IDX_TARGET)->visible_set(b);
}

void GW_Game_Monkey::showall_miss(bool b)
{
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
        data().position_get(i, IDX_MISS)->visible_set(b);
}

void GW_Game_Monkey::showall_got(bool b)
{
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
        data().position_get(i, IDX_GOT)->visible_set(b);
}

void GW_Game_Monkey::do_setmode(int mode)
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
        SetMode(MODE_IDLE);
        break;
    }
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
