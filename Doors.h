#pragma once
#include<string>

class Door {
private:
	std::string id;
	char icon;
	bool locked;
public:
	Door(std::string _id, char _icon) :
		id(_id), icon(_icon) {
		locked = false;
	};

	std::string get_id() { return id; }
	char get_icon() { return icon; }
	void lock() { locked = true; }
};