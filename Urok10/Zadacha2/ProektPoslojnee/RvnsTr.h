#pragma once
#include "Treugolnik.h"

class RavnostoronnyiTriangl : public Triangl {
public:
    RavnostoronnyiTriangl(int dlina_a);

    RavnostoronnyiTriangl();

    void print_info(Figura* ukazatel) override;
};
