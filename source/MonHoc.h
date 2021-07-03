#pragma once

#include "Const.h"
#include "Validate.h"

class MonHoc{
private:
	string maMH;
	string tenMH;
	int STCLT;
	int STCTH;
	bool daMoLop;
public:
	
	MonHoc();
	
	void setTT(bool tt);
	
	bool getTT();
	
	void setMaMH(string maMH);
	
	void setTenMH(string tenMH);
	
	void setSTCLT(int STCLT);
	
	void setSTCTH(int STCTH);
	
	string getMaMH();
	
	string getTenMH();
	
	int getSTCLT();
	
	int getSTCTH();
	
	void setData(MonHoc data);
};

class NodeMonHoc{
private:
	MonHoc data;
	NodeMonHoc *left;
	NodeMonHoc *right;	
public:
	
	NodeMonHoc();
	
	NodeMonHoc(MonHoc MH);
	
	void setData(MonHoc data);
	
	void setLeft(NodeMonHoc *left);
	
	void setRight(NodeMonHoc *right);
	
	MonHoc &getData_MH();
	
	NodeMonHoc *& getLeft();
	
	NodeMonHoc *& getRight();
	
};

class TREE{
private:
	NodeMonHoc *root;
public:
	
	TREE();
	
	void freeDS_MH(NodeMonHoc *&root);
	
	NodeMonHoc *&getRoot();
	
	void setRoot(NodeMonHoc* root);
	
	void loadDataDS_MH();
	
	void writeData_MH(NodeMonHoc *root, ofstream &fileOut);
	
	void writeDataDS_MH();
	
	void them_MH(NodeMonHoc *&root, MonHoc &MH, int &checkTrung);
	
	NodeMonHoc* minValueNode(NodeMonHoc* root);
	
	NodeMonHoc* XoaTheoMaMonHoc(NodeMonHoc* &root, string key);
	
	void ChuyenCayVaoMang(MonHoc arr[], NodeMonHoc* root, int& n);
	
	int DemSoNodeTrongCay(NodeMonHoc *root);
	
	void Swap(MonHoc& a, MonHoc& b);
	
	void SapXepTheoTen(MonHoc arr[], int n);
	
	void xuatDS1Trang_MH(MonHoc arrMH[], int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac);		
	
	void locDS_MH(string content, MonHoc arrMHFilter[], int &nFilter, MonHoc arrMH[], int n, int &tongSoTrang);
	
	void xuatDSTheoTrang_MH(MonHoc *&arrMH, int tongSoDong, int &viTriChon, Action &thaoTac, Button *menuButton[] );
	
	void formNhap_MH(MonHoc &monHoc, Action &thaoTac);
	
	void menu_MH( Action &thaoTac, Button *menuButton[]);
	
	MonHoc chonMH_LTC(Action thaoTac, Button *menuButton[]);
	
};

/*
** ================ Mon hoc ================
*/

MonHoc::MonHoc(){
	maMH = "";
	tenMH = "";
	STCLT = 0;
	STCTH = 0;
	daMoLop = false;
}

void MonHoc::setTT(bool tt){
		this->daMoLop = tt;
	}
	
