#include "XuLySL_MT.h"


void Introduce() {
	system("color 0");
	ShowCur(false);
	setFontSize(16);
	string a;
	ifstream inFile("Welcome.txt", ios:: in );
	if (inFile.good()) { 
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(LIGHT_AQUA);;
			cout << a << endl;
		}
	} else {
		cout << "Lien ket voi File WC khong thanh cong! " << "\n";
	}
	SetColor(WHITE);
	ShowCur(false);
	SetBGColor(BLACK);
	cin.ignore();
	return;
}

void ManHinhChinh() {
	system("color 0");
	clrscr();
	normalTextColor();
	ShowCur(false);
	normalBGColor();
	setFontSize(16);
	MainMenu(keyMainMenu, 5);
	normalBGColor();
	string text;
	int y = 0;
	ifstream inFile("TV.txt", ios:: in );
	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, text);
			SetColor(11);
			Sleep(15);
			gotoxy(25, y++);
			cout << text << endl;
		}
	}
	else {
		cout << "ERROR! File QLTV not found!" << "\n";
	}
	normalBGColor();
	SetBGColor(BLACK);
	return;
}

void Save_DS(List_DauSach listDS) {
	fstream outFile;
	outFile.open("DauSach1.txt", ios::out);
	if (outFile.is_open()) {
		outFile << listDS.n + 1 << endl;
		for (int i = 0; i <= listDS.n; i++) {
			outFile << listDS.nodesDS[i] -> tenSach << endl;
			outFile << listDS.nodesDS[i] -> ISBN << endl;
			outFile << listDS.nodesDS[i] -> tacGia << endl;
			outFile << listDS.nodesDS[i] -> theLoai << endl;
			outFile << listDS.nodesDS[i] -> soTrang << endl;
			outFile << listDS.nodesDS[i] -> namXB << endl;
			outFile << listDS.nodesDS[i]->soLanMuon << endl;
			outFile << listDS.nodesDS[i]->pListDMS.n << endl;
			for (Node_DMS * p = listDS.nodesDS[i] -> pListDMS.headLDMS; p != NULL; p = p -> nextNDMS) {
				outFile << p -> info.maSach << endl;
				outFile << p -> info.trangThaiSach << endl;
				outFile << p -> info.viTri << endl;
			}
		}
	} else {
		cout << "ERROR! File DauSach not found!";
	}
	outFile.close();
}

void Load_DS(List_DauSach & listDS) {
	fstream inFile;
	dauSach info;
	inFile.open("DauSach1.txt", ios:: in );
	pDauSach pDS;
	DMSach dms;
	int soDauSach, soSach;
	if (inFile.is_open()) {
		string temp;
		inFile >> soDauSach;
		getline(inFile, temp);
		for (int i = 0; i < soDauSach; i++) {
			pDS = new dauSach;
			if (pDS == NULL) continue;
			// load thong tin vao bien tam.
			getline(inFile, info.tenSach);
			getline(inFile, info.ISBN); //DOC KIEU STRING, CHAR bi loi
			getline(inFile, info.tacGia);
			getline(inFile, info.theLoai);
			inFile >> info.soTrang;
			inFile >> info.namXB;
			inFile >> info.soLanMuon;
			// load thong tin vao dau sach
			*(pDS) = info;
			inFile >> soSach;
			getline(inFile, temp);
			initList_DMS(pDS->pListDMS);
			for (int j = 0; j < soSach; j++) {
				getline(inFile, dms.maSach);
				inFile >> dms.trangThaiSach;
				getline(inFile, temp);
				getline(inFile, dms.viTri);
				themCuoiList_DMS(pDS->pListDMS, dms);
			}
			themDauSach(listDS, pDS);
		}
	} else {
		cout << "file DocGia khong tim thay! ";
	}
	inFile.close();
}

void Save(TreeTDG t, fstream &file) {
	file << t->info.maThe << endl;
	file << t->info.ho << endl;
	file << t->info.ten << endl;
	file << t->info.phai << endl;
	file << t->info.trangThaiThe << endl;
	file << t->listMT.n << endl;
	for (NodeMT* p = t->listMT.headLMT ; p != NULL; p = p->rightNMT ) {
		file << p->info.maSach << endl;

		file << p->info.ngayMuon.ngay << endl;
		file << p->info.ngayMuon.thang << endl;
		file << p->info.ngayMuon.nam << endl;

		file << p->info.ngayTra.ngay << endl;
		file << p->info.ngayTra.thang << endl;
		file << p->info.ngayTra.nam << endl;

		file << p->info.tenSach << endl;
		file << p->info.trangThai << endl;
		file << p->info.viTriSach << endl;
	}
}

