#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Keys.h"
#include "Print.h"

IMPORT_MAP(splash);
IMPORT_TILES(font);

void performantdelay(uint8_t numloops) BANKED; // Just testing banked func here

void START() {
    InitScroll(BANK(splash), &splash, 0, 0);
    INIT_FONT(font, PRINT_BKG);
	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
}

void UPDATE() {
    PRINT(5, 12, "Press START");
    if(KEY_PRESSED(J_START)) {
        UPDATE_KEYS();
        SetState(StateGame);
    }
}
