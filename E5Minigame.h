#pragma once
#ifndef _E5MiniGame_
#define _E5MiniGame_
#include<thread>
#include<chrono>
#include<iostream>
#include<conio.h>
#include<vector>
#include<mutex>

#include "MiniGameActor.h"
#include "Functions.h"
#include "Globals.h"

extern std::mutex e5_mutex;

class E5MiniGamePlayer : public MiniGameActor {
private:
	bool movement;
	int keys;
public:
	E5MiniGamePlayer(int _x, int _y) :
		MiniGameActor(_x, _y, 254) {
		movement = true;
		keys = 0;
	};

	void move_player(int dir);
	void restart_position();
	void sum_key() { keys++; }
	int get_keys() const { return keys; }
};

class Block : public MiniGameActor {
private:
	bool up;
public:
	Block(int _x, int _y, int _up) :
		MiniGameActor(_x, _y, 179) {
		up = _up;
	};

	void vertical_move();
	bool check_limit();
};

class Key : public MiniGameActor {
public:
	Key(int _x, int _y) :
		MiniGameActor(_x, _y, 158) {};
};

class E5MiniGame {
private:
	std::vector<Block*> blocks;
	std::vector<Key*> keys;
	E5MiniGamePlayer* player;
	bool running; // Bandera para controlar la ejecuci6n de los hilos
	bool checking;
	int keys_amount;
public:
	E5MiniGame() :
		running(true), checking(false), player(nullptr), keys_amount(0) {}

	void redraw();
	void move_blocks();
	void add_block(Block* block, int x, int y);
	void add_player(E5MiniGamePlayer* _player);
	void stop_threads() { running = false; }
	bool is_running() const { return running; }
	void move_player(int dir);
	void check_collision();
	void add_key(Key* key);
};
#endif // !_E5MiniGame_
