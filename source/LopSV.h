#pragma once
#include "Const.h"

class LopSV{
private:
	string maLop;
	string tenLop;
	DSSV dssv;
public:
	LopSV();
	~LopSV();
	
	void setMaLop(string maLop);
	void setTenLop(string tenLop);
	void setDS_SV(NodeSV *head);
	
	string getMaLop();
	string getTenLop();
	NodeSV* getDS_SV();
	
	void nhap_LSV(){
		cin.ignore();
		cout<<"\nNhap ma lop: ";
		getline(cin, maLop);
		cout<<"\nNhap ten lop: ";
		getline(cin, tenLop);
	}
	
	void xuat_LSV(){
		cout<<"\nNhap ma lop: "<<maLop;
		cout<<"\nNhap ten lop: "<<tenLop;
	}
};

class DSLopSV{
private:
	LopSV *dslsv[MAX_LOPSV];
	int n;
public:
	DSLopSV();
	~DSLopSV();
	
	void setN(int n);
	int getN();
	
	void writeFile_LSV(LopSV *LSV,ofstream &fileOut);
	void writeFileDS_LSV();
	
	bool isNull_LSV();
	bool isFull_LSV();
	int them_LSV(LopSV *LSV);
	int tim_LSV(string maLop);
	
	void xuatDS_LSV(){
		if(n==0) cout<<"\n dslsv rong";
		for(int i=0; i<n; i++){
			dslsv[i]->xuat_LSV();
		}
	}
};


/*
** ================ Lop sinh vien ================
*/

LopSV::LopSV(){
	maLop = "";
	tenLop = "";
	dssv.setHead_DSSV(NULL);
}

LopSV::~LopSV(){
	
}

void LopSV::setMaLop(string maLop){
	this->maLop = maLop;
}

void LopSV::setTenLop(string tenLop){
	this->tenLop = tenLop;
}

void LopSV::setDS_SV(NodeSV *head){
	this->dssv.setHead_DSSV(head);
}
	
string LopSV::getMaLop(){
	return this->maLop;
}

string LopSV::getTenLop(){
	return this->tenLop;
}

NodeSV* LopSV::getDS_SV(){
	return this->dssv.getHead_DSSV();
}

/*
** ================ Danh sach lop sinh vien ================
*/

DSLopSV::DSLopSV(){
	n = 0;
}

DSLopSV::~DSLopSV(){
	
}

void DSLopSV::setN(int n){
	this->n = n;
}

int DSLopSV::getN(){
	return this->n;
}

bool DSLopSV::isNull_LSV(){
	return this->n == 0;
}

bool DSLopSV::isFull_LSV(){
	return this->n == MAX_LOPSV;
}

int DSLopSV::them_LSV(LopSV *LSV){
	if(isFull_LSV()) return -1;
	
	this->dslsv[this->n++] = LSV;
	return 1;
}

int DSLopSV::tim_LSV(string maLop){
	if(isNull_LSV()) return -1;
	
	return -1;
}

void DSLopSV::writeFile_LSV(LopSV *LSV,ofstream &fileOut){
	char temp = ',';
	fileOut << LSV->getMaLop();
	fileOut << temp;
	fileOut << LSV->getTenLop();
	fileOut << temp;
	fileOut << "\n";
}

void DSLopSV::writeFileDS_LSV(){
	ofstream fileOut;
	fileOut.open("data\\DSLSV.txt", ios::out);
	if (fileOut.is_open()) {
		for (int i = 0; i < this->n; i++)	{
				writeFile_LSV(this->dslsv[i], fileOut);
			}
		
	}
	fileOut.close();
}
