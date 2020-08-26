#pragma once

#include "mylib.h"
#include "DauSach.h"
#include <string>

//Ham chuc nang DMS
void initList_DMS(ListDMS& ldms);
bool ListDMSIsEmpty(ListDMS ldms);
Node_DMS* getNode_DMS(DMS data);
void addTailList_DMS(ListDMS &ldms, DMS data);
int layViTri_Key(Node_DMS *First, string keySearch);
Node_DMS * nodePointer(Node_DMS *First, int i);
void xoaFirst(Node_DMS *&First);
void xoaAfter(Node_DMS *p);
int xoa_Key(pDauSach &pDS, string keySearch);
bool Check_DMS(Node_DMS* nDMS);
// tim kiem tra ve con tro nut 1
Node_DMS* Search_DMS1(pDauSach pDS, string masach);
// tim kiem tra ve con tro nut 2
Node_DMS* Search_DMS2(Node_DMS* dms, int pos);

//
int ChooseItems1(pDauSach &pDS, int &tttrang, int tongtrang);
int ChooseItems(List_DauSach &lDS, int &tttrang, int tongtrang);
void Xoa_OutDMS_29lines();
void Xoa_OutDMS_1line(int locate);
int SuaDanhMucSach(pDauSach &pDS, Node_DMS* dms) ;
int NhapSach(pDauSach &pDS);
void NhapDanhMucSach(pDauSach &pDS, int sosach);
void Output_ListDMS(pDauSach &pDS);
void OutputDMS_PerPage(pDauSach pDS, int index) ;
void Output_DMS(DMS dms);
//
void Top10Sach(List_DauSach lDS);
int TongSoSachDuocMuon(ListDMS dms);
void Menu_DMS(List_DauSach &lDS);

void sortTop(List_DauSach &listDS, int left, int right);
void swap_DS_Top(pDauSach ds1, pDauSach ds2);



