#pragma once

#include "Const.h"

class MonHoc{
private:
	string maMH;
	string tenMH;
	int STCLT;
	int STCTH;
public:
	MonHoc();
	~MonHoc();
};

class NodeMonHoc{
private:
	MonHoc monHoc;
	NodeMonHoc *left;
	NodeMonHoc *right;	
public:
	NodeMonHoc();
	~NodeMonHoc();
};

class TREE{
private:
	NodeMonHoc *data;
public:
	TREE();
	~TREE();
};

MonHoc::MonHoc(){
	maMH = "";
	tenMH = "";
	STCLT = 0;
	STCTH = 0;
}

MonHoc::~MonHoc(){
	
}


NodeMonHoc::NodeMonHoc(){
	left = NULL;
	right = NULL;
}

NodeMonHoc::~NodeMonHoc(){
	delete left;
	delete right;
}

TREE::TREE(){
	data = NULL;
}

TREE::~TREE(){
	delete data;
}




