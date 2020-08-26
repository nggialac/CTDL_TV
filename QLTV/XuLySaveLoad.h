#pragma once
#include <tchar.h>
#include "DocGia.h"
#include "DauSach.h"
#include <fstream>
#include "DanhMucSach.h"

void ManHinhChinh();
void Save_DS(List_DauSach listDS);
void Load_DS(List_DauSach &listDS);
void Save(TreeTDG t, fstream &file);
void OutFile_DG(TreeTDG t, fstream &file);
void Save_DG(TreeTDG t);
void Load_DG(TreeTDG &t);
int Menu_MS(List_DauSach &lDS, NodeTDG* nDG);
void xuLyMS(TreeTDG &t, List_DauSach &lDS);
void xuLyTS(TreeTDG &t, List_DauSach &lDS);
void xuLyMM(TreeTDG &t, List_DauSach &lDS);
