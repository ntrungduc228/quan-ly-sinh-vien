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
		
	void writeData_SV(SinhVien SV, ofstream &fileOut){
	
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
};

class DSSV{
private:
	NodeSV *head;
public:
	DSSV();
	~DSSV(){
	//delete head;
		cout<<"\ndelete head sv";
	}
	
	void setHead_DSSV(NodeSV *head);
	NodeSV*& getHead_DSSV();
	
	bool isNULL_SV();
	
	/*void loadDaTaDS_SV(){
		ifstream fileIn; char temp;
		fileIn.open("data\\DSSV.txt",ios::in);
		if (fileIn.is_open())	{

			while (!fileIn.eof())	{
				
				NODESV* SV = taoNode_SV();
				getline(fileIn, SV->data.MASV, ',');
				getline(fileIn, SV->data.HO, ',');
				getline(fileIn, SV->data.TEN, ',');
				getline(fileIn, SV->data.PHAI, ',');
				getline(fileIn, SV->data.SDT, ',');
				getline(fileIn, SV->data.MALOP,'\n');
	
	
				/*int viTriThem = timviTri_SV(DSSV, SV);
				them_SV(DSSV,SV, viTriThem);
		
				int viTriLop = timMaLop_LSV(DSLSV, SV->data.MALOP);
				if (viTriLop != -1)
				{
					int viTriThem = timviTri_SV(DSLSV.Lop[viTriLop].DSSV, SV);
					/*cout << viTriThem;
					system("pause");
					them_SV(DSLSV.Lop[viTriLop].DSSV, SV, viTriThem);
					DSLSV.Lop[viTriLop].soLuongSV++;
				}
				if (fileIn.eof()) break;
				
			}
		}
		
		fileIn.close();
	}*/
	
	void writeDataDS_SV(){
		/*ofstream fileOut(PATH_SAVE_SV,ios::out);
		if(fileOut.is_open()){
			for(NodeSV *p = this->head; p!=NULL; p=(p->getNext_SV())){
				writeData_SV(p->getData_SV(),fileOut);
			}
		}
		fileOut.close();*/
	}
	
	void freeDS_SV(NodeSV *&pHead){
		
		NodeSV* SV = NULL;
		while (pHead != NULL)
		{
			SV = pHead;
			pHead = pHead->getNext_SV();
			delete SV;
		}
	}
	
	NodeSV * tim_SV(int viTriChon){
		if(head == NULL) return NULL;
		int i=0; NodeSV*p=head;
		for(; p!=NULL && i<viTriChon ;i++, p=p->getNext_SV());
		
		return p;
	}
	
	
	int tim_SV(string maSV){
		int viTri = 1;
		NodeSV *p;
		for(p = this->head; p!=NULL ; viTri++, p = p->getNext_SV())
			if(p->getData_SV().getMaSV() == maSV) return viTri;
			
		return -1;
	}
	
	int timViTriThem_SV(NodeSV *SV);
	void themDau_SV(NodeSV * SV);
	void them_SV(NodeSV *SV);
	int xoa_SV(string maSV);
	
	int demSoLuongSV(){
		int n = 0;
		for(NodeSV *p = this->head; p != NULL ; n++,p=(p->getNext_SV()));
		
		return n;
	}
		
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
	
	void xuatDS1Trang_SV(NodeSV *&head, int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; // Xem can xuat bao nhieu dong
		if(soDong == 0) soDong = MAX_DONG_1_TRANG; // neu so du == 0 thi xuat ra MAX_DONG_1_TRANG dong
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT;	
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack);
		cout<<"\nBat dau "<<batDau<<" "<<ketThuc;
		
		NodeSV *p = head;
		for(int vt = 0;  p !=NULL && vt < batDau; vt++, p = p->getNext_SV()) ; // chay den STT can xuat
		
		
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
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(1)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth()- 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(3)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() - 4 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(4)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(5)->getWidth() - 4 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(5)->getWidth();
				
				View view("",x,yBtn, x+newTable.getCols(6)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
				view.draw();
				
				x =  tableLeft;
				continue;
			}
			
