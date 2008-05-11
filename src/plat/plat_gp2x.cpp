#include "gwdefs.h"
#include "plat/plat_gp2x.h"
#include "SDL_gp2x.h"

GW_PlatformGP2X::~GW_PlatformGP2X()
{

}
void GW_PlatformGP2X::custom_initialize()
{
    SDL_Joystick *joystick = SDL_JoystickOpen(0); // initialize the joystick and buttons.  Number '0' is the only one.
	if (!joystick) // should not happen
        throw GW_Exception(string("Unable to open joystick: "+string(SDL_GetError())));
}

void GW_PlatformGP2X::custom_finalize()
{

}

bool GW_PlatformGP2X::process_event(GW_Platform_GameType gametype,
    SDL_Event *sdlevent, GW_Platform_Event *event)
{
    bool proc=false;
    switch (sdlevent->type)
    {
    // Joystick
    case SDL_JOYBUTTONDOWN:
        {
            proc=true;
            event->id=GPE_KEYDOWN;
            switch(sdlevent->jbutton.button)
            {
            case GP2X_VK_START:
                event->data=GPK_QUIT;
                break;
            case GP2X_VK_LEFT:
                event->data=GPK_LEFT;
                break;
            case GP2X_VK_RIGHT:
                event->data=GPK_RIGHT;
                break;
            case GP2X_VK_UP:
                event->data=GPK_UP;
                break;
            case GP2X_VK_DOWN:
                event->data=GPK_DOWN;
                break;
            case GP2X_VK_SELECT:
                event->data=GPK_TURNONTOGGLE;
                break;
            case GP2X_VK_FL:
                event->data=GPK_GAMEA;
                break;
            case GP2X_VK_FR:
                event->data=GPK_GAMEB;
                break;
            case GP2X_VK_VOL_UP:
                event->data=GPK_VOLUP;
                break;
            case GP2X_VK_VOL_DOWN:
                event->data=GPK_VOLDOWN;
                break;
            case GP2X_VK_FA:
                event->data=GPK_TIME;
                break;
            case GP2X_VK_FB:
                if (gametype==GPG_LEFTRIGHT)
                    event->data=GPK_RIGHT;
                else
                    proc=false;
                break;
            default:
                proc=false;
                break;
            }
        }
        break;
    }

    if (!proc)
        return GW_PlatformSDL::process_event(gametype, sdlevent, event);
    return true;
}
