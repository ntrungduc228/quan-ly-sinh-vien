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
	
	void NhapThongTin(int chon, string str)
	{
		string temp;
		// nhap moi
		if(chon==0){
			cin.ignore();
			cout << "Nhap ma mon hoc: ";
			getline(cin, temp);
			this->maMH = temp;
		 } // chinh sua
		else if(chon==1){
			this->maMH = str;
		}
	

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
	
	MonHoc &getData_MH(){
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
	
	void setRoot(NodeMonHoc* root)
	{
		this->root = root;
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
				if(tempStr=="") break;
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
				
				if(checkTrung==0){
					checkTrung = 1;  return; // da trung mon hoc co san
				}else if(checkTrung==2){
					
					root->getData_MH().setMaMH(MH.getMaMH());
					root->getData_MH().setTenMH(MH.getTenMH());
					root->getData_MH().setSTCLT(MH.getSTCLT());
					root->getData_MH().setSTCTH(MH.getSTCTH());
					checkTrung = 0; return; // chinh sua mon hoc
				}
				
			
			}
			else if (MH.getMaMH() < root->getData_MH().getMaMH())  {
				them_MH(root->getLeft(), MH, checkTrung);
			} else if (MH.getMaMH() > root->getData_MH().getMaMH())	{
				them_MH(root->getRight(), MH, checkTrung);
			}
	
		}
	}
	
	/*	void XuatDanhSachMonHoc(NodeMonHoc* root)
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
		}*/
	
	NodeMonHoc* minValueNode(NodeMonHoc* root)
	{
		NodeMonHoc* current = root;

		while (current && current->getLeft() != NULL)
			current = current->getLeft();

		return current;
	}

	NodeMonHoc* XoaTheoMaMonHoc(NodeMonHoc* &root, string key)
	{
		if (root == NULL)
			return root;

		if (stricmp(key.c_str(), root->getData_MH().getMaMH().c_str()) < 0)
			root->setLeft(XoaTheoMaMonHoc(root->getLeft(), key));
		else if (stricmp(key.c_str(), root->getData_MH().getMaMH().c_str()) > 0)
			root->setRight(XoaTheoMaMonHoc(root->getRight(), key));
		else {
			if (root->getLeft() == NULL)
			{
				NodeMonHoc* temp = root->getRight();

				root->setRight(NULL);
				delete root;

				return temp;
			}
			else if (root->getRight() == NULL)
			{
				NodeMonHoc* temp = root->getLeft();

				root->setLeft(NULL);
				delete root;

				return temp;
			}

			NodeMonHoc* temp = minValueNode(root->getRight());

			root->getData_MH().setTenMH(temp->getData_MH().getTenMH());
			root->getData_MH().setMaMH(temp->getData_MH().getMaMH());
			root->getData_MH().setSTCLT(temp->getData_MH().getSTCLT());
			root->getData_MH().setSTCTH(temp->getData_MH().getSTCTH());

			root->setRight(XoaTheoMaMonHoc(root->getRight(), temp->getData_MH().getMaMH()));
		}

		return root;
	}
	
	void XuatDanhSachMonHoc(MonHoc arr[], int n)
	{
		if(n==0)
		{
			cout << "\nDanh sach rong";
		}
		
		SapXepTheoTen(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << "Ma mon hoc: " << arr[i].getMaMH() << endl;
			cout << "Ten mon hoc: " << arr[i].getTenMH() << endl;
			cout << "So luong tin chi ly thuyet: " << arr[i].getSTCLT() << endl;
			cout << "So luong tin chi thuc hanh: " << arr[i].getSTCTH() << endl;
		}
	}
	
		void ChuyenCayVaoMangConTro(MonHoc arr[], NodeMonHoc* root, int& n)
	{
		if (root != NULL)
		{
			ChuyenCayVaoMangConTro(arr, root->getLeft(), n);
			arr[n] = root->getData_MH();
			n++;
			ChuyenCayVaoMangConTro(arr, root->getRight(), n);
		}
	}
	
	int DemSoNodeTrongCay(NodeMonHoc *root)
	{
		if (root == NULL) {
			return 0;
		}
		
		return 1 + DemSoNodeTrongCay(root->getLeft()) +  DemSoNodeTrongCay(root->getRight());
	
	
	}
	
	void Swap(MonHoc& a, MonHoc& b)
	{
		MonHoc temp = a;

		a = b;
		b = temp;
	}

	void SapXepTheoTen(MonHoc arr[], int n)
	{

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i].getTenMH()[0] > arr[j].getTenMH()[0])
				{
					Swap(arr[i], arr[j]);
				}
			}
		}
	}
	
	void xuatDSTheoTrang_MH(){
		
	}
	
	void chon_MH(action hanhDong){
		if(this->root != NULL){
			
			if(hanhDong==xuat){
				
			}else if(hanhDong==xoa){
				
			}else if(hanhDong==sua){
				
			}
			
		}else{
			return;
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

