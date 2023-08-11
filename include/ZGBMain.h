#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateLogo)\
_STATE(StateStart)\
_STATE(StateGame)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteLogo, logo)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif