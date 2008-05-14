#include "devices/dev_defendo.h"

GW_Game *GW_Game_Defendo_Info::create()
{
    return new GW_Game_Defendo;
}

GW_Game_Defendo::GW_Game_Defendo() :
    GW_GameEngine_VTech_Monkey(false)
{
    gamepath_set("defendo");
}

