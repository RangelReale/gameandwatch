#include "platform.h"


const char* GW_Platform_DataPath =
#ifdef HAVE_CONFIG_H
"/usr/share/gameandwatch/data";
#else
"data";
#endif


GW_Platform_RGB GW_Platform_RGB_create(int r, int g, int b)
{
    GW_PLATFORM_RGB(ret, r, g, b);
    return ret;
}