void OutFile_DG(TreeTDG t, fstream &file) {
	if (t != NULL) {
		Save(t, file);
		OutFile_DG(t->leftTDG, file);
		OutFile_DG(t->rightTDG, file);
	}
}

void Save_DG(TreeTDG t) {
	fstream outFile;
	outFile.open("DocGia1.txt", ios::out);
	if (outFile.is_open()) {
		// so doc gia..
		outFile << demDG(t) << endl;
		OutFile_DG(t, outFile);
	} else {
		cout << " FILE DocGia error! ";
	}
	outFile.close();
}

void Load_DG(TreeTDG &t) {
	// khoi tao cay doc gia
	khoiTaoCayDG(t);
	fstream inFile;
	NodeTDG* pDG = NULL;
	TDG dg;
	MT mt;
	inFile.open("DocGia1.txt", ios::in);
	int sodocgia, sosachmuontra;
	if (inFile.is_open()) {
		string temp;
		inFile >> sodocgia;
		for (int i = 0 ; i < sodocgia; i++) {
			inFile >> dg.maThe;
			getline(inFile, temp);
			getline(inFile, dg.ho);
			getline(inFile, dg.ten);
			inFile >> dg.phai;
			inFile >> dg.trangThaiThe;
			// them data vao cay doc gia.
			chenTree(t, dg);
			pDG = layDG_NTDG(t, dg.maThe);
			inFile >> sosachmuontra;
			getline(inFile, temp);
			for (int j = 0; j <  sosachmuontra; j++) {
				getline(inFile, mt.maSach);
				inFile >> mt.ngayMuon.ngay;
				inFile >> mt.ngayMuon.thang;
				inFile >> mt.ngayMuon.nam;
				inFile >> mt.ngayTra.ngay;
				inFile >> mt.ngayTra.thang;
				inFile >> mt.ngayTra.nam;

				getline(inFile, temp);
				getline(inFile, mt.tenSach);
				inFile >> mt.trangThai;
				getline(inFile, temp);
				getline(inFile, mt.viTriSach);

				// cap nhat du lieu vao
				themDauList_MT(pDG->listMT, mt);
			}
		}
	} else {
		cout << "file DocGia khong tim thay! ";
	}
	inFile.close();
}

int Menu_MS(List_DauSach &lDS, NodeTDG* nDG) {
	int choose1, choose2;
	bool check;
	char thongbao1[] = "  Sach da co doc gia muon !";
	char thongbao2[] = "  Sach da duoc thanh ly !";
	char thongbao3[] = "  Doc gia da muon sach thuoc Dau Sach nay!";
	normalBGColor();

	// nDs : so luong dau sach.
	int nDS = lDS.n + 1;
	int thuTuTrang, tongtrang;
	pDauSach pDS = NULL;
	thuTuTrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;

label:
	do {
		// hien thi bang chua thong tin dau sach
		XoaMotVung(1, 1, 65, 80);
		ve_DS(keyDisplayDS, 6, x_DS);
		xuat_DStheoTrang(lDS, thuTuTrang);
		gotoxy(23, 1);
		cout << "Chon dau sach de muon ! ";
		normalBGColor();
		// chon dau sach muon nhap sach vao
		choose1 = ChonItems(lDS, thuTuTrang, tongtrang);
		// check cac truong hop ...
		if (choose1 == -1) {
			return -1;
		} else if (choose1 > lDS.n) {
			gotoxy(2, y_Ve + 3 + choose1 % NUMBER_LINES);
			cout << setw(27) << setfill(' ') << ' ';
			continue;
		}
		pDS = lDS.nodesDS[choose1];
		// lay ten sach.
		tensach = pDS->tenSach;
		check = timTenSach_MT(nDG->listMT, tensach);
		// check cac truong hop
		if (check == true) {
			gotoxy(90, 24);
			cout << thongbao3;
			_getch();
			gotoxy(90, 24);
			cout << "                                                       ";
		} else {
			XoaMotVung(1, 1, 35, 79);
			temp = 2;
		}
	} while (temp == 1);

label1:
	temp = 1;
	thuTuTrang = 1;
	tongtrang = (pDS->pListDMS.n / NUMBER_LINES) + 1;
	gotoxy(15, 1);
	cout << "Chon Sach De Muon !";
	normalBGColor();
	do {
		// hien thi bang chua thong tin danh muc sach
		ve_DMS(keyDisplayDMS, 3, x_DMS);
		xuat_DMS_trang(pDS, thuTuTrang);
		choose2 = chonItems1(pDS, thuTuTrang, tongtrang);
		if (choose2 == -1) {
			temp = 1;
			thuTuTrang = 1;
			gotoxy(15, 1);
			cout << "                                       ";
			goto label;
		} else if (choose2 + 1 > pDS->pListDMS.n) {
			gotoxy(2, y_Ve + 3 + choose2 % NUMBER_LINES);
			cout << setw(12) << setfill(' ') << ' ';
			continue;
		} else {
			Node_DMS* dms = Search_DMS_ViTri(pDS->pListDMS.headLDMS, choose2);
			// trang thai sach = 1 se khong muon sach nay.
			if (dms->info.trangThaiSach == 1) {
				gotoxy(88, 24);
				cout << thongbao1;
				_getch();
				gotoxy(88, 24);
				cout << "                                                                     ";
				goto label1;
			}
			else if (dms->info.trangThaiSach == 2) {
				gotoxy(88, 24);
				cout << thongbao1;
				_getch();
				gotoxy(88, 24);
				cout << "                                                                      ";
				goto label1;
			}
			else if (dms->info.trangThaiSach == 0) {
				masach = dms->info.maSach;
				vitrisach = dms->info.viTri;
				dms->info.trangThaiSach = 1;
				pDS->soLanMuon += 1;
			}
			gotoxy(15, 1);
			cout << "                                       ";
			temp = 0;
		}
	} while (temp);
	return 1;
}

