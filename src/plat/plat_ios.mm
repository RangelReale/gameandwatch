#ifdef __cplusplus
#include "gwdefs.h"
#include "plat/plat_ios.h"
#include "gwdbg.h"
#endif

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#endif

bool GW_PlatformIOS::process_event(GW_Platform_GameType gametype,
                                       SDL_Event *sdlevent, GW_Platform_Event *event)
{
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) 
    {
        // Do iPad only stuff here
    }

    
    bool proc=false;
    switch (sdlevent->type)
    {
        case SDL_FINGERDOWN:
    	{
    	    SDL_Touch* inTouch = SDL_GetTouch(sdlevent->tfinger.touchId);
    	    if(inTouch != NULL)
    	    {
    	    	proc = true;
                event->id=GPE_KEYDOWN;
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
				else if (sdlevent->tfinger.x < ceil(((float)inTouch->xres) * 0.5f))
	                event->data=GPK_TURNON;
				else if (sdlevent->tfinger.x > ceil(((float)inTouch->xres) * 0.5f))
	                event->data=GPK_GAMEA;
				else
					proc = false;
                
    	    }
    	}
    }
    
    if (!proc)
        return GW_PlatformSDL::process_event(gametype, sdlevent, event);
    return true;
}
