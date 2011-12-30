#include "gwdefs.h"
#include "plat/plat_android.h"
#include "gwdbg.h"

#define GWSDLK_MENU  1073741942
#define GWSDLK_BACK  1073742094
#define GWSDLK_SEARCH  1073742092

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
            case GWSDLK_BACK:
                event->data=GPK_GAMEA;
                break;
            case SDLK_w:
            case GWSDLK_SEARCH:
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
            case GWSDLK_MENU:
                event->data=GPK_TURNON;
                break;
            default:
                proc=false;
                break;
            }
        }
    case SDL_FINGERDOWN:
    	{
    	    SDL_Touch* inTouch = SDL_GetTouch(sdlevent->tfinger.touchId);
    	    if(inTouch != NULL)
    	    {
    	    	proc = true;
    	    	GWDBG_FVOUTPUT("FINGER DOWN: x=%d - y=%d - xmax=%d - ymax=%d", sdlevent->tfinger.x, sdlevent->tfinger.y, inTouch->xres, inTouch->yres)
    	    	//GWDBG_FVOUTPUT("FINGER POS: %f", ceil(((float)inTouch->xres) * 0.2f))

				if (sdlevent->tfinger.x < ceil(((float)inTouch->xres) * 0.3f))
	                event->data=GPK_LEFT;
				else if (sdlevent->tfinger.x > ceil(((float)inTouch->xres) * 0.7f))
	                event->data=GPK_RIGHT;
				else if (sdlevent->tfinger.y < ceil(((float)inTouch->yres) * 0.3f))
	                event->data=GPK_UP;
				else if (sdlevent->tfinger.y > ceil(((float)inTouch->yres) * 0.7f))
	                event->data=GPK_DOWN;
				else
					proc = false;

    	    }
    	}
    }

    if (!proc)
        return GW_PlatformSDL::process_event(gametype, sdlevent, event);
    return true;
}
