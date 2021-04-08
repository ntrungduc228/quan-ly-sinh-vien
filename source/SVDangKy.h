#pragma once
#include "Const.h"

class SVDangKy{
private:
	string maSV;
	float diem;
public:
	SVDangKy();
	~SVDangKy();
};

class NodeDK{
private:
	SVDangKy SVDK;
	NodeDK *next;
public:
	NodeDK();
	~NodeDK();
};

class DSDK{
private:
	NodeDK *head;
public:
	DSDK();
	~DSDK();
};

SVDangKy::SVDangKy(){
	diem = 0;
}

NodeDK::NodeDK(){
	next = NULL;
}

DSDK::DSDK(){
	head = NULL;
}
