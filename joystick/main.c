#include <genesis.h>
#include "sprite.h"

Sprite *spr2_obj;
int c2 = 1;
s16 x2 = 16;
s16 y2 = 16;
u16 spr2_width = 8;
u16 spr2_height = 8;
Sprite *spr1_obj;
Sprite *parrot_obj;
s16 pr_x = 16;
s16 pr_y = 16;
int pr_c = 1;
int c1 = 1;
s16 x1 = 16;
s16 y1 = 16;
u16 spr1_width = 8;
u16 spr1_height = 8;
u16 health1 = 1;
u16 health2 = 1;
Sprite *mina1;
Sprite *mina2;
u16 mina1_w = 8;
u16 mina1_h = 8;
u16 mina2_w = 8;
u16 mina2_h = 8;
s16 mx1 = 150;
s16 my1 = 210;
s16 mx2 = 114;
s16 my2 = 210;
u16 beh1 = 0;
u16 beh2 = 0;
s16 px1 = 0;
s16 py1 = 215;
u16 pl_w = 320;
u16 pl_h = 215;
u16 floor_x = 0;
u16 floor_y = 0;
u16 floor_w = 320;
u16 floor_h = 0;
u16 woll_x = 0;
u16 woll_y = 0;
u16 woll_w = 0;
u16 woll_h = 240;
Sprite *platforma_obj;
s16 platforma_x = 150;
s16 platforma_y = 50;
Sprite *platforma_obj2;
s16 platforma_x2 = 100;
s16 platforma_y2 = 50;

bool checkColllision(s16 x1, s16 y1, u16 width1, u16 height1, s16 x2, s16 y2, u16 width2, u16 height2)
{
  if (x1 < x2 + width2 &&
      x1 + width1 > x2 &&
      y1 < y2 + height2 &&
      height2 + y1 > y2)
  {
    return TRUE;
  }
  return FALSE;
}

void handleInput()
{
  u16 value = JOY_readJoypad(JOY_1);
  if (value & BUTTON_RIGHT)
  {
    if (health1 > 0)
    {
      x1++;
      SPR_setHFlip(spr1_obj, FALSE);
    }
  }
  if (value & BUTTON_LEFT)
  {
    if (health1 > 0)
    {
      x1--;
      SPR_setHFlip(spr1_obj, TRUE);
    }
  }
  if (value & BUTTON_DOWN)
  {
    if (health1 > 0)
    {
      y1 += 2;
      SPR_setHFlip(spr1_obj, FALSE);
    }
  }
  if (value & BUTTON_UP)
  {
    if (health1 > 0)
    {
      y1 -= 2;
      SPR_setHFlip(spr1_obj, TRUE);
    }
  }
  if (value & BUTTON_A)
  {
    if (health1 > 0)
    {
      c1 = 0;
      SPR_setAnim(spr1_obj, c1);
    }
  }
  if (value & BUTTON_B)
  {
    if (health1 > 0)
    {
      c1 = 1;
      SPR_setAnim(spr1_obj, c1);
    }
  }
  if (value & BUTTON_C)
  {
    if (health1 > 0)
    {
      c1 = 2;
      SPR_setAnim(spr1_obj, c1);
    }
  }
  if (value & BUTTON_X)
  {
    if (health1 > 0)
    {
      c1 = 3;
      SPR_setAnim(spr1_obj, c1);
    }
  }
  if (value & BUTTON_Y)
  {
    if (health1 > 0)
    {
      health2 = 0;
    }
  }
}
void handleInput2()
{
  u16 value = JOY_readJoypad(JOY_2);
  if (value & BUTTON_RIGHT)
  {
    if (health2 > 0)
    {
      x2++;
      SPR_setHFlip(spr2_obj, FALSE);
    }
  }
  if (value & BUTTON_LEFT)
  {
    if (health2 > 0)
    {
      x2--;
      SPR_setHFlip(spr2_obj, TRUE);
    }
  }
  if (value & BUTTON_DOWN)
  {
    if (health2 > 0)
    {
      y2 += 2;
      SPR_setHFlip(spr2_obj, FALSE);
    }
  }
  if (value & BUTTON_UP)
  {
    if (health2 > 0)
    {
      y2 -= 2;
      SPR_setHFlip(spr2_obj, TRUE);
    }
  }
  if (value & BUTTON_A)
  {
    if (health2 > 0)
    {
      c2 = 0;
      SPR_setAnim(spr2_obj, c2);
    }
  }
  if (value & BUTTON_B)
  {
    if (health2 > 0)
    {
      c2 = 1;
      SPR_setAnim(spr2_obj, c2);
    }
  }
  if (value & BUTTON_C)
  {
    if (health2 > 0)
    {
      c2 = 2;
      SPR_setAnim(spr2_obj, c2);
    }
  }
  if (value & BUTTON_X)
  {
    if (health2 > 0)
    {
      c2 = 3;
      SPR_setAnim(spr2_obj, c2);
    }
  }
  if (value & BUTTON_Y)
  {
    if (health2 > 0)
    {
      health1 = 0;
    }
  }
}
void SPR_setVisibility(Sprite* sprite, SpriteVisibility value);

