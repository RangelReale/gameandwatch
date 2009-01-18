#include "gwdbg.h"
#include "devices/deveng_vtech_banana.h"

GW_GameEngine_VTech_Banana::GW_GameEngine_VTech_Banana(int engineoptions, int options) :
    GW_GameEngine_VTech(engineoptions), options_(options)
{
    // "BANANA" is default

    gamepath_set("banana");
    size_set(561, 347);

    // game screen position
    GW_PLATFORM_RECT(gr, 152, 53, 257, 192);
    gamerect_set(gr);

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // character 1
    data().
        position_add(PS_CHAR_1, 1, 258, 138, IM_CHAR_1, 1, "im_char_1_1.bmp", &tcolor_img);
    if ((options_&GO_HAVECHARANIM)==GO_HAVECHARANIM)
        data().
        position_add(PS_CHAR_1, 2, 236, 145, IM_CHAR_1, 2, "im_char_1_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_1, 3, 247, 128, IM_CHAR_1, 3, "im_char_1_3.bmp", &tcolor_img);

    // character 2
    data().
        position_add(PS_CHAR_2, 1, 280, 141, IM_CHAR_2, 1, "im_char_2_1.bmp", &tcolor_img);
    if ((options_&GO_HAVECHARANIM)==GO_HAVECHARANIM)
        data().
        position_add(PS_CHAR_2, 2, 312, 149, IM_CHAR_2, 2, "im_char_2_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_2, 3, 309, 129, IM_CHAR_2, 3, "im_char_2_3.bmp", &tcolor_img);

    // character 3
    data().
        position_add(PS_CHAR_3, 1, 200, 207, IM_CHAR_3, 1, "im_char_3_1.bmp", &tcolor_img);
    if ((options_&GO_HAVECHARANIM)==GO_HAVECHARANIM)
        data().
        position_add(PS_CHAR_3, 2, 226, 214, IM_CHAR_3, 2, "im_char_3_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_3, 3, 225, 197, IM_CHAR_3, 3, "im_char_3_3.bmp", &tcolor_img);

    // character 4
    data().
        position_add(PS_CHAR_4, 1, 349, 211, IM_CHAR_4, 1, "im_char_4_1.bmp", &tcolor_img);
    if ((options_&GO_HAVECHARANIM)==GO_HAVECHARANIM)
        data().
        position_add(PS_CHAR_4, 2, 327, 215, IM_CHAR_4, 2, "im_char_4_2.bmp", &tcolor_img)->
        position_add(PS_CHAR_4, 3, 335, 201, IM_CHAR_4, 3, "im_char_4_3.bmp", &tcolor_img);

    // item 1
    data().
        position_add(PS_ITEM_1, 1, 160, 99, IM_ITEM_1, 1, "im_item_1_01.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 2, 178, 101, IM_ITEM_1, 2, "im_item_1_02.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 3, 200, 101, IM_ITEM_1, 3, "im_item_1_03.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 4, 226, 99, IM_ITEM_1, 4, "im_item_1_04.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 5, 264, 100, IM_ITEM_1, 5, "im_item_1_05.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 6, 281, 100, IM_ITEM_1, 6, "im_item_1_06.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 7, 307, 99, IM_ITEM_1, 7, "im_item_1_07.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 8, 340, 100, IM_ITEM_1, 8, "im_item_1_08.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 9, 359, 100, IM_ITEM_1, 9, "im_item_1_09.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, 10, 380, 101, IM_ITEM_1, 10, "im_item_1_10.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, IDX_MISS_4, 244, 94, IM_ITEM_1, IDX_MISS_4, "im_item_1_04miss.bmp", &tcolor_img)->
        //position_add(PS_ITEM_1, IDX_OBSTACLE_4, 236, 130, IM_ITEM_1, IDX_OBSTACLE_4, "im_item_1_04obstacle.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, IDX_MISS_7, 320, 93, IM_ITEM_1, IDX_MISS_7, "im_item_1_07miss.bmp", &tcolor_img);
/*
    if ((options_&GO_HAVEOBSTACLE17)==GO_HAVEOBSTACLE17)
        data().
        position_add(PS_ITEM_1, IDX_OBSTACLE_7, 321, 132, IM_ITEM_1, IDX_OBSTACLE_7, "im_item_1_07obstacle.bmp", &tcolor_img);
*/

    // item 2
    data().
        position_add(PS_ITEM_2, 1, 160, 171, IM_ITEM_2, 1, "im_item_2_01.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 2, 184, 169, IM_ITEM_2, 2, "im_item_2_02.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 3, 205, 169, IM_ITEM_2, 3, "im_item_2_03.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 4, 238, 168, IM_ITEM_2, 4, "im_item_2_04.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 5, 265, 168, IM_ITEM_2, 5, "im_item_2_05.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 6, 291, 168, IM_ITEM_2, 6, "im_item_2_06.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 7, 330, 169, IM_ITEM_2, 7, "im_item_2_07.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 8, 347, 170, IM_ITEM_2, 8, "im_item_2_08.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 9, 367, 169, IM_ITEM_2, 9, "im_item_2_09.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, 10, 386, 166, IM_ITEM_2, 10, "im_item_2_10.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_MISS_4, 207, 159, IM_ITEM_2, IDX_MISS_4, "im_item_2_04miss.bmp", &tcolor_img)->
        //position_add(PS_ITEM_2, IDX_OBSTACLE_4, 239, 202, IM_ITEM_2, IDX_OBSTACLE_4, "im_item_2_04obstacle.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_MISS_7, 304, 167, IM_ITEM_2, IDX_MISS_7, "im_item_2_07miss.bmp", &tcolor_img);
        //position_add(PS_ITEM_2, IDX_OBSTACLE_7, 324, 201, IM_ITEM_2, IDX_OBSTACLE_7, "im_item_2_07obstacle.bmp", &tcolor_img);

    // obstacle
    data().
        position_add(PS_OBSTACLE, 1, 236, 130, IM_OBSTACLE, 1, "im_item_1_04obstacle.bmp", &tcolor_img)->
        position_add(PS_OBSTACLE, 3, 239, 202, IM_OBSTACLE, 3, "im_item_2_04obstacle.bmp", &tcolor_img)->
        position_add(PS_OBSTACLE, 4, 324, 201, IM_OBSTACLE, 4, "im_item_2_07obstacle.bmp", &tcolor_img);
    if ((options_&GO_HAVEOBSTACLE17)==GO_HAVEOBSTACLE17)
        data().
        position_add(PS_OBSTACLE, 2, 321, 132, IM_OBSTACLE, 2, "im_item_1_07obstacle.bmp", &tcolor_img);


    // numbers
    data().
        position_change(PS_NUMBER, 1, 257, 61)->
        position_change(PS_NUMBER, 2, 272, 61)->
        position_change(PS_NUMBER, 3, 290, 61)->
        position_change(PS_NUMBER, 4, 305, 61)->
        position_change(PS_SEMICOLON, 0, 286, 66);

    // miss
    data().
        position_change(PS_MISS, 1, 333, 61)->
        position_change(PS_MISS, 2, 349, 61)->
        position_change(PS_MISS, 3, 363, 61)->
        position_change(PS_MISS, 4, 377, 61)->
        position_change(PS_MISS, 5, 392, 61)->
        position_change(PS_MISS, 6, 334, 75)->
        position_change(PS_MISS, 7, 349, 75)->
        position_change(PS_MISS, 8, 363, 75)->
        position_change(PS_MISS, 9, 377, 75)->
        position_change(PS_MISS, 10, 392, 75);

    // options
    data().
        position_change(PS_GAMEA, 0, 160, 61)->
        position_change(PS_GAMEB, 0, 160, 72)->
        position_change(PS_ALARM, 0, 206, 73)->
        position_change(PS_BELL, 0, 186, 63)->
        position_change(PS_CHRONO, 0, 223, 73)->
        position_change(PS_DATE, 0, 237, 73)->
        position_change(PS_TIME1, 0, 229, 61)->
        position_change(PS_TIME2, 0, 206, 61)->
        position_change(PS_AM, 0, 320, 61)->
        position_change(PS_PM, 0, 320, 76);

    // sounds
    data().
        sound_add(SND_HIGH, "High.wav")->
        sound_add(SND_LOW, "Low.wav")->
        sound_add(SND_MISS, "Miss.wav")->
        sound_add(SND_OVER, "Over.wav")->
        sound_add(SND_SAFE, "Safe.wav")->
        sound_add(SND_START, "Start.wav");

    // timers
    data().
		timer_add(TMR_HIT, 75, false)->
		timer_get(TMR_GAME)->time_set(500);

}

void GW_GameEngine_VTech_Banana::do_timer(int timerid)
{
    GW_GameEngine_VTech::do_timer(timerid);

    switch (timerid)
    {
    case TMR_HIT:
        char_update(char_position_, false);
        break;
    }
}

void GW_GameEngine_VTech_Banana::Event(GW_Platform_Event *event)
{
    GW_GameEngine_VTech::Event(event);

    if (event->id==GPE_KEYDOWN)
    {
        switch (event->data)
        {
        case GPK_UPLEFT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_update(0, true);
                data_starttimer(TMR_HIT);
            }
            break;
        case GPK_DOWNLEFT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_update(2, true);
                data_starttimer(TMR_HIT);
            }
            break;
        case GPK_UPRIGHT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_update(1, true);
                data_starttimer(TMR_HIT);
            }
            break;
        case GPK_DOWNRIGHT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_update(3, true);
                data_starttimer(TMR_HIT);
            }
            break;
        }
    }
}

