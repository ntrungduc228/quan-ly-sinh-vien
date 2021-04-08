#pragma once
#include "Const.h"

class LopSV{
private:
	string maLop;
	DSSV dssv;
	int soSV;
public:
	LopSV();
	~LopSV();
};

LopSV::LopSV(){
	soSV = 0;
}

class NodeLopSV{
private:
	LopSV dslsv;
	NodeSV *next;
public:
};

class DSLopSV{
private:
	NodeLopSV *head;
public:
	DSLopSV();
	~DSLopSV();
};

DSLopSV::DSLopSV(){
	head = NULL;
}

DSLopSV::~DSLopSV(){
	
}
