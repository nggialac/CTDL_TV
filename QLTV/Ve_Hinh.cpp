#include "Ve_Hinh.h"

string keyMainMenu[5] = { "", "QUAN LY DAU SACH", "QUAN LY DOC GIA ", "QUAN LY SACH", "THOAT" };

string keySubMainMenu3[3] = { "       TRA SACH       ",
							  " SACH MUON NHIEU NHAT ",
							  "       MUON SACH      "
};

string keySubMainMenu2[3] = { "    CAP NHAT DOC GIA     ",
							  "    DS TAT CA DOC GIA    ",
							  " DS DG MUON SACH QUA HAN "
};


string keySubMainMenu1[3] = { "   CAP NHAT DAU SACH   ",
							  " HIEN THI CAC DAU SACH " ,
							  " CAP NHAT DANH MUC SACH "
};


string keyBangNhapDauSach[14] = { "               Cap Nhat Dau Sach               ",
									"                                                   ",
									" Ten Sach     :",
									"                                                   ",
									" ISBN         :",
									"                                                   ",
									" Tac Gia      :",
									"                                                   ",
									" The Loai     :",
									"                                                   ",
									" So Trang     :",
									"                                                   ",
									" Nam Xuat Ban :",
									"                                                   "
};


string keyBangNhapDanhMucSach[8] = { "                    Cap Nhat Danh Muc Sach                   ",
									"                                                                   ",
									" Ma Sach           :",
									"                                                                   ",
									" Trang Thai(0,1,2) :",
									"                                                                   ",
									" Vi tri cua sach   :",
									"                                                                   "
};

string keyBangNhapDG[12] = { "                Cap Nhat The Doc Gia                      ",
							 "                                                            ",
							 " Ma Doc Gia   :",
							 "                                                            ",
							 " Ho Doc Gia   :",
							 "                                                            ",
							 " Ten Doc Gia  :",
							 "                                                            ",
							 " Phai [0, 1]  :",
							 "                                                            ",
							 " TT the [0, 1]:",
							 "                                                            ",
};



string keyDisplayDG[5] = { "Ma DG", "     Ho DG", "Ten DG", "Phai  ", "TTr The" };

string keyDisplayDS[6] = { "        Dau Sach", "ISBN", "    Tac Gia", "  The Loai ", " So Trg ", " NXB" };

string keyDisplayDMS[3] = { "Ma Sach", "Trang Thai", "            Vi Tri" };

string keyDisplayMT[7] = { "          Ten Sach", "Ma Sach", "   Ngay Muon", "   Ngay Tra", "So Ngay Da Muon", "        Vi Tri Sach", "  Trang Thai" };

string keyDisplayTop10[3] = { "   So Thu Tu", "          Ten Sach", " So Luot Muon Sach Thuoc Dau Sach" };

string keyGuide1[6] = { "                       NOTE                         ",
						" Ma Doc Gia    : Ngau nhien    ",
						" Ho Doc Gia    : Toi da 16 ky tu   ",
						" Ten Doc Gia   : Toi da 7 ky tu    ",
						" Phai          : 0 =  NAM, 1 = NU.                       ",
						" Trang Thai The: 0 = The bi khoa, 1 = The dang hoat dong. "
};

string keyGuide2[7] = { "                     NOTE                    ",
						" Ten Sach     : Toi da 24 ky tu ",
						" ISBN         : Toi da 6 ky tu chu ",
						" Tac Gia      : Toi da 17 ky tu " ,
						" The Loai     : Toi da 11 ky tu " ,
						" So Trang     : So trang khong qua 999999         " ,
						" Nam Xuat Ban : Nam XB <= nam hien tai "
};


string keyGuide3[4] = { "                         NOTE                             ",
						" Ma Sach  :  Danh tu dong                           ",
						" TTrang   :0  = cho muon duoc, 1 = da duoc muon, 2 = da thanh ly",
						" Vi Tri   : Toi da 17 ky tu (so, chu va ',')   "
};



int x_DG[6] = { 3,13, 32,43,53,65 };
int x_DS[7] = { 1, 29, 36, 55, 67, 74 , 80 };
int x_DMS[4] = { 2, 14,29,64 };
int x_MT[8] = { 2, 30, 39, 55, 70, 88, 115, 132};
int x_Top10[4] = { 30, 45, 77, 112 };

