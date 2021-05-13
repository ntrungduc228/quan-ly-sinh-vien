
#pragma once
#include "Const.h"
#include "View.h"



/*string convertIntToString(int so){
	stringstream ss;
	ss << so;
	string str;
	str = ss.str();
	return str; 
}*/

class Input : public Label {
private:
	string content = "";
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
	
	Input(
		string content,
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
		this->content = content;
	}
	
	string getContent(){
		return this->content;
	}
	
	
	void draw(){
		View::draw();
		
		setbkcolor(backgroundColor);
		setcolor(textColor);
		// draw title
		outtextxy(left - textwidth(text.c_str()) - 2, top + INPUT_HEIGHT/2 - textheight(text.c_str())/2 + 5, text.c_str() );
		
		// draw content
		//cout<<"\ncontent: "<<content<<" "<<content.length(); 
		outtextxy(left + 10, top + INPUT_HEIGHT/2 - textheight(text.c_str())/2 + 5, content.c_str());
		
	}
	
	
	
	void xuLyNhapTen_MH(int ch){
		if(ch == BACKSPACE && !content.empty()){
			content.erase(content.length() - 1, 1);	
		}else {
			if(content.empty()) ch = toupper(ch); // Viet hoa chu cai dau
			content.push_back(char(ch));
		}
		
	}
	
	void xuLyNhapMa_LSV(int ch){
		if(ch == BACKSPACE && !content.empty()){
			content.erase(content.length() - 1, 1);	
		}else {
			ch = toupper(ch); // Viet tat ca cac ki tu trong chuoi
			content.push_back(char(ch));
		}
	}
	
}; 



