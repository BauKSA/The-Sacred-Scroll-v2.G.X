#include<thread>
#include<chrono>
#include<iostream>
#include<conio.h>
#include<vector>
#include<mutex>

#include "Functions.h"
#include "Globals.h"
#include "A2MiniGame.h"

std::mutex a2_mutex;


//PLAYER
void MiniGamePlayer::move_up() {
	std::lock_guard<std::mutex> lock(a2_mutex);
	move(1);
}

void MiniGamePlayer::move_down() {
	std::lock_guard<std::mutex> lock(a2_mutex);
	move(0);
}

//BULLET
void A2Bullet::move_right() {
	move(2);
}

//ENEMY
void Enemy::move_left() {
	std::lock_guard<std::mutex> lock(a2_mutex);
	move(3);
}

//A2MiniGame
void A2MiniGame::print_points() const {
	print_text("Consegu5 quinientos puntos para pasar!");
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + 3);
	printf("Pts.:      ");
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + 3);
	printf("Pts.: %i", points);
}

void A2MiniGame::redraw() {
	std::lock_guard<std::mutex> lock(a2_mutex);
	for (size_t i = 0; i < MAP_HEIGHT - 1; i++) {
		gotoxy(3, MAP_Y_INIT + i);
		for (size_t j = 0; j < MAP_WIDTH - 1; j++) {
			printf(" ");
		}
	}

	for (size_t i = 0; i < enemies.size(); i++) {
		enemies.at(i)->draw(false);
	}

	for (size_t i = 0; i < bullets.size(); i++) {
		enemies.at(i)->draw(false);
	}

	player->draw(false);
}

void A2MiniGame::check_positions() {
	std::lock_guard<std::mutex> lock(a2_mutex);
	bool change_points = false;
	checking = true;
	std::vector<int> indexes{};
	std::vector<int> enemy_indexes{};
	for (size_t i = 0; i < bullets.size(); i++) {
		if (bullets.at(i)->get_x() == 75) {
			indexes.push_back(i);
		}
		else {
			for (size_t j = 0; j < enemies.size(); j++) {
				if (enemies.at(j)->get_x() <= 3) {
					if (player->get_y() == enemies.at(i)->get_y()) points -= 150;
					else points -= 15;
					if (points < 0) points = 0;
					change_points = true;
					enemy_indexes.push_back(j);
				}
				else if (enemies.at(j)->get_x() <= bullets.at(i)->get_x()
					&& enemies.at(j)->get_y() == bullets.at(i)->get_y()) {
					points += 75 - enemies.at(j)->get_x();
					change_points = true;
					enemy_indexes.push_back(j);
					indexes.push_back(i);
				}
			}
		}
	}

	if (bullets.size() < 1) {
		for (size_t i = 0; i < enemies.size(); i++) {
			if (enemies.at(i)->get_x() <= 3) {
				if (player->get_y() == enemies.at(i)->get_y()) points -= 150;
				else points -= 15;
				if (points < 0) points = 0;
				enemy_indexes.push_back(i);
				change_points = true;
			}
		}
	}

	for (size_t i = 0; i < indexes.size(); i++) {
		delete bullets.at(indexes.at(i));
		bullets.erase(bullets.begin() + indexes.at(i));
	}

	for (size_t i = 0; i < enemy_indexes.size(); i++) {
		delete enemies.at(enemy_indexes.at(i));
		enemies.erase(enemies.begin() + enemy_indexes.at(i));
	}

	if (change_points) print_points();
	checking = false;
	change_points = false;
}

void A2MiniGame::move_bullets() {
	while (running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		for (size_t i = 0; i < bullets.size(); i++) {
			if (bullets.at(i) != nullptr) {
				bullets.at(i)->move_right();
				if (!checking) check_positions();
			}
		}
	}
}

void A2MiniGame::move_enemies() {
	while (running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(15));
		for (size_t i = 0; i < enemies.size(); i++) {
			if (enemies.at(i) != nullptr) {
				enemies.at(i)->move_left();
				if (!checking) check_positions();
			}
		}
	}
}

void A2MiniGame::add_bullet(A2Bullet* bullet) {
	if (bullets.size() < 3) {
		bullets.push_back(bullet);
	}
}

void A2MiniGame::add_enemy(Enemy* enemy) {
	if (enemies.size() < 3) {
		enemies.push_back(enemy);
	}
}

void A2MiniGame::add_player(MiniGamePlayer* _player) {
	player = _player;
}