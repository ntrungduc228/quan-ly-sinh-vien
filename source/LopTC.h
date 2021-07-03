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
	bool huyLop = false;
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
	
	DSDK &getDSDK();
	
	int getSoSVDK();
	
	void setSoSVDK(int soSVDK);
	
	void taoMaLop_LTC(int nLTC);
	
	bool checkTrung_LTC(LopTC ltc);
	
	void huyLopTC();
};

class DSLopTC{
private:
	LopTC *lopTC[MAX_LOPTC] = {NULL};
	int n;	
public:
	
	DSLopTC();
	
	int getN();
	
	bool isNull_LTC();
	
	bool isFull_LTC();
	
	LopTC *&getLopTC(int viTri);

	int them_LTC(LopTC *LTC);
	
	int xoa_LTC(int maLopTC);
	
	int tim_LTC(int maLopTC);
	
	void writeData_LTC(LopTC *LTC, ofstream &fileOut);
	
	void writeDataDS_LTC();
	
	void freeDS_LTC();

	int getMaLopTCMax();
	
	bool checkLopTC(string maMH);
	
	void huyLopDS_LTC();
	
	void huyLopTCTheoKhoaVaHK_LTC(int khoa, int HK);
	
	int checkLopTheoKhoaVaHK_LTC(int khoa, int HK);
	
	void loadDataDS_DK();
	
	void loadDataDS_LTC();
	
	bool checkSVDK_LTC(int maLopTC, string maSV);
	
	bool checkDK_LTC(int viTri, string maSV);
	
	void dangKy_LTC(int viTri, NodeDK *DK);
	
	void dangKyMH_LTC(int maLopTC, NodeDK *DK);
	
	bool checkTrungDS_LTC(LopTC *ltc);
	
	void writeDataDS_DK();
	
	void xuatDS1Trang_LTC(LopTC *loptc[], MonHoc *arrMH, int soLuongMH,  int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac);
	
	void locDS_LTC(string content, LopTC *loptc[], LopTC *lopTC[], int &nFilter, int n, int &tongSoTrang);
	
	void xuatDSTheoTrang_LTC(TREE DSMH, int &viTriChon, Action &thaoTac, Button *menuButton[]);
	
	void resetChooseButton(Button *chooseButton[], LopTC *loptc[],  int n, string maMH, int viTriDaChon, int batDau, int ketThuc);
	
	void dangKyTheoLop_LTC(TREE DSMH, string maSV, int khoa, int HK, Action &thaoTac);
	
	void formDK_LTC(string &maSV, int &khoa, int &HK, Action &thaoTac);
	
	void formHuy_LTC(int &khoa, int &HK, Action &thaoTac);
	
	void formXuatDS_DK(int &viTriChon, Action &thaoTac);
	
	void formNhap_LTC(LopTC *loptc, TREE DSMH, Action &thaoTac, Button *menuButton[]);
	
	void menu_LTC(TREE &DSMH, DSLopSV DSLSV, Action thaoTac, Button *menuButton[]);
	
};

/*
** ================ LopTC ================
*/

LopTC::LopTC(){
	maLopTC = 0;
	maMH = "";
	nienKhoa = 0;
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

DSDK &LopTC::getDSDK(){
		return this->dsdk;
	}
	
int LopTC::getSoSVDK(){
		return this->soSVDK;
	}
	
void LopTC::setSoSVDK(int soSVDK){
		this->soSVDK = soSVDK;
	}
	
void LopTC::taoMaLop_LTC(int nLTC)	{
			this->maLopTC = nLTC +1;
		}
	
bool LopTC::checkTrung_LTC(LopTC ltc){
		
		if(this->maMH == ltc.maMH && this->nienKhoa == ltc.nienKhoa && (this->hocKy == ltc.hocKy && this->nhom == ltc.nhom)){
			return true;
		}
			
		return false;
	}
	
void LopTC::huyLopTC(){
		if(soSVDK < svMin && huyLop == false)
		//if(soSVDK != 0 && soSVDK < svMin && huyLop == false)
			this->huyLop = true;
	}


/*
** ================ Danh sach LopTC ================
*/

DSLopTC::DSLopTC(){
	n = 0;
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

LopTC *&DSLopTC::getLopTC(int viTri){
		return lopTC[viTri];
		
	}

void DSLopTC::writeDataDS_LTC(){
		ofstream fileOut;
		fileOut.open(PATH_LTC.c_str(), ios::out);
		if (fileOut.is_open()) {
			for (int i = 0; i < this->n; i++) {
				writeData_LTC(this->lopTC[i], fileOut);
			}
			
		}
		fileOut.close();
	}

void DSLopTC::freeDS_LTC(){
		for(int i=0; i<n; i++){
			if(this->lopTC[i] != NULL){
				lopTC[i]->getDSDK().freeDS_SV(lopTC[i]->getDSDK().getHead_DSDK());
				delete lopTC[i];
			}
		}
	}

int DSLopTC::getMaLopTCMax(){
		int max = -1;
		if(n>0){
			max = lopTC[0]->getMaLopTC();
			for(int i=1; i<n; i++){
				if(max < lopTC[i]->getMaLopTC())
					max = lopTC[i]->getMaLopTC();
			}
		}
		return max;
	}

bool DSLopTC::checkLopTC(string maMH){
		
		for(int i=0; i<n; i++)
			if(lopTC[i]->getMaMH() == maMH)
				return true;
		
		return false;
	}

void DSLopTC::huyLopDS_LTC(){
		for(int i=0; i<n; i++)
			this->lopTC[i]->huyLopTC();
	}

void DSLopTC::huyLopTCTheoKhoaVaHK_LTC(int khoa, int HK){
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->getNienKhoa() == khoa && this->lopTC[i]->getHocKy() == HK)
				this->lopTC[i]->huyLopTC();
		}
	}

int DSLopTC::checkLopTheoKhoaVaHK_LTC(int khoa, int HK){
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->getNienKhoa() == khoa && this->lopTC[i]->getHocKy() == HK)
				return i;
		}
		
		return  -1;
	}

void DSLopTC::loadDataDS_DK(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp; int maLop; int viTriLop=0; string tempStr; float tempFloat;
		fileIn.open(PATH_DK.c_str(), ios::in);
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
						
						if(this->lopTC[viTriLop]->getDSDK().checkSV_DK(sv.getMaSV())) continue;
						
						NodeDK* DK = new NodeDK(sv);
	
						//cout <<maLop<<" "<<viTriLop<<" " <<DK->data.MASV << " " << DK->data.DIEM<<endl;
						
						this->lopTC[viTriLop]->getDSDK().them_DK(DK);
						this->lopTC[viTriLop]->setSoSVDK(this->lopTC[viTriLop]->getSoSVDK() + 1);
					}
	
	
					if (fileIn.eof()) break;
	
				}
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS SINH VIEN DK ";
			LIST_DATA = "DS SINH VIEN DK";
			loadFileIsSuccess = false;
		}
		
		fileIn.close();
	}

