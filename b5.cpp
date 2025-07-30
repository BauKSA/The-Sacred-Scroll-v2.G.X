#include<conio.h>
#include<iostream>

#include "b5.h"

static std::vector<std::string*> create_b5() {
	std::string* b5_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b5_01 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b5_02 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b5_03 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b5_04 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b5_05 = new std::string("iwwwwwwwwwwwwwwwqyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* b5_06 = new std::string("iwwwwwwwwwwwwwwwqyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* b5_07 = new std::string("iwwwwwwwwwwwwwwwqyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* b5_08 = new std::string("iwwwwwwwwwwwwwwwqyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* b5_09 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* b5_10 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* b5_11 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* b5_12 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* b5_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxwwwwww");

	std::vector<std::string*> _b5 = { b5_00, b5_01, b5_02, b5_03, b5_04, b5_05, b5_06, b5_07,
	b5_08, b5_09, b5_10, b5_11, b5_12, b5_13 };

	return _b5;
}

static void event_b5_func() {

}

void initialize_items_b5(Stage* stage) {

}

void static trigger_b5() {

}

const static std::vector<std::string*> b5_map = create_b5();

Stage* initialize_b5() {
	Stage* stage_b5 = new Stage(b5_map, "B5");
	stage_b5->set_teleport(2, 0);
	stage_b5->set_teleport_init(19, 0);

	return stage_b5;
}