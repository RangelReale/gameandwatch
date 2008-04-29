#ifndef H__DEV_MONKEY__H
#define H__DEV_MONKEY__H

#include <list>
#include "device.h"

using namespace std;

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
        IDX_GOT = 6,
        IDX_MISS,
        IDX_TARGET,
    };

    enum
    {
        SND_GAMEOVER,
        SND_GOT,
        SND_MISS,
        SND_MOVE,
        SND_START
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

    virtual void DefaultKey(defkeys_t key);

    virtual unsigned int TickTime();
    virtual void Tick();
    virtual void Update();
    bool IsGame() { return (GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB); }
protected:
    virtual void do_turnon();
    virtual void do_turnoff();
    virtual int do_modecount() { return MODE_MAX; }
    virtual bool do_setmode(int mode);
private:
    void clock_update();
    void setnumber(int n, int ps1, int ps2);

    void game_start(bool gamea);
    void game_update();
    void game_tick();

    void item_add(int id);

    void score_update();

    void char_update(int pos, bool hit);
    void item_tick();
    void item_update();

    const unsigned int START_DELAY_VALUE;
    list<GW_Game_Monkey_Item> items_;

    mode_t mode_;
    int score_;
    int char_position_;
    unsigned short tick_, ticksum_;
    unsigned int startdelay_;
};

#endif //H__DEV_MONKEY__H
