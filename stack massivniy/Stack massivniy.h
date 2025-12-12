#ifndef STACK_MASSIVNIY_H
#define STACK_MASSIVNIY_H
#include <iostream>
#include <string>
class Stack {
private:
	int top;//первый "пустой" эл-т
	const int size;//максимальный допустимый размер
	int* array;
public:
	Stack(const int& = 1);
	Stack(const Stack&);
	Stack(Stack&&) noexcept;
	~Stack();
	void push(int);
	void pop();
	int peek();
	bool isEmpty() const;
	bool isFull() const;
	Stack& operator =(const Stack&);
	Stack& operator =(Stack&&) noexcept;
	friend std::ostream& operator <<(std::ostream&, Stack&);
};
#endif