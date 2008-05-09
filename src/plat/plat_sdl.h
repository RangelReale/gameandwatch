#ifndef H__PLAT_SDL__H
#define H__PLAT_SDL__H

#include <SDL.h>
#include <SDL_mixer.h>

#include "platform.h"

class GW_PlatformSDL_Image : public GW_Platform_Image
{
public:
    GW_PlatformSDL_Image(const string &filename, GW_Platform_RGB *tcolor = NULL);
    virtual ~GW_PlatformSDL_Image();

    SDL_Surface *surface_get() { return surface_; }
private:
    SDL_Surface *surface_;
};

class GW_PlatformSDL_Sound : public GW_Platform_Sound
{
public:
    GW_PlatformSDL_Sound(const string &filename);
    virtual ~GW_PlatformSDL_Sound();

    Mix_Chunk *sample_get() { return sample_; }
private:
    Mix_Chunk *sample_;
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

    virtual bool event(GW_Platform_Event *event);

    virtual void draw_clear();
    virtual void draw_image(GW_Platform_Image *image, int x, int y);
    virtual void draw_flip();

    virtual void sound_play(GW_Platform_Sound *sound);
    virtual unsigned short sound_volume(unsigned short volume);

    virtual GW_Platform_Image *image_load(const string &filename, GW_Platform_RGB *tcolor = NULL);
    virtual GW_Platform_Sound *sound_load(const string &filename);
protected:
    virtual void custom_initialize() {}
    virtual void custom_finalize() {}

    virtual int sdlinit(int flags) { return flags|SDL_INIT_JOYSTICK; }
    virtual int audiobufsize_get() { return 2048; }

    virtual bool process_event(SDL_Event *sdlevent, GW_Platform_Event *event);
private:
    int width_, height_;
    bool initialized_;

    SDL_Surface *screen_;
};

#endif //H__PLAT_SDL__H
