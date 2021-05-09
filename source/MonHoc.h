#pragma once

#include "Const.h"
#include "Validate.h"

class MonHoc{
private:
	string maMH;
	string tenMH;
	int STCLT;
	int STCTH;
public:
	MonHoc();
	~MonHoc(){}
	
	
	
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
	
	void xuatDS1Trang_MH(MonHoc arrMH[], int batDau, int ketThuc, action thaoTac, Table newTable){
		
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		 
		int STT = batDau - 1;
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		
		string strSTT;	
		
		soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack); 
		//cout<<"\nbat dau: "<<batDau<<" "<<ketThuc<<" "<<soDong;
		for(int i = batDau; i < soDong; i++){ 
		
			// in ra chuoi rong cac dong con thua
			if(i >= ketThuc){
				y +=  rowTableHeight;
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); 	x += newTable.getCols(0)->getWidth();
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(1)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(3)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); 
				
				x =  tableLeft;
				continue;
			}
			
			++STT;
  			y += rowTableHeight;
			//strSTT = convertIntToString(STT+1);
			strSTT = convertIntToString(i+1);
			
			if(thaoTac == XUAT)
				// xoa du lieu cu
				//setbkcolor(clyellow);
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
				
				// xuat du lieu moi
				outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
				x += newTable.getCols(0)->getWidth();
				
				// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
				
				// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(1)->getWidth()/2  - textwidth(arrMH[i].getMaMH().c_str())/2, 
						y, 
						arrMH[i].getMaMH().c_str()
					);
					
				x += newTable.getCols(1)->getWidth();
				
				// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
				
				// xuat du lieu moi
				outtextxy(
						x + 20,
						y, 
						arrMH[i].getTenMH().c_str()
					);				
				x += newTable.getCols(2)->getWidth();
				
				// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
				
				// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(3)->getWidth()/2  - textwidth(convertIntToString(arrMH[i].getSTCLT()).c_str())/2,
						y, 
						convertIntToString(arrMH[i].getSTCLT()).c_str()
					);
				x += newTable.getCols(3)->getWidth();
				
				
				// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
				
				// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(4)->getWidth()/2  - textwidth(convertIntToString(arrMH[i].getSTCTH()).c_str())/2,
				 		y,
						convertIntToString(arrMH[i].getSTCTH()).c_str()
					);
			
			x = tableLeft ;
		
		}
		
		
	}
	
	void locDS_MH(string content, MonHoc arrMHFilter[], int &nFilter,MonHoc arrMH[], int n, int &tongSoTrang){
		if(!content.empty()){
			for(int i=0; i<n; i++){
				if(arrMH[i].getTenMH().find(content) != string::npos){
					arrMHFilter[nFilter++] = arrMH[i];
				}
			}
			
			
		}else {
			for(int i=0; i<n; i++){
				arrMHFilter[nFilter++] = arrMH[i];
			}
		}
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
	}
	
	
	void xuatDSTheoTrang_MH(MonHoc arrMH[], int tongSoDong, action thaoTac){
		
		MonHoc *arrMHFilter = new MonHoc [tongSoDong];
		for(int i=0; i<tongSoDong; i++) arrMHFilter[i] = arrMH[i];
		int nFilter = tongSoDong;
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Table newTable = table_MH();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_MH(arrMH, batDau, ketThuc, thaoTac, newTable);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ten mon hoc:" ,"", INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		int x,y;
		
		while(true){
			delay(0.0000);
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
            		
            		ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : tongSoDong;
					
					ketThuc = (ketThuc > tongSoDong) ? batDau + tongSoDong % batDau : ketThuc;
				}
									
				xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, thaoTac, newTable);
				inTrang(trangHienTai, tongSoTrang);
			}
			
			if(kbhit()){
				char ch = getch();
				newInput.xuLyNhapTen_MH((int)ch);
				newInput.draw();
				nFilter = 0;
				locDS_MH(newInput.getContent(), arrMHFilter, nFilter, arrMH, tongSoDong, tongSoTrang);
				/*cout<<"\n=================\n";
				for(int i=0; i<nFilter; i++){
					cout<<"\n"<<arrMHFilter[i].getMaMH()<<" "<<arrMHFilter[i].getTenMH()<<" "<<arrMHFilter[i].getSTCLT()<<" "<<arrMHFilter[i].getSTCTH();
				}*/
				
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, thaoTac, newTable);
				inTrang(trangHienTai, tongSoTrang);
			}
			
		}
		
		newTable.freeTable();
		delete[] arrMHFilter;
	}
	
	void chon_MH( action thaoTac){
		if(this->root != NULL){
			
			int soLuong = DemSoNodeTrongCay(this->root);
			MonHoc *arrMH = new MonHoc[soLuong];
			soLuong = 0;
			ChuyenCayVaoMangConTro(arrMH, this->root, soLuong);
			SapXepTheoTen(arrMH, soLuong);
			
			//this->XuatDanhSachMonHoc(arrMH, soLuong);
			Label title(
					"IN DANH SACH MON HOC",
					LABEL_X,
					LABEL_Y,
					LABEL_X + LABEL_WIDTH,
					LABEL_Y + LABEL_HEIGHT,
					clgreen,
					cllightgreen,
					cllightwhite
				);
				
			title.printLabel(
						/*"Ma lop",
						"D19CQCN03-N",
						"Nien khoa",
						"2019",
						"Hoc ky",
						"1",
						"Nhom",
						"1"*/
					);
			
			if(thaoTac == XUAT){
				xuatDSTheoTrang_MH(arrMH, soLuong, XUAT);
					
			}else if(thaoTac == XOA){
				
			}else if(thaoTac == SUA){
				
			}
			
			delete[] arrMH;
			
		}else{
			MessageBox(
		        NULL,
		        "Khong co mon hoc nao !!!",
		        "THONG BAO",
		        MB_ICONWARNING | MB_OK
    		);
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

