#include<conio.h>
#include<iostream>

#include "a3.h"

static std::vector<std::string*> create_a3() {
	std::string* a3_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* a3_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* a3_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* a3_03 = new std::string("wyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* a3_04 = new std::string("wwyyyyyyyyywwyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyww");
	std::string* a3_05 = new std::string("iyyyyyyyyyywwyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a3_06 = new std::string("iyyyyyyyyyywwyyyyyyypyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a3_07 = new std::string("iyyyyyyyyyywwyyyyyyypyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a3_08 = new std::string("wwyyyyyyyyywwykyyyywwyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyw");
	std::string* a3_09 = new std::string("wyyyyyyyyyywwyyyyyywwyyyyywwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyw");
	std::string* a3_10 = new std::string("wyyyyyyyyyywwwwwwwwwwyyyyywwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a3_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyywwwwwyyyytttttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a3_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyywwwwwyyyytttttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* a3_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _a3 = { a3_00, a3_01, a3_02, a3_03, a3_04, a3_05, a3_06, a3_07,
	a3_08, a3_09, a3_10, a3_11, a3_12, a3_13 };

	return _a3;
}

static void event_a3_func() {

}

void initialize_items_a3(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Llave E2";
	Door* door = new Door("puerta_a3", 'p');
	Items* key = new Items(name, 'k', 244, offset, name, 'p', {}, "puerta_e2");

	stage->add_item(key);
	stage->add_door(door);
}

bool static trigger_a3(bool completed, Player* player = nullptr) {
	print_text("La salida del laberinto est3 oculta... no ser3 f3cil encontrarla");
	return true;
}

const static std::vector<std::string*> a3_map = create_a3();

Stage* initialize_a3() {
	Stage* stage_a3 = new Stage(a3_map, "A3");
	stage_a3->set_trigger(trigger_a3);
	initialize_items_a3(stage_a3);

	return stage_a3;
}