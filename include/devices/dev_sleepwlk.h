#ifndef H__DEV_SLEEPWLK__H
#define H__DEV_SLEEPWLK__H

#include "devices/deveng_vtech_banana.h"

class GW_Game_SleepWlk_Info : public GW_Game_Info
{
public:
    GW_Game_SleepWlk_Info() :
        GW_Game_Info("sleepwlk", "Time & Fun - Sleep Walker", "sleepwlk",
            "bg.bmp", true, GW_Platform_RGB_create(255, 255, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_SleepWlk : public GW_GameEngine_VTech_Banana
{
public:
    GW_Game_SleepWlk();
};

#endif //H__DEV_BANANA__H
