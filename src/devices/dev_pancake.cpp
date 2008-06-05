#include "devices/dev_pancake.h"

GW_Game *GW_Game_Pancake_Info::create()
{
    return new GW_Game_Pancake;
}

GW_Game_Pancake::GW_Game_Pancake() :
    GW_GameEngine_VTech_Condor(EO_NONE, GO_HAVEITEM0|GO_HAVELEFT0|GO_HAVERIGHT1A|GO_HAVERIGHT6)
{
    gamepath_set("pancake");
    size_set(560, 372);

    // game screen position
    GW_PLATFORM_RECT(gr, 151, 52, 257, 192);
    gamerect_set(gr);

    // character
    data().
        position_change(PS_CHAR, 1, 177, 171)->
        position_change(PS_CHAR, 2, 262, 177)->
        position_change(PS_CHAR, 3, 306, 177);

    // item
    data().
        position_change(PS_ITEM, 0, 372, 117)->
        position_change(PS_ITEM, 1, 365, 106)->
        position_change(PS_ITEM, 2, 343, 103)->
        position_change(PS_ITEM, 3, 328, 114)->
        position_change(PS_ITEM, 4, 320, 130)->
        position_change(PS_ITEM, 5, 314, 148)->
        position_change(PS_ITEM, 6, 312, 166)->
        position_change(PS_ITEM, 7, 311, 179)->
        position_change(PS_ITEM, 8, 308, 156)->
        position_change(PS_ITEM, 9, 306, 136)->
        position_change(PS_ITEM, 10, 300, 119)->
        position_change(PS_ITEM, 11, 290, 104)->
        position_change(PS_ITEM, 12, 277, 115)->
        position_change(PS_ITEM, 13, 270, 131)->
        position_change(PS_ITEM, 14, 267, 148)->
        position_change(PS_ITEM, 15, 266, 165)->
        position_change(PS_ITEM, 16, 267, 178)->
        position_change(PS_ITEM, 17, 263, 156)->
        position_change(PS_ITEM, 18, 258, 136)->
        position_change(PS_ITEM, 19, 248, 118)->
        position_change(PS_ITEM, 20, 233, 132)->
        position_change(PS_ITEM, 21, 225, 149)->
        position_change(PS_ITEM, 22, 220, 165)->
        position_change(PS_ITEM, 23, 221, 178)->
        position_change(PS_ITEM, 24, 218, 156)->
        position_change(PS_ITEM, 25, 213, 140)->
        position_change(PS_ITEM, 26, 205, 131)->
        position_change(PS_ITEM, 27, 191, 137)->
        position_change(PS_ITEM, IDX_MISS_1, 219, 191)->
        position_change(PS_ITEM, IDX_MISS_2, 243, 189)->
        position_change(PS_ITEM, IDX_MISS_3, 306, 193);

    data().
        position_change(PS_ITEMLEFT, 0, 162, 117)->
        position_change(PS_ITEMLEFT, 1, 180, 138)->
        position_change(PS_ITEMLEFT, 2, 179, 129);

    // item right
    data().
        position_change(PS_ITEMRIGHT, 0, 335, 123)->
        position_change(PS_ITEMRIGHT, 1, 366, 163)->
        position_change(PS_ITEMRIGHT, 2, 370, 146)->
        position_change(PS_ITEMRIGHT, 3, 375, 146)->
        position_change(PS_ITEMRIGHT, 4, 360, 110)->
        position_change(PS_ITEMRIGHT, 5, 366, 129)->
        position_change(PS_ITEMRIGHT, 6, 166, 122);


    // numbers
    data().
        position_change(PS_NUMBER, 1, 253, 63)->
        position_change(PS_NUMBER, 2, 268, 63)->
        position_change(PS_NUMBER, 3, 288, 63)->
        position_change(PS_NUMBER, 4, 303, 63)->
        position_change(PS_SEMICOLON, 0, 283, 68);

    // miss
    data().
        position_change(PS_MISS, 1, 332, 63)->
        position_change(PS_MISS, 2, 347, 63)->
        position_change(PS_MISS, 3, 361, 63)->
        position_change(PS_MISS, 4, 375, 63)->
        position_change(PS_MISS, 5, 389, 63)->
        position_change(PS_MISS, 6, 333, 77)->
        position_change(PS_MISS, 7, 348, 77)->
        position_change(PS_MISS, 8, 362, 77)->
        position_change(PS_MISS, 9, 375, 77)->
        position_change(PS_MISS, 10, 389, 77);

    // options
    data().
        position_change(PS_GAMEA, 0, 155, 63)->
        position_change(PS_GAMEB, 0, 155, 79)->
        position_change(PS_ALARM, 0, 201, 79)->
        position_change(PS_BELL, 0, 182, 65)->
        position_change(PS_CHRONO, 0, 219, 79)->
        position_change(PS_DATE, 0, 233, 79)->
        position_change(PS_TIME1, 0, 224, 63)->
        position_change(PS_TIME2, 0, 201, 63)->
        position_change(PS_AM, 0, 317, 63)->
        position_change(PS_PM, 0, 317, 78);
}


