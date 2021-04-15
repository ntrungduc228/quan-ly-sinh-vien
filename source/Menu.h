#pragma once

#include "MonHoc.h"
#include "SinhVien.h"
#include "SVDangKy.h"
#include "LopTC.h"
#include "LopSV.h"
#include "View.h"

void menu(DSSV &dssv){
	int chon;
	while(true){
		system("cls");
		
		cout<<"\n1. Nhap sinh vien";
		cout<<"\n2. Xuat sinh vien";
		cout<<"\n3. Sua sinh vien";
		cout<<"\n4. Xoa sinh vien";
		cout<<"\n0. thoat";
		
		cout<<"\n\nNhap lua chon: ";
		cin>>chon;
		
		if(chon==0){
			dssv.writeFileDS_SV();
			if(dssv.getHead_DSSV() == NULL) cout<<"null";
			else cout<<"not null";
			exit(0);
		}else if(chon==1){
			cin.ignore();
			while(true){
				system("cls");
				SinhVien sv;
				sv.nhap_SV("");
				if(sv.getMaSV()=="") break;
				NodeSV *SV = new NodeSV(sv);
				int viTri = dssv.timViTriThem_SV(SV);
				cout<<"\nVi tri: "<<viTri;
				dssv.them_SV(SV,viTri);
			}
			
			cout<<"\nok";
			system("pause");
		}else if(chon==2){
			system("cls");
			dssv.xuatDS_SV();
			system("pause");
		}else if(chon==3){
			system("cls");
			string maSV;
			cin.ignore();
			cout<<"\nNhap ma sv can sua: ";
			getline(cin,maSV);
			int vt = dssv.tim_SV(maSV);
			if(dssv.tim_SV(maSV)!=-1){
				
				if(dssv.sua_SV(maSV)!=-1)	cout<<"\Sua thanh cong sv";
			}else cout<<"\nko tim thay sv";
			system("pause");
		}
		else if(chon==4){
			system("cls");
			string maSV;
			cin.ignore();
			cout<<"\nNhap ma sv can xoa: ";
			getline(cin,maSV);
			int vt = dssv.tim_SV(maSV);
			if(dssv.tim_SV(maSV)!=-1){
				
				if(dssv.xoa_SV(maSV)!=-1)	cout<<"\Xoa thanh cong sv";
			}else cout<<"\nko tim thay sv";
			system("pause");
		}
		
	}
}
