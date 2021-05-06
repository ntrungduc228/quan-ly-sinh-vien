#pragma once
#include "Const.h"
#include "View.h"

string convertIntToString(int so){
	stringstream ss;
	ss << so;
	string str;
	str = ss.str();
	return str; 
}

class Input : public Label {
public:
	Input(
		string text,
		string id,
		int left,
		int top,
		int right,
		int bottom,
		int backgroundColor = 15,
		int borderColor = 0,
		int textColor = 0
	) : Label(text, id, left,  top, right, bottom, backgroundColor, borderColor, textColor)
	{
	}
	
	void draw(){
		View::draw();
		
		setcolor(textColor);
		outtextxy(left - textwidth(text.c_str()) - 2, top + INPUT_HEIGHT/2 - textheight(text.c_str())/2 + 5, text.c_str() );
	}
	
}; 


