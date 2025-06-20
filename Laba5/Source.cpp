#include <iostream>
#include "Functions.h"
int main() {
	//variant 5
	try {
		int32_t** mtr = nullptr;
		std::cout << "Input height and weidth of matrix\n";
		size_t rows{};
		size_t columns{};
		InputSize(rows);
		InputSize(columns);
		if (rows <= 0 || columns <= 0)
			throw std::invalid_argument("Size of the matrix should be positive");
		CreateMtr(mtr, rows , columns);
		std::cout << "Fill array automatically(1) or manually(0)?\n";
		int16_t type{};
		std::cin >> type;
		if (type == 1) {
			std::cout << "Input borders of the interval\n";
			int32_t a{};
			int32_t b{};
			std::cin >> a >> b;
			if (a == b)
				throw std::invalid_argument("Borders of the interval shouldn't be equal");
			if (a > b)
				Swap(a, b);
			AutoFillMtr(mtr, rows, columns, a, b);
		}
		if (type == 0) {
			std::cout << "Input elements of matrix\n";
			ManualFillMtr(mtr, rows, columns);
		}
		PrintMtr(mtr, rows, columns);
		std::cout << "\nProduct of non negative rows is " << ProductOfNonNegRows(mtr, rows, columns) << '\n';
		MakeTheBiggestPosNumTheFirstByRowsAndColumnsSwap(mtr, rows, columns);
		PrintMtr(mtr, rows, columns);
		DeleteMtr(mtr, rows);
	}
	catch (std::invalid_argument e) {
		std::cout << "ERROR: " << e.what();
	}
}