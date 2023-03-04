/*
 * Mob.cpp
 *
 *  Created on: 2 mar 2023
 *      Author: Szymon
 */
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include <Player.h>
#include <Mob.h>

Mob::Mob(int x,int y,int is_al,int w,int h,const unsigned char* b,int ml,int mr){
	pos_x=x;
	pos_y=y;

	is_mob_alive=is_al;
	width=w;
	height=h;
	bitmap=b;
	moveL=ml;
	moveR=mr;
}

void Mob::generateHIT(){
	LHIT=pos_x;
	RHIT=pos_x+width;
	THIT=pos_y;
	BHIT=pos_y+height;
}

void Mob::check(Player &player){
generateHIT();
player.generateHIT();
if(is_mob_alive==1){

if((player.RHIT>LHIT)&&(player.LHIT<RHIT)&&(player.BHIT==THIT)){//if player hit mob's head mob dies
  is_mob_alive=0;//Mob dies
}
/*if((player.RHIT>=LHIT)&&(player.BHIT>=THIT)&&(player.BHIT<=BHIT)){//if player hit left side of Mob
  player.Player_live--;//player is loosing his hearts
}


if((player.LHIT<=RHIT)&&(player.BHIT>=BHIT)&&(player.BHIT<=THIT)){// if player hit the right side of Mob
  player.Player_live--;//player is loosing his hearts
  }*/
if((player.RHIT==LHIT)&&(player.THIT>=THIT)&&(player.BHIT<=BHIT)){//if player hit left side of Mob
  player.Player_live--;//player is loosing his hearts
}


if((player.LHIT==RHIT)&&(player.THIT>=THIT)&&(player.BHIT<=BHIT)){// if player hit the right side of Mob
  player.Player_live--;//player is loosing his hearts
  }

 }
else{
   pos_y=100;
   //throwing body of dead Mob out of the map
}
}

void Mob::Move_mob(int point_A, int point_B){
	generateHIT();
	if(is_mob_alive==1){
	if(moveR==true){   //moving  Mob form point A to point B
		   pos_x++;
		  }
		if(moveL==true){   //moving Mob form point B to point A
		   pos_x--;
		  }
		if(pos_x==point_A){//check if Mob hit the point_A
		   moveL=false;
		   moveR=true;
		  }
		if(RHIT==point_B){//check if Mob hit the ponit_B
		   moveL=true;
		   moveR=false;
          }
	}
}
void Mob::Display_mob(){
	if(is_mob_alive==1){
	ssd1306_DrawBitmap(pos_x, pos_y, bitmap, width, height, White);
	}
}
void Mob::Change_position(int x,int y){
	pos_x=x;
	pos_y=y;
}
Mob::~Mob() {
	// TODO Auto-generated destructor stub
}

