#include <iostream>
#include "String.hpp"

int main()
{
	String s1("HelloThereBuddy");
	String s2("There");


	s1.delete_sub(s2);

	s1.display();
}