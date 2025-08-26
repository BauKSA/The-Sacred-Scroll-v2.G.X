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
	move(1);
}

void MiniGamePlayer::move_down() {
	move(0);
}

//BULLET
void A2Bullet::move_right() {
	move(2);
}

//ENEMY
void Enemy::move_left() {
	move(3);
}

//A2MiniGame
void A2MiniGame::print_points() const {
	print_text("Consegu5 quinientos puntos para pasar!");
	gotoxy(THIRD_HORIZONTAL_BAR_WIDTH + 1, MAP_Y_INIT + 3);
	printf("Pts.: %-5i", points);
}

void A2MiniGame::redraw() {
	std::lock_guard<std::mutex> lock(a2_mutex);
	for (std::unique_ptr<Enemy>& e : enemies) e->draw(true);
	for (std::unique_ptr<A2Bullet>& b : bullets) b->draw(true);
	if (player) player->draw(true);

	for (std::unique_ptr<Enemy>& e : enemies) e->draw(false);
	for (std::unique_ptr<A2Bullet>& b : bullets) b->draw(false);
	if (player) player->draw(false);
}

void A2MiniGame::check_positions() {
	bool change_points = false;
	checking = true;

	for (int i = bullets.size() - 1; i >= 0; --i) {
		if (bullets[i]->get_x() == 75) {
			bullets.erase(bullets.begin() + i);
		}
	}

	for (int j = enemies.size() - 1; j >= 0; --j) {
		bool enemy_removed = false;

		if (enemies[j]->get_x() <= 3) {
			points -= (player->get_y() == enemies[j]->get_y()) ? 150 : 15;
			if (points < 0) points = 0;
			change_points = true;
			enemies.erase(enemies.begin() + j);
			continue;
		}

		for (int i = bullets.size() - 1; i >= 0; --i) {
			if (enemies[j]->get_x() <= bullets[i]->get_x() &&
				enemies[j]->get_y() == bullets[i]->get_y()) {
				points += 75 - enemies[j]->get_x();
				change_points = true;

				enemies.erase(enemies.begin() + j);
				bullets.erase(bullets.begin() + i);
				enemy_removed = true;
				break;
			}
		}

		if (enemy_removed) continue;
	}

	if (change_points) print_points();
	checking = false;
}

void A2MiniGame::move_objects() {
	while (running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25));

		{
			std::lock_guard<std::mutex> lock(a2_mutex);

			for (std::unique_ptr<A2Bullet>& b : bullets) b->move_right();
			for (std::unique_ptr<Enemy>& e : enemies) e->move_left();

			check_positions();
		}
	}
}

void A2MiniGame::add_bullet(std::unique_ptr<A2Bullet> bullet) {
	if (bullets.size() < 3) {
		bullets.push_back(std::move(bullet));
	}
}

void A2MiniGame::add_enemy(std::unique_ptr<Enemy> enemy) {
	if (enemies.size() < 3) {
		enemies.push_back(std::move(enemy));
	}
}

void A2MiniGame::add_player(MiniGamePlayer* _player) {
	player = _player;
}