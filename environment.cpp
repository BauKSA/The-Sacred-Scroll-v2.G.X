#include<conio.h>
#include<iostream>
#include<mutex>
#include <random>
#include <ctime>
#include<Windows.h>

#include "Environment.h"

Stage* Environment::actual_stage = nullptr;

bool Environment::can_move(int coord_x, int coord_y) {
	char pos = Environment::actual_stage->get_position(coord_x, coord_y);
	if (pos == 'w' || pos == 'p' || pos == 'r') return false;
	else return true;
}

void Environment::add_stage(Stage* stage) {
	stages.at(stages.size() - 1).push_back(stage);
	if (stages.at(stages.size() - 1).size() == 5) {
		stages.push_back({});
	}
}

void Environment::init_stage(std::string stage_id) {
	for (size_t i = 0; i < stages.size(); i++) {
		std::vector<Stage*> row = stages.at(i);
		for (size_t j = 0; j < row.size(); j++) {
			Stage* stage = row.at(j);
			if (stage->get_id() == stage_id) {
				Environment::actual_stage = stage;
				Environment::actual_stage->active_event();
				Environment::actual_stage->draw();
				break;
			}
		}
	}
}

void Environment::change_stage(char dir) {
	clear_screen();
	loading_screen();
	for (size_t i = 0; i < stages.size(); i++) {
		std::vector<Stage*> row = stages.at(i);
		for (size_t j = 0; j < row.size(); j++) {
			Stage* stage = row.at(j);
			if (stage->get_id() == Environment::actual_stage->get_id()) {
				Position* player_pos = new Position;
				switch (dir) {
				case 'i':
					Environment::actual_stage = row.at(j - 1);

					player_pos->x = actual_player->get_pos().x + MAP_WIDTH - 5;
					player_pos->y = 0;

					Environment::actual_stage->active_event();
					actual_player->move(*player_pos);
					draw();

					return;
				case 'd':
					Environment::actual_stage = row.at(j + 1);

					player_pos->x = (MAP_WIDTH * -1) + 3;
					player_pos->y = 0;

					Environment::actual_stage->active_event();
					actual_player->move(*player_pos);
					draw();

					return;
				case 'a':
					Environment::actual_stage = stages.at(i - 1).at(j);

					player_pos->x = 0;
					player_pos->y = 12;

					Environment::actual_stage->active_event();
					actual_player->move(*player_pos);
					draw();

					return;
				case 'x':
					if (i < stages.size() - 1 && j < stages.at(i + 1).size()) {
						Environment::actual_stage = stages.at(i + 1).at(j);

						player_pos->x = 0;
						player_pos->y = -12;

						Environment::actual_stage->active_event();
						actual_player->move(*player_pos);
						draw();
					}

					return;
				default:
					return;
				}
			}

		}

	}
}

void Environment::add_player(Player* player) {
	actual_player = player;
}

void Environment::check_items(int x_pos, int y_pos) {
	const char icon = Environment::actual_stage->get_position(x_pos, y_pos);
	if (icon == 'w' || icon == 'y' || icon == 'r' || icon == 't') return;

	Items* item = nullptr;
	item = Environment::actual_stage->check_items(icon);

	if (item != nullptr && item->name != "password") {
		actual_player->add_items(item);
	}
	else if (item != nullptr && item->name == "password") {
		actual_player->add_password();
	}

	draw();
}

void Environment::check_trigger(int x_pos, int y_pos) {
	const char icon = Environment::actual_stage->get_position(x_pos, y_pos);
	if (icon == 't') {
		Environment::actual_stage->active_trigger();
		draw();
	}
	else return;
}

void Environment::tick() {
	if (!movement) return;
	if (_kbhit() && movement) {
		const int key = _getch();
		Position* added_position = new Position;
		added_position->x = 0;
		added_position->y = 0;

		switch (key) {
		case RIGHT:
			added_position->x = 1;
			added_position->y = 0;
			break;
		case LEFT:
			added_position->x = -1;
			added_position->y = 0;
			break;
		case DOWN:
			added_position->x = 0;
			added_position->y = 1;
			break;
		case UP:
			added_position->x = 0;
			added_position->y = -1;
			break;
		case ACTION:
			check_scroll();
			check_doors();
			break;
		default:
			break;
		}

		if (actual_player != nullptr) {
			if (temp_player_items != actual_player->get_items().size()) {
				temp_player_items = actual_player->get_items().size();
				draw();
			}

			int player_x_in_map = actual_player->get_pos().x - MAP_X_INIT;
			int player_y_in_map = actual_player->get_pos().y - MAP_Y_INIT;
			if (can_move(player_x_in_map + added_position->x, player_y_in_map + added_position->y)) {
				actual_player->move(*added_position);
				clear_text();

				player_x_in_map = actual_player->get_pos().x - MAP_X_INIT;
				player_y_in_map = actual_player->get_pos().y - MAP_Y_INIT;
				check_items(player_x_in_map, player_y_in_map);
				check_trigger(player_x_in_map, player_y_in_map);
				cursorVisible(false);
				switch (Environment::actual_stage->get_position(player_x_in_map, player_y_in_map)) {
				case 'i':
					change_stage('i');
					break;
				case 'd':
					change_stage('d');
					break;
				case 'a':
					change_stage('a');
					break;
				case 'x':
					change_stage('x');
					break;
				case 'q':
					gotoxy(0, 0);
					teleport();
					break;
				default:
					break;
				}

				draw_stage();
			}
		}

		delete added_position;
	}
}

