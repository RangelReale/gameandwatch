#ifndef H__DEVENG_VTECH_BANANA__H
#define H__DEVENG_VTECH_BANANA__H

#include "device.h"
#include "deveng_vtech.h"

using namespace std;

class GW_GameEngine_VTech_Banana : public GW_GameEngine_VTech
{
public:
    enum options_t
    {
        GO_NONE,
    };

    GW_GameEngine_VTech_Banana(int engineoptions, int options);
private:
    int options_;
};


#endif //H__DEVENG_VTECH_BANANA__H

