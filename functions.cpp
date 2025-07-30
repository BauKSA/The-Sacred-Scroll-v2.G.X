#include<Windows.h>
#include<iostream>
#include<chrono>
#include <random>

#include "Globals.h"
#include "functions.h"

void gotoxy(int x, int y) {
	HANDLE cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cCoords{};
	cCoords.X = x;
	cCoords.Y = y;

	SetConsoleCursorPosition(cHandle, cCoords);
}

void colour() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 1 + rand() % 15;
	SetConsoleTextAttribute(hConsole, color);
}

void cursorVisible(bool visible) {
	HANDLE cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cCursor{};
	cCursor.bVisible = visible;
	cCursor.dwSize = 1;

	SetConsoleCursorInfo(cHandle, &cCursor);
}

Position get_coords(char id[1]) {
	Position pos{0};
	pos.y = int(id[1]);

	switch (id[0]) {
	default:
		pos.x = 0;
		break;
	case 'A':
		pos.x = 0;
		break;
	case 'B':
		pos.x = 1;
		break;
	case 'C':
		pos.x = 2;
		break;
	case 'D':
		pos.x = 3;
		break;
	case 'E':
		pos.x = 4;
		break;
	case 'F':
		pos.x = 5;
		break;
	case 'G':
		pos.x = 6;
		break;
	case 'H':
		pos.x = 7;
		break;
	case 'I':
		pos.x = 8;
		break;
	case 'J':
		pos.x = 9;
		break;
	}

	return pos;

}

void print_text(std::string text, int offset) {
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + offset);
	size_t limit = 0;
	size_t enter = 0;
	for (size_t i = 0; i < text.size(); i++) {
		if (text.at(i) == '¿') continue;
		if (limit == 20) {
			enter++;
			gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + enter + offset);
			limit = 0;
			switch (text.at(i)) {
			case '3':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 160);
				}
				break;
			case '4':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 130);
				}
				break;
			case '5':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 161);
				}
				break;
			case '6':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 162);
				}
				break;
			case '7':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 163);
				}
				break;
			case '8':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 164);
				}
				break;
			case '°':
				enter++;
				break;
			case '{':
				printf("4");
				break;
			default:
				if (text.at(i) != ' ') printf("%c", text.at(i));
				break;
			}
		} else {
			switch (text.at(i)) {
			case '3':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 160);
				}
				break;
			case '4':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 130);
				}
				break;
			case '5':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 161);
				}
				break;
			case '6':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 162);
				}
				break;
			case '7':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 163);
				}
				break;
			case '8':
				if (text.at(i - 1) && text.at(i - 1) == '¿') {
					printf("%c", text.at(i));
				}
				else {
					printf("%c", 164);
				}
				break;
			case '°':
				enter++;
				continue;
			default:
				printf("%c", text.at(i));
				break;
			}

			limit++;
		}
	}
}

void clear_text() {
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT);
	size_t enter = 0;
	for (size_t i = 0; i < 15; i++) {
		gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + enter);
		enter++;
		printf("                     ");
	}
}

void getCursorPosition(int& x, int& y) {
	// Obtenemos el handle del buffer de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		std::cerr << "Error al obtener el handle de la consola" << std::endl;
		return;
	}

	// Obtenemos la informaci6n del buffer de la consola
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	if (!GetConsoleScreenBufferInfo(hConsole, &consoleInfo)) {
		std::cerr << "Error al obtener la informaci6n del buffer de la consola" << std::endl;
		return;
	}

	// Obtenemos las coordenadas del cursor
	x = consoleInfo.dwCursorPosition.X;
	y = consoleInfo.dwCursorPosition.Y;
}

int generate_random_number(int min, int max) {
	// Obt4n una semilla basada en el tiempo actual
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Crea un motor de n7meros aleatorios con la semilla
	std::default_random_engine engine(seed);

	// Define la distribuci6n en el rango [x, y]
	std::uniform_int_distribution<int> distribution(min, max);

	// Genera y retorna el n7mero aleatorio
	return distribution(engine);
}