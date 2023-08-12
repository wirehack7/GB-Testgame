#include "Banks/SetAutoBank.h"

#include "gb/gb.h"

#include "ZGBMain.h"
#include "Sprite.h"
#include "Keys.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Math.h"
#include "Sound.h"
#include "Sounds.h"
#include "Print.h"

//typedef signed INT8;
//typedef signed INT16;
//ypedef unsigned UINT8;
//typedef unsigned UINT16;

int16_t player_accel_y;
uint16_t player_old_x, player_old_y;
uint8_t moving = 0;

const uint8_t anim_idle[] = {2, 2, 0};
const uint8_t anim_walk[] = {2, 1, 0};
const uint8_t anim_jump[] = {3, 3, 3, 0};

typedef enum {
	PLAYER_STATE_IDLE,
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_JUMPING
} PLAYER_STATE;

PLAYER_STATE player_state;
uint8_t tile_collision;

struct Sprite* player_parent = 0;

void START() {
    player_accel_y = 0;
    scroll_target = THIS;
}

void CheckCollisionTile() {
	switch(tile_collision) {
		//case 25u:
			// SET_BIT(stage_completion, current_stage);
			//SetState(STATE_VICTORY);
			//break;
	}
	player_state = PLAYER_STATE_NORMAL;
}

void Jump(){
	DPrintf("Jumping!             ");
	if(player_state != PLAYER_STATE_JUMPING) {
		PlayFx(FX_JUMP);
		SetSpriteAnim(THIS, anim_jump, 10);
		player_accel_y = -30;
		player_state = PLAYER_STATE_JUMPING;
		player_parent = 0;
	}
}

void UPDATE() {
    if(KEY_PRESSED(J_RIGHT)) {
		DPrintf("Walking!             ");
        TranslateSprite(THIS, 1 << delta_time, 0);
        THIS->mirror = NO_MIRROR;
		SetSpriteAnim(THIS, anim_walk, 15);
		//PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
    } 
	if(KEY_PRESSED(J_LEFT)) {
		DPrintf("Walking!             ");
        TranslateSprite(THIS, -1 << delta_time, 0);
        THIS->mirror = V_MIRROR;
		SetSpriteAnim(THIS, anim_walk, 15);
		//PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
    }

	if(KEY_PRESSED(J_B)) {
		Jump();
	}

	if(KEY_PRESSED(J_START)) {
		DPrintf("Paused!         ");
		print_target = PRINT_BKG;
		// TODO: how to remove this after unpause??? might use WINDOW for this (aka HUD)
		PRINT(0, 0, "        PAUSED       ");
		HIDE_SPRITES;
		waitpadup();
		waitpad(J_A | J_B | J_START);
		waitpadup();
		UPDATE_KEYS();
		SHOW_SPRITES;
	}

	if(keys == 0) {
		DPrintf("Idling!             ");
		SetSpriteAnim(THIS, anim_idle, 3);
	}

    if(player_parent == 0) {
		if(player_accel_y < 60) {
			player_accel_y += 2;
		}
		tile_collision = TranslateSprite(THIS, 0, (player_accel_y >> 4));
		if(!tile_collision && delta_time != 0 && player_accel_y < 40) {
			player_accel_y += 2;
			tile_collision = TranslateSprite(THIS, 0, (player_accel_y >> 4));
		}
		if(tile_collision) {
			 CheckCollisionTile();
		}
	}
}

void DESTROY() {
}