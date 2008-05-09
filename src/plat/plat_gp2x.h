#ifndef H__PLAT_GP2X__H
#define H__PLAT_GP2X__H

#include "plat/plat_sdl.h"

class GW_PlatformGP2X : public GW_PlatformSDL
{
public:
    GW_PlatformGP2X() : GW_PlatformSDL(320, 240) {}
    virtual ~GW_PlatformGP2X();

    virtual unsigned int time_ms_get() { return SDL_GetTicks(); } // gp2x doesn't have RTC
protected:
    virtual void custom_initialize();
    virtual void custom_finalize();

    virtual int sdlinit(int flags) { return flags|SDL_INIT_JOYSTICK; }
    virtual int audiobufsize_get() { return 128; }

    virtual bool process_event(SDL_Event *sdlevent, GW_Platform_Event *event);
};


#endif //H__PLAT_GP2X__H
