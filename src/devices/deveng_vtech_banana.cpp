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
        position_add(PS_ITEM_1, IDX_OBSTACLE_4, 236, 130, IM_ITEM_1, IDX_OBSTACLE_4, "im_item_1_04obstacle.bmp", &tcolor_img)->
        position_add(PS_ITEM_1, IDX_MISS_7, 320, 93, IM_ITEM_1, IDX_MISS_7, "im_item_1_07miss.bmp", &tcolor_img);
    if ((options_&GO_HAVEOBSTACLE17)==GO_HAVEOBSTACLE17)
        data().
        position_add(PS_ITEM_1, IDX_OBSTACLE_7, 321, 132, IM_ITEM_1, IDX_OBSTACLE_7, "im_item_1_07obstacle.bmp", &tcolor_img);

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
        position_add(PS_ITEM_2, IDX_OBSTACLE_4, 239, 202, IM_ITEM_2, IDX_OBSTACLE_4, "im_item_2_04obstacle.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_MISS_7, 304, 167, IM_ITEM_2, IDX_MISS_7, "im_item_2_07miss.bmp", &tcolor_img)->
        position_add(PS_ITEM_2, IDX_OBSTACLE_7, 234, 201, IM_ITEM_2, IDX_OBSTACLE_7, "im_item_2_07obstacle.bmp", &tcolor_img);


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
}

