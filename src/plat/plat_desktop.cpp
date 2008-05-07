#include <ctime>
#include "plat/plat_desktop.h"

GW_Platform_Desktop::GW_Platform_Desktop(int width, int height) :
    GW_Platform(), width_(width), height_(height)
{

}

void GW_Platform_Desktop::_process_event(SDL_Event *event)
{
    switch (event->type)
    {
    // QUIT
    case SDL_QUIT:
        device_get()->Quit();
        break;
    // Keypress
    case SDL_KEYDOWN:
        {
            switch (event->key.keysym.sym)
            {
            case SDLK_LEFT:
                if ((event->key.keysym.mod&KMOD_LCTRL)==KMOD_LCTRL)
                    device_get()->MoveBGOffset(-5, 0);
                else
                    device_get()->DefaultKey(GW_Game::DK_LEFT);
                break;
            case SDLK_RIGHT:
                if ((event->key.keysym.mod&KMOD_LCTRL)==KMOD_LCTRL)
                    device_get()->MoveBGOffset(5, 0);
                else
                    device_get()->DefaultKey(GW_Game::DK_RIGHT);
                break;
            case SDLK_UP:
                if ((event->key.keysym.mod&KMOD_LCTRL)==KMOD_LCTRL)
                    device_get()->MoveBGOffset(0, -5);
                else
                    device_get()->DefaultKey(GW_Game::DK_UP);
                break;
            case SDLK_DOWN:
                if ((event->key.keysym.mod&KMOD_LCTRL)==KMOD_LCTRL)
                    device_get()->MoveBGOffset(0, 5);
                else
                    device_get()->DefaultKey(GW_Game::DK_DOWN);
                break;
            case SDLK_RETURN:
                device_get()->TurnOn();
                break;
            case SDLK_BACKSPACE:
                device_get()->TurnOff();
                break;
            case SDLK_SPACE:
                device_get()->MoveBGCenter();
                break;
            case SDLK_ESCAPE:
                device_get()->Quit();
                break;
            case SDLK_F1:
                device_get()->SetMode(0);
                break;
            case SDLK_F2:
                device_get()->SetMode(1);
                break;
            case SDLK_F3:
                device_get()->SetMode(2);
                break;
            case SDLK_F4:
                device_get()->SetMode(3);
                break;
            case SDLK_F5:
                device_get()->SetMode(4);
                break;
            case SDLK_F6:
                device_get()->SetMode(5);
                break;
            case SDLK_F7:
                device_get()->SetMode(6);
                break;
            case SDLK_F8:
                device_get()->SetMode(7);
                break;
            case SDLK_F9:
                device_get()->SetMode(8);
                break;
            case SDLK_F10:
                device_get()->SetMode(9);
                break;
            case SDLK_1:
                device_get()->DefaultKey(GW_Game::DK_GAMEA);
                break;
            case SDLK_2:
                device_get()->DefaultKey(GW_Game::DK_GAMEB);
                break;
            case SDLK_3:
                device_get()->DefaultKey(GW_Game::DK_TIME);
                break;
            case SDLK_PLUS:
                device_get()->DefaultKey(GW_Game::DK_VOLUP);
                break;
            case SDLK_MINUS:
                device_get()->DefaultKey(GW_Game::DK_VOLDOWN);
                break;
            default:
                break;
            }
        }
        break;
    default:
        break;
    }
}

unsigned int GW_Platform_Desktop::timems_get()
{
    time_t date;
    struct tm  *ts;
    time(&date);
    ts=localtime(&date);

    return (ts->tm_sec + (ts->tm_min * 60) + (ts->tm_hour * 60 * 60)) * 1000;
    //return SDL_GetTicks();
}