int x_MainMenus[5] = { 8,26,52, 81,105 };
int y_SMainMenus1[3] = { 16, 19, 22};
int y_SMainMenus2[3] = { 16, 19, 22 };
int y_SMainMenus3[3] = { 16, 19, 22 };

void taoBox(int x, int y, string text, int length) {
	gotoxy(x - 2, y - 1);
	cout << char(218) << setw(length) << setfill(char(196)) << char(196) << char(191);

	gotoxy(x - 2, y);
	cout << char(179) << text << setw(length - text.length() + 1) << setfill(' ') << char(179);

	gotoxy(x - 2, y + 1);
	cout << char(192) << setw(length) << setfill(char(196)) << char(196) << char(217);
}

void VeHinhBangNhap(int x, int y, int dorong, string str) {
	SetBGColor(WHITE);
	SetColor(BLACK);
	dorong -= 3;
	gotoxy(x, y - 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y );
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y + 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x + (int)str.length()/ 3, y + 1);
	cout << setw((int)str.length() / 3  + 3) << setfill('=') << "=";

	gotoxy(x, y );
	cout << str;
	gotoxy(x, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x + dorong - 4, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x, y + 3);
	cout << setw(dorong) << setfill(' ') << " ";
	normalBGColor();
}

void XoaMotDong(int width) {
	SetBGColor(BLACK);
	cout << " " << setw(width) << setfill(' ') << " ";
}

void XoaMotVung(int x, int y, int ndoc, int width) {
	for (int i = 0; i < ndoc; i++) {
		gotoxy(x, y + i);
		XoaMotDong(width);
	}
}

void HighLight(string key, int index, int newColor, int oldColor) {
	gotoxy(x_MainMenus[index] - 1, yMainMenu);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}

void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor) {
	// den dia chi can highlight
	gotoxy(x - 1, y[index]);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}

void MainMenu(string key[], int nKey) {
	normalBGColor();
	for (int i = 1; i < nKey; i++) {
		taoBox(x_MainMenus[i], yMainMenu, key[i],(int)key[i].length());
	}
}

void SMainMenu1(string key[], int nKey) {
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(x_SMainMenus1, y_SMainMenus1[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu1[0], 0, x_SMainMenus1, y_SMainMenus1, LIGHT_RED, BLACK);
	ShowCur(false);
}

void SMainMenu2(string key[], int nKey) {
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(x_SMainMenus2, y_SMainMenus2[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu2[0], 0, x_SMainMenus2, y_SMainMenus2, LIGHT_RED, BLACK);
	ShowCur(false);
}

void SMainMenu3(string key[], int nKey) {
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(x_SMainMenus3, y_SMainMenus3[i], key[i],(int)key[i].length());
	}
	HighLight1(keySubMainMenu3[0], 0, x_SMainMenus3, y_SMainMenus3, LIGHT_RED, BLACK);
	ShowCur(false);
}

void hieuUngMenu(int pos, int flag) {
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1) {
		ShowCur(false);
		gotoxy(x_MainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(LIGHT_RED);
		SetColor(WHITE);
		cout << keyMainMenu[pos + 1];
		gotoxy(x_MainMenus[(pos + 3) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 3) % 4 + 1];
	} else if (flag == 2) {
		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);
		gotoxy(x_MainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(LIGHT_RED);
		SetColor(WHITE);
		cout << keyMainMenu[pos + 1];
		gotoxy(x_MainMenus[(pos + 1) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 1) % 4 + 1];
	}
}

void hieuUngSMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag) {
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1) {
		ShowCur(false);
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(LIGHT_RED);
		SetColor(WHITE);
		cout << key[pos];
		gotoxy(xSubMenu - 1, ykey[(pos + nkey - 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(WHITE);
		cout << key[(pos + nkey - 1) % nkey];
	} else if (flag == 2) {
		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(LIGHT_RED);
		SetColor(WHITE);
		cout << key[pos];
		gotoxy(xSubMenu - 1, ykey[(pos + 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(WHITE);
		cout << key[(pos + 1) % nkey];
	}
}

int chonMainMenu(int nKey) {
	int currposMainMenu = -1;
	ShowCur(false);
	int kb_hit;
	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0) {
				kb_hit = _getch();
			}
			switch (kb_hit) {
				case KEY_LEFT:
					if (currposMainMenu > 0) {
						currposMainMenu = currposMainMenu - 1;
					} else {
						currposMainMenu = nKey - 2;
					}
					hieuUngMenu(currposMainMenu, 2);
					break;
				case KEY_RIGHT: 
					if (currposMainMenu < nKey - 2) {
						currposMainMenu = currposMainMenu + 1;
					} else {
						currposMainMenu = 0;
					}
					hieuUngMenu(currposMainMenu, 1);
					break;
				case ENTER: //enter
					return currposMainMenu;
			}
		}
	}
}


int ChonSMenu(string key[], int xSubMenu, int ykey[], int nkey) {
	int currposSubMainMenu = 0;
	ShowCur(false);
	int kb_hit;
	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case KEY_UP:
					if (currposSubMainMenu > 0) {
						currposSubMainMenu = currposSubMainMenu - 1;
					} else {
						currposSubMainMenu = nkey - 1;
					}
					hieuUngSMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 2);
					break;
				case KEY_DOWN:
					if (currposSubMainMenu < nkey - 1) {
						currposSubMainMenu = currposSubMainMenu + 1;
					} else {
						currposSubMainMenu = 0;
					}
					hieuUngSMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 1);
					break;
				case ESC:
					return -1;
				case ENTER:
					return currposSubMainMenu;
			}
		}
	}
}

