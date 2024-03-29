﻿#include <iostream>
#include <string>
#include <windows.h>

class Figura {
protected:
    std::string Imya;
    int storony;
    int dlina_a;
    int dlina_b;
    int dlina_c;
    int dlina_d;
    int ugol_A;
    int ugol_B;
    int ugol_C;
    int ugol_D;

public:
    Figura(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D) {
        storony = 0;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->dlina_d = dlina_d;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
        this->ugol_D = ugol_D;
    }

    Figura() {
        Imya = "Фигура";
        storony = 0;
        dlina_a = 0;
        dlina_b = 0;
        dlina_c = 0;
        dlina_d = 0;
        ugol_A = 0;
        ugol_B = 0;
        ugol_C = 0;
        ugol_D = 0;
    }    
      std::string print_name() {
        return Imya;
    }
      int print_storony() {
          return storony;
      }     
     int print_dlina_a() {
        return dlina_a;
    }
     int print_dlina_b() {
        return dlina_b;
    }
     int print_dlina_c() {
        return dlina_c;
    }
     virtual int print_dlina_d() {
         return dlina_d;
     }
     int print_Ugol_A() {
        return ugol_A;
    }
     int print_Ugol_B() {
         return ugol_B;
     }
     int print_Ugol_C() {
         return ugol_C;
     }
     virtual int print_Ugol_D() {
         return ugol_D;
     }
};

class Triangl : public Figura {
public:
    Triangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B, int ugol_C) {
        Imya = "Треугольник";
        storony = 3;
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        this->ugol_C = ugol_C;
    }

    Triangl() {
        Imya = "Треугольник";
        storony = 3;
        dlina_a = 10;
        dlina_b = 10;
        dlina_c = 10;
        ugol_A = 30;
        ugol_B = 70;
        ugol_C = 80;
    }
        std::string print_name() {
            return Imya;
    }
        int print_dlina_a() {
            return dlina_a;
        }
        int print_dlina_b() {
            return dlina_b;
        }
        int print_dlina_c() {
            return dlina_c;
        }
        int print_Ugol_A() {
            return ugol_A;
        }
        int print_Ugol_B() {
            return ugol_B;
        }
        int print_Ugol_C() {
            return ugol_C;
        }
};

class PryamougolnyiTriangl : public Triangl {

public:
    PryamougolnyiTriangl(int dlina_a, int dlina_b, int dlina_c, int ugol_A, int ugol_B) {
        Imya = "Прямоугольный треугольник";
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->dlina_c = dlina_c;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        ugol_C = 90;
    }

    PryamougolnyiTriangl() {
        Imya = "Прямоугольный треугольник";
        storony = 3;
        dlina_a = 40;
        dlina_b = 50;
        dlina_c = 30;
        ugol_A = 30;
        ugol_B= 60;
        ugol_C = 90;
    }
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
};

class RavnobedrennyiTriangl : public Triangl {

public:
    RavnobedrennyiTriangl(int dlina_a, int dlina_b, int ugol_A, int ugol_B) {
        Imya = "Равнобедренный треугольник";
        this->dlina_a = dlina_a;
        this->dlina_b = dlina_b;
        this->ugol_A = ugol_A;
        this->ugol_B = ugol_B;
        dlina_c = dlina_a;
        ugol_C = ugol_A;
    }
 
    RavnobedrennyiTriangl() {
        Imya = "Равнобедренный треугольник";
        storony = 3;
        dlina_a = 40;
        dlina_b = 40;
        dlina_c = 60;
        ugol_A = 70;
        ugol_B = 50;
        ugol_C = 70;
    }
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
};

class RavnostoronnyiTriangl : public Triangl {
public:
    RavnostoronnyiTriangl(int dlina_a) {
        Imya = "Равносторонний треугольник";
        this->dlina_a = dlina_a;        
        dlina_b = dlina_a;
        dlina_c = dlina_a;
        ugol_A = 60;
        ugol_B = ugol_A;
        ugol_C = ugol_A;
    }

