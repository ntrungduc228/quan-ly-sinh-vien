#pragma once
#include "Const.h"

class SVDangKy{
private:
	string maSV;
	float diem;
public:
	SVDangKy();
	~SVDangKy();
	
	SVDangKy(string maSV){
		this->maSV = maSV;
	}
	
	string getMaSV(){
		return this->getMaSV();
	}
	
	float getDiem(){
		return this->diem;
	}
	
	void setMaSV(string maSV){
		this->maSV = maSV;
	}
	
	void setDiem(float diem){
		this->diem = diem;
	}
	
	void xuat_DK(){
		cout<<"\nMa sv: "<<maSV;
		cout<<"\nDiem: "<<diem;
	}
};

class NodeDK{
private:
	SVDangKy data;
	NodeDK *next;
public:
	NodeDK();
	NodeDK(SVDangKy data){
		this->data = data;
		this->next = NULL;
	}
	~NodeDK();
	
	void setData(SVDangKy data){
		this->data = data;
	}
	
	void setNext_DK(NodeDK *DK){
		this->next = DK;
	}
	
	SVDangKy getData_DK(){
		return this->data;
	}
	
	NodeDK *&getNext_DK(){
		return this->next;
	}
	
	NodeDK *getNode_DK(){
		return this;
	}
	
};

class DSDK{
private:
	NodeDK *head;
public:
	DSDK();
	~DSDK();
	
	void setHead_DSDK(NodeDK *head);
	NodeDK* getHead_DSDK();
	
	void writeData_DK(){
		
	}
	
	
	void xuatDS_DK(){
		if(this->head == NULL) {
			cout<<"\nDS rong";
			return;
		}
		for(NodeDK *p = this->head; p != NULL ; p=(p->getNext_DK())){
			p->getData_DK().xuat_DK();
			//if(p->getNext_SV()==NULL) return;
		}
	}
	
	
	void themDau_DK(NodeDK *DK){
		DK->setNext_DK(this->head);
		this->head = DK->getNode_DK();
	}
	
	int timViTriThem_DK(NodeDK *DK){
		int viTri = 1;

		NodeDK* p = this->head;
		while (p != NULL && p->getData_DK().getMaSV() <= DK->getData_DK().getMaSV())	{
			if (p->getData_DK().getMaSV() == DK->getData_DK().getMaSV()) return -1;
			viTri++;
			p = p->getNext_DK();
		}
		return viTri;
	}
	
	void them_DK(NodeDK *DK){
		int viTriThem = this->timViTriThem_DK(DK);
	
		if(this->head == NULL || viTriThem == 1){
			themDau_DK(DK); return;
		}
		
		int viTri = 1;
		NodeDK *p;
		for(p = this->head; p->getNext_DK()!= NULL && viTri < viTriThem-1; viTri++,p=p->getNext_DK());
		
		DK->setNext_DK(p->getNext_DK());
		p->setNext_DK(DK);
		
		cout<<"\nthem thanh cong";
	}
	
	bool checkSV_DK(string maSV){
		
		for(NodeDK *p = this->head; p != NULL; p=p->getNext_DK()){
			if(p->getData_DK().getMaSV() == maSV) return true;
		}
		
		return false;
	}
	
};

/*
** ================ SV dang ky ================
*/

SVDangKy::SVDangKy(){
	maSV = "";
	diem = 0;
}

SVDangKy::~SVDangKy(){
	
}

/*
** ================ Node SV dang ky ================
*/

NodeDK::NodeDK(){
	next = NULL;
}

NodeDK::~NodeDK(){
	delete next;
}

/*
** ================ DS SV dang ky ================
*/

DSDK::DSDK(){
	head = NULL;
}

DSDK::~DSDK(){
	delete head;
}

void DSDK::setHead_DSDK(NodeDK *head){
	this->head = head;
}

NodeDK* DSDK::getHead_DSDK(){
	return this->head;
}
