#include "XuLySaveLoad.h"


void Introduce() {
	//system("color 3E"); //Background xanh
	system("color 0");
	ShowCur(false);
	string a;

	// lay tu file o che do chi doc
	ifstream inFile("introduce.txt", ios:: in );
	if (inFile.good()) { // Kiem tra xem file co ket noi duoc hay khong?
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(LIGHT_AQUA); // Mau Load file
			Sleep(25);
			cout << a << endl;
		}
	} else { //Tra ve loi
		cout << "Lien ket voi File introduce khong thanh cong! " << "\n";
	}

	SetColor(WHITE);

	ShowCur(false);

	// nhan enter de thoat vong lap
	gotoxy(54, 35);
	cout << "Press ENTER to continue! ";
	SetBGColor(BLACK);
	cin.ignore();
	return;
}

void ManHinhChinh() {
	system("color 0");
	clrscr();
	normalTextColor();
	ShowCur(false);
	//VeKhungMenu();

	normalBGColor();
	MainMenu(keyMainMenu, 5);
	normalBGColor();

	string text;
	int y = 0;
	// lay tu file va chi doc
	ifstream inFile("QuanLyThuVien.txt", ios:: in );
	// Kiem tra xem file co ket noi duoc hay khong?
	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, text);
			SetColor(11);
			Sleep(25);
			gotoxy(25, y++);
			cout << text << endl;
		}
	} else { //Tra ve loi
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
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
		cout << "KET NOI VOI FILE DauSach THAT BAI! ";
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
			/*pDS->tenSach = info.tenSach;
			pDS->ISBN = info.ISBN;
			pDS->tacGia = info.tacGia;
			pDS->theLoai = info.theLoai;
			pDS->soTrang = info.soTrang;
			pDS->namXB = info.namXB;*/
			inFile >> soSach;
			getline(inFile, temp);
			initList_DMS(pDS->pListDMS);
			for (int j = 0; j < soSach; j++) {
				getline(inFile, dms.maSach);
				inFile >> dms.trangThaiSach;
				getline(inFile, temp);
				getline(inFile, dms.viTri);
				addTailList_DMS(pDS->pListDMS, dms);
			}
			themDauSach(listDS, pDS);
		}
	} else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
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
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
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
			pDG = tim_DG(t, dg.maThe);


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
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
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
	int tttrang, tongtrang;
	pDauSach pDS = NULL;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;

label:
	do {
		// hien thi bang chua thong tin dau sach
		XoaMotVung(1, 1, 65, 80);
		ve_DS(keyDisplayDS, 6, x_DS);
		xuat_DStheoPage(lDS, tttrang);
		gotoxy(23, 1);
		cout << "Chon dau sach de muon ! ";
		normalBGColor();
		// chon dau sach muon nhap sach vao
		choose1 = ChooseItems(lDS, tttrang, tongtrang);
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
	tttrang = 1;
	tongtrang = (pDS->pListDMS.n / NUMBER_LINES) + 1;

	gotoxy(15, 1);
	cout << "Chon Sach De Muon !";
	normalBGColor();
	do {
		// hien thi bang chua thong tin danh muc sach
		ve_DMS(keyDisplayDMS, 3, x_DMS);
		OutputDMS_PerPage(pDS, tttrang);
		choose2 = ChooseItems1(pDS, tttrang, tongtrang);
		if (choose2 == -1) {
			temp = 1;
			tttrang = 1;
			gotoxy(15, 1);
			cout << "                                       ";
			goto label;
		} else if (choose2 + 1 > pDS->pListDMS.n) {
			gotoxy(2, y_Ve + 3 + choose2 % NUMBER_LINES);
			cout << setw(12) << setfill(' ') << ' ';
			continue;
		} else {
			Node_DMS* dms = Search_DMS2(pDS->pListDMS.headLDMS, choose2);
			// trang thai sach = 1 se khong muon sach nay.
			if (dms->info.trangThaiSach == 1) {
				gotoxy(88, 24);
				cout << thongbao1;
				_getch();
				gotoxy(88, 24);
				cout << "                                                                     ";
				goto label1;
			}
			// trang thai sach = 2 , sach da thanh ly, nen se khong muon sach duoc
			else if (dms->info.trangThaiSach == 2) {
				//chuChay(thongbao2, 88, 24);
				gotoxy(88, 24);
				cout << thongbao1;
				_getch();
				gotoxy(88, 24);
				cout << "                                                                      ";
				goto label1;
			}
			// trang thai sach = 0 cho muon duoc, nen se tien hanh muon sach.
			else if (dms->info.trangThaiSach == 0) {
				// lay ma sach va vi tri sach... cap nhap trang thai sach da duoc muon.
				masach = dms->info.maSach;
				vitrisach = dms->info.viTri;
				dms->info.trangThaiSach = 1;
				pDS->soLanMuon += 1;
			}
			// xoa dong tieu de di.
			gotoxy(15, 1);
			cout << "                                       ";
			temp = 0;
		}
	} while (temp);
	return 1;
}