void DSLopTC::loadDataDS_LTC(){ if(!loadFileIsSuccess) return;
		ifstream fileIn; char temp;
		fileIn.open(PATH_LTC.c_str(), ios::in);
		if(fileIn.is_open()){
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
		}else {
			cout<<"\nKHONG TIM THAY FILE DU LIEU DS LOP TC";
			LIST_DATA = "DS LOP TIN CHI";
			loadFileIsSuccess = false;
		}
		fileIn.close();
	}

bool DSLopTC::checkSVDK_LTC(int maLopTC, string maSV){
		int vt = 0;
		for(; vt<n && this->lopTC[vt]->getMaLopTC() != maLopTC; vt++);
		
		if(lopTC[vt]->getMaLopTC() == maLopTC)
			return this->lopTC[vt]->getDSDK().checkSV_DK(maSV);
		
		return false;
	}

bool DSLopTC::checkDK_LTC(int viTri, string maSV){
		
		if(viTri < n ){
			return this->lopTC[viTri]->getDSDK().checkSV_DK(maSV);
		}
		
		return false;
	}

void DSLopTC::dangKy_LTC(int viTri, NodeDK *DK){
		if(viTri < n){
			
			this->lopTC[viTri]->getDSDK().them_DK(DK);
			
			this->lopTC[viTri]->setSoSVDK(this->lopTC[viTri]->getSoSVDK() + 1);
		}
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
	fileOut<<"\n";
}

void DSLopTC::dangKyMH_LTC(int maLopTC, NodeDK *DK){
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->getMaLopTC() == maLopTC){
				dangKy_LTC(i, DK); return;
			}
		}
	}

bool DSLopTC::checkTrungDS_LTC(LopTC *ltc){
		if(this->isNull_LTC()) return false;
		
		for(int i=0; i<n; i++){
			if(this->lopTC[i]->checkTrung_LTC(*(ltc))) return true;
		}
		
		return false;
	}

void DSLopTC::writeDataDS_DK(){
		ofstream fileOut;
		fileOut.open(PATH_DK.c_str(), ios::out);
		if (fileOut.is_open())	{
				for (int i = 0; i < n; i++)	{
					for(NodeDK *k = this->lopTC[i]->getDSDK().getHead_DSDK(); k!= NULL; k=k->getNext_DK())	{
							k->writeData_DK(k->getData_DK(), this->lopTC[i]->getMaLopTC(), fileOut);
							if(k->getNext_DK() != NULL || i + 1 != n ) fileOut << "\n";
						}
						
				}
			
		}
		fileOut.close();
	}

