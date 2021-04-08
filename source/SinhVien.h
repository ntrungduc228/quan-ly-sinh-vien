#pragma once
#include"Const.h"

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
};

class NodeSV{
private:
	SinhVien SV;
	NodeSV *next;
public:
	NodeSV();
	~NodeSV();
};

class DSSV{
private:
	NodeSV *head;
public:
	DSSV();
	~DSSV();
};

SinhVien::SinhVien(){
	phai = "nam";
}

NodeSV::NodeSV(){
	next = NULL;
}

DSSV::DSSV(){
	head = NULL;
}
