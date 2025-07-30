#include<conio.h>
#include<iostream>

#include "b4.h"

static std::vector<std::string*> create_b4() {
	std::string* b4_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwaaawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	std::string* b4_01 = new std::string("wwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwww");
	std::string* b4_02 = new std::string("wyyyyyyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwww");
	std::string* b4_03 = new std::string("wyyyyyyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyywwwwwwwwwwwwwwwwww");
	std::string* b4_04 = new std::string("wttyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwww");
	std::string* b4_05 = new std::string("wwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyqwwwwwwwwwwwwwwd");
	std::string* b4_06 = new std::string("wwwtyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyqwwwwwwwwwwwwwwd");
	std::string* b4_07 = new std::string("wwwtyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyqwwwwwwwwwwwwwwd");
	std::string* b4_08 = new std::string("wwttyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyqwwwwwwwwwwwwwwd");
	std::string* b4_09 = new std::string("wttyyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwww");
	std::string* b4_10 = new std::string("wyyyyyyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyywwwwwwwwwwwwwwwwww");
	std::string* b4_11 = new std::string("wyyyyyyyywyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwww");
	std::string* b4_12 = new std::string("wwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwww");
	std::string* b4_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _b4 = { b4_00, b4_01, b4_02, b4_03, b4_04, b4_05, b4_06, b4_07,
	b4_08, b4_09, b4_10, b4_11, b4_12, b4_13 };

	return _b4;
}

static void event_b4_func() {

}

void initialize_items_b4(Stage* stage) {

}

bool static trigger_b4(bool completed, Player* player) {
	static bool used = false;
	clear_text();

	if (used) {
		print_text("Mmmm, qu4 rico.");
		return true;
	}

	bool has_ticket = false;
	std::vector<Items*> player_items = player->get_items();
	for (size_t i = 0; i < player_items.size(); i++) {
		if (player_items.at(i)->name == "Chocolate") has_ticket = true;
	}

	if (!has_ticket) {
		print_text("Matar5a por un chocolate...");
		return false;
	}

	print_text("Ah! Un chocolate, gracias! No tengo contrase8as, pero te puedo dar esto como agradecimiento...");
	player->delete_items("Chocolate");

	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Pase A4";
	Items* pase = new Items(name, 'k', 244, offset, name, ' ', {}, "");
	player->add_items(pase);

	used = true;
	return true;
}

const static std::vector<std::string*> b4_map = create_b4();

Stage* initialize_b4() {
	Stage* stage_b4 = new Stage(b4_map, "B4");
	stage_b4->set_trigger(trigger_b4);

	stage_b4->set_teleport(76, 0);
	stage_b4->set_teleport_init(60, 0);


	return stage_b4;
}