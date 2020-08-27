#pragma once
#include <Windows.h>
#include "DefineVar.h"
#include <string>
using std::string;

extern int toaDo;
extern int index;
extern int nDG;
extern bool done;
extern string tensach;
extern string masach;
extern string vitrisach;
extern char dongthongbao[];

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
void setFontSize(int FontSize);
