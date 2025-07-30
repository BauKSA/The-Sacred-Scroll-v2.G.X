#include<conio.h>
#include<iostream>

#include "d2.h"

static std::vector<std::string*> create_d2() {
	std::string* d2_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d2_01 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyyttttttwwwyyywww");
	std::string* d2_02 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyyttttttwwwyyywww");
	std::string* d2_03 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwyyyyyyyyywwwtttwwwyyywwwyyywwwyyyttttytwwwyyywww");
	std::string* d2_04 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwtttwwwyyywwwyyywwwyyytttyyyyyyyyywww");
	std::string* d2_05 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwttywwwyyywwwyyyyyyyyywwwyyywwwyyytttytywwwyyywww");
	std::string* d2_06 = new std::string("wwwyyywwwyyyyyyyyytttyyywwwttywwwyyywwwyttwwwyyywwwyyytttyyytttytywwwyyyyyd");
	std::string* d2_07 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwttywwwyyywwwyttwwwyyytttyyyyyyyyytttytywwwyyyyyd");
	std::string* d2_08 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwttywwwyyyyyyyttwwwyyywwwyyytttyyytttytywwwyyyyyd");
	std::string* d2_09 = new std::string("wwwyyywwwyyywwwyyyyyyyyywwwyyywwwyyywwwyttwwwyyywwwyyywwwyyyyyyytywwwyyywww");
	std::string* d2_10 = new std::string("wwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywwwyyyyyyyyywwwyyywwwytywwwyyywww");
	std::string* d2_11 = new std::string("wwwyyyyyyyyytttyyywwwyyywwwyyywwwtttwwwyyywwwyyywwwyyywwwyyywwwytywwwyyywww");
	std::string* d2_12 = new std::string("wwwyyywwwyyywwwyyywwwyyyyyyyyywwwtttwwwyyywwwyyywwwyyywwwyyywwwyyywwwyyywww");
	std::string* d2_13 = new std::string("wwwwxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _d2 = { d2_00, d2_01, d2_02, d2_03, d2_04, d2_05, d2_06, d2_07,
	d2_08, d2_09, d2_10, d2_11, d2_12, d2_13 };

	return _d2;
}

static void event_d2_func() {

}

void initialize_items_d2(Stage* stage) {

}

bool static trigger_d2(bool completed, Player* player) {
	const int x_init = 6;

	Position added_position{};
	added_position.x = (player->get_pos().x - x_init) * -1;
	added_position.y = 0;

	player->move(added_position);
	return false;
}

const static std::vector<std::string*> d2_map = create_d2();

Stage* initialize_d2() {
	Stage* stage_d2 = new Stage(d2_map, "D2");
	stage_d2->set_trigger(trigger_d2);

	return stage_d2;
}