#include <iostream>
#include "Pryamoug.h"

Pryamougolnik::Pryamougolnik(int dlina_a, int dlina_b) {
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        dlina_c = dlina_a;
        dlina_d = dlina_b;
        ugol_A = 90;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
        ugol_D = ugol_A;
    }
Pryamougolnik::Pryamougolnik() {
        storony = 4;
        dlina_a = 20;
        dlina_b = 30;
        dlina_c = 20;
        dlina_d = 30;
        ugol_A = 90;
        ugol_B = 90;
        ugol_C = 90;
        ugol_D = 90;
    }
    void Pryamougolnik::print_info(Figura* ukazatel) {
        std::cout << "Прямоугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }

