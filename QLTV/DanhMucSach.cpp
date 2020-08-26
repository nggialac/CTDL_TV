#include "DanhMucSach.h"

void initList_DMS(ListDMS& ldms) {
	ldms.n = 0;
	ldms.headLDMS = ldms.tailLDMS = NULL;
}

bool ListDMSIsEmpty(ListDMS ldms) {
	return ldms.headLDMS == NULL;
}

Node_DMS* getNode_DMS(DMS data) {
	Node_DMS *p = new Node_DMS;
	if(p == NULL) {
		return NULL;
	}
	p-> info = data;
	p-> nextNDMS = NULL;
	return (p);
}

void addTailList_DMS(ListDMS &ldms, DMS data) {
	Node_DMS *p = getNode_DMS(data);
	if (ldms.headLDMS == NULL) {
		ldms.headLDMS = ldms.tailLDMS = p;
	} else {
		ldms.tailLDMS->nextNDMS = p;
		ldms.tailLDMS = p;
	}
	ldms.n++;
}

int layViTri_Key(Node_DMS *first, string key) {
	int viTri;
	Node_DMS *q;
	q = first;
	viTri = 1;
	if (q == NULL)
		return(-1);
	while (q != NULL && q->info.maSach != key) {
		q = q->nextNDMS;
		viTri++;
	}
	return(viTri);
}

Node_DMS *nodePointer(Node_DMS *first, int i) {
	Node_DMS *p;
	int viTri = 1;
	p = first;
	while (p != NULL && viTri < i) {
		p = p->nextNDMS;
		viTri++;
	}
	return(p);
}

void xoaFirst(Node_DMS *&first) {
	Node_DMS *p;
	if (first == NULL)
		return;
	else {
		p = first;    // nut can xoa la nut dau
		first = first->nextNDMS;
		delete p;
	}
}

void xoaAfter(Node_DMS *p) {
	Node_DMS *q;
	q = p-> nextNDMS;  // q chi nut can xoa
	p->nextNDMS = q-> nextNDMS;
	delete q;
}

int xoa_Key(pDauSach &pDS, string key) {
	int viTri;
	viTri = layViTri_Key(pDS->pListDMS.headLDMS, key);
	if (viTri > pDS->pListDMS.n   || viTri == -1) {
		return  -1;
	}
	// truong hop xoa dau
	else if (viTri == 1) {
		xoaFirst(pDS->pListDMS.headLDMS );
		pDS->pListDMS.n--;
		return 1;
	} else {
		//p chi toi nut truoc nut can xoa
		Node_DMS  *p = nodePointer(pDS->pListDMS.headLDMS , viTri - 1);
		xoaAfter(p);

		// truong hop xoa duoi, thi phai cap nhat lai pTail*
		if (viTri == pDS->pListDMS.n) {
			pDS->pListDMS.tailLDMS = p;
		}
		pDS->pListDMS.n--;
		return 1;
	}
}

bool Check_DMS(Node_DMS* nDMS) {
	for (Node_DMS* p = nDMS; p != NULL; p = p->nextNDMS) {
		// sach da co nguoi muon.
		if (p->info.trangThaiSach == 1) {
			return true;
		}
	}
	return false;
}

Node_DMS* Search_DMS1(pDauSach pDS, string masach) {
	Node_DMS* p;
	p = pDS->pListDMS.headLDMS;
	while (p != NULL && p->info.maSach != masach)
		p = p->nextNDMS;
	return (p);
}

Node_DMS* Search_DMS2(Node_DMS* dms, int pos) {
	int count = -1;
	for (Node_DMS* temp = dms; temp != NULL; temp = temp->nextNDMS) {
		count++;
		if (pos == count) {
			return temp;
		}
	}
	return NULL;
}

