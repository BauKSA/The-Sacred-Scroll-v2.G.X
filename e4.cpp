#include<conio.h>
#include<iostream>
#include<vector>

#include "e4.h"

static std::vector<std::string*> create_e4() {
	std::string* e4_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e4_01 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_02 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwtyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_03 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_04 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_05 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_06 = new std::string("irrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_07 = new std::string("irrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e4_08 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e4_09 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e4_10 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_11 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwtyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_12 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e4_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _e4 = { e4_00, e4_01, e4_02, e4_03, e4_04, e4_05, e4_06, e4_07,
	e4_08, e4_09, e4_10, e4_11, e4_12, e4_13 };

	return _e4;
}

static void event_e4_func() {

}

void initialize_items_e4(Stage* stage) {

}

bool static trigger_e4(bool completed, Player* player) {
	static bool used = false;
	if (used) return false;

	std::vector<Items*> items = player->get_items();
	for (size_t i = 0; i < items.size(); i++) {
		if (items.at(i)->name == "Medalla E4") {
			player->delete_items("Medalla E4");
			clear_text();
			print_text("Pasadizo descubierto");
			return true;
		}
	}

	return false;

}

const static std::vector<std::string*> e4_map = create_e4();

Stage* initialize_e4() {
	Stage* stage_e4 = new Stage(e4_map, "E4");
	stage_e4->set_trigger(trigger_e4);

	return stage_e4;
}