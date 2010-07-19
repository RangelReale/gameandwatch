#ifndef H__DEV_PIRATE__H
#define H__DEV_PIRATE__H

#include "devices/deveng_vtech_monkey.h"


class GW_Game_Pirate_Info : public GW_Game_Info
{
public:
    GW_Game_Pirate_Info(const string &platformdatapath) :
        GW_Game_Info("pirate", "Time & Fun - Pirate", "pirate",
			platformdatapath,
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};


class GW_Game_Pirate : public GW_GameEngine_VTech_Monkey
{
public:
    GW_Game_Pirate();
};

#endif //H__DEV_PIRATE__H
