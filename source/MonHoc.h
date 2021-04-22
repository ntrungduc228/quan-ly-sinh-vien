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

	void NhapThongTinMonHoc()
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

	MonHoc(const MonHoc& monHoc)
	{
		this->maMH = monHoc.maMH;
		this->tenMH = monHoc.tenMH;
		this->STCLT = monHoc.STCLT;
		this->STCTH = monHoc.STCTH;
	}

};

class NodeMonHoc{
private:
	MonHoc monHoc;
	NodeMonHoc *left;
	NodeMonHoc *right;	
public:
	NodeMonHoc();
	~NodeMonHoc();
	
	void setLeft(NodeMonHoc* node)
	{
		this->left = node;
	}

	void setRight(NodeMonHoc* node)
	{
		cout << "Trong day ne 11111: " << (getRight() == NULL) << endl;
		this->right = node;
		cout << "Trong day ne 22222: " << (getRight() == NULL) << endl;
	}

	NodeMonHoc* getLeft()
	{
		return left;
	}

	NodeMonHoc* getRight()
	{
		return right;
	}

	void setMaMH(string maMH)
	{
		monHoc.setMaMH(maMH);
	}

	void setTenMH(string tenMH)
	{
		monHoc.setMaMH(tenMH);
	}

	void setSTCLT(int STCLT)
	{
		monHoc.setSTCLT(STCLT);
	}

	void setSTCTH(int STCTH)
	{
		monHoc.setSTCTH(STCTH);
	}

	string getTenMH()
	{
		return monHoc.getTenMH();
	}

	string getMaMH()
	{
		return monHoc.getMaMH();
	}

	int getSTCLT()
	{
		return monHoc.getSTCLT();
	}

	int getSTCTH()
	{
		return monHoc.getSTCTH();
	}

	NodeMonHoc(MonHoc monHoc)
	{
		this->monHoc = monHoc;
		this->left = NULL;
		this->right = NULL;
	}
};

class TREE{
private:
	NodeMonHoc *root;
public:
	TREE();
	~TREE();
	
	void writeData_MH(MonHoc monHoc, ofstream &fileOut);
	void writeDataDS_MH();
	
	void setData(NodeMonHoc* root)
	{
		this->root = root;
	}

	NodeMonHoc* getData()
	{
		return root;
	}
	
	
	NodeMonHoc* ThemVaoDanhSachMonHoc(NodeMonHoc* root, NodeMonHoc* new_node)
	{
		if (root == NULL)
		{
			cout << "them thanh cong";
			return new_node;
		}

		if (stricmp(new_node->getMaMH().c_str(), root->getMaMH().c_str()) < 0)
			root->setLeft(ThemVaoDanhSachMonHoc(root->getLeft(), new_node));
		else if (stricmp(new_node->getMaMH().c_str(), root->getMaMH().c_str()) > 0)
			root->setRight(ThemVaoDanhSachMonHoc(root->getRight(), new_node));

		return root;
	}

	NodeMonHoc* minValueNode(NodeMonHoc* root)
	{
		NodeMonHoc* current = root;

		while (current && current->getLeft() != NULL)
			current = current->getLeft();

		return current;
	}

	NodeMonHoc* XoaTheoTenMonHoc(NodeMonHoc* root, string key)
	{

		if (root == NULL)
			return root;

		if (stricmp(key.c_str(), root->getTenMH().c_str()) < 0)
			root->setLeft(XoaTheoTenMonHoc(root->getLeft(), key));
		else if (stricmp(key.c_str(), root->getTenMH().c_str()) > 0)
			root->setRight(XoaTheoTenMonHoc(root->getRight(), key));
		else {
			if (root->getLeft() == NULL)
			{
				NodeMonHoc* temp = root->getRight();

				delete root;

				return temp;
			}
			else if (root->getRight() == NULL)
			{
				NodeMonHoc* temp = root->getLeft();

				delete root;

				return temp;
			}

			NodeMonHoc* temp = minValueNode(root->getRight());

			root->setTenMH(temp->getTenMH());
			root->setMaMH(temp->getMaMH());
			root->setSTCLT(temp->getSTCLT());
			root->setSTCTH(temp->getSTCTH());

			root->setRight(XoaTheoTenMonHoc(root->getRight(), temp->getTenMH()));
		}

		return root;
	}


