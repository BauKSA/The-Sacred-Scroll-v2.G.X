#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef d3
#define d3
static std::vector<std::string*> create_d3();
void trigger_d3();
void initialize_items_d3(Stage* stage);

Stage* initialize_d3();
#endif // !d3