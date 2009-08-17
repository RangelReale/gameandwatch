#ifndef H__DEV_CONDOR__H
#define H__DEV_CONDOR__H

#include "devices/deveng_vtech_condor.h"

class GW_Game_Condor_Info : public GW_Game_Info
{
public:
    GW_Game_Condor_Info() :
        GW_Game_Info("condor", "Time & Fun - Condor", "condor",
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_Condor : public GW_GameEngine_VTech_Condor
{
public:
    GW_Game_Condor();
};

#endif //H__DEV_CONDOR__H
