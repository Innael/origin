#pragma once
#include "Treugolnik.h"

class RavnostoronnyiTriangl : public Triangl {
public:
    RavnostoronnyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C);

    RavnostoronnyiTriangl();

    void print_info(Figura* ukazatel) override;
};
