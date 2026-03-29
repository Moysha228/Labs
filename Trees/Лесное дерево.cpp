#include "Лесное дерево.h"
void Forest_tree::info() {
	if (this->type == 0) {
		std::cout << "This is " << this->name << ". " << this->name << " is " << "coniferous" << " tree. " << "It is " << this->age << " years old." << "The mass of wood in this tree " << this->wood_mass << " kg.\n";
	}
	else {
		std::cout << "This is " << this->name << ". " << this->name << " is " << "deciduous" << " tree. " << "It is " << this->age << " years old." << "The mass of wood in this tree " << this->wood_mass << " kg.\n";
	}
}