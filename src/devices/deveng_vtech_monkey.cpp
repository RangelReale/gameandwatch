#include <cstdlib>
#include "devices/deveng_vtech_monkey.h"

GW_GameEngine_VTech_Monkey::GW_GameEngine_VTech_Monkey(int engineoptions, int options) :
    GW_GameEngine_VTech(engineoptions), options_(options)
{
    // "MONKEY" is default

    gamepath_set("monkey");
    size_set(561, 347);

    // game screen position
    GW_PLATFORM_RECT(gr, 152, 53, 257, 192);
    gamerect_set(gr);

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // character
    data().
        position_add(PS_CHAR_1, 1, 240, 97, IM_CHAR_1, 1, "im_char_1_1.bmp", &tcolor_img)->
        position_add(PS_CHAR_1, 2, 228, 92, IM_CHAR_1, 2, "im_char_1_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_1, 3, 213, 116, IM_CHAR_1, 3, "im_char_1_3.bmp", &tcolor_img);
    data().
        position_add(PS_CHAR_2, 1, 273, 110, IM_CHAR_2, 1, "im_char_2_1.bmp", &tcolor_img)->
        position_add(PS_CHAR_2, 2, 269, 102, IM_CHAR_2, 2, "im_char_2_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_2, 3, 260, 127, IM_CHAR_2, 3, "im_char_2_3.bmp", &tcolor_img);
    data().
        position_add(PS_CHAR_3, 1, 297, 104, IM_CHAR_3, 1, "im_char_3_1.bmp", &tcolor_img)->
        position_add(PS_CHAR_3, 2, 318, 100, IM_CHAR_3, 2, "im_char_3_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_3, 3, 319, 121, IM_CHAR_3, 3, "im_char_3_3.bmp", &tcolor_img);

    // item
    data().
        position_add(PS_ITEM_1, 1, 210, 221, IM_ITEM_1, 1, "im_item_1_1.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 2, 171, 216, IM_ITEM_1, 2, "im_item_1_2.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 3, 171, 194, IM_ITEM_1, 3, "im_item_1_3.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 4, 172, 169, IM_ITEM_1, 4, "im_item_1_4.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 5, 174, 134, IM_ITEM_1, 5, "im_item_1_5.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, IDX_GOT, 207, 184, IM_ITEM_1, IDX_GOT, "im_item_1_got.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, IDX_MISS, 210, 150, IM_ITEM_1, IDX_MISS, "im_item_1_miss.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, IDX_HIT, 174, 134, IM_ITEM_1, 5); // same image as 5
    if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
        data().
            position_add(PS_ITEM_1, IDX_TARGET, 189, 126, IM_ITEM_1, IDX_TARGET, "im_item_1_target.bmp", &tcolor_img);
    data().
        position_add(PS_ITEM_2, 1, 239, 221, IM_ITEM_2, 1, "im_item_2_1.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 2, 269, 221, IM_ITEM_2, 2, "im_item_2_2.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 3, 273, 194, IM_ITEM_2, 3, "im_item_2_3.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 4, 269, 170, IM_ITEM_2, 4, "im_item_2_4.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 5, 270, 142, IM_ITEM_2, 5, "im_item_2_5.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_GOT, 241, 187, IM_ITEM_2, IDX_GOT, "im_item_2_got.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_MISS, 238, 158, IM_ITEM_2, IDX_MISS, "im_item_2_miss.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_HIT, 270, 142, IM_ITEM_2, 5); // same image as 5
    if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
        data().
            position_add(PS_ITEM_2, IDX_TARGET, 277, 134, IM_ITEM_2, IDX_TARGET, "im_item_2_target.bmp", &tcolor_img);
    data().
        position_add(PS_ITEM_3, 1, 328, 222, IM_ITEM_3, 1, "im_item_3_1.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, 2, 352, 221, IM_ITEM_3, 2, "im_item_3_2.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, 3, 354, 194, IM_ITEM_3, 3, "im_item_3_3.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, 4, 352, 171, IM_ITEM_3, 4, "im_item_3_4.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, 5, 342, 138, IM_ITEM_3, 5, "im_item_3_5.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, IDX_GOT, 310, 183, IM_ITEM_3, IDX_GOT, "im_item_3_got.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, IDX_MISS, 316, 145, IM_ITEM_3, IDX_MISS, "im_item_3_miss.bmp", &tcolor_img)->
        position_add(PS_ITEM_3, IDX_HIT, 342, 138, IM_ITEM_3, 5);
    if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
        data().
            position_add(PS_ITEM_3, IDX_TARGET, 351, 130, IM_ITEM_3, IDX_TARGET, "im_item_3_target.bmp", &tcolor_img);

    // sounds
    data().
        sound_add(SND_GAMEOVER, "Gameover.wav")->
        sound_add(SND_GOT, "Got.wav")->
        sound_add(SND_MISS, "Miss.wav")->
        sound_add(SND_MOVE, "Move.wav")->
        sound_add(SND_START, "Start.wav");

    // timers
    data().
        timer_add(TMR_HIT, 100, false);
}

void GW_GameEngine_VTech_Monkey::Event(GW_Platform_Event *event)
{
    GW_GameEngine_VTech::Event(event);

    if (event->id==GPE_KEYDOWN)
    {
        switch (event->data)
        {
        case GPK_LEFT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_position_-=1;
                if (char_position_<0) char_position_=0;
                char_update(char_position_, false);
                //game_update();
            }
            break;
        case GPK_RIGHT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
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

void GW_GameEngine_VTech_Monkey::game_reprise()
{
    showall_miss(false);
    showall_target(true);
}

void GW_GameEngine_VTech_Monkey::do_timer(int timerid)
{
    GW_GameEngine_VTech::do_timer(timerid);

    switch (timerid)
    {
    case TMR_HIT:
        char_update(char_position_, false);
        break;
    }
}

void GW_GameEngine_VTech_Monkey::game_start(int mode)
{
    GW_GameEngine_VTech::game_start(mode);

    tick_=0;
    char_position_=1; // middle

    if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
    {
        data().position_get(PS_ITEM_1, IDX_TARGET)->show();
        data().position_get(PS_ITEM_2, IDX_TARGET)->show();
        data().position_get(PS_ITEM_3, IDX_TARGET)->show();
    }

    maxonscreen_=1;

    char_update(char_position_, false);

    data_playsound(SND_START);
}

void GW_GameEngine_VTech_Monkey::game_tick()
{
    // blink the semicolon on tick
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
        score_add();
        iGot=char_position_;
        data_delaytimer(TMR_GAME, 60); // when hit, delay the game a little to allow for moving
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
        canmove_set(false);
        data_stopalltimers();

        data().position_get(PS_ITEM_1+iMistake, IDX_MISS)->show();
        if ((options_&GO_HAVETARGET)==GO_HAVETARGET)
            data().position_get(PS_ITEM_1+iMistake, IDX_TARGET)->hide();
        misses_add();
        if (misses_get()<5)          // checks how many misses were done
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

void GW_GameEngine_VTech_Monkey::char_update(int pos, bool hit)
{
    for (int i=PS_CHAR_1; i<=PS_CHAR_3; i++)
    {
        data().position_get(i, 1)->visible_set(i-PS_CHAR_1==pos);
        data().position_get(i, 2)->visible_set(i-PS_CHAR_1==pos && !hit);
        data().position_get(i, 3)->visible_set(i-PS_CHAR_1==pos && hit);
    }
}

void GW_GameEngine_VTech_Monkey::level_update(int mode)
{
    if (mode==-1) mode=GetMode();
    int i=score_get();
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

void GW_GameEngine_VTech_Monkey::showall_target(bool b)
{
    if (!(options_&GO_HAVETARGET)==GO_HAVETARGET) return;

    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
        data().position_get(i, IDX_TARGET)->visible_set(b);
}

void GW_GameEngine_VTech_Monkey::showall_miss(bool b)
{
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
        data().position_get(i, IDX_MISS)->visible_set(b);
}

void GW_GameEngine_VTech_Monkey::showall_got(bool b)
{
    for (int i=PS_ITEM_1; i<=PS_ITEM_3; i++)
        data().position_get(i, IDX_GOT)->visible_set(b);
}

