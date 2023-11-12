#pragma once
#include "Chetyrehugolnik.h"

class Romb : public Quad {
public:
    Romb(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D);

    Romb();

    void print_info(Figura* ukazatel) override;
};