#include "DocGia.h"

void khoiTaoCayDG(TreeTDG &t) {
	nDG = 0;
	t = NULL;
}

bool checkNull(TreeTDG t) {
	return t == NULL;
}

NodeTDG* GetNode_DG(TDG dg) {
	NodeTDG *p = new NodeTDG;
	if (p == NULL) {
		return NULL;
	}
	// khoi tao DMS
	taoListMT(p->listMT);
	p->info = dg;
	p->leftTDG = p->rightTDG = NULL;
	return (p);
}

void chenTree(TreeTDG &t, TDG dg) {
	if (t == NULL) {
		t = GetNode_DG(dg);
		++nDG;
	}
	else if (t->info.maThe > dg.maThe) {
		chenTree(t->leftTDG, dg);
	}
	else if (t->info.maThe < dg.maThe) {
		chenTree(t->rightTDG, dg);
	}
}

int demDG(TreeTDG tree) {
	int nut = 1;    
	if (tree == NULL)
		return 0;
	else {
		nut += demDG(tree->leftTDG);
		nut += demDG(tree->rightTDG);
		return nut;
	}
}

bool Check_MADG(TreeTDG  t, int MADG) {
	if (t == NULL) {
		return false;
	}
	else if (t->info.maThe == MADG) {
		return true;
	}
	else if (MADG < t->info.maThe) {
		return Check_MADG(t->leftTDG, MADG);
	}
	else {
		return Check_MADG(t->rightTDG, MADG);
	}
}

int taoRandom() {
	srand((int)time(0));
	int x;
	for (int i = 0; i < 500; i++) {
		x = rand(); // ran() trong vong for
	}
	return x;
}

int randomMaDG(TreeTDG t) {
	int temp;
	do {
		temp = taoRandom();
	} while (Check_MADG(t, temp)); //trung
	return temp;
}

NodeTDG* layMin_NTDG(TreeTDG t) {
	while (t->leftTDG != NULL) t = t->leftTDG;
	return (t);
}

NodeTDG* layDG_NTDG(TreeTDG t, int MADG) {
	while (t != NULL && t->info.maThe != MADG) {
		if (MADG < t->info.maThe) {
			t = t->leftTDG;
		}
		else t = t->rightTDG;
	}
	return (t);
}

bool checkDeleted_DG(TreeTDG &t, TDG dg) {
	if (t == NULL)
		return false;
	else {
		if (dg.maThe > t->info.maThe)
			return checkDeleted_DG(t->rightTDG, dg);
		else if (dg.maThe < t->info.maThe)
			return checkDeleted_DG(t->leftTDG, dg);
		else { 
			//case 1: No child
			if (t->leftTDG == NULL && t->rightTDG == NULL) {
				delete t; 
				t = NULL;
				nDG--;
			}
			else if (t->leftTDG == NULL) { // chi co 1 ben
				NodeTDG* temp = t;
				t = t->rightTDG;
				delete temp;
				nDG--;
			}
			else if (t->rightTDG == NULL) {
				NodeTDG* temp = t;
				t = t->leftTDG;
				delete temp;
				nDG--;
			}
			else {//2 ben
				NodeTDG* temp = layMin_NTDG(t->rightTDG);
				t->info = temp->info;
				t->listMT = temp->listMT;
				return checkDeleted_DG(t->rightTDG, temp->info);
			}
			return true;
		}
	}
}

void Xoa_DG_line(int locate) {
	gotoxy(x_DG[0] + 1, y_Ve + 3 + locate);
	cout << setw(x_DG[1] - x_DG[0] - 1) << setfill(' ') << ' ';
	gotoxy(x_DG[1] + 1, y_Ve + 3 + locate);
	cout << setw(x_DG[2] - x_DG[1] - 1) << setfill(' ') << ' ';
	gotoxy(x_DG[2] + 4, y_Ve + 3 + locate);
	cout << setw(x_DG[3] - x_DG[2] - 5) << setfill(' ') << ' ';
	gotoxy(x_DG[3] + 3, y_Ve + 3 + locate);
	cout << setw(x_DG[4] - x_DG[3] - 3) << setfill(' ') << ' ';
	gotoxy(x_DG[4] + 3, y_Ve + 3 + locate);
	cout << setw(x_DG[5] - x_DG[4] - 3) << setfill(' ') << ' ';
}

