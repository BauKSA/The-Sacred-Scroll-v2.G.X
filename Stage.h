#pragma once
#include<string>
#include<vector>

#include "Globals.h"
#include "Items.h"
#include "Doors.h"
#include "Event.h"
#include "Player.h"

typedef bool (*TriggerFunction)(bool completed, Player* player);

struct Coords {
	int x;
	int y;
};

class Stage {	
private:
	std::vector<std::string*> coords;
	std::string map_id;
	std::string id;
	std::vector<Items*> items;
	std::vector<Door*> doors;
	TriggerFunction trigger = nullptr;
	Event* event = nullptr;
	Player* temp;
	Coords* teleport;
	Coords* teleport_init;
public:
	Stage(std::vector<std::string*> _coords, std::string _id = "A0") :
		coords(_coords), id(_id) {
		items = {};
		doors = {};
		temp = nullptr;
		teleport = nullptr;
		teleport_init = nullptr;
	}

	void set_trigger(TriggerFunction _trigger) { trigger = _trigger; }
	void active_trigger();

	void use_player(Player* player) { temp = player; }

	void set_event(Event* _event) { event = _event; }
	void active_event();

	void set_teleport(int x, int y) {
		Coords* _teleport = new Coords;

		_teleport->x = x;
		_teleport->y = y;

		teleport = _teleport;
	}

	void set_teleport_init(int x, int y) {
		Coords* _teleport = new Coords;

		_teleport->x = x;
		_teleport->y = y;

		teleport_init = _teleport;
	}

	Coords get_teleport() { return *teleport; }
	Coords get_teleport_init() { return *teleport_init; }

	void change_icon(char old_icon, char new_icon);
	bool has_items();
	std::string get_name() { return id; }
	std::string has_door(int x, int y);
	void add_door(Door* door);
	void unlock_door(std::string door_id);
	Items* check_items(char icon);
	void delete_items(char icon, int index);
	void add_item(Items* item);
	void draw();
	int get_char(char c);
	std::string get_id() const { return id; }
	char get_position(int coord_x, int coord_y) {
		return coords.at(coord_y)->at(coord_x);
	}
};