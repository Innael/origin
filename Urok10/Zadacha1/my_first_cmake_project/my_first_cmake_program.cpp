#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string Imya = "";

	std::cout << "������� ���: ";
	std::cin >> Imya;
	std::cout << "������������, " << Imya << "! \n\n";
	std::cout << "������� ����� ����, ���� ������ ������� ���������: ";
	std::cin >> Imya;
	return 0;
}