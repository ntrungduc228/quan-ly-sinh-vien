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
		cout<<"\n0. thoat";
		
		cout<<"\n\nNhap lua chon: ";
		cin>>chon;
		
		if(chon==0){
			exit(0);
		}else if(chon==1){
			system("cls");
			cin.ignore();
			SinhVien sv;
			sv.nhap_SV();
			NodeSV *SV = new NodeSV(sv);
			/*int viTri = dssv.timViTri_SV(SV);
			cout<<"\nVi tri: "<<viTri;
			dssv.them_SV(SV,viTri);*/
			dssv.themDau_SV(SV);
			cout<<"\nok";
			system("pause");
		}else if(chon==2){
			system("cls");
			dssv.xuatDS_SV();
			system("pause");
		}
		
	}
}
