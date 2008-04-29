#ifndef H__PLAT_DESKTOP__H
#define H__PLAT_DESKTOP__H

#include "device.h"

class GW_Platform_Desktop : public GW_Platform
{
public:
    GW_Platform_Desktop(int width, int height);

    virtual int width_get() { return width_; }
    virtual int height_get() { return height_; }
    virtual unsigned int timems_get();
protected:
    virtual void _process_event(SDL_Event *event);
private:
    int width_, height_;
};

#endif //H__PLAT_DESKTOP__H
