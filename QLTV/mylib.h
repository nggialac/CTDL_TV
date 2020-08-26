#pragma once
#include <Windows.h>
#include "Marcro.h"
//#include "GlobalVariable.h"
#include <string>

using std::string;
// global variable
extern int toaDo;
extern int index;
extern int nDG;
extern bool done;
extern string tensach;
extern string masach;
extern string vitrisach;
extern char dongthongbao[];

// thay doi kich thuoc cua so console
void resizeConsole(int width, int height);
int wherex(void);
int wherey(void);
void SetBGColor(WORD color);
void gotoxy(int x, int y);
void ShowCur(bool CursorVisibility);
void SetColor(WORD color);
void cls(HANDLE hConsole);
void clrscr();
void normalTextColor();
void normalBGColor();
char getCursorChar();    
char readChar(int x, int y); 
