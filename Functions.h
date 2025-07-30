#pragma once
#include<string>

struct Position {
	int x;
	int y;
};

void gotoxy(int x, int y);
void colour();
void cursorVisible(bool visible);
void print_text(std::string text, int offset = 0);
void clear_text();
void getCursorPosition(int& x, int& y);
int generate_random_number(int min, int max);
Position get_coords(char id[1]);