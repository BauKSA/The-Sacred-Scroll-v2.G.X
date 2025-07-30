#include<conio.h>
#include<iostream>

#include "c5.h"

static std::vector<std::string*> create_c5() {
	std::string* c5_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaawwwwww");
	std::string* c5_01 = new std::string("wyyyyywwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* c5_02 = new std::string("wyyyyywwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* c5_03 = new std::string("wyyyyyttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* c5_04 = new std::string("i;yywwttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* c5_05 = new std::string("i;yywwttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyywwwwww");
	std::string* c5_06 = new std::string("wwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* c5_07 = new std::string("wwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwww");
	std::string* c5_08 = new std::string("i:yywwttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c5_09 = new std::string("i:yywwttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c5_10 = new std::string("wyyyyyttyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c5_11 = new std::string("wyyyyywwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c5_12 = new std::string("wyyyyywwyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c5_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _c5 = { c5_00, c5_01, c5_02, c5_03, c5_04, c5_05, c5_06, c5_07,
	c5_08, c5_09, c5_10, c5_11, c5_12, c5_13 };

	return _c5;
}

static void event_c5_func() {

}

void initialize_items_c5(Stage* stage) {

}


bool static trigger_c5(bool completed, Player* player) {
	static bool used = false;

	if (used) return false;
	char door{};
	clear_text();
	print_text("-Puerta 1: Tu objetivo est3 ac3.- -Puerta 2: Tu objetivo NO est3 ac3- Solo uno de los carteles es verdadero... elije sabiamente la puerta.");
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + 10);
	printf("Abrir puerta: ");
	std::cin >> door;

	Stage* actual_stage = Environment::get_actual_stage();
	Position pos{};
	pos.x = 2;
	pos.y = 0;

	if (door == '1') {
		Position offset{};
		offset.x = 0;
		offset.y = 0;
		std::string name = ":(";

		Items* zopenca = new Items(name, 'k', 244, offset, name, 'p', {}, "");

		bool has_zopenca = false;

		std::vector<Items*> items = player->get_items();
		for (size_t i = 0; i < items.size(); i++)
			if (items.at(i)->name == name) has_zopenca = true;
		
		if(!has_zopenca) player->add_items(zopenca);

		clear_text();
		print_text("Puerta 1 abierta");
		player->move(pos);

		actual_stage->change_icon(';', 'y');
		return false;
	} else if (door == '2') {
		clear_text();
		print_text("Puerta 2 abierta");

		player->move(pos);

		actual_stage->change_icon(':', 'y');
		used = true;

		return false;
	} else {
		clear_text();
		print_text("N7mero de puerta no v3lido (1 o 2)");

		player->move(pos);
		return false;
	}

	return true; 
}

const static std::vector<std::string*> c5_map = create_c5();

Stage* initialize_c5() {
	Stage* stage_c5 = new Stage(c5_map, "C5");
	stage_c5->set_trigger(trigger_c5);

	return stage_c5;
}