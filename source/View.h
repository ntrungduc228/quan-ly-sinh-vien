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


void init_View(){
	// now, you can run project
	/*initwindow(screenWidth, screenHeight);			// init window graphics
	setbkcolor(cllightwhite);					// set background
   	cleardevice();
	setcolor(clblack);					// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	while(!kbhit()) delay(1);*/		// pause screen	
	
	resizeConsole(screenWidth, screenHeight);
}
	
	
