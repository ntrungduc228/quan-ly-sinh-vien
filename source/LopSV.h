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
	
	
	string getMaLop();
	string getTenLop();
	DSSV getDS_SV();
	void setDS_SV(DSSV ds){
		this->dssv.setHead_DSSV(ds.getHead_DSSV());
		cout<<"\nXuat trong ham setDS_SV";
		this->dssv.xuatDS_SV();
		//this->dssv = ds;
	}
	
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
	LopSV *lopSV[MAX_LOPSV] ;
	int n;
public:
	DSLopSV();
	~DSLopSV();
	
	void setN(int n);
	int getN();
	
	LopSV *getLopSV_LSV(int viTri);
	
	void loadData_LSV(){
		ifstream fileIn; char temp;
		fileIn.open("data\\DSLSV.txt", ios::in);
		
		string str;
		while (!fileIn.eof())
		{
			
			getline(fileIn, str, ',');
			this->lopSV[this->n]->setMaLop(str);
			getline(fileIn, str, ',');
			this->lopSV[this->n]->setTenLop(str);
			fileIn.ignore();

			this->n++;
			if (fileIn.eof()) break;
		}
		fileIn.close();
	}
	
	void writeData_LSV(LopSV *LSV,ofstream &fileOut);
	void writeDataDS_LSV();
	
	bool isNull_LSV();
	bool isFull_LSV();
	int them_LSV(LopSV *LSV);
	int tim_LSV(string maLop);
	
	void xuatDS_LSV(){
		if(n==0) {
			cout<<"\n lopSV rong";
			return;
		}
		for(int i=0; i<n; i++){
			lopSV[i]->xuat_LSV();
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


	
string LopSV::getMaLop(){
	return this->maLop;
}

string LopSV::getTenLop(){
	return this->tenLop;
}

DSSV LopSV::getDS_SV(){
	return this->dssv;
}

/*
** ================ Danh sach lop sinh vien ================
*/

DSLopSV::DSLopSV(){
	n = 0;
	for(int i=0; i<MAX_LOPSV; i++) lopSV[i] = NULL;
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
	
	this->lopSV[this->n++] = LSV;
	return 1;
}

int DSLopSV::tim_LSV(string maLop){
	if(isNull_LSV()) return -1;
	
	for(int i=0; i<n; i++)
		if(this->lopSV[i]->getMaLop() == maLop ) return i;
	
	return -1;
}

void DSLopSV::writeData_LSV(LopSV *LSV,ofstream &fileOut){
	char temp = ',';
	fileOut << LSV->getMaLop();
	fileOut << temp;
	fileOut << LSV->getTenLop();
	fileOut << temp;
	fileOut << "\n";
}

void DSLopSV::writeDataDS_LSV(){
	ofstream fileOut;
	fileOut.open("data\\DSLSV.txt", ios::out);
	if (fileOut.is_open()) {
		for (int i = 0; i < this->n; i++)	{
				writeData_LSV(this->lopSV[i], fileOut);
			}
		
	}
	fileOut.close();
}

LopSV *DSLopSV::getLopSV_LSV(int viTri){
		if(isNull_LSV()) return NULL;
		
		for(int i=0; i<n; i++)
			if(i==viTri)
				return this->lopSV[i];	
}