// ham hien thi bang thong tin
void ve_DG(string key[], int nKey, int xDisplay[]) {
	ShowCur(true);
	normalBGColor();
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++) {
		gotoxy(xDisplay[i] + 3, y_Ve + 1);
		cout << key[i];
	}
	//hien thi cot hai ben
	SetColor(WHITE);
	for (int j = y_Ve; j <= y_Ve + 32; j++) {
		for (int i = 0; i < nKey + 1; i++) {
			gotoxy(xDisplay[i], j);

			cout << char(179);
		}
	}
	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++) {
		gotoxy(i, y_Ve);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(194);//nga 3
		else if (i == xDisplay[0]) {
			cout << char(218); //moc phai
		} else if (i == xDisplay[nKey]) {
			cout << char(191);//moc trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_Ve + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(197); //nga 4
		else if (i == xDisplay[0]) {
			cout << char(195); //nga 3 sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(180);//nga 3 sang trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_Ve + 32);
		if (i == xDisplay[nKey]) {
			cout << char(217); //nga 3 sang trai
		} else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(193);
		else if (i == xDisplay[0])
			cout << char(192); //nga 3 sang phai
		else {
			cout << char(196); //duong thang ngang
		}
	}
}

void ve_DS(string key[], int nKey, int xDisplay[]) {
	normalBGColor();
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++) {
		gotoxy(xDisplay[i] + 1, y_Ve + 1);
		cout << key[i];
	}
	//hien thi cot hai ben
	SetColor(WHITE);
	for (int j = y_Ve; j <= y_Ve + 32; j++) {
		for (int i = 0; i < nKey + 1; i++) {
			gotoxy(xDisplay[i], j);
			cout << char(179);
		}
	}
	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++) {
		gotoxy(i, y_Ve);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4]  || i == xDisplay[5])
			cout << char(194);//nga 3
		else if (i == xDisplay[0]) {
			cout << char(218); //moc phai
		} else if (i == xDisplay[nKey]) {
			cout << char(191);//moc trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_Ve + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
			cout << char(197); //nga 4
		else if (i == xDisplay[0]) {
			cout << char(195); //nga 3 sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(180);//nga 3 sang trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_Ve + 32);
		if (i == xDisplay[0]) {
			cout << char(192); //qeo sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(217); //qeo sang trai
		} else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
			cout << char(193);
		else {
			cout << char(196); //duong thang ngang
		}
	}
}

