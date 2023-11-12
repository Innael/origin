#include <iostream>
#include "RvnsTr.h"
#include "creation_exeption.h"


 RavnostoronnyiTriangl::RavnostoronnyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        if (ugol_A + ugol_B + ugol_C != 180) throw summa_ugl_tr_er();
        if (dlina_a != dlina_b || dlina_a != dlina_c) throw rvnst_tr_neravenstvo_storon_er();
        if (ugol_A != ugol_B || ugol_C != ugol_A) throw rvnst_tr_neravenstvo_uglov_er();
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
    }

 RavnostoronnyiTriangl::RavnostoronnyiTriangl() {
        storony = 3;
        dlina_a = 50;
        dlina_b = 50;
        dlina_c = 50;
        ugol_A = 60;
        ugol_B = 60;
        ugol_C = 60;
    }
    void RavnostoronnyiTriangl::print_info(Figura* ukazatel) {
        std::cout << "Равносторонний треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }