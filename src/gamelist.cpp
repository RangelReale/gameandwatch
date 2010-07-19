#include "gamelist.h"

#include "devices/dev_monkey.h"
#include "devices/dev_pirate.h"
#include "devices/dev_defendo.h"

#include "devices/dev_condor.h"
#include "devices/dev_pancake.h"
#include "devices/dev_rollerc.h"

#ifdef GW_DEVEL_DEVICE
#include "devices/dev_banana.h"
#include "devices/dev_sleepwlk.h"

#include "devices/dev_dkong.h"
#endif

//////////////////////////////////////////
////
//// GW_GameList
////
//////////////////////////////////////////
GW_GameList::GW_GameList(GW_Platform *platform) :
    list_(), platform_(platform)
{
    load();
}

void GW_GameList::load()
{
#ifdef GW_DEVEL_DEVICE
	add(new GW_Game_Banana_Info(platform_->datapath_get())); // Banana
    add(new GW_Game_SleepWlk_Info(platform_->datapath_get())); // Sleep Walker

    add(new GW_Game_DKong_Info(platform_->datapath_get())); // Donkey Kong
#endif //GW_DEVEL_DEVICE

    add(new GW_Game_Condor_Info(platform_->datapath_get())); // Condor
    add(new GW_Game_Defendo_Info(platform_->datapath_get())); // Defendo
    add(new GW_Game_Monkey_Info(platform_->datapath_get())); // Monkey
    add(new GW_Game_Pancake_Info(platform_->datapath_get())); // Pancake
    add(new GW_Game_Pirate_Info(platform_->datapath_get())); // Pirate
    add(new GW_Game_RollerC_Info(platform_->datapath_get())); // Roller Coaster
}

GW_Game_Info *GW_GameList::get(int index)
{
    return &*list_[index];
}

void GW_GameList::add(GW_Game_Info *gameinfo)
{
    list_.push_back( linked_ptr<GW_Game_Info>(gameinfo) );
}
