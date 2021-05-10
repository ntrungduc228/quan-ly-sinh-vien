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
const int clbrown = 6;
const int clwhite = 7;
const int clgray = 8;
const int cllightblue = 9;
const int cllightgreen = 10;
const int cllightaqua = 11;
const int cllightred = 12;
const int cllightpurple = 13;
const int clyellow = 14;
const int cllightwhite = 15;


const int backgroundColor = cllightwhite;
const int FONT_SIZE = 0;
const int FONT_OF_TEXT = 8; 

enum action { THEM, XUAT, SUA, XOA};

/*
** ================ GRAPHICS ================
*/

const int screenWidth = 1460; //1520 1460;
const int screenHeight = 745; //745;

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
const int tableTop = 130;//110; 
const int rowTableHeight = 32;//36; 

const int MAX_DONG_1_TRANG = 15;

/*
** ================ Label ================
*/

const int LABEL_WIDTH = 360;
const int LABEL_HEIGHT = rowTableHeight - 10;
const int LABEL_X = (leftSideBar + frameRight)/2  - LABEL_WIDTH/2;
const int LABEL_Y = frameTop + 20;
const int LABEL_SPACE_Y = LABEL_HEIGHT + 10;
const int LABEL_SPACE_X = 120;

/*
** ================ Input ================
*/

const int INPUT_X = 1000;// 960;
const int INPUT_Y = tableTop - rowTableHeight - 10;
const int INPUT_WIDTH = 320;
const int INPUT_HEIGHT = rowTableHeight;

/*
** ================ Button ================
*/

const int buttonBGColor = cllightgreen;
const int buttonBorderColor = clgreen;
const int buttonTextColor = clblack;

const int buttonPrevX = tableLeft + 320; //tableLeft + 220;
const int buttonNextX = buttonPrevX + 250;//buttonPrevX + 450;

const int buttonY = 650;
const int buttonHeight = buttonY + 36;
const int buttonWidth = 70;

const int checkBoxButtonWidth = 30;
const int checkBoxButtonHeight = 23;
const int checkBoxButtonX = tableLeft + 15;
const int checkBoxButtonY = rowTableHeight-3;

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





