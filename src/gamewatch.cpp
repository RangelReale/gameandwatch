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

#include "util/anyoption.h"

//#ifndef _WIN32
//int main(int argc, char** argv)
int main(int argc, char** argv)
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
	string datapath;

	AnyOption *opt = new AnyOption();
	
    opt->addUsage( "" );
    opt->addUsage( "Usage: " );
    opt->addUsage( "" );
    opt->addUsage( " -h  --help  				Prints this help " );
    opt->addUsage( " -d  --data-path /dir		Data files path " );
    opt->addUsage( "" );

	opt->setFlag(  "help", 'h' );
	opt->setOption(  "data-path", 'd' );

	opt->processCommandArgs( argc, argv );

    if( opt->getFlag( "help" ) || opt->getFlag( 'h' ) ) 
	{
        opt->printUsage();
		delete opt;
		return 0;
	}
	if( opt->getValue( 'd' ) != NULL  || opt->getValue( "data-size" ) != NULL  )
		datapath = opt->getValue('d');

	delete opt;

    try
    {
#ifdef GP2X
        GW_PlatformGP2X platform;
#elif defined(GW_PLAT_S60)
        GW_PlatformS60 platform;
#else
        GW_PlatformSDL platform(640, 400);
#endif
		if (!datapath.empty())
			platform.datapath_set(datapath);

        platform.initialize();

        GW_GameList gamelist(&platform);

        GW_Menu menu(&platform, &gamelist);
        menu.Run();

        platform.finalize();
    } catch (GW_Exception &e) {
        fprintf(stderr, "%s\n", e.what().c_str());
        return 1;
    }

    return 0;
}