void xuat_ListDG_MT(TreeTDG t, hoTen *arr) {
	ShowCur(false);
	nDG = demDG(t);
	// thu tu trang
	int thuTuTrang, tongtrang;
	thuTuTrang = 1;
	tongtrang = (nDG / NUMBER_LINES) + 1;
	xuat_DG_Page1(t, arr, thuTuTrang);
	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
			case PAGE_UP:
				(thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
				xuat_DG_Page1(t, arr, thuTuTrang);
				break;
			case PAGE_DOWN:
				(thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
				xuat_DG_Page1(t, arr, thuTuTrang);
				break;
			case ENTER:
				return;
			}
		}
		SetColor(WHITE);
		gotoxy(3, 35);
		cout << " PageUp, PageDn, ENTER (tiep tuc) ";
		gotoxy(62, 1);
		cout << "Page: " << thuTuTrang << "/" << tongtrang;
	} while (true);
}

void xuLyMS(TreeTDG &t, List_DauSach &lDS) {
	clrscr();
	system("color 0");
	int msdg =  0;
	int check1, check2, check3 = 0;
	MT mt;
	NodeTDG* temp;
	char thongbao1[] = "           Doc Gia chi duoc muon toi da 3 cuon !";
	char thongbao2[] = "           Doc Gia da bi khoa the!";
	char thongbao3[] = "           Doc Gia da giu sach qua han 7 ngay!";
	char thongbao4[] = "           Doc Gia da lam mat sach! ";

label:
	index = 0;
	hoTen* ArrTenHo = new hoTen[nDG];
	tao_ArrTenHo(t, ArrTenHo);
	ve_DG(keyDisplayDG, 5, x_DG);
	QSort_TenHo(ArrTenHo, 0, nDG - 1);
	xuat_ListDG_MT(t, ArrTenHo);
	//// xoa vung nho
	delete[] ArrTenHo;

	VeHinhBangNhap(95, 3, 50, "Nhap ma doc gia de muon !");
	gotoxy(103, 5);
	check1 = NhapMaDocGia(msdg);

	// kiem tra ca truong hop  
	if (check1 == -1) {
		gotoxy(91, 10);
		cout << "Huy muon sach !";
		_getch();
	} else if (check1 == 1) {
		temp = layDG_NTDG(t, msdg);
		if (temp == NULL) {
			gotoxy(82, 10);
			cout << "Khong tim thay ma doc gia !";
			_getch();
			gotoxy(82, 10);
			cout << "                                                   ";
			goto label;
		} else {
			// in thong tin doc gia.
label1:
			gotoxy(95, 9);
			cout << "-Thong tin Doc Gia";
			gotoxy(93, 11);
			cout << "-Ho va ten: " << temp->info.ho << " "<< temp->info.ten;
			gotoxy(93, 12);
			cout << "-Trang thai the : ";
			(temp->info.trangThaiThe == 0) ? cout << "Khoa" : cout << "Hoat dong";
			gotoxy(93, 13);
			cout << "-Phai: ";
			(temp->info.phai == 0) ? cout << "Nam" : cout << "Nu";
			gotoxy(93,14);
			cout << "-So sach  da muon : " << temp->listMT.n;
			gotoxy(93, 15);
			cout << "-So sach chua tra : " << SoSachDangMuon(temp->listMT);
			// in danh sach cac sach dang muon trong list MUONTRA cua doc gia.
			gotoxy(95, 17);
			cout << "     =Sach Dang Muon=      ";
			gotoxy(85, 18);
			cout << "     Ten Sach                           ";
			gotoxy(118, 18);
			cout << " Ngay Muon  ";
			int i =  0;
			for (NodeMT * p = temp->listMT.headLMT; p != NULL ; p = p->rightNMT) {
				if (p->info.trangThai == 0  || p->info.trangThai == 2) {
					gotoxy(87 , 20 + i);
					cout << "                                           ";
					gotoxy(87, 20 + i);
					cout << p->info.tenSach;
					xuatNgayThang(p->info.ngayMuon, 118, 20 + i);
					i++;
					if (i == 3) {
						gotoxy(70, 28);
						cout << thongbao1;
						_getch();
						return;
					}
				}
			}
			if (temp->info.trangThaiThe == 0) {
				gotoxy(70, 28);
				cout << thongbao2;
				_getch();
				return;
			}
			if (MatSach(temp->listMT)) {
				gotoxy(70, 28);
				cout << thongbao4;
				_getch();
				return;
			}
			if (soNgayMuonMax(temp->listMT) > 7) {
				gotoxy(70, 28);
				cout << thongbao3;
				_getch();
				return;
			}
			gotoxy(70, 35);
			cout << dongthongbao;
			_getch();
			gotoxy(88, 35);
			cout << "                                                  ";
			//MT
			check2 = Menu_MS(lDS, temp);
			// check cac truong hop
			if (check2 == -1) {
				return;
			} else if (check2 == 1) {
				mt.tenSach = tensach;
				mt.ngayTra.nam = 0;
				mt.ngayTra.thang = 0;
				mt.ngayTra.ngay = 0;
				mt.maSach = masach;
				mt.viTriSach = vitrisach;
				mt.trangThai = 0;
				do {
					gotoxy(83, 28);
					cout << "Nhap vao ngay muon (F5 luu, ESC huy) !";
					check3 = InputNgayThang(mt.ngayMuon, 100, 30);
					// check cac truong hop
					if (check3 == -1) {
						return;
					} else if (check3 == 2) {
						themDauList_MT(temp->listMT, mt);
						goto label1;
					}
				} while (check3 );
			}
		}
	}
}

