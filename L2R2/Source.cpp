#include "Stack.hpp"
#include <iostream>

bool palindrome(char const a[])
{
	Stack s;
	for (int i = 0; a[i] != '\0'; i++) {
		s.push(a[i]);
	}

	for (int i = 0; a[i] != '\0'; i++) {
		if (s.pop() != a[i]) {
			return false;
		}
	}

	return true;
}


void convert(int n, int b)
{
	IntStack s;
	while (n > 0) {
		s.push(n % b);
		n = n / b;
	}

	while (!s.empty()) {
		std::cout << s.pop();
	}

	std::cout << '\n';
}


int main()
{
	Stack s;

	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');

	s.pop();
	s.pop();

	s.display();

	convert(3370, 8);

	char a[] = "racecar";
	std::cout << palindrome(a) << '\n';
}