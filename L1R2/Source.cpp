#include <iostream>
#include "Student.hpp"

int main()
{
	int index = 0;
	Student s[100];
	Student::read_p(s, index, "buddy1", 10, 'a');
	Student::read_p(s, index, "buddy2", 50, 'a');
	Student::read_p(s, index, "buddy3", 20, 'a');
	Student::read_p(s, index, "buddy4", 8, 'a');
	Student::read_p(s, index, "buddy5", 15, 'a');


	Student::sort_students(s, index);

	Student::display_students(s, index);
}