void Output_ListDG_MT(TreeTDG t, hoTen *arr) {
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
			case ENTER:
				return;
			}
		}
		SetColor(WHITE);
		gotoxy(3, 35);
		cout << "HotKey: PgUp, PgDn, ENTER (tiep tuc) ";
		gotoxy(62, 1);
		cout << "Page: " << tttrang << "/" << tongtrang;
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
	Output_ListDG_MT(t, ArrTenHo);
	//// xoa vung nho
	delete[] ArrTenHo;

	VeHinhBangNhap(83, 3, 50, "            Nhap ma doc gia de muon !");
	gotoxy(103, 5);
	check1 = NhapMaDocGia(msdg);

	// kiem tra ca truong hop  
	if (check1 == -1) {
		gotoxy(91, 10);
		cout << "Huy muon sach !";
		_getch();
	} else if (check1 == 1) {
		temp = tim_DG(t, msdg);
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
			cout << "Thong tin Doc Gia";
			gotoxy(93, 11);
			cout << "- Ho va ten: " << temp->info.ho << " "<< temp->info.ten;

			gotoxy(93, 12);
			cout << "- Trang thai the : ";
			(temp->info.trangThaiThe == 0) ? cout << "Khoa" : cout << "Hoat dong";
			gotoxy(93, 13);
			cout << "- Phai: ";
			(temp->info.phai == 0) ? cout << "Nam" : cout << "Nu";
			gotoxy(93, 14);
			cout << "- So sach  da muon : " << temp->listMT.n;
			gotoxy(93, 15);
			cout << "- So sach chua tra : " << SoSachDangMuon(temp->listMT);

			// in danh sach cac sach dang muon trong list MUONTRA cua doc gia.
			gotoxy(95, 17);
			cout << "     =Sach Dang Muon=      ";
			gotoxy(85, 18);
			cout << "     Ten Sach                           ";
			gotoxy(118, 18);
			cout << " Ngay Muon  ";
			int i =  0;
			for (NodeMT * p = temp->listMT.headLMT; p != NULL ; p = p->rightNMT) {////?????????????????????????
				// truong hop dang muon chua tra, va truong hop dang muon nhung bi mat sach.
				if (p->info.trangThai == 0  || p->info.trangThai == 2) {
					// nap vao so sach muon cua doc gia qua bien i
					gotoxy(87 , 20 + i);
					cout << "                                           ";
					gotoxy(87, 20 + i);
					cout << p->info.tenSach;
					xuatNgayThang(p->info.ngayMuon, 118, 20 + i);
					i++;
					if (i == 3) {
						gotoxy(60, 24);
						cout << thongbao1;
						_getch();
						return;
					}
				}
			}
			// xu ly truong hop khong cho muon sach khi trang thai the da bi khoa.
			if (temp->info.trangThaiThe == 0) {
				gotoxy(60, 24);
				cout << thongbao2;
				_getch();
				return;
			}
			// xu ly truong hop khong cho muon sach khi doc gia lam mat sach.
			if (MatSach(temp->listMT)) {
				gotoxy(60, 24);
				cout << thongbao4;
				_getch();
				return;
			}
			// xu ly truong hop muon sach qua han 7 ngay.
			if (soNgayMuonMax(temp->listMT) > 7) {
				gotoxy(60, 24);
				cout << thongbao3;
				_getch();
				return;
			}
			// in ra dong thong bao
			gotoxy(60, 35);
			cout << dongthongbao;
			_getch();
			gotoxy(88, 35);
			cout << "                                                  ";
			// xu ly thao tac muon tra.
			check2 = Menu_MS(lDS, temp);
			// check cac truong hop
			if (check2 == -1) {
				return;
			} else if (check2 == 1) {
				// nap thong tin vao cau truc muon tra bao gom ten sach, ngay muon, ngay tra..v.v.v
				mt.tenSach = tensach;
				mt.ngayTra.nam = 0;
				mt.ngayTra.thang = 0;
				mt.ngayTra.ngay = 0;
				mt.maSach = masach;
				mt.viTriSach = vitrisach;
				mt.trangThai = 0;
				do {
					gotoxy(83, 28);
					cout << "Nhap vao ngay muon. Nhan F10 de luu, ESC de huy !";
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
	VeHinhBangNhap(40, 3, 50, "        HAY NHAP VAO MA DOC GIA !");
	gotoxy(63, 5);
	check = NhapMaDocGia(msdg);

	// kiem tra ca truong hop
	if (check == -1) {
		gotoxy(50, 10);
		cout << "BAN VUA HUY TAC VU TRA SACH !!!";
		_getch();
	} else if (check == 1) {
		temp = tim_DG(t, msdg);
		if (temp == NULL) {
			gotoxy(40, 10);
			cout << "MA DOC GIA KHONG TON TAI !!!";
			_getch();
			gotoxy(40, 10);
			cout << "                                                   ";
			goto label;
		} else {
			gotoxy(52, 9);
			cout << "THONG TIN DOC GIA";
			gotoxy(52, 11);
			cout << " Ho va ten: " << temp->info.ho << " " << temp->info.ten;

			gotoxy(52, 12);
			cout << " Trang thai the : ";
			(temp->info.trangThaiThe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(52, 13);
			cout << " Phai: ";
			(temp->info.phai == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(52, 14);
			cout << " So sach  da muon : " << temp->listMT.n;
			gotoxy(35, 25);
			cout << "Hotkey:  F3 -  Tra Sach,  F4  -  Bao mat sach,  ESC - thoat";

label1:
			gotoxy(52, 15);
			cout << " So sach chua tra : " << SoSachDangMuon(temp->listMT);
			gotoxy(37, 17);
			cout << "               CAC SACH DANG MUON                     ";
			ve_MT(keyDisplayMT, 7, x_MT);
			xuatListMT(temp->listMT);
			do {
				while (_kbhit()) {
					int kb_hit = _getch();
					if (kb_hit == 224 || kb_hit == 0)
						kb_hit = _getch();

					switch (kb_hit) {
						case  KEY_F3:
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
											cout << "Nhap vao ngay tra. Nhan F10 de luu, ESC de huy !";
											check1 = InputNgayThang(ngaytra, 55, 30);
											// check cac truong hop
											if (check1 == 2) {
												if (soSanhNgay(pMT->info.ngayMuon, ngaytra) < 0) {
													check1 = 1;
												} else {
													// thay doi trang thai sang da tra sach.
													pMT->info.trangThai = 1;
													pMT->info.ngayTra = ngaytra;
													// tim kiem dau sach ma doc gia da muon
													pDauSach pDS = layDauSach_Ten(lDS, pMT->info.tenSach);
													// tim kiem sach co ma dau sach ma doc gia da muon.
													Node_DMS* pDMS = Search_DMS1(pDS, pMT->info.maSach);
													// thay doi trang thai sach tu da co nguoi muon sang chua co nguoi muon
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

						case KEY_F4:
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
										// thay doi trang thai sang da lam mat sach.
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
		gotoxy(55, 32);
		cout << " ESC: Ve Menu Chinh";
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
					Top10Sach(lDS);
				} else if (result == 2) {
					xuLyMS(t, lDS);
				}
				break;

			case 3:
				// luu data tu chuong trinh vao file.
				Save_DS(lDS);
				Save_DG(t);
				return;
		}
	}
}
