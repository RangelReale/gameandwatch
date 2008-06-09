#ifndef H__DEV_BANANA__H
#define H__DEV_BANANA__H

#include "devices/deveng_vtech_banana.h"

class GW_Game_Banana_Info : public GW_Game_Info
{
public:
    GW_Game_Banana_Info() :
        GW_Game_Info("banana", "Time & Fun - Banana", "banana",
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_Banana : public GW_GameEngine_VTech_Banana
{
public:
    GW_Game_Banana();
};

#endif //H__DEV_BANANA__H
