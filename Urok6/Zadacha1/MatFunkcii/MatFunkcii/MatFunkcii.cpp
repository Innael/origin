#include <iostream>
#include <windows.h>
#include "Calc.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a = 0, b = 0, d = 0 ;

    for (int j = 0;;) {
        std::cout << "Введите первое число: ";
        std::cin >> a;
        std::cout << "Введите второе число: ";
        std::cin >> b;
        d = 0;
        while (d < 1 || d> 6) {
            std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень, 6 - завершить программу ): ";
            std::cin >> d;
        }

        switch (d) {
        case 1: std::cout << a << " + " << b << " = " << slojenie(a, b) << "\n"; break;
        case 2: std::cout << a << " - " << b << " = " << vychitanie(a, b) << "\n"; break;
        case 3: std::cout << a << " * " << b << " = " << umnojenie(a, b) << "\n"; break;
        case 4: std::cout << a << " / " << b << " = " << delenie(a, b) << "\n"; break;
        case 6: return 0;
        }

        if (d == 5) {
            if (b > -1)
                std::cout << a << " в степени " << b << " = " << stepen(a, b) << "\n";
            else
                std::cout << a << " в степени " << -b << " = 1/" << stepen(a, b) << "\n";
        }
    }
    return 0;
}


