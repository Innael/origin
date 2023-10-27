#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class Adress {
    std::string gorod;
    std::string ulica;
    std::string dom;
    std::string kvartira;
    int schetchik;
public:
    Adress () {
     gorod = "Какой то город";
     ulica = "Какая то улица";
     dom = "1";
     kvartira = "1";
     schetchik = 1;
    }
    void vstroku(std::string& chitayu_i_to_i_eto) {
        if (schetchik == 1) {
            gorod = chitayu_i_to_i_eto;
            ++schetchik;
        }
        else if (schetchik == 2) {
            ulica = chitayu_i_to_i_eto;
            ++schetchik;
        }
        else if (schetchik == 3) {
            dom = chitayu_i_to_i_eto;
            ++schetchik;
        }
        else if (schetchik == 4) {
            kvartira = chitayu_i_to_i_eto;                     
            schetchik = 1;
        }
        
    }
    void izstroki(std::ofstream& zapis) {
        if (schetchik == 1) {
            zapis << gorod << ", ";
            ++schetchik;
        }
        else if
        (schetchik == 2) {
            zapis << ulica << ", ";
            ++schetchik;
        }
        else if
        (schetchik == 3) {
            zapis << dom << ", ";
            ++schetchik;
        }
        else if
            (schetchik == 4) {
            zapis << kvartira << std::endl;
            schetchik = 1;
        }
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream chtenie("in.txt");
    if (chtenie.is_open()) {
    }
    else {
        std::cout << "Отсутствует необходимый файл in.txt , программа будет закрыта ";
        return 0;
    }

    std::string chitayu_i_to_i_eto;
    chtenie >> chitayu_i_to_i_eto;
    int skolko = stoi(chitayu_i_to_i_eto);

    Adress* basa = new Adress[skolko];

    for (int j = 0; j < skolko; ++j) {
        for (int i = 0; i < 4; ++i) {
            chtenie >> chitayu_i_to_i_eto;
            basa[j].vstroku(chitayu_i_to_i_eto);
            if (chtenie.eof())
                break;
        }
    }

    std::ofstream zapis("out.txt");

    zapis << skolko << "\n";

    for (int j = 0; j < skolko; ++j) {
        for (int i = 0; i < 4; ++i) {
            basa[skolko-j-1].izstroki(zapis);
        }
    }
      

    chtenie.close();
    zapis.close();
    delete[] basa;
    return 0;
}


