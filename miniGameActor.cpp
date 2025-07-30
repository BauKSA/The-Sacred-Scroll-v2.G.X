#include "MiniGameActor.h"

std::mutex miniGame_mutex;

void MiniGameActor::draw(bool erase) const {
	std::lock_guard<std::mutex> lock(miniGame_mutex);

	gotoxy(x, y);

	if (erase) printf(" ");
	else printf("%c", icon);
}

/*
0 -> abajo
1 -> arriba
2 -> derecha
3 -> izquierda
*/

void MiniGameActor::move(int direction) {
	if (direction < 0 || direction > 3) return;
	switch (direction) {
	default:
		return;
	case 0:
		draw(true);
		y++;
		draw(false);
		break;
	case 1:
		draw(true);
		y--;
		draw(false);
		break;
	case 2:
		draw(true);
		x++;
		draw(false);
		break;
	case 3:
		draw(true);
		x--;
		draw(false);
		break;
	}
}

void MiniGameActor::set_position(int _x, int _y) {
	draw(true);
	x = _x;
	y = _y;
	draw(false);
}