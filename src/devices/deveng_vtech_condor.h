#ifndef H__DEVENG_VTECH_CONDOR__H
#define H__DEVENG_VTECH_CONDOR__H

#include "device.h"
#include "devices/deveng_vtech.h"

using namespace std;

class GW_GameEngine_VTech_Condor : public GW_GameEngine_VTech
{
public:
    enum options_t
    {
        GO_HAVEITEM0 = 1,
        GO_HAVELEFT0 = 2,
        GO_HAVERIGHT1A = 4,
        GO_HAVERIGHT6 = 8,
    };

    enum
    {
        PS_CHAR = PS_VTECH_MAX,
        PS_ITEM,
        PS_ITEMLEFT,
        PS_ITEMRIGHT,
    };

    enum
    {
        IM_CHAR = IM_VTECH_MAX,
        IM_ITEM,
        IM_ITEMLEFT,
        IM_ITEMRIGHT,
    };

    enum
    {
        IDX_RIGTH_1B = 10,

        IDX_MAX = 27,
        IDX_MISS_1,
        IDX_MISS_2,
        IDX_MISS_3,

        IDX_MISS,
        IDX_GOT,
        IDX_TARGET,
        IDX_HIT,
    };

    GW_GameEngine_VTech_Condor(int engineoptions, int options);

    virtual void Event(GW_Platform_Event *event);
protected:
    virtual void do_timer(int timerid);

    virtual void game_start(int mode);
    virtual void game_tick();
    virtual void game_reprise();
    virtual void level_update(int mode = -1);
private:
    void char_update(int pos, bool hit);

    int options_;
    int char_position_;
    unsigned short tick_;
    unsigned short maxonscreen_;
};


#endif //H__DEVENG_VTECH_CONDOR__H
