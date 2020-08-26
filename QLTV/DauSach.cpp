#include "DauSach.h"

int checkNull_DauSach(List_DauSach listDS) {
	return listDS.n == -1;
}

int checkFull_DauSach(List_DauSach listDS) {
	return listDS.n == MAX_LIST_DAUSACH;
}

int themDauSach(List_DauSach &listDS,  pDauSach &pDS) {
	if (checkFull_DauSach(listDS)) {
		return 0;
	}
	listDS.nodesDS[++listDS.n] = pDS;
	return 1;
}

void xoaDauSach_ViTri(List_DauSach &listDS, int viTri) {
	if (viTri > listDS.n  || checkNull_DauSach(listDS)  ||  checkFull_DauSach(listDS) || viTri < 0) {
		return;
	}
	// xoa vi tri cuoi mang
	if (viTri == listDS.n) {
		delete listDS.nodesDS[listDS.n];
		listDS.nodesDS[listDS.n--] = NULL; //*
		return;
	}
	// ***NOTE
	delete listDS.nodesDS[viTri];
	for (int temp = viTri + 1; temp <= listDS.n; temp++) {
		listDS.nodesDS[temp - 1] = listDS.nodesDS[temp];
	}
	delete listDS.nodesDS[listDS.n--];//*
	listDS.nodesDS[listDS.n--] = NULL;
	return;
}

bool isDauSach_ISBN(List_DauSach listDS, string ISBN) {
	for (int i = 0; i < listDS.n; i++) {
		if (listDS.nodesDS[i]->ISBN == ISBN)
			return true;
	}
	return false;
}

pDauSach layDauSach_Ten(List_DauSach listDS, string tenSach) {
	pDauSach temp = NULL;
	for (int i = 0; i <= listDS.n; i++) {
		temp = listDS.nodesDS[i];
		if (temp->tenSach == tenSach)
			return temp;
	}
	return NULL;
}

List_DauSach layDauSach_TheLoai(List_DauSach &listDS, string theLoai) {
	List_DauSach listDSTemp;
	listDSTemp.n = 0;
	for (int i = 0; i < listDS.n; i++) {
		if (listDS.nodesDS[i]->theLoai == theLoai) {
			listDSTemp.nodesDS[listDSTemp.n] = listDS.nodesDS[i];
			listDSTemp.n++;
		}
	}
	return listDSTemp;
}

string getString(string a) {
	for (int i = 0; i < (int)a.length(); i++) {
		if (a[i] == ' ') {
			a.erase(i, 1);
			i--;
		}
	}
	return a;
}

//Sap xep Dau Sach
void swap_DS(pDauSach ds1, pDauSach ds2) {
	DauSach temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}

int xetThuTu(pDauSach left , pDauSach right){
	string temp1 = getString(left->theLoai);
	string temp2 = getString(right->theLoai);
	if (temp1 != temp2)
		return temp1 < temp2;

	temp1 = getString(left->tenSach);
	temp2 = getString(right->tenSach);
	if (temp1 != temp2)
		return temp1 < temp2;

	return false;
}

//void quickSortMulti_(List_DauSach &listDS, int l, int r) {
//	pDauSach key = listDS.nodesDS[(l + r) / 2];
//		int i = l, j = r;
//		while (i <= j)
//		{
//			while (xetThuTu(listDS.nodesDS[i], key)) i++;       // tim phan tu ben trai ma >=key
//			while (xetThuTu(listDS.nodesDS[j], key)) j--;       // tim phan tu ben trai ma <=key
//			if (i <= j)
//			{
//				if (i < j)
//					swap_DS(listDS.nodesDS[j], listDS.nodesDS[i]);  // doi cho 2 phan tu kieu int a[i], a[j].
//				i++;
//				j--;
//			}
//		}
//		//bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
//		if (l < j) quickSortMulti_(listDS, l, j);   // lam lai voi mang a[l]....a[j]
//		if (i < r) quickSortMulti_(listDS, i, r); // lam lai voi mang a[i]....a[r]
//	}


