#ifndef H__DEVENG_VTECH_CONDOR__H
#define H__DEVENG_VTECH_CONDOR__H


#include <list>
#include "device.h"

using namespace std;

typedef struct GW_GameEngine_VTech_Condor_Item
{
    unsigned short id;
    unsigned short position;
};

class GW_GameEngine_VTech_Condor : public GW_Game
{
public:
    enum options_t
    {
        GO_HAVEITEM0 = 1,
        GO_HAVELEFT0 = 2,
        GO_HAVERIGHT1A = 4,
        GO_HAVERIGHT6 = 8,

        GO_HAVETARGET = 1000,
        GO_NUMBERSEPARATED = 2000,
    };

    enum
    {
        PS_CHAR,
        PS_ITEM,
        PS_ITEMLEFT,
        PS_ITEMRIGHT,
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
    };

    enum
    {
        IM_BG,
        IM_CHAR,
        IM_ITEM,
        IM_ITEMLEFT,
        IM_ITEMRIGHT,
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
        TMR_GAME,
        TMR_GAMESTART,
        TMR_HIT,
        TMR_REPRISE,
        TMR_GAMEOVER,
        TMR_GAMEOVERSOUND,
        TMR_GAMEOVERWAIT,
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

    GW_GameEngine_VTech_Condor(int options);

    //virtual void DefaultKey(defkeys_t key);
    virtual void Event(GW_Platform_Event *event);


    virtual GW_Platform_GameType gametype_get() { return GPG_LEFTRIGHT; }
    virtual int bgimage_get() { return IM_BG; }

    bool IsGame() { return (GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB); }
protected:
    virtual void do_turnon();
    virtual void do_turnoff();
    virtual int do_modecount() { return MODE_MAX; }
    virtual bool do_setmode(int mode);
    virtual void do_timer(int timerid);
    virtual void do_update();
private:
    void clock_update(int mode = -1);
    void setnumber(int n, int ps1, int ps2, bool leadzero = true);

    void display_number(int pos, int n, bool show = true);

    void game_start(int mode);
    void game_update();
    void game_tick();

    void score_update();
    void level_update(int mode = -1);

    void char_update(int pos, bool hit);
    void item_tick();
    void miss_update();

    void showall_target(bool b);
    void showall_miss(bool b);
    void showall_got(bool b);

    int options_;
    mode_t mode_;
    int score_;
    int char_position_;
    unsigned short tick_;
    unsigned short maxonscreen_;
    int misses_;
    bool canmove_, gameover_;
};


#endif //H__DEVENG_VTECH_CONDOR__H
