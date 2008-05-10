#ifndef H__DEV_MONKEY__H
#define H__DEV_MONKEY__H

#include <list>
#include "device.h"

using namespace std;



class GW_Game_Monkey_Info : public GW_Game_Info
{
public:
    GW_Game_Monkey_Info() :
        GW_Game_Info("monkey", "Game & Watch - Monkey", "monkey",
            "bg.bmp", true, GW_Platform_RGB_create(255, 0, 255)) {}

    virtual GW_Game *create();
};


typedef struct GW_Game_Monkey_Item
{
    unsigned short id;
    unsigned short position;
};

class GW_Game_Monkey : public GW_Game
{
public:
    enum
    {
        PS_CHAR_1,
        PS_CHAR_2,
        PS_CHAR_3,
        PS_ITEM_1,
        PS_ITEM_2,
        PS_ITEM_3,
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
        IM_CHAR_1,
        IM_CHAR_2,
        IM_CHAR_3,
        IM_ITEM_1,
        IM_ITEM_2,
        IM_ITEM_3,
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
        TMR_GAME,
        TMR_GAMESTART,
        TMR_HIT,
        TMR_REPRISE,
        TMR_GAMEOVER,
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

    GW_Game_Monkey();

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
    void clock_update();
    void setnumber(int n, int ps1, int ps2);

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

    mode_t mode_;
    int score_;
    int char_position_;
    unsigned short tick_;
    unsigned short maxonscreen_;
    int misses_;
    bool canmove_, gameover_;
};

#endif //H__DEV_MONKEY__H
