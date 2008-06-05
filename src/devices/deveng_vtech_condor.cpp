#include "devices/deveng_vtech_condor.h"

GW_GameEngine_VTech_Condor::GW_GameEngine_VTech_Condor(int engineoptions, int options) :
    GW_GameEngine_VTech(engineoptions), options_(options)
{
    // "CONDOR" is default

    gamepath_set("condor");
    size_set(562, 373);

    // game screen position
    GW_PLATFORM_RECT(gr, 151, 52, 257, 192);
    gamerect_set(gr);

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

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
        position_change(PS_NUMBER, 1, 248, 54)->
        position_change(PS_NUMBER, 2, 263, 54)->
        position_change(PS_NUMBER, 3, 283, 54)->
        position_change(PS_NUMBER, 4, 298, 54)->
        position_change(PS_SEMICOLON, 0, 278, 59);

    // miss
    data().
        position_change(PS_MISS, 1, 336, 51)->
        position_change(PS_MISS, 2, 349, 51)->
        position_change(PS_MISS, 3, 362, 51)->
        position_change(PS_MISS, 4, 375, 51)->
        position_change(PS_MISS, 5, 388, 51)->
        position_change(PS_MISS, 6, 336, 67)->
        position_change(PS_MISS, 7, 349, 67)->
        position_change(PS_MISS, 8, 362, 67)->
        position_change(PS_MISS, 9, 375, 67)->
        position_change(PS_MISS, 10, 388, 67);

    // options
    data().
        position_change(PS_GAMEA, 0, 158, 54)->
        position_change(PS_GAMEB, 0, 158, 70)->
        position_change(PS_ALARM, 0, 200, 70)->
        position_change(PS_BELL, 0, 184, 56)->
        position_change(PS_CHRONO, 0, 218, 70)->
        position_change(PS_DATE, 0, 231, 70)->
        position_change(PS_TIME1, 0, 224, 54)->
        position_change(PS_TIME2, 0, 201, 54)->
        position_change(PS_AM, 0, 318, 54)->
        position_change(PS_PM, 0, 318, 69);

}

void GW_GameEngine_VTech_Condor::Event(GW_Platform_Event *event)
{
    GW_GameEngine_VTech::Event(event);

    if (event->id==GPE_KEYDOWN)
    {
/*
        switch (event->data)
        {
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
*/
    }
}

void GW_GameEngine_VTech_Condor::do_timer(int timerid)
{
    GW_GameEngine_VTech::do_timer(timerid);
}

void GW_GameEngine_VTech_Condor::game_start(int mode)
{
    char_position_=1; // middle

    tick_=0;
    maxonscreen_=1;

    char_update(char_position_, false);
}

void GW_GameEngine_VTech_Condor::game_tick()
{

}

void GW_GameEngine_VTech_Condor::game_reprise()
{

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

void GW_GameEngine_VTech_Condor::level_update(int mode)
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

