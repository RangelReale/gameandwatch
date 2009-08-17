#ifndef H__DEV_ROLLERC__H
#define H__DEV_ROLLERC__H

#include "devices/deveng_vtech_condor.h"

class GW_Game_RollerC_Info : public GW_Game_Info
{
public:
    GW_Game_RollerC_Info() :
        GW_Game_Info("rollerc", "Time & Fun - Roller Coaster", "rollerc",
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_RollerC : public GW_GameEngine_VTech_Condor
{
public:
    GW_Game_RollerC();
};

#endif //H__DEV_ROLLERC__H
