#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class Adress {
    std::string gorod;
    std::string ulica;
    std::string dom;
    std::string kvartira;
public:
    Adress () {
     gorod = "Какой то город";
     ulica = "Какая то улица";
     dom = "1";
     kvartira = "1";
    }
    void setGorod(std::string& chitayu_i_to_i_eto) {
        gorod = chitayu_i_to_i_eto;
    };

    void setUlica(std::string& chitayu_i_to_i_eto) {
        ulica = chitayu_i_to_i_eto;
    };
    
    void setDom(std::string& chitayu_i_to_i_eto) {
        dom = chitayu_i_to_i_eto;
    };

    void setKvartira(std::string& chitayu_i_to_i_eto) {
        kvartira = chitayu_i_to_i_eto;
    };        
 

    std::string getGorod() {
        return gorod;
    };
    
    std::string getUlica() {
        return ulica;

    };
    
    std::string getDom() {
        return dom;
    };
    
    std::string getKvartira() {
     return kvartira;
    };
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
            chtenie >> chitayu_i_to_i_eto;
            basa[j].setGorod(chitayu_i_to_i_eto);
            chtenie >> chitayu_i_to_i_eto;
            basa[j].setUlica(chitayu_i_to_i_eto);
            chtenie >> chitayu_i_to_i_eto;
            basa[j].setDom(chitayu_i_to_i_eto);
            chtenie >> chitayu_i_to_i_eto;
            basa[j].setKvartira(chitayu_i_to_i_eto);
            if (chtenie.eof())
                break;        
    }

    std::ofstream zapis("out.txt");

    zapis << skolko << "\n";

    for (int j = 0; j < skolko; ++j) {
     zapis << basa[skolko-j-1].getGorod();
     zapis << " ";
     zapis << basa[skolko - j - 1].getUlica();
     zapis << " ";
     zapis << basa[skolko - j - 1].getDom();
     zapis << " ";
     zapis << basa[skolko - j - 1].getKvartira();
     zapis << "\n";     
    }      

    chtenie.close();
    zapis.close();
    delete[] basa;
    return 0;
}


