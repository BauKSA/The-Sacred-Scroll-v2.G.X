#pragma once
#include<vector>
#include<string>

class Password {
public:
	static const std::vector<std::string> encoded_password;
	static std::string get_password(int i);
};