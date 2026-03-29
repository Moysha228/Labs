#ifndef депебн_H
#define депебн_H
#include <string>
#include <iostream>
class Tree {
protected:
	std::string name;
	uint32_t age;
	enum Type { coniferous, deciduous };
	Type type;
public:
	virtual void info() = 0;
};
#endif