/*
 * Player.h
 *
 *  Created on: 25 lut 2023
 *      Author: Szymon
 */
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_

class Player {
public:
int Player_live;
int pos_x,pos_y,width,height;
int LHIT,RHIT,THIT,BHIT;// is for checking if our player hit any block
const unsigned char* bitmap;

/*-------methods-----*/
Player(int x=64,int y=56,int w=8,int h=8,int p_l=3,const unsigned char* b=Bitmap_boxi);
void generateHIT();// generates hit box for player
void Display_Player();//displays player
void Display_Player_hearts();//displays player's hearts (points of live)
virtual ~Player();

 friend void Check(int &b,int &rb,int &lb,Player player);
};

#endif /* INC_PLAYER_H_ */
