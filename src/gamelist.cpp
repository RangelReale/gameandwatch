#include "gamelist.h"

#include "devices/dev_monkey.h"
#include "devices/dev_pirate.h"
#include "devices/dev_defendo.h"

#include "devices/dev_condor.h"
#include "devices/dev_pancake.h"
#include "devices/dev_rollerc.h"

//////////////////////////////////////////
////
//// GW_GameList
////
//////////////////////////////////////////
GW_GameList::GW_GameList() :
    list_()
{
    load();
}

void GW_GameList::load()
{
    add(new GW_Game_Monkey_Info); // Monkey
    add(new GW_Game_Pirate_Info); // Pirate
    add(new GW_Game_Defendo_Info); // Defendo
    add(new GW_Game_Condor_Info); // Condor
    add(new GW_Game_Pancake_Info); // Pancake
    add(new GW_Game_RollerC_Info); // Roller Coaster
}

GW_Game_Info *GW_GameList::get(int index)
{
    return &*list_[index];
}

void GW_GameList::add(GW_Game_Info *gameinfo)
{
    list_.push_back( shared_ptr<GW_Game_Info>(gameinfo) );
}
