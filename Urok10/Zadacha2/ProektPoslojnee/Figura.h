#pragma once

class Figura {
protected:
    int storony;
    int dlina_a;
    int dlina_b;
    int dlina_c;
    int ugol_A;
    int ugol_B;
    int ugol_C;

public:
    Figura(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C);

    Figura();

    virtual void print_info(Figura* ukazatel);
};
