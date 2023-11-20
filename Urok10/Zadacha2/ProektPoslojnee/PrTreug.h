#pragma once
#include "Treugolnik.h"

class PryamougolnyiTriangl : public Triangl {

public:
    PryamougolnyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B);

    PryamougolnyiTriangl();

    void print_info(Figura* ukazatel) override;
};