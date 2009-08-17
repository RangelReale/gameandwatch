#include <ctime>
#include "plat/plat_sdl.h"
#include "gwdefs.h"
#include "gwdbg.h"
#ifdef GW_USE_ZDATA
#include <plat/SDL_rwops_zzip.h>
#endif

//////////////////////////////////////////
////
//// GW_PlatformSDL_Image
////
//////////////////////////////////////////
GW_PlatformSDL_Image::GW_PlatformSDL_Image(const string &filename, GW_Platform_RGB *tcolor)
{
#ifndef GW_USE_ZDATA
    surface_ = SDL_LoadBMP( filename.c_str() );
#else
    SDL_RWops *l = SDL_RWFromZZIP( filename.c_str(), "rb" );
    if (l)
        surface_ = SDL_LoadBMP_RW( l, 1 );
    else
        surface_=NULL;
    //SDL_FreeRW(l);
#endif

    if (!surface_)
        throw GW_Exception(string("Unable to load image "+filename+": "+string(SDL_GetError())));
    if (tcolor)
        SDL_SetColorKey(surface_, SDL_SRCCOLORKEY, SDL_MapRGB(surface_->format, tcolor->r, tcolor->g, tcolor->b));
    SDL_DisplayFormat(surface_);
}

GW_PlatformSDL_Image::~GW_PlatformSDL_Image()
{
    SDL_FreeSurface(surface_);
}

bool GW_PlatformSDL_Image::resize_fit(int w, int h)
{
#ifndef GW_NO_SDL_GFX
	float rw=(float)w/surface_->w, rh=(float)h/surface_->h, r;

    if (rw < rh) r=rw; else r=rh;

    SDL_Surface *news=zoomSurface(surface_, r, r, 0);
    if (news)
    {
        SDL_FreeSurface(surface_);
        surface_=news;
        SDL_DisplayFormat(surface_);
    }
    return news!=NULL;
#else
	return false;
#endif
}

//////////////////////////////////////////
////
//// GW_PlatformSDL_Sound
////
//////////////////////////////////////////
GW_PlatformSDL_Sound::GW_PlatformSDL_Sound(const string &filename)
{
#ifndef GW_NO_SDL_MIXER

#ifndef GW_USE_ZDATA
    sample_ = Mix_LoadWAV( filename.c_str() );
#else
    SDL_RWops *l = SDL_RWFromZZIP( filename.c_str(), "rb" );
    if (l)
        sample_ = Mix_LoadWAV_RW( l, 1 );
    else
        sample_=NULL;
    //SDL_FreeRW(l);
#endif

    if (!sample_)
        throw GW_Exception(string("Unable to load sound sample "+filename+": "+string(Mix_GetError())));
#endif
}

GW_PlatformSDL_Sound::~GW_PlatformSDL_Sound()
{
#ifndef GW_NO_SDL_MIXER
	Mix_FreeChunk(sample_);
#endif
}

//////////////////////////////////////////
////
//// GW_PlatformSDL
////
//////////////////////////////////////////
GW_PlatformSDL::GW_PlatformSDL(int width, int height) :
    GW_Platform(), width_(width), height_(height),
    initialized_(false), screen_(NULL)
{

}

GW_PlatformSDL::~GW_PlatformSDL()
{
    if (initialized_)
        finalize();
}

void GW_PlatformSDL::initialize()
{
    if (!initialized_)
    {
		GWDBG_OUTPUT("SDL: Initialize")

		// initialize SDL video
        if ( SDL_Init( sdlinit(SDL_INIT_VIDEO|SDL_INIT_AUDIO) ) < 0 )
            throw GW_Exception(string("Unable to init SDL: "+string(SDL_GetError())));

#ifndef GW_NO_SDL_MIXER
        if ( Mix_OpenAudio(22050, AUDIO_S16SYS, 1, audiobufsize_get()) < 0)
            throw GW_Exception(string("Unable to init SDL_mixer: "+string(Mix_GetError())));
#endif

#ifndef GW_NO_SDL_TTF
        if ( TTF_Init() < 0 )
            throw GW_Exception(string("Unable to init SDL_ttf: "+string(TTF_GetError())));
#endif

#ifndef GW_NO_SDL_MIXER
		Mix_AllocateChannels(6);
        sound_volume(75);
#endif

        custom_initialize();

        // make sure SDL cleans up before exit
        atexit(SDL_Quit);

        // set application icon
        plat_init();

        // create a new window
        screen_ = SDL_SetVideoMode(width_get(), height_get(), 16,
                                               SDL_HWSURFACE|SDL_DOUBLEBUF);
        if ( !screen_ )
            throw GW_Exception(string("Unable to set resolution: "+string(SDL_GetError())));

        SDL_ShowCursor(SDL_DISABLE);

        SDL_WM_SetCaption("Game & Watch simulator - by Hitnrun & Madrigal", NULL);

#ifndef GW_NO_SDL_TTF
        // load font
        //font_=TTF_OpenFont( bf::path( bf::path(platformdata_get() ) / "andalemo.ttf" ).string().c_str(), fontsize_get() );
		string pfont(platformdata_get() + "/" + "andalemo.ttf" );
		font_=TTF_OpenFont( pfont.c_str(), fontsize_get() );
        if (!font_)
            throw GW_Exception(string("Unable to load font: "+string(TTF_GetError())));
#endif

        initialized_=true;
    }
}

void GW_PlatformSDL::finalize()
{
    if (initialized_)
    {
        custom_finalize();

        // set application icon
        plat_finish();

#ifndef GW_NO_SDL_TTF
        TTF_CloseFont(font_);
        TTF_Quit();
#endif

#ifndef GW_NO_SDL_MIXER
        Mix_CloseAudio();
#endif

        SDL_Quit();

		GWDBG_OUTPUT("SDL: Finalize")

		initialized_=false;
    }
}

unsigned int GW_PlatformSDL::ticks_get()
{
    return SDL_GetTicks();
}

unsigned int GW_PlatformSDL::time_ms_get()
{
    time_t date;
    struct tm  *ts;
    time(&date);
    ts=localtime(&date);

    return (ts->tm_sec + (ts->tm_min * 60) + (ts->tm_hour * 60 * 60)) * 1000;
    //return SDL_GetTicks();
}

GW_Platform_Time GW_PlatformSDL::time_get()
{
    time_t date;
    struct tm  *ts;
    time(&date);
    ts=localtime(&date);

    GW_Platform_Time ret;
    ret.d=ts->tm_mday;
    ret.m=ts->tm_mon+1;
    ret.y=ts->tm_year;
    ret.h=ts->tm_hour;
    ret.n=ts->tm_min;
    ret.s=ts->tm_sec;
    return ret;
}

bool GW_PlatformSDL::event(GW_Platform_GameType gametype,
    GW_Platform_Event *event)
{
    SDL_Event sdlevent;
    while (true)
    {
        if (SDL_PollEvent(&sdlevent))
        {
            if (process_event(gametype, &sdlevent, event))
                return true;
        }
        else
            return false;
    }
    return false;
}

void GW_PlatformSDL::draw_clear()
{
    SDL_FillRect(screen_, 0, SDL_MapRGB(screen_->format, 0, 0, 0));
}

void GW_PlatformSDL::draw_image(GW_Platform_Image *image, int x, int y)
{
    SDL_Rect spos, srcpos;
    spos.x=x; spos.y=y;
    srcpos.w=dynamic_cast<GW_PlatformSDL_Image*>(image)->surface_get()->w;
    srcpos.h=dynamic_cast<GW_PlatformSDL_Image*>(image)->surface_get()->h;

    // clip
    if (spos.x<0)
    {
        srcpos.x=abs(spos.x);
        spos.x=0;
    }
    else
    {
        srcpos.x=0;
        //bgdst_.x=offsetx_;
    }
    if (spos.x<0)
    {
        srcpos.y=abs(spos.y);
        spos.y=0;
    }
    else
    {
        srcpos.y=0;
    }

    SDL_BlitSurface(dynamic_cast<GW_PlatformSDL_Image*>(image)->surface_get(),
        &srcpos, screen_, &spos);
}

void GW_PlatformSDL::draw_line(int x1, int y1, int x2, int y2,
    GW_Platform_RGB *color)
{
#ifndef GW_NO_SDL_GFX
	GW_PLATFORM_RGB(lcolor,255,255,255);
    if (color) lcolor=*color;
    lineRGBA(screen_, x1, y1, x2, y2, lcolor.r, lcolor.g, lcolor.b, 255);
#endif
}

void GW_PlatformSDL::draw_rectangle(int x1, int y1, int x2, int y2,
    GW_Platform_RGB *forecolor, GW_Platform_RGB *backcolor, int alpha)
{
#ifndef GW_NO_SDL_GFX
	if (forecolor || (!forecolor && !backcolor))
    {
        GW_PLATFORM_RGB(lcolor,255,255,255);
        if (forecolor) lcolor=*forecolor;
        rectangleRGBA(screen_, x1, y1, x2, y2, lcolor.r, lcolor.g, lcolor.b, (alpha>-1?alpha:255));
    }
    if (backcolor)
    {
        boxRGBA(screen_, x1, y1, x2, y2, backcolor->r, backcolor->g, backcolor->b, (alpha>-1?alpha:255));
    }
#endif
}


void GW_PlatformSDL::draw_flip()
{
    SDL_Flip(screen_);
}

void GW_PlatformSDL::text_draw(int x, int y, const string &text,
    GW_Platform_RGB *color)
{
#ifndef GW_NO_SDL_TTF
    SDL_Surface *tsurf;
    SDL_Color tcolor={255,255,255};
    if (color)
    {
        tcolor.r=color->r; tcolor.g=color->g; tcolor.b=color->b;
    }

    SDL_Rect tpos;
    tpos.x=x; tpos.y=y;
    tsurf=TTF_RenderText_Solid(font_, text.c_str(), tcolor);
    if (tsurf)
        SDL_BlitSurface(tsurf, NULL, screen_, &tpos);
#endif
}

