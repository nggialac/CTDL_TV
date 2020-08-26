#pragma once
#include "Date.h"
#include "DauSach.h"

//Ham khoi tao
void taoListMT(ListMT &l);
bool checkNullListMT(ListDMS l);
NodeMT* GetNode_MT(MT DATA);
void themDauList_MT(ListMT &l, MT data);
void themCuoiList_MT(ListMT &l, MT data);
void xoaListMT(ListMT &l);
bool timTenSach_MT(ListMT lMT, string tensach);
int SoSachDangMuon(ListMT lMT);
int MatSach(ListMT lMT);
int soNgayMuonMax(ListMT lMT);
int soNgayQuaHan(ListMT lMT);
void xuat_MT(NodeMT * p, int i);
void xoaManHinh_MT(int i);
void xuatListMT(ListMT lMT);
void hieuUngMenu_MT(ListMT lMT, int pos, int flag);
int chonItem_MT(ListMT lMT);

