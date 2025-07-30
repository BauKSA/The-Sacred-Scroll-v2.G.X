#include<conio.h>
#include<iostream>

#include "b2.h"

static std::vector<std::string*> create_b2() {
	std::string* b2_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaaw");
	std::string* b2_01 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyywwyyywwyyyw");
	std::string* b2_02 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyykywwyyywwyyyw");
	std::string* b2_03 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyywwyyywwyyyw");
	std::string* b2_04 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyywwyyyw");
	std::string* b2_05 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytttywwyyyryyyyw");
	std::string* b2_06 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyttwywwyyyryyyyw");
	std::string* b2_07 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyttwywwyyyryyyyw");
	std::string* b2_08 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyytttywwyyyryyyyw");
	std::string* b2_09 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywyyywwyyyw");
	std::string* b2_10 = new std::string("wwwwwwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyywwyyyw");
	std::string* b2_11 = new std::string("wwwwwwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyywwyyyw");
	std::string* b2_12 = new std::string("wwwwwwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyywwyyyw");
	std::string* b2_13 = new std::string("wwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _b2 = { b2_00, b2_01, b2_02, b2_03, b2_04, b2_05, b2_06, b2_07,
	b2_08, b2_09, b2_10, b2_11, b2_12, b2_13 };

	return _b2;
}

static void event_b2_func() {

}

void initialize_items_b2(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Ca8on";
	Items* weapon = new Items(name, 'k', 170, offset, name, 'x', {}, "");

	stage->add_item(weapon);
}

bool static trigger_b2(bool has_items, Player* player = nullptr) {
	if (has_items) {
		print_text("Es peligroso seguir avanzando sin un arma como defensa! Te recomiendo llevar una encima...");
		return false;
	} else {
		print_text("Pod4s pasar...");
		return true;
	}
}

const static std::vector<std::string*> b2_map = create_b2();

Stage* initialize_b2() {
	Stage* stage_b2 = new Stage(b2_map, "B2");
	initialize_items_b2(stage_b2);
	stage_b2->set_trigger(trigger_b2);

	return stage_b2;
}