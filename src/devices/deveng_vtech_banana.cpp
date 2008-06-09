#include "devices/deveng_vtech_banana.h"

GW_GameEngine_VTech_Banana::GW_GameEngine_VTech_Banana(int engineoptions, int options) :
    GW_GameEngine_VTech(engineoptions), options_(options)
{
    // "BANANA" is default

    gamepath_set("banana");
    size_set(561, 347);

    // game screen position
    GW_PLATFORM_RECT(gr, 152, 53, 257, 192);
    gamerect_set(gr);

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);
}

