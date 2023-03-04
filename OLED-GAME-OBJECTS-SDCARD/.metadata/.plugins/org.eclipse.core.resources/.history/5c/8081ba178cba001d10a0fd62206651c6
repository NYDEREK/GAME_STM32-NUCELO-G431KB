/*
 * Player.cpp
 *
 *  Created on: 25 lut 2023
 *      Author: Szymon
 */
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include <Player.h>

Player::Player(int x,int y,int w,int h,int p_l,const unsigned char* b) {//setting values and generating hit box
	pos_x=x;
	pos_y=y;
	width=w;
	height=h;
	bitmap=b;
    Player_live=p_l;
	generateHIT();
}
void Player::Display_Player(){ //drawing the player

	ssd1306_DrawBitmap(pos_x, pos_y, bitmap,width, height, White);

}
void Player::Display_Player_hearts(){//drawing player's hearts

	if(Player_live==3){//if player has all lives
		ssd1306_DrawBitmap(121,0, Bitmap_heart, 5, 5, White);//displaying 5x5 bitmap of one heart
		ssd1306_DrawBitmap(116,0, Bitmap_heart, 5, 5, White);//displaying 5x5 bitmap of one heart
		ssd1306_DrawBitmap(111,0, Bitmap_heart, 5, 5, White);//displaying 5x5 bitmap of one heart
	}
	if(Player_live==2){//if player lose one heart
		ssd1306_DrawBitmap(121,0, Bitmap_heart, 5, 5, White);//displaying 5x5 bitmap of one heart
		ssd1306_DrawBitmap(116,0, Bitmap_heart, 5, 5, White);//displaying 5x5 bitmap of one heart
	}
	if(Player_live==1){//if player lose two hearts
		ssd1306_DrawBitmap(121,0, Bitmap_heart, 5, 5, White);//displaying 5x5 bitmap of one heart

	}

}
void Player::generateHIT(){ //generating hit box
	LHIT=pos_x;
	RHIT=pos_x+width;
	THIT=pos_y;
	BHIT=pos_y+height;
}
Player::~Player() {
	// TODO Auto-generated destructor stub
}

