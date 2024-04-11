#include <iostream>
#include <thread>
#include <windows.h>
#include <atomic>


void Line(int& count, std::atomic<int>& c) {
    for (int i = 0; i < count;) {
        Sleep(1000);
        ++c;
        std::cout << "В очереди, сейчас, ожидают приёма, " << c << ".\n";
        --count;
    }
}

void Reception(int& count, std::atomic<int>& c) {
    for (int i = 0; i < count;) {
        Sleep(2000);
        --c;
        std::cout << "Заявку обработали, и в очереди, сейчас, " << c << ".\n\n";
    }
    if (c > 0) {
        for (int i = 0; i < c;) {
            Sleep(2000);
            --c;
            std::cout << "Заявку обработали, и в очереди сейчас, " << c << " .\n\n";
        }
    }
}

int main()
{


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count = 0;
    std::atomic<int> c = 0;  // инициализация или присваивание при помощи оператора
    // c.store(10); // альтернативный вариант при помощи метода 
   
    //std::cout << c.is_lock_free();         // проверка, поддерживает ли железо, работу с атомарными операциями
    

    std::cout << "Сколько человек, сегодня, прийдёт получать услуги? ";
    std::cin >> count;

    std::thread line(Line, std::ref(count), std::ref(c) );
    std::thread reception(Reception, std::ref(count), std::ref(c));

    line.join();
    reception.join();

    std::cout << "На сегодня приём окончен.\n";

    return 0;
}