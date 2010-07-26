#ifndef H__PLAT_SDL__H
#define H__PLAT_SDL__H

#include <SDL.h>
#ifndef GW_NO_SDL_MIXER
#include <SDL_mixer.h>
#endif
#ifndef GW_NO_SDL_TTF
#include <SDL_ttf.h>
#endif
#ifndef GW_NO_SDL_GFX
#include <SDL_gfxPrimitives.h>
#include <SDL_rotozoom.h>
#endif
#if defined(_WIN32) && !defined(GW_NO_WIN32)
#include <SDL_syswm.h>
#include <windows.h>
#endif //_WIN32

#include "platform.h"

class GW_PlatformSDL_Image : public GW_Platform_Image
{
public:
    GW_PlatformSDL_Image(const string &filename, GW_Platform_RGB *tcolor = NULL);
    virtual ~GW_PlatformSDL_Image();

    virtual int width_get() { return surface_->w; }
    virtual int height_get() { return surface_->h; }

    virtual bool resize_fit(int w, int h);

    SDL_Surface *surface_get() { return surface_; }
private:
    SDL_Surface *surface_;
};

class GW_PlatformSDL_Sound : public GW_Platform_Sound
{
public:
    GW_PlatformSDL_Sound(const string &filename);
    virtual ~GW_PlatformSDL_Sound();

#ifndef GW_NO_SDL_MIXER
    Mix_Chunk *sample_get() { return sample_; }
private:
    Mix_Chunk *sample_;
#endif
};

class GW_PlatformSDL : public GW_Platform
{
public:
    GW_PlatformSDL(int width, int height);
    virtual ~GW_PlatformSDL();

    virtual void initialize();
    virtual void finalize();

    virtual int width_get() { return width_; }
    virtual int height_get() { return height_; }
    virtual unsigned int ticks_get();
    virtual unsigned int time_ms_get();
    virtual GW_Platform_Time time_get();

    virtual bool event(GW_Platform_GameType gametype,
        GW_Platform_Event *event);

    virtual void draw_clear();
    virtual void draw_image(GW_Platform_Image *image, int x, int y);
    virtual void draw_line(int x1, int y1, int x2, int y2,
        GW_Platform_RGB *color = NULL);
    virtual void draw_rectangle(int x1, int y1, int x2, int y2,
        GW_Platform_RGB *forecolor = NULL, GW_Platform_RGB *backcolor = NULL,
        int alpha = -1);
    virtual void draw_flip();

    virtual void text_draw(int x, int y, const string &text, GW_Platform_RGB *color = NULL);
    virtual int text_fontheight();
    virtual int text_width(const string &text);
    virtual int text_height(const string &text);

    virtual void sound_play(GW_Platform_Sound *sound);
    virtual unsigned short sound_volume(unsigned short volume);
    virtual void sound_stop_all();

    virtual GW_Platform_Image *image_load(const string &filename, GW_Platform_RGB *tcolor = NULL);
    virtual GW_Platform_Sound *sound_load(const string &filename);
protected:
    virtual void custom_initialize() {}
    virtual void custom_finalize() {}

    virtual int sdlinit(int flags) { return flags|SDL_INIT_JOYSTICK; }
    virtual int sdlvideomode(int flags) { return flags; }
    virtual int audiobufsize_get() { return 2048; }
    virtual int fontsize_get() { return 16; }

    virtual bool process_event(GW_Platform_GameType gametype,
        SDL_Event *sdlevent, GW_Platform_Event *event);
private:
    void plat_init();
    void plat_finish();

    int width_, height_;
    bool initialized_;

#ifndef GW_NO_SDL_TTF
    TTF_Font *font_;
#endif
    SDL_Surface *screen_;
#if defined(_WIN32) && !defined(GW_NO_WIN32)
    HICON icon_;
#endif
};

#endif //H__PLAT_SDL__H
