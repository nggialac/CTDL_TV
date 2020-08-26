#pragma once


#include <iostream>
#include "Marcro.h"
#include "mylib.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>      // std::setw, setfill

using std::string;  
using std::cout;
using std::setw;
using std::setfill;
	
// Ten cac danh muc trong Menu chinh
extern string keyMainMenu[5];
// Ten cac danh muc trong Menu con
extern string keySubMainMenu3[3];
extern string keySubMainMenu2[3];
extern string keySubMainMenu1[3];
extern string keyBangNhapDauSach[14];
extern string keyBangNhapDanhMucSach[8];
extern string keyBangNhapDG[12];

// ten cac danh muc hien thi  trong bang hien thi doc gia
extern string keyDisplayDG[5];

// ten cac danh muc hien thi trong bang hien thi dau sach
extern string keyDisplayDS[6];

// ten cac danh muc hien thi trong bang hien thi danh muc sach.
extern string keyDisplayDMS[3];

// ten cac danh muc hien thi trong bang hien thi danh sach muon tra.
extern string keyDisplayMT[7];

// ten cac danh muc hien thi trong bang hien thi Top10
extern string keyDisplayTop10[3];

// ten cac danh muc trong muc Guides
extern string keyGuide1[6];
extern string keyGuide2[7];
extern string keyGuide3[4];

// Cac diem toa do x trong bang hien thi doc gia
extern int x_DG[6];

//Cac diem toa do x trong bang hien thi dau sach
extern int x_DS[7];

//Cac diem toa do x trong bang hien thi danh muc sach
extern int x_DMS[4];

//cac diem toa do x trong bang hien thi danh sach muon tra.
extern int x_MT[8];

// cac diem toa do x trong bang hien thi Top10
extern int x_Top10[4];

// Cac diem toa do x trong main menu
extern int x_MainMenus[5];

// Cac diem toa do y trong  menu con
extern int y_SMainMenus1[3];
extern int y_SMainMenus2[3];
extern int y_SMainMenus3[3];

// tao o hinh chu nhat thay doi theo chieu dai text truyen vao
void taoBox(int x, int y, string text, int length);

// ve hinh bang nhap.
void VeHinhBangNhap(int x, int y, int dorong, string str);

// xoa mot dong
void XoaMotDong(int width);

// xoa mot phan man hinh
void XoaMotVung(int x, int y, int ndoc, int width);

// highlight o Main Menu
void HighLight(string key, int index, int newColor, int oldColor);

// highlight o Menu con
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor);

// ve Menu chinh
void MainMenu(string key[], int nKey);

// ve cac Menu con
void SMainMenu1(string key[], int nKey);

void SMainMenu2(string key[], int nKey);

void SMainMenu3(string key[], int nKey);

void hieuUngMenu(int pos, int flag);

void hieuUngSMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);

//hieu ung chon cac muc trong MainMenu
int chonMainMenu(int nKey);

//hieu ung chon cac muc trong SubMenu
int ChonSMenu(string key[], int xSubMenu, int ykey[], int nkey);

// ham hien thi bang thong tin dau sach
void ve_DS(string key[], int nKey, int xDisplay[]);

// ham hien thi bang thong tin doc gia
void ve_DG(string key[], int nKey, int xDisplay[]);

//   ham hien thi bang thong tin danh muc sach
void ve_DMS(string key[], int nKey, int xDisplay[]);

//  ham hien thi bang thong tin danh sach muon tra.
void ve_MT(string key[], int nKey, int xDisplay[]);


// ham hien thi bang thong tin Top10
void ve_Top10(string key[], int nKey, int xDisplay[], int ndoc);

// ve bang nhap thong tin
void ve_BangNhap(int x, int y, int nngang, string key[], int nkey);

// ve bang huong dan Guides
void ve_BangChiBao(int x, int y, int nngang, string key[], int nkey);

