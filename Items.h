#pragma once
#include<string>
#include<vector>

#include "Actor.h"

struct Items {
	std::string id;
	char icon;
	int icon_character;
	Position offset;
	char icon_to_unlock;
	std::vector<std::string> messages;
	std::string name;
	std::string door_to_unlock;

	Items(std::string _id, char _icon, int _icon_character, Position _offset, std::string _name, char _icon_to_unlock = false,
		std::vector<std::string> _messages = {}, std::string _door = "") :
		id(_id), icon(_icon), icon_character(_icon_character),
		offset(_offset), name(_name), icon_to_unlock(_icon_to_unlock),
		messages(_messages), door_to_unlock(_door) {}
};