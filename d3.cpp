#include<conio.h>
#include<iostream>

#include "d3.h"

static std::vector<std::string*> create_d3() {
	std::string* d3_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* d3_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyywwwwyyywwyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyywwwwyyywwyy*yywwyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_03 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyywwyyyyywwyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_04 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_05 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyttttyyywwyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_06 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwttttwwwwwyykyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_07 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_08 = new std::string("iyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwww");
	std::string* d3_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _d3 = { d3_00, d3_01, d3_02, d3_03, d3_04, d3_05, d3_06, d3_07,
	d3_08, d3_09, d3_10, d3_11, d3_12, d3_13 };

	return _d3;
}

static void event_d3_func() {

}

void initialize_items_d3(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Llave A3";
	Items* pass = new Items("password", '*', 207, offset, "password", 'p', {}, "");
	Items* key = new Items(name, 'k', 244, offset, name, 'p', {}, "puerta_a3");

	stage->add_item(pass);
	stage->add_item(key);
}

bool static trigger_d3(bool completed, Player* player) {
	clear_text();
	print_text("Ya te est3s acercando al Sacred Scroll! Espero que tengas lo necesario para encontrarlo...");
	return true;
}

const static std::vector<std::string*> d3_map = create_d3();

Stage* initialize_d3() {
	Stage* stage_d3 = new Stage(d3_map, "D3");
	stage_d3->set_trigger(trigger_d3);
	initialize_items_d3(stage_d3);

	return stage_d3;
}