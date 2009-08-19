#ifndef H__DEVENG_VTECH__H
#define H__DEVENG_VTECH__H

#include "device.h"

using namespace std;

class GW_GameEngine_VTech : public GW_Game
{
public:
    enum engineoptions_t
    {
        EO_NONE                     = 0,
        EO_NUMBERSEPARATED          = 1,
        EO_MISSSEPARATED            = 2,
    };

    enum
    {
        PS_NUMBER,
        PS_SEMICOLON,
        PS_MISS,
        PS_GAMEA,
        PS_GAMEB,
        PS_ALARM,
        PS_BELL,
        PS_CHRONO,
        PS_DATE,
        PS_TIME1,
        PS_TIME2,
        PS_AM,
        PS_PM,
        PS_VTECH_MAX
    };

    enum
    {
        IM_BG,
        IM_NUMBER,
        IM_SEMICOLON,
        IM_MISS,
        IM_GAMEA,
        IM_GAMEB,
        IM_ALARM,
        IM_BELL,
        IM_CHRONO,
        IM_DATE,
        IM_TIME1,
        IM_TIME2,
        IM_AM,
        IM_PM,
        IM_VTECH_MAX
    };

    enum
    {
        TMR_GAME,
        TMR_GAMESTART,
        TMR_REPRISE,
        TMR_GAMEOVER,
        TMR_GAMEOVERSOUND,
        TMR_GAMEOVERWAIT,
        TMR_VTECH_MAX
    };

    enum mode_t
    {
        MODE_OFF,
        MODE_IDLE,
        MODE_DEMO,
        MODE_GAMEA,
        MODE_GAMEB,
        MODE_TIME1,
        MODE_TIME2,
        MODE_ALARM,
        MODE_CHRONO,
        MODE_DATE,
        MODE_MAX,
    };

    GW_GameEngine_VTech(int engineoptions);

    //virtual void DefaultKey(defkeys_t key);
    virtual void Event(GW_Platform_Event *event);


    virtual int bgimage_get() { return IM_BG; }

    bool IsGame() { return (GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB); }
protected:
    virtual GW_Platform_GameType do_gametype_get() { return GPG_LEFTRIGHT; }
    virtual void do_turnon();
    virtual void do_turnoff();
    virtual int do_modecount() { return MODE_MAX; }
    virtual bool do_setmode(int mode);
    virtual void do_timer(int timerid);
    virtual void do_update();

    virtual void game_start(int) {}
    virtual void game_reprise() {}
    virtual void game_over() {}
    virtual void level_update(int mode = -1);
    virtual void game_tick();

    void score_add(int count=1);
    void misses_add(int count=1);

    bool canmove_get() { return canmove_; }
    void canmove_set(bool c) { canmove_=c; }

    int score_get() { return score_; }
    int misses_get() { return misses_; }
private:
    void clock_update(int mode = -1);
    void setnumber(int n, int ps1, int ps2, bool leadzero = true);

    void display_number(int pos, int n, bool show = true);

    void do_game_start(int mode);

    void score_update();

    void miss_update();

    int engineoptions_;
    mode_t mode_;
    int score_;
    int misses_;
    bool canmove_, gameover_;
};


#endif //H__DEVENG_VTECH__H
