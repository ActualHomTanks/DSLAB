#include <iostream>
#include "Student.hpp"

Student::Student()
{
}

Student::Student(char const n[], int rno, char g)
{
	int len = 0;
	for (int i = 0; n[i] != '\0'; i++) {
		len++;
	}

	name = new char[len + 1];

	for (int i = 0; i < len; i++) {
		name[i] = n[i];
	}

	name[len] = '\0';

	rollNo = rno;
	grade = g;
}

void Student::read(Student s[], int& index)
{
	int rollno;
	char name[20];
	char grade;
	std::cin >> name;
	std::cin >> rollno;
	std::cin >> grade;

	Student* st = new Student(name, rollno, grade);

	s[index++] = *st;
}

void Student::read_p(Student s[], int& index, char const n[], int rno, char g)
{
	Student* st = new Student(n, rno, g);

	s[index++] = *st;
}


void Student::sort_students(Student s[], int& index)
{
	if (index < 2) {
		return;
	}

	bool sorted = false;

	while (!sorted) {
		sorted = true;

		for (int i = 0; i < index - 1; i++) {
			if (s[i + 1].rollNo < s[i].rollNo) {
				Student temp(s[i].name, s[i].rollNo, s[i].grade);
				s[i].name = s[i + 1].name;
				s[i].rollNo = s[i + 1].rollNo;
				s[i].grade = s[i + 1].grade;
				s[i + 1].name = temp.name;
				s[i + 1].rollNo = temp.rollNo;
				s[i + 1].grade = temp.grade;
				sorted = false;
			}
		}
	}
}


void Student::display()
{
	std::cout << "Name: " << name << '\n';
	std::cout << "Rollno: " << rollNo << '\n';
	std::cout << "Grade: " << grade << '\n';
}

void Student::display_students(Student s[], int& index)
{
	for (int i = 0; i < index; i++) {
		s[i].display();
		std::cout << '\n';
	}

	std::cout << std::endl;
}
