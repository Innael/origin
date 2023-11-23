#include <iostream>
#include <string>
#include <windows.h>
#include "Greeter.h"

int main()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    Greeter g;
    std::string name = " ";

    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << g.greet(name) << "\n";

    std::cout << "Введите любой символ, чтобы закрыть программу: ";
    std::cin >> name;

    return 0;
}


