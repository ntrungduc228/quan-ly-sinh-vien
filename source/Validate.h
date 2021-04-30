#pragma once
#include "Const.h"

void xuLyNhapDiem(string& str){
	char ch;
	
	while(true){
		ch = _getch();
		if(((ch>= '0' && ch<= '9') || ch =='.') && str.length() < MAXLENGTH_DIEM){
			
			if(str.length() > 0 ){
				if((str[str.length()-1] == '1' && ch != '.' || ch != '0') || ( str[str.length()-1] != '1' && ch != '.' ))
					continue;
			}
			
			str.push_back(ch);
			cout<<str;
			
		}else if(ch == BACKSPACE && str.length() > 0){
			str.erase(str.length() - 1, 1);
			cout<<"\b " ;
		}else if(ch == ENTER){
			return;
		}else if(ch == ESC){
			return;
		}
	}
}

void xuLyNhapChuoi(string& str){
	
}

void xuLyNhapSo(int& so){
	
}

void xuLyNhapHo(string& ho){
	
}

void xuLyNhapTen(string& ten){
	
}

void xuLyNhapMa(string& ma){
	
}

void xuLyNhapMaLop(string& maLop){
	
}

