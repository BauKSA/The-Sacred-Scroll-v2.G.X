#include<conio.h>
#include<iostream>

#include "e2.h"

static std::vector<std::string*> create_e2() {
	std::string* e2_00 = new std::string("wwwwaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_01 = new std::string("wywwyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_02 = new std::string("wywwyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_03 = new std::string("wywwyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_04 = new std::string("wywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e2_05 = new std::string("wywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e2_06 = new std::string("wywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* e2_07 = new std::string("wywwyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_08 = new std::string("wywwyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_09 = new std::string("wywwyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_10 = new std::string("iypyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_11 = new std::string("iypyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_12 = new std::string("iypyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* e2_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _e2 = { e2_00, e2_01, e2_02, e2_03, e2_04, e2_05, e2_06, e2_07,
	e2_08, e2_09, e2_10, e2_11, e2_12, e2_13 };

	return _e2;
}

static void event_e2_func() {

}

void initialize_items_e2(Stage* stage) {
	Door* door = new Door("puerta_e2", 'p');
	stage->add_door(door);
}

void static trigger_e2() {

}

const static std::vector<std::string*> e2_map = create_e2();

Stage* initialize_e2() {
	Stage* stage_e2 = new Stage(e2_map, "E2");
	initialize_items_e2(stage_e2);

	return stage_e2;
}