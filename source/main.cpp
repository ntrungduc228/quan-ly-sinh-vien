/* 
	graphics in Dev-C++ - nguyenvanquan7826 
	
	Ho Ten: NGUYEN TRUNG DUC - NGUYEN THANH TRUNG
	MSSV: 	N19DCCN040		 - N19DCCN216
	Lop:			 D19CQCN03-N
	De Tai: QUAN LY DIEM SINH VIEN THEO HE TIN CHI
*/

#include"Menu.h"



int main(int argc, char *argv[])
{
	
	
	TREE DSMH;
	DSLopTC DSLTC;
	DSLopSV DSLSV;
	
	DSSV dssv;
	
	DSLSV.loadData_LSV();
	DSLTC.loadDataDS_LTC();
	DSLSV.loadDataDS_SV();
	DSMH.loadDataDS_MH();
	DSLTC.loadDataDS_DK();
	
	resizeConsole(1368, 745);

	
	menu(dssv,DSLTC,DSLSV,DSMH);
	
	
	

	/*init_View();

	Table newTable = table_MH();
	newTable.drawTable(15);

	Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
	btnPrev.draw();
	
	Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
	btnNext.draw();
	
	
	Input newInput("","" ,INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT);
	newInput.draw(); 
	int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2;
	string str = ""; //str += 251; cout<<str;
	int x = tableLeft + 15;
	Button checkBoxBtn(str.c_str(),"checkBoxBtn",x , y+rowTableHeight-3, x+ checkBoxButtonWidth, y +rowTableHeight+20,cllightwhite, clblack, clgreen   );
	checkBoxBtn.draw();
	setcolor(clgreen);
	//setlinestyle(SOLID_LINE, 1, 3);
	//line(x+5, y+rowTableHeight + 10,tableLeft + 30,y +rowTableHeight+18) ;
	//line(x+checkBoxButtonWidth-3, y+rowTableHeight + 5,tableLeft + 20,y +rowTableHeight+1);*/
	
	
	getch();
	
	return 0;
}
