#pragma once
#include "Const.h"


class SVDangKy{
private:
	string maSV;
	float diem;
public:
	SVDangKy();
	
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
	
	void freeDS_SV(NodeDK *&pHead){
		
		NodeDK* SV = NULL;
		while (pHead != NULL)
		{
			SV = pHead;
			pHead = pHead->getNext_DK();
			delete SV;
		}
	}
	
	NodeDK * timSV_DK(string maSV){
		if(head == NULL) return NULL;
		NodeDK*p=head;
		for(; p->getNext_DK() != NULL && p->getData_DK().getMaSV() != maSV ; p=p->getNext_DK());
		
		if(p->getData_DK().getMaSV() == maSV) return p;
		
		return NULL;
	}
	
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
		return  this->head == NULL;
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
	
	void thongKeDiemDS_DK(DSSV &DSSVDK, DSDK &DSDiem, DSLopSV DSLSV){
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
	}
	
	float timDiem_DK(string maSV){
		for(NodeDK *k = this->head; k!=NULL; k=k->getNext_DK()){
			if(k->getData_DK().getMaSV() == maSV)
				return k->getData_DK().getDiem();
		}
		return -1;
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
	
	void xuatDSTheoTrang_DK(DSLopSV DSLSV, Action &thaoTac){
		
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
			
			Table newTable; 	newTable = table_DK();
			newTable.drawTable(MAX_DONG_1_TRANG);
			
			xuatDS1Trang_DK(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
			inTrang(trangHienTai, tongSoTrang);
			
			Input newInput("","Nhap ma sinh vien:" ,"", MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
			newInput.draw();
			
			Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
			btnPrev.draw();
			
			Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
			btnNext.draw();
			
			// dau X tren cung goc phai
			Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
			btnBack.draw();
			
			int x,y;
			
			bool exitLoop = false;
			
			while(!exitLoop){
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
					}else if(btnBack.isClicked(x,y)){
						thaoTac = THOAT;
						exitLoop = true;
						continue;
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
			
			DSSVDK.freeDS_SV(DSSVDK.getHead_DSSV());
			DSSVDKFilter.freeDS_SV(DSSVDKFilter.getHead_DSSV());
			newTable.freeTable();
			
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
	
	void xuatDS1Trang_Diem(NodeSV *&head, int batDau, int ketThuc, Table newTable){
		int soDong = ketThuc % MAX_DONG_1_TRANG; // Xem can xuat bao nhieu dong
		if(soDong == 0) soDong = MAX_DONG_1_TRANG; // neu so du == 0 thi xuat ra MAX_DONG_1_TRANG dong
		
		int x = tableLeft ;
		int y = tableTop + rowTableHeight/2- textheight(string("0").c_str())/2  ;
		int yBtn = tableTop;
		
		string strSTT, strDiem="";
		float diem;
		
		if(ketThuc==0 && batDau == 0) soDong = MAX_DONG_1_TRANG;
		else
			soDong = ketThuc % MAX_DONG_1_TRANG == 0 ? ketThuc : ketThuc + MAX_DONG_1_TRANG - ketThuc % MAX_DONG_1_TRANG;
		
		setbkcolor(cllightwhite); setcolor(clblack);
		//cout<<"\nBat dau "<<batDau<<" "<<ketThuc;
		
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
						x + newTable.getCols(4)->getWidth()/2  - textwidth(p->getData_SV().getMaLop().c_str())/2, 
						y, 
						p->getData_SV().getMaLop().c_str()
					);
					
				x += newTable.getCols(4)->getWidth();
				
			diem = timDiem_DK(p->getData_SV().getMaSV());
			
			
			
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(5)->getWidth() - 4 - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(5)->getWidth()/2 - textwidth(convertFloatToString(diem).c_str())/2, 
						y, 
						convertFloatToString(diem).c_str()
					);
			
			
			x = tableLeft;
			if(p!=NULL ) p = p->getNext_SV();
		}
	}
	
	void xuatDSTheoTrang_Diem123(DSLopSV DSLSV, Action &thaoTac ){
		
		DSSV DSSVDK; 
		this->thongKeDS_DK(DSSVDK, DSLSV);
		
		DSSV DSSVDKFilter;
		for(NodeSV *p = DSSVDK.getHead_DSSV(); p!=NULL; p=p->getNext_SV()){
			NodeSV *sv = new NodeSV(p->getData_SV());
			DSSVDKFilter.them_SV(sv);
		}
		
		/*NodeSV *p = DSSVDK.getHead_DSSV();
		NodeDK *k = this->head;
		for( ;p!=NULL && k!=NULL; p=p->getNext_SV(), k=k->getNext_DK()){
			cout<<"\n"<<p->getData_SV().getMaSV()<<" "<<k->getData_DK().getMaSV();
		}*/
		
		if(!DSSVDK.isNULL_SV()){
			int tongSoDong = this->demSoLuongSV();
			int nFilter = tongSoDong;
			
			int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
			
			int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
			int trangHienTai = 1;
			
			int batDau = 0;
			int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
			
			Table newTable; newTable = table_Diem();
			newTable.drawTable(MAX_DONG_1_TRANG);
			
			xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
			inTrang(trangHienTai, tongSoTrang);
			
			Input newInput("","Nhap ma sinh vien:" ,"", MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y ,INPUT_X + INPUT_WIDTH , INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
			newInput.draw();
			
			Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
			btnPrev.draw();
			
			Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
			btnNext.draw();
			
			// dau X tren cung goc phai
			Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
			btnBack.draw();
			
			Button btnSuaDiem("Sua diem","btnSuaDiem", tableLeft + 40, tableTop-60, (tableLeft + 40) + buttonWidth, tableTop-10 );
			btnSuaDiem.draw();
			
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
	            		
	            		xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);
					}
					
					if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
						trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
						batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
						ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
						
						ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
						
						xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);
					}else if(btnSuaDiem.isClicked(x,y)){
						
					}
					
				}
				
