#include "gwdefs.h"
#include "plat/plat_gp2x.h"
#include "SDL_gp2x.h"

GW_Platform_GP2X::~GW_Platform_GP2X()
{

}
void GW_Platform_GP2X::initialize()
{
    SDL_Joystick *joystick = SDL_JoystickOpen(0); // initialize the joystick and buttons.  Number '0' is the only one.
	if (!joystick) // should not happen
        throw GW_Exception(string("Unable to open joystick: "+string(SDL_GetError())));

    SDL_ShowCursor(SDL_DISABLE);
}

void GW_Platform_GP2X::finalize()
{

}


void GW_Platform_GP2X::_process_event(SDL_Event *event)
{
    switch (event->type)
    {
    // Joystick
    case SDL_JOYBUTTONDOWN:
        {
            switch(event->jbutton.button)
            {
            case GP2X_VK_START:
                device_get()->Quit();
                break;
            case GP2X_VK_LEFT:
                //device_get()->MoveBGOffset(-5, 0);
                device_get()->DefaultKey(GW_Game::DK_LEFT);
                break;
            case GP2X_VK_RIGHT:
                //device_get()->MoveBGOffset(5, 0);
                device_get()->DefaultKey(GW_Game::DK_RIGHT);
                break;
            case GP2X_VK_UP:
                //device_get()->MoveBGOffset(0, -5);
                device_get()->DefaultKey(GW_Game::DK_UP);
                break;
            case GP2X_VK_DOWN:
                //device_get()->MoveBGOffset(0, 5);
                device_get()->DefaultKey(GW_Game::DK_DOWN);
                break;
            case GP2X_VK_SELECT:
                //device_get()->MoveBGCenter();
                device_get()->TurnOn();
                break;
            case GP2X_VK_FL:
                //device_get()->MoveBGOffset(0, 5);
                device_get()->DefaultKey(GW_Game::DK_GAMEA);
                break;
            case GP2X_VK_FR:
                //device_get()->MoveBGOffset(0, 5);
                device_get()->DefaultKey(GW_Game::DK_GAMEB);
                break;
            case GP2X_VK_VOL_UP:
                device_get()->DefaultKey(GW_Game::DK_VOLUP);
                break;
            case GP2X_VK_VOL_DOWN:
                device_get()->DefaultKey(GW_Game::DK_VOLDOWN);
                break;
            case GP2X_VK_FY:
                device_get()->DefaultKey(GW_Game::DK_TIME);
                break;
            }
        }
        break;
    }

    GW_Platform_Desktop::_process_event(event);
}
