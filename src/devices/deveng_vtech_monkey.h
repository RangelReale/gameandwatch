#ifndef H__DEVENG_VTECH_MONKEY__H
#define H__DEVENG_VTECH_MONKEY__H

#include "device.h"
#include "deveng_vtech.h"

using namespace std;

class GW_GameEngine_VTech_Monkey : public GW_GameEngine_VTech
{
public:
    enum options_t
    {
        GO_NONE             = 0,
        GO_HAVETARGET       = 1,
    };

    enum
    {
        PS_CHAR_1 = PS_VTECH_MAX,
        PS_CHAR_2,
        PS_CHAR_3,
        PS_ITEM_1,
        PS_ITEM_2,
        PS_ITEM_3,
    };

    enum
    {
        IM_CHAR_1 = IM_VTECH_MAX,
        IM_CHAR_2,
        IM_CHAR_3,
        IM_ITEM_1,
        IM_ITEM_2,
        IM_ITEM_3,
    };

    enum
    {
        IDX_MAX = 5,
        IDX_GOT,
        IDX_MISS,
        IDX_TARGET,
        IDX_HIT,
    };

    enum
    {
        SND_GAMEOVER,
        SND_GOT,
        SND_MISS,
        SND_MOVE,
        SND_START
    };

    enum
    {
        TMR_HIT = TMR_VTECH_MAX,
    };

    GW_GameEngine_VTech_Monkey(int engineoptions, int options);

    virtual void Event(GW_Platform_Event *event);
protected:
    virtual void do_timer(int timerid);

    virtual void game_start(int mode);
    virtual void game_tick();
    virtual void game_reprise();
    virtual void game_over() { data_playsound(SND_GAMEOVER); }
    virtual void level_update(int mode = -1);
private:
    void char_update(int pos, bool hit);

    void showall_target(bool b);
    void showall_miss(bool b);
    void showall_got(bool b);

    int options_;
    int char_position_;
    unsigned short tick_;
    unsigned short maxonscreen_;
};


#endif //H__DEVENG_VTECH_MONKEY__H
