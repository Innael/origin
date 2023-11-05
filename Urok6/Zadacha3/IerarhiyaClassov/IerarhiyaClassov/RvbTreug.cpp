#include <iostream>
#include "RvbTreug.h"

RavnobedrennyiTriangl::RavnobedrennyiTriangl(int dlina_a, int dlina_b, int ugol_A, int ugol_B) {
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        dlina_c = dlina_a;
        ugol_C = ugol_A;
    }

RavnobedrennyiTriangl::RavnobedrennyiTriangl() {
        storony = 3;
        dlina_a = 40;
        dlina_b = 40;
        dlina_c = 60;
        ugol_A = 70;
        ugol_B = 50;
        ugol_C = 70;
    }
    void RavnobedrennyiTriangl::print_info(Figura* ukazatel) {
        std::cout << "Равнобедренный треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }