#include "devices/dev_monkey.h"

GW_Game *GW_Game_Monkey_Info::create()
{
    return new GW_Game_Monkey;
}

GW_Game_Monkey::GW_Game_Monkey() :
    GW_GameEngine_VTech_Monkey(true)
{
    // game "MONKEY" is default
}