void SSort_DauSach(List_DauSach &lDS) {
	int i, j, min_idx;
	for (i = 0; i <= lDS.n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j <= lDS.n; j++) {
			if (xetThuTu(lDS.nodesDS[j], lDS.nodesDS[min_idx]))
				min_idx = j;
		}
		swap_DS(lDS.nodesDS[min_idx], lDS.nodesDS[i]);
	}
}

void capNhat_DauSach(List_DauSach &lDS, pDauSach &pDS, bool isEdited) {
	dauSach info;
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	int nngang = (int)keyBangNhapDauSach[0].length();
	// cac flag 
	int tienTrinh = 0;
	bool isSave = false;
	bool isEscape = false;

	// temp
	string tensach = "";
	string ISBN = "";
	string tacgia = "";
	string theloai = "";
	int sotrang = 0;
	int namXB = 0;

	/*taoBox(x_Note + 7, y_Note, "Note:  ", 46);*/
	gotoxy(x_Note + 7, y_Note);
	cout << "Luu y: ";
	ve_BangNhap(82, y_Ve, nngang, keyBangNhapDauSach, 14);
	ve_BangChiBao(82, y_Ve + 20, nngang, keyGuide2, 7);
	
	if (isEdited) {
		tensach = pDS->tenSach;
		ISBN = pDS->ISBN;
		tacgia = pDS->tacGia;
		theloai = pDS->theLoai;
		sotrang = pDS->soTrang;
		namXB = pDS->namXB;

		gotoxy(80 + (nngang / 3), y_Ve + 3);
		cout << tensach;
		gotoxy(80 + (nngang / 3), y_Ve + 5);
		cout << ISBN;
		gotoxy(80 + (nngang / 3), y_Ve + 7);
		cout << tacgia;
		gotoxy(80 + (nngang / 3), y_Ve + 9);
		cout << theloai;
		gotoxy(80 + (nngang / 3), y_Ve + 11);
		cout << sotrang;
		gotoxy(80 + (nngang / 3), y_Ve + 13);
		cout << namXB;
	}
	while (true) {
		switch (tienTrinh) {
			case 0:
				gotoxy(83 + (nngang / 3), y_Ve + 3);
				NhapTenSach(tensach, tienTrinh, isSave, isEscape);
				break;
			case 1:
				gotoxy(83 + (nngang / 3), y_Ve + 5);
				NhapISBN(ISBN, tienTrinh, isSave, isEscape);
				break;
			case 2:
				gotoxy(83 + (nngang / 3), y_Ve + 7);
				NhapTenTacGia(tacgia, tienTrinh, isSave, isEscape);
				break;
			case 3:
				gotoxy(83 + (nngang / 3), y_Ve + 9);
				NhapTheLoaiSach(theloai, tienTrinh, isSave, isEscape);
				break;
			case 4:
				gotoxy(83 + (nngang / 3), y_Ve + 11);
				nhapSoTrang(sotrang, tienTrinh, isSave, isEscape);
				break;
			case 5:
				gotoxy(83 + (nngang / 3), y_Ve + 13);
				NhapNamXuatBan(namXB, tienTrinh, isSave, isEscape);
				break;
		}
		// check Save
		if (isSave) {
			// cap nhat lai flag
			isSave = false;
			if (tensach.length() == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "           Du lieu khong de trong ! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				tienTrinh = 0;
				continue;
			} else if (ISBN.length() == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "           Du lieu khong de trong ! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				tienTrinh = 1;
				continue;
			} else if (tacgia.length() == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "           Du lieu khong de trong ! ";
				normalBGColor();
				tienTrinh = 2;
				continue;
			} else if (theloai.length() == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "           Du lieu khong de trong ! ";
				normalBGColor();
				tienTrinh = 3;
				continue;
			} else if (sotrang == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "           Du lieu khong de trong ! ";
				normalBGColor();
				tienTrinh = 4;
				continue;
			} else if (namXB == 0) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "          Du lieu khong de trong !";
				normalBGColor();
				tienTrinh = 5;
				continue;
			} else if (namXB > (int)layNamHT()) {
				gotoxy(x_Note + 15, y_Note);
				SetColor(BLUE);
				cout << "Nam xuat ban khong dung !";
				normalBGColor();
				tienTrinh = 5;
				continue;
			}
			if (isDauSach_ISBN(lDS, ISBN)) {
				if (pDS->ISBN != ISBN) {
					gotoxy(x_Note + 15, y_Note);
					SetColor(BLUE);
					cout << "ISBN bi trung !";
					normalBGColor();
					tienTrinh = 1;
					continue;
				}
			}
			// import data vao info
			info.tenSach = ChuanHoaString(tensach);
			info.ISBN = ChuanHoaString(ISBN);
			info.tacGia = ChuanHoaString(tacgia);
			info.theLoai = ChuanHoaString(theloai);
			info.soTrang = sotrang;
			info.namXB = namXB;
			if (isEdited) {
				pDS->tenSach = info.tenSach;
				pDS->ISBN = info.ISBN;
				pDS->tacGia = info.tacGia;
				pDS->theLoai = info.theLoai;
				pDS->soTrang = info.soTrang;
				pDS->namXB = info.namXB;
				normalBGColor();
				return;
			} else {
				// khoi tao NULL
				initList_DMS(pDS->pListDMS);
				initList_DMS(pDS->pListDMS);
				//
				pDS->tenSach = info.tenSach;
				pDS->ISBN = info.ISBN;
				pDS->tacGia = info.tacGia;
				pDS->theLoai = info.theLoai;
				pDS->soTrang = info.soTrang;
				pDS->namXB = info.namXB;
				int temp = themDauSach(lDS, pDS);
				if (temp == 0) {
					// thong bao ra.
					for (int i = 0; i < 5; i++) {
						SetColor(BLUE);
						gotoxy(x_Note + 15, y_Note);
						cout << "Bo nho day, khong the them!";
					}
				} else {
					for (int i = 0; i < 5; i++) {
						SetColor(BLUE);
						gotoxy(x_Note + 15, y_Note);
						cout << "        Hoan tat !";
					}
				}
				normalBGColor();
				return;
			}
		}
		if (isEscape) {
			return;
		}
	}
	ShowCur(false);
}