void Xoa_DG_lineS() {
	for (int i = 0; i < NUMBER_LINES; i++) {
		Xoa_DG_line(i);
	}
}

void xuat_DG(NodeTDG* dg) {
	Xoa_DG_line(toaDo);
	gotoxy(x_DG[0] + 3, y_Ve + 3 + toaDo);
	cout << dg->info.maThe;
	gotoxy(x_DG[1] + 1, y_Ve + 3 + toaDo);
	cout << dg->info.ho;
	gotoxy(x_DG[2] + 4, y_Ve + 3 + toaDo);
	cout << dg->info.ten;
	gotoxy(x_DG[3] + 3, y_Ve + 3 + toaDo);
	(dg->info.phai == 0) ? cout << "Nam" : cout << "Nu";
	gotoxy(x_DG[4] + 3, y_Ve + 3 + toaDo);
	(dg->info.trangThaiThe == 0) ? cout << "Khoa" : cout << "Hoat dong";
	toaDo++;
}


// loai bo khoang cach.
string layHoTen(TDG dg) {
	int i = 0;
	string token;
	token = dg.ten;
	string temp = dg.ho + ' ';
	while (temp[i] != ' ') {
		token += temp[i++];
	}
	return token;
}

void tao_ArrMaThe(TreeTDG t, int* arr) {
	if (t == NULL)
		return;
	tao_ArrMaThe(t->leftTDG, arr); // visit left subtree
	arr[index++] = t->info.maThe;
	tao_ArrMaThe(t->rightTDG, arr);// visit right subtree
}

void tao_ArrTenHo(TreeTDG t, hoTen* arr) {
	if (t == NULL)
		return;
	tao_ArrTenHo(t->leftTDG, arr); // visit left subtree
	arr[index].hoten = layHoTen(t->info);
	arr[index].MADG = t->info.maThe;
	index++;
	tao_ArrTenHo(t->rightTDG, arr);// visti right subtree
}

void tao_Templist(TreeTDG t, ListTL &l, int &index) {
	if (t == NULL)
		return;
	tao_Templist(t->leftTDG, l, index);
	themCuoiListTL(l, index++, t->info.maThe);
	tao_Templist(t->rightTDG, l, index);
}

void Swap_TenHo(hoTen &a, hoTen &b) {
	hoTen temp;
	temp = a;
	a = b;
	b = temp;
}

