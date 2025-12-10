#ifndef COMPLEX_H
#define COMPLEX_H
#include <cstdint>
#include <cmath>
#include <iostream>
class Complex {
private:
	int32_t re;
	int32_t im;
public:
	//Complex();
	Complex(int32_t = 0, int32_t = 0);            
	Complex(const Complex&);
	Complex(Complex&&) noexcept;
	Complex& operator=(const Complex&);
	Complex& operator=(Complex&&) noexcept;
	~Complex();
	double module();
	double arg();

	Complex operator+(const Complex&);
	Complex operator+(const int32_t);
	friend Complex operator+(const int32_t, const Complex&);

	friend Complex operator-(const Complex&);
	Complex operator-(const Complex&);
	Complex operator-(const int32_t);
	friend Complex operator-(const int32_t, const Complex&);

	Complex operator*(const Complex&);
	Complex operator*(const int32_t);
	friend Complex operator*(const int32_t, const Complex&);

	Complex& operator++() {
		this->re = this->re + 1;
		return *this;
	}
	Complex operator++(int) {
		Complex temp(*this);
		++(*this);
		return temp;
	}
	Complex& operator--() {
		this->re = this->re - 1;
		return *this;
	}
	Complex operator--(int) {
		Complex temp(*this);
		--(*this);
		return temp;
	}
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend void operator>>(std::istream&, Complex&);
	void set_re(const int32_t);
	int32_t get_re() const;
	void set_im(const int32_t);
	int32_t get_im() const;
};
#endif