int chonItems_DS(List_DauSach &lDS, int &thuTuTrang, int tongtrang) {
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_RED);
	gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
	cout << "<<";
	gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
	cout << ">>";
	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case KEY_UP:
					// xoa muc truoc
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "  ";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "  ";
					(pos > 0) ? pos-- : pos = 28;

					// to mau muc moi
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "<<";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << ">>";
					break;

				case KEY_DOWN:
					// xoa muc truoc
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "  ";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "  ";
					(pos < 28) ? pos++ : pos = 0;
					// to mau muc moi
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "<<";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << ">>";
					break;

				case PAGE_UP:
					if (thuTuTrang > 1) {
						thuTuTrang--;
					} else {
						thuTuTrang = tongtrang;
					}
					Xoa_DS_lineS();
					xuat_DStheoPage(lDS, thuTuTrang);
					pos = 0;
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "<<";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << ">>";
					break;

				case PAGE_DOWN:
					if (thuTuTrang <  tongtrang) {
						thuTuTrang++;
					} else {
						thuTuTrang = 1;
					}
					Xoa_DS_lineS();
					xuat_DStheoPage(lDS, thuTuTrang);
					pos = 0;
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "<<";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << ">>";
					break;
				case ENTER:
					return (pos == 0 && thuTuTrang == 1) ? pos : pos + (thuTuTrang - 1)* NUMBER_LINES;
			}
		}
		ShowCur(false);
		SetColor(WHITE);
		gotoxy(70, 1);
		cout << "Page: " << thuTuTrang << "/" << tongtrang;
		normalBGColor();
	}
}

