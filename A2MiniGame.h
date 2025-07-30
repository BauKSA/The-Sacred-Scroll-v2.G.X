#pragma once
#ifndef _A2MiniGame_
#define _A2MiniGame_
#include<thread>
#include<chrono>
#include<iostream>
#include<conio.h>
#include<vector>
#include<mutex>

#include "MiniGameActor.h"
#include "Functions.h"
#include "Globals.h"

extern std::mutex a2_mutex;

class MiniGamePlayer : public MiniGameActor {
public:
	MiniGamePlayer(int _x, int _y) :
		MiniGameActor(_x, _y, 204) {};

	void move_up();
	void move_down();
};

class A2Bullet : public MiniGameActor {
public:
	A2Bullet(int _x, int _y) :
		MiniGameActor(_x, _y, 254) {};

	void move_right();
};


class Enemy : public MiniGameActor {
public:
	Enemy(int _x, int _y) :
		MiniGameActor(_x, _y, 158) {};

	void move_left();
};

class A2MiniGame {
private:
	std::vector<A2Bullet*> bullets;
	std::vector<Enemy*> enemies;
	MiniGamePlayer* player;
	int points;
	bool running; // Bandera para controlar la ejecuci6n de los hilos
	bool checking;
public:
	A2MiniGame():
		points(0), running(true), checking(false), player(nullptr) {}

	void print_points() const;
	void redraw();
	void check_positions();
	void move_bullets();
	void move_enemies();
	void add_bullet(A2Bullet* bullet);
	void add_enemy(Enemy* enemy);
	void add_player(MiniGamePlayer* _player);
	void stop_threads() { running = false; }
	int get_points() const { return points; }
	bool is_running() const { return running; }
};
#endif // !_A2MiniGame_
