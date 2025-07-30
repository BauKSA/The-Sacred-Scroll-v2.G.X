#include<conio.h>
#include<iostream>
#include<Windows.h>

#include "b1.h"

static std::vector<std::string*> create_b1() {
	std::string* b1_00 = new std::string("wwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b1_01 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyw");
	std::string* b1_02 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyw");
	std::string* b1_03 = new std::string("wyyyyyyywwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwyyyyyyyyyw");
	std::string* b1_04 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* b1_05 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* b1_06 = new std::string("wyyyyyyywwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwyyyyyyyyyw");
	std::string* b1_07 = new std::string("wttttttttwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyw");
	std::string* b1_08 = new std::string("wrrrrrrrrwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyw");
	std::string* b1_09 = new std::string("wrrrrrrrrwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwyyyw");
	std::string* b1_10 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyw");
	std::string* b1_11 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyw");
	std::string* b1_12 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyw");
	std::string* b1_13 = new std::string("wwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxw");

	std::vector<std::string*> _b1 = { b1_00, b1_01, b1_02, b1_03, b1_04, b1_05, b1_06, b1_07,
	b1_08, b1_09, b1_10, b1_11, b1_12, b1_13 };

	return _b1;
}

static void event_b1_func() {

}

void initialize_items_b1(Stage* stage) {

}

bool static trigger_b1(bool completed, Player* player) {
	static bool used = false;
	if (used) return false;

	clear_text();
	if (player->get_password_size() == 6) {
		print_text("Veo que ya conseguiste las seis contrase8as... pod4s pasar, pero no te van a servir de nada si no las decodific3s!");
		Sleep(2500);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

		used = true;
		return true;
	} else {
		Position pos{};
		pos.x = 0;
		pos.y = -1;
		player->move(pos);
		print_text("No pod4s pasar si no ten4s las seis contrase8as!");
		return false;
	}
}

const static std::vector<std::string*> b1_map = create_b1();

Stage* initialize_b1() {
	Stage* stage_b1 = new Stage(b1_map, "B1");
	stage_b1->set_trigger(trigger_b1);

	return stage_b1;
}