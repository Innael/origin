#include <iostream>
#include "Ground.h"

Ground::Ground() {
	std::string name = "��������";
	speed = 1;
	stamina = 1;
	rest = 1;
}

std::string Ground::Get_name() {
	return name;
}