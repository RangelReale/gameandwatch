#ifndef H__DEV_DEFENDO__H
#define H__DEV_DEFENDO__H

#include "devices/deveng_vtech_monkey.h"

class GW_Game_Defendo_Info : public GW_Game_Info
{
public:
    GW_Game_Defendo_Info() :
        GW_Game_Info("defendo", "Time & Fun - Defendo", "defendo",
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_Defendo : public GW_GameEngine_VTech_Monkey
{
public:
    GW_Game_Defendo();
};

#endif //H__DEV_DEFENDO__H
