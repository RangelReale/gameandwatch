#include "devices/dev_rollerc.h"

GW_Game *GW_Game_RollerC_Info::create()
{
    return new GW_Game_RollerC;
}

GW_Game_RollerC::GW_Game_RollerC() :
    GW_GameEngine_VTech_Condor(GO_HAVERIGHT6)
{
    gamepath_set("rollerc");
    size_set(609, 377);

    // game screen position
    GW_PLATFORM_RECT(gr, 151, 52, 257, 192);
    gamerect_set(gr);
}


