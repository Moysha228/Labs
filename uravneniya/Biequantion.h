#include "Lenear.h"
class Biequantion : public Equation{
private:
	double a;
	double b;
	double c;
public:
	Biequantion(double = 0, double = 0, double = 0);
	Biequantion(const Biequantion&);
	//Linear& operator=(const Linear&);
	Biequantion(Biequantion&&) noexcept;
	//Linear& operator=(Linear&&) noexcept;
	~Biequantion() = default;
	void print() override;
	void solve() override;
};
