#include "XuLyInput.h"

void xoa(char* s, int vitrixoa) {
	int n = strlen(s);
	for (int i = vitrixoa; i < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0';
}

char* ChuanHoaKyTu(char* result) {
	for (int i = 0; i < strlen(result); i++)
		if (result[i] == ' '&& result[i + 1] == ' ') {
			xoa(result, i);
			i--;
		}
	if (result[0] == ' ')
		xoa(result, 0);
	if (result[strlen(result) - 1] == ' ')
		xoa(result, strlen(result) - 1);
	return result;
}

char* toCharArray(string str) {
	char* c = new char(str.size() + 1);
	for (int i = 0; i < str.size() + 1; i++)
		c[i] = str[i];
	return c;
}

string ChuanHoaChuoi(string result) {
	for (size_t i = 1; i < result.length(); i++) {
		if (result[0] == ' ') {
			result.erase(0, 1);
			i--;
		} else if (result[i - 1] == ' ' && result[i] == ' ') {
			result.erase(i - 1, 1);
			i--;
		} else if (result[result.length() - 1] == ' ') {
			result.erase(result.length() - 1, 1);
		}
	}
	return result;
}

void Nhap(int &result, int choice, int &tienTrinh, bool &isSave, bool &isEscape) {
	//cout << result;
	int count = 0;
	// giu lai vi tri ban dau
	int x = wherex() - 1, y = wherey() - 1;
	if (choice == 1 && result == 3) {
		result = 1;
		gotoxy(x, y);
		cout << result << ":  Hoat dong ";
	}
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if ((kb_hit == 48 || kb_hit == 49) && count < 1) {
				count++;
				result = kb_hit - 48;
				if (choice == 0) {
					gotoxy(x_Note + 15, y_Note);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  Nam" : cout << result << ":  Nu    ";
				} else if (choice == 1) {
					// xoa dong thong bao
					gotoxy(x_Note + 15, y_Note);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  Khoa      " : cout << result << ":  Hoat dong ";
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (choice == 0) {
					if (kb_hit == KEY_UP) {
						tienTrinh = 1;
						return;
					} else {
						tienTrinh = 3;
						return;
					}
				} else if (choice == 1) {
					if (kb_hit == KEY_UP) {
						tienTrinh = 2;
						return;
					} else {
						tienTrinh = 0;
						return;
					}
				}
			} else if (kb_hit == ENTER) {
				if (choice == 0) {
					tienTrinh = 3;
					return;
				} else if (choice == 1) {
					tienTrinh = 0;
					return;
				}
			} else if (kb_hit == BACKSPACE && count > 0) {
				gotoxy(x, y);
				result = 3;
				cout << " " << setw(15) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Nhap 0 hoac 1, Backspace de xoa !";
				SetColor(WHITE);
				gotoxy(x, y);
			}
		}
	}
}

void NhapTen(string &result, int &ordinal, bool &isSave, bool &isEscape) {
	cout << result;
	int count = (int)result.length();
	int x, y;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;

		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa.
			// chi nhap ten toi da 7 ky tu, vi tu dai nhat tieng viet chi la 7.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)) && count < MAX_TEN) {
				count++;
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					ordinal = 0;
					return;
				} else {
					ordinal = 2;
					return;
				}
			} else if (kb_hit == ENTER) {
				ordinal = 2;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);

			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 7 ky tu chu !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}


