#include "Functions.h"
void PrepareText(std::string& txt) {
	std::string simb{ ",.!/?{[]} ;:-" };
	size_t l{ txt.length() };
	for (size_t i{}; i < l; ++i) {
		if (simb.find(txt[i]) != std::string::npos) {
			txt.erase(i, 1);
			--i;
			--l;
		}
	}
}
void CreateAllowedBigrams(std::vector<std::string>& allowed_bigrams, std::string& txt, size_t l) {
	for (size_t i{}; i < l; ++i) {
		if (allowed_bigrams[static_cast<int64_t>(txt[i]) + 64].find(txt[i + 1]) == std::string::npos) {
			allowed_bigrams[static_cast<int64_t>(txt[i]) + 64] += txt[i + 1];
		}
	}
}
bool Check_this_el(Key& key, size_t num) {
	for (size_t i{}; i < num; ++i) {
		if (key.substitution[i] == key.substitution[num]) {
			return 1;
		}
	}
	return 0;
}
bool Check_this_key(Key* pop, size_t num) {
	for (size_t i{}; i < num; ++i) {
		size_t counter{ 1 };
		for (size_t j{}; j < ROW_LENGTH; ++j) {
			if (pop[i].substitution[j] == pop[num].substitution[j]) {
				++counter;
			}
		}
		if (counter == ROW_LENGTH) {
			return true;
		}
	}
	return false;
}
void CreatePopulation(Key* pop, uint64_t AOP) {
	std::uniform_int_distribution<int32_t> dist(0, ROW_LENGTH - 1);
	for (size_t i{}; i < AOP; ++i) {
		pop[i].counter = 0;
	    std::random_device rd;
	    std::mt19937 gen(rd());
		for (size_t j{}; j < ROW_LENGTH; ++j) {
			pop[i].substitution[j] = dist(gen);
			if (Check_this_el(pop[i], j)) {
				--j;
			}
		}
		//if (Check_this_key(pop, i)) {
		//	--i;
		//}
	}
}
void DevideTextByRows(std::string& txt, char** columns, size_t column_length) {
	for (size_t i{}; i < ROW_LENGTH; ++i) {
		for (size_t j{}; j < column_length; ++j) {
			columns[i][j] = txt[j * ROW_LENGTH + i];
		}
	}
}
void CountBadBigramsByKey(char** columns, Key& key, size_t column_length, std::vector<std::string>& allowed_bigrams) {
	for (size_t i{ 1 }; i < ROW_LENGTH; ++i) {
		for (size_t j{}; j < column_length; ++j) {
			if (allowed_bigrams[static_cast<int64_t>(columns[key.substitution[i - 1]][j]) + 64].find(columns[key.substitution[i]][j]) == std::string::npos) {
				++key.counter;
			}
		}
	}
	for (size_t i{}; i < column_length - 1; ++i) {
		if (allowed_bigrams[static_cast<int64_t>(columns[ROW_LENGTH - 1][i]) + 64].find(columns[0][i + 1]) == std::string::npos) {
			++key.counter;
		}
	}
}
void SwapKeysByCounter(Key* pop, uint64_t AOP) {
	std::string bigram[2]{};
	for (size_t i{}; i < AOP; ++i) {
		if (pop[i].counter > pop[i + 1].counter) {
			std::swap(pop[i], pop[i + 1]);
		}
	}
}
void RecreatePopulation(Key* pop, uint64_t AOP, uint64_t AOBK, uint32_t AOM) {
	size_t start_of_mutation{ AOP - AOM };
	size_t border{ static_cast<size_t>(start_of_mutation - AOBK * AMOUNT_OF_CHILDREN) };
	std::uniform_int_distribution<int32_t> dist(0, ROW_LENGTH - 1);
	std::random_device rd1;
	for (size_t i{}; i < AOBK; ++i) {
	    std::mt19937 gen1(rd1());
		pop[i].counter = 0;
		for (size_t j{ border }; j < border + AMOUNT_OF_CHILDREN; ++j) {
			for (size_t l{}; l < ROW_LENGTH; ++l) {
				pop[j].substitution[l] = pop[i].substitution[l];
			}
			std::swap(pop[j].substitution[dist(gen1)], pop[j].substitution[dist(gen1)]);
		}
		border += 3;
		//for (size_t j{ 1 }; j <= AMOUNT_OF_CHILDREN; ++j) {
		//	pop[i].substitution = pop[j * AOSK + i].substitution;
		//	std::swap(pop[j * AOSK + i].substitution[dist(gen1)], pop[j * AOSK + i].substitution[dist(gen1)]);
		//}
	}
	std::random_device rd2;
	for (size_t i{ start_of_mutation }; i < AOP; ++i) {
	    std::mt19937 gen2(rd2());
		pop[i].counter = 0;
		for (size_t j{}; j < ROW_LENGTH; ++j) {
			pop[i].substitution[j] = dist(gen2);
			if (Check_this_el(pop[i], j)) {
				--j;
			}
			//if (Check_this_key(pop, i)) {
			//	--i;
			//}
		}
	}
	//for (size_t i{}; i < AOP; ++i) {
	//	for (size_t j{}; j < ROW_LENGTH; ++j) {
	//		pop[i].substitution[j] = dist(gen);
	//		if (Check_this_el(pop[i], j)) {
	//			--j;
	//		}
	//	}
	//}
}
bool StopFunc(Key* pop, uint64_t AOP) {
	for (size_t i{}; i < AOP; ++i) {
		if (pop[i].counter == 0) {
			return true;
		}
	}
	return false;
}