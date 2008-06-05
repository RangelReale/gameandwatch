#include "devices/deveng_vtech_condor.h"

GW_GameEngine_VTech_Condor::GW_GameEngine_VTech_Condor(int engineoptions, int options) :
    GW_GameEngine_VTech(engineoptions), options_(options)
{
    // "CONDOR" is default

    gamepath_set("condor");
    size_set(562, 373);

    // game screen position
    GW_PLATFORM_RECT(gr, 151, 52, 257, 192);
    gamerect_set(gr);

    // transparent colors
    GW_PLATFORM_RGB(tcolor_bg, 255, 0, 255);
    GW_PLATFORM_RGB(tcolor_img, 255, 255, 255);

    // character
    data().
        position_add(PS_CHAR, 1, 206, 200, IM_CHAR, 1, "char_1.bmp", &tcolor_img)->
        position_add(PS_CHAR, 2, 250, 200, IM_CHAR, 2, "char_2.bmp", &tcolor_img)->
        position_add(PS_CHAR, 3, 315, 203, IM_CHAR, 3, "char_3.bmp", &tcolor_img);

    // item
    if ((options_&GO_HAVEITEM0)==GO_HAVEITEM0)
        data().
            position_add(PS_ITEM, 0, 352, 93, IM_ITEM, 0, "item_00.bmp", &tcolor_img);

    data().
        position_add(PS_ITEM, 1, 345, 107, IM_ITEM, 1, "item_01.bmp", &tcolor_img)->
        position_add(PS_ITEM, 2, 342, 118, IM_ITEM, 2, "item_02.bmp", &tcolor_img)->
        position_add(PS_ITEM, 3, 342, 131, IM_ITEM, 3, "item_03.bmp", &tcolor_img)->
        position_add(PS_ITEM, 4, 342, 146, IM_ITEM, 4, "item_04.bmp", &tcolor_img)->
        position_add(PS_ITEM, 5, 341, 153, IM_ITEM, 5, "item_05.bmp", &tcolor_img)->
        position_add(PS_ITEM, 6, 337, 165, IM_ITEM, 6, "item_06.bmp", &tcolor_img)->
        position_add(PS_ITEM, 7, 335, 182, IM_ITEM, 7, "item_07.bmp", &tcolor_img)->
        position_add(PS_ITEM, 8, 318, 166, IM_ITEM, 8, "item_08.bmp", &tcolor_img)->
        position_add(PS_ITEM, 9, 307, 135, IM_ITEM, 9, "item_09.bmp", &tcolor_img)->
        position_add(PS_ITEM, 10, 297, 119, IM_ITEM, 10, "item_10.bmp", &tcolor_img)->
        position_add(PS_ITEM, 11, 295, 100, IM_ITEM, 11, "item_11.bmp", &tcolor_img)->
        position_add(PS_ITEM, 12, 277, 88, IM_ITEM, 12, "item_12.bmp", &tcolor_img)->
        position_add(PS_ITEM, 13, 274, 111, IM_ITEM, 13, "item_13.bmp", &tcolor_img)->
        position_add(PS_ITEM, 14, 272, 127, IM_ITEM, 14, "item_14.bmp", &tcolor_img)->
        position_add(PS_ITEM, 15, 275, 143, IM_ITEM, 15, "item_15.bmp", &tcolor_img)->
        position_add(PS_ITEM, 16, 278, 159, IM_ITEM, 16, "item_16.bmp", &tcolor_img)->
        position_add(PS_ITEM, 17, 255, 170, IM_ITEM, 17, "item_17.bmp", &tcolor_img)->
        position_add(PS_ITEM, 18, 246, 142, IM_ITEM, 18, "item_18.bmp", &tcolor_img)->
        position_add(PS_ITEM, 19, 240, 114, IM_ITEM, 19, "item_19.bmp", &tcolor_img)->
        position_add(PS_ITEM, 20, 225, 100, IM_ITEM, 20, "item_20.bmp", &tcolor_img)->
        position_add(PS_ITEM, 21, 222, 133, IM_ITEM, 21, "item_21.bmp", &tcolor_img)->
        position_add(PS_ITEM, 22, 217, 146, IM_ITEM, 22, "item_22.bmp", &tcolor_img)->
        position_add(PS_ITEM, 23, 220, 168, IM_ITEM, 23, "item_23.bmp", &tcolor_img)->
        position_add(PS_ITEM, 24, 198, 171, IM_ITEM, 24, "item_24.bmp", &tcolor_img)->
        position_add(PS_ITEM, 25, 194, 145, IM_ITEM, 25, "item_25.bmp", &tcolor_img)->
        position_add(PS_ITEM, 26, 196, 121, IM_ITEM, 26, "item_26.bmp", &tcolor_img)->
        position_add(PS_ITEM, 27, 188, 102, IM_ITEM, 27, "item_27.bmp", &tcolor_img)->
        position_add(PS_ITEM, IDX_MISS_1, 167, 191, IM_ITEM, IDX_MISS_1, "miss_1.bmp", &tcolor_img)->
        position_add(PS_ITEM, IDX_MISS_2, 277, 186, IM_ITEM, IDX_MISS_2, "miss_2.bmp", &tcolor_img)->
        position_add(PS_ITEM, IDX_MISS_3, 354, 189, IM_ITEM, IDX_MISS_3, "miss_3.bmp", &tcolor_img);

    // item left
    if ((options_&GO_HAVELEFT0)==GO_HAVELEFT0)
        data().
            position_add(PS_ITEMLEFT, 0, 210, 221, IM_ITEMLEFT, 0, "item_left_0.bmp", &tcolor_img);
    data().
        position_add(PS_ITEMLEFT, 1, 158, 144, IM_ITEMLEFT, 1, "item_left_1.bmp", &tcolor_img)->
        position_add(PS_ITEMLEFT, 2, 159, 94, IM_ITEMLEFT, 2, "item_left_2.bmp", &tcolor_img);

    // item right
    if ((options_&GO_HAVERIGHT1A)==GO_HAVERIGHT1A)
    {
        data().
            position_add(PS_ITEMRIGHT, 1, 210, 221, IM_ITEMRIGHT, 1, "item_right_1a.bmp", &tcolor_img)->
            position_add(PS_ITEMRIGHT, IDX_RIGTH_1B, 210, 221, IM_ITEMRIGHT, IDX_RIGTH_1B, "item_right_1b.bmp", &tcolor_img);
    }
    else
        data().
            position_add(PS_ITEMRIGHT, 1, 374, 117, IM_ITEMRIGHT, 1, "item_right_1.bmp", &tcolor_img);

    data().
        position_add(PS_ITEMRIGHT, 2, 389, 106, IM_ITEMRIGHT, 2, "item_right_2.bmp", &tcolor_img)->
        position_add(PS_ITEMRIGHT, 3, 384, 105, IM_ITEMRIGHT, 3, "item_right_3.bmp", &tcolor_img)->
        position_add(PS_ITEMRIGHT, 4, 375, 106, IM_ITEMRIGHT, 4, "item_right_4.bmp", &tcolor_img);

    if ((options_&GO_HAVERIGHT6)==GO_HAVERIGHT6)
        data().
            position_add(PS_ITEMRIGHT, 5, 210, 221, IM_ITEMRIGHT, 5, "item_right_5.bmp", &tcolor_img)->
            position_add(PS_ITEMRIGHT, 6, 210, 221, IM_ITEMRIGHT, 6, "item_right_6.bmp", &tcolor_img);


    // numbers
    data().
        position_change(PS_NUMBER, 1, 248, 54)->
        position_change(PS_NUMBER, 2, 263, 54)->
        position_change(PS_NUMBER, 3, 283, 54)->
        position_change(PS_NUMBER, 4, 298, 54)->
        position_change(PS_SEMICOLON, 0, 278, 59);

    // miss
    data().
        position_change(PS_MISS, 1, 336, 51)->
        position_change(PS_MISS, 2, 349, 51)->
        position_change(PS_MISS, 3, 362, 51)->
        position_change(PS_MISS, 4, 375, 51)->
        position_change(PS_MISS, 5, 388, 51)->
        position_change(PS_MISS, 6, 336, 67)->
        position_change(PS_MISS, 7, 349, 67)->
        position_change(PS_MISS, 8, 362, 67)->
        position_change(PS_MISS, 9, 375, 67)->
        position_change(PS_MISS, 10, 388, 67);

    // options
    data().
        position_change(PS_GAMEA, 0, 158, 54)->
        position_change(PS_GAMEB, 0, 158, 70)->
        position_change(PS_ALARM, 0, 200, 70)->
        position_change(PS_BELL, 0, 184, 56)->
        position_change(PS_CHRONO, 0, 218, 70)->
        position_change(PS_DATE, 0, 231, 70)->
        position_change(PS_TIME1, 0, 224, 54)->
        position_change(PS_TIME2, 0, 201, 54)->
        position_change(PS_AM, 0, 318, 54)->
        position_change(PS_PM, 0, 318, 69);


    // timers
    data().
        timer_add(TMR_GAMEOVER, 120, false)->
        timer_add(TMR_GAMEOVER, 2000, false)->
        timer_add(TMR_REPRISE, 800, false);
}

