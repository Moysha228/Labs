#include "Stack massivniy.h"
Stack::Stack(const int& size) : size(size), top{ 0 } {
	if(size < 1){
		throw std::invalid_argument("Can't create stack with this size\n");
	}
    array = new int[size];
}
Stack::Stack(const Stack& rhs) : size(rhs.size), top(rhs.top){
	this->array = new int[size];
	for (size_t i{}; i < top; ++i) {
		array[i] = rhs.array[i];
	}
}
Stack::Stack(Stack&&/*äâà & ðàäè r-valueñòè*/ rhs) noexcept : size(rhs.size), top(rhs.top) {
	const_cast<int&>(size) = 0;
	rhs.top = 0;
	array = rhs.array;
	rhs.array = nullptr;
}
Stack::~Stack() {
	if (array != nullptr) {
		delete[] array;
	}
}
void Stack::push(int num) {
	if (isFull()) {
		throw "Stack if full\n";
	}
	array[top++] = num;
}
void Stack::pop() {
	if (isEmpty()) {
		throw "loh\n";
	}
	--top;
}
int Stack::peek() {
	if (isEmpty()) {
		throw "loh\n";
	}
	return array[top - 1];
}
bool Stack::isEmpty() const {
	return top == 0;
}
bool Stack::isFull() const {
	return top == size + 1;
}
Stack& Stack::operator =(const Stack& rhs) {
	if (this != &rhs) {
		for (size_t i{}; i < top; ++i) {
			array[i] = rhs.array[i];
		}
		const_cast<int&>(size) = rhs.size;
		top = rhs.top;
		return *this;
	}
	else {
		throw std::invalid_argument("Selfassigning");
	}
}
Stack& Stack::operator =(Stack&& rhs) noexcept {
	for (size_t i{}; i < top; ++i) {
		array[i] = rhs.array[i];
	}
	const_cast<int&>(size) = rhs.size;
	top = rhs.top;
	rhs.top = 0;
	const_cast<int&>(rhs.size) = 0;
	return *this;
}
std::ostream& operator <<(std::ostream& os, Stack& rhs) {
	for (size_t i{}; i < rhs.size; ++i) {
		os << rhs.array[i] << '\t';
	}
	return os;
}