#include<conio.h>
#include<iostream>

#include "b3.h"

static std::vector<std::string*> create_b3() {
	std::string* b3_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b3_01 = new std::string("wwyyyyyyyyyyyyttyy*ywyyyyyyyyyyyyyyyyyyyyyywwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* b3_02 = new std::string("wwywwwwwwwwywwwwwwwwwyyywwwwwwwwwwwwwwwwwwywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b3_03 = new std::string("wwwwyyyyyyyywwwwwwwwwyyyyyyyyyyyywwwwyyyyyyyyyyywwwwwwwwwwyyyyyyyywwwwwwwww");
	std::string* b3_04 = new std::string("wwywyywwwwywwwwwwwwywwwwwwwwwwwwyywwwwwwwyywwwwwwywwwwwwwwwwywwwwywwwwwwwww");
	std::string* b3_05 = new std::string("wwyyyywyyyywyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyywwywwwwywwww");
	std::string* b3_06 = new std::string("wwywwwwwwwwwwwwwwywyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwywwwwywwww");
	std::string* b3_07 = new std::string("wwywyyyyyyyyyyywwwwwwwwwwwwwywwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwywwww");
	std::string* b3_08 = new std::string("wwywyywwwwwwwwwwwwwwwwwwwwwwywyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwywwwwywwww");
	std::string* b3_09 = new std::string("wwywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwywwww");
	std::string* b3_10 = new std::string("wwywwwwwwwwyywwwwwwwwwwwwwwwwwwwwwwwwywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwywwww");
	std::string* b3_11 = new std::string("wwywwwwwwwwyywwwwwwwwwwwwwwwwwwwwwwwwywwwwwwwwwwwwwwwwwwwwyyyyyyyyyywwwwwww");
	std::string* b3_12 = new std::string("wwyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyypyyyyyw");
	std::string* b3_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxw");

	std::vector<std::string*> _b3 = { b3_00, b3_01, b3_02, b3_03, b3_04, b3_05, b3_06, b3_07,
	b3_08, b3_09, b3_10, b3_11, b3_12, b3_13 };

	return _b3;
}

static void event_b3_func() {

}

void initialize_items_b3(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;

	Door* door = new Door("puerta_b3", 'p');
	stage->add_door(door);

	Items* pass = new Items("password", '*', 207, offset, "password", 'p', {}, "");
	stage->add_item(pass);
}

bool static trigger_b3(bool completed, Player* player) {
	char codificado[3] = { 153, 216, 226 };
	clear_text();
	print_text("El primer guardi3n que protege el Sacred Scroll es conocido como:");
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + 5);
	for (size_t i = 0; i < 3; i++) {
		printf("%c", codificado[i]);
	}
	print_text("... podr3as decodificarlo con las primeras tres contrase8as", 7);

	return false;
}

const static std::vector<std::string*> b3_map = create_b3();

Stage* initialize_b3() {
	Stage* stage_b3 = new Stage(b3_map, "B3");
	stage_b3->set_trigger(trigger_b3);
	initialize_items_b3(stage_b3);

	return stage_b3;
}