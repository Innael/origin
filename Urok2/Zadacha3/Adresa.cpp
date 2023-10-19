#include <iostream>
#include <string>
#include <windows.h>

const int  N = 3;

struct adress {
    std::string city;
    std::string street;
    int dom;
    int room;
    int index;
};

void svodka(adress a[N]) {
    for (int i = 0; i < N; ++i) {
        std::cout << "Город: " << a[i].city << "\n";
        std::cout << "Улица: " << a[i].street << "\n";
        std::cout << "Номер дома: " << a[i].dom << "\n";
        std::cout << "Номер квартиры: " << a[i].room << "\n";
        std::cout << "Индекс: " << a[i].index << "\n\n";
    }

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    adress basa[N]{
        {"Воронеж", "Печорского", 5, 2, 332564},
        {"Рязань" , "Комсомольцев", 14 , 7 , 442810},
        {"Омск" , "Ермака", 42 , 3, 158112}
    };

    svodka(basa);
    
    return 0;
}


