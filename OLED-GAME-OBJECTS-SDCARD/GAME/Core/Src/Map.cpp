/*
 * Map.cpp
 *
 *  Created on: 25 lut 2023
 *      Author: Szymon
 */
/*--------includes------*/
#include"ssd1306.h"
#include"ssd1306_tests.h"
#include"Bitmaps.h"
#include <Map.h>

Map::Map(const unsigned char* b ,int w ,int h, int x, int y){
	pos_x=x;
	pos_y=y;
	width=w;
	height=h;
	bitmap=b;
}
void Map::Display_map(){
	//ssd1306_Fill(Black);
	ssd1306_DrawBitmap(pos_x, pos_y, bitmap, width, height,White);
    //ssd1306_UpdateScreen();
}
Map::~Map() {
	// TODO Auto-generated destructor stub
}

