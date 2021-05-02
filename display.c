#include "display.h"

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

// Surrupiado do StackOverflow
// https://stackoverflow.com/questions/8621578/do-windows-console-color-values-have-official-names-constants-associated-with/49929936

/*Enum to store Foreground colors*/
typedef enum FG_COLORS
{
    FG_BLACK = 0,
    FG_BLUE = 1,
    FG_GREEN = 2,
    FG_CYAN = 3,
    FG_RED = 4,
    FG_MAGENTA = 5,
    FG_BROWN = 6,
    FG_LIGHTGRAY = 7,
    FG_GRAY = 8,
    FG_LIGHTBLUE = 9,
    FG_LIGHTGREEN = 10,
    FG_LIGHTCYAN = 11,
    FG_LIGHTRED = 12,
    FG_LIGHTMAGENTA = 13,
    FG_YELLOW = 14,
    FG_WHITE = 15
}FG_COLORS;

/*Enum to store Background colors*/
typedef enum BG_COLORS
{
    BG_NAVYBLUE = 16,
    BG_GREEN = 32,
    BG_TEAL = 48,
    BG_MAROON = 64,
    BG_PURPLE = 80,
    BG_OLIVE = 96,
    BG_SILVER = 112,
    BG_GRAY = 128,
    BG_BLUE = 144,
    BG_LIME = 160,
    BG_CYAN = 176,
    BG_RED = 192,
    BG_MAGENTA = 208,
    BG_YELLOW = 224,
    BG_WHITE = 240
} BG_COLORS;

HWND wnd = NULL;
HWND Handle() {
	return wnd == NULL ? wnd = GetStdHandle(STD_OUTPUT_HANDLE) : wnd;
}

void Display_Board(Board b)
{
	board_iter(
		Display_Casa(i_pos.coluna * 11, i_pos.linha * 6, i_casa->valor);
	);
}

void SetCoord(int x, int y) {
	COORD c = { .X = x, .Y = y };
	SetConsoleCursorPosition(Handle(), c);
}

void desenha_casa_grid(int x, int y) {
	SetCoord(x, y++);
	printf("+----------+"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("|          |"); SetCoord(x, y++);
	printf("+----------+");
}

void desenha_casa_interior(int x, int y, int score) {
	SetCoord(x, y++);
	printf("          ");		SetCoord(x, y++);
	printf("          ");		SetCoord(x, y++);
	printf("  %5d   ", score);	SetCoord(x, y++);
	printf("          ");		SetCoord(x, y++);
	printf("          ");
}

void Display_Casa(int x, int y, int score) {
	CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(Handle(), &info);

	desenha_casa_grid(x, y);

    SetConsoleTextAttribute(Handle(), ScoreToCor(score));
	desenha_casa_interior(x + 1, y + 1, score);
    SetConsoleTextAttribute(Handle(), info.wAttributes);
    // Deixa o cursor em uma posição decente
	SetCoord(x + 12, y + 6);
}

void Display_Score(int x, int y, int score)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(Handle(), &info);

    SetConsoleTextAttribute(Handle(), FG_BLACK | BG_SILVER);
    SetCoord(x, y++);
    printf("  Score  ");

    SetConsoleTextAttribute(Handle(), FG_YELLOW | BG_GRAY);
    SetCoord(x, y++);
    printf("    %3d  ", score);  

    SetConsoleTextAttribute(Handle(), info.wAttributes);
}

void MostrarCursor(bool mostrar)
{
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(Handle(), &info);
    info.bVisible = false;
    SetConsoleCursorInfo(Handle(), &info);
}

BG_COLORS ScoreToCor(int score) {
    switch (score) {
        case 2: return BG_GRAY;
        case 4: return BG_TEAL;
        case 8: return BG_MAROON;
        case 16: return BG_RED;
        case 32: return BG_CYAN;
        case 64: return BG_NAVYBLUE;
        case 128: return BG_LIME;
        case 256: return BG_OLIVE;
        case 512: return BG_MAGENTA;
        case 1024: return BG_SILVER;
        case 2048: return BG_YELLOW;
        case 4096: return BG_PURPLE;
        default: return 0;
    }
}

enum Cor {
	Red,
	Green,
	Blue
};

void Display(Board b, int score, int movimentos) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    Display_Board(b);

    GetConsoleScreenBufferInfo(Handle(), &info);

    Display_Score(50, 3, score);

    SetConsoleCursorPosition(Handle(), info.dwCursorPosition);
}