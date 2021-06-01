#pragma once
#include "Const.h"


class SVDangKy{
private:
	string maSV;
	float diem;
public:
	SVDangKy();
	~SVDangKy();
	
	SVDangKy(string maSV){
		this->maSV = maSV;
		diem = 0;
	}
	
	string getMaSV(){
		return this->maSV;
	}
	
	float getDiem(){
		return this->diem;
	}
	
	void setMaSV(string maSV){
		this->maSV = maSV;
	}
	
	void setDiem(float diem){
		this->diem = diem;
	}
	
	void xuat_DK(){
		cout<<"\nMa sv: "<<maSV;
		cout<<"\nDiem: "<<diem;
	}
};

class NodeDK{
private:
	SVDangKy data;
	NodeDK *next;
public:
	NodeDK();
	NodeDK(SVDangKy data){
		this->data = data;
		this->next = NULL;
	}
	~NodeDK();
	
	void setData(SVDangKy data){
		this->data = data;
	}
	
	void setNext_DK(NodeDK *DK){
		this->next = DK;
	}
	
	SVDangKy &getData_DK(){
		return this->data;
	}
	
	NodeDK *&getNext_DK(){
		return this->next;
	}
	
	NodeDK *getNode_DK(){
		return this;
	}
	
	void writeData_DK(SVDangKy DK, int maLopTC, ofstream &fileOut){
		char temp = ',';
		fileOut << maLopTC;
		fileOut << temp;
		fileOut << DK.getMaSV();
		fileOut << temp;
		fileOut << DK.getDiem();	
		fileOut << '\n';
	}
	
};

class DSDK{
private:
	NodeDK *head;
public:
	DSDK();
	~DSDK();
	
	void setHead_DSDK(NodeDK *head);
	NodeDK*& getHead_DSDK();
	
	
	
	void xuatDS_DK(){
		if(this->head == NULL) {
			cout<<"\nDS rong";
			return;
		}
		for(NodeDK *p = this->head; p != NULL ; p=(p->getNext_DK())){
				cout<<"\n"<<p->getData_DK().getMaSV()<<" "<<p->getData_DK().getDiem();

		}
	}
	
	
	void themDau_DK(NodeDK *DK){
		DK->setNext_DK(this->head);
		this->head = DK->getNode_DK();
	}
	
	int timViTriThem_DK(NodeDK *DK){
		int viTri = 1;

		NodeDK* p = this->head;
		
		//if(p==NULL) return viTri;
		
		while (p != NULL && p->getData_DK().getMaSV() <= DK->getData_DK().getMaSV())	{
			if (p->getData_DK().getMaSV() == DK->getData_DK().getMaSV()) return -1;
			viTri++;
			if(p->getNext_DK()==NULL) break;
			p = p->getNext_DK();
		}
		//cout<<"\nVi tri them"<<viTri<<" "; system("pause");
		return viTri;
	}
	
	void them_DK(NodeDK *DK){
		
		int viTriThem = this->timViTriThem_DK(DK);
	
		
		if(this->head == NULL || viTriThem == 1){
			themDau_DK(DK); return;
		}
		
		int viTri = 1;
		NodeDK *p;
		for(p = this->head; p->getNext_DK()!= NULL && viTri < viTriThem-1; viTri++,p=p->getNext_DK());
		
		DK->setNext_DK(p->getNext_DK());
		p->setNext_DK(DK);
		
		cout<<"\nthem thanh cong";
	}
	
	bool checkSV_DK(string maSV){
		
		for(NodeDK *p = this->head; p != NULL; p=p->getNext_DK()){
			if(p->getData_DK().getMaSV() == maSV) return true;
			
		}
		
		return false;
	}
	
	bool isNull_DK(){
		return this->head == NULL;
	}
	
	int demSoLuongSV(){
		int n = 0;
		for(NodeDK *p = this->head; p != NULL ; n++,p=(p->getNext_DK()));
		
		return n;
	}
	
	void thongKeDS_DK(DSSV &DSSVDK, DSLopSV DSLSV){
		int n=0; int tmp=0;
		if(!isNull_DK()){
			for(NodeDK *p = this->head; p!=NULL; p=p->getNext_DK()){
				NodeSV*temp = DSLSV.layInfo_SV(p->getData_DK().getMaSV());
				tmp++;
				if(temp!=NULL){
					NodeSV *sv = new NodeSV(temp->getData_SV());
					DSSVDK.them_SV(sv); n++;
				}else {
					cout<<"\nKhong tim thay: "<<p->getData_DK().getMaSV();
				}
			}
		}else{
			return;
		}
		cout<<"\n so ld dk: "<<n<<" "<<tmp;
	}
	
	void xuatDS1Trang_DK(NodeSV *&head, int batDau, int ketThuc, Table newTable){
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
					string(	(newTable.getCols(1)->getWidth() - 5 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
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
				outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
				x += newTable.getCols(0)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() - 5 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
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
						x + newTable.getCols(4)->getWidth()/2  - textwidth(p->getData_SV().getSDT().c_str())/2, 
						y, 
						p->getData_SV().getSDT().c_str()
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
						x + newTable.getCols(5)->getWidth()/2  - textwidth(p->getData_SV().getMaLop().c_str())/2, 
						y, 
						p->getData_SV().getMaLop().c_str()
					);
					
				x += newTable.getCols(5)->getWidth();
			
			
			x = tableLeft;
			if(p!=NULL ) p = p->getNext_SV();
		}
	}
	
