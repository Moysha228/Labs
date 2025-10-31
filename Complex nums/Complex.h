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
	Complex();
	Complex(int32_t, int32_t);            
	Complex(const Complex&);
	Complex(Complex&&);
	void operator=(const Complex&);
	void operator=(Complex&&);
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
	void set_re(int32_t);
	int32_t get_re();
	void set_im(int32_t);
	int32_t get_im();
};
#endif