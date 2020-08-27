#pragma once
#include <time.h>
#include <iostream>
#include "mylib.h"
#include "Struct.h"
using namespace std;

#define NAM_MIN 1900
#define NAM_MAX 2200

bool isNamNhuan(int year);
int isNgayDung(NTN d); 
void xuatNgayThang(NTN dt, int x, int y);
void layNgayGioHT(NTN &d); 
int layNamHT();
int tinhNgay(NTN dt);
int khoangCachNgay(NTN nt1); 
int soSanhNgay(NTN nt1, NTN nt2);
