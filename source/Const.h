#pragma once

#include <winbgim.h> // lib graphics
#include <iostream>	
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime>
using namespace std;

/*
** ================ GRAPHICS ================
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

const int screenWidth = 1400; //1368;
const int screenHeight = 750; //745;

const int frameLeft = 10;
const int frameTop = 5;
const int frameRight = screenWidth - 100;
const int frameBottom = screenHeight - 40;

const int frameBorder = 10;

const int leftSideBar = screenWidth/5 + 20;

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







