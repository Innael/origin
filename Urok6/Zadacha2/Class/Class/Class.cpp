﻿#include <iostream>
#include <string>
#include <windows.h>
#include "Uchet.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a = 1;

    std::string vopros = "";
    for (int i = 0; i < 1;) {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> vopros;
        if (vopros == "Да" || vopros == "да") {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> a;
            i = 1;
        }
        else if (vopros == "Нет" || vopros == "нет") {
            i = 1;
        }
    }

    Counter schet(a);

    std::string znak = "";
    for (int i = 0; i < 1; ) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> znak;

        if (znak == "+") {
            schet.UjeNeHochu();
        }
        else if (znak == "-") {
            schet.IschoHochu();
        }
        else if (znak == "=") {
            std::cout << schet.Naschitali() << "\n";
        }
        else if (znak == "x" || znak == "х") {
            std::cout << "До свидания!";
            i = 1;
        }
    }

    return 0;
}
