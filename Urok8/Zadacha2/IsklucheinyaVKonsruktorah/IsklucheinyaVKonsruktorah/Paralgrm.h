#pragma once
#include "Chetyrehugolnik.h"

class Parralelogram : public Quad {
public:
    Parralelogram(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D);

    Parralelogram();

    void print_info(Figura* ukazatel) override;
};