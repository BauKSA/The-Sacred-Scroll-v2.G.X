#include<thread>
#include<chrono>
#include<iostream>
#include<conio.h>
#include<vector>
#include<mutex>

#include "Functions.h"
#include "Globals.h"
#include "E5MiniGame.h"

/*
0 -> abajo
1 -> arriba
2 -> derecha
3 -> izquierda
*/

std::mutex e5_mutex;

//PLAYER
void E5MiniGamePlayer::move_player(int dir) {
	if (!movement) return;
	move(dir);
}

void E5MiniGamePlayer::restart_position() {
	set_position(4, get_y());
}

//BLOCK
void Block::vertical_move() {
	if (up) {
		move(0);
		if (check_limit()) up = false;
	} else {
		move(1);
		if (check_limit()) up = true;
	}
}

bool Block::check_limit() {
	if (get_y() == SECOND_HORIZONTAL_BAR + 5 ||
		get_y() == THIRD_HORIZONTAL_BAR - 5)
		return true;

	return false;
}

//E5MiniGame
void E5MiniGame::redraw() {
	std::lock_guard<std::mutex> lock(e5_mutex);
	for (size_t i = 0; i < MAP_HEIGHT - 1; i++) {
		gotoxy(3, MAP_Y_INIT + i);
		for (size_t j = 0; j < MAP_WIDTH - 1; j++) {
			printf(" ");
		}
	}

	for (size_t i = 0; i < blocks.size(); i++) {
		blocks.at(i)->draw(false);
	}

	player->draw(false);
}

void E5MiniGame::move_blocks() {
	while (running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		for (size_t i = 0; i < blocks.size(); i++) {
			if (blocks.at(i) != nullptr) {
				blocks.at(i)->vertical_move();
				check_collision();
			}
		}
	}
}

void E5MiniGame::add_block(Block* block, int x, int y) {
	blocks.push_back(block);
}


void E5MiniGame::add_player(E5MiniGamePlayer* _player) {
	player = _player;
}

void E5MiniGame::move_player(int dir) {
	player->move_player(dir);
	check_collision();
}

void E5MiniGame::check_collision() {
	if (checking) return;

	checking = true;
	for (size_t i = 0; i < blocks.size(); i++) {
		if (blocks.at(i)->get_x() == player->get_x()
			&& blocks.at(i)->get_y() == player->get_y()) player->restart_position();
	}

	int key_index = -1;

	for (size_t i = 0; i < keys.size(); i++) {
		if (keys.at(i)->get_x() == player->get_x()
			&& keys.at(i)->get_y() == player->get_y()) key_index = i;
	}

	if (key_index > -1) {
		delete keys.at(key_index);
		keys.erase(keys.begin() + key_index);
		player->sum_key();
		player->draw(false);
	}

	if (player->get_x() == MAP_WIDTH) {
		if (player->get_keys() == keys_amount) running = false;
		else {
			move_player(3);
			gotoxy(player->get_x() + 1, player->get_y());
			printf("%c", 176);
		}
	}

	checking = false;
}

void E5MiniGame::add_key(Key* key) {
	key->draw(false);
	keys.push_back(key);
	keys_amount++;
}