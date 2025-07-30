#pragma once
#include<vector>

#include "Actor.h"
#include "Items.h"

class Player : public Actor {
private:
	int health;
	std::vector<Items*> items;
	std::vector<std::string> password;
public:
	Player(Position position):
		Actor(position) {
		health = 100;
	}

	int get_password_size() { return password.size(); };
	std::string get_current_password(int i);
	void throw_key(std::string door_id);
	void add_items(Items* item);
	void add_password();
	void delete_items(std::string name);
	bool has_key(std::string door_id);
	std::vector<Items*> get_items() { return items; };
};