#ifndef H__PLAT_GP2X__H
#define H__PLAT_GP2X__H

#include "plat/plat_desktop.h"

class GW_Platform_GP2X : public GW_Platform_Desktop
{
public:
    GW_Platform_GP2X() : GW_Platform_Desktop(320, 240) {}
    virtual ~GW_Platform_GP2X();

    virtual int sdlinit(int flags) { return flags|SDL_INIT_JOYSTICK; }

    virtual void initialize();
    virtual void finalize();
    virtual unsigned int timems_get() { return SDL_GetTicks(); }
    virtual int audiobufsize_get() { return 128; }
protected:
    virtual void _process_event(SDL_Event *event);
};


#endif //H__PLAT_GP2X__H
