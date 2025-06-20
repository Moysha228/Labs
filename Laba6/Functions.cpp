#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
void DeleteStrings(char* str1, char* str2) {
	delete[] str1;
	delete[] str2;
}
char* FindMinWord(char* str, char* delim) {
	char* token = strtok(str, delim);
	char* min = token;
	while (token != NULL) {
		if (strlen(min) > strlen(token))
			strcpy(min, token);
		token = strtok(NULL, delim);
	}
	return min;
}