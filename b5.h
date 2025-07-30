#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef b5
#define b5
static std::vector<std::string*> create_b5();
void trigger_b5();
void initialize_items_b5(Stage* stage);

Stage* initialize_b5();
#endif // !b5