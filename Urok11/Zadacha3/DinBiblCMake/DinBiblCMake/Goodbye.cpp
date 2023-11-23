#include "Goodbye.h"

std::string Leaver::leave(std::string name) {
	std::string bye1 = "До свидания, " ;
	std::string bye2 = "!\n" ;
	return bye1 + name + bye2;
}