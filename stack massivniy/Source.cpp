#include "Stack massivniy.h"
int main() {
	size_t size{};
	std::cout << "Input size of a stack\n";
	std::cin >> size;
	Stack st(size);
	std::string nums{};
	std::string nums_end{};
	std::cout << "Input numbers\n";
	std::cin >> nums;
	std::getline(std::cin, nums_end);
	nums += nums_end;
	while (size--) {
		size_t beg{ nums.find_first_not_of(" ") };
		size_t beg_copy{ beg };
		size_t end{ nums.find_first_of(" ") };
		if (end == std::string::npos) {
			end = nums.length() + 1;
		}
		std::string num;
		for (size_t i{}; i < end - beg; ++i) {
			num += nums[beg_copy++];
		}
		st.push(stoi(num));
		nums.erase(beg, end - beg + 1);
	}
	std::cout << st;
}