#include "gwdefs.h"
#include "plat/plat_s60.h"

GW_PlatformS60::~GW_PlatformS60()
{

}
void GW_PlatformS60::custom_initialize()
{

}

void GW_PlatformS60::custom_finalize()
{

}

bool GW_PlatformS60::process_event(GW_Platform_GameType gametype,
    SDL_Event *sdlevent, GW_Platform_Event *event)
{
    return GW_PlatformSDL::process_event(gametype, sdlevent, event);
}
