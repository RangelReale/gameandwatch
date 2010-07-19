#ifndef H__DEV_PANCAKE__H
#define H__DEV_PANCAKE__H

#include "devices/deveng_vtech_condor.h"

class GW_Game_Pancake_Info : public GW_Game_Info
{
public:
    GW_Game_Pancake_Info(const string &platformdatapath) :
        GW_Game_Info("pancake", "Time & Fun - Pancake", "pancake",
			platformdatapath,
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_Pancake : public GW_GameEngine_VTech_Condor
{
public:
    GW_Game_Pancake();
};

#endif //H__DEV_PANCAKE__H
