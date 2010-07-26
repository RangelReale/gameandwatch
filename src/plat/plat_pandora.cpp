#include "gwdefs.h"
#include "plat/plat_pandora.h"

bool GW_PlatformPandora::process_event(GW_Platform_GameType gametype,
    SDL_Event *sdlevent, GW_Platform_Event *event)
{
    bool proc=false;
    switch (sdlevent->type)
    {
    // Keypress
    case SDL_KEYDOWN:
        {
            proc=true;
            event->id=GPE_KEYDOWN;
            switch (sdlevent->key.keysym.sym)
            {
            case SDLK_RSHIFT: // L
                event->data=GPK_LEFT;
                break;
            case SDLK_RCTRL: // R
            case SDLK_END: // B
                event->data=GPK_RIGHT;
                break;
            case SDLK_LALT: // START
                event->data=GPK_TURNONTOGGLE;
		break;
            case SDLK_LCTRL: // SELECT
                event->data=GPK_QUIT;
		break;
            default:
                proc=false;
                break;
            }
	}
    }

    if (!proc)
        return GW_PlatformSDL::process_event(gametype, sdlevent, event);
    return true;
}
