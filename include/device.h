#ifndef H__DEVICE__H
#define H__DEVICE__H

#include <map>
#include <string>
#include "linked_ptr.h"
#include "platform.h"

#define GW_INDEX_DEFAULT 0

using namespace std;

// forward declaration
class GW_Device;
class GW_GameData;
class GW_Game;

class GW_GameData_Item
{
public:
    GW_GameData_Item(GW_GameData *gdata) : gdata_(gdata) {}
    virtual ~GW_GameData_Item() {}

    void Changed();
    GW_GameData *gamedata_get() { return gdata_; }
    GW_Platform *platform_get();
private:
    GW_GameData *gdata_;
};

class GW_GameData_Sound : public GW_GameData_Item
{
public:
    GW_GameData_Sound(GW_GameData *gdata, const string &sound) :
        GW_GameData_Item(gdata), sound_(sound), sounddata_(NULL) {}
    ~GW_GameData_Sound();

    void Load(const string &soundpath);

    GW_Platform_Sound *data_get() { return sounddata_; }
private:
    string sound_;
    GW_Platform_Sound *sounddata_;
};

class GW_GameData_Image : public GW_GameData_Item
{
public:
    GW_GameData_Image(GW_GameData *gdata, const string &image,
        GW_Platform_RGB *tcolor = NULL) :
        GW_GameData_Item(gdata), image_(image), imagedata_(NULL),
        istcolor_(tcolor!=NULL) { if (tcolor) tcolor_=*tcolor; }
    ~GW_GameData_Image();

    void Load(const string &imagepath);

    GW_Platform_Image *data_get() { return imagedata_; }
private:
    string image_;
    GW_Platform_Image *imagedata_;
    bool istcolor_;
    GW_Platform_RGB tcolor_;
};

class GW_GameData_Position : public GW_GameData_Item
{
public:
    GW_GameData_Position(GW_GameData *gdata, int x, int y) :
        GW_GameData_Item(gdata),
        x_(x), y_(y), imageid_(-1), imageindex_(-1), status_(-1), visible_(false) {}

    int x_get() { return x_; }
    int y_get() { return y_; }

    int imageid_get() { return imageid_; }
    int imageindex_get() { return imageindex_; }
    void image_set(int imageid, int imageindex, bool doshow = false)
        { imageid_=imageid; imageindex_=imageindex; if (doshow) show(); Changed(); }
    void position_set(int x, int y) { x_=x; y_=y; Changed(); }

    bool visible_get() { return visible_; }
    void visible_set(bool v) { visible_=v; Changed(); }
    void show() { visible_set(true); }
    void hide() { visible_set(false); }

    void show_status(int s) { show(); status_set(s); }
    void hide_status(int s) { hide(); status_set(s); }
    void visible_status(bool v, int s) { visible_set(v); status_set(s); }
    void visible_status(GW_GameData_Position *source) { visible_set(source->visible_get()); status_set(source->status_get()); }

    int status_get() { return status_; }
    void status_set(int s) { status_=s; }
private:
    int x_, y_;
    int imageid_, imageindex_, status_;
    bool visible_;
};

class GW_GameData_Timer : public GW_GameData_Item
{
public:
    GW_GameData_Timer(GW_GameData *gdata, int timerid, unsigned int time, bool autoloop) :
        GW_GameData_Item(gdata),
        timerid_(timerid), time_(time), autoloop_(autoloop), curtime_(0), delay_(0) {}
    ~GW_GameData_Timer() {}

    void start(unsigned int time = 0);
    void stop();
    bool started();
    bool finished();
    void loop();
    void delay(unsigned int time);

    int timerid() { return timerid_; }
    unsigned int time() { return time_; }
    bool autoloop() { return autoloop_; }

    void time_set(unsigned int time) { time_=time; }
private:
    int timerid_;
    unsigned int time_;
    bool autoloop_;
    unsigned int curtime_, delay_;
};

class GW_GameData
{
public:
    typedef map< int, linked_ptr<GW_GameData_Image> > imagesindex_t;
    typedef map< int, linked_ptr<GW_GameData_Position> > positionsindex_t;

    typedef map< int, imagesindex_t > images_t;
    typedef map< int, positionsindex_t > positions_t;
    typedef map< int, linked_ptr<GW_GameData_Sound> > sounds_t;
    typedef map< int, linked_ptr<GW_GameData_Timer> > timers_t;

    GW_GameData(GW_Game *game) : game_(game), images_(), positions_(), sounds_(), timers_() {}

    GW_GameData *image_add(int id, int index, const string &image, GW_Platform_RGB *tcolor = NULL);
    GW_GameData *position_add(int id, int index = GW_INDEX_DEFAULT, int x = 0, int y = 0,
        int imageid = -1, int imageindex = GW_INDEX_DEFAULT,
        const string &image = "", GW_Platform_RGB *tcolor = NULL);
    GW_GameData *position_change(int id, int index = GW_INDEX_DEFAULT, int x = 0, int y = 0);
    GW_GameData *sound_add(int id, const string &sound);
    GW_GameData *timer_add(int timerid, unsigned int time, bool autoloop);

    GW_GameData_Image *image_get(int id, int index = GW_INDEX_DEFAULT);
    GW_GameData_Position *position_get(int id, int index = GW_INDEX_DEFAULT);
    GW_GameData_Sound *sound_get(int id);
    GW_GameData_Timer *timer_get(int timerid);

