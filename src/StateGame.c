#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#include "Print.h"
IMPORT_TILES(font);

IMPORT_MAP(map);

uint8_t collision_tiles[] = {1, 0};

void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 20);
	InitScroll(BANK(map), &map, collision_tiles, 0);

	INIT_CONSOLE(font, 1);
	DPrintf("Level started..");

	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
}

void UPDATE() {
}
