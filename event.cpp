#include "Event.h"

void Event::tick() {
	event();
	active = false;
}