bool MonHoc::getTT(){
		return this->daMoLop;
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

void MonHoc::setData(MonHoc data){
		this->maMH = data.maMH;
		this->tenMH = data.tenMH;
		this->STCLT = data.STCLT;
		this->STCTH = data.STCTH;
	}
	

/*
** ================ Danh sach mon hoc ================
*/

NodeMonHoc::NodeMonHoc(){
	left = NULL;
	right = NULL;
}

NodeMonHoc::NodeMonHoc(MonHoc MH){
		this->data = MH;
		left = NULL;
		right = NULL;
	}
	
void NodeMonHoc::setData(MonHoc data){
		this->data = data;
	}
	
void NodeMonHoc::setLeft(NodeMonHoc *left){
		this->left = left;
	}
	
void NodeMonHoc::setRight(NodeMonHoc *right){
		this->right = right;
	}
	
MonHoc &NodeMonHoc::getData_MH(){
		return this->data;
	}
	
NodeMonHoc *& NodeMonHoc::getLeft(){
		return this->left;
	}
	
NodeMonHoc *& NodeMonHoc::getRight(){
		return this->right;
	}

/*
** ================ TREE ================
*/

TREE::TREE(){
		root = NULL;
	}
	
void TREE::freeDS_MH(NodeMonHoc *&root){
		delete root;
	}

NodeMonHoc *& TREE::getRoot(){
		return this->root;
	}

void TREE::setRoot(NodeMonHoc* root)
	{
		this->root = root;
	}

void TREE::loadDataDS_MH(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp; string tempStr; int tempInt;
		fileIn.open(PATH_MH.c_str(), ios::in);
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
				fileIn >> temp;
				fileIn >> tempInt;
				MH.setTT(bool(tempInt)); tempInt = 1;
			
				them_MH(root, MH, tempInt);
				if (fileIn.eof()) break;
			}
			
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS MON HOC";
			LIST_DATA = "DS MON HOC"; 
			loadFileIsSuccess = false;
		}
		
		fileIn.close();
	}

void TREE::writeData_MH(NodeMonHoc *root, ofstream &fileOut){
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
		fileOut << temp;
		fileOut << root->getData_MH().getTT();
		fileOut << '\n';
		writeData_MH(root->getRight(), fileOut);
	}
}
	
void TREE::writeDataDS_MH(){
	ofstream fileOut;
	fileOut.open(PATH_MH.c_str(), ios::out);
	if (fileOut.is_open())	{
		if(this->root!=NULL)
		writeData_MH(root, fileOut);
	}
	fileOut.close();
}

void TREE::them_MH(NodeMonHoc *&root, MonHoc &MH, int &checkTrung){
		if(root == NULL){
			
			if(checkTrung == 0) { checkTrung = -1; return; // khong ton tai mon hoc ( tao ltc moi )
			}
			
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
				}else if(checkTrung == 3){
					root->getData_MH().setTT(MH.getTT());
					checkTrung = 0; return; // set lai trang thai sau khi them, xoa lop tc
				}
			
			}
			else if (MH.getMaMH() < root->getData_MH().getMaMH())  {
				them_MH(root->getLeft(), MH, checkTrung);
			} else if (MH.getMaMH() > root->getData_MH().getMaMH())	{
				them_MH(root->getRight(), MH, checkTrung);
			}
	
		}
	}

NodeMonHoc* TREE::minValueNode(NodeMonHoc* root)
	{
		NodeMonHoc* current = root;

		while (current && current->getLeft() != NULL)
			current = current->getLeft();

		return current;
	}

NodeMonHoc* TREE::XoaTheoMaMonHoc(NodeMonHoc* &root, string key)
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

void TREE::ChuyenCayVaoMang(MonHoc arr[], NodeMonHoc* root, int& n)
	{
		if (root != NULL)
		{
			ChuyenCayVaoMang(arr, root->getLeft(), n); 
			if(root != NULL)
				arr[n++] = root->getData_MH();  
			else cout<<"\nroot null";
			
			ChuyenCayVaoMang(arr, root->getRight(), n);
		}
	}

int TREE::DemSoNodeTrongCay(NodeMonHoc *root)
	{
		if (root == NULL) {
			return 0;
		}
		
		return 1 + DemSoNodeTrongCay(root->getLeft()) +  DemSoNodeTrongCay(root->getRight());
	
	
	}

void TREE::Swap(MonHoc& a, MonHoc& b)
	{
		MonHoc temp = a;

		a = b;
		b = temp;
	}

