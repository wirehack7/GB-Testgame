#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#ifndef NDEBUG
#define NDEBUG
#endif

#include "Print.h"
IMPORT_TILES(font);

IMPORT_MAP(map);

UINT8 collision_tiles[] = {1, 0};

void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);
	InitScroll(BANK(map), &map, collision_tiles, 0);

	#ifdef NDEBUG
	INIT_CONSOLE(font, 3);
	DPrintf("Started!");
	#endif

	NR52_REG = 0x80; //Enables sound, you should always setup this first
	NR51_REG = 0xFF; //Enables all channels (left and right)
	NR50_REG = 0x77; //Max volume
}

void UPDATE() {
}
