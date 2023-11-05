#pragma once
#include "Chetyrehugolnik.h"

class Parralelogram : public Quad {
public:
    Parralelogram(int dlina_a, int dlina_b, int ugol_A, int ugol_B);

    Parralelogram();

    void print_info(Figura* ukazatel) override;
};