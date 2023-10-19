#include <iostream>
#include <string>
#include <windows.h>

struct account {
    long long nomer;
    std::string name;
    long double balans;
};

void opper(account& a) {
    std::cout << "Введите новый баланс:";
    std::cin >> a.balans;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    account a{ 0, "Кто то" , 0 };
    std::cout << "Введите номер счёта: ";
    std::cin >> a.nomer;
    std::cout << "Введите имя владельца: ";
    std::cin >> a.name;
    std::cout << "Введите баланс: ";
    std::cin >> a.balans;
    opper(a);
    std::cout << "Ваш счёт: " << a.name << ", " << a.nomer << ", " << a.balans;
    return 0;
}

