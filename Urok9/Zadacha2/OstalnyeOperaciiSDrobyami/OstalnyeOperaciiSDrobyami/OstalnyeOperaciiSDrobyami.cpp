#include <iostream>
#include <windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void Set_num(int a) {
		numerator_ = a;
	}
	void Set_denom(int b) {
		denominator_ = b;
	}
	int Get_num() {
		return numerator_;
	}
	int Get_denom() {
		return denominator_;
	}
	Fraction operator+(Fraction drob) {
		return Fraction(this->numerator_ * drob.denominator_ + drob.numerator_ * this->denominator_, this->denominator_ * drob.denominator_);
	}
	Fraction operator-(Fraction drob) {
		return Fraction(this->numerator_ * drob.denominator_ - drob.numerator_ * this->denominator_, this->denominator_ * drob.denominator_);
	}
	Fraction operator*(Fraction drob) {
		return Fraction(this->numerator_ * drob.numerator_, this->denominator_ * drob.denominator_);
	}
	Fraction operator/(Fraction drob) {
		return Fraction(this->numerator_ * drob.denominator_, drob.numerator_ * this->denominator_);
	}
	Fraction operator-() {
		Fraction temp(numerator_,denominator_);
		temp.numerator_ = -1 * temp.numerator_;
			return temp;
	}
	Fraction& operator++() {
		numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction operator++(int) {
		Fraction temp = *this;
		this->numerator_ = this->numerator_ + this->denominator_;
		return temp;
	}
	Fraction& operator--() {
		numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction operator--(int) {
		Fraction temp = *this;
		this->numerator_ = this->numerator_ - this->denominator_;
		return temp;
	}
};

int main()
{
	SetConsoleCP (1251);
	SetConsoleOutputCP (1251);

	Fraction f1(4, 3);
	Fraction f2(6, 11);
	Fraction f3(1, 1);
	int a = 0, b = 1; 


	for (int i = 0; i < 2;) {
		std::cout << "Введите числитель дроби: ";
		std::cin >> a;
		if (a == 0)
			std::cout << "Дробь, с таким числителем, равна нулю и, по факту, не является дробью. \n";
		else i = 2;
	}
    f1.Set_num(a);

	for (int i = 0; i < 2;) {
		std::cout << "Введите знаменатель дроби: ";
		std::cin >> b;
		if (b == 0)
			std::cout << "Знаменатель не должен равняться нулю. \n";
		else i = 2;
	}
	f1.Set_denom(b);

	for (int i = 0; i < 2;) {
		std::cout << "Введите числитель дроби: ";
		std::cin >> a;
		if (a == 0)
			std::cout << "Дробь, с таким числителем, равна нулю и, по факту, не является дробью. \n";
		else i = 2;
	}
	f2.Set_num(a);

	for (int i = 0; i < 2;) {
		std::cout << "Введите знаменатель дроби: ";
		std::cin >> b;
		if (b == 0)
			std::cout << "Знаменатель не должен равняться нулю. \n";
		else i = 2;
	}
	f2.Set_denom(b);

	f3 = f1 + f2;
	std::cout << f1.Get_num() << "/" << f1.Get_denom() << " + " << f2.Get_num() << "/" << f2.Get_denom() << " = " << f3.Get_num() << "/" << f3.Get_denom() << "\n";

	f3 = f1 - f2;
	std::cout << f1.Get_num() << "/" << f1.Get_denom() << " - " << f2.Get_num() << "/" << f2.Get_denom() << " = " << f3.Get_num() << "/" << f3.Get_denom() << "\n";

	f3 = f1 * f2;
	std::cout << f1.Get_num() << "/" << f1.Get_denom() << " * " << f2.Get_num() << "/" << f2.Get_denom() << " = " << f3.Get_num() << "/" << f3.Get_denom() << "\n";

	f3 = f1 / f2;
	std::cout << f1.Get_num() << "/" << f1.Get_denom() << " / " << f2.Get_num() << "/" << f2.Get_denom() << " = " << f3.Get_num() << "/" << f3.Get_denom() << "\n";

	f3 = -f1;
	std::cout << "-" << f1.Get_num() << "/" << f1.Get_denom() << " = " << f3.Get_num() << "/" << f3.Get_denom() << "\n";
	
	std::cout << "++" << f1.Get_num() << "/" << f1.Get_denom() << " * " << f2.Get_num() << "/" << f2.Get_denom() << " = ";
	f3 = ++f1 * f2;
	std::cout << f3.Get_num() << "/" << f3.Get_denom() << "\n";
	std::cout << "Значение дроби 1: " << f1.Get_num() << "/" << f1.Get_denom() << "\n";

	
	std::cout << f1.Get_num() << "/" << f1.Get_denom() << "--" << " * " << f2.Get_num() << "/" << f2.Get_denom() << " = ";
	f3 = f1-- * f2;
	std::cout << f3.Get_num() << "/" << f3.Get_denom() << "\n";
	std::cout << "Значение дроби 1: " << f1.Get_num() << "/" << f1.Get_denom() << "\n";

	return 0;
}