void GW_GameEngine_VTech_Condor::Event(GW_Platform_Event *event)
{
    GW_GameEngine_VTech::Event(event);

    if (event->id==GPE_KEYDOWN)
    {
        switch (event->data)
        {
        case GPK_LEFT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_position_-=1;
                if (char_position_<1) char_position_=1;
                char_update(char_position_);
            }
            break;
        case GPK_RIGHT:
            if ((GetMode()==MODE_GAMEA || GetMode()==MODE_GAMEB) && canmove_get())
            {
                char_position_+=1;
                if (char_position_>3) char_position_=3;
                char_update(char_position_);
            }
            break;
        }
    }
}

void GW_GameEngine_VTech_Condor::do_timer(int timerid)
{
    GW_GameEngine_VTech::do_timer(timerid);
}

void GW_GameEngine_VTech_Condor::game_start(int mode)
{
    char_position_=3; // right
    items_left_=1;

    tick_=6;

    char_update(char_position_);
    items_left_update(items_left_);
    items_right_update(0);
}

void GW_GameEngine_VTech_Condor::game_tick()
{
    // main game action
    int i, iOnscreen, iMistake, iGot, iMoved;

    // animates items on rightmost part of the screen
    items_right_update(tick_);

    // puts item on left to the "normal" status
    items_left_=1; items_left_update(items_left_);

    // various initialization (for later use within this procedure)
    iMistake=0;
    iGot=0;
    iMoved=0;

    // checks for mistakes
    if (data().position_get(PS_ITEM, 23)->status_get()==1 && char_position_!=1) { data().position_get(PS_ITEM, 23)->show_status(3); iMistake=1; }
    if (data().position_get(PS_ITEM, 16)->status_get()==1 && char_position_!=2) { data().position_get(PS_ITEM, 16)->show_status(3); iMistake=2; }
    if (data().position_get(PS_ITEM, 7)->status_get()==1 && char_position_!=3) { data().position_get(PS_ITEM, 7)->show_status(3); iMistake=3; }

    // checks for collisions character-items in certain positions
    if (iMistake==0)
    {
        if (data().position_get(PS_ITEM, 23)->status_get()==1 && char_position_==1) { data().position_get(PS_ITEM, 23)->show_status(2); iGot=1; }
        if (data().position_get(PS_ITEM, 16)->status_get()==1 && char_position_==2) { data().position_get(PS_ITEM, 16)->show_status(2); iGot=2; }
        if (data().position_get(PS_ITEM, 7)->status_get()==1 && char_position_==3) { data().position_get(PS_ITEM, 7)->show_status(2); iGot=3; }
    }

    // moves and generates items
    if (iMistake==0)
    {
      // columns 1 (leftmost) and 4 (rightmost)
      if (tick_==1 || tick_==4)
      {
          // checks for items on position 27, to increase score & sets current level
          if (data().position_get(PS_ITEM, 27)->status_get()==1)
          {
              score_add();
              items_left_=2; items_left_update(items_left_);
          }

          // moves items on column 1 (leftmost)
          if (data().position_get(PS_ITEM, 23)->status_get()==2) data().position_get(PS_ITEM, 23)->show_status(1);
          for (i=27; i>=24; i--) data().position_get(PS_ITEM, i)->visible_status(data().position_get(PS_ITEM, i-1));
          data().position_get(PS_ITEM, 23)->hide_status(0);

          // moves items on column 4 (rightmost)
          for (i=7; i>=1; i--) data().position_get(PS_ITEM, i)->visible_status(data().position_get(PS_ITEM, i-1));
          if ((options_&GO_HAVEITEM0)==GO_HAVEITEM0)
            if (tick_==1) data().position_get(PS_ITEM, 0)->hide_status(0);

          // checks for collisions character-items
          if (data().position_get(PS_ITEM, 7)->status_get()==1 && char_position_==3) { data().position_get(PS_ITEM, 7)->show_status(2); iGot=3; }

          // generates new items when iLoop=4
          if (tick_==4)
          {
              iOnscreen=0;
              for (i=0; i<=27; i++)
                if (data().position_get(PS_ITEM, i)->visible_get()) iOnscreen++;       // counts items on screen
              if (rand() % 4==0) data().position_get(PS_ITEM, 0)->show_status(1); else data().position_get(PS_ITEM, 0)->hide_status(0);                   // generates new item randomly
              if (iOnscreen==0) data().position_get(PS_ITEM, 0)->show_status(1);          // forces new item generation if none on screen
              if (iOnscreen>=maxonscreen_) data().position_get(PS_ITEM, 0)->hide_status(0);;                             // prevents new item from being generated if more onscreen items than allowed
          }

          // gets ready to play "pfMove" sound
          for (i=0; i<=7; i++) if (data().position_get(PS_ITEM, i)->status_get()==1) iMoved++;
          for (i=24; i<=27; i++) if (data().position_get(PS_ITEM, i)->status_get()==1) iMoved++;
      }

      // column 2 (left-of-middle)
      if (tick_==2 || tick_==5)
      {
          // moves items on column 2 (left-of-middle)
          if (data().position_get(PS_ITEM, 16)->status_get()==2) data().position_get(PS_ITEM, 16)->show_status(1);
          for (i=23; i>=17; i--) data().position_get(PS_ITEM, i)->visible_status(data().position_get(PS_ITEM, i-1));
          data().position_get(PS_ITEM, 16)->hide_status(0);

          // checks for collisions character-items
          if (data().position_get(PS_ITEM, 23)->status_get()==1 && char_position_==1) { data().position_get(PS_ITEM, 23)->show_status(2); iGot=1; }

          // gets ready to play "pfMove" sound
          for (i=17; i<=23; i++) if (data().position_get(PS_ITEM, i)->status_get()==1) iMoved++;
      }

      // column 3 (right-of-middle)
      if (tick_==3 || tick_==6)
      {
          // moves items on column 3 (right-of-middle)
          if (data().position_get(PS_ITEM, 7)->status_get()==2) data().position_get(PS_ITEM, 7)->show_status(1);
          for (i=16; i>=8; i--) data().position_get(PS_ITEM, i)->visible_status(data().position_get(PS_ITEM, i-1));
          data().position_get(PS_ITEM, 7)->hide_status(0);

          // checks for collisions character-items
          if (data().position_get(PS_ITEM, 16)->status_get()==1 && char_position_==2) { data().position_get(PS_ITEM, 16)->show_status(2); iGot=2; }

          // gets ready to play "pfMove" sound
          for (i=8; i<=16; i++) if (data().position_get(PS_ITEM, i)->status_get()==1) iMoved++;
      }
    }

  // executes miss routine, counts misses and reprises or goes to "game over"
  if (iMistake!=0)
  {
      canmove_set(false);
      data_stopalltimers();

      switch (iMistake)
      {
        case 1: { data().position_get(PS_ITEM, 23)->hide_status(0); data().position_get(PS_ITEM, IDX_MISS_1)->show(); } break;
        case 2: { data().position_get(PS_ITEM, 16)->hide_status(0); data().position_get(PS_ITEM, IDX_MISS_2)->show(); } break;
        case 3: { data().position_get(PS_ITEM, 7)->hide_status(0); data().position_get(PS_ITEM, IDX_MISS_3)->show(); } break;
      }
      misses_add();
      if (misses_get()<5)
      {                                                         // checks how many misses were done
          // game continues if misses<5
          data_starttimer(TMR_REPRISE);
      }
      else
      {
          // game is over if misses=5
          tick_=0; // becomes 1 before the end of this procedure
          data_starttimer(TMR_GAMEOVER);
      }
  }

  // renders items on screen
  //for i:=0 to 27 do if aItems[i]>0 then aimItems[i].visible:=true else aimItems[i].visible:=false;

  // plays correct sound (miss

    if (iMistake>0)
        data_playsound(SND_MISS);
    else if (iGot>0)
        data_playsound(SND_GOT);
    else if (iMoved>0)
        data_playsound(SND_MOVE);

    // loops action
    tick_++;
    if (tick_>6) tick_=1;
}

