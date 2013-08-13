#ifndef H__GAMELIST__H
#define H__GAMELIST__H

#include <string>
#include <deque>
#include "linked_ptr.h"
#include "device.h"
#include "platform.h"

using namespace std;

class GW_GameList
{
public:
    GW_GameList(GW_Platform *platform);

    int count() { return list_.size(); }
    GW_Game_Info *get(int index);
protected:
    void add(GW_Game_Info *gameinfo);
private:
    void load();

    typedef deque< linked_ptr<GW_Game_Info> > list_t;

    list_t list_;
	GW_Platform *platform_;
};


#endif // H__GAMELIST__H
