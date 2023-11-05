#pragma once
#include "Figura.h"

class Triangl : public Figura {
public:
    Triangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C);

    Triangl();

    void print_info(Figura* ukazatel) override;
};