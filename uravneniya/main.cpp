#include "Biequantion.h"
int main() {
	int32_t a{};
	int32_t b{};
	std::cout << "Input coefficients of a linear equation: ";
	std::cin >> a >> b;
	Linear lin(a, b);
	lin.print();
	lin.solve();
	int32_t c{};
	std::cout << "Input coefficients of a biequantion: ";
	std::cin >> a >> b >> c;
	Biequantion bi(a, b, c);
	bi.print();
	bi.solve();
}