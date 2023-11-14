#include <iostream>

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
	bool operator==(Fraction drob) {
		if (this->numerator_ == drob.numerator_ && this->denominator_ == drob.denominator_) 
			return true;		
		else return false;
	}
	bool operator!=(Fraction drob) {
		return !(*this == drob);
	}
	bool operator<(Fraction drob) {
		if (this->numerator_ / this->denominator_ < drob.numerator_ / drob.denominator_)
			return true;
		else return false;
	}
	bool operator>(Fraction drob) {
		return !(*this < drob);
	}
	bool operator<=(Fraction drob) {
		return !(*this > drob);
	}
	bool operator>=(Fraction drob) {
		return !(*this < drob);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}