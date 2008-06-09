#ifndef H__PLATFORM__H
#define H__PLATFORM__H

#include <string>

using namespace std;

#define GW_PLATFORM_RGB(ps, pr, pg, pb) \
    GW_Platform_RGB ps; ps.r=pr; ps.g=pg; ps.b=pb;
#define GW_PLATFORM_POINT(ps, px, py) \
    GW_Platform_Point ps; ps.x=px; ps.y=py;
#define GW_PLATFORM_RECT(ps, px, py, pw, ph) \
    GW_Platform_Rect ps; ps.x=px; ps.y=py; ps.w=pw; ps.h=ph;

#define MAKE_GW_PLATFORM_RECT(ps, px, py, pw, ph) \
    ps.x=px; ps.y=py; ps.w=pw; ps.h=ph;



typedef struct GW_Platform_RGB
{
    unsigned char r, g, b;
};

typedef struct GW_Platform_Point
{
    int x, y;
};

typedef struct GW_Platform_Rect
{
    int x, y, w, h;
};

enum GW_Platform_EventID
{
    GPE_QUIT,
    GPE_KEYDOWN,
    GPE_KEYUP,
};

enum GW_Platform_EventID_Keys
{
    GPK_UP,
    GPK_DOWN,
    GPK_LEFT,
    GPK_RIGHT,
    GPK_TURNON,
    GPK_TURNOFF,
    GPK_TURNONTOGGLE,
    GPK_QUIT,
    GPK_VOLUP,
    GPK_VOLDOWN,
    GPK_GAMEA,
    GPK_GAMEB,
    GPK_TIME,
};

typedef struct GW_Platform_Event
{
    GW_Platform_EventID id;
    int data;
};

enum GW_Platform_GameType
{
    GPG_MENU,
    GPG_LEFTRIGHT,
    GPG_UPDOWN,
    GPG_4DIAG,
    GPG_LRUDB,   // LEFT RIGHT UP DOWN BUTTONS
};

typedef struct GW_Platform_Time
{
    short d, m, y;
    short h, n, s;
};

extern const char* GW_Platform_DataPath;

// constants
const GW_Platform_RGB GW_RGB_BLACK = {0, 0, 0};

GW_Platform_RGB GW_Platform_RGB_create(int r, int g, int b);

class GW_Platform_Image
{
public:
    GW_Platform_Image() {}
    virtual ~GW_Platform_Image() {};

    virtual int width_get() { return -1; }
    virtual int height_get() { return -1; }

    virtual bool resize_fit(int w, int h) { return false; }
};

class GW_Platform_Sound
{
public:
    GW_Platform_Sound() {}
    virtual ~GW_Platform_Sound() {};
};

class GW_Platform
{
public:
    GW_Platform() {}
    virtual ~GW_Platform() {}

    virtual void initialize() = 0;
    virtual void finalize() = 0;

    virtual int width_get() = 0;
    virtual int height_get() = 0;
    virtual string platformdata_get() { return GW_Platform_DataPath + string("/gamewatch"); }

    virtual unsigned int ticks_get() = 0;
    virtual unsigned int time_ms_get() = 0;
    virtual GW_Platform_Time time_get() = 0;

    virtual bool event(GW_Platform_GameType gametype,
        GW_Platform_Event *event) = 0;

    virtual void draw_clear() = 0;
    virtual void draw_image(GW_Platform_Image *image, int x, int y) = 0;
    virtual void draw_line(int x1, int y1, int x2, int y2,
        GW_Platform_RGB *color = NULL) = 0;
    virtual void draw_rectangle(int x1, int y1, int x2, int y2,
        GW_Platform_RGB *forecolor = NULL, GW_Platform_RGB *backcolor = NULL,
        int alpha = -1) = 0;
    virtual void draw_flip() = 0;

    virtual void text_draw(int x, int y, const string &text,
        GW_Platform_RGB *color = NULL) = 0;
    virtual int text_fontheight() = 0;
    virtual int text_width(const string &text) = 0;
    virtual int text_height(const string &text) = 0;

    virtual void sound_play(GW_Platform_Sound *sound) = 0;
    virtual unsigned short sound_volume(unsigned short volume) = 0;
    virtual void sound_stop_all() = 0;

    virtual GW_Platform_Image *image_load(const string &filename, GW_Platform_RGB *tcolor = NULL) = 0;
    virtual GW_Platform_Sound *sound_load(const string &filename) = 0;
};

#endif //H__PLATFORM__H
