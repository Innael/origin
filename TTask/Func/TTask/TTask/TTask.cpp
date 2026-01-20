// TTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <string>
#include <cmath>

#ifdef _UNICODE
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif

double quadratic_equation(int a, int b, int c) 
{
    double d = 0;
    double x = 0;
    double X1, X2;

    if (a == 0) {
        x = - c / b;
        return x;
    }

    d = (b * b) - (4 * a * c);

    if (d < 0) return 0;    
    else if (d == 0) {
        x = (-b + sqrt(d)) / (2 * a);
    } 
    else
    {
        X1 = (-b + sqrt(d)) / (2 * a);
        X2 = (-b - sqrt(d)) / (2 * a);
        (X1 > X2 ? x = X1 : x = X2);
    }

    return x;
}

TCHAR* GetNewStr(TCHAR* str, bool& is_equal)
{
    size_t length = _tcslen(str);
    TCHAR* temp = new TCHAR[length + 1];
    temp[0] = str[length - 1];

    for (int i = 0; i < length - 1; ++i) {
        temp[i + 1] = str[i];
    }

    temp[length] = _T('\0');

    is_equal = (_tcscmp(temp, str) == 0);

    return temp;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int A, B, C;
    bool type_check = false;
    std::cout << "Введите коофиценты квадратного уравнения: \n" ;

        std::cout << "A = ";
        std::cin >> A;
        std::cout << std::endl;       
   
        std::cout << "B = ";
        std::cin >> B;
        std::cout << std::endl;
           
    
        std::cout << "C = ";
        std::cin >> C;
        std::cout << std::endl;
       

    std::cout << "x = " << quadratic_equation(A, B, C) << std::endl;


    bool is_equal = false;
    std::string my_string;

    std::cout << "Введите строку: \n";
    std::cin >> my_string;
    std::cout << std::endl;

    TCHAR* t_str = new TCHAR[my_string.length() + 1];

    for (int i = 0; i < my_string.length(); ++i) {
        t_str[i] = (TCHAR)my_string[i];
    }

    t_str[my_string.length()] = _T('\0');

    TCHAR* new_t_str = GetNewStr(t_str, is_equal);

    tcout << new_t_str << std::endl;
    std::cout << (is_equal == false ? "Строки не равны." : "Строки равны.");

    delete[] new_t_str;
    delete[] t_str;

    return 0;
}