				// Filter
				if(kbhit()){
					char ch = getch();
					newInput.appendText(ch);
					newInput.draw();
					(locDS_DK(newInput.getContent(), DSSVDK, DSSVDKFilter, nFilter, tongSoTrang)) ;
					batDau = 0; trangHienTai = 1;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
					cout<<"\nKet thucccccccccccccccccccc: "<<nFilter<<" "<<ketThuc;
					
					xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
					inTrang(trangHienTai, tongSoTrang);
					
					// nhap diem
				}
			}
			
			DSSVDK.freeDS_SV(DSSVDK.getHead_DSSV());
			DSSVDKFilter.freeDS_SV(DSSVDKFilter.getHead_DSSV());
			newTable.freeTable();
			
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
	
	void xuatDSTheoTrang_Diem(DSLopSV DSLSV, Action& thaoTac) {

		DSSV DSSVDK;
		this->thongKeDS_DK(DSSVDK, DSLSV);

		DSSV DSSVDKFilter;
		for (NodeSV* p = DSSVDK.getHead_DSSV(); p != NULL; p = p->getNext_SV()) {
			NodeSV* sv = new NodeSV(p->getData_SV());
			DSSVDKFilter.them_SV(sv);
		}

		/*NodeSV *p = DSSVDK.getHead_DSSV();
		NodeDK *k = this->head;
		for( ??!=NULL && k!=NULL; p=p->getNext_SV(), k=k->getNext_DK()){
			cout<<"\n"<<p->getData_SV().getMaSV()<<" "<<k->getData_DK().getMaSV();
		}*/

		if (!DSSVDK.isNULL_SV()) {
			int tongSoDong = this->demSoLuongSV();
			int nFilter = tongSoDong;

			int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;

			int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
			int trangHienTai = 1;

			int batDau = 0;
			int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;

			Table newTable;
			newTable = table_Diem();
			newTable.drawTable(MAX_DONG_1_TRANG);

			xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
			inTrang(trangHienTai, tongSoTrang);

			Input newInput("", "Nhap ma sinh vien:", "", MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y, INPUT_X + INPUT_WIDTH, INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
			newInput.draw();

			Button btnSuaDiem("Sua diem", "btnSuaDiem", tableLeft + 40, tableTop - 60, (tableLeft + 40) + buttonWidth, tableTop - 10);
			btnSuaDiem.draw();

			Button btnPrev("<", "btnPrev", buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
			btnPrev.draw();

			Button btnNext(">", "btnNext", buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
			btnNext.draw();

			Button btnBack("X", "quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
			btnBack.draw();

			int x, y;
			
			bool exitLoop=false;

			while (!exitLoop) {
				// Click event change page output
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if (newInput.isClicked(x, y)) {
						newInput.requestFocus();
						newInput.draw();

						//newInput.initFocusedId();
					}

					if (btnPrev.isClicked(x, y) && (trangHienTai > 1)) {

						trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
						batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
						ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;

						ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;

						xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);
					}

					if (btnNext.isClicked(x, y) && (trangHienTai < tongSoTrang)) {

						trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
						batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
						ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;

						ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;

						xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);
					}

					if (btnSuaDiem.isClicked(x, y))
					{
						//INPUT_X, INPUT_Y, INPUT_X + INPUT_WIDTH, INPUT_Y + INPUT_HEIGHT
						clearRegion(INPUT_X, INPUT_Y, INPUT_X + INPUT_WIDTH+2, INPUT_Y + INPUT_HEIGHT+2);
						clearRegion(INPUT_X - 150 , INPUT_Y + 10, INPUT_X , INPUT_Y + INPUT_HEIGHT - 5 );
						nhapDiemTheoTrang(DSLSV, thaoTac);
						
						exitLoop=true;
						
						continue;
					}
					
					if (btnBack.isClicked(x, y))
					{						
						exitLoop=true;
						continue;
					}
				}

				// Filter
				if (kbhit()) {
					char ch = getch();
					newInput.appendText(ch);
					newInput.draw();
					(locDS_DK(newInput.getContent(), DSSVDK, DSSVDKFilter, nFilter, tongSoTrang));
					batDau = 0; trangHienTai = 1;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
					cout << "\nKet thucccccccccccccccccccc: " << nFilter << " " << ketThuc;

					xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
					inTrang(trangHienTai, tongSoTrang);
				}
			}

			DSSVDK.freeDS_SV(DSSVDK.getHead_DSSV());
			DSSVDKFilter.freeDS_SV(DSSVDKFilter.getHead_DSSV());
			newTable.freeTable();
			thaoTac = THOAT;
			
		}
		else {
			MessageBox(
				NULL,
				"HIEN KHONG CO LOP SINH VIEN NAO !!!",
				"THONG BAO",
				MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
			);
			return;
		}

	}
	
	void formNhapDiem(SVDangKy &sv, Action &thaoTac){
		// Ve form
		drawFrame(500, 150, 540 + 500, 200+300);
		
		int nInput = 2;
		Input *input[nInput] = {NULL};
		
		int left = 650;
		int top = 220;
		
		input[0] = new Input("","Ma sinh vien ","0", MAX_MASV, STUDENT_ID, left, top, left + 300, top + INPUT_HEIGHT );
		input[1] = new Input("","Diem ","1", 3, MARK, left, top+INPUT_HEIGHT+20, left+300, top + INPUT_HEIGHT*2 +20);
		
		Button btnLuu("Tiep tuc","L",left, top+130, left+buttonWidth, top+INPUT_HEIGHT+130, claqua, cllightblue, clblack);
		btnLuu.draw();
		
		Button btnThoat("Thoat", "T", left + 200, top+130, 850+buttonWidth, top+INPUT_HEIGHT+130, cllightred, clred, cllightwhite);
		btnThoat.draw();
		
		int x,y; char ch;
		string notification;
		
	
		int indexInput=0;
		
		input[indexInput]->draw();
		
		input[indexInput]->requestFocus();
		input[indexInput]->draw();
		
		bool exitLoop = false;
		
		NodeDK *svdk = NULL;
	/*NHAP_MA_SV:	
		indexInput = 0;
		while(!exitLoop){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
					
				if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT; 
					exitLoop = true;
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}else if(btnLuu.isClicked(x,y) && !input[indexInput]->getContent().empty()){
					svdk = timSV_DK(input[indexInput]->getContent());
					
					if(svdk != NULL){
						
						btnLuu.setText("Luu");
						btnLuu.draw();
						
						btnThoat.setText("Quay lai");
						btnThoat.draw();
						
						exitLoop = true;
						continue;
					}else {
						MessageBox(
						        NULL,
						        "KHONG TIM THAY SINH VIEN !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
					}
					
				}else if (btnLuu.isClicked(x,y) && input[indexInput]->getContent().empty()){
					MessageBox(
						        NULL,
						        "VUI LONG KHONG BO TRONG DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				}
			}
			
			if(kbhit()){
				ch = getch();
				input[indexInput]->appendText(ch);
				input[indexInput]->draw();
			}
				
		}
		
		
		input[1]->requestFocus();
		input[0]->setOffEnable();
		//input[0]->setBorderColor(clblack);
		input[0]->draw();
		input[1]->setContent(convertFloatToString(svdk->getData_DK().getDiem()));
		input[1]->draw();
		
		indexInput = 1;
		
		exitLoop = false;*/
		
		while(!exitLoop){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnThoat.isClicked(x,y) && indexInput == 1){
					clearRegion(left-textwidth(btnThoat.getText().c_str()), top+INPUT_HEIGHT+20, left+302, top + INPUT_HEIGHT*2 +22);
					btnThoat.setText("Thoat");
					btnThoat.draw();
					indexInput = 0;
					input[indexInput]->requestFocus();
					input[indexInput]->draw();
				}else if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT; 
					exitLoop = true;
				}
				else if(btnLuu.isClicked(x,y) && !input[indexInput]->getContent().empty() && indexInput == 0){
					svdk = timSV_DK(input[indexInput]->getContent());
					
					if(svdk != NULL){
						
						btnLuu.setText("Luu");
						btnLuu.draw();
						
						btnThoat.setText("Quay lai");
						btnThoat.draw();
						
						input[1]->requestFocus();
						input[0]->setOffEnable();
						input[0]->draw();
						input[1]->setContent(convertFloatToString(svdk->getData_DK().getDiem()));
						input[1]->draw();
						
						indexInput = 1;
						continue;
					}else {
						MessageBox(
						        NULL,
						        "KHONG TIM THAY SINH VIEN !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
					}
					
					
				}else if(btnLuu.isClicked(x,y) && !input[indexInput]->getContent().empty()){
					sv.setDiem(atof(input[indexInput]->getContent().c_str()));
					sv.setMaSV(input[0]->getContent());
					svdk->setData(sv);
					exitLoop = true;
					continue;
				}
				else if (btnLuu.isClicked(x,y) && input[indexInput]->getContent().empty()){
					MessageBox(
						        NULL,
						        "VUI LONG KHONG BO TRONG DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				}
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == ENTER){
					if(!input[indexInput]->getContent().empty() && indexInput == 0){
						svdk = timSV_DK(input[indexInput]->getContent());
					
						if(svdk != NULL){
							
							btnLuu.setText("Luu");
							btnLuu.draw();
							
							btnThoat.setText("Quay lai");
							btnThoat.draw();
							
							input[1]->requestFocus();
							input[0]->setOffEnable();
							input[0]->draw();
							input[1]->setContent(convertFloatToString(svdk->getData_DK().getDiem()));
							input[1]->draw();
							
							indexInput = 1; continue;
						}else {
							MessageBox(
							        NULL,
							        "KHONG TIM THAY SINH VIEN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					    	continue;
						}
					}else if(!input[indexInput]->getContent().empty() && indexInput == 1){
						sv.setDiem(atof(input[indexInput]->getContent().c_str()));
						sv.setMaSV(input[0]->getContent());
						svdk->setData(sv);
						exitLoop = true;
						continue;
					}else{
						MessageBox(
						        NULL,
						        "VUI LONG KHONG BO TRONG DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
					}
				}
				
				if(input[indexInput]->getEnable()){
					input[indexInput]->appendText(ch);
					input[indexInput]->draw();
				}
			}
		
		
		}
		
		for(int i=0; i<nInput; i++) delete input[i];
		clearRegion(500, 150, 550 + 500, 200+300);
	}
	
	void nhapDiemTheoTrang(DSLopSV DSLSV, Action& thaoTac) {

		DSSV DSSVDK;
		this->thongKeDS_DK(DSSVDK, DSLSV);
		
		/*NodeSV *p = DSSVDK.getHead_DSSV();
		NodeDK *k = this->head;
		for( ??!=NULL && k!=NULL; p=p->getNext_SV(), k=k->getNext_DK()){
			cout<<"\n"<<p->getData_SV().getMaSV()<<" "<<k->getData_DK().getMaSV();
		}*/

		if (!DSSVDK.isNULL_SV()) {
			int tongSoDong = this->demSoLuongSV();
			int nFilter = tongSoDong;

			int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;

			int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
			int trangHienTai = 1;

			int batDau = 0;
			int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;

			Table newTable;
			newTable = table_Diem();
			newTable.drawTable(MAX_DONG_1_TRANG);

			xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);
			inTrang(trangHienTai, tongSoTrang);

//			Input newInput("", "Nhap ma sinh vien:", "", MAX_MASV, STUDENT_ID, INPUT_X, INPUT_Y, INPUT_X + INPUT_WIDTH, INPUT_Y + INPUT_HEIGHT, cllightwhite, clblack, clblack);
//			newInput.draw();

			Button btnTimSV("Tim SV", "btnSV", tableLeft + 40, tableTop - 60, (tableLeft + 40) + buttonWidth, tableTop - 10);			
			btnTimSV.draw();

			Button btnPrev("<", "btnPrev", buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
			btnPrev.draw();

			Button btnNext(">", "btnNext", buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
			btnNext.draw();

			Button btnBack("X", "quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
			btnBack.draw();

			Button btnLuu("Luu", "btnLuu", (tableLeft + 40 + buttonWidth) + 20, tableTop - 60, (tableLeft + 40 + buttonWidth + 20) + buttonWidth, tableTop - 10);
			btnLuu.draw();

			
			int nInputDiem = this->demSoLuongSV();
			Input* inputDiem[nInputDiem];
			int viTriThieu = -1;
			int top = tableTop + rowTableHeight;
			int left = 1172;//1172
			int right = left + 155;
			int bottom = top + rowTableHeight;
			int nDong = 0;
			SVDangKy *arrDiem=new SVDangKy[nInputDiem];

			// Ve input, cap phat o nho
			for (int i = 0; i < nInputDiem; i++){

				inputDiem[i] = new Input("", "", "", MAXLENGTH_DIEM, TEXT, left, top, right, bottom, cllightwhite, clred, clblack);
				inputDiem[i]->draw();

				top = bottom;
				bottom += rowTableHeight;

				if ((i + 1) % MAX_DONG_1_TRANG == 0){
					top = tableTop + rowTableHeight;
					bottom = top + rowTableHeight;
				}
			}
			
			int i = 0;
			float diem;
			cout << "\nINPUTDIEMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
			for (NodeSV* p = DSSVDK.getHead_DSSV(); p != NULL && i < nInputDiem; p = p->getNext_SV(), i++) {
				diem=timDiem_DK(p->getData_SV().getMaSV());
				
				inputDiem[i]->setContent(convertFloatToString(diem));
				inputDiem[i]->setId(p->getData_SV().getMaSV());							
			}

			for(int i=0 ; i<nInputDiem;i++){
				cout << inputDiem[i]->getContent() << "    " << inputDiem[i]->getId() << "\n";
				cout <<	arrDiem[i].getDiem() << "      " << arrDiem[i].getMaSV() <<"\n";
				cout << "\n==============================\n";
			}
			
			

			for (int i = batDau; i < ketThuc; i++){
				inputDiem[i]->draw();
			}

			xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);

			int indexIsFocused = -1;
			int oldIndexIsFocused = -1;		
			int x, y;
			bool exitLoop=false;
			
			while (!exitLoop) {
				// Click event change page output
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

//					if (newInput.isClicked(x, y)) {
//						newInput.requestFocus();
//						newInput.draw();
//
//						if (indexIsFocused != -1) {
//
//							inputDiem[indexIsFocused]->draw();
//							indexIsFocused = -1;
//						}				
//					}

		
					for (int i = batDau; i < ketThuc; i++)
					{
						if (inputDiem[i]->isClicked(x, y))
						{

							inputDiem[i]->requestFocus();
							//newInput.draw();

							oldIndexIsFocused = indexIsFocused;

							if (oldIndexIsFocused != -1)
							{
								inputDiem[oldIndexIsFocused]->draw();
							}

							inputDiem[i]->draw();
							indexIsFocused = i;
							break;
						}
					}
					
					if(btnTimSV.isClicked(x,y)){
						SVDangKy svdk;
						formNhapDiem(svdk, thaoTac);
						newTable.drawTable(MAX_DONG_1_TRANG);
						xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);
						
						for(int i = 0; i < nInputDiem; i++){
							if(inputDiem[i]->getId() == svdk.getMaSV()){
								inputDiem[i]->setContent(convertFloatToString(svdk.getDiem()));
								break;
							}
						}
						
						for (int i = batDau; i < ketThuc; i++){
							inputDiem[i]->draw();
						}
					}
					
					if (btnPrev.isClicked(x, y) && (trangHienTai > 1)) {

						if (indexIsFocused != -1)
						{
							inputDiem[indexIsFocused]->initFocusedId();
							inputDiem[indexIsFocused]->draw();
							indexIsFocused = -1;
						}
						trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
						batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
						ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;

						ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;

						xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);

					
							for (int i = batDau; i < ketThuc; i++)
							{
								inputDiem[i]->draw();
							}
						
					}

					if (btnNext.isClicked(x, y) && (trangHienTai < tongSoTrang)) {
						if (indexIsFocused != -1) {
							inputDiem[indexIsFocused]->initFocusedId();
							inputDiem[indexIsFocused]->draw();
							indexIsFocused = -1;
						}

						trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
						batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
						ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;

						ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;

						xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);
						inTrang(trangHienTai, tongSoTrang);

						
							for (int i = batDau; i < ketThuc; i++)
							{
								inputDiem[i]->draw();
							}
					
					}

					if (btnLuu.isClicked(x, y)) {					
						// kiem tra arr input co bi trong diem
						viTriThieu = -1;
						for (int i = 0; i < nInputDiem; i++) {
							if (inputDiem[i]->getContent().empty()) {
								
								viTriThieu = i; break;

							}
						}

						if (viTriThieu != -1) {

							MessageBox(
								NULL,
								"VUI LONG NHAP DU THONG TIN TRUOC KHI LUU !!!",
								"THONG BAO",
								MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							);

							int viTriTrang = 1;
							while (viTriTrang < tongSoTrang && viTriThieu >= (viTriTrang * MAX_DONG_1_TRANG)) viTriTrang++;

							if (trangHienTai != viTriTrang) trangHienTai = viTriTrang;

							batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
							ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;

							ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;

							inputDiem[viTriThieu]->requestFocus();
							indexIsFocused = viTriThieu;
							//xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);

							for (NodeDK* p = this->head; p != NULL; p = p->getNext_DK()) {
								for (int i = 0; i < ketThuc; i++) {
									if (p->getData_DK().getMaSV() == inputDiem[i]->getId()) {
										inputDiem[i]->draw();
									}
								}
							}

							inputDiem[viTriThieu]->draw();
							inTrang(trangHienTai, tongSoTrang);
							continue;

						}

						// luu diem tu arr input vao danh sach dang ky
						for (NodeDK* p = this->head; p != NULL; p = p->getNext_DK()) {
							for (int i = 0; i < ketThuc; i++) {
								if (p->getData_DK().getMaSV() == inputDiem[i]->getId())
								{								
									p->getData_DK().setDiem(atof(inputDiem[i]->getContent().c_str()));

									cout << inputDiem[i]->getId() << ": ";
									cout << p->getData_DK().getDiem() << endl;

								}
							}
						}

					
						for (int i = 0; i < nInputDiem; i++)	delete inputDiem[i];

						MessageBox(
							NULL,
							"LUU DS DIEM THANH CONG !!!",
							"THONG BAO",
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						
						exitLoop=true;
						continue;				
					} // btn luu

		//
					if (btnBack.isClicked(x, y)) {

						int isConfirmed = MessageBox(NULL,
							"BAN CO MUON LUU DS DIEM",
							"THONG BAO",
							MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY
						);

						switch (isConfirmed) {
						case IDCANCEL: {
							thaoTac = THOAT_CT;
							newTable.freeTable();
							
							//khoi tao lai focus truoc khi thoat
							
							//===============
							for (int i = 0; i < nInputDiem; i++)	delete inputDiem[i];
							return;

							break;
						}

						case IDOK: default: {

							// kiem tra nhap du thong tin
							viTriThieu = -1;
							for (int i = 0; i < nInputDiem; i++) {
								if (inputDiem[i]->getContent().empty()) {
									viTriThieu = i; break;
								}
							}

							if (viTriThieu != -1) {

								MessageBox(NULL,
									"VUI LONG NHAP DU THONG TIN TRUOC KHI LUU !!!",
									"THONG BAO",
									MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								);

								int viTriTrang = 1;
								while (viTriTrang < tongSoTrang && viTriThieu >= (viTriTrang * MAX_DONG_1_TRANG)) viTriTrang++;

								if (trangHienTai != viTriTrang) trangHienTai = viTriTrang;

								batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
								ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;

								ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;								
									
								inputDiem[viTriThieu]->requestFocus();
								indexIsFocused = viTriThieu;
								xuatDS1Trang_Diem(DSSVDK.getHead_DSSV(), batDau, ketThuc, newTable);
							

								for (NodeDK* p = this->head; p != NULL; p = p->getNext_DK()) {
									for (int i = 0; i < ketThuc; i++) {
										if (p->getData_DK().getMaSV() == inputDiem[i]->getId()) {
											inputDiem[i]->draw();
										}
									}
								}

								inputDiem[viTriThieu]->draw();
								inTrang(trangHienTai, tongSoTrang);
								//isSuaDiem = true;
								continue;

							}
							else {
								for (NodeDK* p = this->head; p != NULL; p = p->getNext_DK()) {
									for (int i = 0; i < ketThuc; i++) {
										if (p->getData_DK().getMaSV() == inputDiem[i]->getId())
										{									
											p->getData_DK().setDiem(atof(inputDiem[i]->getContent().c_str()));
										}
									}
								}
								
								for (int i = 0; i < nInputDiem; i++)	delete inputDiem[i];
								MessageBox(
									NULL,
									"LUU DS DIEM THANH CONG !!!",
									"THONG BAO",
									MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								);
								
								exitLoop=true;
								continue;
							}

							break;

						}
						}
					} // btnBack is suaDiem
					
				} // mouse click

				if (kbhit()) {
					if (indexIsFocused != -1) {
						char ch = getch();

						inputDiem[indexIsFocused]->appendText(ch);
						inputDiem[indexIsFocused]->draw();

						continue;
					}
					
//					//Filter
//					char ch = getch();
//					newInput.appendText(ch);
//					newInput.draw();
//					(locDS_DK(newInput.getContent(), DSSVDK, DSSVDKFilter, nFilter, tongSoTrang));
//					batDau = 0; trangHienTai = 1;
//					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
//					cout << "\nKet thucccccccccccccccccccc: " << nFilter << " " << ketThuc;
//					
//					xuatDS1Trang_Diem(DSSVDKFilter.getHead_DSSV(), batDau, ketThuc, newTable);
//					inTrang(trangHienTai, tongSoTrang);
											
//					for (int i = batDau; i < ketThuc; i++)
//					{
//						inputDiem[i]->draw();
//					}

				}
			}
			
			// FREE
			//DSSVDK.freeDS_SV(DSSVDK.getHead_DSSV());
			DSSVDK.freeDS_SV(DSSVDK.getHead_DSSV());
			newTable.freeTable();

		}
		else {
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
		string strMaLopTC = convertIntToString(maLopTC);
		string strKhoa = convertIntToString(khoa);
		string strHK = convertIntToString(HK);
		string strNhom = convertIntToString(nhom);
		string strTT = !trangThai ? "Mo lop" : "Huy lop";
		string subTitle;
		int soLuong;
		string strSoLuong;
		while(!isNull_DK()){
			
			
			soLuong = this->demSoLuongSV();
			strSoLuong = convertIntToString(soLuong);
			
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
			
			switch(thaoTac){
				case XUAT_DS:{
					xuatDSTheoTrang_DK(DSLSV, thaoTac);
					if(thaoTac == THOAT) return;
					break;
				}
				
				case DIEM:{
					xuatDSTheoTrang_Diem(DSLSV, thaoTac);
					if(thaoTac == THOAT_CT){
						thaoTac = DIEM;
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						
					}else if(thaoTac == THOAT){
						return;
					}else if(thaoTac == DIEM){
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					}
					break;
				}
			}
			
			
		} if(isNull_DK()){
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
