#include <iostream>
#include <windows.h>

enum class mesyac {    
    Январь = 1,
    Февраль,
    Март,
    Апрель,
    Май,
    Июнь,
    Июль,
    Август,
    Сентябрь,
    Октябрь,
    Ноябрь,
    Декабрь
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int nomer = 1;

    while (nomer != 0) {
        std::cout << "Введите номер месяца:";
        std::cin >> nomer;
        if (nomer > 12 || nomer < 0) {
            std::cout << "Неправильный номер!\n";
            continue;
        }        
        mesyac m = static_cast<mesyac>(nomer);
        switch (m) {
        case mesyac::Январь: std::cout << "Январь \n"; break;
        case mesyac::Февраль: std::cout << "Февраль \n"; break;
        case mesyac::Март: std::cout << "Март \n"; break;
        case mesyac::Апрель: std::cout << "Апрель \n"; break;
        case mesyac::Май: std::cout << "Май \n"; break;
        case mesyac::Июнь: std::cout << "Июнь \n"; break;
        case mesyac::Июль: std::cout << "Июль \n"; break;
        case mesyac::Август: std::cout << "Август \n"; break;
        case mesyac::Сентябрь: std::cout << "Сентябрь \n"; break;
        case mesyac::Октябрь: std::cout << "Октябрь \n"; break;
        case mesyac::Ноябрь: std::cout << "Ноябрь \n"; break;
        case mesyac::Декабрь: std::cout << "Декабрь \n"; break;
        }
    }
    std::cout << "До свидания";
    return 0;
}


