#include <iostream>
#include "Figura.h"



   Figura::Figura(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        storony = 0;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
    }

    Figura::Figura() {
        storony = 0;
        dlina_a = 0;
        dlina_b = 0;
        dlina_c = 0;
        ugol_A = 0;
        ugol_B = 0;
        ugol_C = 0;
    }
     void Figura::print_info(Figura* ukazatel) {
        std::cout << "Фигура: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
 