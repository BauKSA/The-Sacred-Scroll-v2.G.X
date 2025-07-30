#include<conio.h>
#include<iostream>

#include "c1.h"

static std::vector<std::string*> create_c1() {
	std::string* c1_00 = new std::string("wwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaaw");
	std::string* c1_01 = new std::string("wyyywwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_03 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_04 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_05 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_06 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_07 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_08 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* c1_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwyyyw");
	std::string* c1_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwyyyw");
	std::string* c1_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyywwwwwwwwwwwwwwwyyyw");
	std::string* c1_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxwwwwwwwwwwwwwwwxxxw");

	std::vector<std::string*> _c1 = { c1_00, c1_01, c1_02, c1_03, c1_04, c1_05, c1_06, c1_07,
	c1_08, c1_09, c1_10, c1_11, c1_12, c1_13 };

	return _c1;
}

static void event_c1_func() {

}

void initialize_items_c1(Stage* stage) {

}

void static trigger_c1() {

}

const static std::vector<std::string*> c1_map = create_c1();

Stage* initialize_c1() {
	Stage* stage_c1 = new Stage(c1_map, "C1");

	return stage_c1;
}