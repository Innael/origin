#include <iostream>
#include "Fly.h"

Fly::Fly() {
	std::string name = "���������";
	speed = 1.0;
	cruise = 1.0;
}

std::string Fly::Get_name() {
	return name;
}