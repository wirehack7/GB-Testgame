#include "Banks/SetAutoBank.h"

#include "gb/gb.h"
#include "rand.h"
#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
#include "Music.h"

#define DEBUGGING

IMPORT_MAP(map);
IMPORT_TILES(font);
DECLARE_MUSIC(synthesizer);

uint8_t collision_tiles[] = {1, 0};

void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 214);
	InitScroll(BANK(map), &map, collision_tiles, 0);

	INIT_FONT(font, PRINT_BKG);
	INIT_CONSOLE(font, 1);

	#ifdef DEBUGGING

	// just fun with randomness
	initrand(DIV_REG);
	uint8_t n, i;
	uint8_t randn;
	n = 20;
	for( i = 0 ; i < n ; i++ ) {
		// get random number between 4 and 15 (add +1 to first integer!)
		randn = rand() % 12 + 4;
		if(randn > 15 && randn < 4) {
			DPrintf("Wrong Number: %i", randn);
			waitpad(J_A | J_B | J_START);
		}
	}
	DPrintf("runs %i - num %i", i, randn);

	#endif
	
	//DPrintf("Level started..");

	PlayMusic(synthesizer, 1);
	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
}

void UPDATE() {
}
