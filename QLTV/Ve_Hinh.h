#pragma once
#include <iostream>
#include "DefineVar.h"
#include "mylib.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>    

using std::string;  
using std::cout;
using std::setw;
using std::setfill;
	
//Menu 
extern string keyMainMenu[5];
extern string keySubMainMenu3[3];
extern string keySubMainMenu2[3];
extern string keySubMainMenu1[3];
extern string key_NhapDS[14];
extern string keyBangNhapDanhMucSach[8];
extern string keyBangNhapDG[12];

//
extern string keyDisplayDG[5];
extern string keyDisplayDS[6];
extern string keyDisplayDMS[3];
extern string keyDisplayMT[7];
extern string keyDisplayTop10[3];

extern int x_DG[6];
extern int x_DS[7];
extern int x_DMS[4];
extern int x_MT[8];
extern int x_Top10[4];
extern int x_MainMenus[5];

// Cac diem toa do y trong  menu con
extern int y_SMainMenus1[3];
extern int y_SMainMenus2[3];
extern int y_SMainMenus3[3];

void taoBox(int x, int y, string text, int length);
void VeHinhBangNhap(int x, int y, int dorong, string str);
void XoaMotDong(int width);
void XoaMotVung(int x, int y, int ndoc, int width);
void HighLight(string key, int index, int newColor, int oldColor);
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor);
void MainMenu(string key[], int nKey);
void SMainMenu1(string key[], int nKey);
void SMainMenu2(string key[], int nKey);
void SMainMenu3(string key[], int nKey);
void hieuUngMenu(int pos, int flag);
void hieuUngSMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);
int chonMainMenu(int nKey);
int ChonSMenu(string key[], int xSubMenu, int ykey[], int nkey);

//Ham ve bang
void ve_DS(string key[], int nKey, int xDisplay[]);
void ve_DG(string key[], int nKey, int xDisplay[]);
void ve_DMS(string key[], int nKey, int xDisplay[]);
void ve_MT(string key[], int nKey, int xDisplay[]);
void ve_Top10(string key[], int nKey, int xDisplay[], int ndoc);
void ve_BangNhap(int x, int y, int nngang, string key[], int nkey);
void ve_BangChiBao(int x, int y, int nngang, string key[], int nkey);

