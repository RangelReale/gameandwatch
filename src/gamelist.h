#ifndef H__GAMELIST__H
#define H__GAMELIST__H

#include <string>
#include <deque>
#include <boost/shared_ptr.hpp>
#include "device.h"

using namespace std;
using namespace boost;

class GW_GameList
{
public:
    GW_GameList();

    int count() { return list_.size(); }
    GW_Game_Info *get(int index);
protected:
    void add(GW_Game_Info *gameinfo);
private:
    void load();

    typedef deque< shared_ptr<GW_Game_Info> > list_t;

    list_t list_;
};


#endif // H__GAMELIST__H
