#include "Stage.h"
#include "Functions.h"



void Stage::add_item(Items* item) {
	items.push_back(item);
}

void Stage::draw() {
	int height{ 5 };

	for (size_t i = 0; i < coords.size(); i++) {
		gotoxy(2, height);
		std::string* row = coords.at(i);
		for (size_t j = 0; j < row->size(); j++) {
			printf("%c", get_char(row->at(j)));
		}

		height++;
	}
}

int Stage::get_char(char c) {
	switch (c) {
	case 'y':
		return 32;
	case 'i':
		return 32;
	case 'd':
		return 32;
	case 'a':
		return 32;
	case 'x': //x es abajo
		return 32;
	case 'w':
		return 219;
	case 't':
		return 176;
	case 'q':
		return 178;
	case '.':
		return 250;
	case '-':
		return 45;
	default:
		if (c == '1' || c == '2' || c == '3' || c == '4' || c == '<' || c == '>' || c == 'v' || c == '^') return c;
		for (size_t i = 0; i < items.size(); i++) {
			if (c == items.at(i)->icon) {
				return items.at(i)->icon_character;
			}
		}

		return 219;
	}
	return 0;
}

Items* Stage::check_items(char icon) {
	int index = -1;
	Items* item = nullptr;
	for (size_t i = 0; i < items.size(); i++) {
		if (items.at(i)->icon == icon) {
			std::string name = items.at(i)->name;
			item = items.at(i);
			index = i;
		}
	}

	if (index >= 0) {
		delete_items(items.at(index)->icon, index);
	}

	return item;
}

void Stage::delete_items(char icon, int index) {
	items.erase(items.begin() + index);
	for (size_t i = 0; i < coords.size(); i++) {
		std::string* row = coords.at(i);
		for (size_t j = 0; j < row->size(); j++) {
			if (row->at(j) == icon) {
				row->at(j) = 'y';
			}
		}
	}
}

void Stage::add_door(Door* door) {
	doors.push_back(door);
}

void Stage::unlock_door(std::string door_id) {
	char icon{};
	bool exist = false;
	for (int i = 0; i < doors.size(); i++) {
		if (doors.at(i)->get_id() == door_id) {
			icon = doors.at(i)->get_icon();
			doors.at(i)->lock();

			exist = true;
		}
	}

	if (exist) {
		for (size_t i = 0; i < coords.size(); i++) {
			std::string* row = coords.at(i);
			for (size_t j = 0; j < row->size(); j++) {
				if (row->at(j) == icon) {
					row->at(j) = 'y';
				}
			}
		}
	}
}

std::string Stage::has_door(int x, int y) {
	std::string door_id = "no hay puerta";

	char icon = coords.at(y)->at(x);

	if (icon != 'w' && icon != 'y') {
		for (size_t index_doors = 0; index_doors < doors.size(); index_doors++) {
			if (doors.at(index_doors)->get_icon() == icon) {
				door_id = doors.at(index_doors)->get_id();

				return door_id;
			}
		}
	}

	return door_id;
}

void Stage::active_trigger() {
	if (trigger) {
		bool completed = has_items();
		bool delete_trigger = trigger(completed, temp);

		if (delete_trigger) {
			for (size_t i = 0; i < coords.size(); i++) {
				std::string* row = coords.at(i);
				for (size_t j = 0; j < row->size(); j++) {
					if (row->at(j) == 'r') {
						row->at(j) = 'y';
					}
				}
			}
		}
	}
}

void Stage::active_event() {
	if (event) {
		if(event->is_active()) event->tick();
	}

	draw();
	return;
}

bool Stage::has_items() {
	if (items.size() > 0) return true;
	return false;
}

void Stage::change_icon(char old_icon, char new_icon) {
	for (size_t i = 0; i < coords.size(); i++) {
		std::string* row = coords.at(i);
		for (size_t j = 0; j < row->size(); j++) {
			if (row->at(j) == old_icon)
				row->at(j) = new_icon;
		}
	}
}