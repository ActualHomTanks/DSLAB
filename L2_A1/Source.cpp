#include <iostream>
#include "MultiStack.hpp"

int main()
{
	MultiStack s(3);
	s.push(2, 0);
	s.push(4, 0);
	s.push(6, 0);
	s.push(8, 0);
	s.push(3, 1);
	s.push(5, 1);
	s.push(7, 1);
	s.push(9, 2);
	s.push(10, 2);
	s.push(11, 2);
	s.push(12, 2);

	s.pop(0);
	s.pop(1);
	s.pop(1);
	s.pop(2);
	s.pop(2);

	s.display(0);
	s.display(1);
	s.display(2);

}