void GW_GameEngine_VTech_Condor::game_reprise()
{
    showall_miss(false);
}

void GW_GameEngine_VTech_Condor::char_update(int pos)
{
    for (int i=1; i<=3; i++)
    {
        data().position_get(PS_CHAR, i)->visible_set(i==pos);
    }
}

void GW_GameEngine_VTech_Condor::items_left_update(int pos)
{
    int min=1, max=2;
    for (int i=min; i<=max; i++)
        data().position_get(PS_ITEMLEFT, i)->visible_set(i==pos);
}

void GW_GameEngine_VTech_Condor::items_right_update(int pos)
{
/*
 shows animated items on the right of screen. frame '0' is used when game
 begins, then is never used anymore. frames '1'='2' and '4'='5' in order to
 have 6 frames looping, with '1' and '4' lasting double the times than others
*/
  bool ir[5] = {false, false, false, false, false};

  switch (pos)
  {
    case 0: { ir[1]=true; ir[2]=false; ir[3]=true; ir[4]=true; } break;
    case 1: { ir[1]=true; ir[2]=true;  ir[3]=false; ir[4]=true; } break;
    case 2: { ir[1]=true; ir[2]=true;  ir[3]=false; ir[4]=true; } break;
    case 3: { ir[1]=true; ir[2]=false; ir[3]=true;  ir[4]=false; } break;
    case 4: { ir[1]=true; ir[2]=false; ir[3]=true;  ir[4]=false; } break;
    case 5: { ir[1]=true; ir[2]=false; ir[3]=true;  ir[4]=false; } break;
    case 6: { ir[1]=true; ir[2]=true;  ir[3]=false; ir[4]=false; } break;
  }
    int min=1, max=4;
    for (int i=min; i<=max; i++)
        data().position_get(PS_ITEMRIGHT, i)->visible_set(ir[i]);
}

