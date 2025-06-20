#include <iostream>
#include <string>
#include "Functions.h"
int main() {
	try {
		std::string str;
		std::cout << "Input your sentence\n";
		getline(std::cin, str);
		if (str.length() == 0)
			throw std::invalid_argument("Zero length");
		std::string res{ FindAllDigitWords(str) };
		if(res.find_first_not_of(' '))
			throw std::logic_error("No result");
		for (size_t i{ 0 }; i < res.length(); ++i)
			std::cout << res[i];
		res = FindAllNonDigitWords(str);
		if (res.find_first_not_of(' '))
			throw std::logic_error("No result");
		for (size_t i{ 0 }; i < res.length() - 1; ++i)
			std::cout << res[i];
	}
	catch (std::invalid_argument e) {
		std::cout << "ERROR: " << e.what();
	}
	catch (std::logic_error e) {
		std::cout << e.what();
	}
}