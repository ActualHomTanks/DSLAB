#include <iostream>
#include "MultiStack.hpp"


MultiStack::MultiStack(int n)
{
	a = new int[arrsize];
	top = new int[topsize];
	boundary = new int[boundarysize];

	for (int i = 0; i < n; i++) {
		boundary[i] = top[i] = (arrsize / n) * i - 1;
	}
}


void MultiStack::push(int n, int sno)
{
	if (top[sno] == boundary[sno + 1] || top[sno] == arrsize - 1) {
		return;
	}

	a[++top[sno]] = n;
	return;
}

int MultiStack::pop(int sno)
{
	if (top[sno] == boundary[sno]) {
		std::cout << "Stack is empty\n";
		return 0;
	}

	return a[top[sno]--];
}

bool MultiStack::empty(int sno)
{
	if (top[sno] == boundary[sno]) {
		return true;
	}
	else return false;
}

void MultiStack::display(int sno)
{
	if (empty(sno)) {
		std::cout << "Stack is Empty";
		return;
	}

	for (int i = boundary[sno] + 1; i <= top[sno]; i++) {
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;
}
