#include<stdio.h>
#include<Windows.h>

#include "Actor.h"

void Actor::draw(bool empty) const {
	gotoxy(position.x, position.y);

	if (empty) {
		printf(" ");
		Sleep(10);
	} else {
		printf("%c", body);
	}
}

void Actor::move(Position added_position) {
	gotoxy(position.x, position.y);
	draw(true);
	position.x += added_position.x;
	position.y += added_position.y;
	gotoxy(position.x, position.y);
	draw(false);
}