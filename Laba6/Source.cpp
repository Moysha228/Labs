#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Functions.h"
int main() {
	try {
		char str[300];
		std::cin.getline(str, 300);
		if (strlen(str) == 0)
			throw 1;
		char delim[2]{" "};
		char* str_copy = new char[strlen(str) + 1];
		strcpy(str_copy, str);
		char* token = strtok(str_copy, delim);
		bool check{ 1 };
		size_t length{};
		char* polindroms = new char[strlen(str)] {};
		size_t counter{};
		while (token != NULL) {
			length = strlen(token);
			check = 1;
			for (size_t i{}; i < (length / 2) && check; ++i) {
				if (token[i] != token[length - 1 - i]) {
					check = 0;
				}
			}
			if (check) {
				strcat(polindroms, token);
				strcat(polindroms, " ");
				++counter;
			}
			token = strtok(NULL, delim);
		}

		DeleteStrings(str_copy, polindroms);
	}
	catch (const int) {
		std::cout << "Empty string";
	}
}