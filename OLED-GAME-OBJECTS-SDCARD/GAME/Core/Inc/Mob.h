/*
 * Mob.h
 *
 *  Created on: 2 mar 2023
 *      Author: Szymon
 */

#ifndef INC_MOB_H_
#define INC_MOB_H_
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include <Player.h>
//Player boxi(80,4,8,8);
class Mob {
public:
int is_mob_alive;
int pos_x,pos_y,width,height;
int moveR,moveL;
public:
int LHIT,RHIT,THIT,BHIT; /* this is the hit box of our Mob*/
const unsigned char* bitmap;
//Player player;

//------methods------//
//Mob(int x=100,int y=56,Player &p,int is_al=1,int w=8,int h=8,const unsigned char* bitmap=Bitmap_mob,int moveL=1,int moveR=0);
Mob(int x=100,int y=56,int is_al=1,int w=8,int h=8,const unsigned char* b=Bitmap_mob,int ml=1,int mr=0);
void generateHIT(); //generates hit box
void check(Player &player); //checking if player kill mob or mob damage player
void Move_mob(int point_A,int point_B);//moves mob form point A to point B
void Display_mob(); //draws mob on screen
virtual ~Mob();
};

#endif /* INC_MOB_H_ */
