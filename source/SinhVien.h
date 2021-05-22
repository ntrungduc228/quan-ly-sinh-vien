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
	~DSSV();
	
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
	
	void freeDS_SV(){
		
		NodeSV* SV = NULL;
		while (this->head != NULL)
		{
			SV = head;
			head = head->getNext_SV();
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
	
	void xuatDS1Trang_SV(NodeSV *head, int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT;	
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack);
		
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
			
			if(i != batDau && p!=NULL) p = p->getNext_SV(); // i != batDau de khong bi mat du lieu dong dau tien	
				
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
		}
	}
	
	void locDS_SV(string content, DSSV &dssv, int &tongSoTrang){
		dssv.freeDS_SV();
		dssv.setHead_DSSV(NULL);
		/*if(!content.empty()){
			for(NodeSV *p = this->head; p!=NULL; p=p->getNext_SV()){
				if(p->getData_SV().getMaSV().find(content) != string::npos){
					//cout<<"\n"<<p->getData_SV().getMaSV();
					NodeSV*sv = new NodeSV(p->getData_SV());
					 dssv.them_SV(sv);
				}
			}
			
		}*///else{
			dssv.setHead_DSSV( this->head);
		//}
		
		int nFilter = 0;
		nFilter = dssv.isNULL_SV() ? 0 : dssv.demSoLuongSV();
		//for(NodeSV *p=dssv.getHead_DSSV(); p!=NULL; nFilter++, p=p->getNext_SV());
		cout<<"\nnFilter: "<<nFilter;
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
	}
	
	void xuatDSTheoTrang_SV(int &viTriChon, Action &thaoTac){
		
		DSSV dssv; dssv.setHead_DSSV(this->head);
		
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
		
		Input newInput("","Nhap ma sinh vien:" ,"",MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		//newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
		newInput.requestFocus();
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		int x,y;
		
		while(true) {
			delay(0.000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	// checked if button sua || xoa is clicked
            	for(int i=batDau; i<ketThuc; i++){
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
								viTriChon = i;  thaoTac = XOA;
								newTable.freeTable();
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
        	
				xuatDS1Trang_SV(dssv.getHead_DSSV(), batDau, ketThuc, editButton, deleteButton, newTable);
				inTrang(trangHienTai, tongSoTrang);
			}
		
			// Filter by input
			if(kbhit()){
				freeArrButton(editButton, nFilter);
				freeArrButton(deleteButton, nFilter);
				char ch = getch();
				newInput.appendText(ch);
				newInput.draw();
				locDS_SV(newInput.getContent(), dssv, tongSoTrang);
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				xuatDS1Trang_SV(dssv.getHead_DSSV(), batDau, ketThuc, editButton, deleteButton, newTable);
				inTrang(trangHienTai, tongSoTrang);
			}
		}
	}
	
	void chon_SV(Action thaoTac){
		if(!isNULL_SV()){
			
			int soLuongSV = this->demSoLuongSV();
			char *intStr;  itoa(soLuongSV,intStr, 10);
			string strSL = string(intStr);
			string maLop = this->head->getData_SV().getMaLop();
			
			int viTriChon = 1;
			Label title(
					"IN DANH SACH SINH VIEN 1 LOP",
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
						"Tong so sinh vien",
						strSL
					);
			
			
			xuatDSTheoTrang_SV(viTriChon, thaoTac);
			
			switch(thaoTac){
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
						if(isNULL_SV())	
							clearRegion(tableLeft, INPUT_Y - 30, frameRight - 12, frameBottom - 12);
						this->chon_SV(thaoTac);
					}
					break;
				}
				
				 
			}
		}else {
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
	//delete head;
	cout<<"\ndelete head sv";
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
			q->~NodeSV();
			return 1;
		}
	
	
	return -1;
}
