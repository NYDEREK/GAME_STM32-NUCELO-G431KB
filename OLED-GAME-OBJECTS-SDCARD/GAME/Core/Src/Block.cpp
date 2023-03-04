/*
 * Block.cpp
 *
 *  Created on: 25 lut 2023
 *      Author: Szymon
 */
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include "Block.h"
#include"Player.h"
#define true 1
#define false 0

Block::Block(int x, int y,int w,int h,const unsigned char* b,int ml,int mr) {//writing primary data to spike object
	pos_x=x;
	pos_y=y;
	width=w;
	height=h;
    bitmap=b;
    moveL=ml;
    moveR=mr;
}
void Block::generateHIT(){ // it generates the hit box for this block
	LHIT=pos_x;
	RHIT=pos_x+width;
	THIT=pos_y;
	BHIT=pos_y+height;
}
void Block::Display_Block(){
	ssd1306_DrawBitmap(pos_x, pos_y, bitmap, width, height, White);

}

void Block::Check(int &barrier,Player &player){ // it checks if player hit this block (int b is int barrier for gravitation function)
player.generateHIT();
generateHIT();
if((player.RHIT>LHIT)&&(player.LHIT<RHIT)&&(player.BHIT==THIT)){
barrier=1; //function turn of our gravitation so we do not fall of this block {is barrier for gravitation)
}

if((player.RHIT>=LHIT)&&(((player.THIT>=THIT)&&(player.THIT<=BHIT))||((player.BHIT<=BHIT)&&(player.BHIT>THIT)))&&(player.RHIT<RHIT)){//if player hit left side of block
  player.pos_x--;

  if(is_block_moving==true){//because of this "if" moving block can move the moving player
  player.pos_x--;
  }

}

if((player.LHIT<=RHIT)&&(((player.THIT>=THIT)&&(player.THIT<=BHIT))||((player.BHIT<=BHIT)&&(player.BHIT>THIT)))&&(player.LHIT>LHIT)){// if player hit the right side of block
 player.pos_x++;

 if(is_block_moving==true){//because of this "if" moving block can move the moving player
 player.pos_x++;
 }

 }
//TODO write function for hiting bottom of block
}

void Block:: Move_Block(int point_A,int point_B,int &barrier,Player &player){
    is_block_moving=true;
	if(moveR==true){   //moving the block form point A to point B
	   pos_x++;
	  }
	if(moveL==true){   //moving the block form point B to point A
	   pos_x--;
	  }
	if(pos_x==point_A){//check if block hit the point_A
	   moveL=false;
	   moveR=true;
	  }
	if(RHIT==point_B){//check if block hit the ponit_B
	   moveL=true;
	   moveR=false;
 }
	//----moving character-----// /*<-- the player can ride on block (be on him and move with him without doing anything)*/
	player.generateHIT();
	generateHIT();
	if((player.RHIT>LHIT)&&(player.LHIT<RHIT)&&(player.BHIT==THIT)){
	barrier=1;  //function turn of our gravitation so we do not fall of this block {is barrier for gravitation)
	if(moveR==true){
		player.pos_x++;
	}
	if(moveL==true){
	    player.pos_x--;
	}
  }
}
void Block::Change_position(int x,int y){
	pos_x=x;
	pos_y=y;
}
Block::~Block() {
	// TODO Auto-generated destructor stub
}

