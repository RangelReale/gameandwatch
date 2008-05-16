#include "menu.h"

void GW_Menu::Run()
{
    if (gamelist_->count()>0)
        current_set(0);

    bool quit=false;
    while (!quit)
    {
        GW_Platform_Event event;
        while (platform_->event(GPG_MENU, &event))
        {
            if (!process_event(&event))
            {
                quit=true;
                break;
            }
        }
        if (quit)
            break;

        if (changed_)
        {
            // clear screen
            platform_->draw_clear();


            draw_bg();

            draw_title();
            draw_gamelist();

            platform_->draw_flip();
            changed_=false;
        }
    } // end main loop
}

bool GW_Menu::process_event(GW_Platform_Event *event)
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
        case GPK_TURNONTOGGLE:
            rungame();
            changed_=true;
            // selected
            break;
        case GPK_UP:
            current_set(current_-1);
            break;
        case GPK_DOWN:
            current_set(current_+1);
            break;
        }
    default:
        break;
    }
    return true;
}

void GW_Menu::draw_text_center(int y, const string &text)
{
    platform_->text_draw(
        (platform_->width_get() / 2) - (platform_->text_width(text) / 2),
        y-(platform_->text_height(text) / 2),
        text);
}

void GW_Menu::draw_textbox_center(int y, const string &text, GW_Platform_RGB &color)
{
    int xdraw=(platform_->width_get() / 2) - (platform_->text_width(text) / 2);
    int ydraw=y-(platform_->text_height(text) / 2);
    platform_->draw_rectangle(xdraw, ydraw, xdraw+platform_->text_width(text), ydraw+platform_->text_fontheight(), NULL, &color);
    platform_->text_draw(xdraw, ydraw, text);
}

void GW_Menu::draw_title()
{
    const int spacing=10;

    draw_title_and_line(spacing, spacing, "Game & Watch Simulator");
    draw_title_and_line(platform_->height_get()-spacing, spacing, "by Hitnrun and Madrigal");

    platform_->draw_line(spacing, spacing, spacing, platform_->height_get()-spacing);
    platform_->draw_line(platform_->width_get()-spacing, spacing, platform_->width_get()-spacing, platform_->height_get()-spacing);
}

void GW_Menu::draw_title_and_line(int y, int spacing, const string &title)
{
    int titwidth=platform_->text_width(title);

    draw_text_center(y, title);
    platform_->draw_line(spacing, y, ((platform_->width_get()-titwidth)/2)-spacing, y);
    platform_->draw_line(titwidth+((platform_->width_get()-titwidth)/2)+spacing, y, platform_->width_get()-spacing, y);
}

void GW_Menu::draw_gamelist()
{
    int dpos=5+(2*platform_->text_fontheight());

    GW_PLATFORM_RGB(boxcolor, 255, 0, 0);
    for (int i=0; i<gamelist_->count(); i++)
    {
        if (i==current_)
            draw_textbox_center(dpos, gamelist_->get(i)->description(), boxcolor);
        else
            draw_text_center(dpos, gamelist_->get(i)->description());

        dpos+=platform_->text_fontheight();
    }
}

void GW_Menu::draw_bg()
{
    if (bg_.get())
    {
        int xdraw=(platform_->width_get() / 2) - (bg_->width_get() / 2);
        int ydraw=(platform_->height_get() / 2) - (bg_->height_get() / 2);

        platform_->draw_image(bg_.get(), xdraw, ydraw);

        GW_PLATFORM_RGB(rcolor, 0, 0, 0);
        platform_->draw_rectangle(xdraw, ydraw, xdraw+bg_->width_get(), ydraw+bg_->height_get(),
            NULL, &rcolor, 140);
    }
}

void GW_Menu::rungame()
{
    GW_Game *game=gamelist_->get(current_)->create();
    GW_Device device(platform_);
    device.Run(game);
    delete game;
}

void GW_Menu::current_set(int cur)
{
    current_=cur;
    if (current_<0) current_=0;
    if (current_>gamelist_->count()-1) current_=gamelist_->count()-1;
    if (current_>-1)
    {
        bg_.reset(platform_->image_load(gamelist_->get(current_)->bgimg_path(),
            (gamelist_->get(current_)->istcolor()?&gamelist_->get(current_)->tcolor():NULL)));
        bg_->resize_fit(platform_->width_get(), platform_->height_get());
    }
    else
        bg_.release();
    changed_=true;
}
