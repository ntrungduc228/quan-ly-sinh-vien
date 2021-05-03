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
	
/*	
	TREE DSMH;
	DSLopTC DSLTC;
	DSLopSV DSLSV;
	
	DSSV dssv;
	
	DSLSV.loadData_LSV();
	DSLTC.loadDataDS_LTC();
	DSLSV.loadDataDS_SV();
	DSMH.loadDataDS_MH();
	DSLTC.loadDataDS_DK();
	
	init_View();

	menu(dssv,DSLTC,DSLSV,DSMH);
	
	*/
	
	
	init_View();

	Table newTable = table_SV();
	newTable.drawTable(15);
	newTable.printTitle();
	//newTable.drawLine(tableLeft,tableTop);
	
	/*Column  col;
	
	col.setX(tableLeft);
	col.setY(tableTop + 100);
	col.setWidth(100);
	col.drawBox();*/
	
	getch();
	
	return 0;
}
