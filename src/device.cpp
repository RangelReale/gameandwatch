#include <iostream>
#include "gwdefs.h"
#include "device.h"
#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;


//////////////////////////////////////////
////
//// GW_GameData_Item
////
//////////////////////////////////////////
void GW_GameData_Item::Changed()
{
    gdata_->Changed();
}

GW_Platform *GW_GameData_Item::platform_get()
{
    return gdata_->game_get()->device_get()->platform_get();
}

//////////////////////////////////////////
////
//// GW_GameData_Sound
////
//////////////////////////////////////////
GW_GameData_Sound::~GW_GameData_Sound()
{
    if (sounddata_)
        delete sounddata_;
}

void GW_GameData_Sound::Load(const string &soundpath)
{
    if (sounddata_)
        delete sounddata_;

    sounddata_=platform_get()->sound_load( bf::path( bf::path(soundpath) / sound_).string() );
}

//////////////////////////////////////////
////
//// GW_GameData_Timer
////
//////////////////////////////////////////
void GW_GameData_Timer::start(unsigned int time)
{
    if (time>0)
        time_=time;
    delay_=0;
    curtime_=platform_get()->ticks_get();
}

void GW_GameData_Timer::stop()
{
    curtime_=0;
}

bool GW_GameData_Timer::started()
{
    return time_>0 && curtime_>0;
}

bool GW_GameData_Timer::finished()
{
    bool ret=
        started() &&
        (curtime_+delay_ <= platform_get()->ticks_get()) &&
        (platform_get()->ticks_get()-curtime_+delay_ > time_);
/*
    if (ret)
    {
        if (!autoloop_)
            curtime_=0;
        else
            curtime_=platform_get()->ticks_get();
    }
*/
    return ret;
}

void GW_GameData_Timer::loop()
{
    if (finished())
    {
        delay_=0;
        if (!autoloop_)
            curtime_=0;
        else
            curtime_=platform_get()->ticks_get();
    }
}

void GW_GameData_Timer::delay(unsigned int time)
{
    if (started())
        delay_+=time;
        //curtime_+=time;
}

//////////////////////////////////////////
////
//// GW_GameData_Image
////
//////////////////////////////////////////
GW_GameData_Image::~GW_GameData_Image()
{
    if (imagedata_)
        delete imagedata_;
}

void GW_GameData_Image::Load(const string &imagepath)
{
    if (imagedata_)
        delete imagedata_;

    //GW_PLATFORM_RGB(tcolor, 255, 255, 255);
    imagedata_=platform_get()->image_load(bf::path( bf::path(imagepath) / image_).string(), (istcolor_?&tcolor_:NULL));

    Changed();
}


//////////////////////////////////////////
////
//// GW_GameData
////
//////////////////////////////////////////
GW_GameData *GW_GameData::image_add(int id, int index, const string &image, GW_Platform_RGB *tcolor)
{
    if (image.empty())
        throw GW_Exception("Image cannot be blank");

    images_[id][index]=shared_ptr<GW_GameData_Image>(new GW_GameData_Image(this, image, tcolor));
    Changed();
    return this;
}

GW_GameData *GW_GameData::position_add(int id, int index, int x, int y,
    int imageid, int imageindex, const string &image, GW_Platform_RGB *tcolor)
{
    positions_[id][index]=shared_ptr<GW_GameData_Position>(new GW_GameData_Position(this, x, y));

    if (imageid>-1)
    {
        if (!image_get(imageid, imageindex))
            image_add(imageid, imageindex, image, tcolor);
        position_get(id, index)->image_set(imageid, imageindex);
    }
    Changed();
    return this;
}

GW_GameData *GW_GameData::sound_add(int id, const string &sound)
{
    if (sound.empty())
        throw GW_Exception("Sound cannot be blank");

    sounds_[id]=shared_ptr<GW_GameData_Sound>(new GW_GameData_Sound(this, sound));
    Changed();
    return this;
}

