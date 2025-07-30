#pragma once
#include "Globals.h"
#include "Player.h"

class Interface {
public:
	void draw_borders();
	void draw_title();
	void draw_game_info();
	void draw_items(Player* player);
	void draw(Player* player);
};