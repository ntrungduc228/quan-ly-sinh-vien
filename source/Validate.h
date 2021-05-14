
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
	InputType type;
	int maxLength; // chieu dai chuoi
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
		int maxLength,
		InputType type,
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
		this->type = type;
		this->maxLength = maxLength;
	}
	
	string getContent(){
		return this->content;
	}
	
	bool isClicked(int x, int y){
		return View::isClicked(x,y); 
	}
	
	/*void draw(){
		View::draw();
		
		setbkcolor(backgroundColor);
		setcolor(textColor);
		// draw title
		outtextxy(left - textwidth(text.c_str()) - 2, top + INPUT_HEIGHT/2 - textheight(text.c_str())/2 + 5, text.c_str() );
		
		// draw content
		//cout<<"\ncontent: "<<content<<" "<<content.length(); 
		outtextxy(left + 10, top + INPUT_HEIGHT/2 - textheight(text.c_str())/2 + 5, content.c_str());
		
	}*/
	
	void draw(){		
		if(isFocused())
		{
			this->setBorderColor(clgreen);		
		}else
		{
			this->setBorderColor(clblack);	
		}
		
		View::draw();
		
		setbkcolor(backgroundColor);
		setcolor(textColor);
		
		// draw title
		outtextxy(left - textwidth(text.c_str()) - 2, top + INPUT_HEIGHT/2 - textheight(text.c_str()) / 2 , text.c_str() );
		
		string newContent = content;
		
		if (isFocused()) {
			newContent += "|";
		}
		
		// draw content
		outtextxy(left + 10, top + INPUT_HEIGHT/2 - textheight(text.c_str())/2, newContent.c_str());
		
	}

	void appendText(int character){
		if(content.empty() && (character == ' ' ||  character == BACKSPACE))
		{
			return;			
		}else if(character == BACKSPACE && !content.empty()){
			content.erase(content.length() - 1, 1);
		}else
		{
			switch(type)
			{
			case NUMBER:
				if(atoi(content.c_str()) > maxLength)
				{
					break;
				}else if(((character >= '0') && (character <= '9')))
				{
					content.push_back(character);
				}	
				break;
				
			case TEXT:
				if(content.length() > maxLength)
				{
					return;
				}else if(content[content.length()-1] == ' ' && character == ' ') // Kiem tra khoang trang lien tiep
				{
					return;
				}
				else if(((character < '0') || (character > '9'))) // Khong nhan ki tu So
				{				
					if(content.empty()) character = toupper(character); // Viet hoa chu cai dau
				
					content.push_back(character);
				}				
				break;
			
			case NON_SPACE:
				if(character != ' ' && content.length() <= maxLength)
				{
					character=toupper(character);
					content.push_back(character);
				}
				break;
			}
		}
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
// Duyet xem con input khac rong hay chua
bool duyetInputs(Input **input, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(input[i]->getContent().empty())
		{
			return false;	
		}
	}
	
	return true;
}


