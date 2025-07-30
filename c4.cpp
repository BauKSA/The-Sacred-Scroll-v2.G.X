#include<conio.h>
#include<iostream>

#include "c4.h"

static std::vector<std::string*> create_c4() { //..-. . .-.. .. --..     **     -.-. ..- -- .--. .-.. .
	std::string* c4_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c4_01 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyw");
	std::string* c4_02 = new std::string("wwttttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyw");
	std::string* c4_03 = new std::string("wwtwwtyyyywwwwwwwwwwwwwwwwwwwwwwwwyywwyyyy4>y1vy2>y2^y2>y1^yyyywwyyyyyyyyyw");
	std::string* c4_04 = new std::string("wwtwwtyyyywwwwwwwwwwwwwwwwwwwwwwwwyywwyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyd");
	std::string* c4_05 = new std::string("wwttttyyyywwwwwwwwwwwwwwwwwwwwwwwwyywwyyyy2>y3vy2>y2^y2>yyyyyyywwyyyyyyyyyd");
	std::string* c4_06 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyywwyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwww");
	std::string* c4_07 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwww");
	std::string* c4_08 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyd");
	std::string* c4_09 = new std::string("wwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* c4_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c4_11 = new std::string("wyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwycyyyyyyyw");
	std::string* c4_12 = new std::string("wyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyw");
	std::string* c4_13 = new std::string("wwwwwwxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _c4 = { c4_00, c4_01, c4_02, c4_03, c4_04, c4_05, c4_06, c4_07,
	c4_08, c4_09, c4_10, c4_11, c4_12, c4_13 };

	return _c4;
}

static void event_c4_func() {

}

void initialize_items_c4(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Chocolate";
	Items* chocolate = new Items(name, 'c', 157, offset, name, 'p', {}, "");

	stage->add_item(chocolate);
}

bool static trigger_c4(bool completed, Player* player = nullptr) {
	clear_text();
	print_text("'Cuatro >'?? Cuatro a la derecha? Mmm... Qu4 ser3 esto?");
	return true;
}

const static std::vector<std::string*> c4_map = create_c4();

Stage* initialize_c4() {
	Stage* stage_c4 = new Stage(c4_map, "C4");
	stage_c4->set_trigger(trigger_c4);
	initialize_items_c4(stage_c4);

	return stage_c4;
}