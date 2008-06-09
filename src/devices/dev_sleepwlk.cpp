#include "devices/dev_sleepwlk.h"

GW_Game *GW_Game_SleepWlk_Info::create()
{
    return new GW_Game_SleepWlk;
}

GW_Game_SleepWlk::GW_Game_SleepWlk() :
    GW_GameEngine_VTech_Banana(EO_NONE, GO_NONE)
{
    // game "BANANA" is default
    gamepath_set("sleepwlk");

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // bg - sleep walker bg is white not pink
    data().
        image_add(IM_BG, GW_INDEX_DEFAULT, "bg.bmp", &tcolor_img);

}