void NhapHo(string &result, int &ordinal, bool &isSave, bool &isEscape) {

	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			// chi nhap ho toi da 15 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
			        && count < MAX_HO && count >= 0) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (nSpace == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					ordinal = 3;
					return;
				} else {
					ordinal = 1;
					return;
				}
			} else if (kb_hit == ENTER) {
				ordinal = 1;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 16 ky tu chu !!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void NhapTenSach(string &result, int &tienTrinh, bool &isSave, bool &isEscape) {
	ShowCur(true);
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int flag = 0;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)
			        || (kb_hit >=  48 && kb_hit <= 57) || kb_hit == SPACE) && count < MAX_TENSACH && count >= 0) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (flag == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					flag = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					flag = 1;
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 5;
					return;
				} else {
					tienTrinh = 1;
					return;
				}
			} else if (kb_hit == ENTER) {
				tienTrinh = 1;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 24 ky tu chu + so";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void NhapTenTacGia(string &result, int &tienTrinh, bool &isSave, bool &isEscape) {
	ShowCur(true);
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
			        && count < MAX_TENTG && count >= 0) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (nSpace == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 1;
					return;
				} else {
					tienTrinh = 3;
					return;
				}
			} else if (kb_hit == ENTER) {
				tienTrinh = 3;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 17 ky tu chu !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void NhapTheLoaiSach(string &result, int &tienTrinh, bool &isSave, bool &isEscape) {
	ShowCur(true);
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
			        && count < MAX_THELOAISACH && count >= 0) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (nSpace == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 2;
					return;
				} else {
					tienTrinh = 4;
					return;
				}
			} else if (kb_hit == ENTER) {
				tienTrinh = 4;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 11 ky tu chu !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void nhapSoTrang(int &nTrang, int &tienTrinh, bool &isSave, bool &isEscape) {
	ShowCur(true);
	int temp = nTrang;
	int count = 0;
	int x, y;
	while (temp != 0) {
		count++;
		temp /= 10;
	}
	if (count) {
		cout << nTrang;
	}
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count < 6) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				int f = kb_hit - 48;
				cout << f;
				nTrang = nTrang * 10 + (f);
				count++;
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 3;
					return;
				} else {
					tienTrinh = 5;
					return;
				}
			} else if (kb_hit == ENTER) {
				tienTrinh = 5;
				return;
			} else if (kb_hit == BACKSPACE && count >0) {
				cout << "\b" << " " << "\b";
				count--;
				nTrang /= 10;
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 6 so !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void NhapNamXuatBan(int &nam, int &tienTrinh, bool &isSave, bool &isEscape) {
	ShowCur(true);
	// dem so chu so
	int temp = nam;
	int count =  0;
	int x, y;
	while (temp != 0) {
		count++;
		temp /= 10;
	}
	if (count) {
		cout << nam;
	}
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count <= 3) {
				// xoa dong thong bao
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				int f = kb_hit - 48;
				cout << f;
				nam = nam * 10 + (f);
				count++;
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 4;
					return;
				} else {
					tienTrinh = 0;
					return;
				}
			} else if (kb_hit == ENTER) {
				tienTrinh = 0;
				return;
			} else if (kb_hit == BACKSPACE && count >0) {
				cout << "\b" << " " << "\b";
				count--;
				nam /= 10;
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Toi da 4 so";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void NhapISBN(string &result, int &tienTrinh, bool &isSave, bool &isEscape) {
	ShowCur(true);
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57)) && count < MAX_ISBN) {
				count++;
				gotoxy(x_Note + 15, y_Note);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 0;
					return;
				} else {
					tienTrinh = 2;
					return;
				}
			} else if (kb_hit == ENTER) {
				if (result.length() == MAX_ISBN) {
					tienTrinh = 2;
					return;
				}
				else {
					gotoxy(x_Note + 15, y_Note);
					SetColor(WHITE);
					cout << "Nhap dung 6 ky tu chu !";
					return;
				}
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(x_Note + 15, y_Note);
				SetColor(WHITE);
				cout << "Nhap dung 6 ky tu chu !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

int  ChonSoSachNhap() {
	int soluong = 2;
	gotoxy(88, 3);
	SetColor(WHITE);
	cout << "So luong (up, down): ";
	gotoxy(88, 5);
	cout << "(Chon '0' de chinh sua!)";
	gotoxy(117, 3);
	cout << soluong;
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					soluong++;
					gotoxy(115, 3);
					SetBGColor(BLACK);
					cout << " " << setw(10) << setfill(' ') << " ";
					gotoxy(117, 3);
					cout << soluong;
				}
				else if (kb_hit == KEY_DOWN) {
					if (soluong >= 1) {
						soluong--;
						gotoxy(115, 3);
						SetBGColor(BLACK);
						cout << " " << setw(10) << setfill(' ') << " ";
						gotoxy(117, 3);
						cout << soluong;
					}
				}
			}
			else if (kb_hit == ENTER) {
				return soluong;
			}
			else if (kb_hit == ESC) {
				return -1;
			}
		}
	}
}

