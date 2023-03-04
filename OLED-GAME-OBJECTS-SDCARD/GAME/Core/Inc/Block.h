/*
 * Block.h
 *
 *  Created on: 25 lut 2023
 *      Author: Szymon
 */

#ifndef INC_BLOCK_H_
#define INC_BLOCK_H_
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include"Player.h"
class Block{
public:
int pos_x,pos_y,width,height;
int moveR,moveL,is_block_moving;
public:
int LHIT,RHIT,THIT,BHIT;   /* this is the hit box of our block*/
const unsigned char* bitmap;

//------methods------//
public:
Block(int x=0, int y=0,int w=10,int h=10,const unsigned char* b=Bitmap_block,int ml=0, int mr=1);
void generateHIT();                                                                              /* generates hit box of our block */
void Check(int &barrier,Player &player);                                                         /*checks if player hit the hit box*/
void Display_Block();                                                                            /*displays the block              */
void Move_Block(int point_A,int point_B,int &barrier,Player &player);                            /*moves block from A to B in loop */
void Change_position(int x,int y);                                                               /* changes position to x and y    */
virtual ~Block();
};

#endif /* INC_BLOCK_H_ */
