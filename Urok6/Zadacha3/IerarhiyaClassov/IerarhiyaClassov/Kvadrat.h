#pragma once
#include "Chetyrehugolnik.h"

class Kvadrat : public Quad {
public:
    Kvadrat(int dlina_a);

    Kvadrat();

    void print_info(Figura* ukazatel) override;
};