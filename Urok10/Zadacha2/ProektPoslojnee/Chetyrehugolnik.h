#pragma once
#include "Figura.h"

class Quad : public Figura {
protected:
    int dlina_d;
    int ugol_D;
public:
    Quad(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D);

    Quad();

    void print_info(Figura* ukazatel) override;
};