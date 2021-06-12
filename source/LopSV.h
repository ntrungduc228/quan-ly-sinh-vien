#pragma once
#include "Const.h"

class LopSV{
private:
	string maLop;
	DSSV dssv;
public:
	LopSV();
	~LopSV();
	
	void setMaLop(string maLop);
	void setTenLop(string tenLop);
	
	
	string getMaLop();
	string getTenLop();
	DSSV &getDS_SV(){
		return this->dssv;	
	}
	
	/*int demSoLuongSV(){
		int n = 0;
		for(NodeSV *p = dssv.getHead_DSSV(); p != NULL ; n++,p=(p->getNext_SV()))
		
		return n;
	}*/
	
	void setDS_SV(DSSV ds){
		this->dssv.setHead_DSSV(ds.getHead_DSSV());
		cout<<"\nXuat trong ham setDS_SV";
		this->dssv.xuatDS_SV();
		//this->dssv = ds;
	}
	
	void nhap_LSV(){
		cin.ignore();
		cout<<"\nNhap ma lop: ";
		getline(cin, maLop);
	//	cout<<"\nNhap ten lop: ";
		//getline(cin, tenLop);
	}
	
	void xuat_LSV(){
		cout<<"\nNhap ma lop: "<<maLop<<" "<<this->getDS_SV().demSoLuongSV();
		//cout<<"\nNhap ten lop: "<<tenLop;
	}
};

class DSLopSV{
private:
	LopSV *lopSV[MAX_LOPSV]  = {NULL};
	int n;
public:
	DSLopSV();
	~DSLopSV();
	
	void freeDS_LSV(){
		for(int i=0; i<n; i++){
			if(lopSV[i] != NULL) {
				lopSV[i]->getDS_SV().freeDS_SV(lopSV[i]->getDS_SV().getHead_DSSV());
				delete lopSV[i];
			}
		}
	}
	
	void setN(int n);
	int getN();
	
	LopSV *&getLopSV_LSV(int viTri);
	
	void loadData_LSV(){
		ifstream fileIn; char temp;
		fileIn.open("data\\DSLSV.txt", ios::in);
		if(fileIn.is_open()){
			string str;
			while (!fileIn.eof()){
			
				getline(fileIn, str, '\n');
				if(str=="") break;
				
				/*getline(fileIn, str, '\n');
				this->lopSV[this->n]->setTenLop(str);*/
	
				them_LSV(str);
				if (fileIn.eof()) break;
			}
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS LOP SINH VIEN";
			MessageBox(
					NULL,
					"KHONG TIM THAY FILE DU LIEU DS LOP SINH VIEN",
					"THONG BAO",
					MB_ICONERROR | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
			); 
			loadFileIsSuccess = false;
		}
			
		fileIn.close();
	}
	
	void loadDataDS_SV(){
		ifstream fileIn; char temp; string tempStr;
		fileIn.open("data\\DSSV.txt",ios::in);
		if (fileIn.is_open())
		{
			//if(DSSV.pHead==NULL)
			while (!fileIn.eof())
			{
				SinhVien data;
				
				getline(fileIn, tempStr, ',');
				if(tempStr=="") break;
				data.setMaSV(tempStr);
				getline(fileIn, tempStr, ',');
				data.setHo(tempStr);
				getline(fileIn, tempStr, ',');
				data.setTen(tempStr);
				getline(fileIn, tempStr, ',');
				data.setPhai(tempStr);
				getline(fileIn, tempStr, ',');
				data.setSDT(tempStr);
				getline(fileIn, tempStr,'\n');
				data.setMaLop(tempStr);
	
				NodeSV* SV = new NodeSV(data);
				/*int viTriThem = timviTri_SV(DSSV, SV);
				them_SV(DSSV,SV, viTriThem);*/
		
				int viTriLop = tim_LSV(SV->getData_SV().getMaLop());
				if (viTriLop != -1)	{
					this->lopSV[viTriLop]->getDS_SV().them_SV(SV);
				}
				if (fileIn.eof()) break;
				
			}
		}else { cout<<"\nKHONG TIM THAY FILE DU LIEU DS SINH VIEN";
			MessageBox(
					NULL,
					"KHONG TIM THAY FILE DU LIEU DS SINH VIEN",
					"THONG BAO",
					MB_ICONERROR | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
				);
			loadFileIsSuccess = false;
		}
		
		fileIn.close();
	}
	
	void writeData_LSV(LopSV *LSV,ofstream &fileOut);
	void writeDataDS_LSV();
	
