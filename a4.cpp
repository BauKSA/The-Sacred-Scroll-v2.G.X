#include<conio.h>
#include<iostream>

#include "a4.h"

static std::vector<std::string*> create_a4() {
	std::string* a4_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a4_01 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyttwwttwwyyyyyw");
	std::string* a4_02 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyttwwttwwyyyyyw");
	std::string* a4_03 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyttwwttwwyyyyww");
	std::string* a4_04 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyttwwwwwwyyyyyd");
	std::string* a4_05 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyttttttwwyyyyyd");
	std::string* a4_06 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyywwyyyyyd");
	std::string* a4_07 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyywwyyyyyyyyyyyyyywwyyyyww");
	std::string* a4_08 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyywwwyyyyyyyyyyyyyywwyyyyyw");
	std::string* a4_09 = new std::string("wwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyw");
	std::string* a4_10 = new std::string("wwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyryyyyyw");
	std::string* a4_11 = new std::string("wwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyryyyyyw");
	std::string* a4_12 = new std::string("wwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyryyyyyw");
	std::string* a4_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _a4 = { a4_00, a4_01, a4_02, a4_03, a4_04, a4_05, a4_06, a4_07,
	a4_08, a4_09, a4_10, a4_11, a4_12, a4_13 };

	return _a4;
}

static void event_a4_func() {

}

void initialize_items_a4(Stage* stage) {

}

bool static trigger_a4(bool completed, Player* player) {
	static bool used = false;
	clear_text();

	if (used) {
		print_text("Hola de vuelta. Pod4s pasar.");
		return true;
	}

	bool has_ticket = false;
	std::vector<Items*> player_items = player->get_items();
	for (size_t i = 0; i < player_items.size(); i++) {
		if (player_items.at(i)->name == "Pase A4") has_ticket = true;
	}

	if (!has_ticket) {
		print_text("Para pasar por ac3, necesit3s un pase!");
		return false;
	}

	print_text("Pod4s pasar!");
	player->delete_items("Pase A4");

	used = true;
	return true;
}

const static std::vector<std::string*> a4_map = create_a4();

Stage* initialize_a4() {
	Stage* stage_a4 = new Stage(a4_map, "A4");
	stage_a4->set_trigger(trigger_a4);

	return stage_a4;
}