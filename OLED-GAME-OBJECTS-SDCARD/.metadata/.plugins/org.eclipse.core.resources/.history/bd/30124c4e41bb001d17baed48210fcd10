/*
 * Coin.cpp
 *
 *  Created on: 4 mar 2023
 *      Author: Szymon
 */
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include "Block.h"
#include"Player.h"
#include <Coin.h>
#define true 1
#define false 0


Coin::Coin(int x,int y,int w,int h,const unsigned char* b,int icl){
	pos_x=x;
	pos_y=y;
	width=w;
	height=h;
	bitmap=b;
	is_coin_alive=icl;

}

void Coin::Check(Player &player,int &map){//checking if player(boxi) grab this coin
if(is_coin_alive==true){
	player.generateHIT();
	generateHIT();
	if((player.RHIT>LHIT)&&(player.LHIT<RHIT)&&(player.BHIT==THIT)){
	    player.Player_coins++;
	    map++;
	   is_coin_alive=false;
	}

	if((player.RHIT>=LHIT)&&(((player.THIT>=THIT)&&(player.THIT<=BHIT))||((player.BHIT<=BHIT)&&(player.BHIT>THIT)))&&(player.RHIT<RHIT)){//if player hit left side of coin
	    player.Player_coins++;
	    map++;
	    is_coin_alive=false;
	}

	if((player.LHIT<=RHIT)&&(((player.THIT>=THIT)&&(player.THIT<=BHIT))||((player.BHIT<=BHIT)&&(player.BHIT>THIT)))&&(player.LHIT>LHIT)){// if player hit the right side of coin
	    player.Player_coins++;
	    map++;
	    is_coin_alive=false;

	 }
}
}

void Coin::generateHIT(){ //generates hit box of coin
	LHIT=pos_x;
	RHIT=pos_x+width;
	THIT=pos_y;
	BHIT=pos_y+height;
}

void Coin::Display_Coin(){//if coin is alive can be displayed
	if(is_coin_alive==true){
		ssd1306_DrawBitmap(pos_x, pos_y, bitmap, width, height, White);
	}
}
void Coin::Change_position(int x,int y){//repositioning
	pos_x=x;
	pos_y=y;
}
Coin::~Coin() {
	// TODO Auto-generated destructor stub
}

