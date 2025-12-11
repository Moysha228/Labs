#ifndef ПЛОДОВОЕ_ДЕРЕВО_H
#define ПЛОДОВОЕ_ДЕРЕВО_H
#include "Дерево.h"
class Плодовое_дерево : public Tree {
protected:
	uint32_t crop_weight;
	uint32_t average_shelf_life;
public:
	Плодовое_дерево();
	Плодовое_дерево(std::string, uint32_t, uint32_t, uint32_t);
	Плодовое_дерево(const Плодовое_дерево&);
	Плодовое_дерево(Плодовое_дерево&&);
	~Плодовое_дерево() = default;
	void info() override;
	void set_type(int);
};
#endif