	void writeDataDS_SV(){
		
		ofstream fileOut(PATH_SAVE_SV,ios::out);
		if(fileOut.is_open()){
			
			for(int i=0; i<n; i++){
				if(this->lopSV[i]->getDS_SV().isNULL_SV()!=true)
						
				for(NodeSV *p = this->lopSV[i]->getDS_SV().getHead_DSSV(); p!=NULL; p=(p->getNext_SV())){
						p->writeData_SV(p->getData_SV(),fileOut);
					}
			}
			
			
		}
		fileOut.close();
		
	}
	
	bool isNull_LSV();
	bool isFull_LSV();
	int them_LSV(string &maLopSV);
	int tim_LSV(string maLop);
	
	int timSV_LSV(string maSV){
		for(int i=0; i<n; i++){
			if(this->lopSV[i]->getDS_SV().tim_SV(maSV)!=-1) return i;
		}
		
		return -1;
	}
	
	void xuatDS_LSV(){
		if(n==0) {
			cout<<"\n lopSV rong";
			return;
		}
		for(int i=0; i<n; i++){
			lopSV[i]->xuat_LSV();
		}
	}
	
	NodeSV * layInfo_SV(string maSV){
		for(int i=0; i<n; i++){
			if(!lopSV[i]->getDS_SV().isNULL_SV()){
				for(NodeSV *p = lopSV[i]->getDS_SV().getHead_DSSV(); p!=NULL; p=p->getNext_SV() )
					if(p->getData_SV().getMaSV() == maSV)
						return p;
			}
		}
		
		return NULL;
	}
	