int main()
{
  VDP_drawImage(BG_A, &fonk, 0, 0);
  SPR_init();
  PAL_setPalette(PAL3, spr_spr.palette->data, CPU);
  spr1_obj = SPR_addSprite(&spr_spr, x1, y1, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  spr2_obj = SPR_addSprite(&spr_spr2, x2, y2, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  parrot_obj = SPR_addSprite(&parrot, pr_x, pr_y, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  mina1 = SPR_addSprite(&mina1_spr, mx1, my1, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  mina2 = SPR_addSprite(&mina2_spr, mx2, my2, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  platforma_obj = SPR_addSprite(&paltforma_spr, platforma_x, platforma_y, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  platforma_obj2 = SPR_addSprite(&paltforma_spr2, platforma_x2, platforma_y2, TILE_ATTR(PAL3, 0, FALSE, FALSE));
  SPR_setAnim(spr1_obj, c1);
  SPR_setAnim(spr2_obj, c2);
  SPR_setAnim(mina1, 0);
  SPR_setAnim(mina2, 0);
  SPR_setAnim(platforma_obj, 0);
  SPR_setAnim(platforma_obj2, 0);
  SPR_setAnim(parrot_obj, pr_c);
  while (1)
  {
    handleInput();
    handleInput2();
    if (health1 == 0 && health2 == 0)
    {
      SPR_setVisibility(spr1_obj, HIDDEN);
      SPR_setVisibility(spr2_obj, HIDDEN);
      VDP_drawText("Game Over", 14, 13);
    }
    if (y1 < 220)
    {
      y1 += 1;
    }
    if (y2 < 220)
    {
      y2 += 1;
    }

    if (checkColllision(x1, y1, spr1_width, spr1_height, mx2, my2, mina2_w, mina2_h))
    {
      health1 = 0;
    }
    if (checkColllision(x2, y2, spr2_width, spr2_height, mx1, my1, mina1_w, mina1_h))
    {
      health2 = 0;
    }
    if (checkColllision(px1, py1, pl_w, pl_h, x1, y1, spr1_width, spr1_height))
    {
      y1 -= 1;
    }
    if (checkColllision(px1, py1, pl_w, pl_h, x2, y2, spr2_width, spr2_height))
    {
      y2 -= 1;
    }
    if (checkColllision(floor_x, floor_y, floor_w, floor_h, x1, y1, spr1_width, spr1_height))
    {
      y1 += 1;
    }
    if (checkColllision(floor_x, floor_y, floor_w, floor_h, x2, y2, spr2_width, spr2_height))
    {
      y2 += 1;
    }
    if (checkColllision(x1, y1, spr1_width, spr1_height, 0, 0, 1, 240))
    {
      x1 += 1;
    }
    if (checkColllision(x2, y2, spr2_width, spr2_height, 0, 0, 1, 240))
    {
      x2 += 1;
    }
    if (checkColllision(x1, y1, spr1_width, spr1_height, 320, 0, 1, 240))
    {
      x1 -= 1;
    }
    if (checkColllision(x2, y2, spr2_width, spr2_height, 320, 0, 1, 240))
    {
      x2 -= 1;
    }
    if (checkColllision(150, 42, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      y1 -= 1;
    }
    if (checkColllision(150, 42, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      y2 -= 1;
    }
    if (checkColllision(150, 42, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      x1 -= 1;
    }
    if (checkColllision(150, 42, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      x2 -= 1;
    }
    if (checkColllision(150, 50, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      y1 += 1;
    }
    if (checkColllision(150, 50, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      y2 += 1;
    }
    if (checkColllision(150, 50, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      x1 += 1;
    }
    if (checkColllision(150, 50, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      x2 += 1;
    }
    if (checkColllision(100, 42, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      y1 -= 1;
    }
    if (checkColllision(100, 42, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      y2 -= 1;
    }
    if (checkColllision(100, 42, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      x1 -= 1;
    }
    if (checkColllision(100, 42, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      x2 -= 1;
    }
    if (checkColllision(100, 50, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      y1 += 1;
    }
    if (checkColllision(100, 50, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      y2 += 1;
    }
    if (checkColllision(100, 50, 32, 8, x1, y1, spr1_width, spr1_height))
    {
      x1 += 1;
    }
    if (checkColllision(100, 50, 32, 8, x2, y2, spr2_width, spr2_height))
    {
      x2 += 1;
    }
    if (health2 <= 0)
    {
      c2 = 4;
      SPR_setAnim(spr2_obj, c2);
    }
    if (health1 <= 0)
    {
      c1 = 4;
      SPR_setAnim(spr1_obj, c1);
    }
    SPR_setPosition(spr1_obj, x1, y1);
    SPR_setPosition(spr2_obj, x2, y2);
    SPR_update();
    SYS_doVBlankProcess();
  }
  return 0;
}