	//	void XuatDanhSachMonHocA(NodeMonHoc* root)
	//	{
	//		if(root!=NULL)
	//		{
	//		 	XuatDanhSachMonHoc(root->getLeft());
	//			cout << "Ma mon hoc: " << root->getMaMH() << endl;
	//			cout << "Ten mon hoc: " << root->getTenMH() << endl;
	//			cout << "So luong tin chi ly thuyet: " << root->getSTCLT() << endl;
	//			cout << "So luong tin chi thuc hanh: " << root->getSTCTH() << endl;
	//			XuatDanhSachMonHoc(root->getRight());
	//		}
	//	}

	void XuatDanhSachMonHoc(NodeMonHoc* arr[], int n)
	{
		SapXepTheoTen(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << "Ma mon hoc: " << arr[i]->getMaMH() << endl;
			cout << "Ten mon hoc: " << arr[i]->getTenMH() << endl;
			cout << "So luong tin chi ly thuyet: " << arr[i]->getSTCLT() << endl;
			cout << "So luong tin chi thuc hanh: " << arr[i]->getSTCTH() << endl;
		}
	}

	NodeMonHoc* KiemTraTrungTheoMaMonHoc(NodeMonHoc* root, string key)
	{
		if (root == NULL)
			return NULL;

		if (root->getMaMH() == key)
		{
			return root;
		}

		KiemTraTrungTheoMaMonHoc(root->getLeft(), key);
		KiemTraTrungTheoMaMonHoc(root->getRight(), key);

		return NULL;
	}

	void HieuChinhThongTinMonHoc(string key)
	{
		NodeMonHoc* monHoc = KiemTraTrungTheoMaMonHoc(root, key);

		if (monHoc)
		{
			string str;

			cout << "\nNhap ten Mon Hoc: ";
			getline(cin, str);
			monHoc->setTenMH(str);

			int num;

			cout << "\nNhap so Tin Chi Ly Thuyet: ";
			cin >> num;
			monHoc->setSTCLT(num);

			cout << "\nNhap so Tin Chi Thuc Hanh: ";
			cin >> num;
			monHoc->setSTCTH(num);
		}
		else
		{
			cout << "\nMa Mon Hoc khong ton tai!";
		}
	}

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
				if (arr[i]->getTenMH()[0] > arr[j]->getTenMH()[0])
				{
					Swap(arr[i], arr[j]);
				}
			}
		}
	}
	
};

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



NodeMonHoc::NodeMonHoc(){
	left = NULL;
	right = NULL;
}

NodeMonHoc::~NodeMonHoc(){
	delete left;
	delete right;
}

TREE::TREE(){
	root = NULL;
}

TREE::~TREE(){
	delete root;
}

/*void writeData_MH(TREE DSMH, ofstream &fileOut){
	char temp = ',';
	if (DSMH != NULL)
	{
		writeData_MH(DSMH->getLeft(), fileOut);
		fileOut << DSMH->getData().getMaMH();
		fileOut << temp;
		fileOut << DSMH->getData().getTenMH();
		fileOut << temp;
		fileOut << DSMH->getData().getSTCLT();
		fileOut << temp;
		fileOut << DSMH->getData().getSTCTH();
		fileOut << '\n';
		writeData_MH(DSMH->getRight(), fileOut);
	}
}

void writeDataDS_MH(){
	ofstream fileOut;
	fileOut.open("data\\DSMH.txt", ios::out);
	if (fileOut.is_open())
	{
		if(this->root!=NULL)
		writeData_MH(this, fileOut);
	}
	fileOut.close();
}*/



