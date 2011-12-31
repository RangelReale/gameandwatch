#ifndef H__PLAT_IOS__H
#define H__PLAT_IOS__H

#include "plat/plat_sdl.h"

class GW_PlatformIOS : public GW_PlatformSDL
{
public:
    GW_PlatformIOS() : GW_PlatformSDL(0, 0, true, true) {}
    
    //virtual unsigned int time_ms_get() { return SDL_GetTicks(); } // gp2x doesn't have RTC
protected:
    //virtual int sdlvideomode(int flags) { return GW_PlatformSDL::sdlvideomode(flags|SDL_FULLSCREEN); }
    
    virtual bool process_event(GW_Platform_GameType gametype,
                               SDL_Event *sdlevent, GW_Platform_Event *event);
};


#endif //H__PLAT_IOS__H
