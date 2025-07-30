#include<conio.h>
#include<iostream>
#include<Windows.h>

#include "e1.h"

static std::vector<std::string*> create_e1() {
	std::string* e1_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaaw");
	std::string* e1_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytttwwyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyw");
	std::string* e1_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytttwwyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyw");
	std::string* e1_03 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyyyyyyyyyyyyyywwyyyw");
	std::string* e1_04 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyyyyyyyyyyyyyywwyyyw");
	std::string* e1_05 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyrryyyywwwwwyyyyyyywwyyyw");
	std::string* e1_06 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyrryyyyysywwyyyyyyywwyyyw");
	std::string* e1_07 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyrryyyyysywwyyyyyyywwyyyw");
	std::string* e1_08 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyrryyyywwwwwyyyyyyywwyyyw");
	std::string* e1_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyyyyyyyyyyyyyywwyyyw");
	std::string* e1_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyyyyyyyyyyyyyywwyyyd");
	std::string* e1_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytttwwyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyd");
	std::string* e1_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytttwwyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyd");
	std::string* e1_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _e1 = { e1_00, e1_01, e1_02, e1_03, e1_04, e1_05, e1_06, e1_07,
	e1_08, e1_09, e1_10, e1_11, e1_12, e1_13 };

	return _e1;
}

static void event_e1_func() {

}

void initialize_items_e1(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Sacred Scroll (presione l para abrir)";
	Items* key = new Items(name, 's', 197, offset, name, 'p', {}, "");

	stage->add_item(key);
}

bool static trigger_e1(bool completed, Player* player) {
	static int use = 0;
	if (use == 2) return true;
	if (use == 0) {
		if (player->get_pos().y < 6 || player->get_pos().y > 7) {
			Position pos{};
			pos.x = -2;
			pos.y = 0;
			player->move(pos);
			return false;
		}

		clear_text();
		print_text("Nombre decodificado del primer guardi3n:");
		gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, 8);
		std::string name;
		std::cin >> name;
		if (name == "Mon") {
			use++;
			Position pos{};
			pos.x = -2;
			pos.y = 0;
			player->move(pos);
			clear_text();
			return false;
		} else {
			clear_text();
			print_text("El nombre del guardi3n es incorrecto!");
			Position pos{};
			pos.x = -2;
			pos.y = 0;
			player->move(pos);
			return false;
		}
	}

	if (use == 1) {
		gotoxy(5, 5);
		if (player->get_pos().y < 16 || player->get_pos().y > 17) {
			Position pos{};
			pos.x = -2;
			pos.y = 0;
			player->move(pos);
			return false;
		}
		clear_text();
		print_text("Nombre decodificado del segundo guardi3n:");
		gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, 7);
		std::string name;
		std::cin >> name;

		if (name == "Zau") {
			use++;
			Position pos{};
			pos.x = -2;
			pos.y = 0;
			player->move(pos);
			clear_text();
			print_text("Los guardianes te permiten el acceso al Sacred Scroll. Contin7a con cuidado...");
			Sleep(2500);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

			return true;
		}
		else {
			clear_text();
			print_text("El nombre del guardi3n es incorrecto!");
			Position pos{};
			pos.x = -2;
			pos.y = 0;
			player->move(pos);
			return false;
		}
	}
}

const static std::vector<std::string*> e1_map = create_e1();

Stage* initialize_e1() {
	Stage* stage_e1 = new Stage(e1_map, "E1");
	stage_e1->set_trigger(trigger_e1);
	initialize_items_e1(stage_e1);

	return stage_e1;
}