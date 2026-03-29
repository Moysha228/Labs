#include <cctype>
#include <iostream>
#include "fstream"
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <vector>
//количество ключей
const uint32_t ROW_LENGTH{ 10 };//длина ключа
const uint32_t AMOUNT_OF_CHILDREN{ 3 };//количество ключей, задействованных в скрещивании
const uint32_t SWAPES_DURING_EBLA{ 1 };//количество свапов при скрещивании
struct Key {
	int32_t substitution[ROW_LENGTH];
	size_t counter;
};
void PrepareText(std::string&);
void CreateAllowedBigrams(std::vector<std::string>&, std::string&, size_t);
//void CreateAllowedBigram(std::string&, std::string&, size_t);
bool Check_this_el(Key&, size_t);
bool Check_this_key(Key*, size_t);
void CreatePopulation(Key*, uint64_t);
void DevideTextByRows(std::string&, char**, size_t);
void CountBadBigramsByKey(char**, Key&, size_t, std::vector<std::string>&);
void SwapKeysByCounter(Key*, uint64_t);
void RecreatePopulation(Key*, uint64_t, uint64_t, uint32_t);
bool StopFunc(Key*, uint64_t);