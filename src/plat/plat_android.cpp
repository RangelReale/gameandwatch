#include "gwdefs.h"
#include "plat/plat_android.h"

bool GW_PlatformAndroid::process_event(GW_Platform_GameType gametype,
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
            case SDLK_q:
                event->data=GPK_GAMEA;
                break;
            case SDLK_w:
                event->data=GPK_GAMEB;
                break;
			case SDLK_u:
				event->data=GPK_ZOOM_NORMAL;
				break;
			case SDLK_i:
				event->data=GPK_ZOOM_DEVICE;
				break;
			case SDLK_o:
				event->data=GPK_ZOOM_GAME;
				break;
            case SDLK_x:
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
