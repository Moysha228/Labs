#include <iostream>
#include "Functions.h"
int main() {
	int32_t size{};
	try {
		InputSize(size);
		int32_t* array_int = nullptr;
		CreateArray(array_int, size);
		std::cout << "Fill array automatically(1) or manually(0)?\n";
		int16_t type{};
		InputNum(type);
		if (type != 1 && type != 0) {
			throw std::invalid_argument("Type of generating should be 1 or 0");
		}
		switch (type) {
		case 1:
			AutoFillArray(array_int, size);
			break;
		case 0:
			ManualFillArray(array_int, size);
			break;
		}
		PrintArray(array_int, size);
		std::cout << "\nNumber of sign changes is " << CountSignChanges(array_int, size) << '\n';
		std::cout << "Product of numbers between zeros is " << ProductOfNumbersBetweenZeros(array_int, size) << '\n';
		SortByParity(array_int, size);
		std::cout << "Array sorted by parity ";
		PrintArray(array_int, size);
		DeleteArray(array_int);
		std::cout << '\n';
		InputSize(size);
		double* array_double = nullptr;
		CreateArray(array_double, size);
		std::cout << "Fill array automatically(1) or manually(0)?\n";
		InputNum(type);
		if (type != 1 && type != 0) {
			throw std::invalid_argument("Type of generating should be 1 or 0");
		}
		switch (type) {
		case 1:
			AutoFillArray(array_double, size);
			break;
		case 0:
			ManualFillArray(array_double, size);
			break;
		}
		PrintArray(array_double, size);
		std::cout << "Number of element with minimal difference between summs of elements around it is " << NumWitnMinSummDifference(array_double, size);
		FindModularlyMaxNum(array_double, size);
		double a{};
		double b{};
		std::cout << "\nInput interval edges\n";
		InputNum(a);
		InputNum(b);
		if (a > b)
			Swap(a, b);
		ShrinkArray(array_double, size, a, b);
		PrintArray(array_double, size);
		DeleteArray(array_double);
		return 0;
	}
	catch (std::invalid_argument& e) {
		std::cout << "\nERROR: " << e.what();
	}
	catch (std::logic_error e) {
		std::cout << "\nERROR: " << e.what();
	}
}