int NhapSach(pDauSach &pDS) {
	DMSach info;
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();
	int nngang = (int)keyBangNhapDanhMucSach[0].length();
	//taoBox(40, y_Note + 2, "Luu Y:  ", 66);
	gotoxy(38, y_Note + 2);
	cout << "Luu y: ";
	ve_BangNhap(38, y_Ve + 2, nngang, keyBangNhapDanhMucSach, 8);
	//ve_BangChiBao(38, y_Ve + 22, nngang, keyGuide3, 4);
	gotoxy(40, y_Ve + 22);
	cout << "                         NOTE                             " << endl;
	cout << "                                      MA SACH  :  Danh tu dong                           " << endl;
	cout << "                                      TT       :0  = cho muon duoc, 1 = da duoc muon, 2 = da thanh ly" << endl;
	cout << "                                      VI TRI   : Toi da 17 ky tu (so, chu va ',')   ";

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;
	// Temp
	int stt = pDS->pListDMS.n;
	string maSach = pDS->ISBN + to_string(++stt); //int->char
	//kt trung, tang stt
	while (Search_DMS1(pDS, maSach) != NULL) {
		stt++;
		maSach = pDS->ISBN + to_string(stt);
	}
	int ttSach = 3;
	string viTri = "";
	gotoxy(40 + (nngang / 3), y_Ve + 5);
	cout << maSach;
	while (true) {
		switch (ordinal) {
			case 1:
				NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, 40 + (nngang / 3), y_Ve + 7);
				break;
			case 2:
				NhapViTri(viTri, ordinal, isSave, isEscape, 40 + (nngang / 3), y_Ve + 9);
				break;
		}
		if (isSave) {
			isSave = false;
			// check rong;
			if (ttSach == 3) {
				gotoxy(55, y_Note + 2);
				SetColor(BLUE);
				cout << "Cac truong du lieu khong de trong ! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			if (viTri.length() == 0) {
				gotoxy(55, y_Note + 2);
				SetColor(BLUE);
				cout << "Cac truong du lieu khong de trong ! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			// import data vao info
			info.maSach = maSach;
			info.trangThaiSach = ttSach;
			info.viTri = viTri;
			addTailList_DMS(pDS->pListDMS, info);
			return 0;
		}
		if (isEscape) {
			return -1;
		}
	}
}

int SuaDanhMucSach(pDauSach &pDS, Node_DMS* dms) {
	DMS info;
	// kiem tra dieu kien.
	if (dms->info.trangThaiSach == 1)
		return 2;
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();
	int nngang = (int)keyBangNhapDanhMucSach[0].length();
	taoBox(67, y_Note + 2, "Luu Y:  ", 66);
	ve_BangNhap(65, y_Ve + 6, nngang, keyBangNhapDanhMucSach, 8);
	ve_BangChiBao(65, y_Ve + 22, nngang, keyGuide3, 4);
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;
	string maSach = dms->info.maSach;
	int ttSach = dms->info.trangThaiSach ;
	string viTri = dms->info.viTri;
	gotoxy(67 + (nngang / 3), y_Ve + 9);
	cout << maSach;
	gotoxy(89, y_Ve + 11);
	if (ttSach == 0)
		cout << ttSach << ":   Co the muon  ";
	else if (ttSach == 1)
		cout << ttSach << ":   Da duoc muon   ";
	else if (ttSach == 2)
		cout << ttSach << ":   Da thanh ly    ";
	gotoxy(89, y_Ve + 13);
	cout << viTri;
	while (true) {
		switch (ordinal) {
			case 1:
				NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, 89,  y_Ve + 11);
				break;
			case 2:
				NhapViTri(viTri, ordinal, isSave, isEscape, 89, y_Ve + 13);
				break;
		}
		if (isSave) {
			isSave = false;
			// check rong;
			if (ttSach == 3) {
				gotoxy(67, y_Note + 2);
				SetColor(BLUE);
				cout << "          Du lieu khong duoc de trong ! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			if (viTri.length() == 0) {
				gotoxy(67, y_Note + 2);
				SetColor(BLUE);
				cout << "          Du lieu khong duoc de trong ! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			// import data vao info
			info.maSach = maSach;
			info.trangThaiSach = ttSach;
			info.viTri = viTri;
			dms->info = info;
			return 1;
		}
		if (isEscape) {
			return -1;
		}
	}
}

