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
	
	void loadDataDS_MH(){
		ifstream fileIn; char temp; string tempStr; int tempInt;
		fileIn.open("data\\DSMH.txt", ios::in);
		if (fileIn.is_open())	{
			//if(DSMH==NULL)
			while (!fileIn.eof())
			{
				MonHoc MH;
				//fileIn.ignore();
				if(root!=NULL)
				fileIn.ignore();
				getline(fileIn, tempStr, ',');
				MH.setMaMH(tempStr);
				getline(fileIn, tempStr, ',');
				MH.setTenMH(tempStr);
				fileIn >> tempInt;
				MH.setSTCLT(tempInt);
				fileIn >> temp; //  doc dau , giua 2 so nguyen -> tuong tu cho cac ham load data khac
				fileIn >> tempInt;
				MH.setSTCTH(tempInt);
		
				them_MH(root, MH, tempInt);
				if (fileIn.eof()) break;
			}
			
		}
		
		fileIn.close();
	}
	
	void writeData_MH(NodeMonHoc *root, ofstream &fileOut){
		char temp = ',';
		if (root != NULL)	{
			writeData_MH(root->getLeft(), fileOut);
			fileOut << root->getData_MH().getMaMH();
			fileOut << temp;
			fileOut << root->getData_MH().getTenMH();
			fileOut << temp;
			fileOut << root->getData_MH().getSTCLT();
			fileOut << temp;
			fileOut << root->getData_MH().getSTCTH();
			fileOut << '\n';
			writeData_MH(root->getRight(), fileOut);
		}
	}
	
	void writeDataDS_MH(){
		ofstream fileOut;
		fileOut.open(PATH_SAVE_MH, ios::out);
		if (fileOut.is_open())	{
			if(this->root!=NULL)
			writeData_MH(root, fileOut);
		}
		fileOut.close();
	}
	
	void them_MH(NodeMonHoc *&root, MonHoc MH, int &checkTrung){
		if(root == NULL){
			
			NodeMonHoc *p = new NodeMonHoc(MH);
			root = p; checkTrung = 0;
			
		}else{
			
			if(MH.getMaMH() == root->getData_MH().getMaMH()){
				checkTrung = 1;  return; // da trung mon hoc co san
			}
			else if (MH.getMaMH() < root->getData_MH().getMaMH())  {
				them_MH(root->getLeft(), MH, checkTrung);
			} else if (MH.getMaMH() > root->getData_MH().getMaMH())	{
				them_MH(root->getRight(), MH, checkTrung);
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
	
	/*void XuatDanhSachMonHoc(NodeMonHoc* arr[], int n)
	{
		SapXepTheoTen(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << "Ma mon hoc: " << arr[i]->getData_MH().getMaMH() << endl;
			cout << "Ten mon hoc: " << arr[i]->getData_MH().getTenMH() << endl;
			cout << "So luong tin chi ly thuyet: " << arr[i]->getData_MH().getSTCLT() << endl;
			cout << "So luong tin chi thuc hanh: " << arr[i]->getData_MH().getSTCTH() << endl;
		}
	}*/
	
	void ChuyenCayVaoMangConTro(NodeMonHoc* arr[], NodeMonHoc* root, int& n)
	{
		if (root != NULL)
		{
			ChuyenCayVaoMangConTro(arr, root->getLeft(), n);
			arr[n] = root;
			n++;
			ChuyenCayVaoMangConTro(arr, root->getRight(), n);
		}
	}

	void Swap(NodeMonHoc*& a, NodeMonHoc*& b)
	{
		NodeMonHoc* temp = a;

		a = b;
		b = temp;
	}

	void SapXepTheoTen(NodeMonHoc* arr[], int n)
	{

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i]->getData_MH().getTenMH()[0] > arr[j]->getData_MH().getTenMH()[0])
				{
					Swap(arr[i], arr[j]);
				}
			}
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

