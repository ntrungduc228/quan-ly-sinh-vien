/* 
	Graphics in Dev-C++ winbgim.h
	
	Ho Ten: NGUYEN TRUNG DUC   -  	NGUYEN THANH TRUNG
	MSSV: 	N19DCCN040	       -    N19DCCN216
	Lop:			 D19CQCN03-N
	Truong:			 PTIT HCM
	De Tai: QUAN LY DIEM SINH VIEN THEO HE TIN CHI
*/

#include"Menu.h"

int main(int argc, char *argv[])
{
	TREE DSMH;
	DSLopTC DSLTC;
	DSLopSV DSLSV;
	
	DSLSV.loadData_LSV();
	DSLTC.loadDataDS_LTC();
	DSLSV.loadDataDS_SV();
	DSMH.loadDataDS_MH();
	DSLTC.loadDataDS_DK();
	
	if(loadFileIsSuccess){
		//resizeConsole(745, 545);
		
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

	return 0;
}