void DSLopTC::xuatDS1Trang_LTC(LopTC *loptc[], MonHoc *arrMH, int soLuongMH,  int batDau, int ketThuc, Button *editButton[], Button *deleteButton[], Table newTable, Action thaoTac){
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
					string((newTable.getCols(0)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); 	x += newTable.getCols(0)->getWidth();
				
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				); x += newTable.getCols(1)->getWidth();
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(2)->getWidth() -4- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
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
				
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(10)->getWidth() - textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				); x += newTable.getCols(10)->getWidth();
				
				View view("",x,yBtn, x+newTable.getCols(11)->getWidth(), yBtn + rowTableHeight, cllightwhite, clblack);
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
					string((newTable.getCols(0)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
				);
			
			// xuat du lieu moi
				outtextxy(x + newTable.getCols(0)->getWidth()/2 - textwidth(strSTT.c_str())/2, y, strSTT.c_str());
				x += newTable.getCols(0)->getWidth();
				
			// xoa du lieu cu
				outtextxy(
					x + textwidth(string("|").c_str()), 
					y, 
					string(	(newTable.getCols(1)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
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
					string((newTable.getCols(2)->getWidth() -4- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),' ').c_str()
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
			
			// lay ten mon hoc	
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
				
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(9)->getWidth()/2  - textwidth(convertIntToString(loptc[i]->getSVMin()).c_str())/2,
						y, 
						convertIntToString(loptc[i]->getSVMin()).c_str()
					);
				x += newTable.getCols(9)->getWidth();
			
			// xoa du lieu cu
				outtextxy(
					x +textwidth(string("|").c_str()), 
					y, 
					string((newTable.getCols(10)->getWidth() -2- textwidth(string("|").c_str())) / textwidth(string(" ").c_str()),	' ').c_str()
				);
			
				trangThai = loptc[i]->getTrangThai() ? "TRUE" : "FALSE";	
			
			// xuat du lieu moi
				outtextxy(
						x + newTable.getCols(10)->getWidth()/2  - textwidth(trangThai.c_str())/2,
						y, 
						trangThai.c_str()
					);
				x += newTable.getCols(10)->getWidth();
			
			if(thaoTac != DIEM && thaoTac != DK_LTC){
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
			}else if(thaoTac == DIEM){
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
			}else if(thaoTac == DK_LTC){
				if(editButton[i] == NULL)
					editButton[i] = new Button(
											"Dang ky",
											strSTT, 
											x+15, 
											yBtn+3, 
											x+45+checkBoxButtonWidth,
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


void DSLopTC::locDS_LTC(string content, LopTC *loptc[], LopTC *lopTC[], int &nFilter, int n, int &tongSoTrang){
		// reset so lop tin chi loc ra duoc
		nFilter = 0; string strMaLopTC;
		if(!content.empty()){
			for(int i=0; i<n; i++){
				strMaLopTC = convertIntToString(lopTC[i]->getMaLopTC());
				if(strMaLopTC.find(content) != string::npos){
					loptc[nFilter++] = lopTC[i];
				}
			}
		}else {
			for(int i=0; i<n; i++){
				loptc[nFilter++] = lopTC[i];
			}
		}
		
		int soDu = (nFilter % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		tongSoTrang = nFilter / MAX_DONG_1_TRANG + soDu;
	}
	

void DSLopTC::xuatDSTheoTrang_LTC(TREE DSMH, int &viTriChon, Action &thaoTac, Button *menuButton[]){
		int tongSoDong = n;
		int nFilter = n; int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0; 
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH); 
		cout<<"\nSo luong sau "<<soLuongMH;
		LopTC *loptc[n] = {NULL};
		for(int i=0; i<n; i++) {
		 	loptc[i] = this->lopTC[i];
		}
		
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
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnThem("THEM LTC","them", 300, 80, 320 + buttonWidth, 120);
		Button btnXuat("XEM DSSV","xuat", 410, 80, 410 + buttonWidth, 120);
		Button btnHuyLTC("HUY LTC", "huy", 500, 80, 500 + buttonWidth, 120);
		Button btnDangKy("DANG KY LTC","dang_ky", 590, 80, 610 + buttonWidth, 120);
		
		if(thaoTac == XUAT || thaoTac == THEM || thaoTac == SUA)	{
			btnThem.draw();
			btnXuat.draw();
			btnHuyLTC.draw();
			btnDangKy.draw();
		}
		
		if(thaoTac == THEM || thaoTac == SUA) {
			newTable.freeTable();
			freeArrButton(editButton, nFilter);
			freeArrButton(deleteButton, nFilter);
			return;
		}
		
		int x,y;
		bool exitLoop = false;
		
		while(!exitLoop){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	clearmouseclick(WM_LBUTTONDOWN);
            	
            	if(newInput.isClicked(x,y)){
            		newInput.requestFocus();
            		newInput.draw();
				}
				
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
            	
            	if(btnBack.isClicked(x,y)){
					thaoTac = THOAT_CT;
					exitLoop = true; continue;
				}
            	
            	// is clicked button Sua || Xoa
            	for(int i=batDau; i<ketThuc; i++){
					if(thaoTac != DIEM) {
						if(editButton[i] != NULL && deleteButton[i] != NULL){
							// btn sua
							if(editButton[i]->isClicked(x,y)){
								cout<<"\n"<<i<<" is clicked "<<editButton[i]->getText();
								int tempMaLopTC = loptc[i]->getMaLopTC();
								viTriChon = tim_LTC(tempMaLopTC);
								thaoTac = SUA;
								newTable.freeTable();
								delete[] arrMH;
								freeArrButton(editButton, nFilter);
								freeArrButton(deleteButton, nFilter);
								return; 
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
				
				if(btnHuyLTC.isClicked(x,y)){
					thaoTac = HUY_LTC; 
					newTable.freeTable();
					delete[] arrMH;
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return; 
					
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
				
				if(btnThem.isClicked(x,y)){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = THEM;
					newTable.freeTable();
					delete[] arrMH;
					freeArrButton(editButton, nFilter);
					freeArrButton(deleteButton, nFilter);
					return;
				}
				
				if(btnDangKy.isClicked(x,y)){
					newInput.setBorderColor(clblack);
					newInput.draw();
					
					thaoTac = DK_LTC;
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
				locDS_LTC(newInput.getContent(), loptc, lopTC, nFilter, tongSoDong, tongSoTrang);
				batDau = 0; trangHienTai = 1;
				ketThuc = (nFilter > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : nFilter;
				xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, editButton, deleteButton, newTable, thaoTac);
				inTrang(trangHienTai, tongSoTrang);
			}
		}
	
		delete[] arrMH;
		newTable.freeTable();
		freeArrButton(editButton, nFilter);
		freeArrButton(deleteButton, nFilter);
	}

void DSLopTC::resetChooseButton(Button *chooseButton[], LopTC *loptc[],  int n, string maMH, int viTriDaChon, int batDau, int ketThuc){
		for(int i=0; i<n; i++){
			if(loptc[i]->getMaMH() == maMH && i != viTriDaChon && chooseButton[i]->getId() != "da_du"){
				if(chooseButton[i]->getId() != "khong_duocchon"){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("khong_duocchon");
					chooseButton[i]->setOffEnable();
					if(batDau <= i && i < ketThuc)
						chooseButton[i]->draw();
				}else {
					chooseButton[i]->setBGColor(claqua);
					chooseButton[i]->setId("");
					chooseButton[i]->setEnable();
					if(batDau <= i && i < ketThuc)
						chooseButton[i]->draw();
				}
				
			}else if(i == viTriDaChon && chooseButton[i]->getId() != "da_du"){
				if(chooseButton[i]->getId() != "dangky" && chooseButton[i]->getId() != "da_dangky"){
					chooseButton[i]->setBGColor(cllightgreen);
					chooseButton[i]->setId("dangky");
					chooseButton[i]->draw();
				}else if(chooseButton[i]->getId() != "da_dangky"){
					chooseButton[i]->setBGColor(claqua);
					chooseButton[i]->setId("");
					chooseButton[i]->draw();
				}
			}
		}
	}

void DSLopTC::dangKyTheoLop_LTC(TREE DSMH, string maSV, int khoa, int HK, Action &thaoTac){
		
		int tongSoDong = 0;
		
		// dem xem co bao nhieu ltc thoa man khoa, hk duoc nhap vao
		for(int i=0; i<n; i++){
			if(lopTC[i]->getNienKhoa() == khoa && lopTC[i]->getHocKy() == HK) 
				tongSoDong++;
		}
		
		if(tongSoDong  == 0){
			
			MessageBox(
					NULL,
					"KHONG TIM THAY LOP TIN CHI !!!",
					"THONG BAO",
					 MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				);
			
			thaoTac = THOAT;
			return;
		}
		
		int nFilter = n; int soLuongMH=0;
		soLuongMH = DSMH.DemSoNodeTrongCay(DSMH.getRoot());
		MonHoc *arrMH = new MonHoc[soLuongMH];
		soLuongMH = 0;
		DSMH.ChuyenCayVaoMang(arrMH, DSMH.getRoot(), soLuongMH);
		
		
		nFilter = tongSoDong;
		LopTC *loptc[nFilter] = {NULL};
		nFilter = 0;
		for(int i=0; i<n; i++){
			if(lopTC[i]->getNienKhoa() == khoa && lopTC[i]->getHocKy() == HK) 
				loptc[nFilter++] = lopTC[i];
 		}
		
		int soDu = (tongSoDong % MAX_DONG_1_TRANG > 0) ? 1 : 0;
		
		int tongSoTrang = tongSoDong / MAX_DONG_1_TRANG + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc = (tongSoDong > MAX_DONG_1_TRANG) ? MAX_DONG_1_TRANG : tongSoDong;
		
		Button *chooseButton[nFilter] = {NULL};
		Button *deleteButton[nFilter] = {NULL};
		
		Table newTable = table_LTC();
		newTable.drawTable(MAX_DONG_1_TRANG);
		
		Button btnPrev("<","btnPrev",buttonPrevX, buttonY, buttonPrevX + buttonWidth, buttonHeight);
		btnPrev.draw();
		
		Button btnNext(">","btnNext",buttonNextX, buttonY, buttonNextX + buttonWidth, buttonHeight);
		btnNext.draw();
		
		// dau X tren cung goc phai
		Button btnBack("X","quay_lai", buttonXLeft, buttonXTop, buttonXLeft + buttonXWidth, buttonXTop + buttonXHeight, cllightred, clred, cllightwhite);
		btnBack.draw();
		
		Button btnSave("Luu","luu",380, 80, 380 + buttonWidth, 120);
		btnSave.draw();
		
		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, chooseButton, deleteButton, newTable, thaoTac);
		inTrang(trangHienTai, tongSoTrang);
		
		int xBtn=tableLeft; int yBtn = tableTop+rowTableHeight;
		for(int i=0; i<newTable.getNumOfCols()-1; i++) xBtn += newTable.getCols(i)->getWidth();
		
		for(int i=ketThuc; i<nFilter; i++){
			if(chooseButton[i] == NULL){
				if(ketThuc % MAX_DONG_1_TRANG) yBtn = tableTop+rowTableHeight;
				chooseButton[i] = new Button(
										"Dang ky1",
										convertIntToString(i+1), 
										xBtn+15, 
										yBtn+3, 
										xBtn+15+checkBoxButtonWidth+30,
										yBtn-3+checkBoxButtonHeight, 
										claqua, 
										cllightblue, 
										clblack
									);
				yBtn += rowTableHeight;
				
				if((loptc[i]->getSVMax() - loptc[i]->getSoSVDK()) == 0){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("da_du");
					chooseButton[i]->setOffEnable();
					chooseButton[i]->draw();
				}
				
			}
		}
		
		// kiem tra nhung lop tc da dang ki truoc do trong nien khoa, hoc ki da nhap
		for(int i=batDau; i<ketThuc; i++){
			if(chooseButton[i] != NULL){
				if(this->checkSVDK_LTC(loptc[i]->getMaLopTC(),maSV)){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("da_dangky");
					chooseButton[i]->setText("Da DK");
					chooseButton[i]->setOffEnable();
					chooseButton[i]->draw();
					resetChooseButton(chooseButton, loptc, nFilter, loptc[i]->getMaMH(), i, batDau, ketThuc);
				}
				
				if((loptc[i]->getSVMax() - loptc[i]->getSoSVDK()) == 0){
					chooseButton[i]->setBGColor(clgray);
					chooseButton[i]->setId("da_du");
					chooseButton[i]->setOffEnable();
					chooseButton[i]->draw();
				}
			}
		}
		
		// da_dangky, dangky, ko_duocchon
		int x,y; char ch;
		
		while(true){
			delay(0.0000);
			// Click event change page output
			if (ismouseclick(WM_LBUTTONDOWN)){
            	getmouseclick(WM_LBUTTONDOWN, x, y);
            	clearmouseclick(WM_LBUTTONDOWN);
            	
            	for(int i=batDau; i<ketThuc; i++){
            		if(chooseButton[i]->isClicked(x,y) && chooseButton[i]->getEnable()){
            			resetChooseButton(chooseButton, loptc, nFilter, loptc[i]->getMaMH(), i, batDau, ketThuc);
					}
				}
				
				if(btnPrev.isClicked(x,y) && (trangHienTai > 1)){
            		
            		trangHienTai = --trangHienTai == 0 ? 1 : trangHienTai;
            		batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
            		ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
            		
            		ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
            		
            	
            		
            		xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, chooseButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
					
					
					
				}
				else if(btnNext.isClicked(x,y) && (trangHienTai < tongSoTrang )) {
						
					trangHienTai = ++trangHienTai > tongSoTrang ? tongSoTrang : trangHienTai;
					batDau = (trangHienTai - 1) * MAX_DONG_1_TRANG;
					ketThuc = (nFilter > MAX_DONG_1_TRANG) ? batDau + MAX_DONG_1_TRANG : nFilter;
					
					ketThuc = (ketThuc > nFilter) ? batDau + nFilter % batDau : ketThuc;
					
					
					
					xuatDS1Trang_LTC(loptc, arrMH, soLuongMH, batDau, ketThuc, chooseButton, deleteButton, newTable, thaoTac);
					inTrang(trangHienTai, tongSoTrang);
					
				}else if(btnBack.isClicked(x,y)){
					
					int isConfirmed = MessageBox(NULL,
												"CAC THAY DOI CUA BAN SE KHONG DUOC LUU",
												"THONG BAO",
												MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
												);
												    		
					switch(isConfirmed){
						case IDCANCEL:{
								break;
						}
										
						case IDOK: default:{	
								thaoTac = THOAT;
			            		newTable.freeTable();
								delete[] arrMH;
								freeArrButton(chooseButton, nFilter);
								return; 	
						}
					}
					
            		
            		
				}else if(btnSave.isClicked(x,y)){
					
					for(int i=0; i<tongSoDong; i++){
						if(chooseButton[i]->getId() == "dangky"){
							SVDangKy sv(maSV);
							NodeDK * dk = new NodeDK(sv);
							
							if(dk != NULL) this->dangKyMH_LTC(loptc[i]->getMaLopTC(), dk);
						}
					}
					
					delete[] arrMH;
					freeArrButton(chooseButton, tongSoDong);
					newTable.freeTable();
					return;
				}
				
			}
			
		} // end while
	}

void DSLopTC::formDK_LTC(string &maSV, int &khoa, int &HK, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300, "Dang ky TC");
		
		int nInput = 3;
		Input *input[nInput] = {NULL};
		
		int left = 650;
		int top = 220;
		
		input[0] = new Input("", "Ma sinh vien ", "0", MAX_MASV, STUDENT_ID, left, top, left+300, top+INPUT_HEIGHT);
		input[1] = new Input("", "Nien khoa ", "1", 4, NUMBER, left, top+INPUT_HEIGHT+20, left+300, top + INPUT_HEIGHT*2 +20);
		input[2] = new Input("", "Hoc ky ", "2", 1, NUMBER, left, top+INPUT_HEIGHT*2+20*2, left+300, top + INPUT_HEIGHT*3 +20*2);
		
		Button btnTT("Tiep tuc","TT",left, top+180, left+buttonWidth, top+INPUT_HEIGHT+190, claqua, cllightblue, clblack);
		btnTT.draw();
		
		Button btnThoat("Thoat", "T", left + 200, top+180, 850+buttonWidth, top+INPUT_HEIGHT+190, cllightred, clred, cllightwhite);
		btnThoat.draw();
		
		int x,y; char ch;
		int oldIndexInput=-1;
		int indexInput=0;
		
		bool isFullInfo = true;
		input[0]->setContent(maSV);
		
		if(khoa != 0)
			input[1]->setContent(convertIntToString(khoa));
		if(HK != 0)
			input[2]->setContent(convertIntToString(HK));
		
		input[indexInput]->requestFocus();
		
		for(int i=0; i<nInput; i++){
			input[i]->draw();
		}
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				for(int i=0; i<nInput; i++){
					if(input[i]->isClicked(x,y) && input[i]->getEnable()){
						input[i]->requestFocus();
						input[i]->draw();
						
						oldIndexInput = indexInput;
						if(oldIndexInput != -1 )
							input[oldIndexInput]->draw();
						indexInput = i;
						break;
					}
				}
				
				if(btnTT.isClicked(x,y)){
					isFullInfo = true;
					
					for(int i=0; i<nInput; i++){
						if(input[i]->getContent().empty()){
							isFullInfo = false; 
							input[i]->requestFocus();
							input[indexInput]->draw();
							indexInput = i;
							input[indexInput]->draw();
							break;
						}
					}
					
					if(isFullInfo){
						
						maSV = input[0]->getContent();
						khoa = atoi(input[1]->getContent().c_str());
						HK = atoi(input[2]->getContent().c_str());
						
						for(int i=0; i<nInput; i++){
							delete input[i];
						}
						return;
						
					}else{
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					}
					
					
				}else if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT; 
					for(int i=0; i<nInput; i++){
						if(input[i] != NULL) delete input[i];
					}
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == TAB){
					oldIndexInput = indexInput;
					if(++indexInput == nInput) indexInput = 0;
					input[indexInput]->requestFocus();
					input[oldIndexInput]->draw();
					input[indexInput]->draw();
				}else if(ch == ENTER){
					isFullInfo = true;
					
					for(int i=0; i<nInput; i++){
						if(input[i]->getContent().empty()){
							isFullInfo = false; 
							input[i]->requestFocus();
							input[indexInput]->draw();
							indexInput = i;
							input[indexInput]->draw();
							break;
						}
					}
					
					if(isFullInfo){
						
						maSV = input[0]->getContent();
						khoa = atoi(input[1]->getContent().c_str());
						HK = atoi(input[2]->getContent().c_str());
						
						for(int i=0; i<nInput; i++){
							delete input[i];
						}
						return;
						
					}else{
						MessageBox(
							        NULL,
							        "VUI LONG NHAP DU THONG TIN !!!",
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					}
				}
				
				input[indexInput]->appendText(ch);
				input[indexInput]->draw();
			}
		}
		
		for(int i=0; i<nInput; i++) delete input[i];
		
	}

void DSLopTC::formHuy_LTC(int &khoa, int &HK, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300, "Huy lop TC");
		
		int nInput = 2;
		Input *input[nInput] = {NULL};
		
		int left = 650;
		int top = 220;
		
		input[0] = new Input("","Nien khoa ","0", 4, NUMBER, left, top, left + 300, top + INPUT_HEIGHT );
		input[1] = new Input("","Hoc ky ","1",1, NUMBER, left, top+INPUT_HEIGHT+20, left+300, top + INPUT_HEIGHT*2 +20);
		
		Button btnHuy("Huy","H",left, top+130, left+buttonWidth, top+INPUT_HEIGHT+130, clyellow, clblack, clblack);
		btnHuy.draw();
		
		Button btnThoat("Thoat", "T", left + 200, top+130, 850+buttonWidth, top+INPUT_HEIGHT+130, cllightred, clred, cllightwhite);
		btnThoat.draw();
		
		int x,y; char ch;
		string notification;
		
		for(int i=0; i<nInput; i++){
			if(input[i] != NULL)
				input[i]->draw();
		}
		
		int oldIndexInput=-1;
		int indexInput=0;
		
		input[indexInput]->requestFocus();
		input[indexInput]->draw();
		
		bool isEnter = false;
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN) || isEnter) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnThoat.isClicked(x,y)){
					thaoTac = THOAT; 
					for(int i=0; i<nInput; i++){
						if(input[i] != NULL) delete input[i];
					}
					clearRegion(500, 150, 550 + 500, 200+300);
					return;
				}
				
				if(btnHuy.isClicked(x,y) && !input[0]->getContent().empty() && !input[1]->getContent().empty() || isEnter){
					isEnter = false;
					int isConfirmed = MessageBox(NULL,
												"HUY CAC LOP TIN CHI KHONG DU DIEU KIEN MO",
												"THONG BAO",
												MB_ICONQUESTION | MB_OKCANCEL | MB_DEFAULT_DESKTOP_ONLY 
												);
												    		
					switch(isConfirmed){
						case IDCANCEL:{
								break;
						}
										
						case IDOK: default:{	
								thaoTac = HUY_LTC;
								khoa = atoi(input[0]->getContent().c_str());
								HK = atoi(input[1]->getContent().c_str());
								
								for(int i=0; i<nInput; i++){
									if(input[i] != NULL) delete input[i];
								}
								
								return; 	
						}
					}
				}else if(btnHuy.isClicked(x,y) || isEnter) {
					
					isEnter = false;	
						
					 if(input[0]->getContent().empty() && input[1]->getContent().empty())
						notification = "KHONG DUOC BO TRONG DU LIEU !!!";
					else  if(input[0]->getContent().empty())
						notification = "VUI LONG NHAP O NIEN KHOA !!!";
					else if(input[1]->getContent().empty())
						notification = "VUI LONG NHAP O HOC KY !!!";
						
						MessageBox(
							        NULL,
							        notification.c_str(),
							        "THONG BAO",
							        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
					    		);
					    		
					
				
				}
				
				for(int i=0; i<nInput; i++){
					if(input[i]->isClicked(x,y) && input[i]->getEnable()){
						input[i]->requestFocus();
						input[i]->draw();
						
						oldIndexInput = indexInput;
						if(oldIndexInput != -1 )
							input[oldIndexInput]->draw();
						indexInput = i;
						break;
					}
				}
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == TAB){
					oldIndexInput = indexInput;
					if(++indexInput == nInput) indexInput = 0;
					input[indexInput]->requestFocus();
					input[oldIndexInput]->draw();
					input[indexInput]->draw();
				}else if(ch == ENTER ){
					isEnter = true;
					continue;
				}
				
				if(indexInput != -1){
					input[indexInput]->appendText(ch);
					input[indexInput]->draw();
				}
			}
		}
	}

