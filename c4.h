#pragma once
#include<string>
#include<vector>

#include "index.h"

#ifndef c4
#define c4
static std::vector<std::string*> create_c4();
void trigger_c4();
void initialize_items_c4(Stage* stage);

Stage* initialize_c4();
#endif // !c4