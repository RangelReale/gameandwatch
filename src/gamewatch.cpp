#include <SDL.h>

#include "gwdefs.h"
#include "device.h"
#include "devices/dev_monkey.h"
#include "plat/plat_sdl.h"
#ifdef GP2X
#include "plat/plat_gp2x.h"
#endif
#ifdef GW_PLAT_S60
#include "plat/plat_s60.h"
#endif
/*
#ifdef _WIN32
#include <windows.h>
#endif
*/
#include "gamelist.h"
#include "menu.h"
/*
#include <sdlmain.h>
#include <sdlepocapi.h>
*/

//#ifndef _WIN32
//int main(int argc, char** argv)
int main(int, char**)
/*
#else
int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
#endif
*/
{
    try
    {
#ifdef GP2X
        GW_PlatformGP2X platform;
#elif defined(GW_PLAT_S60)
        GW_PlatformS60 platform;
#else
        GW_PlatformSDL platform(640, 480);
#endif
        platform.initialize();

        GW_GameList gamelist;

        GW_Menu menu(&platform, &gamelist);
        menu.Run();

        platform.finalize();
    } catch (GW_Exception &e) {
        fprintf(stderr, "%s\n", e.what().c_str());
        return 1;
    }

    return 0;
}