// ham hien thi bang thong tin
void ve_DMS(string key[], int nKey, int xDisplay[]) {
	ShowCur(true);
	normalBGColor();
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++) {
		gotoxy(xDisplay[i] + 3, y_Ve + 1);
		cout << key[i];
	}
	//hien thi cot hai ben
	SetColor(WHITE);
	for (int j = y_Ve; j <= y_Ve + 32; j++) {
		for (int i = 0; i < nKey + 1; i++) {
			gotoxy(xDisplay[i], j);

			cout << char(179);
		}
	}
	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++) {
		gotoxy(i, y_Ve);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3])
			cout << char(194);//nga 3
		else if (i == xDisplay[0]) {
			cout << char(218); //moc phai
		} else if (i == xDisplay[nKey]) {
			cout << char(191);//moc trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_Ve + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(197); //nga 4
		else if (i == xDisplay[0]) {
			cout << char(195); //nga 3 sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(180);//nga 3 sang trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_Ve + 32);
		if (i == xDisplay[nKey]) {
			cout << char(217); //nga 3 sang trai
		} else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(193);
		else if (i == xDisplay[0])
			cout << char(192); //nga 3 sang phai
		else {
			cout << char(196); //duong thang ngang
		}
	}
}

void ve_MT(string key[], int nKey, int xDisplay[]) {
	normalBGColor();
	ShowCur(false);
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++) {
		gotoxy(xDisplay[i] + 1, y_VeMT + 1);
		cout << key[i];
	}
	//hien thi cot hai ben
	SetColor(WHITE);
	for (int j = y_VeMT; j <= y_VeMT + 6; j++) {
		for (int i = 0; i < nKey + 1; i++) {
			gotoxy(xDisplay[i], j);
			cout << char(179);
		}
	}
	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++) {

		gotoxy(i, y_VeMT);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
			cout << char(194);//nga 3
		else if (i == xDisplay[0]) {
			cout << char(218); //moc phai
		} else if (i == xDisplay[nKey]) {
			cout << char(191);//moc trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_VeMT + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
			cout << char(197); //nga 4
		else if (i == xDisplay[0]) {
			cout << char(195); //nga 3 sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(180);//nga 3 sang trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_VeMT + 6);
		if (i == xDisplay[0]) {
			cout << char(192); //qeo sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(217); //qeo sang trai
		} else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
			cout << char(193);
		else {
			cout << char(196); //duong thang ngang
		}
	}
}

void ve_Top10(string key[], int nKey, int xDisplay[], int ndoc) {
	normalBGColor();
	ShowCur(false);
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++) {
		gotoxy(xDisplay[i] + 1, y_VeTop10 );
		cout << key[i];
	}

	//hien thi cot hai ben
	SetColor(WHITE);
	for (int j = y_VeTop10; j <= y_VeTop10 + ndoc; j++) {
		for (int i = 0; i < nKey + 1; i++) {
			gotoxy(xDisplay[i], j);
			cout << char(179);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++) {
		gotoxy(i, y_VeTop10 - 1);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(194);//nga 3
		else if (i == xDisplay[0]) {
			cout << char(218); //moc phai
		} else if (i == xDisplay[nKey]) {
			cout << char(191);//moc trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_VeTop10 + 1);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(197); //nga 4
		else if (i == xDisplay[0]) {
			cout << char(195); //nga 3 sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(180);//nga 3 sang trai
		} else {
			cout << char(196); //duong thang ngang
		}

		gotoxy(i, y_VeTop10 + ndoc);
		if (i == xDisplay[0]) {
			cout << char(192); //qeo sang phai
		} else if (i == xDisplay[nKey]) {
			cout << char(217); //qeo sang trai
		} else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(193);
		else {
			cout << char(196); //duong thang ngang
		}

	}
}

void ve_BangNhap(int x, int y, int nngang, string key[], int nkey) {
	int i;
	SetBGColor(BLACK);
	SetColor(WHITE);
	for (i = 0; i < nkey + 2; i++) {
		gotoxy(x, y + i);
		if (i == 0) {
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		} else if (i == nkey + 1) {
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		} else {
			cout << char(245);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(245);
		}
	}
	normalBGColor();
}

void ve_BangChiBao(int x, int y, int nngang, string key[], int nkey) {
	int i;
	SetBGColor(BLACK);
	SetColor(WHITE);
	for (i = 0; i < nkey + 2; i++) {
		gotoxy(x, y + i);
		if (i == 0) {
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		} else if (i == nkey + 1) {
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		} else {
			cout << char(245);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(245);
		}
	}
	normalBGColor();
}

