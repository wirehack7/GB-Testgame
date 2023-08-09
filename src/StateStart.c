#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
#include "Keys.h"

IMPORT_MAP(hud);
IMPORT_TILES(font);

void START() {
    INIT_HUD(hud);
    INIT_FONT(font, PRINT_WIN);

    PRINT(6, 2, "TestGame");
    PRINT(4, 5, "Press START!");

	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
}

void UPDATE() {
    if(KEY_PRESSED(J_START)) {
        SetState(StateGame);
    }
}
