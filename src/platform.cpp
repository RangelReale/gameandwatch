#include "platform.h"


const char* GW_Platform_DataPath =
#define QMAKESTR(x) #x
#define MAKESTR(x) QMAKESTR(x)
#ifdef DATADIR
MAKESTR(DATADIR) "/gameandwatch/data";
#elif defined(GW_DATADIR_FULL)
MAKESTR(GW_DATADIR_FULL);
#else
"data";
#endif


GW_Platform_RGB GW_Platform_RGB_create(int r, int g, int b)
{
    GW_PLATFORM_RGB(ret, r, g, b);
    return ret;
}
