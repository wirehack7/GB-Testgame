#include "Banks/SetAutoBank.h"

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Sprite.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Math.h"
#include "Sound.h"
#include "Sounds.h"
#include "Print.h"
#include "Palette.h"
#include "Vector.h"

void START() {

}

void UPDATE() {
    TranslateSprite(THIS, 0, 1 << delta_time);

}

void DESTROY() {
}