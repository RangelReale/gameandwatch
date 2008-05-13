#include "devices/dev_pirate.h"

GW_Game *GW_Game_Pirate_Info::create()
{
    return new GW_Game_Pirate;
}


GW_Game_Pirate::GW_Game_Pirate() : GW_GameEngine_VTech_Monkey(false)
{
    gamepath_set("pirate");

    // size and gamerect are the same as "MONKEY"

    // character
    data().
        position_change(PS_CHAR_1, 1, 205, 91)->
        position_change(PS_CHAR_1, 2, 199, 82)->
        position_change(PS_CHAR_1, 3, 186, 95);
    data().
        position_change(PS_CHAR_2, 1, 258, 95)->
        position_change(PS_CHAR_2, 2, 266, 89)->
        position_change(PS_CHAR_2, 3, 273, 109);
    data().
        position_change(PS_CHAR_3, 1, 325, 111)->
        position_change(PS_CHAR_3, 2, 333, 105)->
        position_change(PS_CHAR_3, 3, 340, 123);

    // item
    data().
        position_change(PS_ITEM_1, 1, 201, 224)->
        position_change(PS_ITEM_1, 2, 170, 215)->
        position_change(PS_ITEM_1, 3, 170, 184)->
        position_change(PS_ITEM_1, 4, 179, 150)->
        position_change(PS_ITEM_1, 5, 178, 127)->
        position_change(PS_ITEM_1, IDX_GOT, 196, 188)->
        position_change(PS_ITEM_1, IDX_MISS, 211, 139)->
        position_change(PS_ITEM_1, IDX_HIT, 178, 127); // same image as 5
    data().
        position_change(PS_ITEM_2, 1, 269, 202)->
        position_change(PS_ITEM_2, 2, 293, 202)->
        position_change(PS_ITEM_2, 3, 291, 174)->
        position_change(PS_ITEM_2, 4, 289, 143)->
        position_change(PS_ITEM_2, 5, 290, 114)->
        position_change(PS_ITEM_2, IDX_GOT, 252, 172)->
        position_change(PS_ITEM_2, IDX_MISS, 263, 134)->
        position_change(PS_ITEM_2, IDX_HIT, 290, 114); // same image as 5
    data().
        position_change(PS_ITEM_3, 1, 338, 217)->
        position_change(PS_ITEM_3, 2, 359, 213)->
        position_change(PS_ITEM_3, 3, 366, 186)->
        position_change(PS_ITEM_3, 4, 365, 161)->
        position_change(PS_ITEM_3, 5, 353, 132)->
        position_change(PS_ITEM_3, IDX_GOT, 331, 185)->
        position_change(PS_ITEM_3, IDX_MISS, 327, 150)->
        position_change(PS_ITEM_3, IDX_HIT, 353, 132);

    // numbers
    data().
        position_change(PS_NUMBER, 1, 252, 53)->
        position_change(PS_NUMBER, 2, 267, 53)->
        position_change(PS_NUMBER, 3, 287, 53)->
        position_change(PS_NUMBER, 4, 302, 53)->
        position_change(PS_SEMICOLON, 0, 282, 58);


    // miss
    data().
        position_change(PS_MISS, 1, 336, 52)->
        position_change(PS_MISS, 2, 350, 52)->
        position_change(PS_MISS, 3, 363, 52)->
        position_change(PS_MISS, 4, 376, 52)->
        position_change(PS_MISS, 5, 389, 52)->
        position_change(PS_MISS, 6, 337, 72)->
        position_change(PS_MISS, 7, 350, 73)->
        position_change(PS_MISS, 8, 364, 72)->
        position_change(PS_MISS, 9, 377, 73)->
        position_change(PS_MISS, 10, 390, 72);

    // options
    data().
        position_change(PS_GAMEA, 0, 159, 53)->
        position_change(PS_GAMEB, 0, 159, 68)->
        position_change(PS_ALARM, 0, 202, 69)->
        position_change(PS_BELL, 0, 185, 55)->
        position_change(PS_CHRONO, 0, 219, 69)->
        position_change(PS_DATE, 0, 233, 69)->
        position_change(PS_TIME1, 0, 225, 53)->
        position_change(PS_TIME2, 0, 202, 53)->
        position_change(PS_AM, 0, 320, 53)->
        position_change(PS_PM, 0, 320, 68);

}
