#include <iostream>
#include <string>
#include <windows.h>

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
    Figura(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        storony = 0;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
    }

    Figura() {
        storony = 0;
        dlina_a = 0;
        dlina_b = 0;
        dlina_c = 0;
        ugol_A = 0;
        ugol_B = 0;
        ugol_C = 0;
    }    
    virtual void print_info(Figura* ukazatel) {
        std::cout << "Фигура: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
};

class Triangl : public Figura {
public:
    Triangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        storony = 3;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
    }

    Triangl() {
        storony = 3;
        dlina_a = 10;
        dlina_b = 10;
        dlina_c = 10;
        ugol_A = 30;
        ugol_B = 70;
        ugol_C = 80;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
};

class PryamougolnyiTriangl : public Triangl {

public:
    PryamougolnyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B) {
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        ugol_C = 90;
    }

    PryamougolnyiTriangl() {
        storony = 3;
        dlina_a = 40;
        dlina_b = 50;
        dlina_c = 30;
        ugol_A = 30;
        ugol_B= 60;
        ugol_C = 90;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Прямоугольный треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
};

class RavnobedrennyiTriangl : public Triangl {

public:
    RavnobedrennyiTriangl(int dlina_a, int dlina_b, int ugol_A, int ugol_B) {
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        dlina_c = dlina_a;
        ugol_C = ugol_A;
    }
 
    RavnobedrennyiTriangl() {
        storony = 3;
        dlina_a = 40;
        dlina_b = 40;
        dlina_c = 60;
        ugol_A = 70;
        ugol_B = 50;
        ugol_C = 70;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Равнобедренный треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
};

class RavnostoronnyiTriangl : public Triangl {
public:
    RavnostoronnyiTriangl(int dlina_a) {
        this->dlina_a = dlina_a;        
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        ugol_A = 60;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
    }

    RavnostoronnyiTriangl() {
        storony = 3;
        dlina_a = 50;
        dlina_b = 50;
        dlina_c = 50;
        ugol_A = 60;
        ugol_B = 60;
        ugol_C = 60;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Равносторонний треугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << "\n";
    }
};

class Quad : public Figura {
protected:
    int dlina_d;
    int ugol_D;
public:
    Quad(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D){
        storony = 4;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->dlina_d = dlina_d;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
        this->ugol_D = ugol_D;
    }
    Quad() {
        storony = 4;
        dlina_a = 10;
        dlina_b = 10;
        dlina_c = 10;
        dlina_d = 10;
        ugol_A = 90;
        ugol_B = 90;
        ugol_C = 90;
        ugol_D = 90;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Четырёхугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }
};

class Pryamougolnik : public Quad {
public:
    Pryamougolnik(int dlina_a, int dlina_b) {
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        dlina_c = dlina_a;
        dlina_d = dlina_b;
        ugol_A = 90;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
        ugol_D = ugol_A;
    }
    Pryamougolnik() {
        storony = 4;
        dlina_a = 20;
        dlina_b = 30;
        dlina_c = 20;
        dlina_d = 30;
        ugol_A = 90;
        ugol_B = 90;
        ugol_C = 90;
        ugol_D = 90;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Прямоугольник: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }
};

class Kvadrat : public Quad {
public:
    Kvadrat(int dlina_a) {
        this->dlina_a = dlina_a;
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        dlina_d = dlina_a;
        ugol_A = 90;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
        ugol_D = ugol_A;
    }
    Kvadrat() {
        storony = 4;
        dlina_a = 10;
        dlina_b = 10;
        dlina_c = 10;
        dlina_d = 10;
        ugol_A = 90;
        ugol_B = 90;
        ugol_C = 90;
        ugol_D = 90;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Квадрат: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }
};

class Parralelogram : public Quad {
public:
    Parralelogram(int dlina_a, int dlina_b, int ugol_A, int ugol_B) {
        storony = 4;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        dlina_c = dlina_a;
        dlina_d = dlina_b;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        ugol_C = ugol_A;
        ugol_D = ugol_B;
    }
    Parralelogram() {
        storony = 4;
        dlina_a = 20;
        dlina_b = 30;
        dlina_c = 20;
        dlina_d = 30;
        ugol_A = 60;
        ugol_B = 120;
        ugol_C = 60;
        ugol_D = 120;
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Параллелограм: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A << " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }
};

class Romb : public Quad {
public:
    Romb(int dlina_a, int ugol_A, int ugol_B) {
        storony = 4;
        this->dlina_a = dlina_a;
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        dlina_d = dlina_a;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        ugol_C = ugol_A;
        ugol_D = ugol_B;
    }
    Romb() {
        storony = 4;
        dlina_a = 30;
        dlina_b = 30;
        dlina_c = 30;
        dlina_d = 30;
        ugol_A = 60;
        ugol_B = 120;
        ugol_C = 60;
        ugol_D = 120;    
    }
    void print_info(Figura* ukazatel) override {
        std::cout << "Ромб: \n";
        std::cout << "Стороны: a = " << dlina_a << " b = " << dlina_b << " c = " << dlina_c << " d = " << dlina_d << "\n";
        std::cout << "Углы: A = " << ugol_A <<  " B = " << ugol_B << " C = " << ugol_C << " D = " << ugol_D << "\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangl t(30, 20, 70, 10, 100, 70);
    PryamougolnyiTriangl pt(60, 70, 80, 45, 45);
    RavnobedrennyiTriangl rt(60, 70, 30, 120);
    RavnostoronnyiTriangl rvnt(70);
    Quad ch(20, 30, 40, 50, 30, 70, 80, 150);
    Pryamougolnik pryamoug(30, 70);
    Kvadrat k(50);
    Parralelogram pr(30, 40, 70, 110);
    Romb r(30, 75, 115);

    t.print_info(&t);
    std::cout << "\n";
    pt.print_info(&pt);
    std::cout << "\n";
    rt.print_info(&rt);
    std::cout << "\n";
    rvnt.print_info(&rvnt);
    std::cout << "\n";
    ch.print_info(&ch);
    std::cout << "\n";
    pryamoug.print_info(&pryamoug);
    std::cout << "\n";
    k.print_info(&k);
    std::cout << "\n";
    pr.print_info(&pr);
    std::cout << "\n";
    r.print_info(&r);
    std::cout << "\n";

    return 0;
}

