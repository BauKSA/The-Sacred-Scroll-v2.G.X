#pragma once
#include "Functions.h"
#include "Interface.h"

#ifndef init_interface
#define init_interface
Interface* initialize_interface() {
	gotoxy(0, 0);
	Interface* gameInterface = new Interface();
	gameInterface->draw_borders();
	gameInterface->draw_title();
	gameInterface->draw_game_info();

	return gameInterface;
}
#endif // !init_interface
