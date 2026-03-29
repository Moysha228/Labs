#include "header.h"
class Linear : public Equation {
private:
	double a;
	double b;
public:
	Linear(double = 0, double = 0);
	Linear(const Linear&);
	Linear(Linear&&) noexcept;
	~Linear() = default;
	void print() override;
	void solve() override;
};