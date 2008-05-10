#include "gamelist.h"


#include "devices/dev_monkey.h"

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
}

GW_Game_Info *GW_GameList::get(int index)
{
    return &*list_[index];
}

void GW_GameList::add(GW_Game_Info *gameinfo)
{
    list_.push_back( shared_ptr<GW_Game_Info>(gameinfo) );
}
