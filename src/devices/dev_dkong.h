#ifndef H__DEV_DKONG__H
#define H__DEV_DKONG__H

#include "device.h"

using namespace std;

class GW_Game_DKong_Info : public GW_Game_Info
{
public:
    GW_Game_DKong_Info() :
        GW_Game_Info("dkong", "Nintendo - Donkey Kong", "dkong",
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};

class GW_Game_DKong : public GW_Game
{
public:
    enum
    {
        PS_BG,
        PS_BAR,
        PS_HOOK,
        PS_CRANE,
        PS_HEART,
        PS_KEY,
        PS_KONGUP,
        PS_KONGDOWN,
        PS_KONGFALL,
        PS_LEVER,
        PS_MARIO,
        PS_PLAT,
        PS_BINDER,
        PS_LIFE,

        PS_NUMBER,
        PS_SEMICOLON,
        PS_ALARM,
        PS_GAMEA,
        PS_GAMEB,
        PS_AM,
        PS_PM,
    };

    enum
    {
        IM_BG,
        IM_BAR,
        IM_HOOK,
        IM_CRANE,
        IM_HEART,
        IM_KEY,
        IM_KONGUP,
        IM_KONGDOWN,
        IM_KONGFALL,
        IM_LEVER,
        IM_MARIO,
        IM_PLAT,
        IM_BINDER,
        IM_LIFE,

        IM_NUMBER,
        IM_SEMICOLON,
        IM_ALARM,
        IM_GAMEA,
        IM_GAMEB,
        IM_AM,
        IM_PM,
    };

    enum
    {
        SND_BARREL,
        SND_BONUS,
        SND_FALL,
        SND_JUMP,
        SND_KONGFALL,
        SND_MISS,
        SND_OVER,
        SND_STEP,
    };

    enum mode_t
    {
        MODE_OFF,
        MODE_IDLE,
        MODE_GAMEA,
        MODE_GAMEB,
        MODE_TIME,
        MODE_ALARM,
        MODE_MAX,
    };


    GW_Game_DKong();

    virtual void Event(GW_Platform_Event *event);

    virtual GW_Platform_GameType gametype_get() { return GPG_LEFTRIGHT; }
    virtual int bgimage_get() { return IM_BG; }
protected:
    virtual void do_turnon();
    virtual void do_turnoff();
    virtual int do_modecount() { return MODE_MAX; }
    virtual void do_update();

    virtual bool do_setmode(int mode);
private:
    void clock_update(int mode = -1);
    void setnumber(int n, int ps1, int ps2, bool leadzero = true);
    void display_number(int pos, int n, bool show = true);
};

#endif //H__DEV_DKONG__H
