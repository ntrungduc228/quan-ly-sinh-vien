#pragma once
#include"Const.h"

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
	
	void nhap_SV(string maSV){
			string temp;
		if(maSV!="") {
			this->maSV = maSV;
		}else{
			cout<<"\nNhap mssv: ";
			getline(cin,temp);
	
			this->maSV = temp;
			if(temp == "") return;
		}
	
		
		cout<<"\nNhap ho: ";
		getline(cin,temp);
		ho = temp;
		cout<<"\nNhap ten: ";
		getline(cin,temp);
		ten = temp;
		
		cout<<"\nNhap phai: ";
		getline(cin,temp);
		phai = temp;
		
		cout<<"\nNhap sdt: ";
		getline(cin,temp);
		sdt = temp;
		
		
		maSV = "";
	}
	
	void xuat_SV(){
		cout<<"\n\nHo ten: "<<ho<<" "<<ten;
		cout<<"\nMSSV: "<<maSV;
		cout<<"\nPhai: "<<phai;
		cout<<"\nSDT: "<<sdt;
		cout<<"\nMa lop: "<<maLop;

	}
	
	void sua(SinhVien sv){
		this->ten = sv.ten;
		this->ho = sv.ho;
		this->phai = sv.phai;
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
	NodeSV*& getNext_SV();
	NodeSV* getNode_SV();
		
};

class DSSV{
private:
	NodeSV *head;
public:
	DSSV();
	~DSSV();
	
	void setHead_DSSV(NodeSV *head);
	NodeSV*& getHead_DSSV();
	
	bool isNULL_SV();
	
	void loadFile_SV();
	void writeData_SV(SinhVien SV, ofstream &fileOut);
	void writeDataDS_SV();
	
	int tim_SV(string maSV);
	int timViTriThem_SV(NodeSV *SV);
	void themDau_SV(NodeSV * SV);
	void them_SV(NodeSV *SV);
	int xoa_SV(string maSV);
	
		
	int sua_SV(string maSV){
		if(this->head == NULL){
			cout<<"\nDS rong"; return-1;
		}
		for(NodeSV *p = this->head; p!=NULL ; p = p->getNext_SV())
			if(p->getData_SV().getMaSV() == maSV) {
				SinhVien sv;
				sv.nhap_SV(maSV);
				sv.setMaLop(p->getData_SV().getMaLop());
				p->setData_SV(sv);
				return 1;
			}
		return -1;
	}
	
	void xuatDS_SV(){
		if(this->head == NULL) {
			cout<<"\nDS rong";
			return;
		}
		for(NodeSV *p = this->head; p != NULL ; p=(p->getNext_SV())){
			p->getData_SV().xuat_SV();
			//if(p->getNext_SV()==NULL) return;
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
	delete next;
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

NodeSV* &NodeSV::getNext_SV(){
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
	delete head;
}

void DSSV::setHead_DSSV(NodeSV *head){
	this->head = head;
}

NodeSV* &DSSV::getHead_DSSV(){
	return this->head;
}

bool DSSV::isNULL_SV(){
	return this->head == NULL;
}

void DSSV::writeData_SV(SinhVien SV, ofstream &fileOut){
	
	char temp = ',';
	fileOut << SV.getMaSV();
	fileOut << temp;
	fileOut << SV.getHo();
	fileOut << temp;
	fileOut << SV.getTen();
	fileOut << temp;
	fileOut << SV.getPhai();
	fileOut << temp;
	fileOut << SV.getSDT();
	fileOut << temp;
	fileOut << SV.getMaLop();
	fileOut << "\n";
	
}

void DSSV::writeDataDS_SV(){
	ofstream fileOut(PATH_SAVE_SV,ios::out);
	if(fileOut.is_open()){
		for(NodeSV *p = this->head; p!=NULL; p=(p->getNext_SV())){
			writeData_SV(p->getData_SV(),fileOut);
		}
	}
	fileOut.close();
}


void DSSV::themDau_SV(NodeSV * SV){
	SV->setNext_SV(this->head);
	this->head = SV->getNode_SV();
}

int DSSV::tim_SV(string maSV){
	int viTri = 1;
	NodeSV *p;
	for(p = this->head; p!=NULL ; viTri++, p = p->getNext_SV())
		if(p->getData_SV().getMaSV() == maSV) return viTri;
		
	return -1;
}

int DSSV::timViTriThem_SV( NodeSV *SV){
	int viTri = 1;
		NodeSV *p = this->head;
		while(p!=NULL && p->getData_SV().getTen() <= SV->getData_SV().getTen() ) {
			
			if (p->getData_SV().getTen() == SV->getData_SV().getTen()) {
				while (p!=NULL && p->getData_SV().getHo() < SV->getData_SV().getHo()) {

					viTri++;
					p=(p->getNext_SV());
				}
				return viTri;
			}
			viTri++;
			p=(p->getNext_SV());
			
		}
	
	return viTri;
}

void DSSV::them_SV(NodeSV *SV){
	
	int viTriThem = this->timViTriThem_SV(SV);
	
	if(this->head == NULL || viTriThem == 1){
		themDau_SV(SV); return;
	}
	
	int viTri = 1;
	NodeSV *p;
	for(p = this->head; p->getNext_SV()!= NULL && viTri < viTriThem-1; viTri++,p=p->getNext_SV());
	
	SV->setNext_SV(p->getNext_SV());
	p->setNext_SV(SV);
	
	cout<<"\nthem thanh cong";
	
}

int DSSV::xoa_SV(string maSV){
	
	if(this->head == NULL) return -1;
	NodeSV *p,*q;
	if(this->head->getData_SV().getMaSV() == maSV){
		p = this->head;
		this->head = p->getNext_SV();
		//delete p; 
		p->setNext_SV(NULL);
		p->~NodeSV();
		return 1;
	}
	
	for(p=this->head; p->getNext_SV()!=NULL && p->getNext_SV()->getData_SV().getMaSV() != maSV ; p=p->getNext_SV());
		if(p->getNext_SV()->getData_SV().getMaSV() == maSV){
			
			q = p->getNext_SV();
			p->setNext_SV(q->getNext_SV());
			//delete q; 
			q->setNext_SV(NULL);
			q->~NodeSV();
			return 1;
		}
	
	
	return 0;
}
