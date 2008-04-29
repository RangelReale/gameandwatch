#include "boost/filesystem.hpp"

#include "gwdefs.h"
#include "device.h"

//using boost::filesystem;
namespace bf = boost::filesystem;


//////////////////////////////////////////
////
//// GW_GameData_Sound
////
//////////////////////////////////////////
GW_GameData_Sound::~GW_GameData_Sound()
{
    if (sample_)
        Mix_FreeChunk(sample_);
}

void GW_GameData_Sound::Load(const string &soundpath)
{
    if (sample_)
        Mix_FreeChunk(sample_);

    sample_ = Mix_LoadWAV( bf::path( bf::path(soundpath) / sound_).string().c_str() );
    if (!sample_)
        throw GW_Exception(string("Unable to load sound sample: "+string(Mix_GetError())));
}

//////////////////////////////////////////
////
//// GW_GameData_Image
////
//////////////////////////////////////////
GW_GameData_Image::~GW_GameData_Image()
{
    if (surface_)
        SDL_FreeSurface(surface_);
}

void GW_GameData_Image::Load(const string &imagepath)
{
    if (surface_)
        SDL_FreeSurface(surface_);

    surface_ = SDL_LoadBMP( bf::path( bf::path(imagepath) / image_).string().c_str() );
    if (!surface_)
        throw GW_Exception(string("Unable to load image: "+string(SDL_GetError())));
    SDL_SetColorKey(surface_, SDL_SRCCOLORKEY, SDL_MapRGB(surface_->format, 255, 255, 255));
    SDL_DisplayFormat(surface_);

}


//////////////////////////////////////////
////
//// GW_GameData
////
//////////////////////////////////////////
GW_GameData *GW_GameData::image_add(int id, int index, const string &image)
{
    if (image.empty())
        throw GW_Exception("Image cannot be blank");

    images_[id][index]=shared_ptr<GW_GameData_Image>(new GW_GameData_Image(image));
    return this;
}

GW_GameData *GW_GameData::position_add(int id, int index, int x, int y,
    int imageid, int imageindex, const string &image)
{
    positions_[id][index]=shared_ptr<GW_GameData_Position>(new GW_GameData_Position(x, y));

    if (imageid>-1)
    {
        if (!image_get(imageid, imageindex))
            image_add(imageid, imageindex, image);
        position_get(id, index)->image_set(imageid, imageindex);
    }

    return this;
}

GW_GameData *GW_GameData::sound_add(int id, const string &sound)
{
    if (sound.empty())
        throw GW_Exception("Sound cannot be blank");

    sounds_[id]=shared_ptr<GW_GameData_Sound>(new GW_GameData_Sound(sound));
    return this;
}

GW_GameData_Image *GW_GameData::image_get(int id, int index)
{
    images_t::iterator i=images_.find(id);
    if (i!=images_.end())
    {
        imagesindex_t::iterator j=i->second.find(index);
        if (j!=i->second.end())
            return &*j->second;
    }
    return NULL;
}

GW_GameData_Position *GW_GameData::position_get(int id, int index)
{
    positions_t::iterator i=positions_.find(id);
    if (i!=positions_.end())
    {
        positionsindex_t::iterator j=i->second.find(index);
        if (j!=i->second.end())
            return &*j->second;
    }
    return NULL;
}

GW_GameData_Sound *GW_GameData::sound_get(int id)
{
    sounds_t::iterator i=sounds_.find(id);
    if (i!=sounds_.end())
    {
        return &*i->second;
    }
    return NULL;
}

void GW_GameData::Load(const string &gamepath)
{
    bf::path imagepath( bf::path(gamepath) / "image" );
    bf::path soundpath( bf::path(gamepath) / "sound" );

    for (images_t::iterator i=images_.begin(); i!=images_.end(); i++)
        for (imagesindex_t::iterator j=i->second.begin(); j!=i->second.end(); j++)
            j->second->Load(imagepath.string());
    for (sounds_t::iterator i=sounds_.begin(); i!=sounds_.end(); i++)
        i->second->Load(soundpath.string());
}

//////////////////////////////////////////
////
//// GW_Game
////
//////////////////////////////////////////
GW_Game::GW_Game() : data_(),
    gamepath_(""), bgimage_("bg.bmp"), width_(0), height_(0),
    on_(false), mode_(-1), device_(NULL)
{
    gamerect_.x=gamerect_.y=gamerect_.w=gamerect_.h=-1;
}

void GW_Game::data_showall()
{
    for (GW_GameData::positions_t::const_iterator i=data_.positions_list().begin();
        i!=data_.positions_list().end(); i++)
    {
        for (GW_GameData::positionsindex_t::const_iterator j=i->second.begin();
            j!=i->second.end(); j++)
        {
            j->second->visible_set(true);
        }
    }
}

void GW_Game::data_hideall()
{
    for (GW_GameData::positions_t::const_iterator i=data_.positions_list().begin();
        i!=data_.positions_list().end(); i++)
    {
        for (GW_GameData::positionsindex_t::const_iterator j=i->second.begin();
            j!=i->second.end(); j++)
        {
            j->second->visible_set(false);
        }
    }
}

void GW_Game::data_playsound(int soundid)
{
    Mix_PlayChannel(-1, data_.sound_get(soundid)->sample_get(), 0);
}

void GW_Game::Load(GW_Device *device, const string &datapath)
{
    device_=device;

    bf::path gamepath=bf::path(datapath) / gamepath_;

    data_.Load( gamepath.string() );
}

