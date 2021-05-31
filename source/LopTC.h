#pragma once
#include "Const.h"

class LopTC{
private:
	int maLopTC;
	string maMH;
	int nienKhoa;
	int hocKy;
	int nhom;
	int svMax;
	int svMin;
	bool huyLop;
	int soSVDK;
	DSDK dsdk;
public:
	LopTC();
	
	
	void setMaLopTC(int maLopTC);
	void setMaMH(string maMH);
	void setNienKhoa(int khoa);
	void setHocKy(int hocKy);
	void setNhom(int nhom);
	void setSVMax(int svMax);
	void setSVMin(int svMin);
	void setTrangThai(bool huyLop);
	void setDSDK(DSDK DS);
	
	int getMaLopTC();
	string getMaMH();
	int getNienKhoa();
	int getHocKy();
	int getNhom();
	int getSVMax();
	int getSVMin();
	bool getTrangThai();
	DSDK &getDSDK(){
		return this->dsdk;
	}
	
	int getSoSVDK(){
		return this->soSVDK;
	}
	
	void setSoSVDK(int soSVDK){
		this->soSVDK = soSVDK;
	}
	
	void taoMaLop_LTC(int nLTC)	{
			this->maLopTC = nLTC +1;
		}
	
	void nhap_LTC(){
		cin.ignore();
		cout<<"\nNhap ma mh ";
		getline(cin,maMH);
		cout<<"\nNhap nien khoa: ";
		cin>>nienKhoa;
		cout<<"\nNhap hoc ky: ";
		cin>>hocKy;
		cout<<"\nNhap nhom: ";
		cin>>nhom;
		cout<<"\nNhap so sv max: ";
		cin>>svMax;
		cout<<"\nNhap so sv min: ";
		cin>>svMin;
		
	}
	
	
	void xuat_LTC(){
		cout<<"\nMa lop TC: "<<maLopTC;
		cout<<"\nMa mh: "<<maMH;
		cout<<"\nkhoa: "<<nienKhoa;
		cout<<"\nHoc ky: "<<hocKy;
		cout<<"\nNhom: "<<nhom;
		cout<<"\nsvMax: "<<svMax;
		cout<<"\nsvMin: "<<svMin;
		if(huyLop) cout<<"\nHuy lop: true";
		else cout<<"\nSo sv dk: "<<soSVDK;
		if(dsdk.getHead_DSDK() == NULL) cout<<"\ndk null";
		else cout<<"\ndsk not null";
	}
	
	bool checkTrung_LTC(LopTC ltc){
		
		if(this->maMH == ltc.maMH && this->nienKhoa == ltc.nienKhoa && this->hocKy == ltc.hocKy && this->nhom == ltc.nhom)
			return true;
			
		return false;
	}
	
	void huyLopTC(){
		if(soSVDK < svMin && huyLop == false)
			huyLop = true;
	}
};

class DSLopTC{
private:
	LopTC *lopTC[MAX_LOPTC] = {NULL};
	int n;	
public:
	
	DSLopTC();
	~DSLopTC();
	int getN();
	
	bool isNull_LTC();
	bool isFull_LTC();
	
	LopTC *&getLopTC(int viTri){
		return lopTC[viTri];
		
	}

	int them_LTC(LopTC *LTC);
	int xoa_LTC(int maLopTC);
	int tim_LTC(int maLopTC);
	
	void writeData_LTC(LopTC *LTC, ofstream &fileOut);
	void writeDataDS_LTC();
	
	void huyLopDS_LTC(){
		for(int i=0; i<n; i++)
			this->lopTC[i]->huyLopTC();
	}
	
