
#pragma once

#include "MonHoc.h"
#include "SinhVien.h"
#include "LopSV.h"
#include "SVDangKy.h"
#include "LopTC.h"
#include "Validate.h"
#include "View.h"


void free(TREE &DSMH, DSLopTC &DSLTC, DSLopSV &DSLSV){
	DSMH.freeDS_MH(DSMH.getRoot());
	DSLTC.freeDS_LTC();
	DSLSV.freeDS_LSV();
}

void menu(TREE &DSMH, DSLopTC &DSLTC, DSLopSV &DSLSV){
	
	Button *menuButton[nMenuButton] = {NULL};
	
	menuTitle(menuButton, MENU, MENU_ID);
	
	int x,y;
	
	Action thaoTac = XUAT;

	while(true){
		
		delay(0.0001);
		if(ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			
			indexMenu = isClickMenuButton(menuButton, x,y);
			
		}
		
		if(indexMenu == -1) {
			decorMainScreen();
		}else if(indexMenu != -1){ cout<<"\nindex khac 1";
			thaoTac = XUAT;
			clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
			
			if(indexMenu != -1 && indexMenu != nMenuButton -1 ) drawMenu(menuButton);
				
			if(menuButton[indexMenu]->getId() == "LTC"){
				
				oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSLTC.menu_LTC(DSMH, DSLSV, thaoTac, menuButton); //cout<<"\ntt ltc "<<indexMenu;
				
			}else if(menuButton[indexMenu]->getId() == "SV"){
				
				oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSLSV.menu_LSV(thaoTac, menuButton); //cout<<"\ntt lsv "<<indexMenu;
				
			}else if(menuButton[indexMenu]->getId() == "MH"){
				
				oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSMH.menu_MH(thaoTac, menuButton); //cout<<"\ntt mh "<<indexMenu;
				
			}else if(menuButton[indexMenu]->getId() == "DIEM"){
				
				thaoTac = DIEM; oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSLTC.menu_LTC(DSMH, DSLSV, thaoTac, menuButton); //cout<<"\ntt dk "<<indexMenu;
			}else if(indexMenu == nMenuButton -1 ){
				exitProgram = isExit();
				if(!exitProgram){
					indexMenu = -1; continue;
				}
			}
			
			clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);	
		}
	
		if(exitProgram){
			
			DSMH.writeDataDS_MH();
			DSLTC.writeDataDS_DK();
			DSLTC.writeDataDS_LTC();
			DSLSV.writeDataDS_LSV();
			DSLSV.writeDataDS_SV();
					
			freeArrButton(menuButton, nMenuButton);
			return;			
				
		}
	}
	
}



