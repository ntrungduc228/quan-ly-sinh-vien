#pragma once

#include "Const.h"

class MonHoc{
private:
	string maMH;
	string tenMH;
	int STCLT;
	int STCTH;
public:
	MonHoc();
	~MonHoc();
	
	
	
	void setMaMH(string maMH);
	void setTenMH(string tenMH);
	void setSTCLT(int STCLT);
	void setSTCTH(int STCTH);
	
	string getMaMH();
	string getTenMH();
	int getSTCLT();
	int getSTCTH();
	
	void NhapThongTin()
	{
		cin.ignore();

		string temp;

		cout << "Nhap ma mon hoc: ";
		getline(cin, temp);
		this->maMH = temp;

		cout << "Nhap ten mon hoc: ";
		getline(cin, temp);
		this->tenMH = temp;

		int stclt;

		cout << "Nhap so tin chi Ly Thuyet: ";
		cin >> stclt;
		this->STCLT = stclt;

		int stcth;

		cout << "Nhap so tin chi Thuc Hanh; ";
		cin >> stcth;
		this->STCTH = stcth;
	}
	
	
	
};

class NodeMonHoc{
private:
	MonHoc data;
	NodeMonHoc *left;
	NodeMonHoc *right;	
public:
	NodeMonHoc();
	~NodeMonHoc();
	
	NodeMonHoc(MonHoc MH){
		this->data = MH;
		left = NULL;
		right = NULL;
	}
	
	void setData(MonHoc data){
		this->data = data;
	}
	
	void setLeft(NodeMonHoc *left){
		this->left = left;
	}
	
	void setRight(NodeMonHoc *right){
		this->right = right;
	}
	
	MonHoc getData_MH(){
		return this->data;
	}
	
	NodeMonHoc *& getLeft(){
		return this->left;
	}
	
	NodeMonHoc *& getRight(){
		return this->right;
	}
	
};

class TREE{
private:
	NodeMonHoc *root;
public:
	TREE();
	~TREE();
	
	NodeMonHoc *&getRoot(){
		return this->root;
	}
	
	void them_MH(NodeMonHoc *&root, MonHoc MH){
		if(root == NULL){
			
			NodeMonHoc *p = new NodeMonHoc(MH);
			root = p;
			
		}else{
			
			if (MH.getMaMH() < root->getData_MH().getMaMH())	{
				them_MH(root->getLeft(), MH);
			} else if (MH.getMaMH() > root->getData_MH().getMaMH())	{
				them_MH(root->getRight(), MH);
			}
			
		}
	}
	
		void XuatDanhSachMonHoc(NodeMonHoc* root)
		{
			if(root!=NULL)
			{
			 	XuatDanhSachMonHoc(root->getLeft());
				cout << "Ma mon hoc: " << root->getData_MH().getMaMH() << endl;
				cout << "Ten mon hoc: " << root->getData_MH().getTenMH() << endl;
				cout << "So luong tin chi ly thuyet: " << root->getData_MH().getSTCLT() << endl;
				cout << "So luong tin chi thuc hanh: " << root->getData_MH().getSTCTH() << endl;
				XuatDanhSachMonHoc(root->getRight());
			}
		}
	
};

/*
** ================ Mon hoc ================
*/

MonHoc::MonHoc(){
	maMH = "";
	tenMH = "";
	STCLT = 0;
	STCTH = 0;
}

MonHoc::~MonHoc(){
	
}

void MonHoc::setMaMH(string maMH){
	this->maMH = maMH;
}

void MonHoc::setTenMH(string tenMH){
	this->tenMH = tenMH;
}

void MonHoc::setSTCLT(int STCLT){
	this->STCLT = STCLT;
}

void MonHoc::setSTCTH(int STCTH){
	this->STCTH = STCTH;
}

string MonHoc::getMaMH(){
	return this->maMH;
}

string MonHoc::getTenMH(){
	return this->tenMH;
}

int MonHoc::getSTCLT(){
	return this->STCLT;
}

int MonHoc::getSTCTH(){
	return this->STCTH;
}

/*
** ================ Danh sach mon hoc ================
*/

NodeMonHoc::NodeMonHoc(){
	left = NULL;
	right = NULL;
}

NodeMonHoc::~NodeMonHoc(){
	delete left;
	delete right;
}

/*
** ================ TREE ================
*/


TREE::TREE(){
	root = NULL;
}

TREE::~TREE(){
	delete root;
}

