#include <iostream>
#include <string>
#include <windows.h>

class bad_length: public std::exception {
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(std::string str, int forbidden_length) {
    int a = str.length();
    if (a == forbidden_length) throw bad_length();
    return a;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int zapretnaya_dlina = 0;
    std::string slovo = "";

    std::cout << "Введите запретную длину: ";
    std::cin >> zapretnaya_dlina ;
   
    for (int i = 0;;) {
        std::cout << "Введите слово: ";
        std::cin >> slovo ; 
        try {
            std::cout << "Длина слова " << '"' << slovo << '"' << " равна: " << function(slovo, zapretnaya_dlina) << "\n";
        }
        catch (const bad_length& ex) { std::cout << ex.what() << std::endl; return 0; }    
        
    }

    return 0;

}