void GW_GameEngine_VTech_Condor::showall_miss(bool b)
{
    for (int i=IDX_MISS_1; i<=IDX_MISS_3; i++)
        data().position_get(PS_ITEM, i)->visible_set(b);
}

void GW_GameEngine_VTech_Condor::level_update(int mode)
{
    if (mode==-1) mode=GetMode();
    int i=score_get();
    while (i>199) i-=200;
    switch (mode)
    {
    case MODE_GAMEA:
         // maximum moveable items on screen
         if (i>=0 && i<4) maxonscreen_=1;
         else if (i>=4 && i<30)  maxonscreen_=3;
         else if (i>=30 && i<100) maxonscreen_=5;
         // game speed
         if (i>=0 && i<40) data().timer_get(TMR_GAME)->time_set(215);
         else if (i>=40 && i<70) data().timer_get(TMR_GAME)->time_set(185);
         if (i>=70 && i<100) data().timer_get(TMR_GAME)->time_set(150);
        break;
    case MODE_GAMEB:
         // maximum moveable items on screen
         if (i>=0 && i<4) maxonscreen_=1;
         else if (i>=4 && i<24) maxonscreen_=4;
         else if (i>=24 && i<100) maxonscreen_=6;
         // game speed
         if (i>=0 && i<40) data().timer_get(TMR_GAME)->time_set(180);
         else if (i>=40 && i<70) data().timer_get(TMR_GAME)->time_set(155);
         else if (i>=70 && i<100) data().timer_get(TMR_GAME)->time_set(130);
        break;
    default:
        break;
    }
}