	void loadDataDS_DK(){
		ifstream fileIn; char temp; int maLop; int viTriLop=0; string tempStr; float tempFloat;
		fileIn.open("data\\DSDK.txt", ios::in);
		if (fileIn.is_open())	{
			
				while (!fileIn.eof())	{
					
					fileIn >> maLop;
					viTriLop = this->tim_LTC( maLop);
					if (viTriLop != -1)	{
						fileIn >> temp;
						SVDangKy sv;
						
						getline(fileIn, tempStr, ',');
						sv.setMaSV(tempStr);
						fileIn >> tempFloat;
						sv.setDiem(tempFloat);
						
						NodeDK* DK = new NodeDK(sv);
	
						//cout <<maLop<<" "<<viTriLop<<" " <<DK->data.MASV << " " << DK->data.DIEM<<endl;
						
						this->lopTC[viTriLop]->getDSDK().them_DK(DK);
						this->lopTC[viTriLop]->setSoSVDK(this->lopTC[viTriLop]->getSoSVDK() + 1);
					}
	
	
					if (fileIn.eof()) break;
	
				}
		}
		
		fileIn.close();
	}
	
	void loadDataDS_LTC(){
		ifstream fileIn; char temp;
		fileIn.open("data\\DSLTC.txt", ios::in);
		int tempInt; string tempStr;
		while (!fileIn.eof())
		{
			
			lopTC[n] = new LopTC;
			fileIn >> tempInt;	lopTC[n]->setMaLopTC(tempInt);
			if(tempInt==0) break;
			fileIn >> temp;
			getline(fileIn, tempStr, ','); lopTC[n]->setMaMH(tempStr);
			fileIn >> tempInt; lopTC[n]->setNienKhoa(tempInt);
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setHocKy(tempInt);
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setNhom(tempInt);
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setSVMax(tempInt);
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setSVMin(tempInt);
			fileIn >> temp;
			fileIn >> tempInt; lopTC[n]->setTrangThai(bool(tempInt));
			
	
			lopTC[n]->getDSDK().setHead_DSDK(NULL);
			
	
			this->n++;
	
			if (fileIn.eof()) break;
		}
		fileIn.close();
	}
	
	void xuatDS_LTC(){
		if(n==0) cout<<"\nDS ltc rong";
		for(int i=0; i<n; i++){
			cout<<"\n";
			lopTC[i]->xuat_LTC();
		}
	}
	
	int sua_LTC(int maLopTC){
		int viTri = tim_LTC( maLopTC);
		if (viTri >= 0)	{
			
			this->lopTC[viTri]->nhap_LTC();
			return 1;
		}
		
		return -1;
	}
	
	bool checkDK_LTC(int viTri, string maSV){
		
		if(viTri < n ){
			return this->lopTC[viTri]->getDSDK().checkSV_DK(maSV);
		}
		
		return false;
	}
	
	void DK_LTC(int viTri, NodeDK *DK){
		if(viTri < n){
			
			this->lopTC[viTri]->getDSDK().them_DK(DK);
			
			this->lopTC[viTri]->setSoSVDK(this->lopTC[viTri]->getSoSVDK() + 1);
		}
	}
	
	void xuatDSDK_LTC(int viTri){
		if(this->lopTC[viTri]!= NULL){
			this->lopTC[viTri]->getDSDK().xuatDS_DK();
			
		}
	}
	
