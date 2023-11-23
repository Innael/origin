#include <iostream>
#include "../LeaveLib/Goodbye.h"
#include<windows.h>

int main()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP(1251);

    Leaver l;
    std::string name = "";

    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << l.leave(name) ;

    std::cout << "Введите любой символ, если хотите, закрыть программу: ";
    std::cin >> name;

    return 0;
}


