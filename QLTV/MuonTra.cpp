#include "MuonTra.h"

void taoListMT(ListMT &l) {
	l.headLMT = l.tailLMT = NULL;
	l.n = 0;
}

bool checkNullListMT(ListDMS l) {
	return l.headLDMS == NULL;
}

NodeMT* GetNode_MT(MT DATA) {
	NodeMT *p = new NodeMT;
	if (p == NULL) {
		return NULL;
	}
	p->info = DATA;
	p->rightNMT = NULL;
	p->leftNMT = NULL;
	return (p);
}

void themDauList_MT(ListMT &l, MT data) {
	// tao Node
	NodeMT *p = GetNode_MT(data);
	if (l.headLMT == NULL) {
		l.headLMT = l.tailLMT = p;
	} else {
		p->rightNMT = l.headLMT;
		l.headLMT->leftNMT = p;
		l.headLMT = p;
	}
	++l.n;
}

void themCuoiList_MT(ListMT &l, MT data) {
	// tao Node
	NodeMT *p = GetNode_MT(data);
	if (l.headLMT == NULL) {
		l.headLMT = l.tailLMT = p;
	} else {
		p->leftNMT = l.tailLMT;
		l.tailLMT->rightNMT = p;
		l.tailLMT = p;
	}
	++l.n;
}

void xoaListMT(ListMT &l) {
	NodeMT * p;
	while (l.headLMT != NULL) {
		p = l.headLMT;
		l.headLMT = l.headLMT->rightNMT;
		delete p;
	}
}

bool timTenSach_MT(ListMT lMT, string tensach) {
	for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
		if ((p->info.tenSach == tensach && p->info.trangThai == 0) || (p->info.tenSach == tensach && p->info.trangThai == 2)) {
			return true;
		}
	}
	return false;
}

int SoSachDangMuon(ListMT lMT) {
	int i = 0;
	for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
		if (p->info.trangThai == 0 || p->info.trangThai == 2) {
			i++;
		}
	}
	return i;
}

int MatSach(ListMT lMT) {
	for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
		if ( p->info.trangThai == 2) {
			return 1;
		}
	}
	return 0;
}

int soNgayMuonMax(ListMT lMT) {
	int max = 0;
	int nngay;
	for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
		if ((p->info.trangThai == 0) || (p->info.trangThai == 2)) {
			nngay = khoangCachNgay(p->info.ngayMuon);
			if (max < nngay) {
				max = nngay;
			}
		}
	}
	return max;
}

int soNgayQuaHan(ListMT lMT) {
	return (soNgayMuonMax(lMT) - 7);
}


void xuat_MT(NodeMT * p, int i) {
	gotoxy(x_MT[0] + 2, 21 + i);
	cout << p->info.tenSach;
	gotoxy(x_MT[1] + 2, 21 + i);
	cout << p->info.maSach;
	xuatNgayThang(p->info.ngayMuon, x_MT[2] + 2, 21 + i);
	xuatNgayThang(p->info.ngayTra, x_MT[3] + 3, 21 + i);

	gotoxy(x_MT[4] + 9, 21 + i);
	cout << khoangCachNgay(p->info.ngayMuon);
	gotoxy(x_MT[5] + 6, 21 + i);
	cout << p->info.viTriSach;
	gotoxy(x_MT[6] + 2, 21 + i);
	if (p->info.trangThai == 2)
		cout << " Lam Mat Sach";
	else if (khoangCachNgay(p->info.ngayMuon) > 7)
		cout << " M. Qua 7 ngay";
	else if (p->info.trangThai == 0)
		cout << " Dang Muon";
	else if (p->info.trangThai == 1)
		cout << " Da Tra";
}

