#include <iostream>
#include "PrTreug.h"
#include "creation_exeption.h"


PryamougolnyiTriangl::PryamougolnyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        if (ugol_A + ugol_B + ugol_C != 180) throw summa_ugl_tr_er();
        if (ugol_C != 90) throw ugl_pr_tr_not90_er();
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
        ;
    }

PryamougolnyiTriangl::PryamougolnyiTriangl() {
        storony = 3;
        dlina_a = 40;
        dlina_b = 50;
        dlina_c = 30;
        ugol_A = 30;
        ugol_B = 60;
        ugol_C = 90;
    }

    void PryamougolnyiTriangl::print_info(Figura* ukazatel) {
        std::cout << "������������� �����������: \n";
        std::cout << "�������: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "����: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
