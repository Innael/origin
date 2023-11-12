#pragma once
#include "Chetyrehugolnik.h"

class Pryamougolnik : public Quad {
public:
    Pryamougolnik(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D);

    Pryamougolnik();

    void print_info(Figura* ukazatel) override;
};
