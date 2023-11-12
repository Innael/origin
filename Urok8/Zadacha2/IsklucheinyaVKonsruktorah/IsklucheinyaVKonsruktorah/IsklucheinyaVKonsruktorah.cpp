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
#include "creation_exeption.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        Triangl t(70, 80, 90, 10, 100, 70);
        t.print_info(&t);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const summa_ugl_tr_er& ex) {
        std::cout << ex.what();
    }


    try {
        PryamougolnyiTriangl pt(60, 70, 80, 45, 45, 90);
        pt.print_info(&pt);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const ugl_pr_tr_not90_er& ex) {
        std::cout << ex.what();
    }
    catch (const summa_ugl_tr_er& ex) {
        std::cout << ex.what();
    }

    try {
        RavnobedrennyiTriangl rt(60, 70, 60, 30, 120, 30);
        rt.print_info(&rt);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const tr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const tr_neravenstvo_uglov_er& ex) {
        std::cout << ex.what();
    }
    catch (const summa_ugl_tr_er& ex) {
        std::cout << ex.what();
    }
    
    try {
        RavnostoronnyiTriangl rvnt(70, 70, 70, 60, 60 , 60);
        rvnt.print_info(&rvnt);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const rvnst_tr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const rvnst_tr_neravenstvo_uglov_er& ex) {
        std::cout << ex.what();
    }
    catch (const summa_ugl_tr_er& ex) {
        std::cout << ex.what();
    }
    
    try {
        Quad ch(20, 30, 40, 50, 30, 70, 90, 170);
        ch.print_info(&ch);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const summa_ugl_chtr_er& ex) {
        std::cout << ex.what();
    }
    

    try {
        Pryamougolnik pryamoug(30, 70, 30, 70, 90, 90, 90, 90);
        pryamoug.print_info(&pryamoug);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const summa_ugl_chtr_er& ex) {
        std::cout << ex.what();
    }
    catch (const tr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const chtr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const ugl_prmg_not90_er& ex) {
        std::cout << ex.what();
    }
    
    try {
        Kvadrat k(30, 30, 30, 30, 90, 90, 90, 90);
        k.print_info(&k);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const summa_ugl_chtr_er& ex) {
        std::cout << ex.what();
    }
    catch (const quadr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }   
    catch (const ugl_prmg_not90_er& ex) {
        std::cout << ex.what();
    }

    try {
        Parralelogram pr(50, 80, 50, 80, 60, 120, 60, 120);
        pr.print_info(&pr);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const summa_ugl_chtr_er& ex) {
        std::cout << ex.what();
    }
    catch (const tr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const chtr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const tr_neravenstvo_uglov_er& ex) {
        std::cout << ex.what();
    }
    catch (const prlgrm_neravenstvo_uglov_er& ex) {
        std::cout << ex.what();
    }
        
    try {
        Romb r(30, 30, 30, 30, 65, 115, 65, 115);
        r.print_info(&r);
        std::cout << "Фигура создана.\n\n";
    }
    catch (const summa_ugl_chtr_er& ex) {
        std::cout << ex.what();
    }
    catch (const quadr_neravenstvo_storon_er& ex) {
        std::cout << ex.what();
    }
    catch (const tr_neravenstvo_uglov_er& ex) {
        std::cout << ex.what();
    }
    catch (const prlgrm_neravenstvo_uglov_er& ex) {
        std::cout << ex.what();
    }  

    return 0;
}