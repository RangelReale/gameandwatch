#include "devices/dev_pancake.h"

GW_Game *GW_Game_Pancake_Info::create()
{
    return new GW_Game_Pancake;
}

GW_Game_Pancake::GW_Game_Pancake() :
    GW_GameEngine_VTech_Condor(GO_HAVEITEM0|GO_HAVELEFT0|GO_HAVERIGHT1A|GO_HAVERIGHT6)
{
    gamepath_set("pancake");
    size_set(560, 372);

    // game screen position
    GW_PLATFORM_RECT(gr, 151, 52, 257, 192);
    gamerect_set(gr);

}