	void xuatDS1Trang_LSV(LopSV *lopSV[], int batDau, int ketThuc, Button *printButton[], Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT, soLuongSV; 
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack); 
		
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
					string((newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(2)->getWidth();
				
				
				View view("",x,yBtn, x+newTable.getCols(3)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
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
				
			// xuat du lieu moi
			//setbkcolor(cllightwhite);
			outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
			x += newTable.getCols(0)->getWidth();
			
			// xoa du lieu cu
			//setbkcolor(clyellow);
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
			//setbkcolor(cllightwhite);
			outtextxy(
					x + newTable.getCols(1)->getWidth()/2  - textwidth(lopSV[i]->getMaLop().c_str())/2, 
					y, 
					lopSV[i]->getMaLop().c_str()
				);
				
			x += newTable.getCols(1)->getWidth();
				
			// xoa du lieu cu
			outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(2)->getWidth() - 3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
			
			soLuongSV = convertIntToString(lopSV[i]->getDS_SV().demSoLuongSV());
				
			// xuat du lieu moi
			outtextxy(
					x + newTable.getCols(2)->getWidth()/2  - textwidth(soLuongSV.c_str())/2, 
					y, 
					soLuongSV.c_str()
				);
			
			x += newTable.getCols(2)->getWidth();
			
		if(printButton[i] == NULL)
			printButton[i] = new Button(
										 "Xem DSSV",
										 strSTT, 
										 x+30, 
										 yBtn+3, 
										 x+30+checkBoxButtonWidth+30,
										 yBtn-3+checkBoxButtonHeight, 
										 claqua, 
										 cllightblue, 
										 clblack
										);
			printButton[i]->draw();
				
			
			x = tableLeft ;
		}
	}
	
	void locDS_LSV(string content, LopSV *lop[], int &nFilter, int &tongSoTrang){
		nFilter = 0;
		// chuoi khac rong
		if(!content.empty()){
			for(int i=0; i<this->n; i++){
				if(lopSV[i]->getMaLop().find(content) != string::npos)
					lop[nFilter++] = lopSV[i];
			}
			
		}else{
			for(int i=0; i<this->n; i++)
				lop[nFilter++] = lopSV[i];
		}
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;		
	}
	
	void xuatDSTheoTrang_LSV(int &viTriChon, Action &thaoTac){
		int tongSoDong = n;
		int nFilter = n;
		
		LopSV *lop[n];
		for(int i=0; i<n; i++)
			lop[i] = this->lopSV[i];
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *printButton[tongSoDong] = {NULL};
		
		Table newTable = table_LSV();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ten lop hoc:" ,"N", MAX_MALOPSV, NON_SPACE, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		//newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
	
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnAdd("THEM LOP HOC","btnAdd",400, 80, 430 + buttonWidth, 120);
		btnAdd.draw();
		
		int x,y;
		
		while(true){
			delay(0.000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	
            	if(newInput.isClicked(x,y)){
            		newInput.requestFocus();
            		newInput.draw();
				}
            	
            	// checked if btn is clicked xem dssv
            	for(int i=batDau; i<ketThuc; i++){
            		if(printButton[i] != NULL){
            			if(printButton[i]->isClicked(x,y) && printButton[i]->getEnable()){
            				// tim vi tri thuc(real) cua lop sinh vien neu dc filter
            				string tempMaLop = lop[i]->getMaLop();
								for(int vt = 0; vt<this->n; vt++){
									if(lopSV[vt]->getMaLop() == tempMaLop){
										viTriChon = vt; break;
									}
								}
								
	            			if(lop[viTriChon]->getDS_SV().isNULL_SV()){
	            					MessageBox(
								        NULL,
								        "LOP KHONG CO SINH VIEN NAO !!!",
								        "THONG BAO",
								        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						    		);
						    		
						    		int isConfirmed = MessageBox(
											        NULL,
											        "BAN CO THEM SINH VIEN CHO LOP NAY",
											        "THONG BAO",
											        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
									    		);
									switch(isConfirmed){
										case IDCANCEL:{
											break;
										}
										case IDOK: default:{
											thaoTac = NHAP_DS;
											newTable.freeTable();
											freeArrButton(printButton, nFilter);
											return;
										}
									}
						    		
							}else{
								thaoTac = XUAT;
	            				newTable.freeTable();
								freeArrButton(printButton, nFilter);
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
            		
            		xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
				
				if(btnAdd.isClicked(x,y)){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = THEM;
					newTable.freeTable();
					freeArrButton(printButton, nFilter);
					return;
				}
				
        	}
        	
        	// Filter by input
			if(kbhit()){
					freeArrButton(printButton, nFilter);
					char ch = getch();
					//newInput.xuLyNhapMa_LSV((int)ch);
					newInput.appendText(ch);
					newInput.draw();
					locDS_LSV(newInput.getContent(), lop, nFilter, tongSoTrang);
					
					batDau = 0; trangHienTai = 1;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
					xuatDS1Trang_LSV(lop, batDau, ketThuc, printButton, newTable);
					inTrang(trangHienTai, tongSoTrang);
			}
		}
		
	}


	void formThem_LSV(string &maLopSV, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300);
		
		Input input("","Nhap ma lop: " ,"N", MAX_MALOPSV, NON_SPACE,  650, 200, 650 + 300, 200 + INPUT_HEIGHT);
		input.requestFocus();
		input.setContent(maLopSV);
		input.draw();
		
		Button btnThem("Them","T",650, 300, 650+buttonWidth, 300+40, claqua, cllightblue, clblack);
		btnThem.draw();
		
		Button btnHuy("Huy", "H", 850, 300, 850+buttonWidth, 300+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y;
		
		while(true){
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnHuy.isClicked(x,y)){
					thaoTac = HUY; 
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				if(btnThem.isClicked(x,y) && !input.getContent().empty()){
					int isConfirmed = MessageBox(
											 NULL,
											"BAN CO CHAC CHAN MUON THEM LOP SINH VIEN NAY",
											"THONG BAO",
											MB_ICONINFORMATION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
									    );
									    
					switch(isConfirmed){
						case IDCANCEL:{
							break;
						}
						
						case IDOK: default:{
							maLopSV = input.getContent();
							return;
						}
					}
					
				}
			}
			
			if(kbhit()){
				char ch = getch();
				input.appendText(ch);
				input.draw();
			}
		}
	}

	void chon_LSV(){
		while(n>0){
			string strN = convertIntToString(n);
			Label title(
					"IN DANH SACH LOP SINH VIEN",
					LABEL_X,
					LABEL_Y,
					LABEL_X + LABEL_WIDTH,
					LABEL_Y + LABEL_HEIGHT,
					clgreen,
					cllightgreen,
					cllightwhite
				);
				
			title.printLabel(
						"Tong so lop",
						strN
					);
			
			int viTriChon = 0; Action thaoTac = XUAT;
			xuatDSTheoTrang_LSV(viTriChon, thaoTac);
			string maLopSV;
			
			switch(thaoTac){
				case XUAT:{
					if(viTriChon < n){
						clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
						this->lopSV[viTriChon]->getDS_SV().chon_SV(this->lopSV[viTriChon]->getMaLop(), thaoTac);
					}
					break;
				}
					
				case THEM:{
					formThem_LSV(maLopSV, thaoTac);
					if(thaoTac == HUY){
						thaoTac = XUAT;
						chon_LSV();
					}else if(thaoTac == THEM){						
						cout<<"\nma lop can them: "<<maLopSV;
						int kq = them_LSV(maLopSV);
						switch(kq){
							case -1:{ // ds lop sv da full
								MessageBox(
										NULL,
										"DANH SACH LOP SINH VIEN DA DAY !!!",
										"THONG BAO",
										MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
									);
								break;
							}
								
							case 1:{ // them thanh cong
								MessageBox(
										NULL,
										"THEM LOP SINH VIEN THANH CONG !!!",
										"THONG BAO",
										MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
									);
								clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
								thaoTac = XUAT; chon_LSV();
								break;
							}
								
							case 2: default:{ // lop sv da ton tai
								MessageBox(
								        NULL,
								        "LOP SINH VIEN NAY DA TON TAI !!!",
								        "THONG BAO",
								        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							   		);
								break;
							}
						}	
						
					}
					break;
				}
					
				case NHAP_DS:{
					if(viTriChon < n){
						clearRegion(tableLeft, INPUT_Y-30, frameRight - 12, frameBottom - 12);
						thaoTac = THEM;
						this->lopSV[viTriChon]->getDS_SV().chon_SV(this->lopSV[viTriChon]->getMaLop(), thaoTac);
					}
					break;
				}
			} // switch case 
				
			
		} if(n==0){
			MessageBox(
		        NULL,
		        "HIEN KHONG CO LOP SINH VIEN NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}
};


/*
** ================ Lop sinh vien ================
*/

LopSV::LopSV(){
	maLop = "";
	//tenLop = "";
	dssv.setHead_DSSV(NULL);
}

LopSV::~LopSV(){
	
}

void LopSV::setMaLop(string maLop){
	this->maLop = maLop;
}

void LopSV::setTenLop(string tenLop){
//	this->tenLop = tenLop;
}


	
string LopSV::getMaLop(){
	return this->maLop;
}

string LopSV::getTenLop(){
//	return this->tenLop;
}



/*
** ================ Danh sach lop sinh vien ================
*/

DSLopSV::DSLopSV(){
	n = 0;
	for(int i=0; i<MAX_LOPSV; i++) lopSV[i] = NULL;
}

DSLopSV::~DSLopSV(){
	//for(int i=0; i<MAX_LOPSV; i++) delete lopSV[i] ;
	cout<<"\nDelete ds lop sv";
}

void DSLopSV::setN(int n){
	this->n = n;
}

int DSLopSV::getN(){
	return this->n;
}

bool DSLopSV::isNull_LSV(){
	return this->n == 0;
}

bool DSLopSV::isFull_LSV(){
	return this->n == MAX_LOPSV;
}

int DSLopSV::them_LSV(string &maLopSV){
	if(isFull_LSV()) return -1;
	
	int vt=0;
	for(; vt<n ; vt++) {
		if(lopSV[vt]->getMaLop() > maLopSV) break;
		if(lopSV[vt]->getMaLop() == maLopSV ) return 2; // lop sv da ton tai
	}
	
	LopSV *LSV = new LopSV;
	LSV->setMaLop(maLopSV);
	
	for(int i=n; i>vt; i--)
		lopSV[i] = lopSV[i-1];
	
	lopSV[vt] = LSV;
	n++;
	
	//this->lopSV[this->n++] = LSV;
	return 1;
}

int DSLopSV::tim_LSV(string maLop){
	if(isNull_LSV()) return -1;
	
	for(int i=0; i<n; i++)
		if(this->lopSV[i]->getMaLop() == maLop ) return i;
	
	return -1;
}

void DSLopSV::writeData_LSV(LopSV *LSV,ofstream &fileOut){
	char temp = ',';
	fileOut << LSV->getMaLop();
	/*fileOut << temp;
	fileOut << LSV->getTenLop();
	fileOut << temp;*/
	fileOut << "\n";
}

void DSLopSV::writeDataDS_LSV(){
	ofstream fileOut;
	fileOut.open(PATH_SAVE_LSV, ios::out);
	if (fileOut.is_open()) {
		for (int i = 0; i < this->n; i++)	{
				writeData_LSV(this->lopSV[i], fileOut);
			}
		
	}
	fileOut.close();
}

LopSV *&DSLopSV::getLopSV_LSV(int viTri){
		//if(isNull_LSV()) return NULL;
		
				return this->lopSV[viTri];	
}
