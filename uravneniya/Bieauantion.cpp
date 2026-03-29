#include "Biequantion.h"
Biequantion::Biequantion(double a, double b, double c) : a(a), b(b), c(c) {}
Biequantion::Biequantion(const Biequantion& rhs) : a(rhs.a), b(rhs.b), c(rhs.c) {}
Biequantion::Biequantion(Biequantion&& rhs) noexcept : a(rhs.a), b(rhs.b), c(rhs.c) {
	rhs.a = 0;
	rhs.b = 0;
	rhs.c = 0;
}
void Biequantion::print() {
	if (b && c) {
		std::cout << ((a < 0) ? "-" : "-\b") << a << "x^2" << ((b < 0) ? " - " : " + ") << b << "x" << ((c < 0) ? " - " : " + ") << c << " = 0\n";
	}
	else if (b) {
		std::cout << ((a < 0) ? "-" : "-\b") << a << "x^2" << ((b < 0) ? " - " : " + ") << b << "x" << " = 0\n";
	}
	else if (c) {
		std::cout << ((a < 0) ? "-" : "-\b") << a << "x^2" << ((c < 0) ? " - " : " + ") << c << " = 0\n";
	}
}
void Biequantion::solve() {
	double D{ b * b - 4 * a * c };
	if (D > 0) {
		std::cout << "x_1 = " << (-b + sqrt(D)) / 2 * a << ", x_2 = " << (-b + sqrt(D)) / 2 * a << '\n';
	}
	else if (D == 0) {
		std::cout << "x = " << -b / 2 * a << '\n';
	}
	else {
		std::cout << "No solutions\n";
	}
}
		/*std::cout << "No resheniy\n  ____________________\n _                    _\n_    ___        ___    _\n_                      _\n_                      _\n_                      _\n_       ________       _\n _                    _ \n  ____________________";*/