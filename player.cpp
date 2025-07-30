#include<conio.h>
#include<iostream>

#include "Player.h"
#include "Globals.h"
#include "Password.h"

void Player::add_items(Items* item) {
	items.push_back(item);
}

void Player::add_password() {
	std::string pass = Password::get_password(password.size());
	password.push_back(pass);
	print_text("Encontraste una parte de la contrase8a! Complet3 las ¿6 y podr3s acceder al Sacred Scroll.");
}

void Player::delete_items(std::string name) {
	int index = -1;
	for (size_t i = 0; i < items.size(); i++) {
		if (items.at(i)->name == name) {
			index = i;
		}
	}

	if (index >= 0) items.erase(items.begin() + index);
}

bool Player::has_key(std::string door_id) {
	bool has = false;

	for (size_t i = 0; i < items.size(); i++) {
		if (items.at(i)->door_to_unlock == door_id) {
			has = true;
			delete_items(items.at(i)->name);
			return has;
		}
	}

	return has;
}

void Player::throw_key(std::string door_id) {
	int index = -1;
	for (int i = 0; i < items.size(); i++) {
		if (items.at(i)->door_to_unlock == door_id) {
			index = i;
		}
	}

	if (index != -1) {
		items.erase(items.begin() + index);
	}
}

std::string Player::get_current_password(int i) {
	if (i >= 0 && i < password.size()) return password.at(i);
	return "ERROR";
}