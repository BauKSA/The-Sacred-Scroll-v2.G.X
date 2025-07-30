#include<conio.h>
#include<iostream>

#include "e3.h"

static std::vector<std::string*> create_e3() {
	std::string* e3_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e3_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_03 = new std::string("wwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_04 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_05 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyywwttttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyww");
	std::string* e3_06 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwttwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e3_07 = new std::string("wwyyyyyyyyyyyyyyyyyyyyyyyyyywwwwttwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e3_08 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyywwttttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e3_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyww");
	std::string* e3_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* e3_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _e3 = { e3_00, e3_01, e3_02, e3_03, e3_04, e3_05, e3_06, e3_07,
	e3_08, e3_09, e3_10, e3_11, e3_12, e3_13 };

	return _e3;
}

static void event_e3_func() {

}

void initialize_items_e3(Stage* stage) {

}

bool static trigger_e3(bool completed, Player* player) {
	char codificado[3] = { 195, 206, 234 };
	clear_text();
	print_text("El segundo guardi3n que protege el Sacred Scroll es conocido como:");
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + 5);
	for (size_t i = 0; i < 3; i++) {
		printf("%c", codificado[i]);
	}
	print_text("... podr3as decodificarlo con las segundas tres contrase8as", 7);
	return false;
}

const static std::vector<std::string*> e3_map = create_e3();

Stage* initialize_e3() {
	Stage* stage_e3 = new Stage(e3_map, "E3");
	stage_e3->set_trigger(trigger_e3);

	return stage_e3;
}