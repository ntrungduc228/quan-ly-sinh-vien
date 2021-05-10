#ifndef __VIEW__
#define __VIEW__
#pragma once
#include "Const.h"
#include "Utilities.h"

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

class Column{
private:
	string name;
	int width;
public:
	Column(){
		width = 0;
		name="";
	}
		
	int getWidth(){
		return this->width;
	}
	
	void setWidth(int width){
		this->width = width;
	}
	
	string getName(){
		return this->name;
	}
	
	void setName(string name){
		this->name = name;
	}
	
	void drawBox(int x,int y){
		rectangle(x,y,x+width,y+rowTableHeight);
	}
};

class Table{
private:
	int numOfCols;
	Column *col[MAX_NUM_COLUMN] = {NULL};
public:
	Table(){
		numOfCols = 0;
		for(int i=0; i<MAX_NUM_COLUMN; i++) this->col[i] = new Column;
	}
	
	/*~Table(){
		for(int i=0; i<MAX_NUM_COLUMN; i++) delete this->col[i];
	}*/
	
	freeTable(){
		for(int i=0; i<MAX_NUM_COLUMN; i++) delete this->col[i];
		
	}
	
	void setCols(int cols){
		this->numOfCols = cols;
	}
	
	Column* &getCols(int i){
		return this->col[i]; 
	}
	
	void drawLine(int x, int y){
		
		for(int i=0; i<numOfCols; i++){
			
			this->col[i]->drawBox(x,y);
			x+= this->col[i]->getWidth();
		}
	}
	
	void drawTable(int numOfRows){
		setcolor(clblack);
		int y=tableTop; int x= tableLeft;
		// hang so 0 la hang tieu de, du lieu bat dau tu hang 1 -> numOfRows
		for(int i=0; i<=numOfRows; i++){
			
			drawLine(x,y);
			
			x = tableLeft;
			y +=  rowTableHeight ;
		}
		
		printTitle();
	}
	
	void printTitle(){
		setcolor(clblack);
		int y=tableTop +  rowTableHeight/2 - textheight(this->col[0]->getName().c_str())/2;    //rowTableHeight/4 ; 
		int x = tableLeft;  
		int temp = tableLeft;
		
		for(int i=0; i<numOfCols; i++){
			
			x = temp + this->col[i]->getWidth()/2 - textwidth(this->col[i]->getName().c_str())/2;
			
			outtextxy(x,y,this->col[i]->getName().c_str());
			
			temp += this->col[i]->getWidth();
		}
	}
	
};

class View{
protected:
	string id;
	int left;
	int top;
	int right;
	int bottom;
	int backgroundColor;
	int borderColor;
	bool isInvalidate;
public:
	View(){
		id = "";
		left = top = right = bottom = 0;
	}
	
	View(string id, int left, int top, int right, int bottom, int backgroundColor, int borderColor){
		this->id = id;
		this->left = left;
		this->right = right;
		this->top = top;
		this->bottom = bottom;
		this->backgroundColor = backgroundColor;
		this->borderColor = borderColor;
		this->isInvalidate = true;
	}
	
	bool isClicked(int x, int y){
		return (left < x && x < right) && (top < y && y < bottom);
	}
	
	string getId(){
		return this->id;
	}
	
	virtual void draw(){
		
		isInvalidate = false;
		
		// Draw background
		setfillstyle(SOLID_FILL, backgroundColor);
		bar(left, top, right, bottom);

		// Draw border
		setcolor(borderColor);
		rectangle(left, top, right, bottom);
	}
	
	void Invalidate()	{
		isInvalidate = true;
	}
};

class Label : public View {
protected:
	string text;
	int textColor;
public:
	
	Label(
		string text,
		string id,
		int left,
		int top,
		int right,
		int bottom,
		int backgroundColor = 5,
		int borderColor = 5,
		int textColor = 0
	) : View(id, left, top, right, bottom, backgroundColor, borderColor)	{
		this->text = text;
		this->textColor = textColor;
	}

	Label(
		string text,
		int left,
		int top,
		int right,
		int bottom,
		int backgroundColor = cllightwhite,
		int borderColor = clblack,
		int textColor = clblack
	) : View("", left, top, right, bottom, backgroundColor, borderColor)	{
		this->text = text;
		this->textColor = textColor;
	}

	void draw(){
		View::draw();

		// Draw text
		int drawX = (right+left)/2 - textwidth(text.c_str())/2;
		int drawY = top + (bottom - top - 20) / 2; 

		setbkcolor(backgroundColor);
		setcolor(textColor);
		outtextxy(drawX, drawY, text.c_str());
	}

