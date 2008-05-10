#include "platform.h"


GW_Platform_RGB GW_Platform_RGB_create(int r, int g, int b)
{
    GW_PLATFORM_RGB(ret, r, g, b);
    return ret;
}
