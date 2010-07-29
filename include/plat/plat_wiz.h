#ifndef H__PLAT_WIZ__H
#define H__PLAT_WIZ__H

#include "plat/plat_sdl.h"

class GW_PlatformWIZ : public GW_PlatformSDL
{
public:
    GW_PlatformWIZ();
    virtual ~GW_PlatformWIZ();

    virtual unsigned int time_ms_get();
protected:
    virtual void custom_initialize();
    virtual void custom_finalize();

    virtual int sdlinit(int flags) { return flags|SDL_INIT_JOYSTICK; }
    virtual int audiobufsize_get() { return 128; }

    virtual bool process_event(GW_Platform_GameType gametype,
        SDL_Event *sdlevent, GW_Platform_Event *event);

private:
    int m_MEM;
    volatile uint32_t* MEMREGS32;
    volatile uint16_t* MEMREGS16;
};


#endif //H__PLAT_WIZ__H