void Xoa_OutDMS_1line(int locate) {
	gotoxy(x_DMS[0] + 1, y_Ve + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(x_DMS[1] + 1, y_Ve + 3 + locate);
	cout << setw(13) << setfill(' ') << ' ';
	gotoxy(x_DMS[2] + 1, y_Ve + 3 + locate);
	cout << setw(34) << setfill(' ') << ' ';
}

void Xoa_OutDMS_29lines() {
	for (int i = 0; i <NUMBER_LINES; i++) {
		Xoa_OutDMS_1line(i);
	}
}

int ChooseItems(List_DauSach &lDS, int &tttrang, int tongtrang) {
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_RED);
	gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
	cout << "->";
	gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
	cout << "";
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
					SetColor(LIGHT_RED);
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "->";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "";
					break;
				case KEY_DOWN:
					// xoa muc truoc
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "  ";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "  ";
					(pos < 28) ? pos++ : pos = 0;
					// to mau muc moi
					SetColor(LIGHT_RED);
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "->";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "";
					break;
				case PAGE_UP:
					if (tttrang > 1) {
						tttrang--;
					} else {
						tttrang = tongtrang;
					}
					xuat_DStheoPage(lDS, tttrang);
					// hight light dong dau.
					pos = 0;
					SetColor(LIGHT_RED);
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "->";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "";
					break;
				case PAGE_DOWN:
					if (tttrang <  tongtrang) {
						tttrang++;
					} else {
						tttrang = 1;

					}
					xuat_DStheoPage(lDS, tttrang);
					// high light dong dau.
					pos = 0;
					SetColor(LIGHT_RED);
					gotoxy(x_DS[0] + 1, y_Ve + 3 + pos);
					cout << "->";
					gotoxy(x_DS[0] + 26, y_Ve + 3 + pos);
					cout << "";
					break;
				case ENTER:
					return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;

				case ESC:
					return -1;
			}
		}
		ShowCur(false);
		gotoxy(62, 1);
		SetColor(WHITE);
		cout << "Page: " << tttrang << "/" << tongtrang;
	}

}

int ChooseItems1(pDauSach &pDS, int &tttrang, int tongtrang) {
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_RED);
	gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
	cout << "";
	gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
	cout << "->";

	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case KEY_UP:
					// xoa muc truoc
					gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
					cout << "  ";
					gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
					cout << "  ";
					(pos > 0) ? pos-- : pos = 28;
					// to mau muc moi
					SetColor(LIGHT_RED);
					gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
					cout << "";
					gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
					cout << "->";
					break;

				case KEY_DOWN:
					// xoa muc truoc
					gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
					cout << "  ";
					gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
					cout << "  ";
					(pos < 28) ? pos++ : pos = 0;

					// to mau muc moi
					SetColor(LIGHT_RED);
					gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
					cout << "";
					gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
					cout << "->";
					break;

				case PAGE_UP:
					if (tttrang > 1) {
						tttrang--;
					} else {
						tttrang = tongtrang;
					}
					Xoa_OutDMS_29lines();
					OutputDMS_PerPage(pDS, tttrang);

					pos = 0;
					SetColor(LIGHT_RED);
					gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
					cout << "";
					gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
					cout << "->";
					break;

				case PAGE_DOWN:
					if (tttrang <  tongtrang) {
						tttrang++;
					} else {
						tttrang = 1;
					}
					Xoa_OutDMS_29lines();
					OutputDMS_PerPage(pDS, tttrang);
					pos = 0;
					SetColor(LIGHT_RED);
					gotoxy(x_DMS[0] + 1, y_Ve + 3 + pos);
					cout << "";
					gotoxy(x_DMS[0] + 10, y_Ve + 3 + pos);
					cout << "->";
					break;

				case ENTER:
					return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;

				case ESC:
					return -1;
			}
		}
		ShowCur(false);
		gotoxy(62, 1);
		SetColor(WHITE);
		cout << "Page: " << tttrang << "/" << tongtrang;
	}
}

void Output_DMS(DMS dms) {
	Xoa_OutDMS_1line(toaDo);
	gotoxy(x_DMS[0] + 3, y_Ve + 3 + toaDo);
	cout << dms.maSach;
	gotoxy(x_DMS[1] + 1, y_Ve + 3 + toaDo);
	if (dms.trangThaiSach == 0) {
		cout << "Cho Muon Duoc";
	} else if (dms.trangThaiSach == 1) {
		cout << "Da Cho Muon";
	} else if (dms.trangThaiSach == 2) {
		cout << "Da Thanh Ly";
	}
	gotoxy(x_DMS[2] + 10, y_Ve + 3 + toaDo);
	cout << dms.viTri;
	toaDo++;
}

void OutputDMS_PerPage(pDauSach pDS, int index) {
	Xoa_OutDMS_29lines();
	toaDo = 0;
	if (pDS->pListDMS.headLDMS == NULL && pDS->pListDMS.tailLDMS == NULL)
		return;
	index--;
	index *= NUMBER_LINES;
	int count = 0;
	Node_DMS * temp = NULL;
	for ( temp = pDS->pListDMS.headLDMS ; temp != NULL  && count < index ; temp = temp->nextNDMS) {
		count++;
	}
	for (int i = 0; i < NUMBER_LINES && temp != NULL; i++) {
		Output_DMS(temp->info);
		temp = temp->nextNDMS;
	}
	return;
}

