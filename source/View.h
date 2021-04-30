#pragma once
#include "Const.h"

void resizeConsole(int width, int height)
{
	// CODE 1

	/*HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);*/

	// CODE 2

	HWND c = GetConsoleWindow();
	DWORD style = GetWindowLong(c, GWL_STYLE);
	RECT r;
	COORD s = { width,height };
	GetWindowRect(c, &r);
	MoveWindow(c, 1, 1, width, height, TRUE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(c, GWL_STYLE, style);
	SetWindowPos(c, NULL, 1, 1, width, height, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}

void drawMainFrame(){
	
	const int Border_Color = clblue;
	
	// main frame
	
	setfillstyle(SOLID_FILL,Border_Color);	
	bar(frameLeft,frameTop,frameRight, frameBottom);
	
	setfillstyle(SOLID_FILL,backgroundColor);	
	bar(frameLeft+frameBorder,frameTop+frameBorder,frameRight - frameBorder, frameBottom - frameBorder);
	
	// line left side bar
	
	setfillstyle(SOLID_FILL,Border_Color);	
	bar(frameLeft,frameTop,leftSideBar, frameBottom);
	
	setfillstyle(SOLID_FILL,backgroundColor);	
	bar(frameLeft+frameBorder,frameTop+frameBorder,leftSideBar - frameBorder, frameBottom - frameBorder);
	
	// 
	int x = frameLeft, y = (frameBottom-frameBorder)/2;
	setcolor(Border_Color);
	rectangle(frameLeft+frameBorder-1,y,leftSideBar - frameBorder-1,y+2);
}

void init_View(){
	
	initwindow(screenWidth, screenHeight);			// init window graphics
	setbkcolor(cllightwhite);					// set background
   	cleardevice();
	setcolor(clblack);					// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	
	drawMainFrame();
	
	//while(!kbhit()) delay(1);	// pause screen	
	// MessageBox(NULL,"Dat Ve Thanh Cong !!!","THONG BAO",MB_ICONINFORMATION);
	//resizeConsole(screenWidth, screenHeight);
}
	
	
