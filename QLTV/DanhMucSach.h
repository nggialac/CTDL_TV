#pragma once
#include "mylib.h"
#include "DauSach.h"
#include <string>

//Ham chuc nang DMS
void initList_DMS(ListDMS& ldms);
bool ListDMSIsEmpty(ListDMS ldms);
Node_DMS* getNode_DMS(DMS data);
void themCuoiList_DMS(ListDMS &ldms, DMS data);
int layViTri_Key(Node_DMS *First, string keySearch);
Node_DMS * nodePointer(Node_DMS *First, int i);
void xoaFirst(Node_DMS *&First);
void xoaAfter(Node_DMS *p);
int xoa_Key(pDauSach &pDS, string keySearch);
bool CheckMuon_DMS(Node_DMS* nDMS);
Node_DMS* Search_DMS_MaSach(pDauSach pDS, string masach);
Node_DMS* Search_DMS_ViTri(Node_DMS* dms, int pos);
int SuaDanhMucSach(pDauSach &pDS, Node_DMS* dms);
int NhapSach(pDauSach &pDS);
void NhapDanhMucSach(pDauSach &pDS, int sosach);

//Display
int chonItems1(pDauSach &pDS, int &tttrang, int tongtrang);
int ChonItems(List_DauSach &lDS, int &tttrang, int tongtrang);
void Xoa_OutDMS_29lines();
void Xoa_OutDMS_1line(int locate);
void xuat_ListDMS(pDauSach &pDS);
void xuat_DMS_trang(pDauSach pDS, int index) ;
void xuat_DMS(DMS dms);

//Ham Sort top 10
void Top10Sach(List_DauSach lDS);
int TongSoSachDuocMuon(ListDMS dms);
void Menu_DMS(List_DauSach &lDS);
void sortTop(List_DauSach &listDS, int left, int right);
void swap_DS_Top(pDauSach ds1, pDauSach ds2);



