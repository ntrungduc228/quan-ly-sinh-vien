/* 
	graphics in Dev-C++ - nguyenvanquan7826 
	
	Ho Ten: NGUYEN TRUNG DUC - NGUYEN THANH TRUNG
	MSSV: 	N19DCCN040		 - N19DCCN
	Lop:			   D19CQCN03-N
	De Tai: QUAN LY DIEM SINH VIEN THEO HE TIN CHI
*/

//#include <winbgim.h> 
#include"Menu.h"

int main(int argc, char *argv[])
{
	
	TREE DSMH;
	DSLopTC DSLTC;
	DSLopSV DSLSV;
	
	// now, you can run project
	initwindow(500, 500);			// init window graphics
	setbkcolor(1);					// set background
   	cleardevice();
	setcolor(14);					// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	
	if(DSLTC.getN()==0){
		outtextxy(50,120,"NULL");
	}
	
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
