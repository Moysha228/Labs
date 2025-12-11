#ifndef кеямне_депебн_H
#define кеямне_депебн_H
#include "дЕПЕБН.h"
class Forest_tree : public Tree {
protected:
	uint32_t wood_mass;
public:

	~Forest_tree() = default;
	void info() = 0;
};
#endif