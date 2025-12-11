#include "Плодовое дерево.h"
int main() {
	std::string name{};
	uint32_t age{};
	uint32_t crop_weight{};
	uint32_t average_shelf_life{};
	std::string type{};
	std::cout << "Input name, type, age, weight and average shelf life of crop\n";
	std::cin >> name >> type >> age >> crop_weight >> average_shelf_life;
	Плодовое_дерево fruit_tree(name, age, crop_weight, average_shelf_life);
	if (type == "coniferous" || type == "Coniferous" || type == "CONIFEROUS") {
		fruit_tree.set_type(0);
	}
	else if (type == "deciduous" || type == "Deciduous" || type == "DECIDUOUS") {
		fruit_tree.set_type(1);
	}
	else {
		std::cout << "Unknown type";
		return 0;
	}
	fruit_tree.info();
	std::cout << "Input name, type, age, weight and average shelf life of crop\n";
	std::cin >> name >> type >> age >> crop_weight >> average_shelf_life;
	Плодовое_дерево yeblonya(name, age, crop_weight, average_shelf_life);
	if (type == "coniferous" || type == "Coniferous" || type == "CONIFEROUS") {
		yeblonya.set_type(0);
	}
	else if (type == "deciduous" || type == "Deciduous" || type == "DECIDUOUS") {
		yeblonya.set_type(1);
	}
	else {
		std::cout << "Unknown type";
		return 0;
	}
	yeblonya.info();
}