void xuLyTS(TreeTDG &t, List_DauSach &lDS) {
	clrscr();
	system("color 0");
	int msdg = 0;
	char thongbao[] = "         Doc Gia chua muon sach !  ";
	char thongbao1[] = "    Thong tin da duoc cap nhat !";
	int check, check1 = 0;
	NodeTDG* temp;
	NTN ngaytra;
	int choose1, choose2, i1, i2, condition = 1;

label:
	index = 0;
	hoTen* ArrTenHo = new hoTen[nDG];
	tao_ArrTenHo(t, ArrTenHo);
	ve_DG(keyDisplayDG, 5, x_DG);
	QSort_TenHo(ArrTenHo, 0, nDG - 1);
	xuat_ListDG_MT(t, ArrTenHo);
	//// xoa vung nho
	delete[] ArrTenHo;

	VeHinhBangNhap(80, 3, 50, "Hay Nhap Vao Ma Doc Gia !");
	gotoxy(90, 5);
	check = NhapMaDocGia(msdg);
	// kiem tra ca truong hop
	if (check == -1) {
		clrscr();
		gotoxy(50, 10);
		cout << "Huy tra sach !";
		_getch();
	} else if (check == 1) {
		temp = layDG_NTDG(t, msdg);
		if (temp == NULL) {
			gotoxy(40, 10);
			cout << "Ma doc gia khong dung !";
			_getch();
			gotoxy(40, 10);
			cout << "                                                   ";
			goto label;
		} else {
			clrscr();
			gotoxy(52, 9);
			cout << "Thong Tin Doc Gia";
			gotoxy(52, 11);
			cout << " Ho va ten: " << temp->info.ho << " " << temp->info.ten;

			gotoxy(52, 12);
			cout << " Trang thai the : ";
			(temp->info.trangThaiThe == 0) ? cout << "Khoa" : cout << "Hoat dong";
			gotoxy(52, 13);
			cout << " Phai: ";
			(temp->info.phai == 0) ? cout << "Nam" : cout << "Nu";
			gotoxy(52, 14);
			cout << " So sach  da muon : " << temp->listMT.n;
			gotoxy(35, 25);
			cout << "   F2:   Tra Sach,  F3:   Bao mat sach,  ESC:   thoat";
label1:
			gotoxy(52, 15);
			cout << " So sach chua tra : " << SoSachDangMuon(temp->listMT);
			gotoxy(37, 17);
			cout << "               Cac Sach Dang Muon                     ";
			ve_MT(keyDisplayMT, 7, x_MT);
			xuatListMT(temp->listMT);
			do {
				while (_kbhit()) {
					int kb_hit = _getch();
					if (kb_hit == 224 || kb_hit == 0)
						kb_hit = _getch();
					switch (kb_hit) {
						case  F2:
							choose1 = chonItem_MT(temp->listMT);
							if (choose1 == -1) {
								gotoxy(50, 30);
								cout << thongbao;
								return;
							}
							i1 = -1;
							for (NodeMT * pMT = temp->listMT.headLMT; pMT != NULL; pMT = pMT->rightNMT) {
								if (pMT->info.trangThai == 0 || pMT->info.trangThai == 2) {
									i1++;
									if (i1 == choose1) {
										// chuc nang nhap thong tin ngay tra.
										do {
											gotoxy(40, 28);
											cout << "Nhap vao ngay tra. Nhan F5 de luu, ESC de huy !";
											check1 = InputNgayThang(ngaytra, 55, 30);
											// check cac truong hop
											if (check1 == 2) {
												if (soSanhNgay(pMT->info.ngayMuon, ngaytra) < 0) {
													check1 = 1;
												} else {
													// thay doi trang thai sach da tra.
													pMT->info.trangThai = 1;
													pMT->info.ngayTra = ngaytra;
													pDauSach pDS = layDauSach_Ten(lDS, pMT->info.tenSach);
													Node_DMS* pDMS = Search_DMS_MaSach(pDS, pMT->info.maSach);
													pDMS->info.trangThaiSach = 0;
													goto label1;
												}
											} else if (check1 == -1) {
												goto label1;
											}
										} while (check1);
									}
								}
							}
							goto label1;

						case F3:
							choose2 = chonItem_MT(temp->listMT);
							if (choose2 == -1) {
								gotoxy(50, 30);
								cout << thongbao;
								return;
							}
							i2 = -1;
							for (NodeMT * pMT = temp->listMT.headLMT; pMT != NULL; pMT = pMT->rightNMT) {
								if (pMT->info.trangThai == 0 || pMT->info.trangThai == 2) {
									i2++;
									if (i2 == choose2) {
										pMT->info.trangThai = 2;
										gotoxy(45, 30);
										cout << thongbao1;
										cout << "                                                ";
									}
								}
							}
							goto label1;
						case ESC:
							condition = 0;
							break;
					}
				}
			} while (condition);
		}
	}
}

