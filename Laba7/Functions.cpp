#include <string>
std::string FindAllDigitWords(std::string str) {
	std::string digits("1234567890");
	size_t beg{};
	size_t end{};
	std::string res{};
	beg = str.find_first_not_of(' ');
	while (beg != std::string::npos) {
		end = str.find_first_of(' ', beg);
		if (end == std::string::npos)
			end = str.length();
		std::string word;
		for (size_t i{ beg }; i < end; ++i) {
			word.push_back(str[i]);
		}
		if (word.find_first_not_of(digits) == std::string::npos) {
			res.append(word);
			res.push_back(' ');
		}
		beg = str.find_first_not_of(' ', end);
	}
	return res;
}
std::string FindAllNonDigitWords(std::string str) {
	std::string digits("1234567890");
	size_t beg{};
	size_t end{};
	std::string res{};
	beg = str.find_first_not_of(' ');
	while (beg != std::string::npos) {
		end = str.find_first_of(' ', beg);
		if (end == std::string::npos)
			end = str.length();
		std::string word;
		for (size_t i{ beg }; i < end; ++i) {
			word.push_back(str[i]);
		}
		if (word.find_first_not_of(digits) != std::string::npos) {
			res.append(word);
			res.push_back(' ');
		}
		beg = str.find_first_not_of(' ', end);
	}
	return res;
}