#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef e4
#define e4
static std::vector<std::string*> create_e4();
void trigger_e4();
void initialize_items_e4(Stage* stage);

Stage* initialize_e4();
#endif // !e4