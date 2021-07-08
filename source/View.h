
#pragma once
#include "Utilities.h"

void resizeConsole(int width, int height)
{
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
	
	freeTable(){
		for(int i=0; i<MAX_NUM_COLUMN; i++) delete this->col[i];
		
	}
	
	int getNumOfCols(){
		return this->numOfCols;
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
		setcolor(clblack); setbkcolor(cllightwhite); 
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
	int backgroundColor=15;
	int borderColor=0;
	bool isInvalidate;
	static string focusedId;
	bool enable = true;
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
	
	void setId(string id){
		this->id = id;
	}
	
	string getId(){
		return this->id;
	}
	
	int getLeft(){ return this->left; }
	int getTop(){ return this->top; }
	int getRight(){ return this->right; }
	int getBottom(){ return this->bottom; }
	
	
	virtual void draw(){
		
		isInvalidate = false;
		
		// Draw background
		setfillstyle(SOLID_FILL, backgroundColor);
		bar(left, top, right, bottom);

		// Draw border
		if(isFocused()){
			setcolor(clgreen);
		}else  setcolor(borderColor);
		//setcolor(borderColor);
		rectangle(left, top, right, bottom);
	}

	
	void setBorderColor(int borderColor){
		this->borderColor = borderColor;
	}
	
	void setBGColor(int color)
	{
		this->backgroundColor=color;
	}
	
	void requestFocus()
	{
		View::focusedId=this->id;
	}
	
	bool isFocused()
	{
		return (this->id) == (View::focusedId); 
	}
	
	void initFocusedId()
	{
		this->focusedId="";
	}
	
	void setEnable(){
		this->enable = true;
	}
	
	void setOffEnable()
	{
		this->enable=false;
	}
	
	bool getEnable()
	{
		return enable;
	}
	
	void Invalidate()	{
		isInvalidate = true;
	}
};

string View::focusedId = "";

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
	
	string getText(){
		return this->text;
	}
	
	int getBKColor() {return this->backgroundColor;}
	int getBorderColor() { return this->borderColor;}
	int getTextColor() { return this->textColor;}
	
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
				string content4 = "",
				string name5 = "",
				string content5 = "",
				string name6 = "",
				string content6 = "",
				string name7 = "",
				string content7 = ""
		){
			
			draw();
			
			setbkcolor(cllightwhite);
			setcolor(clblack);
			
			if(name1 != "") name1 +=  ": " + content1;
			if(name2 != "") name2 +=  ": " + content2;
			if(name3 != "") name3 +=  ": " + content3;
			if(name4 != "") name4 +=  ": " + content4;
			if(name5 != "") name5 +=  ": " + content5;
			if(name6 != "") name6 +=  ": " + content6;
			if(name7 != "") name7 +=  ": " + content7;
			
			if(name1 != "")
				outtextxy((right+left)/2 - textwidth(name1.c_str())/2, top + LABEL_SPACE_Y, name1.c_str());
		
			
			if(name3 == "" && name4 == ""){
				outtextxy((right+left)/2 - textwidth(name2.c_str())/2, top + LABEL_SPACE_Y*2 - 10 , name2.c_str());
			}else if(name5 == "" && name6 == ""){
				
				outtextxy(left + 20 , top + LABEL_SPACE_Y*2 - 10 , name2.c_str());
				outtextxy(left + LABEL_SPACE_X + textwidth(name2.c_str())/2 , top + LABEL_SPACE_Y*2 - 10 , name3.c_str());
				outtextxy(left + LABEL_SPACE_X*2 + textwidth(name3.c_str())/2 , top + LABEL_SPACE_Y*2 - 10 , name4.c_str());
			}else {
				outtextxy(left-20-textwidth(name2.c_str())/2, top + LABEL_SPACE_Y, name5.c_str());
				outtextxy(left+140+textwidth(name2.c_str())*2, top + LABEL_SPACE_Y, name6.c_str());
				
				outtextxy(left-60, top + LABEL_SPACE_Y*2 - 10, name7.c_str());
				outtextxy(left + 50 , top + LABEL_SPACE_Y*2 - 10 , name2.c_str());
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
	
	void setText(string text){
		this->text = text;
	}
	
	
	
	void setBorderColor(int borderColor){
		this->borderColor = borderColor;
	}
	
	void setTextColor(int textColor){
		this->textColor = textColor;
	}
	
	void setId(string id){
		//this->id = id; 
		View::setId(id);
	}
	
	void setParams(int left, int top, int right, int bottom){
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}
	
	void setState(string text, string id, int bgColor, int borderColor, bool enable){
		this->text = text;
		this->id = id;
		this->backgroundColor = bgColor;
		this->borderColor = borderColor;
		this->enable = enable;
	}
	
	//??
	string getId(){
		return this->id;
	}
	
	string getText(){
		return Label::getText();
	}
	
	void draw(){
		Label::draw();
	} 
	
	bool isClicked(int x, int y){
		return View::isClicked(x,y);
	}
};


Table table_SV(){
	int numOfCols = 7;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 80, 150, 110}; //{60, 200, 280, 160, 80, 170};
	string arrName[numOfCols] = { "STT",
								  "Ma sinh vien",
								  "Ho",
								  "Ten",
								  "Phai",
								  "SDT",
								  "Thao tac"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_NhapSV(){
	int numOfCols = 6;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 170, 170}; 
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
	int numOfCols = 6;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 160, 410, 150, 150, 110}; 
	string arrName[numOfCols] = { "STT",
								  "Ma mon hoc",
								  "Ten mon hoc",
								  "So TC ly thuyet",
								  "So TC thuc hanh",
								  "Thao tac"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_LTC(){
	int numOfCols = 12;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {50,70,80, 370, 50,50,50,50,50,50,60,110}; // 100, 420
	string arrName[numOfCols] = { "STT",
								  "Ma lop",
								  "Ma MH",
								  "Ten mon hoc",
								  "Khoa",
								  "HK",
								  "Nhom",
								  "SL",
								  "CL",
								  "Min",
								  "Huy",
								  "Thao tac"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_DK(){
	int numOfCols = 6;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 150, 180}; 
	string arrName[numOfCols] = { "STT",
								  "Ma sinh vien",
								  "Ho",
								  "Ten",
								  "SDT",
								  "Lop"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_Diem(){
	int numOfCols = 6;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 200, 280, 160, 180, 155}; 
	string arrName[numOfCols] = { "STT",
								  "Ma sinh vien",
								  "Ho",
								  "Ten",
								  "Lop",
								  "Diem"};
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

Table table_LSV(){
	int numOfCols = 4;
	Table newTable;
	newTable.setCols(numOfCols);
	
	int arrWidth[numOfCols] = {60, 420, 420, 135}; // thao tac - 110
	string arrName[numOfCols] = { "STT",
								  "Ten lop",
								  "So sinh vien hien tai cua lop",
								  "Thao tac"
								  };
	
	for(int i=0; i<numOfCols; i++){
		newTable.getCols(i)->setWidth(arrWidth[i]);
		newTable.getCols(i)->setName(arrName[i]);
	}
	
	return newTable;
}

void freeArrButton(Button *arrButton[], int n){
	for(int i=n-1; i>=0; i--){
		delete arrButton[i];
		arrButton[i] = NULL;
	}
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
}


void clearRegion(int left, int top, int right, int bottom)
{
	setfillstyle(SOLID_FILL,backgroundColor);	
	//setfillstyle(SOLID_FILL,clyellow);	
	bar(left, top, right, bottom);
}

void drawFrame(int left, int top, int right, int bottom){
	
	const int Border_Color = clblue;
		
	setfillstyle(SOLID_FILL,Border_Color);	
	bar(left,top,right, bottom);
	
	setfillstyle(SOLID_FILL,backgroundColor);	
	bar(left+frameBorder,top+frameBorder,right - frameBorder, bottom - frameBorder);
}

void drawFrame(int left, int top, int right, int bottom, string title){
	
	const int Border_Color = clblue;
		
	setfillstyle(SOLID_FILL,Border_Color);	
	bar(left,top,right, bottom);
	
	setfillstyle(SOLID_FILL,backgroundColor);	
	bar(left+frameBorder,top+frameBorder,right - frameBorder, bottom - frameBorder);
	
	title = "   " + title + "   ";
	std::transform(title.begin(), title.end(),title.begin(), ::toupper); // in hoa chuoi 
	
	setbkcolor(cllightgreen);
	setcolor(clblack);
	outtextxy((right+left)/2 - textwidth(title.c_str())/2, top+15, title.c_str());
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
	

	int x = frameLeft, y = (frameBottom-frameBorder)/2;
	setcolor(Border_Color);
	rectangle(frameLeft+frameBorder-1,y,leftSideBar - frameBorder-1,y+2);
	
	setcolor(clblack);
	setbkcolor(cllightgreen);
	
	string title = "   MENU   ";
	outtextxy( (frameLeft + leftSideBar)/2 - textwidth(title.c_str())/2 , frameTop+15, title.c_str());
	
	title = "   HUONG DAN   ";
	outtextxy( (frameLeft + leftSideBar)/2 - textwidth(title.c_str())/2 , y+10, title.c_str());
	
	setbkcolor(cllightwhite);
	y+= 40;
	// thong tin
	string info = " - Dung chuot de thao tac";
	outtextxy(frameLeft + 12, y, info.c_str());
	
	y+=30;
	info = " - Khi nhap khong the thao tac voi";
	outtextxy(frameLeft + 12, y, info.c_str());
	y+=20;
	info = "menu chinh";
	outtextxy(frameLeft + 30, y, info.c_str());
	
	y+=30;
	info = " - TAB: di chuyen giua cac o nhap";
	outtextxy(frameLeft + 12, y, info.c_str());
	
	
	y+=40;
	info = "PTIT HCM";
	outtextxy((frameLeft + leftSideBar)/2 - textwidth(info.c_str())/2, y, info.c_str());
	
}


int isClickMenuButton(Button **menuButton, int x, int y){
	for(int i=0; i<nMenuButton; i++){
		if(menuButton[i]->isClicked(x,y)){
			return i;
		}
	}
	
	return -1;
}

void drawMenu(Button *menuButton[]){
	if(oldIndexMenu != -1){
		menuButton[oldIndexMenu]->setBGColor(claqua);
		menuButton[oldIndexMenu]->draw();
	}
	
	
	menuButton[indexMenu]->setBGColor(cllightgreen);
	menuButton[indexMenu]->draw();
}

void menuTitle(Button *button[], string MENU[], string MENU_ID[]){
	int x = xMenu;
	int y = yMenu+30;
	
	for(int i=0; i< nMenuButton; i++){
	 if(button[i] == NULL)
		button[i] = new Button(MENU[i],MENU_ID[i], x, y, x + btnMenuWidth, y+btnMenuHeight, claqua, clblack, clblack);
		button[i]->draw();
		
		y+=menuSpace;
	}
}



void decorMainScreen(){
	ifstream fileIn("data\\Logo.txt", ios::in); string str;
	if(fileIn.is_open()){
		int y = 50; 
		setcolor(clblack); setbkcolor(cllightwhite);
		while (!fileIn.eof()){
			getline(fileIn, str);
			if(!str.empty()){
				for(int i=0; i<str.length(); i++){
					if(str[i] == '@') str[i] = ' ';
				}
				outtextxy(450, y, str.c_str());
			}
			y+= textheight(str.c_str());
		}
		
	}
	fileIn.close();
	
	setbkcolor(cllightred); setcolor(cllightwhite);
	outtextxy(600, 630, "    NGUYEN TRUNG DUC   -   NGUYEN THANH TRUNG   ");
	
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

}

bool isExit(string title = "BAN CO CHAC CHAN THOAT CHUONG TRINH"){
	bool exit = false;
	int isConfirmed = MessageBox(
						NULL,
						title.c_str(),
						"THONG BAO",
						MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
					);
												    		
	switch(isConfirmed){
									
		case IDOK: {
			exit = true;							
			break;
		}
	}
	return exit;
}

