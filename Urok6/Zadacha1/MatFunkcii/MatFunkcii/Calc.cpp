
#include "Calc.h"

int slojenie(int& a, int& b) {
    return a + b;
}

int vychitanie(int& a, int& b) {
    return a - b;
}

int umnojenie(int& a, int& b) {
    return a * b;
}

long double delenie(int& a, int& b) {    
    return a / b;
}

long long stepen(int& a, int& b) {
    long long c = 0;
    c = a;
    if (b == 0)
        return 1;

    if (b < 0)
        b = -b;

    for (int i = 0; i < b - 1; ++i) {
        c = c * a;
    }
    return c;
}