void QSort_TenHo(hoTen *th, int left, int right) {
	hoTen key = th[(left + right) / 2];
	int i = left, j = right;
	do {
		while (th[i].hoten < key.hoten)
			i++;
		while (th[j].hoten > key.hoten)
			j--;
		if (i <= j) {
			if (i < j) Swap_TenHo(th[i], th[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) QSort_TenHo(th, left, j);
	if (right > i) QSort_TenHo(th, i, right);
}

void capNhat_DG(TreeTDG &t, TDG &dg, bool isEdited) {
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();
	// cac flag dieu khien qua trinh cap nhat
	int trinhTu = 0;
	bool isSave = false;
	bool isEscape = false;
	// chieu dai bang nhap
	int nngang = (int)keyBangNhapDG[0].length();
	// cac bien luu tru tam thoi
	string ho = "";
	string ten = "";
	int phai = 3, ttthe = 3;
	int MADG;
	gotoxy(x_Note, y_Note);
	cout << "Luu y:";
	ve_BangNhap(x_DG[5] + 7, y_Ve, nngang, keyBangNhapDG, 12);

	if (isEdited) {
		ho = dg.ho;
		ten = dg.ten;
		phai = dg.phai;
		ttthe = dg.trangThaiThe;
		MADG = dg.maThe;
		gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 3);
		cout << MADG;
		gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 5);
		cout << ho;
		gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 7);
		cout << ten;
		gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 9);
		(phai == 0) ? cout << phai << ":  Nam" : cout << phai << ":  Nu";
		gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 11);
		(ttthe == 0) ? cout << ttthe << ":  Khoa" : cout << ttthe << ":  Hoat dong";
	}
	if (!isEdited) {
		gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 3);
		MADG = randomMaDG(t);
		cout << MADG;
	}
	while (true) {
		switch (trinhTu) {
		case 0:
			gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 5);
			NhapHo(ho, trinhTu, isSave, isEscape);
			break;
		case 1:
			gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 7);
			NhapTen(ten, trinhTu, isSave, isEscape);
			break;
		case 2:
			gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 9);
			Nhap(phai, NHAP_PHAI, trinhTu, isSave, isEscape);
			break;
		case 3:
			gotoxy((x_DG[5] + 7 + nngang / 2), y_Ve + 11);
			Nhap(ttthe, NHAP_TRANG_THAI, trinhTu, isSave, isEscape);
			break;
		}
		if (isSave) {
			isSave = false;
			if (ho.length() == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "Du lieu khong de trong ! ";
				normalBGColor();
				trinhTu = 0;
				continue;
			}
			else if (ten.length() == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "Du lieu khong de trong ! ";
				normalBGColor();
				trinhTu = 1;
				continue;
			}
			else if (phai == 3) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "Du lieu khong de trong ! ";
				normalBGColor();
				trinhTu = 2;
				continue;
			}
			else if (ttthe == 3) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "Du lieu khong de trong ! ";
				normalBGColor();
				trinhTu = 3;
				continue;
			}
			dg.maThe = MADG;
			dg.ho = ChuanHoaChuoi(ho);
			dg.ten = ChuanHoaChuoi(ten);
			dg.phai = phai;
			dg.trangThaiThe = ttthe;
			if (isEdited) {
				NodeTDG* p;
				p = layDG_NTDG(t, MADG);
				p->info = dg;
			}
			else {
				chenTree(t, dg);
			}
			// In dong thong bao .
			for (int i = 0; i < 5; i++) {
				SetColor(BLUE);
				gotoxy(x_Note + 15, y_Note);
				cout << "           Hoan tat ! ";
			}
			normalBGColor();
			XoaMotVung(x_DG[5] + 7, y_Ve, 30, 60);
			return;
		}
		if (isEscape) {
			XoaMotVung(x_DG[5] + 7, y_Ve, 30, 60);
			return;
		}
	}
	ShowCur(false);
}

void xuat_DG_Page1(TreeTDG t, hoTen *arr, int index) {
	Xoa_DG_lineS();
	toaDo = 0;
	index--;
	NodeTDG* temp = NULL;
	if (t == NULL)
		return;
	else {
		for (int i = NUMBER_LINES * index; i < NUMBER_LINES*(1 + index) && i < nDG; i++) {
			temp = layDG_NTDG(t, arr[i].MADG);
			xuat_DG(temp);
		}
	}
}

void xuat_ListDG_1(TreeTDG t, hoTen *arr) {
	ShowCur(false);
	nDG = demDG(t);
	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDG / NUMBER_LINES) + 1;
	xuat_DG_Page1(t, arr, tttrang);

	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				xuat_DG_Page1(t, arr, tttrang);
				break;
			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				xuat_DG_Page1(t, arr, tttrang);
				break;
			case ESC:
				return;
			}
		}
		gotoxy(3, 35);
		cout << "HotKey: PgUp, PgDn, ESC, KEYUP, KEYDOWN ";
		gotoxy(55, 1);
		cout << "Page: " << tttrang << "/" << tongtrang;
	} while (true);
}