void Output_ListDMS(pDauSach &pDS) {
	clrscr();
	int check1;
	int check2;
	int check3;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = ((pDS->pListDMS.n + 1 ) / NUMBER_LINES) + 1;
	Node_DMS* temp = NULL, *temp1 = NULL;
	gotoxy(8, 1);
	cout << " Bang Danh Muc Sach " << pDS->tenSach;
label:
	ve_DMS(keyDisplayDMS, 3, x_DMS);
	OutputDMS_PerPage(pDS, tttrang);
	string keySearch = "";
	int kb_hit;
	do {
		XoaMotVung(65,2,  30, 67);
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case PAGE_UP:
					(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
					OutputDMS_PerPage(pDS, tttrang);
					break;
				case PAGE_DOWN:
					(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
					OutputDMS_PerPage(pDS, tttrang);
					break;
				case  KEY_F3:
					VeHinhBangNhap(82, 3, 38, "       Ma sach can sua !");
					gotoxy(96, 5);
					check1 = NhapMaDauSach(keySearch);
					// kiem tra dieu kien tra ve .....
					if (check1 == -1) {
						gotoxy(84, y_Note + 12);
						cout << "Da huy tac vu!";
						_getch();
					} else if (check1 == 1) {
						temp = Search_DMS1(pDS, keySearch);
						if (temp == NULL) {
							gotoxy(77, y_Note + 12);
							cout << "Ma sach " << "'" << keySearch << "'" << " khong co trong du lieu";
							_getch();
						} else {
							check3 = SuaDanhMucSach(pDS, temp);
							// kiem tra cac truong hop.
							if (check3 == 1) {
								gotoxy(73, y_Note + 12);
								cout << "Ban vua sua thong tin sach co ma la: " << keySearch;
								_getch();
							} else if (check3 == 2) {
								gotoxy(73, y_Note + 12);
								cout << "Sach da co Doc Gia muon nen khong duoc phep hieu chinh !";
								_getch();
								gotoxy(73, y_Note + 12);
								cout << "                                                        ";
							} else {
								gotoxy(82, y_Note + 12);
								cout << "Da huy chinh sua !";
								_getch();
							}
						}
					}
					goto label;
				case KEY_F4:
					VeHinhBangNhap(82, 3, 35,  "     Nhap Ma De Xoa   ");
					gotoxy(96, 5);
					check1 = NhapMaDauSach(keySearch);
					// kiem tra dieu kien tra ve .....
					if (check1 == -1) {
						gotoxy(88, 10);
						cout << "Da huy tac vu xoa !";
						_getch();
					} else if (check1 == 1) {
						temp1 = Search_DMS1(pDS, keySearch);
						// da co doc gia muon.
						if (temp1->info.trangThaiSach == 1) {
							gotoxy(78, 20);
							cout << "Sach da co Doc Gia muon nen khong duoc phep xoa !";
							_getch();
							gotoxy(78, 20);
							cout << "                                                      ";
						} else {
							check2 = xoa_Key(pDS, keySearch);
							if (check2 == -1) {
								gotoxy(75, 10);
								cout << "Ma sach " << "'" << keySearch << "'" << " khong co trong du lieu";
								_getch();
							} else if (check2 == 1) {
								gotoxy(82, 10);
								cout << "Da xoa sach co ma la: " << keySearch;
								_getch();
							}
						}
					}
					goto label;
				case ESC:
					return;
			}
		}
		ShowCur(false);
		gotoxy(3, 35);
		cout << "HotKey:  F3 - Hieu chinh , F4 - Xoa , ESC - Thoat";
		gotoxy(110, 1);
		cout << "Page: " << tttrang << " / " << tongtrang;
	} while (true);
}

void NhapDanhMucSach(pDauSach &pDS, int sosach) {
	clrscr();
	system("color 0");;
	int check1 = 0 ;
	gotoxy(39, 2);
	cout << "Nhap Thong Tin Vao Danh Muc Sach Cua Dau Sach : " << pDS->tenSach;
	gotoxy(60, 16);
	cout << "So sach can nhap: " << sosach << endl;
	gotoxy(52, 31);
	cout << " HotKey:   F10 - Luu ,  ESC - Thoat ";
	// nhap sach theo so sach da cho truoc
	for (int i = 0; i < sosach && check1 != -1; i++) {
		// nhap sach
		check1 = NhapSach(pDS);
		XoaMotVung(38, y_Ve + 2, 10, (int)keyBangNhapDanhMucSach[0].length());
		gotoxy(60, 18);
		cout << "So sach da nhap : " << i + 1;
	}
	Output_ListDMS(pDS);
}