void NhapTrangThaiSach(int &result, int &tienTrinh, bool &isSave, bool &isEscape, int a, int b) {
	gotoxy(a, b);
	ShowCur(true);
	int count = 0;
	int x = wherex() - 1, y = wherey() - 1;
	if ( result == 3) {
		result = 0;
		gotoxy(x, y);
		cout << result << ":  Duoc muon ";
	}
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if ((kb_hit == 48 || kb_hit == 49 || kb_hit == 50) && count < 1) {
				count++;
				result = kb_hit - 48;
				// xoa dong thong bao
				gotoxy(a - 7, y_Note + 2);
				cout << setw(49) << setfill(' ') << " ";
				gotoxy(x, y);
				if (result == 0)
					cout << result << ":   Co the muon ";
				else if (result == 1)
					cout << result << ":   Da duoc muon  ";
				else if (result == 2)
					cout << result << ":   Da thanh ly   ";
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					tienTrinh = 2;
					return;
				} else {
					tienTrinh = 2;
					return;
				}
			} else if (kb_hit == ENTER) {
				tienTrinh = 2;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				gotoxy(x, y);
				result = 3;
				cout << " " << setw(17) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(a - 7, y_Note + 2);
				SetColor(WHITE);
				cout << "Chon 0, 1, 2 hoac Backspace de xoa !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void NhapViTri(string &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b) {
	gotoxy(a, b);
	ShowCur(true);
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;
	while (true) {
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit()) {
			int kb_hit = _getch();
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57 )
			        || kb_hit == SPACE || kb_hit == 44) && count < MAX_TENTG && count >= 0) {
				// xoa dong thong bao
				gotoxy(a - 7, y_Note + 2);
				cout << setw(48) << setfill(' ') << " ";
				gotoxy(x, y);
				// chuan hoa khoang trong
				if (nSpace == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				if (kb_hit == KEY_UP) {
					ordinal = 1;
					return;
				} else {
					ordinal = 1;
					return;
				}
			} else if (kb_hit == ENTER) {
				ordinal = 1;
				return;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else { // check vi tri a ne.
				gotoxy(a - 7 , y_Note + 2);
				SetColor(WHITE);
				cout << "Toi da 17 ky tu chu + so + ',' !";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

int  NhapMaDauSach(string &result) {
	ShowCur(true);
	cout << result;
	int count = (int)result.length();
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57)
			        || kb_hit == 44) && count <= 10 && count >= 0) {
				count++;
				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
			} else if (kb_hit == ENTER) {
				return 1 ;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			} else if (kb_hit == ESC) {
				return  -1;
			}
		}
	}
}

int  NhapTenSachTimKiem(string &result) {
	ShowCur(true);
	cout << result;
	int flag = 0;
	int count = (int)result.length();
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach va so
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)
			        || (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE) && count < 35 && count >= 0) {
				if (flag == 1 && kb_hit == SPACE) {
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					flag = 0;
				} else if (kb_hit != SPACE) {
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					flag = 1;
				}
			} else if (kb_hit == ENTER) {
				return 1;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);

			} else if (kb_hit == ESC) {
				return  -1;
			}
		}
	}
}

int NhapMaDocGia(int &msdg) {
	ShowCur(true);
	int temp = msdg;
	int count = 0;
	while (temp != 0) {
		count++;
		temp /= 10;
	}
	if (count) {
		cout << msdg;
	}
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if ((kb_hit >= 48 && kb_hit <= 57) 	&& ( count <= 9 && count >= 0)) {
				int f = kb_hit - 48;
				cout << f;
				msdg = msdg * 10 + (f);
				count++;
			} else if (kb_hit == ENTER) {
				return 1;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				msdg /= 10;
			} else if (kb_hit == ESC) {
				return  -1;
			}
		}
	}
}

