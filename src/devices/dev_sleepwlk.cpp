#include "devices/dev_sleepwlk.h"

GW_Game *GW_Game_SleepWlk_Info::create()
{
    return new GW_Game_SleepWlk;
}

GW_Game_SleepWlk::GW_Game_SleepWlk() :
    GW_GameEngine_VTech_Banana(EO_MISSSEPARATED, GO_NONE)
{
    // game "BANANA" is default
    gamepath_set("sleepwlk");

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // bg - sleep walker bg is white not pink
    data().
        image_add(IM_BG, GW_INDEX_DEFAULT, "bg.bmp", &tcolor_img);

    // character 1
    data().
        position_change(PS_CHAR_1, 1, 192, 136);

    // character 2
    data().
        position_change(PS_CHAR_2, 1, 304, 130);

    // character 3
    data().
        position_change(PS_CHAR_3, 1, 183, 221);

    // character 4
    data().
        position_change(PS_CHAR_4, 1, 324, 211);

    // item 1
    data().
        position_change(PS_ITEM_1, 1, 158, 97)->
        position_change(PS_ITEM_1, 2, 181, 97)->
        position_change(PS_ITEM_1, 3, 207, 97)->
        position_change(PS_ITEM_1, 4, 227, 98)->
        position_change(PS_ITEM_1, 5, 258, 97)->
        position_change(PS_ITEM_1, 6, 284, 96)->
        position_change(PS_ITEM_1, 7, 308, 94)->
        position_change(PS_ITEM_1, 8, 331, 96)->
        position_change(PS_ITEM_1, 9, 351, 93)->
        position_change(PS_ITEM_1, 10, 374, 96)->
        position_change(PS_ITEM_1, IDX_MISS_4, 241, 79)->
        //position_change(PS_ITEM_1, IDX_OBSTACLE_4, 226, 132)->
        position_change(PS_ITEM_1, IDX_MISS_7, 307, 131);
        // 300, 130

    // item 2
    data().
        position_change(PS_ITEM_2, 1, 156, 176)->
        position_change(PS_ITEM_2, 2, 178, 173)->
        position_change(PS_ITEM_2, 3, 200, 176)->
        position_change(PS_ITEM_2, 4, 236, 176)->
        position_change(PS_ITEM_2, 5, 258, 175)->
        position_change(PS_ITEM_2, 6, 280, 175)->
        position_change(PS_ITEM_2, 7, 310, 176)->
        position_change(PS_ITEM_2, 8, 329, 177)->
        position_change(PS_ITEM_2, 9, 351, 177)->
        position_change(PS_ITEM_2, 10, 372, 176)->
        position_change(PS_ITEM_2, IDX_MISS_4, 216, 171)->
        //position_change(PS_ITEM_2, IDX_OBSTACLE_4, 220, 212)->
        position_change(PS_ITEM_2, IDX_MISS_7, 283, 139);
        //position_change(PS_ITEM_2, IDX_OBSTACLE_7, 290, 208);

    // obstacle
    data().
        position_change(PS_OBSTACLE, 1, 226, 132)->
        position_change(PS_OBSTACLE, 3, 220, 212)->
        position_change(PS_OBSTACLE, 4, 290, 208);


    // numbers
    data().
        position_change(PS_NUMBER, 1, 248, 53)->
        position_change(PS_NUMBER, 2, 263, 53)->
        position_change(PS_NUMBER, 3, 282, 53)->
        position_change(PS_NUMBER, 4, 297, 53)->
        position_change(PS_SEMICOLON, 0, 277, 58);

    // miss
    data().
        position_change(PS_MISS, 1, 331, 47)->
        position_change(PS_MISS, 2, 345, 47)->
        position_change(PS_MISS, 3, 358, 47)->
        position_change(PS_MISS, 4, 371, 47)->
        position_change(PS_MISS, 5, 385, 47)->
        position_change(PS_MISS, 6, 331, 65)->
        position_change(PS_MISS, 7, 345, 65)->
        position_change(PS_MISS, 8, 358, 65)->
        position_change(PS_MISS, 9, 372, 65)->
        position_change(PS_MISS, 10, 386, 65);

    // options
    data().
        position_change(PS_GAMEA, 0, 158, 53)->
        position_change(PS_GAMEB, 0, 158, 68)->
        position_change(PS_ALARM, 0, 200, 69)->
        position_change(PS_BELL, 0, 184, 55)->
        position_change(PS_CHRONO, 0, 217, 68)->
        position_change(PS_DATE, 0, 230, 69)->
        position_change(PS_TIME1, 0, 222, 53)->
        position_change(PS_TIME2, 0, 199, 53)->
        position_change(PS_AM, 0, 315, 53)->
        position_change(PS_PM, 0, 315, 68);
}


