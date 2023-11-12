#include <iostream>
#include "Kvadrat.h"
#include "creation_exeption.h"


Kvadrat::Kvadrat(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D) {
    storony = 4;
    if (ugol_A + ugol_B + ugol_C + ugol_D != 360) throw summa_ugl_chtr_er();
    if (dlina_a != dlina_b || dlina_a != dlina_c || dlina_a != dlina_d) throw quadr_neravenstvo_storon_er();
    if (ugol_A != 90 || ugol_B != 90 || ugol_C != 90 || ugol_D != 90) throw ugl_prmg_not90_er();
    this->dlina_a = dlina_a;
    this->dlina_b = dlina_b;
    this->dlina_c = dlina_c;
    this->dlina_d = dlina_d;
    this->ugol_A = ugol_A;
    this->ugol_B = ugol_B;
    this->ugol_C = ugol_C;
    this->ugol_D = ugol_D;
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
