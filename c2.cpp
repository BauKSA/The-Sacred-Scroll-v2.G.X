#include<conio.h>
#include<iostream>

#include "Player.h"
#include "c2.h"

static std::vector<std::string*> create_c2() {
	std::string* c2_00 = new std::string("wwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c2_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_03 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c2_04 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* c2_05 = new std::string("wyyyyyyyyyyyyyy*yyyyyyyyyyyyyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* c2_06 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyywtttwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyd");
	std::string* c2_07 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwrrrwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* c2_08 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_09 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c2_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _c2 = { c2_00, c2_01, c2_02, c2_03, c2_04, c2_05, c2_06, c2_07,
	c2_08, c2_09, c2_10, c2_11, c2_12, c2_13 };

	return _c2;
}

static void event_c2_func() {

}

void initialize_items_c2(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;

	std::string name = "password";

	Items* pass = new Items(name, '*', 207, offset, name, 'p', {}, "");
	stage->add_item(pass);

	return;
}


bool static trigger_c2(bool complete, Player* player = nullptr) {
	static bool used = false;

	if (used) return true;

	bool correct = false;
	std::string correct_pass = "grand_scroll";
	std::string pass = "";

	clear_text();
	print_text("Para abrir esta puerta, es necesario una contrase8a. Visit3 mi perfil de Itchio para encontrarla!°");
	gotoxy(79, 11);
	std::cin >> pass;
	if (pass != correct_pass) {
		Position* pos = new Position;
		pos->x = 0;
		pos->y = -1;
		player->move(*pos);
		clear_text();
		print_text("Contrase8a incorrecta!");
		delete pos;
		return false;
	}

	clear_text();
	print_text("Contrase8a correcta! Pod4s avanzar");
	used = true;

	return true;
}

const static std::vector<std::string*> c2_map = create_c2();

Stage* initialize_c2() {
	Stage* stage_c2 = new Stage(c2_map, "C2");

	Event* event_c2 = new Event(event_c2_func);

	stage_c2->set_trigger(trigger_c2);

	initialize_items_c2(stage_c2);

	return stage_c2;
}