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
	
	
	

	/* init_View();

	Table newTable = table_MH();
	newTable.drawTable(15);

	Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
	btnPrev.draw();
	
	Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
	btnNext.draw();
	
	
	Input *newInput = new Input("", INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT);
	newInput->draw(); */
	getch();
	
	return 0;
}
