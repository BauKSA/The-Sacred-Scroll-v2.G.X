#include "Password.h"

const std::vector<std::string> Password::encoded_password = {
	"01001100", "01101001", "01110100", "01101001", "01101101", "01110101"
};

std::string Password::get_password(int i) {
	if (i >= 0 && i < Password::encoded_password.size()) {
		return Password::encoded_password.at(i);
	}

	return "ERROR";
}