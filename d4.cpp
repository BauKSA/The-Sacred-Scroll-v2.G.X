#include<conio.h>
#include<iostream>

#include "d4.h"

static std::vector<std::string*> create_d4() {
	std::string* d4_00 = new std::string("wwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_01 = new std::string("wyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_02 = new std::string("wyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_03 = new std::string("wyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_04 = new std::string("wyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_05 = new std::string("wyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_06 = new std::string("wyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_07 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_08 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d4_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _d4 = { d4_00, d4_01, d4_02, d4_03, d4_04, d4_05, d4_06, d4_07,
	d4_08, d4_09, d4_10, d4_11, d4_12, d4_13 };

	return _d4;
}

static void event_d4_func() {

}

void initialize_items_d4(Stage* stage) {

}

void static trigger_d4() {

}

const static std::vector<std::string*> d4_map = create_d4();

Stage* initialize_d4() {
	Stage* stage_d4 = new Stage(d4_map, "D4");

	return stage_d4;
}