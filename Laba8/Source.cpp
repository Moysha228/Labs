#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Functions.h"
int main() {
	void (*Sorts[4])(double*, size_t, bool) = {QuickSort, InsertionSort, SelectionSort, ImprovedBubbleSort};
	int16_t type{};
	std::cout << "Fill array from _ and output result to _:\n1. file/console\n2. console/file\n3. file/file\n";
	std::cin >> type;
	try {
		if (type != 1 || type != 2 || type != 3)
			throw std::logic_error("wrong type's number");
		switch (type) {
		case(1): {
			std::ifstream fin("Text.txt.txt");

			CheckInputFile(fin);
			double array[100]{};
			size_t i{};
			std::string a{};
			while (std::getline(fin, a, ' ')) {
				array[i++] = stod(a);
			}
			Sort(array, i, Sorts);
			OutputArrayToConsole(array, i);
			break;
		}
		case(2): {
			size_t size{};
			std::cout << "Input amount of numbers\n";
			std::cin >> size;
			if (size <= 0)
				throw std::logic_error("size should be positive");
			double* array = nullptr;
			array = new double[size];
			FillArrayFromConsole(array, size);
			Sort(array, size, Sorts);
			OutputArrayToConsole(array, size);
			delete[] array;
			break;
		}
		case(3): {
			std::ifstream fin("Text.txt.txt");
			CheckInputFile(fin);
			double array[100]{};
			size_t i{};
			std::string a{};
			while (std::getline(fin, a, ' ')) {
				array[i++] = stod(a);
			}
			Sort(array, i, Sorts);
			std::ofstream fout("Text.txt.txt", std::ios::app);
			OutputArrayToFile(fout, array, i);
			break;
		}
		}
	}
	catch (std::logic_error e) {
		std::cout << "ERROR: " << e.what();
	}
	catch (const char* e) {
		std::cout << e;
	}
}