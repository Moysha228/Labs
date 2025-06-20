#include <iostream>
void InputSize(int32_t& size) {
	std::cout << "Input size of the array\n";
	std::cin >> size;
	if (size <= 0) {
		throw std::logic_error("Size should be positive");
	}
}
int32_t CountSignChanges(int32_t* array, int32_t size) {
	bool sign{};
	if (array[0] >= 0)
		sign = 1;
	int32_t changes{};
	for (size_t i{1}; i < size; ++i) {
		switch(sign){
		case 1:{
			if (array[i] < 0) {
				sign = 0;
				++changes;
			}
			break;
		}
		case 0: {
			if (array[i] >= 0) {
				sign = 1;
				++changes;
			}
			break;
		}
		}
	}
	return changes;
}
int32_t ProductOfNumbersBetweenZeros(int32_t* array, int32_t size) {
	int32_t first_zero_pos{ -1 };
	int32_t i{};
	while (i < size && first_zero_pos == -1) {
		if (array[i] == 0)
			first_zero_pos = i;
		++i;
	}
	if (first_zero_pos == -1) {
		throw std::logic_error("No zeros");
	}
	int32_t second_zero_pos{ -1 };
	while (i < size && second_zero_pos == -1) {
		if (array[i] == 0)
			second_zero_pos = i;
		++i;
	}
	if (second_zero_pos == -1) {
		throw std::logic_error("Not enough zeros");
	}
	if (first_zero_pos == second_zero_pos - 1)
		throw std::logic_error("No numbers between zeros");
	++first_zero_pos;
    int32_t product{ 1 };
	while (first_zero_pos < second_zero_pos) {
	    product *= array[first_zero_pos++];
	}
	return product;
}
#include <cmath>
int32_t NumWitnMinSummDifference(double* array, int32_t size) {
	double left_summ{};
	double right_summ{};
	double min_diff{};
	int32_t left_nums{};
	int32_t right_nums{};
	double diff{};
	int32_t num{};
    int32_t i{ 1 };
	while (i < size - 1) {
		left_nums = 0;
		for (left_nums; left_nums < i; ++left_nums) {
			left_summ += array[left_nums];
		}
		right_nums = i + 1;
		for (right_nums; right_nums < size; ++right_nums) {
			right_summ += array[right_nums];
		}
		diff = abs(right_summ - left_summ);
		if (i == 1)
			min_diff = diff;
		if (min_diff > diff) {
			min_diff = diff;
			num = i;
		}
		++i;
	}
	return num;
}
void Swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void Swap(double& a, double& b) {
	double temp{a};
	a = b;
	b = temp;
}
void SortByParity(int32_t* array, int32_t size) {
	size_t counter{};
	for (size_t i{}; i < size; ++i) {
		if (array[i] % 2 == 1 && i < size - counter) {
			++counter;
			for (size_t t{ i }; t < size - 1; ++t)
				Swap(array[t], array[t + 1]);
			--i;
		}
	}
}
void FindModularlyMaxNum(double* array, int32_t size) {
	int32_t pos_of_max_num{};
	for (int32_t i{}; i < size; ++i) {
		if (abs(array[i]) > abs(array[pos_of_max_num]))
			pos_of_max_num = i;
	}
	std::cout << "\nMaximal number modularly is " << array[pos_of_max_num] << " and position of this number if " << pos_of_max_num;
}
void ShrinkArray(double* array, int32_t size, double a, double b) {
	int32_t i{};
	int32_t size_copy{ size };
	for (i; i < size; ++i) {
		if (array[i] > a && array[i] < b) {
			Swap(array[i--], array[size-- - 1]);
		}
	}
	while (++size <= size_copy) {
		array[size - 1] = 0;
	}
}