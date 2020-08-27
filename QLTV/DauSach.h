#pragma once
#include "mylib.h"
#include "Ve_Hinh.h"
#include "XuLyInput.h"
#include "Date.h"
#include "DefineVar.h"
#include "DanhMucSach.h"

//Ham chuc nang
int checkNull_DauSach(List_DauSach listDS);
int checkFull_DauSach(List_DauSach listDS);
int themDauSach(List_DauSach &listDS,  pDauSach &pDS);
void xoaDauSach_ViTri(List_DauSach &listDS, int viTri);
bool isDauSach_ISBN(List_DauSach listDS, string ISBN);
pDauSach layDauSach_Ten(List_DauSach listDS, string tenSach);
List_DauSach layListDauSach_TheLoai(List_DauSach &listDS, string theLoai);

//Ham xu ly
void Menu_DauSach(List_DauSach &lDS);
void xuat_ListDStheoTT(List_DauSach lDS);
void xuat_DStheoTrang(List_DauSach &lDS, int index);
void xuat_DS(string tenSach, string ISBN, string tacGia, string theLoai, int soTrang, int namXB);
void Xoa_DS_lineS();
void Xoa_DS_line(int toaDo) ;
int chonItems_DS(List_DauSach &lDS, int &thuTuTrang, int tongtrang);
void capNhat_DauSach(List_DauSach &lDS, pDauSach &pDS, bool isEdited);

//Sap xep theo The Loai + Ten Sach
string getString(string a);
int xetThuTu(pDauSach left, pDauSach right);
void swap_DS(pDauSach ds1, pDauSach ds2);
void SSort_DauSach(List_DauSach &lDS);
