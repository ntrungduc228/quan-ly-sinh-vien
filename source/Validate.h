
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
		int borderColor = clblack,
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
		int backgroundColor = cllightwhite,
		int borderColor = clblack,
		int textColor = clblack
	) : Label(text, id, left,  top, right, bottom, backgroundColor, borderColor, textColor)
	{
		this->content = content;
		this->type = type;
		this->maxLength = maxLength;
	}
	
	/*Input(const Input &input) : Label(text, id, left,  top, right, bottom, backgroundColor, borderColor, textColor)
	{
		this->content = input.content;
		this->type = input.type;
		this->maxLength = input.maxLength;
	}
	
	Input(const Input *input) : Label(text, id, left,  top, right, bottom, backgroundColor, borderColor, textColor)
	{
		this->content = input->content;
		this->text = input->text;
		this->type = input->type;
		this->maxLength = input->maxLength;
		this->id = input->id;
		this->left = input->left;
		this->right = input->right;
		this->top = input->top;
		this->bottom = input->bottom;
		this->backgroundColor = input->backgroundColor;
		this->borderColor = input->borderColor;
		this->textColor = input->textColor;
		this->isInvalidate = true;
	}*/
	
	void setParams(int left, int top, int right, int bottom){
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}
	
	void setTextColor(int textColor){
		this->textColor = textColor;
	}
	
	void setContent(string content){
		this->content = content;
	}
	
	int getMaxLength(){
		return this->maxLength;
	}
	
	InputType getType(){
		return this->type;
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
		/*if(isFocused())
		{
			this->setBorderColor(INPUT_BORDER_COLOR_FOCUS);	// INPUT_BORDER_COLOL_FOCUS = clgreen
		}else
		{
			this->setBorderColor(clblack);
		}*/
		
		View::draw();
		
		setbkcolor(backgroundColor);
		setcolor(textColor);
		
		// draw title
		outtextxy(left - textwidth(text.c_str()) - 2, top + abs (INPUT_HEIGHT/2 - textheight(text.c_str()) / 2 )+ 1 , text.c_str() );
		
		string newContent = content;
		
		if (isFocused()) {
			newContent += "|";
		}
		
		// draw content
		outtextxy(left + 10, top + INPUT_HEIGHT/2 - textheight(newContent.c_str())/2, newContent.c_str());
		//outtextxy(left + 10, top + (top+bottom)/2 - textheight(text.c_str())/2, newContent.c_str());
	}

	void appendText(int character){
		if(content.empty() && (character == ' ' ||  character == BACKSPACE))
		{
			return;			
		}else if(character == BACKSPACE && !content.empty()){
			content.erase(content.length() - 1, 1);
		}else
		{
			switch(type){
				case NUMBER:{
					if(content.length() == maxLength)
					{
						break;
					}else if(((character >= '0') && (character <= '9')))
					{
						content.push_back(character);
					}	
					break;
				}
					
					
				case TEXT:{
					if(content.length() > maxLength)
					{
						return;
					}else if(content[content.length()-1] == ' ' && character == ' ') // Kiem tra khoang trang lien tiep
					{
						return;
					}
					else
					{	if(character == TAB || character == ENTER) return;			
						if(content.empty()) character = toupper(character); // Viet hoa chu cai dau
					
						content.push_back(character);
					}		
					break;
				}
				
				case NON_NUMBER:{
					if(content.length() == maxLength)
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
				}
					
				
				case NON_SPACE:{
					if(character != ' ' && content.length() <= maxLength)
					{
						character=toupper(character);
						content.push_back(character);
					}
					
					break;
				}
				
				case NAME:{
					if(character != ' '  && ((character < '0') || (character > '9')) && content.length() <= maxLength)
					{
						if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
							
							character = tolower(character);
							if(content.empty())	character=toupper(character);
							
							content.push_back(character);
						}
						 
							
					}
				
					break;
				}
				
				case LAST_NAME:{
					if(content.length() == maxLength)
					{
						return;
					}else if(content[content.length()-1] == ' ' && character == ' ' || (content.empty() && character == ' ')) // Kiem tra khoang trang lien tiep
					{
						return;
					}
					else if(((character < '0') || (character > '9'))) // Khong nhan ki tu So
					{	
						if((character == ' ') || (character>='a' && character<='z') || (character>='A' && character<='Z')){
							character = tolower(character);			
							if(content.empty() || content[content.length()-1] == ' ') 
								character = toupper(character); // Viet hoa chu cai dau
							
							content.push_back(character);
						}
							
					}	
					break;
				}
					
				case STUDENT_ID:{
					if((character>='0' && character <= '9'|| character>='a' && character <='z' || character>='A' && character<='Z') && character != ' ' && content.length() <= maxLength)
					{
						character=toupper(character);
						content.push_back(character);
					}
					
					break;
				}
				
				case MARK:{
					if(content.length() == 3){
						return;
					}
					else if(((character >= '0') && (character <= '9')) || character =='.')
					{
						if(content.length()>1){
							if(content ==  "10")
								return;
						}else if(content.length()>0){
							if(character != '.'  && content != "1")
								return;
							if(content == "1" && character != '0' && character != '.')
								return;
						}else if(character <'0' || character >'9')
							return;
							
						content.push_back(character);
					}
					break;
				}
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


