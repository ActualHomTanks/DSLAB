#include <iostream>
#include "Stack.hpp"


Stack::Stack()
{
}

void Stack::push(char n)
{
	if (top == MAX - 1) {
		return;
	}

	arr[++top] = n;
}

char Stack::pop()
{
	if (top == -1) {
		std::cout << "Empty!\n";
		return 0;
	}
	
	return arr[top--];
}

bool Stack::empty()
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void Stack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}



IntStack::IntStack()
{
}

void IntStack::push(int n)
{
	if (top == MAX - 1) {
		return;
	}

	arr[++top] = n;
}

int IntStack::pop()
{
	if (top == -1) {
		std::cout << "Empty!\n";
		return 0;
	}

	return arr[top--];
}

bool IntStack::empty()
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void IntStack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}