GW_GameData *GW_GameData::timer_add(int timerid, unsigned int time, bool autoloop)
{
    timers_[timerid]=shared_ptr<GW_GameData_Timer>(new GW_GameData_Timer(this, timerid, time, autoloop));
    Changed();
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

GW_GameData_Timer *GW_GameData::timer_get(int timerid)
{
    timers_t::iterator i=timers_.find(timerid);
    if (i!=timers_.end())
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
    Changed();
}

void GW_GameData::Unload()
{
    images_.clear();
    sounds_.clear();
    timers_.clear();
    positions_.clear();
    Changed();
}

void GW_GameData::Changed()
{
    game_->Changed();
}

//////////////////////////////////////////
////
//// GW_Game
////
//////////////////////////////////////////
GW_Game::GW_Game() : data_(this),
    gamepath_(""), width_(0), height_(0),
    on_(false), mode_(-1), device_(NULL), changed_(true)
{
    gamerect_.x=gamerect_.y=gamerect_.w=gamerect_.h=-1;
}

void GW_Game::SetMode(int mode)
{
    if (IsOn())
    {
        if (do_setmode(mode))
            mode_=mode;
    }
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
    platform_get()->sound_play(data_.sound_get(soundid)->data_get());
}

void GW_Game::data_stopallsounds()
{
    platform_get()->sound_stop_all();
}

void GW_Game::data_starttimer(int timerid, unsigned int time)
{
    data().timer_get(timerid)->start(time);
}

void GW_Game::data_stopalltimers()
{
    for (GW_GameData::timers_t::iterator ti=data().timers_list().begin();
        ti!=data().timers_list().end(); ti++)
    {
        ti->second->stop();
    }
}

void GW_Game::data_delaytimer(int timerid, unsigned int time)
{
    data().timer_get(timerid)->delay(time);
}

void GW_Game::Load(GW_Device *device, const string &datapath)
{
    device_=device;

    bf::path gamepath=bf::path(datapath) / gamepath_;

    data_.Load( gamepath.string() );
}

void GW_Game::Unload()
{
    data_.Unload();
    device_=NULL;
}

void GW_Game::Update()
{
    // check timers
    for (GW_GameData::timers_t::iterator ti=data().timers_list().begin();
        ti!=data().timers_list().end(); ti++)
    {
        if (ti->second->finished())
        {
            do_timer(ti->second->timerid());
            ti->second->loop();
        }
    }

    do_update();
}

void GW_Game::Changed()
{
    changed_=true;
}

bool GW_Game::CheckChanged()
{
    bool ret=changed_;
    changed_=false;
    return ret;
}

GW_Platform *GW_Game::platform_get()
{
    return device_->platform_get();
}

//////////////////////////////////////////
////
//// GW_Game_Info
////
//////////////////////////////////////////
string GW_Game_Info::bgimg_path()
{
    return bf::path( bf::path("data") / datapath_ / "image" / bgimg_ ).string();
}

//////////////////////////////////////////
////
//// GW_Device
////
//////////////////////////////////////////
GW_Device::GW_Device(GW_Platform *platform) :
    platform_(platform), game_(NULL),
    datapath_("data"), quit_(false),
    volume_(75)
{
}

GW_Device::~GW_Device()
{

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
                GW_Platform_Point spos=position(&*j->second);
                platform_->draw_image(game_->data().image_get(j->second->imageid_get(), j->second->imageindex_get())->data_get(),
                    spos.x, spos.y);
            }
        }
    }
}

void GW_Device::Run(GW_Game *game)
{
    game_=game;

    Load();

    MoveBGCenter();

    bool quit=false;
    while (!quit)
    {
        GW_Platform_Event event;
        while (platform_->event(game_->gametype_get(), &event))
        {
            if (!process_event(&event))
            {
                quit=true;
                break;
            }
        }
        if (quit)
            break;

        if (game_->IsOn())
            game_->Update();

        if (game_->CheckChanged())
        {
            // clear screen
            platform_->draw_clear();

            // draw bg
            if (game_->bgimage_get()>-1)
                platform_->draw_image(game_->data().image_get(game_->bgimage_get())->data_get(), offsetx_, offsety_);

            draw_game();

            platform_->draw_flip();
        }
    } // end main loop

    Unload();
}

bool GW_Device::process_event(GW_Platform_Event *event)
{
    switch (event->id)
    {
    case GPE_QUIT:
        return false;
    case GPE_KEYDOWN:
        switch (event->data)
        {
        case GPK_QUIT:
            return false;
        case GPK_TURNON:
            TurnOn();
            return true;
        case GPK_TURNOFF:
            TurnOff();
            return true;
        case GPK_TURNONTOGGLE:
            if (IsOn())
                TurnOff();
            else
                TurnOn();
            return true;
        case GPK_VOLUP:
            Volume(volume_+5);
            return true;
        case GPK_VOLDOWN:
            Volume(volume_-5);
            return true;
        }
    default:
        break;
    }
    game_->Event(event);
    return true;
}

void GW_Device::Volume(int volume)
{
    volume_=platform_->sound_volume(volume);
}

GW_Platform_Point GW_Device::position(GW_GameData_Position *pos)
{
    GW_PLATFORM_POINT(r, pos->x_get()+offsetx_, pos->y_get()+offsety_);
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
    unsigned int timems=platform_->time_ms_get()/1000;
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
/*
    bg_ = SDL_LoadBMP( bf::path(imagepath / game_->bgimage_get()).string().c_str() );
    if (!bg_)
        throw GW_Exception(string("Unable to load background: "+string(SDL_GetError())));
    SDL_SetColorKey(bg_, SDL_SRCCOLORKEY, SDL_MapRGB(bg_->format, 255, 0, 255));
    SDL_DisplayFormat(bg_);
*/

    game_->Load(this, datapath_);
}

void GW_Device::Unload()
{
    //if (bg_)
        //SDL_FreeSurface(bg_);
    //bg_=NULL;

    game_->Unload();
    game_=NULL;
}
