#pragma once
#include<string>
#include<vector>

#include "Environment.h"
#include "index.h"

#ifndef c5
#define c5
static std::vector<std::string*> create_c5();
void trigger_c5();
void initialize_items_c5(Stage* stage);

Stage* initialize_c5();
#endif // !c5