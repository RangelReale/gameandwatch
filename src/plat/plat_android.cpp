#include "gwdefs.h"
#include "plat/plat_android.h"

bool GW_PlatformAndroid::process_event(GW_Platform_GameType gametype,
    SDL_Event *sdlevent, GW_Platform_Event *event)
{
    return GW_PlatformSDL::process_event(gametype, sdlevent, event);
}
