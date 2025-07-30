#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef c1
#define c1
static std::vector<std::string*> create_c1();
void trigger_c1();
void initialize_items_c1(Stage* stage);

Stage* initialize_c1();
#endif // !c1