void Xoa_DS_line(int locate) {
	gotoxy(x_DS[0] + 1, y_Ve + 3 + locate);
	cout << setw(27) << setfill(' ') << ' ';
	gotoxy(x_DS[1] + 1, y_Ve + 3 + locate);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(x_DS[2] + 1, y_Ve + 3 + locate);
	cout << setw(18) << setfill(' ') << ' ';
	gotoxy(x_DS[3] + 1, y_Ve + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(x_DS[4] + 1, y_Ve + 3 + locate);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(x_DS[5] + 1, y_Ve + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
}

void Xoa_DS_lineS() {
	for (int i = 0; i <NUMBER_LINES; i++) {
		Xoa_DS_line(i);
	}
}

void Output_DS(string tenSach, string ISBN, string tacGia, string theLoai, int soTrang, int namXB) {
	ShowCur(false);
	Xoa_DS_line(toaDo);
	gotoxy(x_DS[0] + 3, y_Ve + 3 + toaDo);
	cout << tenSach;
	gotoxy(x_DS[1] + 1, y_Ve + 3 + toaDo);
	cout << ISBN;
	gotoxy(x_DS[2] + 1, y_Ve + 3 + toaDo);
	cout << tacGia;
	gotoxy(x_DS[3] + 1, y_Ve + 3 + toaDo);
	cout << theLoai;
	gotoxy(x_DS[4] + 1, y_Ve + 3 + toaDo);
	cout << soTrang;
	gotoxy(x_DS[5] + 1, y_Ve + 3 + toaDo);
	cout << namXB;
	toaDo++;
}

void xuat_DStheoPage(List_DauSach &lDS, int index) {
	Xoa_DS_lineS();
	SetColor(WHITE);
	toaDo = 0;
	index--;
	if (lDS.n == -1)
		return;
	for (int i =  NUMBER_LINES * index;  i < NUMBER_LINES*( 1 + index)  && i <= lDS.n ; i++) {
		Output_DS(lDS.nodesDS[i]->tenSach, lDS.nodesDS[i]->ISBN, lDS.nodesDS[i]->tacGia, lDS.nodesDS[i]->theLoai, lDS.nodesDS[i]->soTrang, lDS.nodesDS[i]->namXB);
	}
}

void xuat_ListDStheoTT(List_DauSach lDS) {
	system("color 0");
	clrscr();
	normalBGColor();
	//quickSortMulti_(lDS,0, sl);
	SSort_DauSach(lDS);

	ve_DS(keyDisplayDS, 6, x_DS);
	normalBGColor();
	gotoxy(32, 1);
	cout << "Bang Thong Tin Dau Sach ";
	int nDS = lDS.n + 1;
	int thuTuTrang, tongtrang;
	thuTuTrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	xuat_DStheoPage(lDS, thuTuTrang);

	int check;
	pDauSach temp;
	string tensach = "";

	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case PAGE_UP:
					(thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
					xuat_DStheoPage(lDS, thuTuTrang);
					break;
				case PAGE_DOWN:
					(thuTuTrang <  tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
					xuat_DStheoPage(lDS, thuTuTrang);
					break;
				case KEY_F9:
					VeHinhBangNhap(82, 3,50, "         Nhap ten sach can tra cuu !");
					gotoxy(92, 5);
					check = NhapTenSachTimKiem(tensach);
					// kiem tra dieu kien tra ve .....
					if (check == -1) {
						gotoxy(92, 10);
						cout << "Ban vua huy tra cuu !";
						_getch();
						return;
					} else if (check == 1) {
						temp = layDauSach_Ten(lDS, tensach);
						if (temp == NULL) {
							gotoxy(86, 10);
							cout << "Ten sach khong co trong du lieu !";
							_getch();
							XoaMotVung(82, 1, 35, 50);
						} else {
							//SetBGColor(2);
							gotoxy(93, 8);
							cout << "Thong tin tra cuu !";
							gotoxy(82, 11);
							cout << "Ten sach: " << temp->tenSach;
							gotoxy(82, 13);
							cout << "Tac gia: " << temp->tacGia;
							gotoxy(82, 15);
							cout << "The loai: " << temp->theLoai;
							gotoxy(82, 17);
							cout << "Nam xuat ban: " << temp->namXB;
							gotoxy(82, 19);
							cout << "ISBN: " << temp->ISBN;
							gotoxy(82 ,21);
							cout << "Tong so sach cung dau sach: " << temp->pListDMS.n;
							gotoxy(82, 23);
							cout << "So sach con lai trong thu vien:  " << temp->pListDMS.n - TongSoSachDuocMuon(temp->pListDMS);
							gotoxy(82, 25);
							cout << "Cac ma sach con la: ";
							// thuc hien in ma sach ra theo dung format.
							int i = 0, j = 0, count = 0;
							for (Node_DMS* p = temp->pListDMS.headLDMS; p != NULL; p = p->nextNDMS) {
								gotoxy(82 + i, 26 + j);
								if (p->info.trangThaiSach == 0) {
									cout << p->info.maSach;
									i += 10;
									count++;
									if (count == 5) {
										j++;
										i = 0;
										count = 0;
									}
								}
							}
							_getch();
							XoaMotVung(82, 1, 35, 50);
						}
					}
					break;
				case ESC:
					return ;
			}
		}
		ShowCur(false);
		gotoxy(2, 35);
		SetColor(WHITE);
		cout << "    PgUp, PgDn, ESC,      F9  -  Tim thong tin sach ";
		gotoxy(72, 1);
		cout << "Page: " << thuTuTrang << "/" << tongtrang;
	} while (true);
}

void Menu_DauSach(List_DauSach &lDS) {
	system("color 0");
	clrscr();
	gotoxy(32, 1);
	cout << "Cap Nhat Dau Sach ";
	// nDG la so DG hien co trong danh sach tuyen tinh
	int nDS = lDS.n + 1;
	int choose;
	pDauSach pDS;
	gotoxy(3, y_HKey);
	SetColor(WHITE);
	cout << "     ESC - Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	normalBGColor();
	// thu tu trang
	int thuTuTrang, tongtrang;
	thuTuTrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
label1:
	XoaMotVung(79, y_Ve, 30, 53);
	ve_DS(keyDisplayDS, 6, x_DS);
	xuat_DStheoPage(lDS, thuTuTrang);
	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case PAGE_UP:
					(thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
					xuat_DStheoPage(lDS, thuTuTrang);
					break;
				case PAGE_DOWN:
					(thuTuTrang <  tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
					xuat_DStheoPage(lDS, thuTuTrang);
					break;
				case KEY_F2:
					pDS = new dauSach;
					if (pDS == NULL)
						goto label1;
					capNhat_DauSach(lDS, pDS, false);
					goto label1 ;
				case  KEY_F3:
					choose = chonItems_DS(lDS, thuTuTrang, tongtrang);
					if (choose > lDS.n)
						goto label1;
					capNhat_DauSach(lDS, lDS.nodesDS[choose], true);
					goto label1;
				case KEY_F4:
					choose = chonItems_DS(lDS, thuTuTrang, tongtrang);
					if (choose > lDS.n)
						goto label1;
					// neu co nguoi muon thi se khong duoc phep xoa .
					if (Check_DMS(lDS.nodesDS[choose]->pListDMS.headLDMS)) {
						gotoxy(79,20);
						cout << " Dau Sach da co Doc Gia muon nen khong duoc phep xoa !";
						_getch();
						gotoxy(79, 20);
						cout << "                                                      ";
						goto label1;
					}
					xoaDauSach_ViTri(lDS, choose);
					goto label1;
					// thoat
				case ESC:
					return ;
			}
		}
		SetColor(WHITE);
		ShowCur(false);
		gotoxy(70, 1);
		cout << "Page: " << thuTuTrang << "/" << tongtrang;
	} while (true);
}



