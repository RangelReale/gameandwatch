#include <SDL.h>

#include "gwdefs.h"
#include "device.h"
#include "devices/dev_monkey.h"
#include "plat/plat_sdl.h"
#ifdef GP2X
#include "plat/plat_gp2x.h"
#endif
#ifdef WIN32
#include <windows.h>
#endif
#include "gamelist.h"
#include "menu.h"

#ifndef WIN32
int main(int argc, char** argv)
#else
int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
#endif
{
    try
    {
#ifdef GP2X
        GW_PlatformGP2X platform;
#else
        GW_PlatformSDL platform(320, 240);
#endif
        platform.initialize();


        GW_GameList gamelist;

        GW_Menu menu(&platform, &gamelist);
        menu.Run();

/*
        GW_Game *game=gamelist.get(0)->create();
        GW_Device device(&platform);
        device.Run(game);
        delete game;
*/

        platform.finalize();
    } catch (GW_Exception &e) {
        fprintf(stderr, "%s\n", e.what().c_str());
        return 1;
    }

    return 0;
}
