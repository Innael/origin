#include <iostream>
#include "Treugolnik.h"


Triangl::Triangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        storony = 3;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
    }

Triangl::Triangl() {
        storony = 3;
        dlina_a = 10;
        dlina_b = 10;
        dlina_c = 10;
        ugol_A = 30;
        ugol_B = 70;
        ugol_C = 80;
    }
    void Triangl::print_info(Figura* ukazatel){
        std::cout << "Треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
