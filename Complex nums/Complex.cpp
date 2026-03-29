#include "Complex.h"
#include <cmath>
//Complex::Complex() {
//	this->re = 0;
//	this->im = 0;
//}
Complex::Complex(int32_t rhs_re, int32_t rhs_im) {
	this->re = rhs_re;
	this->im = rhs_im;
}
Complex::Complex(const Complex& rhs) {
	this->re = rhs.re;
	this->im = rhs.im;
}
Complex::Complex(Complex&& rhs) noexcept {
	this->re = rhs.re;
	rhs.re = 0;
	this->im = rhs.im;
	rhs.im = 0;
}
Complex& Complex::operator=(const Complex& rhs) {
	if (this != &rhs) {
		this->re = rhs.re;
		this->im = rhs.im;
	}
	return *this;
}
Complex& Complex::operator=(Complex&& rhs) noexcept {
	if (this != &rhs) {
		this->re = rhs.re;
		this->im = rhs.im;
	    rhs.re = 0;
	    rhs.im = 0;
	}
	return *this;
}
Complex::~Complex() {
	std::cout << "deleted\n";
}
double Complex::module() {
	return sqrt(this->re * this->re + this->im * this->im);
}
double Complex::arg() {
	if (this->re == 0) {
		throw std::invalid_argument("real number doesn't have an argument");
	}
	return atan(this->im / this->re);
}

Complex Complex::operator+(const Complex& rhs) {
	return Complex(this->re + rhs.re, this->im + rhs.im);
}
Complex Complex::operator+(const int32_t rhs) {
	return Complex(this->re + rhs, this->im);
}
Complex operator+(const int32_t lhs, const Complex& rhs) {
	return const_cast<Complex&>(rhs) + lhs;
}

Complex operator-(const Complex& lhs) {
	return Complex(-lhs.re, -lhs.im);
}
Complex Complex::operator-(const Complex& rhs) {
	return *this + (-rhs);
}
Complex Complex::operator-(const int32_t rhs) {
	return Complex(this->re - rhs, this->im);
}
Complex operator-(const int32_t lhs, const Complex& rhs) {
	return -(const_cast<Complex&>(rhs)) + lhs;
}

Complex Complex::operator*(const Complex& rhs) {
	return Complex(this->re * rhs.re - this->im * im, this->im * rhs.re - this->re * im);
}
Complex Complex::operator*(const int32_t rhs) {
	return Complex(rhs * this->re, rhs * this->im);
}
Complex operator*(const int32_t lhs, const Complex& rhs) {
	return const_cast<Complex&>(rhs) * lhs;
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
	if (rhs.im > 0) {
		os << rhs.re << " + " << rhs.im << 'i';
	}
	else if (rhs.im < 0) {
		os << rhs.re << " - " << -rhs.im << 'i';
	}
	else if (rhs.im == 0) {
		os << rhs.re;
	}
	else {
		os << rhs.im << 'i';
	}
	return os;
}
void operator>>(std::istream& is, Complex& rhs) {
	is >> rhs.re >> rhs.im;
}
void Complex::set_re(const int32_t num) {
	this->re = num;
}
int32_t Complex::get_re() const {
	return this->re;
}
void Complex::set_im(const int32_t num) {
	this->im = num;
}
int32_t Complex::get_im() const {
	return this->im;
}