void xuLyMM(TreeTDG &t, List_DauSach &lDS) {
	int result;
	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);
	// load data from File.
	Load_DG(t);
	Load_DS(lDS);
	Introduce();
	clrscr();
	// vong lap vo han de xu ly.
	while (true) {
		ManHinhChinh();
		int type = chonMainMenu(5);
		switch (type) {
			case 0:
				SMainMenu1(keySubMainMenu1, 3);
				result = ChonSMenu(keySubMainMenu1, x_SMainMenus1, y_SMainMenus1, 3);
				if (result == 0) {
					Menu_DauSach(lDS);
				}
				else if (result == 1) {
					xuat_ListDStheoTT(lDS);
				}
				else if (result == 2) {
					Menu_DMS(lDS);
				}
				break;

			case 1:
				SMainMenu2(keySubMainMenu2, 3);
				result = ChonSMenu(keySubMainMenu2, x_SMainMenus2, y_SMainMenus2, 3);
				if (result == 0) {
					Menu_DocGia(t);
				}
				else if (result == 1) {
					InDG(t);
				}
				else if (result == 2) {
					DanhSachQuaHan(t);
				}
				break;

			case 2:
				SMainMenu3(keySubMainMenu3, 3);
				result = ChonSMenu(keySubMainMenu3, x_SMainMenus3, y_SMainMenus3, 3);
				if (result == 0) {
					xuLyTS(t, lDS);
				} else if (result == 1) {
					xuLyMS(t, lDS);
				} else if (result == 2) {
					Top10Sach(lDS);
				}
				break;

			case 3:
				Save_DS(lDS);
				Save_DG(t);
				return;
		}
	}
}
