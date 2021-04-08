#pragma once
#include "Const.h"

class LopTC{
private:
	int maLopTC;
	string maMH;
	int nienKhoa;
	int hocKy;
	int nhom;
	int svMAX;
	int svMin;
	bool trangThai;
	DSDK dsdk;
public:
	LopTC();
	~LopTC();
};

class DSLopTC{
private:
	LopTC *lopTC[MAX_LOPTC];
	int n;	
public:
	DSLopTC();
	~DSLopTC();
	int getN();
};

LopTC::LopTC(){
	trangThai = true;
}

DSLopTC::DSLopTC(){
	n = 0;
}

DSLopTC::~DSLopTC(){
	
}

int DSLopTC::getN(){
	return this->n;
}