void DSLopTC::formXuatDS_DK(int &viTriChon, Action &thaoTac){
		drawFrame(500, 150, 540 + 500, 200+300, "xuat danh sach 1 lop tc");
		
		Input input("","Nhap ma lop tc:" ,"N", 5, NUMBER,  650, 210, 650 + 300, 210 + INPUT_HEIGHT);
		input.requestFocus();
		input.draw();
		
		Button btnXuat("Xem","X",650, 300, 650+buttonWidth, 300+40, claqua, cllightblue, clblack);
		btnXuat.draw();
		
		Button btnHuy("Huy", "H", 850, 300, 850+buttonWidth, 300+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y; char ch;
		
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
				}else if(btnXuat.isClicked(x,y) && input.getContent().empty()){
					MessageBox(
						        NULL,
						        "VUI LONG NHAP DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				}
				
			}
			
			if(kbhit()){
				ch = getch();
				
				if(ch == ENTER){
					if(!input.getContent().empty()){
						viTriChon = atoi(input.getContent().c_str());
						thaoTac = XUAT;
						return;
					}else{
						MessageBox(
						        NULL,
						        "VUI LONG NHAP DU LIEU !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
					} 
				}
				
				input.appendText(ch);
				input.draw();
			}
		}
		
	}

void DSLopTC::formNhap_LTC(LopTC *loptc, TREE DSMH, Action &thaoTac, Button *menuButton[]){
		
		drawFrame(500, 150, 640 + 500, 580, "them lop tc");
		int nInput = 7; 
		Input *input[nInput] = {NULL};
		MonHoc MH;
		int initPos = 1; // vi tri bat dau cua input neu chua co sinh vien dang ky
		
		if(thaoTac == SUA && loptc->getSoSVDK() != 0) initPos = 5; // vi tri bat dau cua input neu da co sinh vien dang ky
		
		
		int left = 650;
		int top = 200;
		
		input[0] = new Input("","Ma lop ","0", 5, NUMBER, left, top, left + 400, top + INPUT_HEIGHT);
		input[1] = new Input("","Ma mon hoc ","1", MAX_MAMH, NON_SPACE, left, top + INPUT_HEIGHT+ 20, left + 200, top + INPUT_HEIGHT * 2 + 20);
		input[2] = new Input("","Nien khoa ","2", 4, NUMBER, left, top+INPUT_HEIGHT*2 + 20*2, left + 90, top + INPUT_HEIGHT * 3 + 20*2);
		input[3] = new Input("","Hoc ky ","3", 1, NUMBER, left+100+60, top+INPUT_HEIGHT*2 + 20*2, left + 250, top + INPUT_HEIGHT * 3 + 20*2);
		input[4] = new Input("","Nhom ","4", 2, NUMBER, left+310, top+INPUT_HEIGHT*2 + 20*2, left + 400, top + INPUT_HEIGHT * 3 + 20*2);
		input[5] = new Input("", "SL Min ","5",3, NUMBER, left, top+INPUT_HEIGHT*3 + 20*3, left + 150, top +INPUT_HEIGHT * 4 + 20*3);
		input[6] = new Input("", "SL Max ","6",3, NUMBER, left + 250, top+INPUT_HEIGHT*3 + 20*3, left + 400, top +INPUT_HEIGHT * 4 + 20*3);
		
		string nameAction, idAction;
		
		if(thaoTac == THEM){
			nameAction = "Them"; idAction = "T";
		}else if(thaoTac == SUA){
			nameAction = "Sua"; idAction = "S";
		}
		
		int clbkcolor = initPos == 1 ? claqua : clgray;
		
		Button btnChonMH("Chon MH","C",left+250, top + INPUT_HEIGHT+ 20, left+250+80, top + INPUT_HEIGHT * 2 + 20, clbkcolor, cllightblue, clblack);
		btnChonMH.draw();
		
		Button btnSave(nameAction, idAction, left, top+INPUT_HEIGHT*6 +20*5, left+buttonWidth, top+INPUT_HEIGHT*6+20*5+40, claqua, cllightblue, clblack);
		btnSave.draw();
		
		Button btnHuy("Huy", "H", left+buttonWidth*2+100, top+INPUT_HEIGHT*6 +20*5, left+buttonWidth*3+100, top+INPUT_HEIGHT*6+20*5+40, cllightred, clred, cllightwhite);
		btnHuy.draw();
		
		int x,y; char ch;
		
		input[0]->setContent(convertIntToString(loptc->getMaLopTC()));
		input[1]->setContent(loptc->getMaMH());
		
		int tempInt;
		
		if(thaoTac == THEM){
			tempInt = loptc->getNienKhoa();
			if(tempInt != 0)
				input[2]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getHocKy();
			if(tempInt != 0)
				input[3]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getNhom();
			if(tempInt != 0)
				input[4]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getSVMin();
			if(tempInt != 0)
				input[5]->setContent(convertIntToString(tempInt));
			
			tempInt = loptc->getSVMax();
			if(tempInt != 0)
				input[6]->setContent(convertIntToString(tempInt));
			
		}
		
		
		if(thaoTac == SUA){
			input[2]->setContent(convertIntToString(loptc->getNienKhoa()));
			input[3]->setContent(convertIntToString(loptc->getHocKy()));
			input[4]->setContent(convertIntToString(loptc->getNhom()));
			input[5]->setContent(convertIntToString(loptc->getSVMin()));
			input[6]->setContent(convertIntToString(loptc->getSVMax()));
		}
		
		int indexInput=initPos;
		int oldIndexInput=1;
		
		bool isFullInfo = true;
		int checkTrung = 0;
		input[indexInput]->requestFocus();
		for(int i=0; i<nInput; i++){
			if(input[i] != NULL){
				input[i]->draw();
			}
		}
		
		
		input[indexInput]->draw();
		string tempMaMHCu;
		
		while(true){
			delay(0.000);
			if(ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				
				if(btnChonMH.isClicked(x,y) && initPos == 1){
					thaoTac = CHON; tempMaMHCu = input[1]->getContent();
					clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					MH = DSMH.chonMH_LTC(thaoTac, menuButton);
					
					if(!MH.getMaMH().empty())
						loptc->setMaMH(MH.getMaMH());
					else loptc->setMaMH(tempMaMHCu);
					loptc->setNienKhoa(atoi(input[2]->getContent().c_str()));
					loptc->setHocKy(atoi(input[3]->getContent().c_str()));
					loptc->setNhom(atoi(input[4]->getContent().c_str()));
					loptc->setSVMin(atoi(input[5]->getContent().c_str()));
					loptc->setSVMax(atoi(input[6]->getContent().c_str()));
					
					for(int i=0; i<nInput; i++)	if(input[i] != NULL) delete input[i];
					return;
					
				}
				
				if(btnSave.isClicked(x,y)){
					isFullInfo = true;
					for(int i=initPos; i<nInput; i++){
						if(input[i]->getContent().empty()){
							MessageBox(
						        NULL,
						        "VUI LONG NHAP DU THONG TIN !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		isFullInfo = false;
				    		break;
						}
					}
					
					if(isFullInfo){
						
						// check xem so luong max co bi be hon so luong min hay ko
						// 5-min 6-max
						if(atoi(input[5]->getContent().c_str()) > atoi(input[6]->getContent().c_str())){
							isFullInfo = false;
							MessageBox(
						        NULL,
						        "SL MAX PHAI LON HON SL MIN !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		continue;
						}
						
						// check ma mon hoc co ton tai trong danh sach hay ko
						MH.setMaMH(input[1]->getContent());
						DSMH.them_MH(DSMH.getRoot(), MH, checkTrung); cout<<"\ncheck trung "<<checkTrung<<" "<<MH.getMaMH();
						if(checkTrung == -1){
							MessageBox(
						        NULL,
						        "MA MON HOC KHONG TON TAI !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
							
							isFullInfo = false;
							checkTrung = 0;
							
							input[1]->requestFocus();
							input[indexInput]->draw();
							indexInput = 1;
							input[indexInput]->draw();
						}
					}
					
					if(isFullInfo && checkTrung==1){
						loptc->setMaMH(input[1]->getContent());
						loptc->setNienKhoa(atoi(input[2]->getContent().c_str()));
						loptc->setHocKy(atoi(input[3]->getContent().c_str()));
						loptc->setNhom(atoi(input[4]->getContent().c_str()));
						loptc->setSVMin(atoi(input[5]->getContent().c_str()));
						loptc->setSVMax(atoi(input[6]->getContent().c_str()));
						
						for(int i=0; i<nInput; i++)
								if(input[i] != NULL) delete input[i];
						return;
					}
				}
				
				if(btnHuy.isClicked(x,y)){
					thaoTac = HUY; 
					clearRegion(500, 150, 640 + 500, 600);
					for(int i=0; i<nInput; i++)
						if(input[i] != NULL) delete input[i];
					return;
				}
				
				// clicked input
				for(int i=initPos; i<nInput; i++){
					if(input[i]->isClicked(x,y) && input[i]->getEnable()){
						input[i]->requestFocus();
						input[i]->draw();
						
						oldIndexInput = indexInput;
						if(oldIndexInput != -1 )
							input[oldIndexInput]->draw();
						indexInput = i;
						break;
					}
				}
				
			}
			
			if(kbhit()){
				ch = getch();
				if(ch == TAB){
					oldIndexInput = indexInput;
					indexInput++;
					if(indexInput == nInput) indexInput = initPos;
					input[indexInput]->requestFocus();
					input[oldIndexInput]->draw();
					input[indexInput]->draw();
					
				}
				
				if(indexInput != -1){
					input[indexInput]->appendText(ch);
					input[indexInput]->draw();
				}
			}
		}
		
		for(int i=0; i<nInput; i++)
			if(input[i] != NULL) delete input[i];
		
	}

void DSLopTC::menu_LTC(TREE &DSMH, DSLopSV DSLSV, Action thaoTac, Button *menuButton[]){
		MonHoc MH;	LopTC *loptc = NULL; bool daThem = true; 
		int viTriChon = 0;
		int khoa = 0, HK = 0;
		string subTitle;
		// DKI LTC
		string maSV = ""; int coSV = -1; int coLTC = -1;
		string strN;
		while(!isNull_LTC() && indexMenu == -1){ 
			strN = convertIntToString(n);
			if(thaoTac != DK_LTC) 
				subTitle = "DANH SACH LOP TIN CHI";
			else 
				subTitle = "DANG KY LOP TIN CHI";
			
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
			if(thaoTac != DK_LTC){
				title.printLabel(
						"  Tong so lop  ",
						strN
					);
			}else if(thaoTac == DK_LTC && coSV != -1 && coLTC != -1){
				title.printLabel(
						"Ma sinh vien",
						maSV
					);
			}		
			
			
			//cout<<"\ncheck thao tac ltc";
			switch(thaoTac){
				case THEM:{
					
					if(n == MAX_LOPTC) {
						MessageBox(
						        NULL,
						        "DS LOP TC DA TOI DA, KHONG THE THEM !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		); thaoTac = XUAT; continue;
					}
					
					if(loptc == NULL || daThem){
						loptc = new LopTC;
						daThem = false;
					}
					
					loptc->taoMaLop_LTC(this->getMaLopTCMax());
					
					thaoTac = THEM;
					formNhap_LTC(loptc, DSMH,thaoTac, menuButton);
					if(thaoTac == HUY){
						delete loptc;
						thaoTac = XUAT;
						daThem = true;
					}else if(thaoTac == THEM){
						if(this->checkTrungDS_LTC(loptc)){
							MessageBox(
						        NULL,
						        "THONG TIN NHAP BI TRUNG VOI THONG TIN DA CO !!!",
						        "THONG BAO",
						        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		
						}else{
							this->them_LTC(loptc);
							MessageBox(
						        NULL,
						        "THEM LOP TIN CHI THANH CONG !!!",
						        "THONG BAO",
						        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		clearRegion(500, 150, 640 + 500, 600);
							thaoTac = XUAT;
							daThem = true;
							
							MH.setMaMH(lopTC[n-1]->getMaMH());
							
							MH.setTT(true);
							int checkTrung = 3;
							DSMH.them_MH(DSMH.getRoot(), MH, checkTrung);
							
							MH.setMaMH(""); MH.setSTCLT(0); MH.setSTCTH(0); MH.setTenMH("");
							this->writeDataDS_LTC();
							DSMH.writeDataDS_MH();
							
						}
					}else if(thaoTac == CHON){
						thaoTac = THEM;
						xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
						//clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
					
					}
					break;
				}
				case SUA:{
					if(viTriChon < n){
							if(!lopTC[viTriChon]->getTrangThai()){
								if(loptc == NULL || daThem) {
								loptc = new LopTC; daThem = false;
								
								loptc->setMaLopTC(lopTC[viTriChon]->getMaLopTC());
								loptc->setMaMH(lopTC[viTriChon]->getMaMH());
								loptc->setNienKhoa(lopTC[viTriChon]->getNienKhoa());
								loptc->setHocKy(lopTC[viTriChon]->getHocKy());
								loptc->setNhom(lopTC[viTriChon]->getNhom());
								loptc->setSVMin(lopTC[viTriChon]->getSVMin());
								loptc->setSVMax(lopTC[viTriChon]->getSVMax());
								loptc->setSoSVDK(lopTC[viTriChon]->getSoSVDK());
								}
								
								formNhap_LTC(loptc, DSMH, thaoTac, menuButton);
								if(thaoTac == HUY){
									delete loptc;
									thaoTac = XUAT; loptc = NULL; daThem = true;
								}else if(thaoTac == SUA){
									if(this->checkTrungDS_LTC(loptc)){
										MessageBox(
									        NULL,
									        "THONG TIN NHAP BI TRUNG VOI THONG TIN DA CO !!!",
									        "THONG BAO",
									        MB_ICONWARNING | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
									}else{
										
										// neu lop tc chua co sinh vien dang ky
										if(lopTC[viTriChon]->getDSDK().isNull_DK()){
											lopTC[viTriChon]->setMaMH(loptc->getMaMH());
											lopTC[viTriChon]->setNienKhoa(loptc->getNienKhoa());
											lopTC[viTriChon]->setHocKy(loptc->getHocKy());
											lopTC[viTriChon]->setNhom(loptc->getNhom());
										}
										
										lopTC[viTriChon]->setSVMin(loptc->getSVMin());
										lopTC[viTriChon]->setSVMax(loptc->getSVMax());
										
										MessageBox(
									        NULL,
									        "SUA LOP TIN CHI THANH CONG !!!",
									        "THONG BAO",
									        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
										clearRegion(500, 150, 640 + 500, 600);
										delete loptc;
										thaoTac = XUAT;
										daThem = true;
										viTriChon = 0;
										this->writeDataDS_LTC();
									}
									
								}else if(thaoTac == CHON){
									thaoTac = SUA;
									xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
								}
							}else { // lop tc da huy, ko duoc sua
								MessageBox(
									        NULL,
									        "LOP TIN CHI BI HUY KHONG THE SUA !!!",
									        "THONG BAO",
									        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
							    	clearRegion(500, 150, 640 + 500, 600);
							    	thaoTac = XUAT;
							}
					}
					break;
				}
				case XOA:{
					if(viTriChon < n){ MH.setMaMH(lopTC[viTriChon]->getMaMH());
						this->xoa_LTC(lopTC[viTriChon]->getMaLopTC());
						if(n == 0)
							clearRegion(tableLeft, INPUT_Y - 30, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							
							// set lai trang thai daMoLop cua mon hoc theo lop tc vua xoa
							int checkTrung = 0;
							
							bool coLop = checkLopTC(MH.getMaMH());
							
							if(coLop==false){
								MH.setTT(false);
								checkTrung = 3;
								DSMH.them_MH(DSMH.getRoot(), MH, checkTrung);
							}
							
							this->writeDataDS_LTC();
							DSMH.writeDataDS_MH();
							MH.setMaMH(""); MH.setSTCLT(0); MH.setSTCTH(0); MH.setTenMH("");
					}
					break;
				}
				case XUAT:{
					xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
					break;
				}
				
				case DIEM:{
					xuatDSTheoTrang_LTC(DSMH, viTriChon, thaoTac, menuButton);
					if(viTriChon < n && indexMenu == -1){
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						MonHoc MH; int temp = 0;
						MH.setMaMH(lopTC[viTriChon]->getMaMH());
						DSMH.them_MH(DSMH.getRoot(), MH, temp );
						lopTC[viTriChon]->getDSDK().menu_DK(
														DSLSV,
														lopTC[viTriChon]->getMaLopTC(),
														lopTC[viTriChon]->getNienKhoa(),
														lopTC[viTriChon]->getHocKy(),
														lopTC[viTriChon]->getNhom(),
														lopTC[viTriChon]->getTrangThai(),
														MH.getTenMH(),
														thaoTac,
														menuButton
													);
						if(thaoTac == THOAT) thaoTac = DIEM;
						clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
						lopTC[viTriChon]->setSoSVDK(lopTC[viTriChon]->getDSDK().demSoLuongSV());
						this->writeDataDS_DK();							
					}
					break;
				}
				
				case XUAT_DS:{
					formXuatDS_DK(viTriChon, thaoTac);
					if(thaoTac == HUY){
						thaoTac = XUAT;
							//menu_LTC(DSMH, DSLSV, thaoTac);
					}else {
						
						viTriChon = this->tim_LTC(viTriChon);
						if(viTriChon==-1){ // khong tim thay lop tin chi
							MessageBox(
						        NULL,
						        "KHONG TIM THAY LOP TIN CHI !!!",
						        "THONG BAO",
						        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
				    		);
				    		
				    		thaoTac = XUAT_DS;
						}else{ // Co lop tin chi
							MonHoc MH; int temp = 0;
							MH.setMaMH(lopTC[viTriChon]->getMaMH());
							DSMH.them_MH(DSMH.getRoot(), MH, temp );
							thaoTac = XUAT_DS;
							if(!lopTC[viTriChon]->getDSDK().isNull_DK()) 
								clearRegion(tableLeft, frameTop+12, frameRight - 12, frameBottom - 12);
								
							lopTC[viTriChon]->getDSDK().menu_DK(
															DSLSV,
															lopTC[viTriChon]->getMaLopTC(),
															lopTC[viTriChon]->getNienKhoa(),
															lopTC[viTriChon]->getHocKy(),
															lopTC[viTriChon]->getNhom(),
															lopTC[viTriChon]->getTrangThai(),
															MH.getTenMH(),
															thaoTac,
															menuButton
														);
							
							clearRegion(tableLeft, frameTop+12, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							lopTC[viTriChon]->setSoSVDK(lopTC[viTriChon]->getDSDK().demSoLuongSV());
							this->writeDataDS_DK();
						}
					}
					break;
				}
				
				case HUY_LTC:{
					
					formHuy_LTC(khoa, HK, thaoTac);
					if(thaoTac == THOAT){
						
					}else {
						this->huyLopTCTheoKhoaVaHK_LTC(khoa, HK);
						MessageBox(
							NULL,
							"HUY THANH CONG!!!",
							"THONG BAO",
							MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);	
						clearRegion(500, 150, 550 + 500, 200+300);	
					}
					khoa = 0; HK = 0;				
					thaoTac=XUAT;
					this->writeDataDS_LTC();
					break;
				}
				
				case DK_LTC:{
					
						if(thaoTac == DK_LTC && coSV == -1 && coLTC == -1){
							formDK_LTC(maSV, khoa, HK, thaoTac);
							if(thaoTac == THOAT){	
								thaoTac = XUAT;
							}else {
								coSV = DSLSV.timSV_LSV(maSV);
								if(coSV == -1){
									MessageBox(
									        NULL,
									        "KHONG TIM THAY SINH VIEN !!!",
									        "THONG BAO",
									        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
							    	coLTC = -1; continue;
								}else {
									
									coLTC = this->checkLopTheoKhoaVaHK_LTC(khoa, HK);
									if(coLTC == -1){
										MessageBox(
									        NULL,
									        "KHONG TIM THAY LOP TIN CHI !!!",
									        "THONG BAO",
									        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    		);
							    		
							    		coSV = -1;  continue;
									}else{
										clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
										
									}
								}
							}
						}else{
							dangKyTheoLop_LTC(DSMH, maSV, khoa, HK, thaoTac);
							if(thaoTac == THOAT){
								clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
								
							}else{
								MessageBox(
									        NULL,
									        "DA LUU THANH CONG !!!",
									        "THONG BAO",
									        MB_ICONINFORMATION | MB_OK | MB_DEFAULT_DESKTOP_ONLY
							    );
							}
							clearRegion(tableLeft, frameTop + 12, frameRight - 12, frameBottom - 12);
							thaoTac = XUAT;
							coSV = -1; coLTC = -1; maSV = "";
							khoa = 0; HK = 0;
							this->writeDataDS_DK();
						}
					
					clearRegion(500, 150, 550 + 500, 200+300);
					
					break;
				}
				
				case THOAT_CT:{
					indexMenu =-1;
					return;
					break;
				}
				
			} // switch case
		
		} 
		if(isNull_LTC()){
			MessageBox(
		        NULL,
		        "HIEN KHONG CO LOP TIN CHI NAO !!!",
		        "THONG BAO",
		        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
    		);
			return;
		}
	}