    RavnostoronnyiTriangl() {
        Imya = "Равносторонний треугольник";
        storony = 3;
        dlina_a = 50;
        dlina_b = 50;
        dlina_c = 50;
        ugol_A = 60;
        ugol_B = 60;
        ugol_C = 60;
    }
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
};

class Quad : public Figura {
protected:
    int dlina_d;
    int ugol_D;
public:
    Quad(int dlina_a, int dlina_b, int dlina_c, int dlina_d, int ugol_A, int ugol_B, int ugol_C, int ugol_D){
        Imya = "Четырёхугольник";
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
        Imya = "Четырёхугольник";
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
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_dlina_d() override {
        return dlina_d;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
    int print_Ugol_D() override {
        return ugol_D;
    }
};

class Pryamougolnik : public Quad {
public:
    Pryamougolnik(int dlina_a, int dlina_b) {
        Imya = "Прямоугольник";
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
        Imya = "Прямоугольник";
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
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_dlina_d() override {
        return dlina_d;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
    int print_Ugol_D() override {
        return ugol_D;
    }
};

class Kvadrat : public Quad {
public:
    Kvadrat(int dlina_a) {
        Imya = "Квадрат";
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
        Imya = "Квадрат";
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
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_dlina_d() override {
        return dlina_d;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
    int print_Ugol_D() override {
        return ugol_D;
    }
};

class Parralelogram : public Quad {
public:
    Parralelogram(int dlina_a, int dlina_b, int ugol_A, int ugol_B) {
        Imya = "Параллелограм";
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
        Imya = "Параллелограм";
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
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_dlina_d() override {
        return dlina_d;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
    int print_Ugol_D() override {
        return ugol_D;
    }
};

class Romb : public Quad {
public:
    Romb(int dlina_a, int ugol_A, int ugol_B) {
        Imya = "Ромб";
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
        Imya = "Ромб";
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
    std::string print_name() {
        return Imya;
    }
    int print_dlina_a() {
        return dlina_a;
    }
    int print_dlina_b() {
        return dlina_b;
    }
    int print_dlina_c() {
        return dlina_c;
    }
    int print_dlina_d() override {
        return dlina_d;
    }
    int print_Ugol_A() {
        return ugol_A;
    }
    int print_Ugol_B() {
        return ugol_B;
    }
    int print_Ugol_C() {
        return ugol_C;
    }
    int print_Ugol_D() override{
        return ugol_D;
    }
};

void print_info(Figura* ukazatel) {
    std::cout << ukazatel->print_name() << ": \n"; 
    if (ukazatel->print_storony() == 3) {
        std::cout << "Стороны: a = " << ukazatel->print_dlina_a() << " b = " << ukazatel->print_dlina_b() << " c = " << ukazatel->print_dlina_c() << "\n";
        std::cout << "Углы: A = " << ukazatel->print_Ugol_A() << " B = " << ukazatel->print_Ugol_B() << " C = " << ukazatel->print_Ugol_C() << "\n";
    }
    else if (ukazatel->print_storony() == 4) {
        std::cout << "Стороны: a = " << ukazatel->print_dlina_a() << " b = " << ukazatel->print_dlina_b() << " c = " << ukazatel->print_dlina_c() << " d = " << ukazatel->print_dlina_d() << "\n";
        std::cout << "Углы: A = " << ukazatel->print_Ugol_A() << " B = " << ukazatel->print_Ugol_B() << " C = " << ukazatel->print_Ugol_C() << " D = " << ukazatel->print_Ugol_D() << "\n";
    } 
}


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
    Romb r(50, 75, 115);

    print_info(&t);
    std::cout << "\n";
    print_info(&pt);
    std::cout << "\n";
    print_info(&rt);
    std::cout << "\n";
    print_info(&rvnt);
    std::cout << "\n";
    print_info(&ch);
    std::cout << "\n";
    print_info(&pryamoug);
    std::cout << "\n";
    print_info(&k);
    std::cout << "\n";
    print_info(&pr);
    std::cout << "\n";
    print_info(&r);
    std::cout << "\n";

    return 0;
}


