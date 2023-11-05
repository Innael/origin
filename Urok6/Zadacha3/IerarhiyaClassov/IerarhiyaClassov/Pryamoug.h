#pragma once
#include "Chetyrehugolnik.h"

class Pryamougolnik : public Quad {
public:
    Pryamougolnik(int dlina_a, int dlina_b);

    Pryamougolnik();

    void print_info(Figura* ukazatel) override;
};
