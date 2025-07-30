#pragma once
#ifndef _A1MiniGame_
#define _A1MiniGame_
#include<thread>
#include<chrono>
#include<iostream>
#include<conio.h>
#include<vector>
#include<mutex>

#include "MiniGameActor.h"
#include "Functions.h"
#include "Globals.h"

std::mutex a1_mutex;

class A1Actor {
protected:
	int x;
	int y;
	int icon;
public:
	A1Actor(int _x, int _y, int _icon) :
		x(_x), y(_y), icon(_icon) {};

	int get_x() const { return x; }
	int get_y() const { return y; }
	void draw() const {
		std::lock_guard<std::mutex> lock(a1_mutex);
		gotoxy(x, y);
		printf("%c", icon);
	}
	void erase() const {
		std::lock_guard<std::mutex> lock(a1_mutex);
		gotoxy(x, y);
		printf(" ");
	}
};

class MovableActor : public A1Actor {
protected:
	bool updated;
	bool alive;
public:
	MovableActor(int x, int y, int icon) :
		A1Actor(x, y, icon) {
		updated = false;
		alive = true;
	};

	virtual void tick() {}

	void kill() { alive = false; }
	bool is_alive() const { return alive; }

	void move(char dir) {
		switch (dir) {
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'd':
			x++;
			break;
		case 'a':
			x--;
			break;
		default:
			break;
		}

		updated = false;
	}

	void update() { updated = true; }
	bool is_updated() const { return updated; }
};

class A1Player : public MovableActor {
private:
	char pending;
	int health;
public:
	A1Player(int x, int y) :
		MovableActor(x, y, 254) {
		pending = 'x';
		health = 100;
	};

	void move_queue(char dir) { pending = dir; }
	void reset_pending() { pending = 'x'; }
	char get_pending() const { return pending; }
	void restart() {
		erase();
		x = 3;
		updated = false;
		draw();
	}
};

class Obstacle : public A1Actor {
public:
	Obstacle(int x, int y) :
		A1Actor(x, y, 219) {};
};

class System {
protected:
	std::vector<MovableActor*> actors;
public:
	void add_actor(MovableActor* actor) { actors.push_back(actor); }

	virtual bool update() { return true; };
};

class MovementSystem : public System {
public:
	bool update() override {
		for (size_t i = 0; i < actors.size(); i++) {
			if (!actors.at(i)->is_updated()) {
				actors.at(i)->draw();
				actors.at(i)->update();
			}
		}

		return true;
	}
};

class A1MiniGame {
private:
	int bullets_active;
	A1Player* player;
	std::vector<MovableActor*> actors;
	std::vector<Obstacle*> obstacles;
	MovementSystem* movementSystem;
	bool running;
	bool checking;
public:
	A1MiniGame() {
		running = true;
		player = nullptr;
		movementSystem = nullptr;
		bullets_active = 0;
		checking = true;
	}

	void add_player(A1Player* _player) { player = _player; }
	void add_movement_system(MovementSystem* _system) { movementSystem = _system; }
	void add_obstacles(Obstacle* obstacle) { obstacles.push_back(obstacle); }
	void add_actors(MovableActor* actor) { actors.push_back(actor); }
	bool is_running() const { return running; }

	void init() {
		player->draw();
	}

	void tick() {
		while (running) {
			if (player->get_pending() != 'x') {
				if (movable(player->get_pending())) {
					player->erase();
					player->move(player->get_pending());
					player->reset_pending();
				}
			}

			movementSystem->update();
			if (player->get_x() == THIRD_HORIZONTAL_BAR_WIDTH - 3) running = false;
			if (checking) check_obstacles(player->get_x());
		}
	}

	bool check_limits(char dir) {
		switch (dir) {
		case 'w':
			if (player->get_y() == 9) return false;
			break;
		case 's':
			if (player->get_y() == 12) return false;
			break;
		case 'd':
			if (player->get_x() == THIRD_HORIZONTAL_BAR_WIDTH - 1) return false;
			break;
		case 'a':
			if (player->get_x() == 1) return false;
			break;
		default:
			break;
		}

		return true;
	}

	bool check_obstacles(char dir) {
		for (size_t i = 0; i < obstacles.size(); i++) {
			switch (dir) {
			case 'w':
				if (player->get_x() != obstacles.at(i)->get_x()) break;
				if (player->get_y() - 1 == obstacles.at(i)->get_y()) player->restart();
				break;
			case 's':
				if (player->get_x() != obstacles.at(i)->get_x()) break;
				if (player->get_y() + 1 == obstacles.at(i)->get_y()) player->restart();
				break;
			case 'd':
				if (player->get_y() != obstacles.at(i)->get_y()) break;
				if (player->get_x() + 1 == obstacles.at(i)->get_x()) player->restart();
				break;
			case 'a':
				if (player->get_y() != obstacles.at(i)->get_y()) break;
				if (player->get_x() - 1 == obstacles.at(i)->get_x()) player->restart();
				break;
			default:
				break;
			}
		}

		return true;
	}

	bool movable(char dir) {
		if (!check_limits(dir)) return false;
		if (!check_obstacles(dir)) return false;
		return true;
	}


	~A1MiniGame() {
		delete player;
		delete movementSystem;
	}
};

#endif // !_A1MiniGame_