	void printLabel(
				string name1 = "", 
				string content1 = "",
				string name2 = "",
				string content2 = "",
				string name3 = "",
				string content3 = "",
				string name4 = "",
				string content4 = ""
		){
			
			draw();
			
			setbkcolor(cllightwhite);
			setcolor(clblack);
			
			if(name1 != "") name1 +=  ": " + content1;
			if(name2 != "") name2 +=  ": " + content2;
			if(name3 != "") name3 +=  ": " + content3;
			if(name4 != "") name4 +=  ": " + content4;
			
			if(name1 != "")
				outtextxy((right+left)/2 - textwidth(name1.c_str())/2, top + LABEL_SPACE_Y, name1.c_str());
		
			
			if(name3 == "" && name4 == ""){
				outtextxy((right+left)/2 - textwidth(name2.c_str())/2, top + LABEL_SPACE_Y*2 - 10 , name2.c_str());
			}else {
				
				outtextxy(left + 20 , top + LABEL_SPACE_Y*2 - 10 , name2.c_str());
				outtextxy(left + LABEL_SPACE_X + textwidth(name2.c_str())/2 , top + LABEL_SPACE_Y*2 - 10 , name3.c_str());
				outtextxy(left + LABEL_SPACE_X*2 + textwidth(name3.c_str())/2 , top + LABEL_SPACE_Y*2 - 10 , name4.c_str());
			}
			
			
		}
};

class Button : public Label{
public:
	Button(string text,
		   string id, 
		   int left, 
		   int top, 
		   int right, 
		   int bottom, 
		   int backgroundColor = buttonBGColor,
		   int borderColor = buttonBorderColor,
		   int textColor = buttonTextColor
		) : Label(text, id, left, top, right, bottom, backgroundColor, borderColor, textColor)
		{
		}
	
	void draw(){
		Label::draw();
	} 
	
	bool isClicked(int x, int y){
		return View::isClicked(x,y);
	}
};

class RadioButton : public Button{
public:
	
};


Table table_SV(){
	int numOfCols = 6;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 80, 150}; //{60, 200, 280, 160, 80, 170};
	string arrName[numOfCols] = { "STT",
								  "Ma sinh vien",
								  "Ho",
								  "Ten",
								  "Phai",
								  "SDT"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_MH(){
	int numOfCols = 5;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 160, 410, 200, 200}; 
	string arrName[numOfCols] = { "STT",
								  "Ma mon hoc",
								  "Ten mon hoc",
								  "So TC ly thuyet",
								  "So TC thuc hanh"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_LTC(){
	int numOfCols = 10;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60,80,140, 360, 60,60,60,70,70,70}; // 420
	string arrName[numOfCols] = { "STT",
								  "Ma lop",
								  "Ma mon hoc",
								  "Ten mon hoc",
								  "Khoa",
								  "HK",
								  "Nhom",
								  "SL",
								  "CL",
								  "TT"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_DK(){
	int numOfCols = 5;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 200}; 
	string arrName[numOfCols] = { "STT",
								  "Ma sinh vien",
								  "Ho",
								  "Ten",
								  "Lop"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_Diem(){
	int numOfCols = 5;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 200}; 
	string arrName[numOfCols] = { "STT",
								  "Ma sinh vien",
								  "Ho",
								  "Ten",
								  "Diem"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_LSV(){
	int numOfCols = 3;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 420,420}; 
	string arrName[numOfCols] = { "STT",
								  "Ten lop",
								  "So sinh vien hien tai cua lop"
								  };
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

void xoaTrang(){
	setbkcolor(cllightwhite); setcolor(cllightwhite);
	outtextxy(buttonPrevX + buttonWidth + 80, buttonY + 10 , string("     ").c_str());
	setbkcolor(cllightwhite); setcolor(clblack);
}

void inTrang(int trangHienTai, int tongSoTrang){
	
	xoaTrang();
	
	setbkcolor(cllightwhite); setcolor(clblack);
	string strTrangHT = convertIntToString(trangHienTai);
	string strTongST = convertIntToString(tongSoTrang);
	
	strTrangHT += "/" + strTongST;
	
	outtextxy(buttonPrevX + buttonWidth + 80, buttonY + 10, strTrangHT.c_str());
	//outtextxy(buttonPrevX + buttonWidth + 160, buttonY + 10 , string("1/3").c_str());
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
   	settextstyle(FONT_OF_TEXT,0,FONT_SIZE);
   	//setusercharsize(1,3,1,2);   // response font-size text UI
   	setusercharsize(2,5,1,2);   // response font-size text UI
	setcolor(clblack);					// set text color
	
	
	drawMainFrame();
	
	//while(!kbhit()) delay(1);	// pause screen	
	// MessageBox(NULL,"Dat Ve Thanh Cong !!!","THONG BAO",MB_ICONINFORMATION);
	
}
	
#endif
