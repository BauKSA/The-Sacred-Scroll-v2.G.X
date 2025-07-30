#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef d5
#define d5
static std::vector<std::string*> create_d5();
void trigger_d5();
void initialize_items_d5(Stage* stage);

Stage* initialize_d5();
#endif // !d5