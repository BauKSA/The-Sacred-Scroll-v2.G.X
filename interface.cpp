#include<stdio.h>
#include<iostream>

#include "Interface.h"
#include "Functions.h"

void Interface::draw_borders() {
	//arrancamos dibujando los bordes externos
	gotoxy(0, 0);
	for (size_t i = 0; i < WIDTH; i++) {
		printf("%c", 205);
	}

	gotoxy(0, HEIGHT);
	for (size_t i = 0; i < WIDTH; i++) {
		printf("%c", 205);
	}

	gotoxy(0, 0);
	for (size_t i = 0; i < HEIGHT; i++) {
		gotoxy(0, i);
		printf("%c", 186);
	}

	gotoxy(WIDTH, HEIGHT);
	for (size_t i = 0; i < HEIGHT; i++) {
		gotoxy(WIDTH, i);
		printf("%c", 186);
	}

	//dibujamos las esquinas
	gotoxy(WIDTH, HEIGHT);
	printf("%c", 188);

	gotoxy(0, 0);
	printf("%c", 201);

	gotoxy(0, HEIGHT);
	printf("%c", 200);

	gotoxy(WIDTH, 0);
	printf("%c", 187);

	//dibujamos la segunda barra horizontal
	gotoxy(0, SECOND_HORIZONTAL_BAR);
	for (size_t i = 0; i < WIDTH; i++) {
		printf("%c", 205);
	}

	//dibujo sus conexiones
	gotoxy(0, SECOND_HORIZONTAL_BAR);
	printf("%c", 204);

	gotoxy(WIDTH, SECOND_HORIZONTAL_BAR);
	printf("%c", 185);

	//dibujamos la tercera barra horizontal
	gotoxy(0, THIRD_HORIZONTAL_BAR);
	for (size_t i = 0; i < THIRD_HORIZONTAL_BAR_WIDTH; i++) {
		printf("%c", 205);
	}

	//dibujamos su conexi6n
	gotoxy(0, THIRD_HORIZONTAL_BAR);
	printf("%c", 204);

	//dibujamos la segunda barra horizontal
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH, SECOND_HORIZONTAL_BAR);
	for (size_t i = 0; i < SECOND_COLUMN; i++) {
		gotoxy(THIRD_HORIZONTAL_BAR_WIDTH, i + SECOND_HORIZONTAL_BAR);
		printf("%c", 186);
	}

	//dibujamos las conexiones
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH, HEIGHT);
	printf("%c", 202);

	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH, SECOND_HORIZONTAL_BAR);
	printf("%c", 203);

	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH, THIRD_HORIZONTAL_BAR);
	printf("%c", 185);

	cursorVisible(false);
}

void Interface::draw_title() {
	//arrancamos dibujando el recuadro
	gotoxy(1, 1);
	for (size_t i = 0; i < TITLE_WIDTH; i++) {
		printf("%c", 196);
	}

	gotoxy(1, TITLE_HEIGHT);
	for (size_t i = 0; i < TITLE_WIDTH; i++) {
		printf("%c", 196);
	}

	//dibujamos los horizontales
	gotoxy(1, 1);
	printf("%c", 218);

	gotoxy(1, 2);
	printf("%c", 179);

	gotoxy(1, TITLE_HEIGHT);
	printf("%c", 192);

	gotoxy(TITLE_WIDTH, 1);
	printf("%c", 191);

	gotoxy(TITLE_WIDTH, 2);
	printf("%c", 179);

	gotoxy(TITLE_WIDTH, TITLE_HEIGHT);
	printf("%c", 217);

	//dibujamos el titulo
	gotoxy(2, 2);
	printf(" THE SACRED SCROLL ");

	//dibujamos los creditos
	gotoxy(CREDITS, 1);
	printf("BAUTISTA MANOLIZI");
	gotoxy(CREDITS, 3);
	printf("%c jul 2025 v2.G.2", 184);
}

void Interface::draw_game_info() {
	//primero dibujamos el titulo de items

}

void Interface::draw_items(Player* player) {
	gotoxy(2, ITEMS);
	printf("%c ITEMS:", 158);

	std::vector<Items*> items = player->get_items();
	int y = ITEMS_1_Y;
	for (size_t i = 0; i < items.size(); i++) {
		if (i % 3 == 0) y++;
		gotoxy(ITEMS_1_X + (15 * (i % 3)), y);
		printf("%c ", 250);
		for (size_t j = 0; j < items.at(i)->name.size(); j++) {
			if(items.at(i)->name.at(j) == '8')printf("%c", 164);
			else printf("%c", items.at(i)->name.at(j));
		}
		printf("  ");
	}
}

void Interface::draw(Player* player) {
	draw_borders();
	draw_title();
	draw_game_info();
	draw_items(player);
}