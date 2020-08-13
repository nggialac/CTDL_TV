#pragma once
#include <iostream>
#include "Marcro.h"
using std::string;

struct TenHo
{
	string hoten;
	int maDG;
};
typedef struct TenHo tenHo;

struct temp
{
	int index;
	int maDG;
};
typedef struct temp TEMP;

struct TempList
{
	int n;
	TEMP * tl;
};
typedef struct TempList tempList;

// ..... khoi tao........
int checkEmptyTempList(tempList l);
tempList* themTempList(int index, int maDG);
void xoaTempList(TempList &l);

int checkEmptyTempList(tempList l){
	return l.n == NULL;
}

tempList* themTempList(int index, int MADG){
	tempList *p = new tempList;
	if (p == NULL) {
		return NULL;
	}
	p->tl->index = index;
	p->tl->maDG = MADG;
	return (p);
}

void xoaTempList(tempList &l) {
	l.n = 0;
	delete[] l.tl;
}