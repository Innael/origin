#include <iostream>
#include "Romb.h"
#include "creation_exeption.h"

Romb::Romb(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D) {
        storony = 4;
        if (ugol_A + ugol_B + ugol_C + ugol_D != 360) throw summa_ugl_chtr_er();
        if (dlina_a != dlina_b || dlina_a != dlina_c || dlina_a != dlina_d) throw quadr_neravenstvo_storon_er();
        if (ugol_A != ugol_C) throw tr_neravenstvo_uglov_er();
        if (ugol_B != ugol_D) throw prlgrm_neravenstvo_uglov_er();
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->dlina_d = dlina_d;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
        this->ugol_D = ugol_D;
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