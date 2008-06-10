#ifndef H__DEVENG_VTECH_BANANA__H
#define H__DEVENG_VTECH_BANANA__H

#include "device.h"
#include "deveng_vtech.h"

using namespace std;

class GW_GameEngine_VTech_Banana : public GW_GameEngine_VTech
{
public:
    enum options_t
    {
        GO_NONE = 0,
        GO_HAVECHARANIM = 1,
        GO_HAVEOBSTACLE17 = 2
    };

    enum
    {
        PS_CHAR_1 = PS_VTECH_MAX,
        PS_CHAR_2,
        PS_CHAR_3,
        PS_CHAR_4,
        PS_ITEM_1,
        PS_ITEM_2
    };

    enum
    {
        IM_CHAR_1 = IM_VTECH_MAX,
        IM_CHAR_2,
        IM_CHAR_3,
        IM_CHAR_4,
        IM_ITEM_1,
        IM_ITEM_2
    };

    enum
    {
        IDX_MISS_4 = 11,
        IDX_OBSTACLE_4,
        IDX_MISS_7,
        IDX_OBSTACLE_7
    };

    enum
    {
        SND_HIGH,
        SND_LOW,
        SND_MISS,
        SND_OVER,
        SND_SAFE,
        SND_START
    };


    GW_GameEngine_VTech_Banana(int engineoptions, int options);

    virtual GW_Platform_GameType gametype_get() { return GPG_4DIAG; }
    virtual void Event(GW_Platform_Event *event);
protected:
    virtual void game_start(int mode);
    virtual void game_tick();
private:
    void char_update(int pos, bool hit);

    int tick_, char_position_;
    int options_;
};


#endif //H__DEVENG_VTECH_BANANA__H

