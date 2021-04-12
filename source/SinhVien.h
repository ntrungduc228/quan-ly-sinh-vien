#pragma once
#include"Const.h"
#include<string>
using namespace std;

class SinhVien{
private:
	string maSV;
	string ten;
	string ho;
	string phai;
	string sdt;
	string maLop;	
public:
	SinhVien();
	~SinhVien();
	
	void setMaSV(string maSV);
	void setTen(string ten);
	void setHo(string ho);
	void setPhai(string phai);
	void setSDT(string sdt);
	void setMaLop(string maLop);
	
	string getMaSV();
	string getTen();
	string getHo();
	string getPhai();
	string getSDT();
	string getMaLop();
	
	void nhap_SV(){
		string temp;
		cout<<"\nNhap ho: ";
		getline(cin,temp);
		ho = temp;
		cout<<"\nNhap ten: ";
		getline(cin,temp);
		ten = temp;
		cout<<"\nNhap mssv: ";
		getline(cin,temp);
		maSV = temp;
		cout<<"\nNhap phai: ";
		getline(cin,temp);
		phai = temp;
	}
	
	void xuat_SV(){
		cout<<"\nHo ten: "<<ho<<" "<<ten;
	}
};

class NodeSV{
private:
	SinhVien data;
	NodeSV *next;
public:
	NodeSV();
	NodeSV(SinhVien data);
	~NodeSV();
	
	void setData_SV(SinhVien data);
	void setNext_SV(NodeSV *next);
	void setNode_SV(NodeSV *SV);
	
	SinhVien getData_SV();
	NodeSV* getNext_SV();
	NodeSV* getNode_SV();
		
};

class DSSV{
private:
	NodeSV *head;
public:
	DSSV();
	~DSSV();
	
	void setHead_DSSV(NodeSV *head);
	NodeSV* getHead_DSSV();
	
	int timViTri_SV(NodeSV *SV);
	void themDau_SV(NodeSV * SV);
	void them_SV(NodeSV *SV, int viTriThem);
	
	void writeFile_SV(SinhVien SV, ofstream &fileOut);
	void writeFileDS_SV();
	
	void xuatDS_SV(){
		if(this->head == NULL) {
			cout<<"\nDS rong";
			return;
		}
		for(NodeSV *k = this->head; k->getNode_SV() != NULL ; k=(k->getNext_SV())){
			k->getData_SV().xuat_SV();
			if(k->getNext_SV()==NULL) return;
		}
	}
};

/*
** ================ Sinh vien ================
*/

SinhVien::SinhVien(){
	phai = "nam";
}

SinhVien::~SinhVien(){
	
}

void SinhVien::setMaSV(string maSV){
	this->maSV = maSV;
}

void SinhVien::setTen(string ten){
	this->ten = ten;
}

void SinhVien::setHo(string ho){
	this->ho = ho;
}

void SinhVien::setPhai(string phai){
	this->phai = phai;
}

void SinhVien::setSDT(string sdt){
	this->sdt = sdt;
}

void SinhVien::setMaLop(string maLop){
	this->maLop = maLop;
}
	
string SinhVien::getMaSV(){
	return this->maSV;
}

string SinhVien::getTen(){
	return this->ten;
}

string SinhVien::getHo(){
	return this->ho;
}

string SinhVien::getPhai(){
	return this->phai;
}

string SinhVien::getSDT(){
	return this->sdt;
}

string SinhVien::getMaLop(){
	return this->maLop;
}

/*
** ================ NodeSV ================
*/

NodeSV::NodeSV(){
	this->next = NULL;
}

NodeSV::NodeSV(SinhVien data){
	this->data = data;
	this->next = NULL; 
}


NodeSV::~NodeSV(){
	
}

void NodeSV::setData_SV(SinhVien data){
	this->data = data;
}

void NodeSV::setNext_SV(NodeSV *next){
	this->next = next;
}
	
SinhVien NodeSV::getData_SV(){
	return this->data;
}

NodeSV* NodeSV::getNext_SV(){
	return this->next;
}

void NodeSV::setNode_SV(NodeSV*SV){
	this->data = SV->data;
	this->next = SV->next;
}

NodeSV* NodeSV::getNode_SV(){
	return this;
}

/*
** ================ DSSV ================
*/

DSSV::DSSV(){
	this->head = NULL;
}

DSSV::~DSSV(){
	
}

void DSSV::setHead_DSSV(NodeSV *head){
	this->head = head;
}

NodeSV* DSSV::getHead_DSSV(){
	return this->head;
}

void DSSV::themDau_SV(NodeSV * SV){
	SV->setNext_SV(this->head);
	this->head = SV->getNode_SV();
}

int DSSV::timViTri_SV( NodeSV *SV){
	int viTri = 1;
		NodeSV *p = this->head;
		while(p!=NULL && p->getData_SV().getTen() <= SV->getData_SV().getTen() ) {
			
			if (p->getData_SV().getTen() == SV->getData_SV().getTen()) {
				while (p!=NULL && p->getData_SV().getHo() < SV->getData_SV().getHo()) {

					viTri++;
					p->setNode_SV(p->getNext_SV());
				}
				return viTri;
			}
			viTri++;
			p=(p->getNext_SV());
			
		}
	
	return viTri;
}

void DSSV::them_SV(NodeSV *SV, int viTriThem){
	
	if(this->head == NULL || viTriThem == 1){
		themDau_SV(SV); return;
	}
	
	int viTri = 0;
	NodeSV *p;
	for(p = this->head; p->getNext_SV()!= NULL && viTri < viTriThem-1; viTri++,p->setNode_SV(p->getNext_SV()));
	
	SV->setNext_SV(p->getNext_SV());
	p->setNext_SV(SV);
	
}

void DSSV::writeFile_SV(SinhVien SV, ofstream &fileOut){
	
	char temp = ',';
	fileOut<<SV.getTen();
	fileOut<<temp;
	fileOut<<"\n";
	
}

void DSSV::writeFileDS_SV(){
	ofstream fileOut("data\\DSSV.txt",ios::out);
	if(fileOut.is_open()){
		for(NodeSV *p = this->head; p!=NULL; p=(p->getNext_SV())){
			writeFile_SV(p->getData_SV(),fileOut);
		}
	}
	fileOut.close();
}