void TREE::SapXepTheoTen(MonHoc arr[], int n)
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

	
void TREE::xuatDS1Trang_MH(MonHoc arrMH[], int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac){
		
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
	
	
void TREE::locDS_MH(string content, MonHoc arrMHFilter[], int &nFilter, MonHoc arrMH[], int n, int &tongSoTrang){
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

void TREE::xuatDSTheoTrang_MH(MonHoc *&arrMH, int tongSoDong, int &viTriChon, Action &thaoTac, Button *menuButton[] ){
		
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
		
		Input newInput("","Nhap ten mon hoc:" ,"N", MAX_TENMH, TEXT, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		
		//newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
		newInput.requestFocus();
		
		xuatDS1Trang_MH(arrMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		newInput.draw();
	
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
		bool exitLoop = false;
		
		while(!exitLoop){
			// Click event change page output
			
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	indexMenu = isClickMenuButton(menuButton, x,y);
            	if(indexMenu != -1){
            		if(indexMenu == nMenuButton - 1){
            			exitProgram = isExit();
            			if(exitProgram)
            				exitLoop = true;
            			else indexMenu = -1;
            			continue;	
					}            			
					else {
						
						exitLoop = true; continue;
					}
				}
            	
            	if(newInput.isClicked(x,y)){
            		newInput.requestFocus();
            		newInput.draw();
				}
				if(btnBack.isClicked(x,y)){
					thaoTac = THOAT_CT;
					exitLoop = true; continue;
				}
            	
            	// is clicked button Sua || Xoa
            	for(int i=batDau; i<ketThuc; i++){
            		if(thaoTac != CHON){
	            		if(editButton[i] != NULL && deleteButton[i] != NULL){
	            			if(editButton[i]->isClicked(x,y)){
								string tempMaMH = arrMHFilter[i].getMaMH();
								// tim vi tri thuc(real) cua mon hoc can sua khi sau da filter trong mang ArrMH
								int vt=0;
								for(; vt<tongSoDong; vt++){
									if(arrMH[vt].getMaMH() == tempMaMH)	break;  
								}
								viTriChon = vt;
							
					    		
					    		thaoTac=SUA;
					    		exitLoop = true; continue;
					    		
					    		
							}else if(deleteButton[i]->isClicked(x,y)){
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
				}else if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
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
					
					thaoTac = THEM;
				
					
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					newTable.freeTable();
					return;
					
				}else if(btnBack.isClicked(x,y)){
					if(thaoTac == CHON){
						thaoTac = THOAT;
						newTable.freeTable();
						return;
					}
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
				
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				
				
				xuatDS1Trang_MH(arrMHFilter, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
			}
		
		}
		
		newTable.freeTable();
		delete[] arrMHFilter;
		freeArrButton(editButton, nFilter);
		freeArrButton(deleteButton, nFilter);
	}


void TREE::formNhap_MH(MonHoc &monHoc, Action &thaoTac){
		string title = thaoTac == THEM ? "Them mon hoc" : "Sua mon hoc";
		drawFrame(500, 150, 500 + 600, 200+400, title);
					Input *input[4];
					int nInput = 4; 
					
					int initPos = thaoTac == THEM ? 0 : 1;
												
					// WIDTD input=400;
					input[0] = new Input("", "Ma mon hoc ", "0", MAX_MAMH, NON_SPACE, 650, 200, 650 + 400, 200 + INPUT_HEIGHT);
												
					input[1] = new Input("", "Ten mon hoc ", "1", MAX_TENMH, TEXT ,650, 200 + INPUT_HEIGHT + 20, 650 + 400, 200 + INPUT_HEIGHT * 2 + 20);
					input[2] = new Input("", "So TC ly thuyet ", "2", 2, NUMBER ,650, (200 + INPUT_HEIGHT * 2) + (20 * 2), 650 + 400, (200 + INPUT_HEIGHT * 3) + (20 * 2));
					input[3] = new Input("","So TC thuc hanh ", "3", 2, NUMBER ,650, (200 + INPUT_HEIGHT * 3) + (20 * 3), 650 + 400, (200 + INPUT_HEIGHT * 4) + (20 * 3));
					
					Button *btn[2];
					int nButton = 2 ;
					
					if(thaoTac==THEM)	{
						btn[0]= new Button("THEM","T", 650, (200 + INPUT_HEIGHT * 5) + (20 * 5), 650 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), claqua, cllightblue, clblack);	
					}else if(thaoTac==SUA)
					{
						initPos = 1;
						btn[0]= new Button("LUU","S", 650, (200 + INPUT_HEIGHT * 5) + (20 * 5), 650 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), claqua, cllightblue, clblack);
						input[0]->setContent(monHoc.getMaMH());
						input[0]->setOffEnable();
					
						input[1]->setContent(monHoc.getTenMH());				
						input[2]->setContent(convertIntToString(monHoc.getSTCLT()));
						
						input[3]->setContent(convertIntToString(monHoc.getSTCTH()));
										
										// draw input
						for(int i = 0; i < nInput; i++)
						{
								input[i]->draw();
						}
										
		//								getch();
						
					}
													
					btn[1]= new Button("HUY","H", 900, (200 + INPUT_HEIGHT * 5) + (20 * 5), 900 + buttonWidth, (200 + INPUT_HEIGHT * 6) + (20 * 5), cllightred, clred, cllightwhite);
					
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
					int indexInput=initPos;
					int oldIndexInput=0;
					input[indexInput]->requestFocus();
					input[indexInput]->draw();
					bool isFullInfo = true;
					// Bang input
					while(!exitLoop)
					{
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							
							// Kiem tra click EditText
							for(int i = 0; i < nInput; i++)
							{
								if(input[i]->isClicked(x,y) && input[i]->getEnable()){
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
									idButton = btn[i]->getId();
									//	cout << "\n222222222222222222=========== "<<idButton;
										cout <<btn[i]->getId();
									if(idButton == "T" && duyetInputs(input, nInput))
									{
										
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
							char character = getch();// cout<<"\n"<<character;
							if(character == TAB){
								oldIndexInput = indexInput;
								indexInput++;
								if(indexInput == nInput) indexInput = initPos;
								input[indexInput]->requestFocus();
								input[oldIndexInput]->draw();
								input[indexInput]->draw();
							}else if(character == ENTER){
								isFullInfo = true;
								for(int i=initPos; i<nInput; i++){
									if(input[i]->getContent().empty()){
										isFullInfo = false; 
										oldIndexInput = indexInput;
										indexInput = i;
										i = nInput;
									}
								}
								
								if(isFullInfo){
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
									return;
								}else {
									MessageBox(
								        NULL,
								        "VUI LONG KHONG BO TRONG THONG TIN !!!",
								        "THONG BAO",
								        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						    		);
						    		input[indexInput]->requestFocus();
						    		input[indexInput]->draw();
						    		input[oldIndexInput]->draw();
						    		continue;
								}
								
							}else if(indexInput != -1)
							{ 
								//if(character == -32 || character == 0 ) { character = getch(); continue;}
								
								input[indexInput]->appendText(character);
								input[indexInput]->draw();	
								
														
							}														
						}
					}
	}
	

void TREE::menu_MH( Action &thaoTac, Button *menuButton[]){
		MonHoc monhoc;
		
		int viTriChon = 0;
		
		while(this->root != NULL && indexMenu == -1){ 
			int soLuong = DemSoNodeTrongCay(this->root);
			MonHoc *arrMH = new MonHoc[soLuong];
			soLuong = 0;
			ChuyenCayVaoMang(arrMH, this->root, soLuong);
			SapXepTheoTen(arrMH, soLuong);
			string strSoLuong = convertIntToString(soLuong);
			
			Label title(
					"DANH SACH MON HOC",
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
			
			
			//xuatDSTheoTrang_MH(arrMH, soLuong, viTriChon, thaoTac, menuButton);
			switch (thaoTac){
				case XUAT:{
					xuatDSTheoTrang_MH(arrMH, soLuong, viTriChon, thaoTac, menuButton);
					break;
				}
				case XOA:{
					if(viTriChon < soLuong){
						if(!arrMH[viTriChon].getTT()) {
							this->XoaTheoMaMonHoc(this->getRoot(), arrMH[viTriChon].getMaMH());
							delete [] arrMH;
							
							if(this->root == NULL)
								clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						}else {
							MessageBox(
						        NULL,
						        "KHONG THE XOA MON HOC DA MO LOP TC !!!",
						        "THONG BAO",
						        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
						}
						
						thaoTac = XUAT;
						this->writeDataDS_MH();
					}
					break;
				}
				case THEM:{
					
					formNhap_MH(monhoc, thaoTac);
					if(thaoTac == HUY){
						clearRegion(500, 150, 500 + 600, 200+400);
						thaoTac = XUAT;	
					}else {
						
						int checkTrung = 0;
						them_MH(this->root, monhoc, checkTrung );
							
						if(checkTrung == 1){
							
				    		MessageBox(
						        NULL,
						        "MA MON HOC DA TON TAI !!!",
						        "THONG BAO",
						        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
							
						}else if(checkTrung ==0 ) {
							MessageBox(
						        NULL,
						        "THEM MON HOC THANH CONG !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		clearRegion(500, 150, 500 + 600, 200+400);
							thaoTac = XUAT;
							monhoc.setMaMH(""); monhoc.setTenMH(""); monhoc.setSTCLT(0); monhoc.setSTCTH(0);
							this->writeDataDS_MH();
						}
							
				    		
					}
					
						
											
					
					break;
				}
				
				case SUA:{ cout<<"\n"<<arrMH[viTriChon].getTenMH();
						monhoc.setMaMH(arrMH[viTriChon].getMaMH());
					    monhoc.setTenMH(arrMH[viTriChon].getTenMH());
					    monhoc.setSTCLT(arrMH[viTriChon].getSTCLT());
					    monhoc.setSTCTH(arrMH[viTriChon].getSTCTH());
					    
					    formNhap_MH(monhoc, thaoTac);
					    if(thaoTac != HUY){
					    	int checkTrung = 2;
							them_MH(this->root, monhoc, checkTrung );
							if(checkTrung == 0 ){
								MessageBox(
							        NULL,
							        "SUA MON HOC THANH CONG !!!",
							        "THONG BAO",
							        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					    		
								monhoc.setMaMH(""); monhoc.setTenMH(""); monhoc.setSTCLT(0); monhoc.setSTCTH(0);
							}
						}
					    
						
							clearRegion(500, 150, 500 + 600, 200+400);
							thaoTac = XUAT;
							this->writeDataDS_MH();
					
					break;
				}
				
				case THOAT_CT:{
					indexMenu = -1; cout<<"\nthoat ct";
					return;
					break;
				}
				
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


MonHoc TREE::chonMH_LTC(Action thaoTac, Button *menuButton[]){
			MonHoc MH;
			int soLuong = DemSoNodeTrongCay(this->root);
			MonHoc *arrMH = new MonHoc[soLuong];
			soLuong = 0;
			ChuyenCayVaoMang(arrMH, this->root, soLuong);
			SapXepTheoTen(arrMH, soLuong);
			string strSoLuong = convertIntToString(soLuong);
					
			int viTriChon = -1;
			
			if(this->root != NULL){ 
				soLuong = DemSoNodeTrongCay(this->root);
				arrMH = new MonHoc[soLuong];
				soLuong = 0;
				ChuyenCayVaoMang(arrMH, this->root, soLuong);
				SapXepTheoTen(arrMH, soLuong);
				strSoLuong = convertIntToString(soLuong);
					
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
				
				xuatDSTheoTrang_MH(arrMH, soLuong, viTriChon, thaoTac, menuButton);
				
				switch(thaoTac){
					case THOAT:{
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						break;
					}
					case CHON: default:{
						if(viTriChon < soLuong && viTriChon != -1){
							cout<<"\n"<<arrMH[viTriChon].getMaMH()<<" "<<arrMH[viTriChon].getTenMH();
							MH.setData(arrMH[viTriChon]);
						}
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						delete[] arrMH;
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
