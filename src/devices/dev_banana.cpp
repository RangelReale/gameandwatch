#include "devices/dev_banana.h"

GW_Game *GW_Game_Banana_Info::create()
{
    return new GW_Game_Banana;
}

GW_Game_Banana::GW_Game_Banana() :
    GW_GameEngine_VTech_Banana(EO_MISSSEPARATED, GO_HAVECHARANIM|GO_HAVEOBSTACLE17)
{
    // game "BANANA" is default
}

