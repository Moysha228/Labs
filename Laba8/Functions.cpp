#ifndef Functions
#define Functions
#include <fstream>
#include <string>
#include <iostream>
bool CheckInputFile(std::ifstream& fin) {
	if (!fin.good()) {
		throw "file doesn't exist\n";
	}
	if (!fin) {
		throw "input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}
}
void OutputArrayToConsole(double* array, size_t size) {
	std::cout << '\n';
	for (size_t i{}; i < size; ++i) {
		std::cout << array[i] << '\t';
	}
}
void FillArrayFromConsole(double* array, size_t size) {
	for (size_t i{}; i < size; ++i) {
		std::cin >> array[i];
	}
}
void OutputArrayToFile(std::ostream& fout, double* array, size_t size) {
	fout << '\n';
	for (size_t i{}; i < size; ++i) {
		fout << array[i] << '\t';
	}
}
void Sort(double* array, size_t size, void (*Sorts[4])(double*, size_t, bool)) {
	std::cout << "Choose sort:\n(1)Quick sort\n(2)Insertion sort\n(3)Selection sort\n(4)Improved bubble sort";
	size_t sort{};
	std::cin >> sort;
	std::cout << "Reverse(>0) or classic(0) sort?\n";
	bool reverse{};
	std::cin >> reverse;
	Sorts[sort - 1](array, size, reverse);
}
int Compare(const void* a, const void* b) {
	double res {(*((double*)a) - *((double*)b))};
	if (res > 0)
		return 1;
	if (res < 0)
		return -1;
	else
		return 0;
}
int ReverseCompare(const void* a, const void* b) {
	double res{ (*((double*)a) - *((double*)b)) };
	if (res > 0)
		return -1;
	if (res < 0)
		return 1;
	else
		return 0;
}
void QuickSort(double* array, size_t size, bool reverse) {
	if(reverse)
	    qsort(array, size, sizeof(double), ReverseCompare);
	else
		qsort(array, size, sizeof(double), Compare);
}
void Swap(double& a, double& b) {
	double temp{};
	temp = a;
	a = b;
	b = temp;
}
void InsertionSort(double* array, size_t size, bool reverse) {
	if (reverse) {
		for (size_t i{ 1 }; i < size; ++i) {
			if (array[i] > array[i - 1] && i > 0) {
				Swap(array[i], array[i-- - 1]);
				--i;
			}
		}
	}
	else {
		for (size_t i{ 1 }; i < size; ++i) {
			if (array[i] < array[i - 1] && i > 0) {
				Swap(array[i], array[i - 1]);
				--i;
			}
		}
	}
}
void SelectionSort(double* array, size_t size, bool reverse) {
	size_t max{ size - 1 };
	if (reverse) {
		while (size) {
			for (size_t i{}; i < size; ++i) {
				if (array[i] < array[max])
					max = i;
			}
			Swap(array[--size], array[max]);
			max = size - 1;
		}
	}
	else {
		while (size) {
			for (size_t i{}; i < size; ++i) {
				if (array[i] > array[max])
					max = i;
			}
			Swap(array[--size], array[max]);
		}
	}
}
void ImprovedBubbleSort(double* array, size_t size, bool reverse) {
	bool check{ 1 };
	if (reverse) {
		while (size && check) {
			check = 0;
			for (size_t i{}; i < size - 1; ++i) {
				if (array[i] < array[i + 1]) {
					Swap(array[i], array[i + 1]);
					++i;
					check = 1;
				}
			}
			--size;
		}
	}
	else {
		while (size && check) {
			check = 0;
			for (size_t i{}; i < size - 1; ++i) {
				if (array[i] > array[i + 1]) {
					Swap(array[i], array[i + 1]);
					check = 1;
				}
			}
			--size;
		}
	}
}
struct Students {
	std::string name{};
	std::string surname{};
	int16_t studying_year{};
	std::string group{};
	int16_t marks[5];
};
#endif