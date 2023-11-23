#include "Greeter.h"

std::string Greeter::greet(std::string name) {
    std::string greetings = "Здравствуйте, ";
        std::string greetings2 = "!";
        return greetings + name + greetings2;
}