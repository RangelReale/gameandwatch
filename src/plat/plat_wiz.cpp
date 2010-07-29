#include "gwdefs.h"
#include "plat/plat_wiz.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

/* -------- */

#define MEM_SIZE 0x20000
#define MEM_BASE 0xC0000000

#define TIMER_BASE3 0x1980
#define TIMER_REG(x) (MEMREGS32[(TIMER_BASE3 + x) >> 2])

/* -------- */

enum
{
	WIZ_VK_UP			= 0,
	WIZ_VK_UPLEFT		= 1,
	WIZ_VK_LEFT		    = 2,
	WIZ_VK_DOWNLEFT	    = 3,
	WIZ_VK_DOWN		    = 4,
	WIZ_VK_DOWNRIGHT	= 5,
	WIZ_VK_RIGHT		= 6,
	WIZ_VK_UPRIGHT		= 7,
	WIZ_VK_MENU		    = 8,
	WIZ_VK_SELECT		= 9,
	WIZ_VK_L			= 10,
	WIZ_VK_R			= 11,
	WIZ_VK_A			= 12,
	WIZ_VK_B			= 13,
	WIZ_VK_X			= 14,
	WIZ_VK_Y			= 15,
	WIZ_VK_VOLUP		= 16,
	WIZ_VK_VOLDOWN		= 17,
};

/* -------- */

GW_PlatformWIZ::GW_PlatformWIZ() :
    GW_PlatformSDL(320, 240),
    m_MEM(-1),
    MEMREGS16((uint16_t*)MAP_FAILED),
    MEMREGS32((uint32_t*)MAP_FAILED)
{}

GW_PlatformWIZ::~GW_PlatformWIZ()
{

}
void GW_PlatformWIZ::custom_initialize()
{
    SDL_Joystick *joystick = SDL_JoystickOpen(0); // initialize the joystick and buttons.  Number '0' is the only one.
	if (!joystick) // should not happen
        throw GW_Exception(string("Unable to open joystick: "+string(SDL_GetError())));


    m_MEM = open("/dev/mem", O_RDWR );
    if (m_MEM<0)
        throw GW_Exception(string("/dev/mem open failed."));

    MEMREGS32 = (volatile uint32_t*)mmap(0,MEM_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, m_MEM, MEM_BASE);
    if (MEMREGS32==MAP_FAILED)
        throw GW_Exception(string("mmap failed."));

    MEMREGS16 = (volatile uint16_t*)MEMREGS32;

    /* start timer */
    TIMER_REG(0x44) = 0x922;
    TIMER_REG(0x40) = 0x0c;
    TIMER_REG(0x08) = 0x6b;
}

void GW_PlatformWIZ::custom_finalize()
{
    if(m_MEM>=0)
    {
        if (MEMREGS32!=MAP_FAILED)
        {
            /* stop timer */
            TIMER_REG(0x40) = 0x0c;
            TIMER_REG(0x08) = 0x23;
            TIMER_REG(0x00) = 0;
            TIMER_REG(0x40) = 0;
            TIMER_REG(0x44) = 0;
        }

        close(m_MEM);
        m_MEM = -1;
        MEMREGS16 = (uint16_t*)MAP_FAILED;
        MEMREGS32 = (uint32_t*)MAP_FAILED;
    }
}

unsigned int GW_PlatformWIZ::time_ms_get()
{
    TIMER_REG(0x08) = 0x4b;  /* run timer, latch value */
    return TIMER_REG(0) / 1000; //timer is us
}

bool GW_PlatformWIZ::process_event(GW_Platform_GameType gametype,
    SDL_Event *sdlevent, GW_Platform_Event *event)
{
    bool proc=false;
    switch (sdlevent->type)
    {
    // Joystick
    case SDL_JOYBUTTONDOWN:
        {
            proc=true;
            event->id=GPE_KEYDOWN;
            switch(sdlevent->jbutton.button)
            {
            case WIZ_VK_SELECT:
                event->data=GPK_TURNONTOGGLE;
                break;
            case WIZ_VK_LEFT:
                if (gametype!=GPG_4DIAG)
                    event->data=GPK_LEFT;
                break;
            case WIZ_VK_RIGHT:
                if (gametype!=GPG_4DIAG)
                    event->data=GPK_RIGHT;
                break;
            case WIZ_VK_UP:
                if (gametype!=GPG_4DIAG)
                    event->data=GPK_UP;
                else
                    event->data=GPK_UPLEFT;
                break;
            case WIZ_VK_DOWN:
                if (gametype!=GPG_4DIAG)
                    event->data=GPK_DOWN;
                else
                    event->data=GPK_DOWNLEFT;
                break;
            case WIZ_VK_MENU:
                event->data=GPK_QUIT;
                break;
            case WIZ_VK_L:
                event->data=GPK_GAMEA;
                break;
            case WIZ_VK_R:
                event->data=GPK_GAMEB;
                break;
            case WIZ_VK_VOLUP:
                event->data=GPK_VOLUP;
                break;
            case WIZ_VK_VOLDOWN:
                event->data=GPK_VOLDOWN;
                break;
            case WIZ_VK_A:
                event->data=GPK_TIME;
                break;
            case WIZ_VK_B:
                if (gametype==GPG_LEFTRIGHT)
                    event->data=GPK_RIGHT;
                else
                    proc=false;
                break;
            case WIZ_VK_X:
                if (gametype==GPG_4DIAG)
                    event->data=GPK_DOWNRIGHT;
                else
                    proc=false;
                break;
            case WIZ_VK_Y:
                if (gametype==GPG_4DIAG)
                    event->data=GPK_UPRIGHT;
                else
                    proc=false;
                break;
            default:
                proc=false;
                break;
            }
        }
        break;
    }

    if (!proc)
        return GW_PlatformSDL::process_event(gametype, sdlevent, event);
    return true;
}
