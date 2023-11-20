#include <iostream>
#include <windows.h>
#include "Figura.h"
#include "Treugolnik.h"
#include "PrTreug.h"
#include "RvbTreug.h"
#include "RvnsTr.h"
#include "Chetyrehugolnik.h"
#include "Pryamoug.h"
#include "Kvadrat.h"
#include "Paralgrm.h"
#include "Romb.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string Pausa = "";

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

    std::cout << "Введите любой символ, если хотите закрыть программу ";
    std::cin >> Pausa;

    return 0;
}