#include "devices/dev_monkey.h"

GW_Game *GW_Game_Monkey_Info::create()
{
    return new GW_Game_Monkey;
}

GW_Game_Monkey::GW_Game_Monkey() :
    GW_GameEngine_VTech_Monkey(GO_HAVETARGET)
{
    // game "MONKEY" is default
}
