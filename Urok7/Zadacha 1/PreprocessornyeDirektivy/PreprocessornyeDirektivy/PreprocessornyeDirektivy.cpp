#include <iostream>
#include <windows.h>

#define MODE 1
#ifndef MODE  
#error Константа MODE не определена
#endif // !MODE  

#if MODE == 1 
int add(int& a, int& b) {
    return a + b;
}
#endif

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#if MODE == 0
    std::cout << "Работаю в режиме тренировки";
#elif MODE != 1 && MODE != 0
    std::cout << "Неизвестный режим. Завершение работы.";
    return 0;
#else 
    int a = 0, b = 0; 
    std::cout << "Работаю в боевом режиме \n";
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a,b);
#endif    
        
    return 0;
}
