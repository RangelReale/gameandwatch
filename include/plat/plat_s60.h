#ifndef H__PLAT_S60__H
#define H__PLAT_S60__H

#include "plat/plat_sdl.h"

class GW_PlatformS60 : public GW_PlatformSDL
{
public:
	GW_PlatformS60() : GW_PlatformSDL(320, 240) {}
    virtual ~GW_PlatformS60();
protected:
    virtual void custom_initialize();
    virtual void custom_finalize();

    virtual int sdlinit(int flags) { return flags|SDL_INIT_JOYSTICK; }
    virtual int audiobufsize_get() { return 128; }

    virtual bool process_event(GW_Platform_GameType gametype,
        SDL_Event *sdlevent, GW_Platform_Event *event);
};


#endif //H__PLAT_S60__H
