#include <iostream>
#include "RvbTreug.h"
#include "creation_exeption.h"

RavnobedrennyiTriangl::RavnobedrennyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        if (ugol_A + ugol_B + ugol_C != 180) throw summa_ugl_tr_er();
        if ( dlina_a != dlina_c) throw tr_neravenstvo_storon_er();
        if (ugol_A != ugol_C) throw tr_neravenstvo_uglov_er();
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;       
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