int GW_PlatformSDL::text_fontheight()
{
#ifndef GW_NO_SDL_TTF
    return TTF_FontLineSkip(font_);
#else
	return 1;
#endif
}

int GW_PlatformSDL::text_width(const string &text)
{
#ifndef GW_NO_SDL_TTF
    int s;
    if (TTF_SizeText(font_, text.c_str(), &s, NULL) == 0)
        return s;
    return -1;
#else
	return 1;
#endif
}

int GW_PlatformSDL::text_height(const string &text)
{
#ifndef GW_NO_SDL_TTF
    int s;
    if (TTF_SizeText(font_, text.c_str(), NULL, &s) == 0)
        return s;
#endif
	return -1;
}

void GW_PlatformSDL::sound_play(GW_Platform_Sound *sound)
{
#ifndef GW_NO_SDL_MIXER
	Mix_PlayChannel(-1, dynamic_cast<GW_PlatformSDL_Sound*>(sound)->sample_get(), 0);
#endif
}

void GW_PlatformSDL::sound_stop_all()
{
#ifndef GW_NO_SDL_MIXER
	Mix_HaltChannel(-1);
#endif
}

unsigned short GW_PlatformSDL::sound_volume(unsigned short volume)
{
#ifndef GW_NO_SDL_MIXER
	//if (volume<0) volume=0;
    if (volume>100) volume=100;

    Mix_Volume(-1, (MIX_MAX_VOLUME/100)*volume);
    return volume;
#else
	return 0;
#endif
}

GW_Platform_Image *GW_PlatformSDL::image_load(const string &filename, GW_Platform_RGB *tcolor)
{
    return new GW_PlatformSDL_Image(filename, tcolor);
}

GW_Platform_Sound *GW_PlatformSDL::sound_load(const string &filename)
{
	return new GW_PlatformSDL_Sound(filename);
}

bool GW_PlatformSDL::process_event(GW_Platform_GameType gametype,
    SDL_Event *sdlevent, GW_Platform_Event *event)
{
    switch (sdlevent->type)
    {
    // QUIT
    case SDL_QUIT:
        event->id=GPE_QUIT;
        break;
    // Keypress
    case SDL_KEYDOWN:
        {
            event->id=GPE_KEYDOWN;
            switch (sdlevent->key.keysym.sym)
            {
            case SDLK_LEFT:
                event->data=GPK_LEFT;
                break;
            case SDLK_RIGHT:
                event->data=GPK_RIGHT;
                break;
            case SDLK_UP:
                event->data=GPK_UP;
                break;
            case SDLK_DOWN:
                event->data=GPK_DOWN;
                break;
            case SDLK_q:
                event->data=GPK_UPLEFT;
                break;
            case SDLK_a:
                event->data=GPK_DOWNLEFT;
                break;
            case SDLK_p:
                event->data=GPK_UPRIGHT;
                break;
            case SDLK_l:
                event->data=GPK_DOWNRIGHT;
                break;
            case SDLK_RETURN:
                event->data=GPK_TURNON;
                break;
            case SDLK_BACKSPACE:
                event->data=GPK_TURNOFF;
                break;
/*
            case SDLK_SPACE:
                device_get()->MoveBGCenter();
                break;
*/
            case SDLK_ESCAPE:
                event->data=GPK_QUIT;
                break;
            case SDLK_1:
                event->data=GPK_GAMEA;
                break;
            case SDLK_2:
                event->data=GPK_GAMEB;
                break;
            case SDLK_3:
                event->data=GPK_TIME;
                break;
            case SDLK_PLUS:
                event->data=GPK_VOLUP;
                break;
            case SDLK_MINUS:
                event->data=GPK_VOLDOWN;
                break;
            default:
                return false;
            }
        }
        break;
    default:
        return false;
    }
    return true;
}

void GW_PlatformSDL::plat_init()
{
#ifdef _WIN32
    HWND hwnd;

    HINSTANCE handle = ::GetModuleHandle(NULL);
    icon_ = ::LoadIcon(handle, "GWICON");

    SDL_SysWMinfo wminfo;
    SDL_VERSION(&wminfo.version)
    if (SDL_GetWMInfo(&wminfo) != 1)
    {
    // error: wrong SDL version
    }

    hwnd = wminfo.window;

    ::SetClassLong(hwnd, GCL_HICON, (LONG) icon_);

    //oldProc = (WNDPROC) ::SetWindowLong(hwnd, GWL_WNDPROC, (LONG) WndProc);
#endif //_WIN32
}

void GW_PlatformSDL::plat_finish()
{
#ifdef _WIN32
    ::DestroyIcon(icon_);
#endif //_WIN32
}
