
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

void menu1(DSSV &ds, DSLopTC &DSLTC,DSLopSV &DSLSV, TREE &dsmh){
	int chon;
	while(true){
		system("cls");
		
		cout<<"\nMenu graphics";
		cout<<"\nMenu guides";
		cout<<"\n1. Nhap sinh vien 					(done graphics)";
		cout<<"\n2. Xuat ds sinh vien 				(done graphics ok)";
		cout<<"\n3. Sua sinh vien 					(done graphics)";
		cout<<"\n4. Xoa sinh vien 					(done graphics)";
		cout<<"\n5. Them lop tc 					(done graphics)";
		cout<<"\n6. Xuat DS lop tc					(done graphics ok)";
		cout<<"\n7. Sua lop tc 						(done graphics)";
		cout<<"\n8. Xoa lop tc 						(done graphics)";
		cout<<"\n9. Them lop hoc 					(done graphics)";
		cout<<"\n10. Xuat ds lop hoc 				(done graphics ok)";
		cout<<"\n\n11. Them mon hoc 				(done graphics)";
		cout<<"\n12. In ds mon hoc 					(done graphics ok)";
		cout<<"\n13. Sua mon hoc 					(done graphics)";
		cout<<"\n14. Xoa mon hoc 					(done graphics)";
		cout<<"\n15. Dang ky lop tc 				(done graphics)";
		cout<<"\n16. In ds dang ky trong 1 lop tc 	(done graphics ok)";
		cout<<"\n17. Huy lop tc 					(done graphics)";
		cout<<"\n18. Nhap diem 1 lop tc 			(done graphics)";
		cout<<"\n19. Xuat diem 1 lop tc 			(done graphics ok)";
		
		cout<<"\n\n20. Lay data lop SV (done)";
		cout<<"\n21. Lay data lop TC (done)";
		cout<<"\n22. Lay data mon hoc (done)";
		cout<<"\n23. Lay data ds Sv (done) ";
		cout<<"\n24. Lay data ds dk (done)";
		cout<<"\n0. thoat (tu dong luu data vo file)";
		
		cout<<"\n\nNhap lua chon: ";
		cin>>chon;
		
		if(chon==0){
			
			// mon hoc
			dsmh.writeDataDS_MH();
			dsmh.freeDS_MH(dsmh.getRoot());
			// ds dk
			DSLTC.writeDataDS_DK();
			
			DSLSV.writeDataDS_SV();
			DSLTC.writeDataDS_LTC();
			DSLSV.writeDataDS_LSV();
			DSLSV.freeDS_LSV();
			
			exit(0);
		}else if(chon==1){
			cin.ignore();
			string maLop;
			cout<<"\nNhap ma lop: ";
			getline(cin, maLop);
			int viTri = DSLSV.tim_LSV(maLop);
			if(viTri!=-1) {
					//DSSV dssv = DSLSV.getLopSV_LSV(viTri)->getDS_SV();
						while(true){
						system("cls");
						SinhVien sv;
						sv.nhap_SV("");
						sv.setMaLop(maLop);
						if(sv.getMaSV()=="") break;
						NodeSV *SV = new NodeSV(sv);
						
						//dssv.them_SV(SV);
						DSLSV.getLopSV_LSV(viTri)->getDS_SV().them_SV(SV);
						system("pause");
					}
					//dssv.xuatDS_SV();
				//DSLSV.getLopSV_LSV(viTri)->setDS_SV(dssv);
			
				cout<<"\n\n================";
				DSLSV.getLopSV_LSV(viTri)->getDS_SV().xuatDS_SV();
				
			}else cout<<"\nKo tim thay lop sv";
			
			cout<<"\nok";
			system("pause");
		}else if(chon==2){
			system("cls");
			cin.ignore();
			string maLop;
			cout<<"\nNhap ma lop: ";
			getline(cin, maLop);
			int viTri = DSLSV.tim_LSV(maLop);
			if(viTri!=-1) {
					//ds.xuatDS_SV();
				//DSLSV.getLopSV_LSV(viTri)->getDS_SV().xuatDS_SV();
				init_View();
				//DSLSV.getLopSV_LSV(viTri)->getDS_SV().chon_SV(DSLSV.getLopSV_LSV(viTri)->getMaLop(), XUAT); getch();
			}else cout<<"\nKo tim thay lop sv";
			system("pause");
		}else if(chon==3){
			system("cls");
			string maSV;
			cin.ignore();
			string maLop;
			cout<<"\nNhap ma lop: ";
			getline(cin, maLop);
			int viTri = DSLSV.tim_LSV(maLop);
			if(viTri!=-1) {
				cout<<"\nNhap ma sv can sua: ";
				getline(cin,maSV);
				int vt = DSLSV.getLopSV_LSV(viTri)->getDS_SV().tim_SV(maSV);
				if(vt!=-1){
					
					if(DSLSV.getLopSV_LSV(viTri)->getDS_SV().sua_SV(maSV)!=-1) cout<<"\nSua thanh cong sv";
				}else cout<<"\nko tim thay sv";
			}else cout<<"\nKo tim thay lop sv";
			
			system("pause");
		}
		else if(chon==4){
			system("cls");
			/*string maSV;
			cin.ignore();
				string maLop;
				cout<<"\nNhap ma lop: ";
				getline(cin, maLop);
				int viTri = DSLSV.tim_LSV(maLop);
				if(viTri!=-1) {
						cout<<"\nNhap ma sv can xoa: ";
						getline(cin,maSV);
						int vt = DSLSV.getLopSV_LSV(viTri)->getDS_SV().tim_SV(maSV);
						if(vt!=-1){
							
							if(DSLSV.getLopSV_LSV(viTri)->getDS_SV().xoa_SV(maSV)!=-1) cout<<"\nXoa thanh cong sv";
						}else cout<<"\nko tim thay sv";
				}else cout<<"\nKo tim thay lop sv";*/
			
			system("pause");
		}else if(chon==5){
			system("cls");
			
			if(!DSLTC.isFull_LTC()){
				LopTC *ltc = new LopTC;
	
				ltc->taoMaLop_LTC(DSLTC.getLopTC(DSLTC.getN()-1)->getMaLopTC());
				
				do{
					ltc->nhap_LTC();
					
				}while(DSLTC.checkTrungDS_LTC(ltc));
					
				
				if(DSLTC.them_LTC(ltc)!=0) cout<<"\nThem lop tc thanh cong";
		
			}else cout<<"\nLTC da day, khong the them";
			
			
			
			system("pause");
		}else if(chon==6){
			system("cls");
			//cout<<"\n ds lop tc";	DSLTC.xuatDS_LTC();	system("pause"); 
			Action	thaoTac = XUAT;
			//init_View(); DSLTC.chon_LTC(dsmh, DSLSV, thaoTac); getch();
		}else if(chon==7){
			system("cls");
			int maLop;
			cout<<"\nNhap ma lop tc: ";
			cin>>maLop;
				if(DSLTC.sua_LTC(maLop)!=-1){
					cout<<"\nSua ltc thanh cong";
				}else cout<<"\nKo tim thay ltc";
			system("pause");
		}else if(chon==8){
			system("cls");
			if(DSLTC.getN()==0) cout<<"\n DSLTC rong";
			else{
				int maLop;
				cout<<"\nNhap ma lop tc: ";
				cin>>maLop;
				if(DSLTC.xoa_LTC(maLop)!=-1){
					cout<<"\nXoa ltc thanh cong";
				}else cout<<"\nKo tim thay ltc";
			}
				
			system("pause");
		}else if(chon==9){
			system("cls");
				/*LopSV *lsv = new LopSV;
				lsv->nhap_LSV();
				if(DSLSV.them_LSV(lsv)) cout<<"\nThem lop sv thanh cong";
				else cout<<"\nLop sv da day";*/
			system("pause");
		}else if(chon==10){
			system("cls");
				//DSLSV.xuatDS_LSV();
				Action thaoTac = XUAT;
				//init_View(); DSLSV.chon_LSV(thaoTac); getch();
			system("pause");
		}else if (chon == 11)
		{
			MonHoc monHoc;
	
			int checkTrung=0;
			do{
				monHoc.NhapThongTin(0,"");
				dsmh.them_MH(dsmh.getRoot(), monHoc, checkTrung );
				
				if(checkTrung==1){
					cout<<"\nMon hoc da ton tai";
					system("pause");
				}
				
			}while(checkTrung == 1);
		

		}
		else if (chon == 12)
		{	system("cls");
			/*int dem = dsmh.DemSoNodeTrongCay(dsmh.getRoot());
				MonHoc* arr = new MonHoc[dem];
				int n = 0;
				
				dsmh.ChuyenCayVaoMangConTro(arr, dsmh.getRoot(), n);
				dsmh.XuatDanhSachMonHoc(arr, n);
				cout << "\nXUAT THANH CONG! "<<n;
				
				delete [] arr; system("pause");*/
				Action thaoTac = XUAT;
				//init_View(); dsmh.chon_MH(thaoTac);
				
				getch();
				
		}
		else if (chon == 13)
		{
			string str;

			cin.ignore();
			cout << "\nNhap Ma Mon Hoc can hieu chinh: ";
			getline(cin, str);

			int checkTrung = 2;
			MonHoc MH;
			MH.NhapThongTin(1,str);
			
			dsmh.them_MH(dsmh.getRoot(), MH, checkTrung);
			
			if(checkTrung==0) cout<<"\nSua mon hoc thanh cong";
			else cout<"\nSua mon hoc that bai";
		}
		else if (chon == 14)
		{
			system("cls");
			/*cin.ignore();
			string key;
			cout << "\nNhap ten mon hoc: ";
			getline(cin, key);
			dsmh.setRoot(dsmh.XoaTheoMaMonHoc(dsmh.getRoot(), key));*/
			
			//init_View(); dsmh.chon_MH(XOA); getch();
		}
		else if(chon==15){
			system("cls"); 
			cin.ignore();
			string maSV;
			cout<<"\nNhap ma sv: ";
			getline(cin, maSV);
			int coSV = DSLSV.timSV_LSV(maSV);
			
			if(coSV!=-1){
				int maLopTC;
				cout<<"\nNhap ma lop tc: ";	
				cin>>maLopTC;
				
				int viTri = DSLTC.tim_LTC(maLopTC);
				
				if(viTri!=-1){
					
					bool daDK = DSLTC.checkDK_LTC(viTri, maSV);
					
					if(daDK==false){
						cout<<"\nChua dk";
						SVDangKy SV(maSV);
						
						NodeDK * dk = new NodeDK(SV);
						if(dk==NULL) cout<<"\nk the cap phat";
						
						DSLTC.dangKy_LTC(viTri, dk);
					}else cout<<"\nSV da dang ky ltc";
					
				}else cout<<"\nKhong tim thay lop tc";
				
			}else cout<<"\nKhong tim thay sv";
			system("pause");
		}else if(chon==16){
			system("cls");
			int maLopTC;
			cout<<"\nNhap ma lop tc: ";	
			cin>>maLopTC;
				
				int viTri = DSLTC.tim_LTC(maLopTC);
			if(viTri!=-1){

					DSLTC.xuatDSDK_LTC(viTri);
					
				}else cout<<"\nKhong tim thay lop tc";
			system("pause");
		}else if(chon==17){
			system("cls");
			char c;cout<<"\nNhan enter de xac nhan ";
			c= _getch();
			if(c==ENTER)
				DSLTC.huyLopDS_LTC();
			system("pause");
		}else if(chon==18){
			system("cls");
			int maLopTC;
			cout<<"\nNhap ma lop tc: ";	
			cin>>maLopTC;
				
			int viTri = DSLTC.tim_LTC(maLopTC);
			if(viTri!=-1){

					DSLTC.nhapDiem_LTC(viTri);
					
				}else cout<<"\nKhong tim thay lop tc";
			system("pause");
		}else if(chon==19){
			system("cls");
			/*int maLopTC;
			cout<<"\nNhap ma lop tc: ";	
			cin>>maLopTC;
				
			int viTri = DSLTC.tim_LTC(maLopTC);
			if(viTri!=-1){

					DSLTC.xuatDiem_LTC(viTri);
					
				}else cout<<"\nKhong tim thay lop tc";
			system("pause");*/
			//init_View();  DSLTC.chon_LTC(dsmh, DSLSV, DIEM); getch();
		}
	}
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
				
				DSLTC.chon_LTC(DSMH, DSLSV, thaoTac, menuButton); //cout<<"\ntt ltc "<<indexMenu;
				
			}else if(menuButton[indexMenu]->getId() == "SV"){
				
				oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSLSV.chon_LSV(thaoTac, menuButton); //cout<<"\ntt lsv "<<indexMenu;
				
			}else if(menuButton[indexMenu]->getId() == "MH"){
				
				oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSMH.chon_MH(thaoTac, menuButton); //cout<<"\ntt mh "<<indexMenu;
				
			}else if(menuButton[indexMenu]->getId() == "DIEM"){
				
				thaoTac = DIEM; oldIndexMenu = indexMenu; indexMenu = -1;
				
				DSLTC.chon_LTC(DSMH, DSLSV, thaoTac, menuButton); //cout<<"\ntt dk "<<indexMenu;
			}else if(indexMenu == nMenuButton -1 ){
				exitProgram = isExit();
				if(!exitProgram){
					indexMenu = -1; continue;
				}
			}
			
			
			clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);	
		}
	
		if(exitProgram){
			int isConfirmed = MessageBox(
						NULL,
						"BAN CO MUON LUU DU LIEU VAO FILE",
						"THONG BAO",
						MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
					);
												    		
			switch(isConfirmed){
				case IDCANCEL:{
					DSMH.writeDataDS_MH();
					DSLTC.writeDataDS_DK();
					DSLTC.writeDataDS_LTC();
					DSLSV.writeDataDS_LSV();
					DSLSV.writeDataDS_SV();
					freeArrButton(menuButton, nMenuButton);
					return;
					break;
				}
												
				case IDOK: default:{
					DSMH.writeDataDS_MH(PATH_MH.c_str());
					DSLTC.writeDataDS_DK(PATH_DK.c_str());
					DSLTC.writeDataDS_LTC(PATH_LTC.c_str());
					DSLSV.writeDataDS_LSV(PATH_LSV.c_str());
					DSLSV.writeDataDS_SV(PATH_SV.c_str());
					
					DSMH.writeDataDS_MH();
					DSLTC.writeDataDS_DK();
					DSLTC.writeDataDS_LTC();
					DSLSV.writeDataDS_LSV();
					DSLSV.writeDataDS_SV();	
					freeArrButton(menuButton, nMenuButton);
					return;			
					break;
				}
			}
		}
	}
	
}



