#include<conio.h>
#include<iostream>

#include "d1.h"

static std::vector<std::string*> create_d1() {
	std::string* d1_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaawwwwwwwwwwwwwwwaaaw");
	std::string* d1_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_02 = new std::string("wywwwywywywwyywwywwwywwywyywwyywwyywwywwywyywwwywywywyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_03 = new std::string("wyywyywywywwyywyywywywyywwywwywywyywyywyywwywywywywywyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_04 = new std::string("wyywyywwwywyyyywywwwywyywyywyywywyyywywyywyywywywywywyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_05 = new std::string("wyywyywywywwyywwywywywwywyywwywwyyywwywwywyywwwywywywyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_06 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_07 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_08 = new std::string("wwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_09 = new std::string("wwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_10 = new std::string("wwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwyyyw");
	std::string* d1_11 = new std::string("wwwwwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* d1_12 = new std::string("wwwwwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyw");
	std::string* d1_13 = new std::string("wwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxw");

	std::vector<std::string*> _d1 = { d1_00, d1_01, d1_02, d1_03, d1_04, d1_05, d1_06, d1_07,
	d1_08, d1_09, d1_10, d1_11, d1_12, d1_13 };

	return _d1;
}

static void event_d1_func() {

}

void initialize_items_d1(Stage* stage) {

}

void static trigger_d1() {

}

const static std::vector<std::string*> d1_map = create_d1();

Stage* initialize_d1() {
	Stage* stage_d1 = new Stage(d1_map, "D1");

	return stage_d1;
}