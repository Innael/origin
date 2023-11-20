#include <iostream>
#include "RvnsTr.h"


 RavnostoronnyiTriangl::RavnostoronnyiTriangl(int dlina_a) {
        this->dlina_a = dlina_a;
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        ugol_A = 60;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
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