#include "Complex.h"
int main() {
	try {
		Complex first_num;
		Complex second_num;
		char answer{};
		do {
			std::cout << "Choose your operation: module(m), arg(a), +, -, *\n";
			std::cin >> answer;
			switch (answer) {
			case('a'):
				std::cout << "Input real and imaginary parts of number: ";
				std::cin >> first_num;
				std::cout << "Result: " << first_num.arg() << '\n';
				std::cout << "Continue?(y) ";
				std::cin >> answer;
			case('m'):
				std::cout << "Input real and imaginary parts of number: ";
				std::cin >> first_num;
				std::cout << "Result: " << first_num.module() << '\n';
				std::cout << "Continue?(y) ";
				std::cin >> answer;
			case('+'):
				std::cout << "Input real and imaginary parts of two numbers: ";
				std::cin >> first_num;
				std::cin >> second_num;
				if (first_num.get_im() == 0) {
					int32_t int_first_num{ first_num.get_re() };
					if (second_num.get_im() == 0) {
						int32_t int_second_num{ second_num.get_re() };
						std::cout << "Result: " << int_first_num + int_second_num << '\n';
					}
					else {
						std::cout << "Result: " << int_first_num + second_num << '\n';
					}
				}
				else {
					if (second_num.get_im() == 0) {
						int32_t int_second_num{ second_num.get_re() };
						std::cout << "Result: " << first_num + int_second_num << '\n';
					}
					else {
						std::cout << "Result: " << first_num + second_num << '\n';
					}
				}
				std::cout << "Continue?(y) ";
				std::cin >> answer;
			case('-'):
				std::cout << "Input real and imaginary parts of two numbers: ";
				std::cin >> first_num;
				std::cin >> second_num;
				if (first_num.get_im() == 0) {
					int32_t int_first_num{ first_num.get_re() };
					if (second_num.get_im() == 0) {
						int32_t int_second_num{ second_num.get_re() };
						std::cout << "Result: " << int_first_num - int_second_num << '\n';
					}
					else {
						std::cout << "Result: " << int_first_num - second_num << '\n';
					}
				}
				else {
					if (second_num.get_im() == 0) {
						int32_t int_second_num{ second_num.get_re() };
						std::cout << "Result: " << first_num - int_second_num << '\n';
					}
					else {
						std::cout << "Result: " << first_num - second_num << '\n';
					}
				}
				std::cout << "Continue?(y) ";
				std::cin >> answer;
			case('*'):
				std::cout << "Input real and imaginary parts of two numbers: ";
				std::cin >> first_num;
				std::cin >> second_num;
				if (first_num.get_im() == 0) {
					int32_t int_first_num{ first_num.get_re() };
					if (second_num.get_im() == 0) {
						int32_t int_second_num{ second_num.get_re() };
						std::cout << "Result: " << int_first_num * int_second_num << '\n';
					}
					else {
						std::cout << "Result: " << int_first_num * second_num << '\n';
					}
				}
				else {
					if (second_num.get_im() == 0) {
						int32_t int_second_num{ second_num.get_re() };
						std::cout << "Result: " << first_num * int_second_num << '\n';
					}
					else {
						std::cout << "Result: " << first_num * second_num << '\n';
					}
				}
				std::cout << "Continue?(y) ";
				std::cin >> answer;
			}
		} while (answer == 'y');
		std::cout << "Your num by get_re and get_im: " << first_num.get_re() << " + " << first_num.get_im() << "i\n";
		int32_t re{};
		int32_t im{};
		std::cout << "Input real and imaginary parts of number: ";
		std::cin >> re >> im;
		first_num.set_re(re);
		first_num.set_im(im);
		std::cout << "Your num by set_re and set_im: " << first_num;
	}
	catch (std::invalid_argument e) {
		std::cout << e.what();
	}
}