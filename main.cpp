#include<iostream>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<vector>

#include "Functions.h"
#include "Player.h"
#include "Environment.h"

#include "init_interface.h"

#include "a1.h"
#include "a2.h"
#include "a3.h"
#include "a4.h"
#include "a5.h"

#include "b1.h"
#include "b2.h"
#include "b3.h"
#include "b4.h"
#include "b5.h"

#include "c1.h"
#include "c2.h"
#include "c3.h"
#include "c4.h"
#include "c5.h"

#include "d1.h"
#include "d2.h"
#include "d3.h"
#include "d4.h"
#include "d5.h"

#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "e4.h"
#include "e5.h"

struct Particle {
	float x, y;
	float dx, dy;
};

static void run_explosion_once() {

	int left = 1, TOP = 5;
	int right = 77, BOTTOM = 18;

	const int num_particles = 120;
	const int max_frames = 20;

	int origin_x = left + rand() % (right - left + 1);
	int origin_y = TOP + rand() % (BOTTOM - TOP + 1);

	std::vector<Particle> particles;

	for (int i = 0; i < num_particles; ++i) {
		float angle = (rand() % 360) * 3.14159f / 180.0f;
		float speed = (rand() % 100) / 100.0f + 0.3f;
		particles.push_back({
			static_cast<float>(origin_x),
			static_cast<float>(origin_y),
			cos(angle) * speed,
			sin(angle) * speed
			});
	}

	int offset = 0;

	for (int frame = 0; frame < max_frames; ++frame) {
		offset += 5;
		for (const auto& p : particles) {
			int px = static_cast<int>(p.x + p.dx * frame);
			int py = static_cast<int>(p.y + p.dy * frame);

			if (px >= left && px <= right && py >= TOP && py <= BOTTOM) {
				gotoxy(px, py);
				std::cout << "*";
			}
		}



		std::this_thread::sleep_for(std::chrono::milliseconds(50 + offset));
	}
}

static void clear_area() {
	int left = 1, TOP = 5;
	int right = 77, BOTTOM = 18;
	for (int y = TOP; y <= BOTTOM; ++y) {
		for (int x = left; x <= right; ++x) {
			gotoxy(x, y);
			std::cout << " ";
		}
	}
}

static void fireworks() {

	std::srand(static_cast<unsigned>(std::time(nullptr)));

	while (true) {
		clear_area();
		colour();
		run_explosion_once();
	}
}

int main() {

	//INICIALIZAMOS STAGES
	Stage* stage_a1 = initialize_a1();
	Stage* stage_a2 = initialize_a2();
	Stage* stage_a3 = initialize_a3();
	Stage* stage_a4 = initialize_a4();
	Stage* stage_a5 = initialize_a5();

	Stage* stage_b1 = initialize_b1();
	Stage* stage_b2 = initialize_b2();
	Stage* stage_b3 = initialize_b3();
	Stage* stage_b4 = initialize_b4();
	Stage* stage_b5 = initialize_b5();

	Stage* stage_c1 = initialize_c1();
	Stage* stage_c2 = initialize_c2();
	Stage* stage_c3 = initialize_c3();
	Stage* stage_c4 = initialize_c4();
	Stage* stage_c5 = initialize_c5();

	Stage* stage_d1 = initialize_d1();
	Stage* stage_d2 = initialize_d2();
	Stage* stage_d3 = initialize_d3();
	Stage* stage_d4 = initialize_d4();
	Stage* stage_d5 = initialize_d5();

	Stage* stage_e1 = initialize_e1();
	Stage* stage_e2 = initialize_e2();
	Stage* stage_e3 = initialize_e3();
	Stage* stage_e4 = initialize_e4();
	Stage* stage_e5 = initialize_e5();

	Interface* gameInterface = initialize_interface();
	Environment* environment = new Environment(gameInterface);

	environment->add_stage(stage_a1);
	environment->add_stage(stage_a2);
	environment->add_stage(stage_a3);
	environment->add_stage(stage_a4);
	environment->add_stage(stage_a5);

	environment->add_stage(stage_b1);
	environment->add_stage(stage_b2);
	environment->add_stage(stage_b3);
	environment->add_stage(stage_b4);
	environment->add_stage(stage_b5);

	environment->add_stage(stage_c1);
	environment->add_stage(stage_c2);
	environment->add_stage(stage_c3);
	environment->add_stage(stage_c4);
	environment->add_stage(stage_c5);

	environment->add_stage(stage_d1);
	environment->add_stage(stage_d2);
	environment->add_stage(stage_d3);
	environment->add_stage(stage_d4);
	environment->add_stage(stage_d5);

	environment->add_stage(stage_e1);
	environment->add_stage(stage_e2);
	environment->add_stage(stage_e3);
	environment->add_stage(stage_e4);
	environment->add_stage(stage_e5);

	//Creamos al jugador
	Position* player_pos = new Position;
	player_pos->x = 10;
	player_pos->y = 8;

	Player* player = new Player(*player_pos);
	environment->add_player(player);

	//Agregamos al Player a las Stage que lo usan
	stage_a4->use_player(player);
	stage_b1->use_player(player);
	stage_b4->use_player(player);
	stage_c2->use_player(player);
	stage_c5->use_player(player);
	stage_d5->use_player(player);
	stage_e4->use_player(player);
	stage_d2->use_player(player);
	stage_e1->use_player(player);


	//Inicializamos el juego en STAGE C3
	environment->init_stage(stage_c3->get_id());

	gameInterface->draw_items(player);
	environment->draw_dynamics();
	environment->draw_password();
	environment->draw_stage();

	while (environment->is_running()) {
		environment->tick();
	}

	print_text("Fin del juego!");

	gotoxy(1, 6);
	fireworks();

	return 0;
}