#pragma once
#include <iostream>
#include "XuLyTam.h"
#include "Struct.h"
#include "MuonTra.h"
#include "XuLyInput.h"
#include "Ve_Hinh.h"
#include "mylib.h"

//Ham khoi tao
void khoiTaoCayDG(TreeTDG &t);
bool checkNull(TreeTDG t);
NodeTDG* GetNode_DG(TDG dg);
void chenTree(TreeTDG &t, TDG dg);

//Ham xu ly
int demDG(TreeTDG tree);
bool Check_MADG(TreeTDG  t, int MADG);
int taoRandom();
int randomMaDG(TreeTDG t);
NodeTDG* layMin_NTDG(TreeTDG t);
NodeTDG* layDG_NTDG(TreeTDG t, int MADG);
bool checkDeleted_DG(TreeTDG &t, TDG dg);
void Xoa_DG_line(int toaDo);
void Xoa_DG_lineS();
void xuat_DG(NodeTDG* dg);
string layHoTen(TDG dg);
void tao_ArrMaThe(TreeTDG t, int* arr);
void tao_ArrTenHo(TreeTDG t, hoTen* arr);
void tao_Templist(TreeTDG t, ListTL &l, int &index);
void Swap_TenHo(hoTen &a, hoTen &b);
void QSort_TenHo(hoTen *th, int left, int right);

//Cac ham xuat
void capNhat_DG(TreeTDG &t, TDG &dg, bool isEdited = false);
void xuat_DG_Page(TreeTDG t, ListTL l, int index);
void xuat_DG_Page1(TreeTDG t, hoTen *arr, int index);
void xuat_DG_Page2(TreeTDG t, int* arr, int index);
void xuat_ListDG_2(TreeTDG t, int *arr);
void xuat_ListDG_1(TreeTDG t, hoTen *arr);
int xuat_ListDG(TreeTDG &t, ListTL &l, TDG &dg, int &thuTuTrang);
int chonItems(TreeTDG &t, ListTL &l, int thuTuTrang, int tongtrang);
void Menu_DocGia(TreeTDG &t);
void InDG(TreeTDG t);

// 
void QSort_QuaHan(QuaHan *ArrQuaHan, int q, int r);
void DanhSachQuaHan(TreeTDG t);
