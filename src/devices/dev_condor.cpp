#include "devices/dev_condor.h"

GW_Game *GW_Game_Condor_Info::create()
{
    return new GW_Game_Condor;
}

GW_Game_Condor::GW_Game_Condor() :
    GW_GameEngine_VTech_Condor(EO_NONE, GO_HAVEITEM0)
{
    // game "CONDOR" is default
}