void xuat_DG_Page2(TreeTDG t, int* arr, int index) {
	Xoa_DG_lineS();
	toaDo = 0;
	NodeTDG* temp = NULL;
	index--;
	for (int i = 0 + NUMBER_LINES * index; i < (NUMBER_LINES + NUMBER_LINES * index) && i < nDG; i++) {
		temp = layDG_NTDG(t, arr[i]);
		xuat_DG(temp);
	}
}

void xuat_ListDG_2(TreeTDG t, int *arr) {
	ShowCur(false);
	nDG = demDG(t);
	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDG / NUMBER_LINES) + 1;
	xuat_DG_Page2(t, arr, tttrang);

	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {

			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				xuat_DG_Page2(t, arr, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				xuat_DG_Page2(t, arr, tttrang);
				break;

			case  ESC:
				return;
			}
		}
		gotoxy(3, 35);
		cout << "HotKey: PgUp, PgDn, ESC, KEYUP, KEYDOWN ";
		gotoxy(55, 1);
		cout << "Page: " << tttrang << "/" << tongtrang;
	} while (true);
}

void xuat_DG_Page(TreeTDG t, ListTL l, int index) {
	Xoa_DG_lineS();
	SetColor(WHITE);
	toaDo = 0;
	NodeTL * temp1 = NULL;
	NodeTDG* temp2 = NULL;
	index--;
	for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (index + 1); i++) {
		temp1 = BSort_TempL(l, i);
		if (temp1 == NULL) {
			return;
		}
		temp2 = layDG_NTDG(t, temp1->tl.MADG);
		xuat_DG(temp2);
	}
}

int chonItems(TreeTDG &t, ListTL &l, int tttrang, int tongtrang) {
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_RED);
	gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
	cout << "->";
	gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
	cout << "";
	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
			case KEY_UP:
				// xoa muc truoc
				gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
				cout << "  ";
				gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
				cout << "  ";

				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
				cout << "->";
				gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
				cout << "";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
				cout << "  ";
				gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
				cout << "  ";

				(pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
				cout << "->";
				gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
				cout << "";
				break;

			case PAGE_UP:
				if (tttrang > 1) {
					tttrang--;
				}
				else {
					tttrang = tongtrang;
				}
				xuat_DG_Page(t, l, tttrang);
				pos = 0;
				SetColor(LIGHT_RED);
				gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
				cout << "->";
				gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
				cout << "";
				break;

			case PAGE_DOWN:
				if (tttrang < tongtrang) {
					tttrang++;
				}
				else {
					tttrang = 1;
				}
				xuat_DG_Page(t, l, tttrang);
				pos = 0;
				SetColor(LIGHT_RED);
				gotoxy(x_DG[0] + 1, y_Ve + 3 + pos);
				cout << "<<";
				gotoxy(x_DG[0] + 2 + 6, y_Ve + 3 + pos);
				cout << ">>";
				break;

			case ENTER:
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
			}
		}
		ShowCur(false);
		SetColor(WHITE);
		gotoxy(60, 1);
		cout << "Page: " << tttrang << "/" << tongtrang;
		normalBGColor();
	}
}

