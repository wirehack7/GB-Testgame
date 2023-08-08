#include "Banks/SetAutoBank.h"

#include "gb/gb.h"

#include "ZGBMain.h"
#include "Sprite.h"
#include "Keys.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Math.h"
#include "Sound.h"

//typedef signed INT8;
//typedef signed INT16;
//ypedef unsigned UINT8;
//typedef unsigned UINT16;

INT16 player_accel_y;
UINT16 player_old_x, player_old_y;
UINT8 moving = 0;

typedef enum {
	PLAYER_STATE_IDLE,
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_JUMPING
}PLAYER_STATE;

PLAYER_STATE player_state;
UINT8 tile_collision;

struct Sprite* player_parent = 0;

void START() {
    player_accel_y = 0;
    scroll_target = THIS;
}

void CheckCollisionTile() {
	switch(tile_collision) {
		case 25u:
			// SET_BIT(stage_completion, current_stage);
			//SetState(STATE_VICTORY);
			break;
	}
}

void MovePlayer(){
	if(KEY_PRESSED(J_LEFT)){
	//	tile_collision = TranslateSprite(THIS, -1, 0);
		tile_collision = TranslateSprite(THIS, -1 << delta_time, 0);
	}
	else if(KEY_PRESSED(J_RIGHT)){
	//	tile_collision = TranslateSprite(THIS, 1, 0);
		tile_collision = TranslateSprite(THIS, 1 << delta_time, 0);
	}
}

void Jump(){
	if(player_state != PLAYER_STATE_JUMPING) {
		player_accel_y = -50;
		player_state = PLAYER_STATE_JUMPING;
		player_parent = 0;
	}
}

void UPDATE() {
    if(KEY_PRESSED(J_RIGHT)) {
        TranslateSprite(THIS, 1 << delta_time, 0);
        THIS->mirror = NO_MIRROR;
		PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
    } else if(KEY_PRESSED(J_LEFT)) {
        TranslateSprite(THIS, -1 << delta_time, 0);
        THIS->mirror = V_MIRROR;
		PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
    }

    if(player_parent == 0) {
		if(player_accel_y < 60) {
			player_accel_y += 2;
		}
		tile_collision = TranslateSprite(THIS, 0, (player_accel_y >> 4));
		if(!tile_collision && delta_time != 0 && player_accel_y < 40) { //Do another iteration if there is no collision
			player_accel_y += 2;
			tile_collision = TranslateSprite(THIS, 0, (player_accel_y >> 4));
		}
		if(tile_collision) {
			if(tile_collision != 3u && tile_collision != 4u) {
				player_accel_y = 0;
				if(player_state == PLAYER_STATE_JUMPING) {
					player_state = PLAYER_STATE_NORMAL;
				}
			}

			 CheckCollisionTile();
		}
	}


}

void DESTROY() {
}