			//if(i != batDau && p!=NULL) p = p->getNext_SV(); // i != batDau de khong bi mat du lieu dong dau tien	
				
			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
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
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(1)->getWidth()/2  - textwidth(p->getData_SV().getMaSV().c_str())/2, 
						y, 
						p->getData_SV().getMaSV().c_str()
					);
					
				x += newTable.getCols(1)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + 10, 
						y, 
						p->getData_SV().getHo().c_str()
					);
					
				x += newTable.getCols(2)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(3)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + 10, 
						y, 
						p->getData_SV().getTen().c_str()
					);
					
				x += newTable.getCols(3)->getWidth();	
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(4)->getWidth() - 4 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(4)->getWidth()/2 - textwidth(p->getData_SV().getPhai().c_str())/2, 
						y, 
						p->getData_SV().getPhai().c_str()
					);
					
				x += newTable.getCols(4)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(5)->getWidth() - 4 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(5)->getWidth()/2  - textwidth(p->getData_SV().getSDT().c_str())/2, 
						y, 
						p->getData_SV().getSDT().c_str()
					);
					
				x += newTable.getCols(5)->getWidth();
				
				// ve button sua 
			if(editButton[i] == NULL)
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
				editButton[i]->draw();
				x += checkBoxButtonWidth + buttonActionSpace;
				
				// ve button xoa 
			if(deleteButton[i] == NULL)
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
				deleteButton[i]->draw();
			
			x = tableLeft;
			if(p!=NULL ) p = p->getNext_SV();
			
			
		}
	}
	
	void locDS_SV(string content, DSSV &dssv, int &nFilter, int &tongSoTrang){
		dssv.freeDS_SV(dssv.getHead_DSSV());
		dssv.setHead_DSSV(NULL);
		//DSSV newds; newds.setHead_DSSV(NULL);
		if(!content.empty()){
			for(NodeSV *p = this->head; p!=NULL; p=p->getNext_SV()){
				if(p->getData_SV().getMaSV().find(content) != string::npos){
					cout<<"\n"<<p->getData_SV().getMaSV();
					
					NodeSV*SV = new NodeSV(p->getData_SV());
					//SV->getData_SV().xuat_SV();
					dssv.them_SV(SV);
					cout<<"\nThem thanh cong";
				}
			}
			
		}else{
			for(NodeSV *p = this->head; p!=NULL; p=p->getNext_SV()){
				NodeSV *sv = new NodeSV(p->getData_SV());
				dssv.them_SV(sv);
			}
		}
		
		
		nFilter = dssv.isNULL_SV() ? 0 : dssv.demSoLuongSV();
	
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
		
		
	}
	
	void xuatDSTheoTrang_SV(int &viTriChon, Action &thaoTac){
		
		DSSV dssv; 
		//dssv.setHead_DSSV(this->head);
		for(NodeSV *p = this->head; p!=NULL; p=p->getNext_SV()){
			NodeSV *sv = new NodeSV(p->getData_SV());
			dssv.them_SV(sv);
		}
		
		int tongSoDong = this->demSoLuongSV();
		int nFilter = tongSoDong;
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *editButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		Table newTable = table_SV();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_SV(dssv.getHead_DSSV(), batDau, ketThuc, editButton, deleteButton, newTable);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ma sinh vien:" ,"N", MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		newInput.requestFocus();
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		Button btnAdd("Nhap SV","btnAdd", 400, 80, 400 + buttonWidth, 120);
		btnAdd.draw();
		
		
		
		int x,y;
		
		while(true) {
			delay(0.000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	if(newInput.isClicked(x,y)){
            		newInput.requestFocus();
            		newInput.draw();
				}
            	
            	// checked if button sua || xoa is clicked
            	for(int i=batDau; i<ketThuc; i++){
            		if(editButton[i] != NULL && deleteButton[i] != NULL) {
	            		if(editButton[i]->isClicked(x,y)){
							cout<<"\n"<<i<<" is clicked "<<editButton[i]->getText();
							MessageBox(
						        NULL,
						        "Ban muon sua sinh vien",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK
				    		);
						}else if(deleteButton[i]->isClicked(x,y)){
							cout<<"\n"<<i<<" is clicked "<<deleteButton[i]->getText();
							int isConfirmed = MessageBox(
											        NULL,
											        "BAN CO CHAC CHAN MUON XOA SINH VIEN NAY",
											        "THONG BAO",
											        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
									    		);
							switch(isConfirmed){
								case IDCANCEL:{
									break;
								}
								case IDOK: default:{
									// tim vi tri thuc(real) cua sinh can xoa khi sau da filter 
									string tempMaSV;
									NodeSV *p = dssv.getHead_DSSV();
									for(int j=0; j<nFilter && p!=NULL; j++, p=p->getNext_SV()){
										if(j==i) {
											tempMaSV = p->getData_SV().getMaSV(); break;
										}
									}
									int vt=0; 
									for( p=this->head; p!=NULL; vt++,p=p->getNext_SV()){
										if(p->getData_SV().getMaSV() == tempMaSV){
											viTriChon = vt; break;
										} 
									}
								
									thaoTac = XOA;
									newTable.freeTable();
									freeArrButton(editButton, nFilter);
									freeArrButton(deleteButton, nFilter);
									return; 	
								}
							}
						}
					}
					
				}
            	
            	if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
            		
            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
            		
            		xuatDS1Trang_SV(dssv.getHead_DSSV(), batDau, ketThuc, editButton, deleteButton, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					xuatDS1Trang_SV(dssv.getHead_DSSV(), batDau, ketThuc, editButton, deleteButton, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
        	
				if(btnAdd.isClicked(x,y)){
					thaoTac = THEM;
					newTable.freeTable();
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return; 
				}
			}
		
			// Filter by input
			if(kbhit()){
				freeArrButton(editButton, nFilter);
				freeArrButton(deleteButton, nFilter);
				char ch = getch();
				newInput.appendText(ch);
				newInput.draw();
				(locDS_SV(newInput.getContent(), dssv, nFilter, tongSoTrang)) ;
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				cout<<"\nKet thucccccccccccccccccccc: "<<nFilter<<" "<<ketThuc;
				
				xuatDS1Trang_SV(dssv.getHead_DSSV(), batDau, ketThuc, editButton, deleteButton, newTable);
				inTrang(trangHienTai, tongSoTrang);
			}
		}
	}
	
	void resetArrInput(Input ***&input, Input ***&inputPhai, int &nRow, int nCol, Table newTable){
		// Input student's info
		// create Arr temp input to save contents from arr input parameters
		
		Input ***tempInput; Input ***tempInputPhai;
		tempInput = new Input **[nRow]; tempInputPhai = new Input **[nRow];
		for(int i=0; i<nRow; i++){
			tempInput[i] = new Input*[nCol];
			tempInputPhai[i] = new Input*[2];
		}
		
		for(int i=0; i<nRow; i++){
			for(int j=0; j<nCol; j++){
				/*tempInput[i][j] = new Input(*input[i][j]);cout<<"\n"<<i<<" "<<j;
				tempInputPhai[i][j] = new Input(*(inputPhai[i][j]));*/
				tempInput[i][j] = new Input(
										input[i][j]->getContent(),
										input[i][j]->getText(),
										input[i][j]->getId(),
										input[i][j]->getMaxLength(),
										input[i][j]->getType(),
										input[i][j]->getLeft(),
										input[i][j]->getTop(),
										input[i][j]->getRight(),
										input[i][j]->getBottom(),
										input[i][j]->getBKColor(),
										input[i][j]->getBorderColor(),
										input[i][j]->getTextColor()
							);
					
				if(j<2){
					tempInputPhai[i][j] = new Input(
										inputPhai[i][j]->getContent(),
										inputPhai[i][j]->getText(),
										inputPhai[i][j]->getId(),
										inputPhai[i][j]->getMaxLength(),
										inputPhai[i][j]->getType(),
										inputPhai[i][j]->getLeft(),
										inputPhai[i][j]->getTop(),
										inputPhai[i][j]->getRight(),
										inputPhai[i][j]->getBottom(),
										inputPhai[i][j]->getBKColor(),
										inputPhai[i][j]->getBorderColor(),
										inputPhai[i][j]->getTextColor()
								);
				}
				
			} 
		}
	
		// free input param to allocate new memory
		
		for(int i=0; i<nRow; i++){
			for(int j=0; j<nCol; j++){
				delete input[i][j];
				
				if(j<2)	delete inputPhai[i][j];
			}
			delete[] input[i]; delete[] inputPhai[i];
		}
		
		delete [] input; delete[] inputPhai;
	
		// allocate new memory for input parameters
		int oldNRow = nRow;
		nRow *= 2; cout<<"\nnew nrow: "<<nRow;
		input = new Input**[nRow]; inputPhai = new Input **[nRow];
		for(int i=0; i<nRow; i++){
			input[i] = new Input*[nCol];
			inputPhai[i] = new Input*[2];
		}
		
		for(int i=0; i<oldNRow; i++){
			for(int j=0; j<nCol; j++){
				input[i][j] = new Input(
									tempInput[i][j]->getContent(),
									tempInput[i][j]->getText(),
									tempInput[i][j]->getId(),
									tempInput[i][j]->getMaxLength(),
									tempInput[i][j]->getType(),
									tempInput[i][j]->getLeft(),
									tempInput[i][j]->getTop(),
									tempInput[i][j]->getRight(),
									tempInput[i][j]->getBottom(),
									tempInput[i][j]->getBKColor(),
									tempInput[i][j]->getBorderColor(),
									tempInput[i][j]->getTextColor()
								);
				if(j<2){
					inputPhai[i][j] = new Input(
									tempInputPhai[i][j]->getContent(),
									tempInputPhai[i][j]->getText(),
									tempInputPhai[i][j]->getId(),
									tempInputPhai[i][j]->getMaxLength(),
									tempInputPhai[i][j]->getType(),
									tempInputPhai[i][j]->getLeft(),
									tempInputPhai[i][j]->getTop(),
									tempInputPhai[i][j]->getRight(),
									tempInputPhai[i][j]->getBottom(),
									tempInputPhai[i][j]->getBKColor(),
									tempInputPhai[i][j]->getBorderColor(),
									tempInputPhai[i][j]->getTextColor()
								);
				}
				
			}
		}
		
		int width = 30;
		string strID;
		int intID;
		int x = tableLeft + newTable.getCols(0)->getWidth();
		int y = tableTop + INPUT_HEIGHT;
		
		for(int i=oldNRow; i<nRow; i++){
			intID = i*10+0; strID = convertIntToString(intID);
			input[i][0] = new Input("","",strID, MAX_MASV, STUDENT_ID, x, y, x+newTable.getCols(1)->getWidth(), y+INPUT_HEIGHT, cllightred);
			x += newTable.getCols(1)->getWidth();
			
			intID = i*10+1; strID = convertIntToString(intID);
			input[i][1] = new Input("","",strID, MAX_HOSV, LAST_NAME, x, y, x+newTable.getCols(2)->getWidth(), y+INPUT_HEIGHT, claqua);
			x += newTable.getCols(2)->getWidth();
			
			intID = i*10+2; strID = convertIntToString(intID);
			input[i][2] = new Input("","",strID, MAX_TENSV, NAME, x, y, x+newTable.getCols(3)->getWidth(), y+INPUT_HEIGHT, cllightgreen);
			x += newTable.getCols(3)->getWidth();
			
			intID = i*10+3; strID = convertIntToString(intID);
			input[i][3] = new Input("","",strID, 3, NON_NUMBER, x, y, x+newTable.getCols(4)->getWidth(), y+INPUT_HEIGHT, clyellow);
			inputPhai[i][0] = new Input("Nam","","chon",3,NON_SPACE,x+20, y+5, x+20 + 50, y+width,cllightgreen, clblack, clblack);
			inputPhai[i][1] = new Input("Nu","","",3,NON_SPACE,x + 100, y+5, x+100+50, y+width, cllightwhite, clblack, clblack);
			
			x += newTable.getCols(4)->getWidth();
			
			intID = i*10+4; strID = convertIntToString(intID);
			input[i][4] = new Input("","",strID, MAX_SDT, NUMBER, x, y, x+newTable.getCols(5)->getWidth(), y+INPUT_HEIGHT, cllightpurple);
			
			y += INPUT_HEIGHT;
			x = tableLeft + newTable.getCols(0)->getWidth();
			cout<<"\n"<<i;
		}
		
		
		// free memory arr temp input
		for(int i=0; i<oldNRow; i++){
			for(int j=0; j<nCol; j++){
				delete tempInput[i][j];
				
				if(j<2)	delete tempInputPhai[i][j];
			}
			delete[] tempInput[i]; delete[] tempInputPhai[i];
		}
		delete [] tempInput; delete[] tempInputPhai;
		cout<<"\ndong 792, xong ham";
	}
	
	void nhapDSTheoDong_SV(Input ***input, Input ***inputPhai, int batDau, int ketThuc, int nRow, int nCol){ cout<<"\nVo day ve "<<batDau<<" "<<ketThuc;
		/*input[ketThuc-1][0]->requestFocus();
		if(ketThuc % MAX_DONG_1_TRANG == 0) input[batDau][0]->requestFocus();*/
		
		int x = tableLeft, y = input[batDau][0]->getTop();
		string strSTT = convertIntToString(0);
		
		for(int i=batDau; i<ketThuc; i++){
			for(int j=0; j<nCol; j++){
				input[i][j]->draw();
			}
			
			for(int j=0; j<2; j++){
				inputPhai[i][j]->draw();
			}
			
			// ve o STT
			rectangle(
					x,
					y,
					input[i][0]->getRight(),
					input[i][0]->getBottom()
				);
			
			// xoa du lieu cu
			setbkcolor(cllightwhite); setcolor(clblack);
			outtextxy(
					x+(input[i][0]->getLeft()-x)/2 - textwidth(strSTT.c_str())/2 - 10,
					y + INPUT_HEIGHT/2 - textheight(strSTT.c_str())/2,
					string(textwidth(strSTT.c_str())/2+2,' ').c_str()	
				);
			
			// in du lieu moi
			strSTT = convertIntToString(i+1);
			//setbkcolor(cllightwhite);
			outtextxy(
					x+(input[i][0]->getLeft()-x)/2 - textwidth(strSTT.c_str())/2,
					y + INPUT_HEIGHT/2 - textheight(strSTT.c_str())/2,
					strSTT.c_str()
				);
			
			y += INPUT_HEIGHT;
		}
		
		if(nRow % ketThuc != 0){  
			//int left = input[ketThuc][0]->getLeft();
			int top = input[ketThuc][0]->getTop() + 1;
			int right = input[ketThuc][nCol-1]->getRight() + 1;
			int bottom = input[nRow-1][0]->getBottom() + 1;
		
			clearRegion(tableLeft, top, right, bottom);
		}
	}
	
	void formNhap_SV(string maLop, Action &thaoTac){
		int nRow; int nCol = 5;
		if(thaoTac == THEM) 
			nRow = MAX_DONG_1_TRANG;
		else if(thaoTac == SUA) 
			nRow = 1;
		
		int soLuong = 1; int batDau = 0; int ketThuc = 1;
		
		Table newTable = table_NhapSV();
		newTable.drawTable(0);
		
		int x = tableLeft + newTable.getCols(0)->getWidth();
		int y = tableTop + INPUT_HEIGHT;
		
		
		Input newInput("","Nhap ma lop tc:" ,"N", 5, NUMBER, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clred, clblack);
		//newInput.draw();
		
		
		Button btnSave("Luu","luu",380, 80, 380 + buttonWidth, 120);
		Button btnAddRow("Them dong","them", 480, 80, 500 + buttonWidth, 120);
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		
		if(nRow > MAX_DONG_1_TRANG){
			btnPrev.draw();
			btnNext.draw();
		}
		
		btnSave.draw();
		if(thaoTac == THEM) btnAddRow.draw();
		
		//Input **inputPhai[nRow];
		Input ***inputPhai; inputPhai = new Input **[nRow];
		for(int i=0; i<nRow; i++){
			inputPhai[i] = new Input*[2];
		}
		
		for(int i=0; i<nRow; i++){
			inputPhai[i][0] = new Input("Nam","","chon",3,NON_SPACE, x,y, x+newTable.getCols(1)->getWidth(), y+INPUT_HEIGHT, cllightgreen, clblack, clblack);
			inputPhai[i][1] = new Input("Nu","","",3,NON_SPACE, x,y, x+newTable.getCols(1)->getWidth(), y+INPUT_HEIGHT, cllightwhite, clblack, clblack);
		}
		
		Input ***input;
		
		input = new Input **[nRow];
		for(int i=0; i<nRow; i++){
			input[i] = new Input*[nCol];
		}
		
		int width = 30; //15;
		string strID;
		int intID;
		for(int i=0; i<nRow; i++){
			intID = i*10+0; strID = convertIntToString(intID);
			input[i][0] = new Input("","",strID, MAX_MASV, STUDENT_ID, x, y, x+newTable.getCols(1)->getWidth(), y+INPUT_HEIGHT, cllightwhite, clblack, clblack);
			x += newTable.getCols(1)->getWidth();
			
			intID = i*10+1; strID = convertIntToString(intID);
			input[i][1] = new Input("","",strID, MAX_HOSV, LAST_NAME, x, y, x+newTable.getCols(2)->getWidth(), y+INPUT_HEIGHT, cllightwhite, clblack, clblack);
			x += newTable.getCols(2)->getWidth();
			
			intID = i*10+2; strID = convertIntToString(intID);
			input[i][2] = new Input("","",strID, MAX_TENSV, NAME, x, y, x+newTable.getCols(3)->getWidth(), y+INPUT_HEIGHT, cllightwhite, clblack, clblack);
			x += newTable.getCols(3)->getWidth();
			
			intID = i*10+3; strID = convertIntToString(intID);
			input[i][3] = new Input("","",strID, 3, NON_NUMBER, x, y, x+newTable.getCols(4)->getWidth(), y+INPUT_HEIGHT, cllightwhite, clblack, clblack);
			inputPhai[i][0]->setParams(x+20, y+5, x+20 + 50, y+width);
			//inputPhai[i][0]->requestFocus();
			inputPhai[i][1]->setParams(x + 100, y+5, x+100+50, y+width);
			x += newTable.getCols(4)->getWidth();
			
			intID = i*10+4; strID = convertIntToString(intID);
			input[i][4] = new Input("","",strID, MAX_SDT, NUMBER, x, y, x+newTable.getCols(5)->getWidth(), y+INPUT_HEIGHT, cllightwhite, clblack, clblack);
			
			y+= INPUT_HEIGHT;
			x = tableLeft + newTable.getCols(0)->getWidth();
		}
		
		//int x,y;
		
		bool isFullInfo = false;
		
		int indexOfRow=0, indexOfCol = 0;
		int oldIndexOfRow=-1, oldIndexOfCol = -1;
		
		int trangHienTai =1;
		int tongSoTrang = 1;
		
		input[batDau][0]->requestFocus();
		nhapDSTheoDong_SV(input, inputPhai, batDau, ketThuc, nRow, nCol);
		input[batDau][0]->draw();
		
		char ch;
		
		bool tiepTucNhap = true;
		
		while(tiepTucNhap){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y); 
				
				for(int i=batDau; i<ketThuc ; i++){
					for(int j=0; j<nCol; j++){
						if(input[i][j]->isClicked(x,y) && input[i][j]->getEnable() && j != 3){
							input[i][j]->requestFocus();
							input[i][j]->draw();
							
							oldIndexOfRow = indexOfRow;
							oldIndexOfCol = indexOfCol;
							
							//if(oldIndexOfRow != -1  && oldIndexOfCol != -1)
								input[oldIndexOfRow][oldIndexOfCol]->draw();
								
							indexOfRow = i;
							indexOfCol = j;
							break;
						}
						
					}
					
					for(int j=0; j<2; j++){
						if(inputPhai[i][0]->isClicked(x,y) && inputPhai[i][0]->getId() == ""){
							inputPhai[i][0]->setBackgroundColor(cllightgreen); 
							inputPhai[i][1]->setBackgroundColor(cllightwhite); 
							inputPhai[i][0]->setId("chon"); inputPhai[i][1]->setId("");
							inputPhai[i][0]->draw(); inputPhai[i][1]->draw();
						}
						else if(inputPhai[i][1]->isClicked(x,y) && inputPhai[i][1]->getId() == ""){
							inputPhai[i][1]->setBackgroundColor(cllightgreen); 
							inputPhai[i][0]->setBackgroundColor(cllightwhite); 
							inputPhai[i][0]->setId(""); inputPhai[i][1]->setId("chon");
							inputPhai[i][0]->draw(); inputPhai[i][1]->draw();
						}
						
					}
				} // end for
				
				if(btnSave.isClicked(x,y)){
					
					isFullInfo = true;
					
					for(int i=0; i<soLuong && (isFullInfo); i++){
						for(int j=0; j<nCol; j++){
							if(input[i][j]->getContent().empty() && j != 3){
								isFullInfo = false;
								break;
							}
						}
					}
					
					if(isFullInfo){
					    tiepTucNhap = false;
					}else {
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN TRUOC KHI LUU !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					}
				}
				
				if(btnAddRow.isClicked(x,y) && thaoTac == THEM){
					isFullInfo = true;
					for(int i=batDau; i<soLuong; i++){
						for(int j=0; j<nCol; j++){
							if(input[i][j]->getContent().empty() && j != 3){
								isFullInfo = false;
								MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN TRUOC KHI THEM DONG MOI!!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
								break;
							}
						}
					}
					
					/// trang hien tai phai == tongsotrang, vd co 2 trang, dang dung trang 1 ko the them dong moi o trang 2
					if(isFullInfo && trangHienTai == tongSoTrang){
						isFullInfo = false;
						
						if(soLuong + 1 > tongSoTrang*MAX_DONG_1_TRANG){
							tongSoTrang++; cout<<"\nreset lai thoi";
							resetArrInput(input, inputPhai, nRow, nCol, newTable);
							
							trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
							batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
							
							btnPrev.draw();
							btnNext.draw();	
							inTrang(trangHienTai, tongSoTrang);
						
						}
						soLuong++; ketThuc++; input[ketThuc-1][0]->requestFocus();
						nhapDSTheoDong_SV(input, inputPhai, batDau, ketThuc, nRow, nCol);
						
						input[ketThuc-1][0]->draw();
						
						indexOfRow = soLuong-1;
						indexOfCol = 0;
					}
				}
				
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )){
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (soLuong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : soLuong;
            		
            		ketThuc = (ketThuc > soLuong) ? batDau + soLuong % batDau : ketThuc;
					
					cout<<"\nbat dau "<<batDau<<" "<<ketThuc;
					
					indexOfRow = batDau;
					indexOfCol = 0;
					
					input[batDau][0]->requestFocus();
					nhapDSTheoDong_SV(input, inputPhai, batDau, ketThuc, nRow, nCol);
					input[batDau][0]->draw();
					
					inTrang(trangHienTai, tongSoTrang);
					
				}
				else if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
					trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (soLuong > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : soLuong;
            		
            		ketThuc = (ketThuc > soLuong) ? batDau + soLuong % batDau : ketThuc;
            		
            		cout<<"\nbat dau "<<batDau<<" "<<ketThuc;
            		
            		indexOfRow = batDau;
					indexOfCol = 0;
					
            		input[batDau][0]->requestFocus();
            		nhapDSTheoDong_SV(input, inputPhai, batDau, ketThuc, nRow, nCol);
            		input[batDau][0]->draw();
					inTrang(trangHienTai, tongSoTrang);
				}
				
			}
				
			if(kbhit()){
				ch = getch();
				if(ch == ENTER){
					isFullInfo = true;
					for(int j=0; j<nCol; j++){
						if(input[soLuong-1][j]->getContent().empty() && j != 3){
							isFullInfo = false;
							MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN TRUOC KHI THEM DONG MOI!!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					    	break;
						}
					}
					
					if(isFullInfo && trangHienTai == tongSoTrang){
						isFullInfo = false;
						
						if(soLuong + 1 > tongSoTrang*MAX_DONG_1_TRANG){
							tongSoTrang++; cout<<"\nreset lai thoi";
							resetArrInput(input, inputPhai, nRow, nCol, newTable);
							
							trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
							batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
							
							btnPrev.draw();
							btnNext.draw();	
							inTrang(trangHienTai, tongSoTrang);
						
						}
						soLuong++; ketThuc++; input[ketThuc-1][0]->requestFocus();
						nhapDSTheoDong_SV(input, inputPhai, batDau, ketThuc, nRow, nCol);
						
						input[ketThuc-1][0]->draw();
						
						indexOfRow = soLuong-1;
						indexOfCol = 0;
					}
					
				}else if(ch == TAB){
					if(!input[indexOfRow][indexOfCol]->getContent().empty()){
						oldIndexOfCol = indexOfCol;
						indexOfCol++;
						if(indexOfCol == 3 || indexOfCol == nCol ) indexOfCol = 4;
						
						input[indexOfRow][indexOfCol]->requestFocus();
						input[indexOfRow][indexOfCol]->draw();
						
						//if(oldIndexOfCol != -1 && oldIndexOfRow != -1)
							input[indexOfRow][oldIndexOfCol]->draw();
							
					}
				}
				if(indexOfRow != -1 && indexOfCol != -1 && indexOfCol != 3){
					input[indexOfRow][indexOfCol]->appendText(ch);
					input[indexOfRow][indexOfCol]->draw();
				}
			}
			
		}
		
		// luu ds sinh vien da nhap
		
		for(int i=0; i<soLuong; i++){
			SinhVien sv;
			sv.setMaSV(input[i][0]->getContent());
			sv.setHo(input[i][1]->getContent());
			sv.setTen(input[i][2]->getContent());
			
			if(inputPhai[i][0]->getId() == "chon")
				sv.setPhai("Nam");
			else if(inputPhai[i][1]->getId() == "chon")
				sv.setPhai("Nu");	
			
			sv.setSDT(input[i][4]->getContent());
			
			NodeSV *p = new NodeSV(sv);
			this->them_SV(p);
		}
		
		// giai phong arr input
		for(int i=0; i<nRow; i++){
			for(int j=0; j<nCol; j++){
				delete input[i][j];
				
				if(j<2)	delete inputPhai[i][j];
			}
			delete[] input[i]; delete[] inputPhai[i];
		}
		delete [] input; delete[] inputPhai;
		newTable.freeTable();
		cout<<"\nDa luu lai ds sinh vien";
		
	}
	
	void chon_SV(Action thaoTac){
		int viTriChon = 1;
		int soLuongSV = this->demSoLuongSV();
			char *intStr;  itoa(soLuongSV,intStr, 10);
			string strSL = string(intStr);
			string maLop = this->head->getData_SV().getMaLop();
		string titleSub;
		
		while(!isNULL_SV()){ soLuongSV = this->demSoLuongSV();
			if(thaoTac != THEM)
				titleSub = "IN DANH SACH SINH VIEN 1 LOP";
			else 
				titleSub = "NHAP DANH SACH SINH VIEN";
			
			Label title(
					titleSub.c_str(),
					LABEL_X,
					LABEL_Y,
					LABEL_X + LABEL_WIDTH,
					LABEL_Y + LABEL_HEIGHT,
					clgreen,
					cllightgreen,
					cllightwhite
				);
				
			title.printLabel(
						"Lop",
						maLop,
						"So sinh vien hien tai",
						strSL
					);
			
			
			switch(thaoTac){
				case XUAT:{
					xuatDSTheoTrang_SV(viTriChon, thaoTac);
					//clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					break;
				}
				case THEM:{
					clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					formNhap_SV(maLop, thaoTac);
					if(thaoTac == THEM){
						MessageBox(
							NULL,
							"LUU THANH CONG DS SINH VIEN VUA NHAP !!!",
							"THONG BAO",
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						thaoTac = XUAT;
					}
					break;
				}
				
				case SUA:{
					
					break;
				}
				
				case XOA:{
					if(viTriChon < soLuongSV){
						int trangThai = 0;
						NodeSV *sv = tim_SV(viTriChon);
						if(sv!= NULL)
							trangThai =	xoa_SV(sv->getData_SV().getMaSV());
						if(trangThai == 1){
							MessageBox(
						        NULL,
						        "XOA SINH VIEN THANH CONG !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
						}else if(trangThai == -1){
							MessageBox(
						        NULL,
						        "XOA SINH VIEN THAT BAI !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
						}
						thaoTac = XUAT;
						if(isNULL_SV())	clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						//this->chon_SV(thaoTac);
					}
					break;
				}
				
				 
			}
		} if(isNULL_SV()){
			MessageBox(
		        NULL,
		        "LOP KHONG CO SINH VIEN NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
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
	//delete next;
	cout<<"\n delete next";
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



void DSSV::setHead_DSSV(NodeSV *head){
	this->head = head;
}

NodeSV* &DSSV::getHead_DSSV(){
	return this->head;
}

bool DSSV::isNULL_SV(){
	return this->head == NULL;
}



void DSSV::themDau_SV(NodeSV * SV){
	SV->setNext_SV(this->head);
	this->head = SV->getNode_SV();
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
			delete q;
			//q->~NodeSV();
			return 1;
		}
	
	
	return -1;
}
