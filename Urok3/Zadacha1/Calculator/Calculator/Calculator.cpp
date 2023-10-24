#include <iostream>
#include <string>
#include <windows.h>

class Calculator {
private:
    double num1;
    double num2;

public:
    Calculator () {
        this -> num1 = 1.0;
        this -> num2 = 1.0;
    }
public:
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else
            return  false;
    }
public:
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else
            return  false;
    }
    
        

    double add () {
         return num1 + num2;
    }

    double subtract_1_2() {
        return num1 - num2;
    }

    double subtract_2_1() {        
        return num2 - num1;
    }

    double multiply() {       
        return num1 * num2;
    }

    double divide_1_2() {
        return num1 / num2;
    }

    double divide_2_1() {       
        return num2 / num1;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a = 1;
    Calculator vychisleniya;

    for (int i;;) {
        for (int j = 0; j < 1; ){
            std::cout << "Введите num1: ";
            std::cin >> a;
            j = 1;
            if (vychisleniya.set_num1(a) != 1) {
                std::cout << "Неверный ввод!" << "\n";
                j = 0;
            }
        }

        for (int j = 0; j < 1; ) {
            std::cout << "Введите num2: ";
            std::cin >> a;
            j = 1;
            if (vychisleniya.set_num2(a) != 1) {
                std::cout << "Неверный ввод!" << "\n";
                j = 0;
            }
        }

        std::cout << "num1 + num2 = " << vychisleniya.add() << "\n";
        std::cout << "num1 - num2 = " << vychisleniya.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << vychisleniya.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << vychisleniya.multiply() << "\n";
        std::cout << "num1 / num2 = " << vychisleniya.divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << vychisleniya.divide_2_1() << "\n";
    }
    return 0;
}

