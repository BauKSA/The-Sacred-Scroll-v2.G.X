#pragma once
#include<string>

#include "Functions.h"
#include "Globals.h"

class Actor {
private:
	int body;
	Position position;

public:
	Actor(Position _position, int _body = 254) :
		body(_body) {
		position = _position;
		draw(false);
	}

	void draw(bool empty) const;
	void move(Position added_position);
	void reset_position() { position.x = MAP_X_INIT + 2; position.y = MAP_Y_INIT + 1; }
	Position get_pos() const {
		return position;
	}
};