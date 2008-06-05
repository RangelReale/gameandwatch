#include "devices/dev_rollerc.h"

GW_Game *GW_Game_RollerC_Info::create()
{
    return new GW_Game_RollerC;
}

GW_Game_RollerC::GW_Game_RollerC() :
    GW_GameEngine_VTech_Condor(EO_NONE, GO_HAVERIGHT6)
{
    gamepath_set("rollerc");
    size_set(609, 377);

    // game screen position
    GW_PLATFORM_RECT(gr, 198, 96, 161, 210);
    gamerect_set(gr);

    // character
    data().
        position_change(PS_CHAR, 1, 202, 261)->
        position_change(PS_CHAR, 2, 257, 259)->
        position_change(PS_CHAR, 3, 300, 264);

    // item
    data().
        position_change(PS_ITEM, 1, 328, 161)->
        position_change(PS_ITEM, 2, 317, 164)->
        position_change(PS_ITEM, 3, 317, 177)->
        position_change(PS_ITEM, 4, 315, 193)->
        position_change(PS_ITEM, 5, 320, 211)->
        position_change(PS_ITEM, 6, 320, 233)->
        position_change(PS_ITEM, 7, 302, 246)->
        position_change(PS_ITEM, 8, 295, 228)->
        position_change(PS_ITEM, 9, 291, 203)->
        position_change(PS_ITEM, 10, 290, 180)->
        position_change(PS_ITEM, 11, 287, 158)->
        position_change(PS_ITEM, 12, 268, 163)->
        position_change(PS_ITEM, 13, 266, 185)->
        position_change(PS_ITEM, 14, 266, 206)->
        position_change(PS_ITEM, 15, 267, 228)->
        position_change(PS_ITEM, 16, 258, 244)->
        position_change(PS_ITEM, 17, 249, 224)->
        position_change(PS_ITEM, 18, 244, 201)->
        position_change(PS_ITEM, 19, 241, 179)->
        position_change(PS_ITEM, 20, 222, 180)->
        position_change(PS_ITEM, 21, 221, 205)->
        position_change(PS_ITEM, 22, 220, 228)->
        position_change(PS_ITEM, 23, 206, 243)->
        position_change(PS_ITEM, 24, 200, 230)->
        position_change(PS_ITEM, 25, 199, 207)->
        position_change(PS_ITEM, 26, 197, 185)->
        position_change(PS_ITEM, 27, 197, 172)->
        position_change(PS_ITEM, IDX_MISS_1, 197, 261)->
        position_change(PS_ITEM, IDX_MISS_2, 239, 262)->
        position_change(PS_ITEM, IDX_MISS_3, 288, 260);

    // item left
    data().
        position_change(PS_ITEMLEFT, 1, 201, 163)->
        position_change(PS_ITEMLEFT, 2, 202, 157);

    // item right
    data().
        position_change(PS_ITEMRIGHT, 1, 333, 172)->
        position_change(PS_ITEMRIGHT, 2, 344, 185)->
        position_change(PS_ITEMRIGHT, 3, 344, 182)->
        position_change(PS_ITEMRIGHT, 4, 342, 162)->
        position_change(PS_ITEMRIGHT, 5, 348, 172)->
        position_change(PS_ITEMRIGHT, 6, 351, 164);


    // numbers
    data().
        position_change(PS_NUMBER, 1, 253, 122)->
        position_change(PS_NUMBER, 2, 273, 122)->
        position_change(PS_NUMBER, 3, 298, 122)->
        position_change(PS_NUMBER, 4, 319, 122)->
        position_change(PS_SEMICOLON, 0, 288, 126);

    // miss
    data().
        position_change(PS_MISS, 1, 339, 100)->
        position_change(PS_MISS, 2, 328, 100)->
        position_change(PS_MISS, 3, 317, 100)->
        position_change(PS_MISS, 4, 306, 100)->
        position_change(PS_MISS, 5, 295, 100)->
        position_change(PS_MISS, 6, 277, 100)->
        position_change(PS_MISS, 7, 266, 100)->
        position_change(PS_MISS, 8, 253, 100)->
        position_change(PS_MISS, 9, 242, 100)->
        position_change(PS_MISS, 10, 231, 100);

    // options
    data().
        position_change(PS_GAMEA, 0, 204, 105)->
        position_change(PS_GAMEB, 0, 216, 105)->
        position_change(PS_ALARM, 0, 208, 142)->
        position_change(PS_BELL, 0, 208, 125)->
        position_change(PS_CHRONO, 0, 228, 142)->
        position_change(PS_DATE, 0, 228, 154)->
        position_change(PS_TIME1, 0, 229, 127)->
        position_change(PS_TIME2, 0, 241, 127)->
        position_change(PS_AM, 0, 335, 121)->
        position_change(PS_PM, 0, 335, 134);
}


