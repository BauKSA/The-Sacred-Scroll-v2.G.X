#include<conio.h>
#include<iostream>

#include "d5.h"

static std::vector<std::string*> create_d5() {
	std::string* d5_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d5_01 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d5_02 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d5_03 = new std::string("wyyyyyyyywwyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwww");
	std::string* d5_04 = new std::string("wyyyyyyyywwyyyyyyyyyyywwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwww");
	std::string* d5_05 = new std::string("wyyyyyywwwwyyyyyyyyyyyywwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwww");
	std::string* d5_06 = new std::string("wyyyyyyttttyyyyyyyyyyyyywwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwww");
	std::string* d5_07 = new std::string("wyy*yyyttttyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwww");
	std::string* d5_08 = new std::string("wyyyyyyttttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwww");
	std::string* d5_09 = new std::string("wyyyyyywwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwww");
	std::string* d5_10 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* d5_11 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwww");
	std::string* d5_12 = new std::string("wyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwww");
	std::string* d5_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxwwww");

	std::vector<std::string*> _d5 = { d5_00, d5_01, d5_02, d5_03, d5_04, d5_05, d5_06, d5_07,
	d5_08, d5_09, d5_10, d5_11, d5_12, d5_13 };

	return _d5;
}

static void event_d5_func() {

}

void initialize_items_d5(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	Items* pass = new Items("password", '*', 207, offset, "password", 'p', {}, "");

	stage->add_item(pass);
}

bool static trigger_d5(bool completed, Player* player) {
	static bool used = false;
	if (used) return true;

	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Medalla E4";
	Items* key = new Items(name, 'k', 244, offset, name, 'p', {}, "");
	player->add_items(key);
	print_text("Con esto vas a poder abrir el pasillo oculto en E¿4!");

	used = true;
	return true;
}

const static std::vector<std::string*> d5_map = create_d5();

Stage* initialize_d5() {
	Stage* stage_d5 = new Stage(d5_map, "D5");
	stage_d5->set_trigger(trigger_d5);
	initialize_items_d5(stage_d5);

	return stage_d5;
}