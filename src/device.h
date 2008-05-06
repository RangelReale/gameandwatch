#ifndef H__DEVICE__H
#define H__DEVICE__H

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

#include <SDL.h>
#include <SDL_mixer.h>

#define GW_INDEX_DEFAULT 0

using namespace std;
using namespace boost;

// forward declaration
class GW_Device;

class GW_GameData_Sound
{
public:
    GW_GameData_Sound(const string &sound) :
        sound_(sound), sample_(NULL) {}
    ~GW_GameData_Sound();

    void Load(const string &soundpath);

    Mix_Chunk *sample_get() { return sample_; }
private:
    string sound_;
    Mix_Chunk *sample_;
};

class GW_GameData_Image
{
public:
    GW_GameData_Image(const string &image) :
        image_(image), surface_(NULL) {}
    ~GW_GameData_Image();

    void Load(const string &imagepath);

    SDL_Surface *surface_get() { return surface_; }
private:
    string image_;
    SDL_Surface *surface_;
};

class GW_GameData_Position
{
public:
    GW_GameData_Position(int x, int y) :
        x_(x), y_(y), imageid_(-1), imageindex_(-1), visible_(false) {}

    int x_get() { return x_; }
    int y_get() { return y_; }

    int imageid_get() { return imageid_; }
    int imageindex_get() { return imageindex_; }
    void image_set(int imageid, int imageindex, bool doshow = false)
        { imageid_=imageid; imageindex_=imageindex; if (doshow) show(); }

    bool visible_get() { return visible_; }
    void visible_set(bool v) { visible_=v; }
    void show() { visible_set(true); }
    void hide() { visible_set(false); }
private:
    int x_, y_;
    int imageid_, imageindex_;
    bool visible_;
};

class GW_GameData_Timer
{
public:
    GW_GameData_Timer(int timerid, unsigned int time, bool autoloop) :
        timerid_(timerid), time_(time), autoloop_(autoloop), curtime_(0) {}
    ~GW_GameData_Timer() {}

    void start(unsigned int time = 0);
    void stop();
    bool started();
    bool finished();

    int timerid() { return timerid_; }
    unsigned int time() { return time_; }
    bool autoloop() { return autoloop_; }

    void time_set(unsigned int time) { time_=time; }
private:
    int timerid_;
    unsigned int time_;
    bool autoloop_;
    unsigned int curtime_;
};

class GW_GameData
{
public:
    typedef map< int, shared_ptr<GW_GameData_Image> > imagesindex_t;
    typedef map< int, shared_ptr<GW_GameData_Position> > positionsindex_t;

    typedef map< int, imagesindex_t > images_t;
    typedef map< int, positionsindex_t > positions_t;
    typedef map< int, shared_ptr<GW_GameData_Sound> > sounds_t;
    typedef map< int, shared_ptr<GW_GameData_Timer> > timers_t;

    GW_GameData() : images_(), positions_(), sounds_(), timers_() {}

    GW_GameData *image_add(int id, int index, const string &image);
    GW_GameData *position_add(int id, int index = GW_INDEX_DEFAULT, int x = 0, int y = 0,
        int imageid = -1, int imageindex = GW_INDEX_DEFAULT,
        const string &image = "");
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
private:
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

    void TurnOn() { if (!on_) { on_=true; do_turnon(); } }
    void TurnOff() { if (on_) { do_turnoff(); on_=false; } }
    bool IsOn() { return on_; }

    virtual int ModeCount() { return do_modecount(); }
    void SetMode(int mode) { if (IsOn()) { mode_=mode; do_setmode(mode); } }
    int GetMode() { return mode_; }

    virtual void DefaultKey(defkeys_t key) {}

    void Update();

    GW_Device *device_get() { return device_; }
    GW_GameData &data() { return data_; }

    const string &gamepath_get() { return gamepath_; }
    const string &bgimage_get() { return bgimage_; }
    const SDL_Rect &gamerect_get() { return gamerect_; }

    void Load(GW_Device *device, const string &datapath);
protected:
    virtual void do_turnon() {}
    virtual void do_turnoff() {}
    virtual int do_modecount() { return 0; }
    virtual void do_setmode(int mode) {}
    virtual void do_timer(int timerid) {}
    virtual void do_update() {}

    void data_showall();
    void data_hideall();
    void data_playsound(int soundid);
    void data_starttimer(int timerid, unsigned int time = 0);
    void data_stopalltimers();

    void gamepath_set(const string &gamepath) { gamepath_=gamepath; }
    void bgimage_set(const string &bgimage) { bgimage_=bgimage; }
    void size_set(int width, int height) { width_=width; height_=height; }
    void gamerect_set(const SDL_Rect &gamerect) { gamerect_=gamerect; }
private:
    GW_GameData data_;

    string gamepath_;
    string bgimage_;
    int width_, height_;
    bool on_;
    int mode_;
    SDL_Rect gamerect_;
    GW_Device *device_;
};

class GW_Platform
{
public:
    GW_Platform() : device_(NULL) {}
    virtual ~GW_Platform() { }

    virtual int sdlinit(int flags) { return flags; }

    virtual void initialize() {}
    virtual void finalize() {}

    void device_set(GW_Device *device) { device_=device; }

    void process_event(SDL_Event *event) { if (device_) _process_event(event); }
    virtual int width_get() = 0;
    virtual int height_get() = 0;
    virtual unsigned int timems_get() { return SDL_GetTicks(); }
    virtual int audiobufsize_get() { return 2048; }
protected:
    GW_Device *device_get() { return device_; }

    virtual void _process_event(SDL_Event *event) = 0;
private:
    GW_Device *device_;
};

class GW_Device
{
public:
    typedef struct devtime_t
    {
        short h, m, s;
    };

    GW_Device(GW_Platform *platform, GW_Game *game);
    ~GW_Device();

    void MoveBG(int xpos, int ypos);
    void MoveBGOffset(int xoff, int yoff);
    void MoveBGCenter();

    void TurnOn() { game_->TurnOn(); curtime_=SDL_GetTicks(); }
    void TurnOff() { game_->TurnOff(); }
    void SetMode(int mode) { game_->SetMode(mode); }
    void DefaultKey(GW_Game::defkeys_t key) { game_->DefaultKey(key); }

    void Run();
    void Quit() { quit_=true; }

    void GetTime(devtime_t *time);

    GW_Platform *platform_get() { return platform_; }
private:
    void draw_game();

    void Load();
    void Unload();

    SDL_Rect position(GW_GameData_Position *pos);

    void CalculateBGOffset();

    GW_Platform *platform_;
    GW_Game *game_;
    string datapath_;
    bool quit_;

    SDL_Surface *screen_, *bg_;
    int offsetx_, offsety_;
    SDL_Rect bgsrc_, bgdst_;

    unsigned int curtime_;
};


#endif //H__DEVICE__H
