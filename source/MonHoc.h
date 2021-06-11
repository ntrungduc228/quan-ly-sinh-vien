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
	
	void setData(MonHoc data){
		this->maMH = data.maMH;
		this->tenMH = data.tenMH;
		this->STCLT = data.STCLT;
		this->STCTH = data.STCTH;
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
	TREE(){
		root = NULL;
	}
	~TREE(){
		//delete root; 
		cout<<"\nXoa root cmnr";
	}
	
	void freeDS_MH(NodeMonHoc *&root){
		delete root;
	}
	
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
	
	void them_MH(NodeMonHoc *&root, MonHoc &MH, int &checkTrung){
		if(root == NULL){
			
			NodeMonHoc *p = new NodeMonHoc(MH);
			root = p; checkTrung = 0;
			
		}else{
			
			if(MH.getMaMH() == root->getData_MH().getMaMH()){
				
				if(checkTrung==0){
					checkTrung = 1;  MH = root->getData_MH();
					return; // da trung mon hoc co san
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

		if (strcmp(key.c_str(), root->getData_MH().getMaMH().c_str()) < 0)
			root->setLeft(XoaTheoMaMonHoc(root->getLeft(), key));
		else if (strcmp(key.c_str(), root->getData_MH().getMaMH().c_str()) > 0)
			root->setRight(XoaTheoMaMonHoc(root->getRight(), key));
		else {
			if (root->getLeft() == NULL)
			{
				NodeMonHoc* temp = root->getRight();

				root->setRight(NULL);
				delete root;
				MessageBox(
			        NULL,
			        "XOA MON HOC THANH CONG !!!",
			        "THONG BAO",
			        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
	    		);
				return temp;
			}
			else if (root->getRight() == NULL)
			{
				NodeMonHoc* temp = root->getLeft();

				root->setLeft(NULL);
				delete root;
				MessageBox(
				        NULL,
				        "XOA MON HOC THANH CONG !!!",
				        "THONG BAO",
				        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
		    		);

				return temp;
			}

			NodeMonHoc* temp = minValueNode(root->getRight());

			root->getData_MH().setTenMH(temp->getData_MH().getTenMH());
			root->getData_MH().setMaMH(temp->getData_MH().getMaMH());
			root->getData_MH().setSTCLT(temp->getData_MH().getSTCLT());
			root->getData_MH().setSTCTH(temp->getData_MH().getSTCTH());

			root->setRight(XoaTheoMaMonHoc(root->getRight(), temp->getData_MH().getMaMH()));
			
			// thong bao xoa mon hoc thanh cong
			MessageBox(
		        NULL,
		        "XOA MON HOC THANH CONG !!!",
		        "THONG BAO",
		        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
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
	
	void ChuyenCayVaoMang(MonHoc arr[], NodeMonHoc* root, int& n)
	{
		if (root != NULL)
		{
			ChuyenCayVaoMang(arr, root->getLeft(), n); 
			if(root != NULL)
				arr[n] = root->getData_MH();  
			else cout<<"\nroot null";
			n++;
			ChuyenCayVaoMang(arr, root->getRight(), n);
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
	
	void xoaTrongMang_MH(MonHoc arr[], int &n, int vt){
		for(int i=vt+1; i<n; i++)
			arr[i-1] = arr[i];
		
		n--;	
	}
	
	void xuatDS1Trang_MH(MonHoc arrMH[], int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac){
		
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		 
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT;	
		
		// Bat truong hop nhap o input ko tim thay (Trung thac mac)
		// de in khoang trang xoa toan bo du lieu cu sau khi filter content tu input ko tim thay
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else{
			int soDongTrong = MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
				soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + soDongTrong;
		}
		
		setbkcolor(cllightwhite); setcolor(clblack); 
		//cout<<"\nbat dau: "<<batDau<<" "<<ketThuc<<" "<<soDong;
		 
		
		for(int i = batDau; i < soDong; i++){ 
			
			setbkcolor(cllightwhite); setcolor(clblack); 
			yBtn += rowTableHeight;
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
				); x += newTable.getCols(4)->getWidth();
				
				
				View view("",x,yBtn, x+newTable.getCols(5)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
				view.draw();
				
				x =  tableLeft;
				continue;
			}
			
			
  			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
			
				// xoa du lieu cu
				//setbkcolor(clyellow);
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(0)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
		//	if(thaoTac == XUAT)	
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
				x += newTable.getCols(4)->getWidth();
			
			if(thaoTac != CHON){
				// ve button sua 
				if(editButton[i] == NULL)
					{
						editButton[i] = new Button(
												"Sua",
												strSTT, 
												x+3, 
												yBtn+3, 
												x+checkBoxButtonWidth,
												yBtn-3+checkBoxButtonHeight, 
												claqua, 
												cllightblue, 
												clblack
											);
						//cout<<"\nDa cap phat edit "<<i;
					}
					editButton[i]->draw();
					x += checkBoxButtonWidth + buttonActionSpace;
					
				
					// ve button xoa 
				if(deleteButton[i] == NULL)	
					{
						deleteButton[i] = new Button(
												"Xoa",
												strSTT, 
												x+3, 
												yBtn+3, 
												x+checkBoxButtonWidth,
												yBtn-3+checkBoxButtonHeight, 
												cllightred, 
												clred, 
												cllightwhite 
											);
						//cout<<"\nDa cap phat delete "<<i;
					}
					deleteButton[i]->draw();
			}else{
				// ve button chon
				if(editButton[i] == NULL)
					{
						editButton[i] = new Button(
												"Chon",
												strSTT, 
												x+15, 
												yBtn+3, 
												x+45+checkBoxButtonWidth,
												yBtn-3+checkBoxButtonHeight, 
												claqua, 
												cllightblue, 
												clblack
											);
						//cout<<"\nDa cap phat edit "<<i;
					}
					editButton[i]->draw();
					x += checkBoxButtonWidth + buttonActionSpace;
			}
					
				
			x = tableLeft ;
		
		}
		
	
	}
	
	void locDS_MH(string content, MonHoc arrMHFilter[], int &nFilter, MonHoc arrMH[], int n, int &tongSoTrang){
		// reset so mon hoc loc ra duoc
		nFilter = 0;
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
	
	
	void xuatDSTheoTrang_MH123(MonHoc *&arrMH, int tongSoDong, int &viTriChon, Action &thaoTac){
		
		MonHoc *arrMHFilter = new MonHoc [tongSoDong];
		for(int i=0; i<tongSoDong; i++) arrMHFilter[i] = arrMH[i];
		int nFilter = tongSoDong;
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *editButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		Table newTable = table_MH();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_MH(arrMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ten mon hoc:" ,"", MAX_TENMH, TEXT, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnThem("THEM","them",400, 80, 400 + buttonWidth, 120);
		btnThem.draw();
		
		int x,y;
		int indexInput = -1; // Dung de giu vi tri input vua click
		
		while(true){
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	// is clicked button Sua || Xoa
            	for(int i=batDau; i<ketThuc; i++){
					if(editButton[i]->isClicked(x,y)){
						cout<<"\n"<<i<<" is clicked "<<editButton[i]->getText();
						MessageBox(
					        NULL,
					        "Ban muon sua mon hoc",
					        "THONG BAO",
					        MB_ICONWARNING | MB_OK
			    		);
					}else if(deleteButton[i]->isClicked(x,y)){
						cout<<"\n"<<i<<" is clicked "<<deleteButton[i]->getText();
						int isConfirmed = MessageBox(
										        NULL,
										        "BAN CO CHAC CHAN MUON XOA MON HOC NAY",
										        "THONG BAO",
										        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
								    		);
						switch(isConfirmed){
							case IDCANCEL:{
								break;
							}
							case IDOK: default:{
								string tempMaMH = arrMHFilter[i].getMaMH();
								for(int vt=0; vt<tongSoDong; vt++){
									if(arrMH[vt].getMaMH() == tempMaMH){
										viTriChon = vt; break;  
									}
								}
								
								thaoTac = XOA;
								newTable.freeTable();
								delete[] arrMHFilter;
								freeArrButton(editButton, nFilter);
								freeArrButton(deleteButton, nFilter);
								return; 	
							}
						}
					}
					
				}
            	
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
				
				
				xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
				
				//	Button THEM
				if(btnThem.isClicked(x,y))
				{
					drawFrame(500, 150, 500 + 600, 200+400);
					
					Input *input[4];
					int nInput = 4; 
					
					// WIDTD input=400;
					input[0] = new Input("", "Ma mon hoc", "0", MAX_MAMH, NON_SPACE, 650, 200, 650 + 400, 200 + INPUT_HEIGHT);
					input[1] = new Input("", "Ten mon hoc", "1", MAX_TENMH, TEXT ,650, 200 + INPUT_HEIGHT + 20, 650 + 400, 200 + INPUT_HEIGHT * 2 + 20);
					input[2] = new Input("", "So TC ly thuyet", "2", INT_MAX, NUMBER ,650, (200 + INPUT_HEIGHT * 2) + (20 * 2), 650 + 400, (200 + INPUT_HEIGHT * 3) + (20 * 2));
					input[3] = new Input("","So TC thuc hanh", "3", INT_MAX, NUMBER ,650, (200 + INPUT_HEIGHT * 3) + (20 * 3), 650 + 400, (200 + INPUT_HEIGHT * 4) + (20 * 3));
					
					Button *btn[2];
					int nButton = 2 ;
					
					btn[0]= new Button("THEM","T", 650, (200 + INPUT_HEIGHT * 5) + (20 * 5), 650 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), clgray);
					btn[0]->draw();
					
					btn[1]= new Button("HUY","H", 900, (200 + INPUT_HEIGHT * 5) + (20 * 5), 900 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), cllightred, clred, cllightwhite );
					btn[1]->draw();
					
					for(int i = 0; i < nInput; i++)
					{
						input[i]->draw();
					}
					
					string idButton;
					bool exitLoop = false;
					
					// Bang input
					while(!exitLoop)
					{
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							
							// Kiem tra click EditText
							for(int i = 0; i < nInput; i++)
							{
								if(input[i]->isClicked(x,y))
								{
									cout << "Clck ne";
									input[i]->requestFocus();																		
									input[i]->draw();	
									
									int oldIndexInput = indexInput;	
													
									if (oldIndexInput != -1) {
										input[oldIndexInput]->draw();
									}
											
									// focusEditText
									indexInput = i;									
																										
									break;		
								}
							}
							
							// Kiem tra click Button
							for(int i=0; i < nButton; i++)
							{
							
								if(btn[i]->isClicked(x,y))
								{
									cout<<"\n"<<i;
									idButton = btn[i]->getId();
									//	cout << "\n222222222222222222=========== "<<idButton;
										cout <<btn[i]->getId();
									if(idButton == "T" && duyetInputs(input, nInput))
									{
										cout << "THEMMMMMMMM NEEEEEEEEEEe\n";
										
										clearRegion(500, 150, 500 + 600, 200+400);
										
										MonHoc monHoc;
																			
										monHoc.setMaMH(input[0]->getContent());
										monHoc.setTenMH(input[1]->getContent());
										monHoc.setSTCLT(atoi(input[2]->getContent().c_str()));
										monHoc.setSTCTH(atoi(input[3]->getContent().c_str()));
										
										
														
										delete[] arrMH;
										arrMH = new MonHoc;
										arrMH->setData(monHoc); thaoTac = THEM;
										
										cout<<"\n"<<arrMH->getMaMH()<<" "<<arrMH->getTenMH()<<" "<< arrMH->getSTCLT();
										cout<<"\n=====================================";
										
										
										// Free
										for(int i = 0 ; i < nInput; i++)
										{
											delete input[i];
										}			
										
										for(int i=0;i<nButton; i++)
										{
											delete btn[i];
										}
										freeArrButton(editButton, nFilter);
										freeArrButton(deleteButton, nFilter);
										newTable.freeTable();
										
										return;
		
									}else if(idButton == "H")
									{
										cout << "HUYYYYYYYYY NEEEEEEE\n";
										
										exitLoop=true;
										
										break;
									}
								}
							}																					
						}
						
					
						
						if(kbhit())
						{
							char character = getch();

							input[indexInput]->appendText(character);
							input[indexInput]->draw();
							
							if(duyetInputs(input, nInput))
							{
								btn[0]->setBackgroundColor(clgreen);
								btn[0]->draw();
							}else
							{
								btn[0]->setBackgroundColor(clgray);
								btn[0]->draw();
							}
						}
					}
					
				
					
					clearRegion(500, 150, 500 + 600, 200+400);
					newTable.drawTable(MAX_DONG_1_TRANG);
					xuatDS1Trang_MH(arrMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				}
			}
			
			// Filter by input
			if(kbhit()){
				freeArrButton(editButton, nFilter);
				freeArrButton(deleteButton, nFilter);
				char ch = getch();
				newInput.xuLyNhapTen_MH((int)ch);
				newInput.draw();
				locDS_MH(newInput.getContent(), arrMHFilter, nFilter, arrMH, tongSoDong, tongSoTrang);
				/*cout<<"\n=================\n";
				for(int i=0; i<nFilter; i++){
					cout<<"\n"<<arrMHFilter[i].getMaMH()<<" "<<arrMHFilter[i].getTenMH()<<" "<<arrMHFilter[i].getSTCLT()<<" "<<arrMHFilter[i].getSTCTH();
				}*/
				
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
			}
		
		}
		
		newTable.freeTable();
		delete[] arrMHFilter;
	}
	
	
	void xuatDSTheoTrang_MH(MonHoc *&arrMH, int tongSoDong, int &viTriChon, Action &thaoTac){
		
		MonHoc *arrMHFilter = new MonHoc [tongSoDong];
		for(int i=0; i<tongSoDong; i++) arrMHFilter[i] = arrMH[i];
		int nFilter = tongSoDong;
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *editButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		Table newTable = table_MH();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_MH(arrMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ten mon hoc:" ,"N", MAX_TENMH, TEXT, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnThem("THEM","them",400, 80, 400 + buttonWidth, 120);
		if(thaoTac != CHON)
			btnThem.draw();
		
		int x,y;
		int indexInput = -1; // Dung de giu vi tri input vua click
		
		while(true){
			// Click event change page output
			
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	if(newInput.isClicked(x,y)){
            		newInput.requestFocus();
            		newInput.draw();
				}
            	
            	// is clicked button Sua || Xoa
            	for(int i=batDau; i<ketThuc; i++){
            		if(thaoTac != CHON){
	            		if(editButton[i] != NULL && deleteButton[i] != NULL){
	            			if(editButton[i]->isClicked(x,y)){
								cout<<"\n"<<i<<" is clicked "<<editButton[i]->getText();
								string tempMaMH = arrMHFilter[i].getMaMH();
								// tim vi tri thuc(real) cua mon hoc can sua khi sau da filter trong mang ArrMH
								int vt=0;
								for(; vt<tongSoDong; vt++){
									if(arrMH[vt].getMaMH() == tempMaMH)	break;  
								}
								MessageBox(
							        NULL,
							        "Ban muon sua mon hoc",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK
					    		);
					    		
					    		MonHoc monHoc;
					    		monHoc.setMaMH(arrMH[vt].getMaMH());
					    		monHoc.setTenMH(arrMH[vt].getTenMH());
					    		monHoc.setSTCLT(arrMH[vt].getSTCLT());
					    		monHoc.setSTCTH(arrMH[vt].getSTCTH());
					    		
					    		thaoTac=SUA;
					    		formNhap_MH(monHoc, thaoTac);
					    		
					    		if(thaoTac != HUY)
					    		{
									delete []arrMH;
									delete []arrMHFilter;
					    			arrMH = new MonHoc(monHoc);
					    			return;
								}
					    		
					    		// Xuat lai cac trang
					    		newTable.drawTable(MAX_DONG_1_TRANG);					
								xuatDS1Trang_MH(arrMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					    		
							}else if(deleteButton[i]->isClicked(x,y)){
								cout<<"\n"<<i<<" is clicked "<<deleteButton[i]->getText();
								// tim vi tri thuc(real) cua mon hoc can xoa khi sau da filter trong mang ArrMH
										string tempMaMH = arrMHFilter[i].getMaMH();
										for(int vt=0; vt<tongSoDong; vt++){
											if(arrMH[vt].getMaMH() == tempMaMH){
												viTriChon = vt; break;  
											}
										}
								int isConfirmed = MessageBox(
												        NULL,
												        "BAN CO CHAC CHAN MUON XOA MON HOC NAY",
												        "THONG BAO",
												        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
										    		);
								switch(isConfirmed){
									case IDCANCEL:{
										viTriChon = 0;
										break;
									}
									case IDOK: default:{
										
										thaoTac = XOA;
										newTable.freeTable();
										delete[] arrMHFilter;
										freeArrButton(editButton, nFilter);
										freeArrButton(deleteButton, nFilter);
										return; 	
									}
								}
							}
						}
					} // thao tac != CHON
					else {
						if(editButton[i] != NULL){
							if(editButton[i]->isClicked(x,y)){
								// tim vi tri thuc(real) cua mon hoc can xoa khi sau da filter trong mang ArrMH
								string tempMaMH = arrMHFilter[i].getMaMH();
								for(int vt=0; vt<tongSoDong; vt++){
									if(arrMH[vt].getMaMH() == tempMaMH){
										viTriChon = vt; break;  
									}
								}
								
								newTable.freeTable();
								delete[] arrMHFilter;
								freeArrButton(editButton, nFilter);
								return;
								
							}
						}
					}
				}
            	
            	if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
            		
            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
            		
            		xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
				
				
				
				// y tuong la nhap click de doi mau Border
				//	Buntton THEM
				if(btnThem.isClicked(x,y))
				{
					
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					MonHoc monHoc;																					
					
					thaoTac = THEM;
					
					formNhap_MH(monHoc, thaoTac);
					
					if(thaoTac!=HUY)
					{
						
						delete[] arrMH;
						arrMH = new MonHoc;
						if(arrMH == NULL ) cout<<"\nNULL";
						else cout<<"\n not null";
						arrMH->setData(monHoc);
						cout << "\nTHAO TAC TRA VE: " << thaoTac << endl;
										
						cout<<"\n"<<arrMH->getMaMH()<<" "<<arrMH->getTenMH()<<" "<< arrMH->getSTCLT();
						
						delete [] arrMHFilter;			
						freeArrButton(editButton, nFilter);
						freeArrButton(deleteButton, nFilter);
						newTable.freeTable();
						cout<<"\n=====================================";
						return;
					}
																																																																																
					newTable.drawTable(MAX_DONG_1_TRANG);
					xuatDS1Trang_MH(arrMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				}
			}
			
			// Filter by input
			if(kbhit()){
				freeArrButton(editButton, nFilter);
				freeArrButton(deleteButton, nFilter);
				char ch = getch();
				//newInput.xuLyNhapTen_MH((int)ch);
				newInput.appendText(int(ch));
				newInput.requestFocus();
				newInput.draw();
				locDS_MH(newInput.getContent(), arrMHFilter, nFilter, arrMH, tongSoDong, tongSoTrang);
				/*cout<<"\n=================\n";
				for(int i=0; i<nFilter; i++){
					cout<<"\n"<<arrMHFilter[i].getMaMH()<<" "<<arrMHFilter[i].getTenMH()<<" "<<arrMHFilter[i].getSTCLT()<<" "<<arrMHFilter[i].getSTCTH();
				}*/
				
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				
				
				xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
			}
		
		}
		
		newTable.freeTable();
		delete[] arrMHFilter;
	}
	
	void formNhap_MH(MonHoc &monHoc, Action &thaoTac)
	{
		drawFrame(500, 150, 500 + 600, 200+400, "them mon hoc");
					Input *input[4];
					int nInput = 4; 
																		
					// WIDTD input=400;
					input[0] = new Input("", "Ma mon hoc ", "0", MAX_MAMH, NON_SPACE, 650, 200, 650 + 400, 200 + INPUT_HEIGHT);
												
					input[1] = new Input("", "Ten mon hoc ", "1", MAX_TENMH, TEXT ,650, 200 + INPUT_HEIGHT + 20, 650 + 400, 200 + INPUT_HEIGHT * 2 + 20);
					input[2] = new Input("", "So TC ly thuyet ", "2", 2, NUMBER ,650, (200 + INPUT_HEIGHT * 2) + (20 * 2), 650 + 400, (200 + INPUT_HEIGHT * 3) + (20 * 2));
					input[3] = new Input("","So TC thuc hanh ", "3", 2, NUMBER ,650, (200 + INPUT_HEIGHT * 3) + (20 * 3), 650 + 400, (200 + INPUT_HEIGHT * 4) + (20 * 3));
					
					Button *btn[2];
					int nButton = 2 ;
					
					if(thaoTac==THEM)
					{
						btn[0]= new Button("THEM","T", 650, (200 + INPUT_HEIGHT * 5) + (20 * 5), 650 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), clgray);	
					}else if(thaoTac==SUA)
					{
						
						btn[0]= new Button("LUU","S", 650, (200 + INPUT_HEIGHT * 5) + (20 * 5), 650 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), clgray);
						input[0]->setContent(monHoc.getMaMH());
						input[0]->setOffEnable();
					
						input[1]->setContent(monHoc.getTenMH());				
						input[2]->setContent(convertIntToString(monHoc.getSTCLT()));
						cout << "\nDay neeeee1111111";
						input[3]->setContent(convertIntToString(monHoc.getSTCTH()));
										
						cout << "\nDay neeeee22222";
										// draw input
						for(int i = 0; i < nInput; i++)
						{
								input[i]->draw();
						}
										
		//								getch();
						
					}
													
					btn[1]= new Button("HUY","H", 900, (200 + INPUT_HEIGHT * 5) + (20 * 5), 900 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), clgray);
					
					//newInput.setBorderColor(clblack);
					//newInput.draw();
																																
					for(int i = 0; i < nInput; i++)
					{
						input[i]->draw();
					}
					
					for(int i = 0; i < nButton; i++)
					{
						btn[i]->draw();
					}
					
					string idButton;
					bool exitLoop = false;
					int x,y;
					int indexInput=-1;
					// Bang input
					while(!exitLoop)
					{
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							
							// Kiem tra click EditText
							for(int i = 0; i < nInput; i++)
							{
								if(input[i]->isClicked(x,y) && input[i]->getEnable())
								{
									cout << "Clck ne";
									input[i]->requestFocus();																		
									input[i]->draw();
									
									int oldIndexInput = indexInput;	
													
									if (oldIndexInput != -1) {
										input[oldIndexInput]->draw();
									}
											
									// focusEditText
									indexInput = i;									
																										
									break;		
								}
							}
							
							// Kiem tra click Button
							for(int i=0; i < nButton; i++)
							{
							
								if(btn[i]->isClicked(x,y))
								{
									cout<<"\n"<<i;
									idButton = btn[i]->getId();
									//	cout << "\n222222222222222222=========== "<<idButton;
										cout <<btn[i]->getId();
									if(idButton == "T" && duyetInputs(input, nInput))
									{
										cout << "THEMMMMMMMM NEEEEEEEEEEe\n";
										
										//clearRegion(500, 150, 500 + 600, 200+400);
																																			
										monHoc.setMaMH(input[0]->getContent());
										monHoc.setTenMH(input[1]->getContent());
										monHoc.setSTCLT(atoi(input[2]->getContent().c_str()));
										monHoc.setSTCTH(atoi(input[3]->getContent().c_str()));
										
										// Khoi tao lai foucedId cua Ipnut cuoi cung duoc click
										input[indexInput]->initFocusedId();																							
										// Free
										for(int i = 0 ; i < nInput; i++)
										{
											delete input[i];
										}			
										
										for(int i=0;i<nButton; i++)
										{
											delete btn[i];
										}
										
										cout << "\nTTTTTTTTTTTTTTTTTTtt";
										
										return;
		
									}else if(idButton == "S")
									{
										//clearRegion(500, 150, 500 + 600, 200+400);
										monHoc.setMaMH(input[0]->getContent());
										monHoc.setTenMH(input[1]->getContent());
										monHoc.setSTCLT(atoi(input[2]->getContent().c_str()));
										monHoc.setSTCTH(atoi(input[3]->getContent().c_str()));
										input[indexInput]->initFocusedId();	
										
										// Khoi tao lai foucedId cua Ipnut cuoi cung duoc click
										input[indexInput]->initFocusedId();		
											// Free
										for(int i = 0 ; i < nInput; i++)
										{
											delete input[i];
										}			
										
										for(int i=0;i<nButton; i++)
										{
											delete btn[i];
										}
										
										return;
									}else  if(idButton == "H")
									{
										cout << "HUYYYYYYYYY NEEEEEEE\n";
										
										// Khoi tao lai foucedId cua Ipnut cuoi cung duoc click
										input[indexInput]->initFocusedId();	
										thaoTac=HUY;
										exitLoop=true;
										clearRegion(500, 150, 500 + 600, 200+400);
										
										break;
									}
								}
							}																					
						}
						
											
						if(kbhit())
						{
							char character = getch();
							
							if(indexInput != -1)
							{
								input[indexInput]->appendText(character);
								input[indexInput]->draw();	
								
								if(duyetInputs(input, nInput))
								{
									btn[0]->setBackgroundColor(clgreen);
									btn[0]->draw();
								}else
								{
									btn[0]->setBackgroundColor(clgray);
									btn[0]->draw();
								}						
							}														
						}
					}					
					

	}
	
	void chon_MH( Action &thaoTac){
		while(this->root != NULL){
			
			int soLuong = DemSoNodeTrongCay(this->root);
			MonHoc *arrMH = new MonHoc[soLuong];
			soLuong = 0;
			ChuyenCayVaoMang(arrMH, this->root, soLuong);
			SapXepTheoTen(arrMH, soLuong);
			string strSoLuong = convertIntToString(soLuong);
			
			int viTriChon = 0;
			
			
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
						"So luong mon hoc",
						strSoLuong
						/*"Ma lop",
						"D19CQCN03-N",
						"Nien khoa",
						"2019",
						"Hoc ky",
						"1",
						"Nhom",
						"1"*/
					);
			
			
			xuatDSTheoTrang_MH(arrMH, soLuong, viTriChon, thaoTac);
			
			switch (thaoTac){
				case XOA:{
					if(viTriChon < soLuong){
						cout<<"\nvi tri :"<<viTriChon; 
						//this->setRoot(this->XoaTheoMaMonHoc(this->getRoot(), arrMH[viTriChon].getMaMH()));
						this->XoaTheoMaMonHoc(this->getRoot(), arrMH[viTriChon].getMaMH());
						delete [] arrMH;
						/*soLuong = 0;
						ChuyenCayVaoMangConTro(arrMH, this->root, soLuong);
						SapXepTheoTen(arrMH, soLuong);
						viTriChon = 0; thaoTac = XUAT;
						xuatDSTheoTrang_MH(arrMH, soLuong, viTriChon, thaoTac);*/
						if(this->root == NULL)
							clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						thaoTac = XUAT;
						//this->chon_MH(thaoTac);
					}
					break;
				}
				case THEM:{
					if(viTriChon < soLuong){
						cout<<"\n"<<arrMH->getMaMH()<<" "<<arrMH->getTenMH();
						int checkTrung = 0;
						them_MH(this->root, *arrMH, checkTrung );
							
						if(checkTrung == 1){
							MessageBox(
						        NULL,
						        "MA MON HOC DA TON TAI !!!",
						        "THONG BAO",
						        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		
							
						}else if(checkTrung ==0 ) 
							MessageBox(
						        NULL,
						        "THEM MON HOC THANH CONG !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
							clearRegion(500, 150, 500 + 600, 200+400);
							thaoTac = XUAT;
							this->chon_MH(thaoTac);						
					}
					break;
				}
				
				case SUA:{
					if(viTriChon < soLuong){
						cout<<"\n"<<arrMH->getMaMH()<<" "<<arrMH->getTenMH();
						int checkTrung = 2;
						them_MH(this->root, *arrMH, checkTrung );
						if(checkTrung ==0 ) 
							MessageBox(
						        NULL,
						        "SUA MON HOC THANH CONG !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		clearRegion(500, 150, 500 + 600, 200+400);
							thaoTac = XUAT;
							this->chon_MH(thaoTac);
						
						delete arrMH;
					}
					break;
				}
				
				/*case CHON:{
					if(viTriChon < soLuong){
						cout<<"\n"<<arrMH[viTriChon].getMaMH()<<" "<<arrMH[viTriChon].getTenMH();
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						delete[] arrMH;
					}
					break;
				}*/
				
				default:{
					delete[] arrMH;
					break;
				}
					
			}
			//delete[] arrMH;
	
		}if(this->root == NULL){
			MessageBox(
		        NULL,
		        "HIEN KHONG CO MON HOC NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}
	
	MonHoc chonMH_LTC(Action thaoTac){
			MonHoc MH;
			int soLuong = DemSoNodeTrongCay(this->root);
			MonHoc *arrMH = new MonHoc[soLuong];
			soLuong = 0;
			ChuyenCayVaoMang(arrMH, this->root, soLuong);
			SapXepTheoTen(arrMH, soLuong);
			string strSoLuong = convertIntToString(soLuong);
					
			int viTriChon = 0;
			
			if(this->root != NULL){
				soLuong = DemSoNodeTrongCay(this->root);
				arrMH = new MonHoc[soLuong];
				soLuong = 0;
				ChuyenCayVaoMang(arrMH, this->root, soLuong);
				SapXepTheoTen(arrMH, soLuong);
				strSoLuong = convertIntToString(soLuong);
				
				viTriChon = 0;
					
					Label title(
							"CHON MON HOC",
							LABEL_X,
							LABEL_Y,
							LABEL_X + LABEL_WIDTH,
							LABEL_Y + LABEL_HEIGHT,
							clgreen,
							cllightgreen,
							cllightwhite
						);
						
					title.printLabel(
								"So luong mon hoc",
								strSoLuong
							);
					
				/*MessageBox(
						NULL,
						"VUI LONG CHON 1 MON HOC !!!",
						"THONG BAO",
						MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    );*/
				
				xuatDSTheoTrang_MH(arrMH, soLuong, viTriChon, thaoTac);
				
				switch(thaoTac){
					case CHON: default:{
						if(viTriChon < soLuong){
							cout<<"\n"<<arrMH[viTriChon].getMaMH()<<" "<<arrMH[viTriChon].getTenMH();
							MH.setData(arrMH[viTriChon]);
							clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
							delete[] arrMH;
						}
						break;
					}
				}
		
		}else{
			MessageBox(
			        NULL,
			        "HIEN KHONG CO MON HOC NAO !!!",
			        "THONG BAO",
			        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
	    		);
		}
		return MH;
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
	//delete left;
	//delete right;
	
	cout<<"\nXoa left va right";
}

/*
** ================ TREE ================
*/

