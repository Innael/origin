#pragma once
#include "Chetyrehugolnik.h"

class Romb : public Quad {
public:
    Romb(int dlina_a, int ugol_A, int ugol_B);

    Romb();

    void print_info(Figura* ukazatel) override;
};