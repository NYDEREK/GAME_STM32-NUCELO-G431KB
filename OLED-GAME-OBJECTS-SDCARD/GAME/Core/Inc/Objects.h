/*
 * Objects.h
 *
 *  Created on: 4 mar 2023
 *      Author: Szymon
 */

#ifndef INC_OBJECTS_H_
#define INC_OBJECTS_H_
//-----includes-----//
#include "Block.h"
#include "Player.h"
#include "Map.h"
#include"Bitmaps.h"
#include "Mob.h"
#include"stdio.h"
#include"string.h"
#include "Spike.h"
#include "Coin.h"

 // creating a map//
Map map1(Bitmap_map);
Map castle_map(Bitmap_castle);
Map Win_map(Bitmap_win);
Map easter_egg_map(Bitmap_easter_egg);
// creating the player//
Player boxi(10,4,8,8);       //there we are creating our map adding player ,blocks, mobs and spikes

//creating blocks//
Block B[10];

//creating Mobs//
Mob m1(95,54);

//creating spikes//
Spike S[6];

//creating coins
Coin c1(119,36);


#endif /* INC_OBJECTS_H_ */
