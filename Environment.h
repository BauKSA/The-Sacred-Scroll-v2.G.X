#pragma once
#include<vector>

#include "Player.h"
#include "Stage.h"
#include "Interface.h"

class Environment {
static Stage* actual_stage;
private:
	std::vector<std::vector<Stage*>> stages;
	bool can_move(int coord_x, int coord_y);
	Player* actual_player;
	Interface* _interface;
	bool movement;
	int temp_player_items;
	bool running;
public:
	Environment(Interface* _interface_) :
		_interface(_interface_) {
		stages = { {} };

		movement = true;
		temp_player_items = 0;
		running = true;

		actual_player = nullptr;
	}

	static Stage* get_actual_stage() { return Environment::actual_stage; }
	std::string get_stage_id() { return Environment::actual_stage->get_id(); }
	void clear_items();
	void draw();
	void add_player(Player* player);
	void add_stage(Stage* stage);
	void tick();
	void check_items(int x_pos, int y_pos);
	void init_stage(std::string stage_id);
	void change_stage(char dir);
	void draw_dynamics();
	void check_doors();
	void check_trigger(int x_pos, int y_pos);
	void draw_password();
	void draw_stage();
	void clear_screen();
	void loading_screen();
	void teleport();
	bool is_running() const { return running; }

	void check_scroll() {
		std::vector<Items*> items = Environment::actual_player->get_items();
		for (size_t i = 0; i < items.size(); i++) {
			if (items.at(i)->name == "Sacred Scroll (presione l para abrir)") {
				running = false;
			}
		}
	}
};