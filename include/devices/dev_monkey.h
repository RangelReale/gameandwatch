#ifndef H__DEV_MONKEY__H
#define H__DEV_MONKEY__H

#include "devices/deveng_vtech_monkey.h"

class GW_Game_Monkey_Info : public GW_Game_Info
{
public:
    GW_Game_Monkey_Info(const string &platformdatapath) :
        GW_Game_Info("monkey", "Time & Fun - Monkey", "monkey",
			platformdatapath,
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_Monkey : public GW_GameEngine_VTech_Monkey
{
public:
    GW_Game_Monkey();
};

#endif //H__DEV_MONKEY__H
