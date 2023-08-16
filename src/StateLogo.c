#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "SpriteManager.h"
#include "Scroll.h"
#include "Print.h"

void performantdelay(uint8_t numloops) BANKED {
    uint8_t ii;
    for(ii = 0; ii < numloops; ii++){
        wait_vbl_done();
    }     
}

void START() {
    scroll_target = SpriteManagerAdd(SpriteLogo, 38, 0);
}

void UPDATE() {
    //performantdelay(200);
    //SetState(StateStart);
}
