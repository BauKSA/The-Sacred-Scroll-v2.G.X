#include<conio.h>
#include<iostream>
#include<thread>
#include<windows.h>

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

std::mutex enemies_mutex;

static void spawn_enemies(A2MiniGame* miniGame) {
	int milisec = 1250;
	int change = 0;
	while (miniGame->is_running()) {
		{
			std::lock_guard<std::mutex> lock(enemies_mutex);
			Enemy* enemy = new Enemy(75, generate_random_number(MAP_Y_INIT, THIRD_HORIZONTAL_BAR - 1));
			miniGame->add_enemy(enemy);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
	}
}

static void inGame(A2MiniGame* miniGame) {
	int x = 3;
	int y = 15;

	MiniGamePlayer* miniGamePlayer = new MiniGamePlayer(x, y);
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
				if (miniGamePlayer->get_y() - 1 <= SECOND_HORIZONTAL_BAR) break;
				else miniGamePlayer->move_up();
				break;
			case DOWN:
				if (miniGamePlayer->get_y() + 1 >= THIRD_HORIZONTAL_BAR) break;
				else miniGamePlayer->move_down();
				break;
			case ACTION:
				A2Bullet* bullet = new A2Bullet(x + 1, miniGamePlayer->get_y());
				miniGame->add_bullet(bullet);
				break;
			}
		}
	}
}

static void event_a2_func() {
	A2MiniGame* miniGame = new A2MiniGame;


	// Crear hilos una sola vez fuera del bucle
	std::thread player_thread(inGame, miniGame);
	std::thread bullet_thread(&A2MiniGame::move_bullets, miniGame);
	std::thread enemy_thread(&A2MiniGame::move_enemies, miniGame);
	std::thread spawn_thread(spawn_enemies, miniGame);

	while (miniGame->get_points() < 500) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Evitar CPU 100%
	}

	// Detener los hilos
	miniGame->stop_threads();

	// Esperar a que los hilos terminen antes de salir
	if (bullet_thread.joinable()) {
		bullet_thread.join();
	}
	if (enemy_thread.joinable()) {
		enemy_thread.join();
	}
	if (spawn_thread.joinable()) {
		spawn_thread.join();
	}
	if (player_thread.joinable()) {
		player_thread.join();
	}

	delete miniGame;

	// Vaciar el b7fer de entrada del teclado
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