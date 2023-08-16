#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
#include "Music.h"

IMPORT_MAP(map);
IMPORT_TILES(font);
DECLARE_MUSIC(synthesizer);

uint8_t collision_tiles[] = {1, 0};

void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 214);
	InitScroll(BANK(map), &map, collision_tiles, 0);

	INIT_FONT(font, PRINT_BKG);
	INIT_CONSOLE(font, 1);
	DPrintf("Level started..");

	PlayMusic(synthesizer, 1);
	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
}

void UPDATE() {
}