	bool checkTrungDS_LTC(LopTC *ltc){
		if(this->isNull_LTC()) return false;
		
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->checkTrung_LTC(*(ltc))) return true;
		}
		
		return false;
	}
	
	void writeDataDS_DK(){
		ofstream fileOut;
		fileOut.open(PATH_SAVE_DK, ios::out);
		if (fileOut.is_open())	{
				for (int i = 0; i < n; i++)	{
					for(NodeDK *k = this->lopTC[i]->getDSDK().getHead_DSDK(); k!= NULL; k=k->getNext_DK())
						k->writeData_DK(k->getData_DK(), this->lopTC[i]->getMaLopTC(), fileOut);
				}
			
		}
		fileOut.close();
	}
	
	void nhapDiem_LTC(int viTri){
		if(viTri < n){
			float diem; int i=1;
			for(NodeDK *k = this->lopTC[viTri]->getDSDK().getHead_DSDK(); k!= NULL;i++, k=k->getNext_DK()){
				cout<<"\nNhap diem ms sinh vien "<<k->getData_DK().getMaSV()<<" ";
				cin>>diem;
				k->getData_DK().setDiem(diem);
			}	
		}
	}
	
	void xuatDiem_LTC(int viTri){
		if(viTri < n){
			 int i=1;
			for(NodeDK *k = this->lopTC[viTri]->getDSDK().getHead_DSDK(); k!= NULL;i++, k=k->getNext_DK()){
				
				k->getData_DK().xuat_DK();
			}	
		}
	}
	
	void xuatDS1Trang_LTC(LopTC *loptc[], MonHoc *arrMH, int soLuongMH,  int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac){
		int soDong = ketThuc % MAX_DONG_1_TRANG; 
		if(soDong == 0) soDong = MAX_DONG_1_TRANG;
		 
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT;	string tenMH, trangThai="TRUE";
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack); 
		
		for(int i = batDau; i < soDong; i++){ 
			
			setbkcolor(cllightwhite); setcolor(clblack); 
			yBtn += rowTableHeight;
			
			// in ra chuoi rong cac dong con thua
			if(i >= ketThuc){
				//setbkcolor(clyellow);
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
					string((newTable.getCols(4)->getWidth() -2 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(4)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(5)->getWidth() -2 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(5)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(6)->getWidth()-3 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(6)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(7)->getWidth() -3- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(7)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(8)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(8)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(9)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(9)->getWidth();
				
				View view("",x,yBtn, x+newTable.getCols(10)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
				view.draw();
				
				x =  tableLeft;
				continue;
			}
		
			y += rowTableHeight;
			strSTT = convertIntToString(i+1);
			
			// xoa du lieu cu
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
						x + newTable.getCols(1)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getMaLopTC()).c_str())/2, 
						y, 
						convertIntToString(loptc[i]->getMaLopTC()).c_str()
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
						x + newTable.getCols(2)->getWidth()/2  - textwidth(loptc[i]->getMaMH().c_str())/2, 
						y, 
						loptc[i]->getMaMH().c_str()
					);				
				x += newTable.getCols(2)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(3)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			for(int j=0; j<soLuongMH; j++){
				if(arrMH[j].getMaMH() == loptc[i]->getMaMH()){
					tenMH = arrMH[j].getTenMH(); j = soLuongMH;
				}
			}
				
			// xuat du lieu moi
				outtextxy(
						x + 10,
						y, 
						tenMH.c_str()
					);				
				x += newTable.getCols(3)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(4)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(4)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getNienKhoa()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getNienKhoa()).c_str()
					);
				x += newTable.getCols(4)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(5)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(5)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getHocKy()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getHocKy()).c_str()
					);
				x += newTable.getCols(5)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(6)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(6)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getNhom()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getNhom()).c_str()
					);
				x += newTable.getCols(6)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(7)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(7)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getSVMax()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getSVMax()).c_str()
					);
				x += newTable.getCols(7)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(8)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(8)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getSVMax() - loptc[i]->getSoSVDK()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getSVMax() - loptc[i]->getSoSVDK()).c_str()
					);
				x += newTable.getCols(8)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(9)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
			
				trangThai = loptc[i]->getTrangThai() ? "TRUE" : "FALSE";	
			
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(9)->getWidth()/2  - textwidth(trangThai.c_str())/2,
						y, 
						trangThai.c_str()
					);
				x += newTable.getCols(9)->getWidth();
			
			if(thaoTac != DIEM){
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
			}else {
				if(editButton[i] == NULL)
					editButton[i] = new Button(
										 "Xem Diem",
										 strSTT, 
										 x+15, 
										 yBtn+3, 
										 x+15+checkBoxButtonWidth+30,
										 yBtn-3+checkBoxButtonHeight, 
										 claqua, 
										 cllightblue, 
										 clblack
									);
				editButton[i]->draw();
			}
			
				
			x = tableLeft;
		}
	}

	
	void locDS_LTC(string content, LopTC *loptc[], int &nFilter, int &tongSoTrang){
		// reset so lop tin chi loc ra duoc
		nFilter = 0; string strMaLopTC;
		if(!content.empty()){
			for(int i=0; i<n; i++){
				strMaLopTC = convertIntToString(this->lopTC[i]->getMaLopTC());
				if(strMaLopTC.find(content) != string::npos){
					loptc[nFilter++] = this->lopTC[i];
				}
			}
		}else {
			for(int i=0; i<n; i++){
				loptc[nFilter++] = this->lopTC[i];
			}
		}
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
	}
	
	void xuatDSTheoTrang_LTC(TREE DSMH, int &viTriChon, Action &thaoTac){
		int tongSoDong = n;
		int nFilter = n; int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		cout<<"\nSo luong trc "<<soLuongMH;
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0; cout<<"\nToi dayyyyy";
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH); 
		cout<<"\nSo luong sau "<<soLuongMH;
		LopTC *loptc[n] = {NULL};
		for(int i=0; i<n; i++) {
		 	loptc[i] = this->lopTC[i];
		}
		
		cout<<"\nVO day r";
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *editButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		Table newTable = table_LTC();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		Input newInput("","Nhap ma lop tc:" ,"N", 5, NUMBER, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
		newInput.draw();
		//newInput.setBorderColor(INPUT_BORDER_VALIDATION); // cllightgreen;
		newInput.requestFocus();
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		Button btnThem("THEM","them",400, 80, 400 + buttonWidth, 120);
		Button btnXuat("XEM DSSV","xuat", 480, 80, 480 + buttonWidth, 120);
		
		if(thaoTac == XUAT)	{
			btnThem.draw();
			btnXuat.draw();
		}
		
		int x,y;
		
		while(true){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	clearmouseclick(WM_LBUTTONDOWN);
            	
            	// is clicked button Sua || Xoa
            	for(int i=batDau; i<ketThuc; i++){
					if(thaoTac != DIEM) {
						if(editButton[i] != NULL && deleteButton[i] != NULL){
							// btn sua
							if(editButton[i]->isClicked(x,y)){
								cout<<"\n"<<i<<" is clicked "<<editButton[i]->getText();
								MessageBox(
							        NULL,
							        "Ban muon sua ltc",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK
					    		);
							}
							// btn xoa
						if(deleteButton[i]->isClicked(x,y)){
							// tim vi tri thuc(real) cua lop tc can xoa khi sau da filter trong mang lopTC
							int tempMaLopTC = loptc[i]->getMaLopTC();
								viTriChon = tim_LTC(tempMaLopTC);
								if(lopTC[viTriChon]->getSoSVDK() == 0){
									int isConfirmed = MessageBox(
													        NULL,
													        "BAN CO CHAC CHAN MUON XOA LOP TIN CHI NAY",
													        "THONG BAO",
													        MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
												    		);
												    		
									switch(isConfirmed){
										case IDCANCEL:{
												viTriChon=0;
												break;
											}
										
										case IDOK: default:{
												
												thaoTac = XOA;
												newTable.freeTable();
												delete[] arrMH;
												freeArrButton(editButton, nFilter);
												freeArrButton(deleteButton, nFilter);
												return; 	
											}
									}
								} else {
									MessageBox(
										       NULL,
										       "LOP DA CO SINH VIEN, KHONG THE XOA !!!",
										       "THONG BAO",
										       MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								    		);
								}
							}
						}
					}else{ // xem diem
						if(editButton[i] != NULL){
							if(editButton[i]->isClicked(x,y)){
								// tim vi tri thuc(real) cua lop tc can xoa khi sau da filter trong mang lopTC
								int tempMaLopTC = loptc[i]->getMaLopTC();
								viTriChon = tim_LTC(tempMaLopTC);
								
								if(lopTC[viTriChon]->getSoSVDK() != 0){
									thaoTac = DIEM;
									newTable.freeTable();
									delete[] arrMH;
									freeArrButton(editButton, nFilter);
									freeArrButton(deleteButton, nFilter);
									return;
								}else{
									MessageBox(
										        NULL,
										        "LOP CHUA CO SINH VIEN DANG KY !!!",
											    "THONG BAO",
										        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
									    	);
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
            		
            		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
					
				if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
				}
				
				
				
				if(btnXuat.isClicked(x,y)){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = XUAT_DS; 
					newTable.freeTable();
					delete[] arrMH;
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
				//newInput.xuLyNhapMa_LSV(ch);
				newInput.draw();
				locDS_LTC(newInput.getContent(), loptc, nFilter, tongSoTrang);
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
			}
		}
	
		delete[] arrMH;
	}
	
	void formXuatDS_DK(int &viTriChon, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300);
		
		Input input("","Nhap ma lop tc:" ,"N", 5, NUMBER,  650, 200, 650 + 300, 200 + INPUT_HEIGHT);
		input.draw();
		
		
		Button btnXuat("Xem","X",650, 300, 650+buttonWidth, 300+40, claqua, cllightblue, clblack);
		btnXuat.draw();
		
		Button btnHuy("Huy", "H", 850, 300, 850+buttonWidth, 300+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y;
		bool exitLoop = false;
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnHuy.isClicked(x,y)){
					thaoTac = HUY; 
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				if(btnXuat.isClicked(x,y) && !input.getContent().empty()){
					viTriChon = atoi(input.getContent().c_str());
					thaoTac = XUAT;
					return;
				}
				
			}
			
			if(kbhit()){
				char ch = getch();
				input.appendText(ch);
				input.draw();
			}
		}
		
	}
	
	void chon_LTC(TREE DSMH, DSLopSV DSLSV, Action thaoTac){
		if(!isNull_LTC()){
			string strN = convertIntToString(n);
			Label title(
					"IN DANH SACH LOP TIN CHI",
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
						strN.c_str()
					);
			
			int viTriChon = 0;
			xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac);
			cout<<"\no day ne";
		//while(true){
			switch(thaoTac){
				case XOA:{
					if(viTriChon < n){
						this->xoa_LTC(lopTC[viTriChon]->getMaLopTC());
						if(n == 0)
							clearRegion(tableLeft, INPUT_Y - 20, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							chon_LTC(DSMH, DSLSV, thaoTac);
					}
					break;
				}
				case XUAT:{
					xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac);
					break;
				}
				
				case DIEM:{
					if(viTriChon < n){
						clearRegion(tableLeft, INPUT_Y - 30, frameRight - 12, frameBottom - 12);
						MonHoc MH; int temp = 0;
						if(this->lopTC[viTriChon] == NULL) cout<<"\n lop tc dc chon NULL";
						else cout<<"\n ltc dc chon not null";
						MH.setMaMH(lopTC[viTriChon]->getMaMH());
						DSMH.them_MH(DSMH.getRoot(), MH, temp );
						lopTC[viTriChon]->getDSDK().chon_DK(
														DSLSV,
														lopTC[viTriChon]->getMaLopTC(),
														lopTC[viTriChon]->getNienKhoa(),
														lopTC[viTriChon]->getHocKy(),
														lopTC[viTriChon]->getNhom(),
														MH.getTenMH(),
														thaoTac
													);
					}
					break;
				}
				
				case XUAT_DS:{
					cout<<"\nXuat ds dk";
					formXuatDS_DK(viTriChon, thaoTac);
					if(thaoTac == HUY){
						thaoTac = XUAT;
							chon_LTC(DSMH, DSLSV, thaoTac);
					}else {
						int vt=-1;
						vt = this->tim_LTC(viTriChon);
						if(vt==-1){ // khong tim thay lop tin chi
							MessageBox(
						        NULL,
						        "KHONG TIM THAY LOP TIN CHI !!!",
						        "THONG BAO",
						        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		
							clearRegion(500, 150, 550 + 500, 200+300);
				    		thaoTac = XUAT_DS;
				    		chon_LTC(DSMH, DSLSV, thaoTac);
						}else{ // Co lop tin chi
							clearRegion(tableLeft, INPUT_Y - 30, frameRight - 12, frameBottom - 12);
							MonHoc MH; int temp = 0;
							if(this->lopTC[viTriChon] == NULL) cout<<"\n lop tc dc chon NULL";
							MH.setMaMH(lopTC[viTriChon]->getMaMH());
							DSMH.them_MH(DSMH.getRoot(), MH, temp );
							cout<<"\nDa lay thong tin mon hoc";
							lopTC[viTriChon]->getDSDK().chon_DK(
															DSLSV,
															lopTC[viTriChon]->getMaLopTC(),
															lopTC[viTriChon]->getNienKhoa(),
															lopTC[viTriChon]->getHocKy(),
															lopTC[viTriChon]->getNhom(),
															MH.getTenMH(),
															thaoTac
														);
						}
					}
					break;
				}
			}
		
			
		}else{
			MessageBox(
		        NULL,
		        "HIEN KHONG CO LOP TIN CHI NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}
};

/*
** ================ LopTC ================
*/

LopTC::LopTC(){
	maLopTC = 0;
	maMH = "";
	nienKhoa = 2021;
	hocKy = 0;
	nhom = 0;
	svMax = 0;
	svMin = 0;
	huyLop = false;
	soSVDK = 0;
	dsdk.setHead_DSDK(NULL);
}



void LopTC::setMaLopTC(int maLopTC){
	this->maLopTC = maLopTC;	
}

void LopTC::setMaMH(string maMH){
	this->maMH = maMH;
}

void LopTC::setNienKhoa(int khoa){
	this->nienKhoa = khoa;
}

void LopTC::setHocKy(int hocKy){
	this->hocKy = hocKy;
}

void LopTC::setNhom(int nhom){
	this->nhom = nhom;
}

void LopTC::setSVMax(int svMax){
	this->svMax = svMax;
}

void LopTC::setSVMin(int svMin){
	this->svMin = svMin;
}

void LopTC::setTrangThai(bool huyLop){
	this->huyLop = huyLop;
}
void LopTC::setDSDK(DSDK DS){
	this->dsdk = DS; 
}
	
int LopTC::getMaLopTC(){
	return this->maLopTC;	
}

string LopTC::getMaMH(){
	return this->maMH;
}

int LopTC::getNienKhoa(){
	return this->nienKhoa;
}

int LopTC::getHocKy(){
	return this->hocKy;
}

int LopTC::getNhom(){
	return this->nhom;
}

int LopTC::getSVMax(){
	return this->svMax;
}

int LopTC::getSVMin(){
	return this->svMin;
}

bool LopTC::getTrangThai(){
	return this->huyLop;
}





/*
** ================ Danh sach LopTC ================
*/

DSLopTC::DSLopTC(){
	n = 0;
}

DSLopTC::~DSLopTC(){
	for(int i=0; i<n; i++)	delete this->lopTC[i];
	cout<<"\n Delete ds ltc";
}

int DSLopTC::getN(){
	return this->n;
}

bool DSLopTC::isNull_LTC(){
	return this->n == 0;
}

bool DSLopTC::isFull_LTC(){
	return this->n >= MAX_LOPTC;
}

int DSLopTC::tim_LTC(int maLopTC){
	for(int i=0; i<this->n; i++)
		if(this->lopTC[i]->getMaLopTC() == maLopTC)
			return i;
	return -1;
}

int DSLopTC::them_LTC(LopTC *LTC){
	if(isFull_LTC()) return 0;
	
	this->lopTC[this->n++] = LTC;
	return 1;
}

int DSLopTC::xoa_LTC(int maLopTC){
	
	int viTri = tim_LTC(maLopTC);
	if(viTri>=0){
		
		delete this->lopTC[viTri];
		
		for (int i = viTri; i < this->n; i++)
			this->lopTC[i] = this->lopTC[i + 1];

		this->n--;
		
			MessageBox(
				    NULL,
				    "XOA LOP TIN CHI THANH CONG !!!",
				    "THONG BAO",
				    MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
		    	);
		return 1;
	}
	
	return -1;
	
}



void DSLopTC::writeData_LTC(LopTC *LTC, ofstream &fileOut){
	char temp = ',';
	fileOut << LTC->getMaLopTC();
	fileOut << temp;
	fileOut << LTC->getMaMH();
	fileOut << temp;
	fileOut << LTC->getNienKhoa();
	fileOut << temp;
	fileOut << LTC->getHocKy();
	fileOut << temp;
	fileOut << LTC->getNhom();
	fileOut << temp;
	fileOut << LTC->getSVMax();
	fileOut << temp;
	fileOut << LTC->getSVMin();
	fileOut << temp;
	fileOut << LTC->getTrangThai();
	fileOut << "\n";
}

void DSLopTC::writeDataDS_LTC(){
	ofstream fileOut;
	fileOut.open(PATH_SAVE_LTC, ios::out);
	if (fileOut.is_open()) {
		for (int i = 0; i < this->n; i++) 
			writeData_LTC(this->lopTC[i], fileOut);
		
	}
	fileOut.close();
}

