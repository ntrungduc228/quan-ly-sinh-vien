#pragma once

#include <winbgim.h> // lib graphics
#include <iostream>	
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <cmath>
#include<sstream> 


using namespace std;

/*
** ================ General ================
*/

const int clblack = 0;
const int clblue = 1;
const int clgreen = 2;
const int claqua = 3;
const int clred = 4;
const int clpurple = 5;
const int clyellow = 6;
const int clwhite = 7;
const int clgray = 8;
const int cllightblue = 9;
const int cllightgreen = 10;
const int cllightaqua = 11;
const int cllightred = 12;
const int cllightpurple = 13;
const int cllightyellow = 14;
const int cllightwhite = 15;


const int backgroundColor = cllightwhite;
const int FONT_SIZE = 1;
const int FONT_OF_TEXT = 8; //8;

enum action { THEM, XUAT, SUA, XOA};

/*
** ================ GRAPHICS ================
*/



const int screenWidth = 1520; //1460;
const int screenHeight = 750; //745;

const int frameLeft = 10;
const int frameTop = 5;
const int frameRight = screenWidth - 100;
const int frameBottom = screenHeight - 40;
const int frameBorder = 10;

const int leftSideBar = screenWidth/5 - 20;

/*
** ================ Table ================
*/

const int MAX_NUM_COLUMN = 10;
const int tableLeft = leftSideBar + 20;
const int tableTop = 110; //50;
const int rowTableHeight = 32;//36; //30;

const int MAX_DONG_1_TRANG = 15;

/*
** ================ Button ================
*/

const int buttonBGColor = cllightgreen;
const int buttonBorderColor = clgreen;
const int buttonTextColor = clblack;

const int buttonPrevX = tableLeft + 150;
const int buttonNextX = buttonPrevX + 300;

const int buttonY = 660;
const int buttonHeight = buttonY + 36;
const int buttonWidth = 70;

/*
** ================ Define key ================
*/

#define ESC 27
#define ENTER 13
#define SPACE 32
#define BACKSPACE 8

/*
** ================ Duong dan lay data tu file ================
*/

const char *PATH_SAVE_LTC = "data\\DSLTCSave.txt"; // lop tin chi
const char *PATH_SAVE_MH = "data\\DSMHSave.txt";   // mon hoc
const char *PATH_SAVE_SV = "data\\DSSVSave.txt";    // danh sach sinh vien
const char *PATH_SAVE_LSV = "data\\DSLSVSave.txt";  // lop sinh vien
const char *PATH_SAVE_DK = "data\\DSDKSave.txt";   // danh sach dang ky

/*
** ================ Danh sach mon hoc ================
*/

const int MAX_MAMH = 10;
const int MAX_TENMH = 50;

/*
** ================ Danh sach sinh vien ================
*/

const int MAX_MASV = 15;
const int MAX_SDT = 11;
const int MAX_MALOP = 15;

/*
** ================ Lop sinh vien ================
*/

const int MAX_LOPSV = 200;
const int MAXLENGTH_DIEM = 3;

/*
** ================ Lop tin chi ================
*/

const int MAX_LOPTC = 10000;





