#pragma once
#include <iostream>
#include "DefineVar.h"
using std::string;

struct TenHo {
	string hoten;
	int MADG;
};
typedef struct TenHo hoTen;

struct TempList {
	int index;
	int MADG;
};
typedef struct TempList TempL;
struct NodeTemp {
	TempL tl;
	struct NodeTemp * pNext;
};
typedef struct NodeTemp NodeTL;
struct ListTempList {
	NodeTL *pHead, *pTail;
};
typedef struct ListTempList ListTL;

//********************************************
void taoTempL(ListTL &l);
NodeTL* GetNodeTempL(int index, int MADG);
void themCuoiListTL(ListTL &l, int index, int MADG);
NodeTL* getMid(NodeTL *start, NodeTL *end);
NodeTL* BSort_TempL(ListTL l, int index);
void xoaTempL(ListTL &l);