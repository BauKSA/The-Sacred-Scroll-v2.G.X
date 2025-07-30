#include<conio.h>
#include<iostream>
#include<thread>
#include<windows.h>

#include "E5Minigame.h"
#include "e5.h"

static std::vector<std::string*> create_e5() {
	std::string* e5_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaawwww");
	std::string* e5_01 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwww");
	std::string* e5_02 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwww");
	std::string* e5_03 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwww");
	std::string* e5_04 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwww");
	std::string* e5_05 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwww");
	std::string* e5_06 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwww");
	std::string* e5_07 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwww");
	std::string* e5_08 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwww");
	std::string* e5_09 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwww");
	std::string* e5_10 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e5_11 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e5_12 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e5_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _e5 = { e5_00, e5_01, e5_02, e5_03, e5_04, e5_05, e5_06, e5_07,
	e5_08, e5_09, e5_10, e5_11, e5_12, e5_13 };

	return _e5;
}

static void inGame(E5MiniGame* miniGame) {
	int x = 7;
	int y = SECOND_HORIZONTAL_BAR + 7;

	E5MiniGamePlayer* miniGamePlayer = new E5MiniGamePlayer(x, y);
	miniGame->add_player(miniGamePlayer);

	miniGamePlayer->draw(false);

	std::this_thread::sleep_for(std::chrono::milliseconds(150));

	while (miniGame->is_running()) {
		if (_kbhit()) {
			const int key = _getch();
			switch (key) {
			default:
				break;
			case UP:
				if (miniGamePlayer->get_y() - 1 <= SECOND_HORIZONTAL_BAR + 5) break;
				else miniGame->move_player(1);
				break;
			case DOWN:
				if (miniGamePlayer->get_y() + 1 >= THIRD_HORIZONTAL_BAR - 5) break;
				else miniGame->move_player(0);
				break;
			case RIGHT:
				if (miniGamePlayer->get_x() + 1 > MAP_WIDTH) break;
				else miniGame->move_player(2);
				break;
			case LEFT:
				if (miniGamePlayer->get_x() - 1 <= MAP_X_INIT) break;
				else miniGame->move_player(3);
				break;
			}
		}
	}
}

static void add_keys(E5MiniGame* miniGame) {
	Key* key_1 = new Key(14, SECOND_HORIZONTAL_BAR + 7);
	Key* key_2 = new Key(29, SECOND_HORIZONTAL_BAR + 7);
	Key* key_3 = new Key(38, THIRD_HORIZONTAL_BAR - 7);
	Key* key_4 = new Key(58, SECOND_HORIZONTAL_BAR + 7);
	Key* key_5 = new Key(73, THIRD_HORIZONTAL_BAR - 7);


	miniGame->add_key(key_1);
	miniGame->add_key(key_2);
	miniGame->add_key(key_3);
	miniGame->add_key(key_4);
	miniGame->add_key(key_5);
}

static void draw_screen() {
	gotoxy(MAP_X_INIT, SECOND_HORIZONTAL_BAR + 5);
	for (size_t j = 0; j < MAP_WIDTH; j++) {
		if (j % 5 != 0) printf("%c", 219);
		else printf(" ");
	}

	gotoxy(MAP_X_INIT, THIRD_HORIZONTAL_BAR - 5);
	for (size_t j = 0; j < MAP_WIDTH; j++) {
		if (j % 5 != 0) printf("%c", 219);
		else printf(" ");
	}

	for (size_t i = 0; i < 4; i++) {
		gotoxy(MAP_WIDTH, SECOND_HORIZONTAL_BAR + 6 + i);
		printf("%c", 176);
	}
}

static void add_blocks(E5MiniGame* miniGame) {
	int x = 7;
	for (size_t i = 0; i < 12; i++) {
		x += 5;
		int y = generate_random_number(SECOND_HORIZONTAL_BAR + 6, THIRD_HORIZONTAL_BAR - 6);

		Block* block = new Block(x, y, generate_random_number(0, 1));
		miniGame->add_block(block, x, y);
	}
}

static void event_e5_func() {
	E5MiniGame* miniGame = new E5MiniGame;

	draw_screen();
	add_blocks(miniGame);
	add_keys(miniGame);

	// Crear hilos una sola vez fuera del bucle
	std::thread block_thread(&E5MiniGame::move_blocks, miniGame);

	inGame(miniGame);

	// Detener los hilos
	miniGame->stop_threads();

	if (block_thread.joinable()) {
		block_thread.join();
	}

	delete miniGame;

	// Vaciar el b7fer de entrada del teclado
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	clear_text();
	print_text("Desaf5o completado!");
	std::this_thread::sleep_for(std::chrono::milliseconds(1750));
}

void initialize_items_e5(Stage* stage) {

}

void static trigger_e5() {

}

const static std::vector<std::string*> e5_map = create_e5();

Stage* initialize_e5() {
	Stage* stage_e5 = new Stage(e5_map, "E5");
	Event* event = new Event(event_e5_func);
	stage_e5->set_event(event);

	return stage_e5;
}