	void locDS_DK(string content, DSSV dssv,  DSSV &dssvfilter, int &nFilter, int &tongSoTrang){
		dssvfilter.freeDS_SV(dssvfilter.getHead_DSSV());
		dssvfilter.setHead_DSSV(NULL);
		
		if(!content.empty()){
			for(NodeSV *p = dssv.getHead_DSSV(); p!=NULL; p=p->getNext_SV()){
				if(p->getData_SV().getMaSV().find(content) != string::npos){
					
					NodeSV*SV = new NodeSV(p->getData_SV());
					dssvfilter.them_SV(SV);
					
				}
			}
			
		}else{
			for(NodeSV *p = dssv.getHead_DSSV(); p!=NULL; p=p->getNext_SV()){
				NodeSV *sv = new NodeSV(p->getData_SV());
				dssvfilter.them_SV(sv);
			}
		}
		
		
		nFilter = dssvfilter.isNULL_SV() ? 0 : dssvfilter.demSoLuongSV();
	
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
		
	}
	
	void xuatDSTheoTrang_DK(DSLopSV DSLSV, Action thaoTac){
		
		DSSV DSSVDK; 
		this->thongKeDS_DK(DSSVDK, DSLSV);
		
		DSSV DSSVDKFilter;
		for(NodeSV *p = DSSVDK.getHead_DSSV(); p!=NULL; p=p->getNext_SV()){
			NodeSV *sv = new NodeSV(p->getData_SV());
			DSSVDKFilter.them_SV(sv);
		}
		
		//DSSVDKFilter.xuatDS_SV();
		
		
		if(!DSSVDK.isNULL_SV()){
			int tongSoDong = this->demSoLuongSV();
			int nFilter = tongSoDong;
			
			int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
			
			int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
			int trangHienTai = 1;
			
			int batDau = 0;
			int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
			
			Table newTable; 
			/*if(thaoTac == DIEM)
				newTable= table_Diem();
			else if(thaoTac == XUAT_DS)*/
				newTable = table_DK();
				
			newTable.drawTable(MAX_DONG_1_TRANG);
			
			xuatDS1Trang_DK(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
			inTrang(trangHienTai, tongSoTrang);
			
			Input newInput("","Nhap ma sinh vien:" ,"", MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
			newInput.draw();
			
			Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
			btnPrev.draw();
			
			Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
			btnNext.draw();
			
			int x,y;
			
			while(true){
				// Click event change page output
				if (ismouseclick(WM_LBUTTONDOWN)){
	            	getmouseclick(WM_LBUTTONDOWN, x, y);
					
					if(newInput.isClicked(x,y)){
	            		newInput.requestFocus();
	            		newInput.draw();
					}
					
					if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
	            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
	            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
	            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
	            		
	            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
	            		
	            		xuatDS1Trang_DK(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);
					}
					
					if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
						trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
						batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
						ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
						
						ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
						
						xuatDS1Trang_DK(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);
					}
				}
				
				// Filter by input
				if(kbhit()){
					char ch = getch();
					newInput.appendText(ch);
					newInput.draw();
					(locDS_DK(newInput.getContent(), DSSVDK, DSSVDKFilter, nFilter, tongSoTrang)) ;
					batDau = 0; trangHienTai = 1;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
					cout<<"\nKet thucccccccccccccccccccc: "<<nFilter<<" "<<ketThuc;
					
					xuatDS1Trang_DK(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
			}
			
		}else{
			MessageBox(
		        NULL,
		        "HIEN KHONG CO LOP SINH VIEN NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}
	
	void chon_DK(DSLopSV DSLSV, int maLopTC, int khoa, int HK, int nhom, bool trangThai, string tenMH, Action thaoTac){
		if(!isNull_DK()){
			string strMaLopTC = convertIntToString(maLopTC);
			string strKhoa = convertIntToString(khoa);
			string strHK = convertIntToString(HK);
			string strNhom = convertIntToString(nhom);
			string strTT = trangThai ? "Mo lop" : "Huy lop";
			string subTitle;
			int soLuong = this->demSoLuongSV();
			string strSoLuong = convertIntToString(soLuong);
			
			if(thaoTac == DIEM)
				subTitle = "BANG DIEM 1 LOP TIN CHI";
			else if(thaoTac == XUAT_DS)
				subTitle = "DANH SACH SINH VIEN 1 LOP TIN CHI";
			
			Label title(
					subTitle,
					LABEL_X,
					LABEL_Y,
					LABEL_X + LABEL_WIDTH,
					LABEL_Y + LABEL_HEIGHT,
					clgreen,
					cllightgreen,
					cllightwhite
				);
				
			title.printLabel(
						"Ten mon hoc",
						tenMH,
						"Nien khoa",
						strKhoa,
						"Hoc ky",
						strHK,
						"Nhom",
						strNhom,
						"Ma lop",
						strMaLopTC,
						"SL",
						strSoLuong,
						"TT",
						strTT
					);
			
			xuatDSTheoTrang_DK(DSLSV, thaoTac);
			
		}else{
			MessageBox(
		        NULL,
		        "LOP CHUA CO SINH VIEN DANG KY !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}
	
};

/*
** ================ SV dang ky ================
*/

SVDangKy::SVDangKy(){
	maSV = "";
	diem = 0;
}

SVDangKy::~SVDangKy(){
	
}

/*
** ================ Node SV dang ky ================
*/

NodeDK::NodeDK(){
	next = NULL;
}

NodeDK::~NodeDK(){
	//delete next;
	cout<<"\n delete next dk";
}

/*
** ================ DS SV dang ky ================
*/

DSDK::DSDK(){
	head = NULL;
}

DSDK::~DSDK(){
	//delete head;
	cout<<"\n delete head dk";
}

void DSDK::setHead_DSDK(NodeDK *head){
	this->head = head;
}

NodeDK*& DSDK::getHead_DSDK(){
	return this->head;
}
