#include <iostream>
#include "Kvadrat.h"


Kvadrat::Kvadrat(int dlina_a) {
        this->dlina_a = dlina_a;
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        dlina_d = dlina_a;
        ugol_A = 90;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
        ugol_D = ugol_A;
    }
Kvadrat::Kvadrat() {
        storony = 4;
        dlina_a = 10;
        dlina_b = 10;
        dlina_c = 10;
        dlina_d = 10;
        ugol_A = 90;
        ugol_B = 90;
        ugol_C = 90;
        ugol_D = 90;
    }
    void Kvadrat::print_info(Figura* ukazatel) {
        std::cout << "Квадрат: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }
