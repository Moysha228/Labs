#include <iostream>
#include <cmath>
class Equation {
public:
	virtual void print() = 0;
	virtual void solve() = 0;
};
//св-ва виртуальности функции про€вл€ютс€ при еЄ вызове через указатель на базовый класс