#include "Lenear.h"
Linear::Linear(double a, double b) : a(a), b(b) {}
Linear::Linear(const Linear& rhs) : a(rhs.a), b(rhs.b) {}
Linear::Linear(Linear&& rhs) noexcept : a(rhs.a), b(rhs.b)  {
	rhs.a = 0;
	rhs.b = 0;
}
void Linear::print() {
	if (b) {
		std::cout << ((a < 0) ? "-" : "-\b") << a << 'x' << ((b < 0) ? " - " : " + ") << b << " = 0\n";
	}
	else {
		std::cout << ((a < 0) ? "-" : "-\b") << a << 'x' << " = 0\n";
	}
}
void Linear::solve() {
	if (a && b) {
		std::cout << "x = " <<  - b / a << '\n';
	}
	else if (a == 0) {
		std::cout << "No solutions\n";
	}
	else {
		std::cout << "Reverse 8 resheniy\n";
	}
}