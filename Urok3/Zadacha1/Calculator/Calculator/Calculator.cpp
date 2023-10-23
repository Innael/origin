#include <iostream>
#include <string>
#include <windows.h>

class Calculator {
public:
    double num1;
    double num2;

    Calculator (double num1, double num2) {
        this->num1 = num1;
        this->num1 = num2;
    }

    bool set_num1(double num1) {
        this->num1 = num1;
        if (num1 != 0)
            return true;       
    }

    bool set_num2(double num2) {
        this->num2 = num2;
        if (num2 != 0)
            return true;
    }

    void add (double a, double b) {
        a = num1;
        b = num2;
        std::cout << "num1 + num2 = " << a + b << "\n";
    }
    void subtract_1_2(double a, double b) {
        a = num1;
        b = num2;
        std::cout << "num1 - num2 = " << a - b << "\n";
    }

    void subtract_2_1(double a, double b) {
        a = num1;
        b = num2;
        std::cout << "num2 - num1 = " << b - a << "\n";
    }

    void multiply(double a, double b) {
        a = num1;
        b = num2;
        std::cout << "num1 * num2 = " << a * b << "\n";
    }

    void divide_1_2(double a, double b) {
        a = num1;
        b = num2;
        std::cout << "num1 / num2 = " << a / b << "\n";
    }

    void divide_2_1(double a, double b) {
        a = num1;
        b = num2;
        std::cout << "num2 / num1 = " << b / a << "\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double resultat = 0;
    Calculator vychisleniya(0, 0);

    for (int i;;) {
        for (int j = 0; j < 1; ){
            std::cout << "Введите num1: ";
            std::cin >> vychisleniya.num1;
            j = 1;
            if (vychisleniya.set_num1(vychisleniya.num1) != 1) {
                std::cout << "Неверный ввод!" << "\n";
                j = 0;
            }
        }

        for (int j = 0; j < 1; ) {
            std::cout << "Введите num2: ";
            std::cin >> vychisleniya.num2;
            j = 1;
            if (vychisleniya.set_num2(vychisleniya.num2) != 1) {
                std::cout << "Неверный ввод!" << "\n";
                j = 0;
            }
        }

        vychisleniya.add(0, 0);
        vychisleniya.subtract_1_2(0, 0);
        vychisleniya.subtract_2_1(0, 0);
        vychisleniya.multiply(0, 0);
        vychisleniya.divide_1_2(0, 0);
        vychisleniya.divide_2_1(0, 0);
    }
    return 0;
}

