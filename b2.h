#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef b2
#define b2
static std::vector<std::string*> create_b2();
void trigger_b2();
void initialize_items_b2(Stage* stage);

Stage* initialize_b2();
#endif // !b2