void GW_GameEngine_VTech_Banana::game_start(int mode)
{
    GW_GameEngine_VTech::game_start(mode);

    tick_=1;

    char_update(0, false);

    data().position_get(PS_ITEM_1, 1)->show();
    data().position_get(PS_ITEM_2, 10)->show();

    data_playsound(SND_START);
}

void GW_GameEngine_VTech_Banana::game_tick()
{
	static int curitem, posmod;

	tick_++;
    if (tick_>1) tick_=0;

	GWDBG_FOUTPUT("game_tick: %d\n", tick_)

	curitem=PS_ITEM_1+tick_;
	if (curitem==PS_ITEM_1) posmod=0; else posmod=10+1;

    for (int i=10; i>=2; i--)
    {
        if (curitem==PS_ITEM_1)
            data().position_get(PS_ITEM_1, i)->visible_set(data().position_get(PS_ITEM_1, i-1)->visible_get());
        else if (curitem==PS_ITEM_2)
            data().position_get(PS_ITEM_2, 10-i+1)->visible_set(data().position_get(PS_ITEM_2, 10-i+2)->visible_get());
    }
    if (curitem==PS_ITEM_1)
        data().position_get(PS_ITEM_1, 1)->visible_set(false);
    else if (curitem==PS_ITEM_2)
        data().position_get(PS_ITEM_2, 10)->visible_set(false);


    if (tick_==0)
        data_playsound(SND_HIGH);
    else if (tick_==1)
        data_playsound(SND_LOW);
}

void GW_GameEngine_VTech_Banana::char_update(int pos, bool hit)
{
    char_position_=pos;
    for (int i=PS_CHAR_1; i<=PS_CHAR_4; i++)
    {
        data().position_get(i, 1)->visible_set(i-PS_CHAR_1==pos);
        if ((options_&GO_HAVECHARANIM)==GO_HAVECHARANIM)
        {
            data().position_get(i, 2)->visible_set(i-PS_CHAR_1==pos && !hit);
            data().position_get(i, 3)->visible_set(i-PS_CHAR_1==pos && hit);
        }
    }
    obstacle_update(pos+1);
}

void GW_GameEngine_VTech_Banana::obstacle_update(int pos)
{
    for (int i=1; i<=4; i++)
    {
        if (i==2 && (options_&GO_HAVEOBSTACLE17)!=GO_HAVEOBSTACLE17)
            continue;

        data().position_get(PS_OBSTACLE, i)->visible_set(i!=pos);
    }
}

