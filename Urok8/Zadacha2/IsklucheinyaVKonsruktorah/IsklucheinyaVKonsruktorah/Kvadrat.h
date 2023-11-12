#pragma once
#include "Chetyrehugolnik.h"

class Kvadrat : public Quad {
public:
    Kvadrat(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D);

    Kvadrat();

    void print_info(Figura* ukazatel) override;
};