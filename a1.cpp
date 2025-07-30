#include<conio.h>
#include<iostream>
#include<thread>
#include<Windows.h>

#include "a1.h"
#include "A1MiniGame.h"

static std::vector<std::string*> create_a1() {
	std::string* a1_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a1_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_02 = new std::string("wyywwwywyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy*yyyw");
	std::string* a1_03 = new std::string("wyywywywwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_04 = new std::string("wyywwyywywywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_05 = new std::string("wyywywywyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_06 = new std::string("wyywwwywyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_07 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_08 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_12 = new std::string("wyyyywyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a1_13 = new std::string("wwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _a1 = { a1_00, a1_01, a1_02, a1_03, a1_04, a1_05, a1_06, a1_07,
	a1_08, a1_09, a1_10, a1_11, a1_12, a1_13 };

	return _a1;
}

static void add_lifts(A1MiniGame* miniGame) {
	std::vector<Obstacle*> lifts{};
	Obstacle* obstacle1 = new Obstacle(15, 9);
	Obstacle* obstacle1a = new Obstacle(15, 10);
	Obstacle* obstacle1b = new Obstacle(15, 11);

	Obstacle* obstacle2 = new Obstacle(17, 12);
	Obstacle* obstacle2a = new Obstacle(17, 11);
	Obstacle* obstacle2b = new Obstacle(17, 9);

	Obstacle* obstacle3 = new Obstacle(19, 10);
	Obstacle* obstacle3a = new Obstacle(19, 11);
	Obstacle* obstacle3b = new Obstacle(19, 12);

	Obstacle* obstacle4 = new Obstacle(21, 9);
	Obstacle* obstacle4a = new Obstacle(21, 10);
	Obstacle* obstacle4b = new Obstacle(21, 11);

	Obstacle* obstacle5 = new Obstacle(23, 9);
	Obstacle* obstacle5a = new Obstacle(23, 11);
	Obstacle* obstacle5b = new Obstacle(23, 12);

	miniGame->add_obstacles(obstacle1);
	miniGame->add_obstacles(obstacle1a);
	miniGame->add_obstacles(obstacle1b);

	miniGame->add_obstacles(obstacle2);
	miniGame->add_obstacles(obstacle2a);
	miniGame->add_obstacles(obstacle2b);

	miniGame->add_obstacles(obstacle3);
	miniGame->add_obstacles(obstacle3a);
	miniGame->add_obstacles(obstacle3b);

	miniGame->add_obstacles(obstacle4);
	miniGame->add_obstacles(obstacle4a);
	miniGame->add_obstacles(obstacle4b);

	miniGame->add_obstacles(obstacle5);
	miniGame->add_obstacles(obstacle5a);
	miniGame->add_obstacles(obstacle5b);
}

static void draw_limits() {
	for (size_t i = 1; i < 76; i++) {
		gotoxy(i + 1, 8);
		printf("%c", 196);
		gotoxy(i + 1, 13);
		printf("%c", 196);
	}

	for (size_t i = 9; i < 13; i++) {
		gotoxy(75, i);
		printf("%c", 176);
		gotoxy(76, i);
		printf("%c", 176);
	}

	gotoxy(15, 7);
	printf("%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(15, 14);
	printf("%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 217);
}

static void check_inputs(A1Player* player, A1MiniGame* miniGame, MovementSystem* system) {
	while (miniGame->is_running()) {
		if (_kbhit()) {
			const int key = _getch();
			switch (key) {
			default:
				break;
			case UP:
				player->move_queue('w');
				break;
			case DOWN:
				player->move_queue('s');
				break;
			case RIGHT:
				player->move_queue('d');
				break;
			case LEFT:
				player->move_queue('a');
				break;
			}
		}
	}
}

static void event_a1_func() {
	A1MiniGame* miniGame = new A1MiniGame;
	A1Player* player = new A1Player(10, 11);
	MovementSystem* movementSystem = new MovementSystem;
	movementSystem->add_actor(player);
	miniGame->add_movement_system(movementSystem);
	add_lifts(miniGame);
	draw_limits();
	miniGame->add_player(player);

	miniGame->init();


	// Crear hilos una sola vez fuera del bucle
	std::thread input_thread(check_inputs, player, miniGame, movementSystem);

	while (miniGame->is_running()) {
		miniGame->tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Evitar CPU 100%
	}

	// Esperar a que los hilos terminen antes de salir
	if (input_thread.joinable()) {
		input_thread.join();
	}

	delete miniGame;

	// Vaciar el b7fer de entrada del teclado
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	clear_text();
	print_text("Desaf5o completado!");
	std::this_thread::sleep_for(std::chrono::milliseconds(1750));
}

void initialize_items_a1(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	Items* pass = new Items("password", '*', 207, offset, "password", 'p', {}, "");

	stage->add_item(pass);
}

void static trigger_a1() {

}

const static std::vector<std::string*> a1_map = create_a1();

Stage* initialize_a1() {
	Stage* stage_a1 = new Stage(a1_map, "A1");

	Event* event_a1 = new Event(event_a1_func);
	stage_a1->set_event(event_a1);
	initialize_items_a1(stage_a1);

	return stage_a1;
}