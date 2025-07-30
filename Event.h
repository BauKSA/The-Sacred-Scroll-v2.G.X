#pragma once
typedef void (*EventFunction)();

class Event {
private:
	EventFunction event = nullptr;
	bool active;
public:
	Event(EventFunction _event) :
		event(_event), active(true) {};

	bool is_active() const { return active; }
	void tick();
};