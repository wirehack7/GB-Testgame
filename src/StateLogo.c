#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "SpriteManager.h"
#include "Scroll.h"
#include "Print.h"

// defining BANKED func here 
void performantdelay(uint8_t numloops) BANKED {
    uint8_t ii;
    for(ii = 0; ii < numloops; ii++){
        wait_vbl_done();
    }     
}

IMPORT_TILES(font);

void START() {
    SpriteManagerAdd(SpriteLogo, 38, 70);
    INIT_CONSOLE(font, 1);
	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
}

void UPDATE() {
    performantdelay(200);
    SetState(StateStart);
}
