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
	SVDangKy data;
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
	
	void setHead_DSDK(NodeDK *head);
	NodeDK* getHead_DSDK();
};

/*
** ================ SV dang ky ================
*/

SVDangKy::SVDangKy(){
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
	delete next;
}

/*
** ================ DS SV dang ky ================
*/

DSDK::DSDK(){
	head = NULL;
}

DSDK::~DSDK(){
	delete head;
}

void DSDK::setHead_DSDK(NodeDK *head){
	this->head = head;
}

NodeDK* DSDK::getHead_DSDK(){
	return this->head;
}
