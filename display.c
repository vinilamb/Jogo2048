#include "display.h"

#include <stdio.h>
#include <Windows.h>
#include <wincon.h>
#include <stdbool.h>

HWND wnd = NULL;
HWND Handle() {
	return wnd == NULL ? wnd = GetStdHandle(STD_OUTPUT_HANDLE) : wnd;
}

void Display_Board()
{
	
}

void SetCoord(int x, int y) {
	COORD c = { .X = x, .Y = y };
	SetConsoleCursorPosition(Handle(), c);
}

void Display_Casa(int x, int y) {
	SetCoord(x, y++);
	printf("+----------+"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("+----------+");
}