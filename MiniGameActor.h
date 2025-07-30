#pragma once
#include<mutex>

#include "Functions.h"

#ifndef _MiniGameActor_
#define _MiniGameActor_

extern std::mutex miniGame_mutex;

class MiniGameActor {
private:
	int icon;
	int x;
	int y;
	std::mutex mtx;

protected:
	void move(int direction);
	void set_position(int x, int y);

public:
	MiniGameActor(int _x, int _y, int _icon) :
		x(_x), y(_y), icon(_icon) {};

	void draw(bool clear) const;
	int get_x() const { return x; }
	int get_y() const { return y; }

	~MiniGameActor() {
		gotoxy(x, y);
		printf(" ");
	}
};

#endif // !_MiniGameActor_
