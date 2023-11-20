#include <iostream>
#include "Romb.h"

Romb::Romb(int dlina_a, int ugol_A, int ugol_B) {
        storony = 4;
        this->dlina_a = dlina_a;
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        dlina_d = dlina_a;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        ugol_C = ugol_A;
        ugol_D = ugol_B;
    }
Romb::Romb() {
        storony = 4;
        dlina_a = 30;
        dlina_b = 30;
        dlina_c = 30;
        dlina_d = 30;
        ugol_A = 60;
        ugol_B = 120;
        ugol_C = 60;
        ugol_D = 120;
    }
    void Romb::print_info(Figura* ukazatel) {
        std::cout << "Ромб: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }