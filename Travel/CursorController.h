#pragma once
//this header is for Locate the Cursor and Control it
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "xcurse.h"
#include <ctime>

using namespace std;
using namespace xc;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
CONSOLE_CURSOR_INFO cci;
void xy(int, int);

void xy(int x, int y)
{
	cci.bVisible = false;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(console, pos);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
