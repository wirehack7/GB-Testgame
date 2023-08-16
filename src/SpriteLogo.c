#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "Sound.h"
#include "Sounds.h"

void performantdelay(uint8_t numloops) BANKED;

void START() {
   
}

void UPDATE() {
    // Don't do while() in UPDATE() loop!
    if(THIS->y <= 65) {
        TranslateSprite(THIS, 0, 1 << delta_time);
    }
    if(THIS->y > 65) {
        PlayFx(LOGO);
        performantdelay(100);
        SetState(StateStart);
    }
}

void DESTROY() {
}