void Menu_DMS(List_DauSach &lDS) {
	system("color 0");
	int choose;
	int nDS = lDS.n + 1;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;
	do {
		clrscr();
		// hien thi bang chua thong tin dau sach
		ve_DS(keyDisplayDS, 6, x_DS);
		xuat_DStheoPage(lDS, tttrang);
		gotoxy(23, 1);
		cout << "Chon dau sach de cap nhat DMS !";
		normalBGColor();
		// chon dau sach muon nhap sach vao
		choose = ChooseItems(lDS, tttrang, tongtrang);
		// check cac truong hop ...
		if (choose == -1) {
			return ;
		} else if (choose > lDS.n) {
			// xem thử chỗ đầu sách có quay lại ngay cái trang hầu nảy luôn kko
			gotoxy( 2 , y_Ve + 3 + choose % NUMBER_LINES);
			cout << setw(27) << setfill(' ') << ' ';
			continue;
		}
		if (lDS.nodesDS[choose]->pListDMS.headLDMS != NULL   && lDS.nodesDS[choose]->pListDMS.n == - 1) {
			continue;
		}
		// chon so sach nhap
		int sosach = ChonSoSachNhap();
		if (sosach == -1) {
			XoaMotVung(81, 3, 20, 50);
			continue ;
		} else {
			// bat dau nhap thong tin sach
			NhapDanhMucSach(lDS.nodesDS[choose], sosach);
		}
	} while (true);
}

int TongSoSachDuocMuon(ListDMS dms) {
	int dem = 0;
	Node_DMS *temp = NULL;
	for (temp = dms.headLDMS; temp != NULL; temp = temp->nextNDMS) {
		//  tinh ca sach da muon va da muon nhung lam mat.
		if (temp->info.trangThaiSach == 1   ||  temp->info.trangThaiSach == 2) {
			dem++;
		}
	}
	return dem;
}

void swap_DS_Top(pDauSach ds1, pDauSach ds2) {
	DauSach temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}

void sortTop(List_DauSach &listDS, int left, int right) {
	dauSach key = *(listDS.nodesDS[(left + right) / 2]);
	dauSach tempDS;
	int i = left, j = right;
	do {
		while (listDS.nodesDS[i]->soLanMuon > key.soLanMuon)
			i++;
		while (listDS.nodesDS[j]->soLanMuon < key.soLanMuon)
			j--;
		if (i <= j) {
			if (i < j) {
				swap_DS_Top(listDS.nodesDS[i], listDS.nodesDS[j]);
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) sortTop(listDS, left, j);
	if (right > i) sortTop(listDS, i, right);
}

void Sort_Top10(List_DauSach lDS, int q, int r) {
	pDauSach temp;
	int i = q;
	int j = r;
	//Lấy phần tử giữa của dãy cần sắp thứ tự làm chốt
	int x = lDS.nodesDS[(q + r) / 2]->soLanMuon;
	do {
		// Phân đoạn dãy con a[q],..., a[r]
		while (lDS.nodesDS[(q + r) / 2]->soLanMuon > x)
			i++; //Tìm phần tử đầu tiên có trị nhỏ hơn hay bằng x
		while (lDS.nodesDS[(q + r) / 2]->soLanMuon < x)
			j--; //Tìm phần tử đầu tiên có trị lớn hơn hay bằng x
		if (i <= j) { // Hoan vi
			temp = lDS.nodesDS[i];
			lDS.nodesDS[i] = lDS.nodesDS[j];
			lDS.nodesDS[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (q < j) 	// phần thứ nhất có từ 2 phần tử trở lên
		Sort_Top10(lDS, q, j);
	if (i < r)   	// phần thứ ba có từ 2 phần tử trở lên
		Sort_Top10(lDS, i, r);
}

void Top10Sach(List_DauSach lDS) {
	system("color 0");
	clrscr();
	int count = 0;
	sortTop(lDS, 0, lDS.n);
	// in thong tin ra  console
	gotoxy(50, 2);
	cout << "10 Dau Sach Duoc Muon Nhieu Nhat !";
	normalBGColor();
	int j = 0;
	while (j < 10) {
		SetColor(WHITE);
		gotoxy(x_Top10[1] + 3, y_VeTop10 + 2 + j);
		cout << lDS.nodesDS[j]->tenSach;
		gotoxy(x_Top10[2] + 16, y_VeTop10 + 2 + j);
		cout << lDS.nodesDS[j]->soLanMuon;
		gotoxy(x_Top10[0] + 7, y_VeTop10 + 2 + j);
		j++;
		cout << j;
	}
	ve_Top10(keyDisplayTop10, 3, x_Top10, j + 2);
	_getch();
}