//////////////////////////////////////////
////
//// GW_Device
////
//////////////////////////////////////////
GW_Device::GW_Device(GW_Platform *platform, GW_Game *game) :
    platform_(platform), game_(game),
    datapath_("data"), quit_(false),
    screen_(NULL), bg_(NULL)
{
    // initialize SDL video
    if ( SDL_Init( platform_->sdlinit(SDL_INIT_VIDEO|SDL_INIT_AUDIO) ) < 0 )
        throw GW_Exception(string("Unable to init SDL: "+string(SDL_GetError())));

    if ( Mix_OpenAudio(22050, AUDIO_S16SYS, 1, 1024) < 0)
        throw GW_Exception(string("Unable to init SDL_mixer: "+string(Mix_GetError())));

    Mix_AllocateChannels(6);

    platform_->initialize();

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    screen_ = SDL_SetVideoMode(platform_->width_get(), platform_->height_get(), 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen_ )
        throw GW_Exception(string("Unable to set resolution: "+string(SDL_GetError())));

    platform_->device_set(this);
}

GW_Device::~GW_Device()
{
    platform_->finalize();

    Mix_CloseAudio();
}

void GW_Device::draw_game()
{
    for (GW_GameData::positions_t::const_iterator i=game_->data().positions_list().begin();
        i!=game_->data().positions_list().end(); i++)
    {
        for (GW_GameData::positionsindex_t::const_iterator j=i->second.begin();
            j!=i->second.end(); j++)
        {
            if (j->second->visible_get() && j->second->imageid_get() > -1)
            {
                SDL_Rect spos=position(&*j->second);
                SDL_BlitSurface(game_->data().image_get(j->second->imageid_get(), j->second->imageindex_get())->surface_get(),
                    NULL, screen_, &spos);
            }
        }
    }
}

void GW_Device::Run()
{
    Load();

    MoveBGCenter();

    while (!quit_)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            platform_->process_event(&event);
        }

        // clear screen
        SDL_FillRect(screen_, 0, SDL_MapRGB(screen_->format, 0, 0, 0));

        // draw bg
        SDL_BlitSurface(bg_, &bgsrc_, screen_, &bgdst_);

        //SDL_Rect spos=image_position(game_->sprites().sprites_get(1)->sprites_get(1)->image_get(1));
        //SDL_BlitSurface(game_->sprites().sprites_get(1)->sprites_get(1)->image_get(1)->surface_get(), NULL, screen_,
            //&spos);

        if (game_->IsOn())
        {
            if (SDL_GetTicks()-curtime_>=game_->TickTime())
            {
                game_->Tick();
                curtime_=SDL_GetTicks();
            }
            game_->Update();
        }


        draw_game();


        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen_);
    } // end main loop

    Unload();
}

SDL_Rect GW_Device::position(GW_GameData_Position *pos)
{
    SDL_Rect r;
    r.x=pos->x_get()+offsetx_;
    r.y=pos->y_get()+offsety_;
    return r;
}

void GW_Device::MoveBG(int xpos, int ypos)
{
    offsetx_=xpos;
    offsety_=ypos;
    CalculateBGOffset();
}

void GW_Device::MoveBGOffset(int xoff, int yoff)
{
    offsetx_+=xoff;
    offsety_+=yoff;
    CalculateBGOffset();
}

void GW_Device::MoveBGCenter()
{
    // center the gamerect area on the screen
    offsetx_=((platform_->width_get()-game_->gamerect_get().w)/2)-game_->gamerect_get().x;
    offsety_=((platform_->height_get()-game_->gamerect_get().h)/2)-game_->gamerect_get().y;
    CalculateBGOffset();
}

void GW_Device::GetTime(devtime_t *time)
{
    unsigned int timems=platform_->timems_get()/1000;
    time->s=timems % 60;
    timems-=time->s;
    time->h=timems / 3600;
    time->m=timems % 3600 / 60;
}

void GW_Device::CalculateBGOffset()
{
    bgsrc_.w=platform_->width_get();
    bgsrc_.h=platform_->height_get();

    if (offsetx_<0)
    {
        bgsrc_.x=abs(offsetx_);
        bgdst_.x=0;
    }
    else
    {
        bgsrc_.x=0;
        bgdst_.x=offsetx_;
    }
    if (offsety_<0)
    {
        bgsrc_.y=abs(offsety_);
        bgdst_.y=0;
    }
    else
    {
        bgsrc_.y=0;
        bgdst_.y=offsety_;
    }
}

void GW_Device::Load()
{
    bf::path rootpath(datapath_);
    rootpath /= game_->gamepath_get();

    bf::path imagepath=rootpath / bf::path("image");
    bf::path soundpath=rootpath / bf::path("sound");
    //rootpath /= game_->bgimage_get();

    // load bg
    bg_ = SDL_LoadBMP( bf::path(imagepath / game_->bgimage_get()).string().c_str() );
    if (!bg_)
        throw GW_Exception(string("Unable to load background: "+string(SDL_GetError())));
    SDL_SetColorKey(bg_, SDL_SRCCOLORKEY, SDL_MapRGB(bg_->format, 255, 0, 255));
    SDL_DisplayFormat(bg_);

    game_->Load(this, datapath_);
}

void GW_Device::Unload()
{
    if (bg_)
        SDL_FreeSurface(bg_);
    bg_=NULL;
}
