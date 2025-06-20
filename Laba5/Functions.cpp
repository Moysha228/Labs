#include <iostream>
#include <random>
void InputSize(size_t& num) {
	std::cin >> num;
	if (num <= 0)
		throw std::invalid_argument("Incorrect size");
}
void Swap(int32_t& a, int32_t& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void CreateMtr(int32_t**& mtr, size_t rows, size_t columns) {
	mtr = new int32_t*[rows];
	for (size_t i{}; i < rows; ++i) {
		mtr[i] = new int32_t[columns];
	}
}
void DeleteMtr(int32_t**& mtr, size_t rows) {
	for (size_t i{}; i < rows; ++i) {
		delete[] mtr[i];
	}
	delete[] mtr;
}
void AutoFillMtr(int32_t** mtr, size_t rows, size_t columns, int32_t a, int32_t b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(a, b);
	for (size_t i{}; i < rows; ++i) {
		for (size_t j{}; j < columns; ++j) {
			mtr[i][j] = dist(gen);
		}
	}
}
void ManualFillMtr(int32_t** mtr, size_t rows, size_t columns) {
	for (size_t i{}; i < rows; ++i) {
		for (size_t j{}; j < columns; ++j) {
			std::cin >> mtr[i][j];
		}
	}
}
void PrintMtr(int32_t** mtr, size_t rows, size_t columns) {
	for (size_t i{}; i < rows; ++i) {
		for (size_t j{}; j < columns; ++j) {
			std::cout << mtr[i][j] << '\t';
		}
		std::cout << '\n';
	}
}
bool IsRowNonNeg(int32_t* array, size_t size) {
	for (size_t i{}; i < size; ++i) {
		if (array[i] < 0)
			return 0;
	}
	return 1;
}
int64_t ProductOfArray(int32_t* array, size_t size) {
	int64_t product{array[0]};
	for (size_t i{1}; i < size; ++i) {
		product *= array[i];
	}
	return product;
}
int64_t ProductOfNonNegRows(int32_t** mtr, size_t rows, size_t columns) {
	int64_t product{ 1 };
	bool correctness{};
	for (size_t i{}; i < rows; ++i) {
		if (IsRowNonNeg(mtr[i], columns)) {
			correctness = 1;
			product *= ProductOfArray(mtr[i], columns);
		}
	}
	if (correctness == 0)
		throw std::invalid_argument("There's no positive rows");
	return product;
}
void MakeRowTheFirst(int32_t** mtr, size_t row, size_t columns) {
	for (size_t i{}; i < columns; ++i)
		Swap(mtr[row][i], mtr[0][i]);
}
void MakeColumnTheFirst(int32_t** mtr, size_t rows, size_t column) {
	for (size_t i{}; i < rows; ++i)
		Swap(mtr[i][column], mtr[i][0]);
}
void MakeTheBiggestPosNumTheFirstByRowsAndColumnsSwap(int32_t** mtr, size_t rows, size_t columns) {
	int32_t max_pos_num{mtr[0][0]};
	size_t max_pos_nums_row{};
	size_t max_pos_nums_column{};
	for (size_t i{}; i < rows; ++i) {
		for (size_t t{}; t < columns; ++t) {
			if (mtr[i][t] > max_pos_num) {
				max_pos_num = mtr[i][t];
				max_pos_nums_row = i;
				max_pos_nums_column = t;
			}
		}
	}
	MakeRowTheFirst(mtr, max_pos_nums_row, columns);
	MakeColumnTheFirst(mtr, rows, max_pos_nums_column);
}