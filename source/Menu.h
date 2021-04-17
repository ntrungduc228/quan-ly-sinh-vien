#pragma once

#include "MonHoc.h"
#include "SinhVien.h"
#include "SVDangKy.h"
#include "LopTC.h"
#include "LopSV.h"
#include "View.h"

void menu(DSSV &DSSV, DSLopTC &DSLTC,DSLopSV &DSLSV){
	int chon;
	while(true){
		system("cls");
		
		cout<<"\n1. Nhap sinh vien ";
		cout<<"\n2. Xuat ds sinh vien (done)";
		cout<<"\n3. Sua sinh vien (done)";
		cout<<"\n4. Xoa sinh vien (done)";
		cout<<"\n5. Them lop tc (done)";
		cout<<"\n6. Xuat DS lop tc (done)";
		cout<<"\n7. Sua lop tc (done)";
		cout<<"\n8. Xoa lop tc (done)";
		cout<<"\n9. Them lop hoc (done)";
		cout<<"\n10. Xuat ds lop hoc (done)";
		cout<<"\n. Dang ky lop tc";
		cout<<"\n. In ds dang ky trong 1 lop tc";
		cout<<"\n. Huy lop tc";
		cout<<"\n. Nhap diem 1 lop tc";
		cout<<"\n. Xuat diem 1 lop tc";
		
		cout<<"\n\n. Them mon hoc";
		cout<<"\n. In ds mon hoc";
		cout<<"\n. Sua mon hoc";
		cout<<"\n. Xoa mon hoc";
		
		cout<<"\n\n. Lay data lop SV";
		cout<<"\n. Lay data lop TC";
		cout<<"\n. Lay data mon hoc";
		cout<<"\n. Lay data ds Sv";
		cout<<"\n. Lay data ds dk";
		cout<<"\n0. thoat (tu dong luu data vo file)";
		
		cout<<"\n\nNhap lua chon: ";
		cin>>chon;
		
		if(chon==0){
			DSSV.writeFileDS_SV();
			DSLTC.writeFileDS_LTC();
			DSLSV.writeFileDS_LSV();
			if(DSSV.getHead_DSSV() == NULL) cout<<" dssv null";
			else cout<<"dssv not null";
			
			exit(0);
		}else if(chon==1){
			cin.ignore();
			while(true){
				system("cls");
				SinhVien sv;
				sv.nhap_SV("");
				if(sv.getMaSV()=="") break;
				NodeSV *SV = new NodeSV(sv);
				int viTri = DSSV.timViTriThem_SV(SV);
				cout<<"\nVi tri: "<<viTri;
				DSSV.them_SV(SV,viTri);
			}
			
			cout<<"\nok";
			system("pause");
		}else if(chon==2){
			system("cls");
			DSSV.xuatDS_SV();
			system("pause");
		}else if(chon==3){
			system("cls");
			string maSV;
			cin.ignore();
			cout<<"\nNhap ma sv can sua: ";
			getline(cin,maSV);
			int vt = DSSV.tim_SV(maSV);
			if(DSSV.tim_SV(maSV)!=-1){
				
				if(DSSV.sua_SV(maSV)!=-1) cout<<"\nSua thanh cong sv";
			}else cout<<"\nko tim thay sv";
			system("pause");
		}
		else if(chon==4){
			system("cls");
			string maSV;
			cin.ignore();
			cout<<"\nNhap ma sv can xoa: ";
			getline(cin,maSV);
			int vt = DSSV.tim_SV(maSV);
			if(DSSV.tim_SV(maSV)!=-1){
				
				if(DSSV.xoa_SV(maSV)!=-1)	cout<<"\Xoa thanh cong sv";
			}else cout<<"\nko tim thay sv";
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
		}
		
	}
}
