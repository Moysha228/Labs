#include "Плодовое дерево.h"
Плодовое_дерево::Плодовое_дерево() : crop_weight(0), average_shelf_life(0) {
	this->name = '\0';
	this->age = 0;
	this->type = coniferous;
}
Плодовое_дерево::Плодовое_дерево(std::string name, uint32_t age, uint32_t c_w, uint32_t a_s_l) : crop_weight(c_w), average_shelf_life(a_s_l)  {
	this->name = name;
	this->age = age;
	this->type = coniferous;
}
Плодовое_дерево::Плодовое_дерево(const Плодовое_дерево& tree) : crop_weight(tree.crop_weight), average_shelf_life(tree.average_shelf_life) {
	if (this != &tree) {
		this->name = tree.name;
		this->age = tree.age;
		this->type = tree.type;
	}
}
Плодовое_дерево::Плодовое_дерево(Плодовое_дерево&& tree) : Плодовое_дерево::Плодовое_дерево(tree) {
	this->type = tree.type;
	tree.name = "\0";
	tree.age = 0;
	crop_weight = 0;
	average_shelf_life = 0;
}
void Плодовое_дерево::info() {
	if (this->type == 0) {
		std::cout << "This is " << this->name << ". " << this->name << " is " << "coniferous" << " tree. " << "It is " << this->age << " years old. The yield from this tree is " << this->crop_weight << " with a shelf life of " << this->average_shelf_life << ".\n";
	}
	else {
		std::cout << "This is " << this->name << ". " << this->name << " is " << "coniferous" << " tree. " << "It is " << this->age << " years old. The yield from this tree is " << this->crop_weight << " with a shelf life of " << this->average_shelf_life << ".\n";
	}
}
void Плодовое_дерево::set_type(int type_num) {
	this->type = static_cast<Type>(type_num);
}