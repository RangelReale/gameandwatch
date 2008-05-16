#include "devices/dev_defendo.h"

GW_Game *GW_Game_Defendo_Info::create()
{
    return new GW_Game_Defendo;
}

GW_Game_Defendo::GW_Game_Defendo() :
    GW_GameEngine_VTech_Monkey(GO_NUMBERSEPARATED)
{
    gamepath_set("defendo");

    // game size
    size_set(614, 378);

    // game screen position
    GW_PLATFORM_RECT(gr, 201, 99, 161, 209);
    gamerect_set(gr);

    // character
    data().
        position_change(PS_CHAR_1, 1, 237, 151)->
        position_change(PS_CHAR_1, 2, 225, 151)->
        position_change(PS_CHAR_1, 3, 213, 152);
    data().
        position_change(PS_CHAR_2, 1, 275, 152)->
        position_change(PS_CHAR_2, 2, 268, 150)->
        position_change(PS_CHAR_2, 3, 261, 151);
    data().
        position_change(PS_CHAR_3, 1, 295, 153)->
        position_change(PS_CHAR_3, 2, 314, 149)->
        position_change(PS_CHAR_3, 3, 315, 147);

    // item
    data().
        position_change(PS_ITEM_1, 1, 212, 268)->
        position_change(PS_ITEM_1, 2, 238, 268)->
        position_change(PS_ITEM_1, 3, 227, 253)->
        position_change(PS_ITEM_1, 4, 228, 222)->
        position_change(PS_ITEM_1, 5, 232, 187)->
        position_change(PS_ITEM_1, IDX_GOT, 207, 196)->
        position_change(PS_ITEM_1, IDX_MISS, 207, 229)->
        position_change(PS_ITEM_1, IDX_HIT, 232, 187); // same image as 5
    data().
        position_change(PS_ITEM_2, 1, 288, 293)->
        position_change(PS_ITEM_2, 2, 273, 259)->
        position_change(PS_ITEM_2, 3, 283, 238)->
        position_change(PS_ITEM_2, 4, 281, 203)->
        position_change(PS_ITEM_2, 5, 280, 172)->
        position_change(PS_ITEM_2, IDX_GOT, 250, 183)->
        position_change(PS_ITEM_2, IDX_MISS, 256, 224)->
        position_change(PS_ITEM_2, IDX_HIT, 280, 172); // same image as 5
    data().
        position_change(PS_ITEM_3, 1, 342, 291)->
        position_change(PS_ITEM_3, 2, 322, 281)->
        position_change(PS_ITEM_3, 3, 320, 253)->
        position_change(PS_ITEM_3, 4, 314, 220)->
        position_change(PS_ITEM_3, 5, 307, 183)->
        position_change(PS_ITEM_3, IDX_GOT, 328, 155)->
        position_change(PS_ITEM_3, IDX_MISS, 331, 207)->
        position_change(PS_ITEM_3, IDX_HIT, 307, 183);

    // numbers
    data().
        position_change(PS_NUMBER, 1, 268, 124)->
        position_change(PS_NUMBER, 2, 284, 124)->
        position_change(PS_NUMBER, 3, 306, 124)->
        position_change(PS_NUMBER, 4, 323, 124)->
        position_change(PS_SEMICOLON, 0, 297, 129);


    // miss
    data().
        position_change(PS_MISS, 1, 342, 104)->
        position_change(PS_MISS, 2, 329, 104)->
        position_change(PS_MISS, 3, 316, 104)->
        position_change(PS_MISS, 4, 303, 104)->
        position_change(PS_MISS, 5, 290, 104)->
        position_change(PS_MISS, 6, 275, 104)->
        position_change(PS_MISS, 7, 263, 104)->
        position_change(PS_MISS, 8, 253, 104)->
        position_change(PS_MISS, 9, 243, 104)->
        position_change(PS_MISS, 10, 232, 104);

    // options
    data().
        position_change(PS_GAMEA, 0, 211, 112)->
        position_change(PS_GAMEB, 0, 222, 111)->
        position_change(PS_ALARM, 0, 212, 134)->
        position_change(PS_BELL, 0, 248, 117)->
        position_change(PS_CHRONO, 0, 252, 136)->
        position_change(PS_DATE, 0, 231, 136)->
        position_change(PS_TIME1, 0, 212, 125)->
        position_change(PS_TIME2, 0, 224, 125)->
        position_change(PS_AM, 0, 339, 124)->
        position_change(PS_PM, 0, 339, 136);
}

