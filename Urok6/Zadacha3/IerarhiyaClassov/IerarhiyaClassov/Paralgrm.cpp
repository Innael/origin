#include <iostream>
#include "Paralgrm.h"

Parralelogram::Parralelogram(int dlina_a, int dlina_b, int ugol_A, int ugol_B) {
        storony = 4;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        dlina_c = dlina_a;
        dlina_d = dlina_b;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        ugol_C = ugol_A;
        ugol_D = ugol_B;
    }
Parralelogram::Parralelogram() {
        storony = 4;
        dlina_a = 20;
        dlina_b = 30;
        dlina_c = 20;
        dlina_d = 30;
        ugol_A = 60;
        ugol_B = 120;
        ugol_C = 60;
        ugol_D = 120;
    }
    void Parralelogram::print_info(Figura* ukazatel) {
        std::cout << "Параллелограм: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }