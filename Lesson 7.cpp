#include <iostream>

class Fraction {
private:
	int number_one;
	int number_two;
	
public:
	Fraction(int f1, int f2) : number_one(f1), number_two(f2) {
	if (f2 == 0) {
	std::cout << "Ошибка: знаменатель равен нулю. Установлен в 1.\n";
	number_two = 1;
	}
	}
	Fraction() : number_one(0), number_two(1) {}

	Fraction operator+(const Fraction& other) const {
	return Fraction(number_one * other.number_two + other.number_one * number_two,number_two * other.number_two);
	}
	
	Fraction operator-(const Fraction& other) const {
	return Fraction(number_one * other.number_two - other.number_one * number_two,number_two * other.number_two);
	}
	
	Fraction operator*(const Fraction& other) const {
	return Fraction(number_one * other.number_one,number_two * other.number_two);
	}
	
	Fraction operator/(const Fraction& other) const {
	return Fraction(number_one * other.number_two,number_two * other.number_one);
	}

	bool operator==(const Fraction& other) const {
	return static_cast<long long>(number_one) * other.number_two ==
	static_cast<long long>(other.number_one) * number_two;
	}
	
	bool operator!=(const Fraction& other) const {
	return !(*this == other);
	}
	
	bool operator<(const Fraction& other) const {
	return static_cast<long long>(number_one) * other.number_two <
	static_cast<long long>(other.number_one) * number_two;
	}
	
	bool operator>(const Fraction& other) const { return other < *this; }
	bool operator<=(const Fraction& other) const { return !(other < *this); }
	bool operator>=(const Fraction& other) const { return !(*this < other); }
	

	Fraction operator-() const {
	return Fraction(-number_one, number_two);
	}
	
	Fraction& operator++() {
	number_one += number_two;
	return *this;
	}
	
	Fraction operator++(int) {
	Fraction temp = *this;
	number_one += number_two;
	return temp;
	}
	
	Fraction& operator--() {
	number_one -= number_two;
	return *this;
	}
	
	Fraction operator--(int) {
	Fraction temp = *this;
	number_one -= number_two;
	return temp;
	}
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
	friend std::istream& operator>>(std::istream& is, Fraction& f);
};


std::ostream& operator<<(std::ostream& ostr, const Fraction& f) {
	ostr << f.number_one << "/" << f.number_two;
	return ostr;
}


std::istream& operator>>(std::istream& istr, Fraction& f) {
	istr >> f.number_one >> f.number_two;
	if (f.number_two == 0) {
	std::cout << "Предупреждение: знаменатель не может быть нулём. Установлен в 1.\n";
	f.number_two = 1;
	}
	return istr;
}

int main() {
	
	Fraction f1, f2;
	
	return 0;
};

