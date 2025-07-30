#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef c3
#define c3
static std::vector<std::string*> create_c3();
void trigger_c3();
void event_c3_func();
void initialize_items_c3(Stage* stage);

Stage* initialize_c3();
#endif // !c3