void xoaManHinh_MT(int i) {
	gotoxy(x_MT[0] + 1, 21 + i);
	cout << setw(x_MT[1] - x_MT[0] - 1) << setfill(' ') << " ";
	gotoxy(x_MT[1] + 1, 21 + i);
	cout << setw(x_MT[2] - x_MT[1] - 1) << setfill(' ') << " ";
	gotoxy(x_MT[2] + 1, 21 + i);
	cout << setw(x_MT[3] - x_MT[2] - 1) << setfill(' ') << " ";
	gotoxy(x_MT[3] + 1, 21 + i);
	cout << setw(x_MT[4] - x_MT[3] - 1) << setfill(' ') << " ";
	gotoxy(x_MT[4] + 1, 21 + i);
	cout << setw(x_MT[5] - x_MT[4] - 1) << setfill(' ') << " ";
	gotoxy(x_MT[5] + 1, 21 + i);
	cout << setw(x_MT[6] - x_MT[5] - 1) << setfill(' ') << " ";
	gotoxy(x_MT[6] + 1, 21 + i);
	cout << setw(x_MT[7] - x_MT[6] - 1) << setfill(' ') << " ";
}

void xuatListMT(ListMT lMT) {
	int i = 0;
	// xoa display dau sach
	for (int j = 0; j < 3; j++) {
		xoaManHinh_MT(j);
	}
	// thuc hien ouput
	for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
		if ( p->info.trangThai == 0 || p->info.trangThai == 2) {
			xuat_MT(p, i);
			i++;
		}
	}
}

void hieuUngMenu_MT(ListMT lMT, int pos, int flag) {
	int i = 0;
	ShowCur(false);
	// get so sach dang muon trong danh sach.
	int n = SoSachDangMuon(lMT);
	// 0 --> 2;  2---> 1;  1---> 0
	if (flag == 1) {
		for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
			if (p->info.trangThai == 0 || p->info.trangThai == 2) {
				if (i == pos) {
					SetBGColor(WHITE);
					SetColor(BLACK);
					xuat_MT(p, i);
					normalBGColor();
				}
				if (i == (pos + n - 1) % n) {
					SetColor(WHITE);
					xuat_MT(p, i);
				}
				i++;
			}
		}
	} else if (flag == 2) {
		// 0 ---> 1; 1 ---> 2; 2 ---> 0
		for (NodeMT * p = lMT.headLMT; p != NULL; p = p->rightNMT) {
			if (p->info.trangThai == 0 || p->info.trangThai == 2) {
				if (i == pos) {
					SetBGColor(WHITE);
					SetColor(BLACK);
					xuat_MT(p, i);
					normalBGColor();
				}
				if (i == (pos + 1) % n) {
					SetColor(WHITE);
					xuat_MT(p, i);
				}
				i++;
			}
		}
	}
}

int chonItem_MT(ListMT lMT) {
	int currpos = 0;
	ShowCur(false);
	// get so sach dang muon trong danh sach.
	int n = SoSachDangMuon(lMT);

	if (n == 0)
		return -1;
	// high light muc dau.
	int i = 0;
	for (NodeMT * p = lMT.headLMT; p != NULL, i != 1; p = p->rightNMT) {
		if (p->info.trangThai == 0 || p->info.trangThai == 2) {
			if (i == 0) {
				SetBGColor(WHITE);
				SetColor(BLACK);
				xuat_MT(p, i);
				normalBGColor();
				i++;
			}
		}
	}
	// xu ly.

	int kb_hit;
	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0) {
				kb_hit = _getch();
			}
			switch (kb_hit) {
				case KEY_UP:
					if (currpos > 0) {
						currpos = currpos - 1;
					} else {
						currpos = n - 1;  // vi tri hien tai bang so so sach muon.
					}
					hieuUngMenu_MT(lMT, currpos, 2);
					break;
				case KEY_DOWN:
					if (currpos <  n - 1) {
						currpos = currpos + 1;
					} else {
						currpos = 0;
					}
					hieuUngMenu_MT(lMT, currpos, 1);
					break;
				case ENTER: 
					return currpos;
			}
		}
	}
	
}