    //const images_t &images_list() { return images_; }
    const positions_t &positions_list() { return positions_; }
    const sounds_t &sounds_list() { return sounds_; }
    timers_t &timers_list() { return timers_; }

    void Load(const string &gamepath);
    void Unload();

    void Changed();
    GW_Game *game_get() { return game_; }
private:
    GW_Game *game_;
    images_t images_;
    positions_t positions_;
    sounds_t sounds_;
    timers_t timers_;
};


class GW_Game
{
public:
    enum defkeys_t
    {
        //DK_ON,
        //DK_OFF,
        DK_GAMEA,
        DK_GAMEB,
        DK_LEFT,
        DK_RIGHT,
        DK_UP,
        DK_DOWN,
        DK_TIME,
        DK_VOLUP,
        DK_VOLDOWN,
    };

    GW_Game();
    virtual ~GW_Game() {};

    void TurnOn() { if (!on_) { on_=true; do_turnon(); Changed(); } }
    void TurnOff() { if (on_) { do_turnoff(); on_=false; Changed(); } }
    bool IsOn() { return on_; }

    virtual int ModeCount() { return do_modecount(); }
    void SetMode(int mode);
    int GetMode() { return mode_; }

    virtual void Event(GW_Platform_Event *) {}

    void Update();

    void Changed();
    bool CheckChanged();

    GW_Device *device_get() { return device_; }
    GW_Platform *platform_get();

    GW_GameData &data() { return data_; }

    GW_Platform_GameType gametype_get() { if (!IsOn()) return GPG_MENU; return do_gametype_get(); }
    const string &gamepath_get() { return gamepath_; }
    //const string &bgimage_get() { return bgimage_; }
    const GW_Platform_Rect &gamerect_get() { return gamerect_; }
    virtual int bgimage_get() { return -1; }

    void Load(GW_Device *device, const string &datapath);
    void Unload();
protected:
    virtual GW_Platform_GameType do_gametype_get() { return GPG_MENU; }
    virtual void do_turnon() {}
    virtual void do_turnoff() {}
    virtual int do_modecount() { return 0; }
    virtual bool do_setmode(int) { return false; }
    virtual void do_timer(int) {}
    virtual void do_update() {}

    void data_showall();
    void data_hideall(bool resetstatus = false);
    void data_playsound(int soundid);
    void data_stopallsounds();
    void data_starttimer(int timerid, unsigned int time = 0);
    void data_stopalltimers();
    void data_delaytimer(int timerid, unsigned int time);

    void gamepath_set(const string &gamepath) { gamepath_=gamepath; }
    //void bgimage_set(const string &bgimage) { bgimage_=bgimage; }
    void size_set(int width, int height) { width_=width; height_=height; }
    void gamerect_set(const GW_Platform_Rect &gamerect) { gamerect_=gamerect; }
private:
    GW_GameData data_;

    string gamepath_;
    //string bgimage_;
    int width_, height_;
    bool on_;
    int mode_;
    GW_Platform_Rect gamerect_;
    GW_Device *device_;
    bool changed_;
};

class GW_Game_Info
{
public:
    GW_Game_Info(const string &id, const string &description,
        const string &datapath, const string &bgimg, bool istcolor = false,
        const GW_Platform_RGB &tcolor = GW_RGB_BLACK) :
        id_(id), description_(description), datapath_(datapath), bgimg_(bgimg),
        istcolor_(istcolor), tcolor_(tcolor) {}
    virtual ~GW_Game_Info() {}

    const string &id() { return id_; }
    const string &description() { return description_; }
    const string &datapath() { return datapath_; }
    const string &bgimg() { return bgimg_; }
    bool istcolor() { return istcolor_; }
    GW_Platform_RGB &tcolor() { return tcolor_; }

    string bgimg_path();
    virtual GW_Game *create() = 0;
private:
    string id_, description_, datapath_, bgimg_;
    bool istcolor_;
    GW_Platform_RGB tcolor_;
};

class GW_Device
{
public:
    typedef struct devtime_t
    {
        short d, m, y;
        short h, n, s;
    };

    GW_Device(GW_Platform *platform);
    ~GW_Device();

    void MoveBG(int xpos, int ypos);
    void MoveBGOffset(int xoff, int yoff);
    void MoveBGCenter();

    bool IsOn() { return game_->IsOn(); }
    void TurnOn() { MoveBGCenter(); game_->TurnOn(); curtime_=platform_->ticks_get(); }
    void TurnOff() { game_->TurnOff(); }
    void SetMode(int mode) { game_->SetMode(mode); }
    void Volume(int volume);
    int Volume() { return volume_; }

    void Run(GW_Game *game);
    void Quit() { quit_=true; }

    void GetTime(devtime_t *time);

    GW_Platform *platform_get() { return platform_; }
private:
    void draw_game();

    void Load();
    void Unload();

    GW_Platform_Point position(GW_GameData_Position *pos);

    bool process_event(GW_Platform_Event *event);

    void CalculateBGOffset();

    GW_Platform *platform_;
    GW_Game *game_;
    string datapath_;
    bool quit_;

    //GW_Platform_Image *bg_;
    int offsetx_, offsety_;
    GW_Platform_Rect bgsrc_, bgdst_;
    int volume_;

    unsigned int curtime_;
};


#endif //H__DEVICE__H