int InputMaThe(int &maThe) {
	ShowCur(true);
	int temp = maThe;
	int count = 0;
	while (temp != 0) {
		count++;
		temp /= 10;
	}
	if (count) {
		cout << maThe;
	}
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if ((kb_hit >= 48 && kb_hit <= 57) && (count <= 9 && count >= 0)) {
				int f = kb_hit - 48;
				cout << f;
				maThe = maThe * 10 + (f);
				count++;
			} else if (kb_hit == ENTER) {
				return 1;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				maThe /= 10;
			} else if (kb_hit == ESC) {
				return  -1;
			}
		}
	}
}

int InputNgayThang(NTN &date, int x, int y) {
	ShowCur(true);
	int flag = 2;
	layNgayGioHT(date);
	NTN tempDate;
	tempDate.ngay = date.ngay;
	tempDate.thang = date.thang;
	tempDate.nam = date.nam;

	gotoxy(123, 37);
	gotoxy(x, y);
	cout << date.ngay << " /" << date.thang << " /" << date.nam;
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57) {
				if (flag == 0) {
					int f = kb_hit - 48;
					tempDate.ngay = tempDate.ngay * 10 + (f);
					if (tempDate.ngay > 31) {
						tempDate.ngay /= 10;
						continue;
					}
					gotoxy(x, y);
					cout << tempDate.ngay;
				} else if (flag == 1) {
					int f = kb_hit - 48;
					tempDate.thang = tempDate.thang * 10 + (f);
					if (tempDate.thang > 12) {
						tempDate.thang /= 10;
						continue;
					}
					gotoxy(x + 4, y);
					cout << tempDate.thang;
				} else if (flag == 2) {
					int f = kb_hit - 48;
					tempDate.nam = tempDate.nam * 10 + (f);
					if (tempDate.nam > 9999) {
						tempDate.nam /= 10;
						continue;
					}
					gotoxy(x + 7, y);
					cout << tempDate.nam;
				}
			} else if (kb_hit == ENTER) {
				if (flag == 0) {
					gotoxy(x + 4, y);
					cout << tempDate.thang;
					flag = 1;
				} else if (flag == 1) {
					gotoxy(x + 7, y);
					cout << tempDate.nam;
					flag = 2;
				} else if (flag == 2) {
					gotoxy(x, y);
					cout << tempDate.ngay;
					flag = 0;
				}
			} else if (kb_hit == BACKSPACE && tempDate.ngay > 0 && tempDate.thang > 0 && tempDate.nam > 0) {
				cout << "\b" << " " << "\b";
				if (flag == 0) {
					tempDate.ngay /= 10;
				} else if (flag == 1) {
					tempDate.thang /= 10;
				} else if (flag == 2) {
					tempDate.nam /= 10;
				}
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					flag = isNgayDung(tempDate);
					if (flag == 3) {
						// xoa du
						gotoxy(x - 19, y - 2);
						cout << "                                                  ";
						gotoxy(x, y);
						cout << "                     ";
						gotoxy(x - 3, y + 2);
						cout << "                     ";
						// kiem tra ngay nhap lon hon ngay hien tai
						if (khoangCachNgay(tempDate) < 0) {
							return 1;
						} else {
							date = tempDate;
							return 2;
						}
					} else if (flag == 0) {
						gotoxy(x - 3, y + 2);
						cout << "Sai ngay. Nhap lai!";
						gotoxy(x, y);
						cout << tempDate.ngay;
						continue;
					} else if (flag == 1) {
						gotoxy(x - 3, y + 2);
						cout << "Sai thang. Nhap lai!";
						gotoxy(x + 4, y);
						cout << tempDate.thang;
						continue;
					} else if (flag == 2) {
						gotoxy(x - 3, y + 2);
						cout << "Sai nam. Nhap lai!";
						gotoxy(x + 7, y);
						cout << tempDate.nam;
						continue;
					}
				}
			} else if (kb_hit == ESC) {
				// xoa du
				gotoxy(x - 19, y - 2);
				cout << "                                                  ";
				gotoxy(x, y);
				cout << "                     ";
				gotoxy(x - 3, y + 2);
				cout << "                     ";
				return -1;
			}
		}
	}
}
