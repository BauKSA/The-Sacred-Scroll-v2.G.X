#include<conio.h>

#include "c3.h"
#include "Player.h"

static std::vector<std::string*> create_c3() {
	std::string* c3_00 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaaaaaw");
	std::string* c3_01 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyyyyyw");
	std::string* c3_02 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwyy*yyw");
	std::string* c3_03 = new std::string("wwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwyyyyyyyyyyyyyyyyywwyyyyyw");
	std::string* c3_04 = new std::string("iyyyywwyyyyyyyyyyyyyyyykyyyyyyyyyyyyyyyyywwtyyyywwyyyyyyyyyyyyyyyyywwyyyyyw");
	std::string* c3_05 = new std::string("iyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwtyyyyypyyyyyyyyyyyyyyyyywwwwwwww");
	std::string* c3_06 = new std::string("iyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwtyyyyypyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_07 = new std::string("wyyyywwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwtyyyyypyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_08 = new std::string("wyyywwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwtyyyywwyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_09 = new std::string("wrrrwwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_10 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_11 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_12 = new std::string("wyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyw");
	std::string* c3_13 = new std::string("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");

	std::vector<std::string*> _c3 = { c3_00, c3_01, c3_02, c3_03, c3_04, c3_05, c3_06, c3_07,
	c3_08, c3_09, c3_10, c3_11, c3_12, c3_13 };

	return _c3;
}

static bool trigger_c3(bool complete, Player* player = nullptr) {
	print_text("Bienvenido a The Sacred Scroll! El objetivo del juego es encontrar toas las contrase8as y decodificar los nombres de los guardianes. Necesitar3s el c6digo ASCII para completar esta misi6n. Mucha suerte!");
	return true;
}

void event_c3_func() {
	print_text("        Menu                             Continuar (L)                             W -> Arriba          S -> Abajo           A -> Izquierda        D -> Derecha        L -> Accion           ");
	while (_getch() != ACTION);

	clear_text();
	return;
}

void initialize_items_c3(Stage* stage) {
	Position offset{};
	offset.x = 0;
	offset.y = 0;
	std::string name = "Llave C3";
	Door* door = new Door("puerta_c3", 'p');
	Items* key = new Items(name, 'k', 244, offset, name, 'p', {}, "puerta_c3");
	Items* pass = new Items("password", '*', 207, offset, "password", 'p', {}, "");

	stage->add_item(key);
	stage->add_item(pass);
	stage->add_door(door);
}

const static std::vector<std::string*> c3_map = create_c3();

Stage* initialize_c3() {
	Stage* stage_c3 = new Stage(c3_map, "C3");

	Event* event_c3 = new Event(event_c3_func);

	stage_c3->set_trigger(trigger_c3);
	stage_c3->set_event(event_c3);

	initialize_items_c3(stage_c3);

	return stage_c3;
}