int xuat_ListDG(TreeTDG &t, ListTL &l, TDG &dg, int &thuTuTrang) {
	NodeTL * temp1 = NULL;
	NodeTDG* temp2 = NULL;
	int choose;
	bool check;

	// nDG la so DG hien co trong cay
	nDG = demDG(t);

	// thu tu trang
	int  tongtrang;
	tongtrang = (nDG / NUMBER_LINES) + 1;
	xuat_DG_Page(t, l, thuTuTrang);

	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
			case PAGE_UP:
				(thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
				xuat_DG_Page(t, l, thuTuTrang);
				break;

			case PAGE_DOWN:
				(thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
				xuat_DG_Page(t, l, thuTuTrang);
				break;
				// them
			case F1:
				capNhat_DG(t, dg, false);
				xoaTempL(l);
				return 1;
				// hieu chinh
			case  F2:
				choose = chonItems(t, l, thuTuTrang, tongtrang);
				temp1 = BSort_TempL(l, choose);

				// check cac truong hop.
				if (temp1 == NULL) {
					return 1;
				}
				else {
					temp2 = layDG_NTDG(t, temp1->tl.MADG);
					capNhat_DG(t, temp2->info, true);
					xoaTempL(l);
					return 1;
				}
				// xoa
			case F3:
				choose = chonItems(t, l, thuTuTrang, tongtrang);
				temp1 = BSort_TempL(l, choose);
				// truong hop khong chon doc gia nao.
				if (temp1 == NULL) {
					return 1;
				}
				else {
					temp2 = layDG_NTDG(t, temp1->tl.MADG);
					if (SoSachDangMuon(temp2->listMT) > 0) {
						gotoxy(75, 20);
						cout << "Doc Gia da muon sach nen khong duoc phep xoa !";
						_getch();
						gotoxy(75, 20);
						cout << "                                                      ";
						return 1;
					}
					else {
						// chỗ biến check này để thông báo là check thành công.....
						check = checkDeleted_DG(t, temp2->info);
						xoaTempL(l);
						return 1;
					}
				}

			case ESC:
				xoaTempL(l);
				return 0;
			}
		}
		ShowCur(false);
		gotoxy(60, 1);
		cout << "Page: " << thuTuTrang << "/" << tongtrang;
	} while (true);
}

void Menu_DocGia(TreeTDG &t) {
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;
	do {
		clrscr();
		gotoxy(26, 1);
		cout << "Cap Nhat Doc Gia ";
		gotoxy(3, y_HKey);
		SetColor(WHITE);
		cout << "ESC: Thoat, F1: Them, F2: Sua, F3: Xoa, F5: Luu, PageUp, PageDn";
		normalBGColor();
		TDG dg;
		int index = 0;
		ListTL l;
		taoTempL(l);
		tao_Templist(t, l, index);
		ve_DG(keyDisplayDG, 5, x_DG);
		esc = xuat_ListDG(t, l, dg, tttrang);
	} while (esc);
}

void InDG(TreeTDG t) {
	clrscr();
	normalBGColor();
	ShowCur(false);

	int c = 0;
	int chosen = 0;
	while (c != ESC) {
		clrscr();
		SetColor(WHITE);
		gotoxy(x_DGIA, y_DGIA);
		cout << " 1. Theo thu tu Ten Ho tang dan ";
		gotoxy(x_DGIA, y_DGIA + 2);
		cout << " 2. Theo thu tu Ma Doc Gia tang dan ";
		while (c != ENTER) {
			SetColor(LIGHT_RED);
			gotoxy(x_DGIA - 3, y_DGIA + chosen);
			cout << "->";
			gotoxy(x_DGIA + 40, y_DGIA + chosen);
			cout << "";
			c = _getch();
			if (c == KEY_UP || c == KEY_DOWN) {
				gotoxy(x_DGIA - 3, y_DGIA + chosen);
				cout << "   ";
				gotoxy(x_DGIA + 40, y_DGIA + chosen);
				cout << "   ";
				if (chosen == 0) {
					chosen = 2;
				}
				else if (chosen == 2) {
					chosen = 0;
				}
			}
			else if (c == ESC) {
				return;
			}
		}
		if (chosen == 0) {
			index = 0;
			hoTen* ArrTenHo = new hoTen[nDG];
			tao_ArrTenHo(t, ArrTenHo);
			ve_DG(keyDisplayDG, 5, x_DG);
			QSort_TenHo(ArrTenHo, 0, nDG - 1);
			xuat_ListDG_1(t, ArrTenHo);
			//// xoa vung nho
			delete[] ArrTenHo;
		}
		else if (chosen == 2) {
			index = 0;
			// su dung cap phat dong.
			int* arrMADG = new int[nDG];
			ve_DG(keyDisplayDG, 5, x_DG);
			tao_ArrMaThe(t, arrMADG);
			xuat_ListDG_2(t, arrMADG);
			// xoa vung nho
			delete[]arrMADG;
		}
		c = 0;
		chosen = 0;
	}
}

