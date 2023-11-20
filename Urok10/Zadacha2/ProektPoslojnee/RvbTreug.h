#pragma once
#include "Treugolnik.h"

class RavnobedrennyiTriangl : public Triangl {

public:
    RavnobedrennyiTriangl(int dlina_a, int dlina_b, int ugol_A, int ugol_B);

    RavnobedrennyiTriangl();

    void print_info(Figura* ukazatel) override;
};