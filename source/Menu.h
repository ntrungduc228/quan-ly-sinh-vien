#pragma once

#include "MonHoc.h"
#include "SinhVien.h"
#include "SVDangKy.h"
#include "LopTC.h"
#include "LopSV.h"
#include "View.h"

void menu(DSSV &ds, DSLopTC &DSLTC,DSLopSV &DSLSV, TREE &dsmh){
	int chon;
	while(true){
		system("cls");
		
		cout<<"\n1. Nhap sinh vien (done)";
		cout<<"\n2. Xuat ds sinh vien (done)";
		cout<<"\n3. Sua sinh vien (done)";
		cout<<"\n4. Xoa sinh vien (done)";
		cout<<"\n5. Them lop tc (done)";
		cout<<"\n6. Xuat DS lop tc (done)";
		cout<<"\n7. Sua lop tc (done)";
		cout<<"\n8. Xoa lop tc (done)";
		cout<<"\n9. Them lop hoc (done)";
		cout<<"\n10. Xuat ds lop hoc (done)";
		
		cout<<"\n\n11. Them mon hoc (done)";
		cout<<"\n12. In ds mon hoc (done)";
		cout<<"\n13. Sua mon hoc (done)";
		cout<<"\n14. Xoa mon hoc (done)";
		
		cout<<"\n15. Dang ky lop tc";
		cout<<"\n16. In ds dang ky trong 1 lop tc";
		cout<<"\n17. Huy lop tc";
		cout<<"\n18. Nhap diem 1 lop tc";
		cout<<"\n19. Xuat diem 1 lop tc";
		
		cout<<"\n\n20. Lay data lop SV";
		cout<<"\n21. Lay data lop TC";
		cout<<"\n22. Lay data mon hoc";
		cout<<"\n23. Lay data ds Sv";
		cout<<"\n24. Lay data ds dk";
		cout<<"\n0. thoat (tu dong luu data vo file)";
		
		cout<<"\n\nNhap lua chon: ";
		cin>>chon;
		
		if(chon==0){
			//DSSV.writeFileDS_SV();
			
			for(int i=0; i<DSLSV.getN(); i++)
				if(DSLSV.getLopSV_LSV(i)->getDS_SV().isNULL_SV()!=true)
					DSLSV.getLopSV_LSV(i)->getDS_SV().writeDataDS_SV();
			
			DSLTC.writeDataDS_LTC();
			DSLSV.writeDataDS_LSV();
			if(ds.getHead_DSSV() == NULL) cout<<" dssv null";
			else cout<<"dssv not null";
			
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
				DSLSV.getLopSV_LSV(viTri)->getDS_SV().xuatDS_SV();
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
			string maSV;
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
				}else cout<<"\nKo tim thay lop sv";
			
			system("pause");
		}else if(chon==5){
			system("cls");
			LopTC *ltc = new LopTC;
			int maLop;
			
			do{
				maLop = ltc->taoMaLop_LTC();
			}while(DSLTC.checkTrungMaLop_LTC(maLop));
			
			ltc->setMaLopTC(maLop);
			
			ltc->nhap_LTC();
			
			if(DSLTC.them_LTC(ltc)!=0) cout<<"\nThem lop tc thanh cong";
			else cout<<"\nDS ltc da day";
			
			system("pause");
		}else if(chon==6){
			system("cls");
			cout<<"\n ds lop tc";
			DSLTC.xuatDS_LTC();
			system("pause");
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
				LopSV *lsv = new LopSV;
				lsv->nhap_LSV();
				if(DSLSV.them_LSV(lsv)) cout<<"\nThem lop sv thanh cong";
				else cout<<"\nLop sv da day";
			system("pause");
		}else if(chon==10){
			system("cls");
				DSLSV.xuatDS_LSV();
			system("pause");
		}else if (chon == 11)
		{
			MonHoc monHoc;

			monHoc.NhapThongTinMonHoc();

			if (dsmh.KiemTraTrungTheoMaMonHoc(dsmh.getData(), monHoc.getMaMH()))
			{
				cout << "\nNhap lai";
			}
			else
			{
				dsmh.setData(dsmh.ThemVaoDanhSachMonHoc(dsmh.getData(), new NodeMonHoc(monHoc)));
			}

		}
		else if (chon == 12)
		{
			NodeMonHoc* arr[100];
			int n = 0;

			dsmh.ChuyenCayVaoMangConTro(arr, dsmh.getData(), n);
			dsmh.XuatDanhSachMonHoc(arr, n);
			cout << "\nXUAT THANH CONG!";
			system("pause");
		}
		else if (chon == 13)
		{
			string str;

			cin.ignore();
			cout << "\nNhap Ma Mon Hoc can hieu chinh: ";
			getline(cin, str);

			dsmh.HieuChinhThongTinMonHoc(str);
		}
		else if (chon == 14)
		{
			cin.ignore();
			string key;
			cout << "\nNhap ten mon hoc: ";
			getline(cin, key);
			dsmh.setData(dsmh.XoaTheoTenMonHoc(dsmh.getData(), key));
		}
		
	}
}