void QSort_QuaHan(QuaHan *ArrQuaHan, int q, int r) {
	QuaHan temp;
	int i = q;
	int j = r;
	//Lấy phần tử giữa của dãy cần sắp thứ tự làm chốt
	int x = ArrQuaHan[(q + r) / 2].songayquahan;
	do {
		while (ArrQuaHan[i].songayquahan > x)
			i++; 
		while (ArrQuaHan[j].songayquahan < x)
			j--;   
		if (i <= j) { // Hoan vi
			temp = ArrQuaHan[i];
			ArrQuaHan[i] = ArrQuaHan[j];
			ArrQuaHan[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (q < j) QSort_QuaHan(ArrQuaHan, q, j);
	if (i < r) QSort_QuaHan(ArrQuaHan, i, r);
}

void DanhSachQuaHan(TreeTDG t) {
	system("color 0");
	clrscr();
	int nDG_MAX = demDG(t);
	QuaHan *ArrQuaHan = new QuaHan[nDG_MAX];
	int ndg = 0;
	//khong de quy.
	const int STACKSIZE = 500;
	NodeTDG* Stack[STACKSIZE];
	int sp = -1;	// Khoi tao Stack rong
	NodeTDG* p = t;
	while (p != NULL) {
		ArrQuaHan[ndg].MADG = p->info.maThe;
		ArrQuaHan[ndg].songayquahan = soNgayQuaHan(p->listMT);
		ndg++;
		if (p->rightTDG != NULL)
			Stack[++sp] = p->rightTDG;
		if (p->leftTDG != NULL)
			p = p->leftTDG;
		else if (sp == -1)
			break;
		else p = Stack[sp--];
	}
	QSort_QuaHan(ArrQuaHan, 0, ndg - 1);
	string text = "Danh Sach Doc Gia Muon Qua Han ";
	//taoBox(48, 2, text, (int)text.length());

	gotoxy(47, 2);
	cout << "Danh Sach DG Muon Qua Han ";
	gotoxy(3, 5);
	cout << "Stt";
	gotoxy(10, 5);
	cout << "Ma doc gia";
	gotoxy(25, 5);
	cout << "Ho DG";
	gotoxy(40, 5);
	cout << "Ten DG";
	gotoxy(55, 5);
	cout << "Ma sach";
	gotoxy(70, 5);
	cout << "Ten sach";
	gotoxy(97, 5);
	cout << "Ngay muon";
	gotoxy(110, 5);
	cout << "Tong so ngay qua han";
	normalBGColor();
	SetColor(WHITE);

	int j = 0;
	for (int i = 0; i < ndg; i++) {
		if (ArrQuaHan[i].songayquahan > 0) {
			NodeTDG* p = layDG_NTDG(t, ArrQuaHan[i].MADG);
			gotoxy(12, 6 + j);
			cout << p->info.maThe;
			gotoxy(23, 6 + j);
			cout << p->info.ho;
			gotoxy(40, 6 + j);
			cout << p->info.ten;
			gotoxy(55, 6 + j);
			cout << p->listMT.headLMT->info.maSach;
			gotoxy(68, 6 + j);
			cout << p->listMT.headLMT->info.tenSach;
			gotoxy(96, 6 + j);
			cout << p->listMT.headLMT->info.ngayMuon.ngay;
			gotoxy(98, 6 + j);
			cout << "/";
			gotoxy(99, 6 + j);
			cout << p->listMT.headLMT->info.ngayMuon.thang;
			gotoxy(101, 6 + j);
			cout << "/";
			gotoxy(102, 6 + j);
			cout << p->listMT.headLMT->info.ngayMuon.nam;
			gotoxy(120, 6 + j);
			cout << soNgayQuaHan(p->listMT);
			gotoxy(4, 6 + j);
			j++;
			cout << j;
		}
	}
	_getch();
	delete[] ArrQuaHan;
}