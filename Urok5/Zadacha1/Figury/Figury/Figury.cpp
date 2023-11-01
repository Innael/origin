#include <iostream>
#include <string>
#include <windows.h>


class Figura {
protected:
    int storony;

public:
    Figura() {
        storony = 0;
    }

public:

    void KtoYa() {
        switch (storony) {
        case 0: std::cout << "Фигура: " << storony << "\n"; break;
        case 3: std::cout << "Треугольник: " << storony << "\n"; break;
        case 4: std::cout << "Четырёхугольник: " << storony << "\n"; break;
        default: std::cout << "Данная фигура, выходит за пределы обсуждаемых параметров." << "\n"; break;
        }
    }

};

class Triangl : public Figura {
public:
    Triangl() {
        storony = 3;
    }
};

class Quadr : public Figura {
public:
    Quadr() {
        storony = 4;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    Figura fig;
    Triangl tri;
    Quadr qua;

    std::cout << "Количество сторон: " << "\n";
    fig.KtoYa();
    tri.KtoYa();
    qua.KtoYa();
    return 0;
}

