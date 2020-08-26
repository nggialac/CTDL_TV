#pragma once
#include "mylib.h"
#include "Ve_Hinh.h"
#include "XuLyInput.h"
#include "Date.h"
#include "Marcro.h"
#include "DanhMucSach.h"

//Ham chuc nang Dau Sach
int checkNull_DauSach(List_DauSach listDS);
int checkFull_DauSach(List_DauSach listDS);
int themDauSach(List_DauSach &listDS,  pDauSach &pDS);
void xoaDauSach_ViTri(List_DauSach &listDS, int viTri);
bool isDauSach_ISBN(List_DauSach listDS, string ISBN);
pDauSach layDauSach_Ten(List_DauSach listDS, string tenSach);
List_DauSach layDauSach_TheLoai(List_DauSach &listDS, string theLoai);

//Ham xu ly Dau Sach
void Menu_DauSach(List_DauSach &lDS);
void xuat_ListDStheoTT(List_DauSach lDS);
void xuat_DStheoPage(List_DauSach &lDS, int index);
void Output_DS(string tenSach, string ISBN, string tacGia, string theLoai, int soTrang, int namXB);
void Xoa_DS_lineS();
void Xoa_DS_line(int toaDo) ;
int chonItems_DS(List_DauSach &lDS, int &thuTuTrang, int tongtrang);
void capNhat_DauSach(List_DauSach &lDS, pDauSach &pDS, bool isEdited);

//Sap xep, Sort
string getString(string a);
int xetThuTu(pDauSach left, pDauSach right);
void swap_DS(pDauSach ds1, pDauSach ds2);
void SSort_DauSach(List_DauSach &lDS);
