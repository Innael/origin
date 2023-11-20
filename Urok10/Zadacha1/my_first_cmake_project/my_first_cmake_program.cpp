#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string Imya = "";

	std::cout << "¬ведите им€: ";
	std::cin >> Imya;
	std::cout << "«дравствуйте, " << Imya << "! \n\n";
	std::cout << "¬ведите любой знак, если хотите закрыть программу: ";
	std::cin >> Imya;
	return 0;
}