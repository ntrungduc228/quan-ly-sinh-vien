/* 
	Graphics in Dev-C++ winbgim.h
	
	Ho Ten: NGUYEN TRUNG DUC - NGUYEN THANH TRUNG
	MSSV: 	N19DCCN040	- N19DCCN216
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
	
	srand(time(NULL));
	
	if(loadFileIsSuccess){
		resizeConsole(1368, 745);
		//menu1(dssv,DSLTC,DSLSV,DSMH);
		
		init_View();
		menu(DSMH, DSLTC, DSLSV);
	}else {
		LIST_DATA.insert(0, "KHONG TIM THAY FILE DU LIEU ");
		MessageBox(
					NULL,
					LIST_DATA.c_str(),
					"THONG BAO",
					MB_ICONERROR | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
			);
	}
	
	free(DSMH, DSLTC, DSLSV);
	
	//decorMainScreen();
	
	/*Table newTable = table_NhapSV();
	newTable.drawTable(15);

	Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
	btnPrev.draw();
	
	Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
	btnNext.draw();
	
	Input newInput("","" ,INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT);
	newInput.draw(); 
	int y = tableTop ;
	string str = "";
	int x = tableLeft + 15;
	int xtemp = 1225;
	Button checkBoxBtn1("Sua","checkBoxBtn",xtemp , y+checkBoxButtonY+3, xtemp+ checkBoxButtonWidth, y-3 +checkBoxButtonY+checkBoxButtonHeight, claqua, cllightblue, clblack   );
	checkBoxBtn1.draw(); xtemp += checkBoxButtonWidth + 5;
	Button checkBoxBtn2("Xoa","checkBoxBtn",xtemp , y+checkBoxButtonY+3, xtemp+ checkBoxButtonWidth, y-3 +checkBoxButtonY+checkBoxButtonHeight,cllightred, clred, cllightwhite   );
	checkBoxBtn2.draw();*/
	
	//drawFrame(500, 150, 540 + 500, 200+300, "Them lop TC");
	
	//getch();
	
	return 0;
}