void Environment::draw_dynamics() {
	_interface->draw(actual_player);
	draw_stage();
	draw_password();
}

void Environment::draw_stage() {
	gotoxy(80, 1);
	std::cout << "Stage: " << Environment::actual_stage->get_id();
}

void Environment::draw_password() {
	const int x = CREDITS + 30;
	int y = 2;

	gotoxy(x, 1);
	printf("Contrase%cas: %i/6", 164, actual_player->get_password_size());

	for (size_t i = 0; i < actual_player->get_password_size(); i++) {
		int sum = i;

		if (i > 2) {
			y = 3;
			sum = i - 3;
		}

		gotoxy(x + ((sum) * 9), y);
		std::cout << actual_player->get_current_password(i);
	}
}

void Environment::check_doors() {
	if (actual_player != nullptr) {
		int player_x_in_map = actual_player->get_pos().x - MAP_X_INIT;
		int player_y_in_map = actual_player->get_pos().y - MAP_Y_INIT;

		std::string door_id = "no hay puerta";
		std::string temp = "";

		//hay puerta a la derecha
		gotoxy(0, 3);
		temp = Environment::actual_stage->has_door(player_x_in_map + 1, player_y_in_map);
		if (temp != "no hay puerta") door_id = temp;
		//hay puerta a la izquierda
		gotoxy(0, 4);
		temp = Environment::actual_stage->has_door(player_x_in_map - 1, player_y_in_map);
		if (temp != "no hay puerta") door_id = temp;
		//hay puerta arriba
		gotoxy(0, 5);
		temp = Environment::actual_stage->has_door(player_x_in_map, player_y_in_map + 1);
		if (temp != "no hay puerta") door_id = temp;
		//hay puerta abajo
		gotoxy(0, 6);
		temp = Environment::actual_stage->has_door(player_x_in_map, player_y_in_map - 1);
		if (temp != "no hay puerta") door_id = temp;

		if (door_id != "no hay puerta") {
			if (actual_player->has_key(door_id)) {
				Environment::actual_stage->unlock_door(door_id);
				actual_player->throw_key(door_id);

				draw();
			}
		}

	}
}

void Environment::draw() {
	Environment::actual_stage->draw();
	clear_items();
	draw_dynamics();
	actual_player->draw(false);

}

void Environment::clear_items() {
	std::vector<Items*> items = actual_player->get_items();
	int y = 0;
	for (size_t i = 0; i < 9; i++) {
		if (y % 3 == 0) y++;
		gotoxy(ITEMS_1_X + (10 * i), ITEMS_1_Y + y);
		std::cout << "               ";
	}

	if (items.size() <= 0) {
		gotoxy(ITEMS_1_X, ITEMS_1_Y);
		std::cout << "          ";
	}
}

void Environment::clear_screen() {
	gotoxy(0, 0);
	for (size_t i = 0; i < HEIGHT * 2; i++) {
		for (size_t j = 0; j < WIDTH; j++) {
			printf(" ");
		}
	}
}

void Environment::loading_screen() {
	movement = false;
	_interface->draw_borders();
	_interface->draw_title();

	gotoxy(30, 15);
	printf("Cargando...");
	Sleep(500);
	gotoxy(30, 15);
	printf("           ");
	Sleep(100);

	// Vaciar el b7fer de entrada del teclado
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	movement = true;
}

void Environment::teleport() {
	int x{};
	int y{};

	x = Environment::actual_stage->get_teleport().x - actual_player->get_pos().x;

	if (Environment::actual_stage->get_teleport().y == 0)
		y = 0;
	else y = Environment::actual_stage->get_teleport().y - actual_player->get_pos().y;

	Position pos{};
	pos.x = x;
	pos.y = y;

	actual_player->move(pos);
	actual_player->draw(true);
	int player_x_in_map = actual_player->get_pos().x - MAP_X_INIT;
	int player_y_in_map = actual_player->get_pos().y - MAP_Y_INIT;

	cursorVisible(false);
	bool changed = false;

	switch (Environment::actual_stage->get_position(player_x_in_map, player_y_in_map)) {
	case 'i':
		change_stage('i');
		changed = true;
		break;
	case 'd':
		change_stage('d');
		changed = true;
		break;
	case 'a':
		change_stage('a');
		changed = true;
		break;
	case 'x':
		change_stage('x');
		changed = true;
		break;
	default:
		break;
	}

	if (!changed) return;

	x = Environment::actual_stage->get_teleport_init().x - actual_player->get_pos().x;

	if (Environment::actual_stage->get_teleport_init().y == 0)
		y = 0;
	else y = Environment::actual_stage->get_teleport_init().y - actual_player->get_pos().y;

	pos.x = x;
	pos.y = y;

	actual_player->move(pos);
	Environment::actual_stage->draw();
	actual_player->draw(false);
}