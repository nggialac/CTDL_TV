#pragma once
#include "DefineVar.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "mylib.h"
#include "Date.h"
using namespace std;

//                      "                         NOTE                             ",
//						" Ma Sach  :  Danh tu dong                           ",
//						" TTrang   :0  = cho muon duoc, 1 = da duoc muon, 2 = da thanh ly",
//						" Vi Tri   : Toi da 17 ky tu (so, chu va ',')   "


//                      "                       NOTE                         ",
//						" Ma Doc Gia    : Ngau nhien    ",
//						" Ho Doc Gia    : Toi da 16 ky tu   ",
//						" Ten Doc Gia   : Toi da 7 ky tu    ",
//						" Phai          : 0 =  NAM, 1 = NU.                       ",
//						" Trang Thai The: 0 = The bi khoa, 1 = The dang hoat dong. "


//                      "                     NOTE                    ",
//						" Ten Sach     : Toi da 24 ky tu ",
//						" ISBN         : Toi da 6 ky tu chu ",
//						" Tac Gia      : Toi da 17 ky tu " ,
//						" The Loai     : Toi da 11 ky tu " ,
//						" So Trang     : So trang khong qua 999999         " ,
//						" Nam Xuat Ban : Nam XB <= nam hien tai "
//

//Ham chuan hoa nhap
void xoa(char* s, int vitrixoa);
char* ChuanHoaKyTu(char* result);
char* toCharArray(string str);
string ChuanHoaChuoi(string result);// bo space
void Nhap(int &result, int choice, int &ordinal, bool &isSave, bool &isEscape);
void NhapISBN(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapNamXuatBan(int &nam, int &ordinal, bool &isSave, bool &isEscape);//
void nhapSoTrang(int &nTrang, int &ordinal, bool &isSave, bool &isEscape);//
void NhapTheLoaiSach(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapTenTacGia(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapTenSach(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapHo(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapTen(string &result, int &ordinal, bool &isSave, bool &isEscape);
int ChonSoSachNhap();
int  NhapMaDauSach(string &result);
void NhapViTri(string &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
void NhapTrangThaiSach(int &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
int  NhapMaDocGia(int &msdg);
int InputMaThe(int &maThe);
int InputNgayThang(NTN &date, int x, int y);
int NhapTenSachTimKiem(string &result);
