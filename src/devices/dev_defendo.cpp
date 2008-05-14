#include "devices/dev_defendo.h"

GW_Game *GW_Game_Defendo_Info::create()
{
    return new GW_Game_Defendo;
}

GW_Game_Defendo::GW_Game_Defendo() :
    GW_GameEngine_VTech_Monkey(false)
{
    gamepath_set("defendo");

    // game size
    size_set(614, 378);

    // game screen position
    GW_PLATFORM_RECT(gr, 201, 99, 161, 209);
    gamerect_set(gr);
}

