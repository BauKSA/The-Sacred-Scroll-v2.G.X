#include<conio.h>
#include<iostream>
#include<thread>
#include<windows.h>
#include<memory>

#include "a2.h"
#include "A2MiniGame.h"
#include "Functions.h"

static std::vector<std::string*> create_a2() {
	std::string* a2_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a2_01 = new std::string("wwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_02 = new std::string("wwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_03 = new std::string("wwwwwwwwwwyyyyyyyyyyyyyyyyyyytttttwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_04 = new std::string("wwwwwwwwwwwyyyyyyyyyyyyyyyyyyttwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyww");
	std::string* a2_05 = new std::string("wwwwwwwwwwwwyyyyyyyyyyyyyyyyyttwtwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* a2_06 = new std::string("wwwwwwwwwwwyyyyyyyyyyyyyyyyyyttwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* a2_07 = new std::string("wwwwwwwwwwyyyyyyyyyyyyyyyyyyytttttwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* a2_08 = new std::string("wwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyww");
	std::string* a2_09 = new std::string("wwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_10 = new std::string("wwwwwwwwwyyyyywwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_11 = new std::string("wwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_12 = new std::string("wwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a2_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxw");

	std::vector<std::string*> _a2 = { a2_00, a2_01, a2_02, a2_03, a2_04, a2_05, a2_06, a2_07,
	a2_08, a2_09, a2_10, a2_11, a2_12, a2_13 };

	return _a2;
}

std::mutex a2_mutex_main;

static void spawn_enemies(A2MiniGame* miniGame) {
	int milisec = 1250;
	while (miniGame->is_running()) {
		{
			std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(
				75, generate_random_number(MAP_Y_INIT, THIRD_HORIZONTAL_BAR - 1)
			);
			std::lock_guard<std::mutex> lock(a2_mutex_main);
			miniGame->add_enemy(std::move(enemy));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
	}
}

static void inGame(A2MiniGame* miniGame) {
	int x = 3;
	int y = 15;

	MiniGamePlayer* miniGamePlayer = new MiniGamePlayer(x, y);
	miniGame->add_player(miniGamePlayer);

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	while (miniGame->is_running()) {
		if (_kbhit()) {
			const int key = _getch();
			switch (key) {
			case UP:
				if (miniGamePlayer->get_y() - 1 > SECOND_HORIZONTAL_BAR) {
					std::lock_guard<std::mutex> lock(a2_mutex_main);
					miniGamePlayer->move_up();
				}
				break;
			case DOWN:
				if (miniGamePlayer->get_y() + 1 < THIRD_HORIZONTAL_BAR) {
					std::lock_guard<std::mutex> lock(a2_mutex_main);
					miniGamePlayer->move_down();
				}
				break;
			case ACTION: {
				std::unique_ptr<A2Bullet> bullet =
					std::make_unique<A2Bullet>(x + 1, miniGamePlayer->get_y());
				std::lock_guard<std::mutex> lock(a2_mutex_main);
				miniGame->add_bullet(std::move(bullet));
				break;
			}
			default:
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

static void event_a2_func() {
	A2MiniGame* miniGame = new A2MiniGame;

	std::thread player_thread(inGame, miniGame);
	std::thread objects_thread(&A2MiniGame::move_objects, miniGame);
	std::thread spawn_thread(spawn_enemies, miniGame);

	const int fps = 30;
	const auto frame_duration = std::chrono::milliseconds(1000 / fps);

	while (miniGame->get_points() < 500) {
		{
			std::lock_guard<std::mutex> lock(a2_mutex_main);
			miniGame->redraw();
		}
		std::this_thread::sleep_for(frame_duration);
	}

	miniGame->stop_threads();

	if (objects_thread.joinable()) objects_thread.join();
	if (spawn_thread.joinable()) spawn_thread.join();
	if (player_thread.joinable()) player_thread.join();

	delete miniGame;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	clear_text();
	print_text("Desaf5o completado!");
	std::this_thread::sleep_for(std::chrono::milliseconds(1750));
}
void initialize_items_a2(Stage* stage) {

}

bool static trigger_a2(bool complete, Player* player = nullptr) {
	print_text("C6mo hab5an dicho...?? Que restar la contrase8a al nombre del guardi3n lo decodificaba..? Mmmm...");
	return true;
}

const static std::vector<std::string*> a2_map = create_a2();

Stage* initialize_a2() {
	Stage* stage_a2 = new Stage(a2_map, "A2");

	Event* event_a2 = new Event(event_a2_func);
	stage_a2->set_event(event_a2);
	stage_a2->set_trigger(trigger_a2);

	return stage_a2;
}