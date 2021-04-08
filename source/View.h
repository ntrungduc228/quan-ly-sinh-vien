#pragma once
#include "Const.h"

void initView(){
	// now, you can run project
	initwindow(screenWidth, screenHeight);			// init window graphics
	setbkcolor(cllightwhite);					// set background
   	cleardevice();
	setcolor(clblack);					// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
}
	
	
