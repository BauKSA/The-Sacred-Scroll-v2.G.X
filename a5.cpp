#include<conio.h>
#include<iostream>

#include "a5.h"

static std::vector<std::string*> create_a5() {
	std::string* a5_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_01 = new std::string("wyyyyyyyyyyyyyyyttyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_02 = new std::string("wyyyyyyyyyyyyyyyttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_03 = new std::string("wwyyyyyyyyyyyyyyttyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_04 = new std::string("iyyyyyyyyyyyyyyyttyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_05 = new std::string("iyyyyyyyyyyyyyyyttyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_06 = new std::string("iyyyyyyyyyyyyyyyttykyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_07 = new std::string("wwyyyyyyyyyyyyyyttyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_08 = new std::string("wyyyyyyyyyyyyyyyttyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_09 = new std::string("wyyyyyyyyyyyyyyyttyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_10 = new std::string("wyyyyyyyyyyyyyyyttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_11 = new std::string("wyyyyyyyyyyyyyyyttyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_12 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a5_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _a5 = { a5_00, a5_01, a5_02, a5_03, a5_04, a5_05, a5_06, a5_07,
	a5_08, a5_09, a5_10, a5_11, a5_12, a5_13 };

	return _a5;
}

static void event_a5_func() {

}

void initialize_items_a5(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Llave B3";
	Items* key = new Items(name, 'k', 244, offset, name, 'p', {}, "puerta_b3");
	stage->add_item(key);
}

bool static trigger_a5(bool completed, Player* player = nullptr) {
	print_text("Muchas veces, las llaves no son 7tiles en donde las encontraste...");

	return true;
}

const static std::vector<std::string*> a5_map = create_a5();

Stage* initialize_a5() {
	Stage* stage_a5 = new Stage(a5_map, "A5");
	stage_a5->set_trigger(trigger_a5);
	initialize_items_a5(stage_a5);

	return stage_a5;
}