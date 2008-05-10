#include <ctime>
#include "plat/plat_sdl.h"
#include "gwdefs.h"
#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;

//////////////////////////////////////////
////
//// GW_PlatformSDL_Image
////
//////////////////////////////////////////
GW_PlatformSDL_Image::GW_PlatformSDL_Image(const string &filename, GW_Platform_RGB *tcolor)
{
    surface_ = SDL_LoadBMP( filename.c_str() );
    if (!surface_)
        throw GW_Exception(string("Unable to load image: "+string(SDL_GetError())));
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
    SDL_Surface *news=zoomSurface(surface_, 0.4, 0.4, 0);
    if (news)
    {
        SDL_FreeSurface(surface_);
        surface_=news;
    }
    return news!=NULL;
}

//////////////////////////////////////////
////
//// GW_PlatformSDL_Sound
////
//////////////////////////////////////////
GW_PlatformSDL_Sound::GW_PlatformSDL_Sound(const string &filename)
{
    sample_ = Mix_LoadWAV( filename.c_str() );
    if (!sample_)
        throw GW_Exception(string("Unable to load sound sample: "+string(Mix_GetError())));
}

GW_PlatformSDL_Sound::~GW_PlatformSDL_Sound()
{
    Mix_FreeChunk(sample_);
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
        // initialize SDL video
        if ( SDL_Init( sdlinit(SDL_INIT_VIDEO|SDL_INIT_AUDIO) ) < 0 )
            throw GW_Exception(string("Unable to init SDL: "+string(SDL_GetError())));

        if ( Mix_OpenAudio(22050, AUDIO_S16SYS, 1, audiobufsize_get()) < 0)
            throw GW_Exception(string("Unable to init SDL_mixer: "+string(Mix_GetError())));

        if ( TTF_Init() < 0 )
            throw GW_Exception(string("Unable to init SDL_ttf: "+string(TTF_GetError())));

        Mix_AllocateChannels(6);
        sound_volume(75);

        custom_initialize();

        // make sure SDL cleans up before exit
        atexit(SDL_Quit);

        // create a new window
        screen_ = SDL_SetVideoMode(width_get(), height_get(), 16,
                                               SDL_HWSURFACE|SDL_DOUBLEBUF);
        if ( !screen_ )
            throw GW_Exception(string("Unable to set resolution: "+string(SDL_GetError())));

        SDL_ShowCursor(SDL_DISABLE);

        SDL_WM_SetCaption("Game & Watch simulator - by Hitnrun & Madrigal", NULL);

        // load font
        font_=TTF_OpenFont( bf::path( bf::path(platformdata_get() ) / "andalemo.ttf" ).string().c_str(), fontsize_get() );
        if (!font_)
            throw GW_Exception(string("Unable to load font: "+string(TTF_GetError())));

        initialized_=true;
    }
}

void GW_PlatformSDL::finalize()
{
    if (initialized_)
    {
        custom_finalize();

        TTF_CloseFont(font_);
        TTF_Quit();

        Mix_CloseAudio();

        SDL_Quit();

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
    GW_PLATFORM_RGB(lcolor,255,255,255);
    if (color) lcolor=*color;
    lineRGBA(screen_, x1, y1, x2, y2, lcolor.r, lcolor.g, lcolor.b, 255);
}

void GW_PlatformSDL::draw_rectangle(int x1, int y1, int x2, int y2,
    GW_Platform_RGB *forecolor, GW_Platform_RGB *backcolor)
{
    if (forecolor || (!forecolor && !backcolor))
    {
        GW_PLATFORM_RGB(lcolor,255,255,255);
        if (forecolor) lcolor=*forecolor;
        rectangleRGBA(screen_, x1, y1, x2, y2, lcolor.r, lcolor.g, lcolor.b, 255);
    }
    if (backcolor)
    {
        boxRGBA(screen_, x1, y1, x2, y2, backcolor->r, backcolor->g, backcolor->b, 255);
    }
}


void GW_PlatformSDL::draw_flip()
{
    SDL_Flip(screen_);
}

void GW_PlatformSDL::text_draw(int x, int y, const string &text,
    GW_Platform_RGB *color)
{
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
}

int GW_PlatformSDL::text_fontheight()
{
    return TTF_FontLineSkip(font_);
}

int GW_PlatformSDL::text_width(const string &text)
{
    int s;
    if (TTF_SizeText(font_, text.c_str(), &s, NULL) == 0)
        return s;
    return -1;
}

int GW_PlatformSDL::text_height(const string &text)
{
    int s;
    if (TTF_SizeText(font_, text.c_str(), NULL, &s) == 0)
        return s;
    return -1;
}

void GW_PlatformSDL::sound_play(GW_Platform_Sound *sound)
{
    Mix_PlayChannel(-1, dynamic_cast<GW_PlatformSDL_Sound*>(sound)->sample_get(), 0);
}

unsigned short GW_PlatformSDL::sound_volume(unsigned short volume)
{
    //if (volume<0) volume=0;
    if (volume>100) volume=100;

    Mix_Volume(-1, (MIX_MAX_VOLUME/100)*volume);
    return volume;
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

/*

void GW_PlatformSDL::_process_event(SDL_Event *event)
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
*/

