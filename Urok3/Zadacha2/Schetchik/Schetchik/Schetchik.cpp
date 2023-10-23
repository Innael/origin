#include <iostream>
#include <string>
#include <windows.h>

class Counter {
private:
    int sch;

    Counter(int sch) {
        this->sch = sch;        
    }
 public:
    Counter() {
        sch = 1;
    }

    void Hochu(std::string vopros) {
        for (int i = 0; i < 1;) {
            std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";        
            std::cin >> vopros;
            if (vopros == "Да" || vopros == "да") {
                std::cout << "Введите начальное значение счётчика: ";
                std::cin >> sch;
                i = 1;
            }
            else if (vopros == "Нет" || vopros == "нет") {
                i = 1;
            }
        }
    };
    void Komanda(std::string znak) {
        for (int i = 0; i < 1; ) {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> znak;
        
            if (znak == "+") {
                ++sch;
            }
            else if (znak == "-") {
                --sch;
            }
            else if (znak == "=") {
                std::cout << sch << "\n";
            }
            else if (znak == "x" || znak == "х") {
                std::cout << "До свидания!";
                i = 1;
            }
        }
    };
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Counter schet;
    schet.Hochu("");
    schet.Komanda("");

    return 0;
}


