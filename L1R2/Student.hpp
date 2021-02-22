#pragma once

class Student
{
private:
	char* name = nullptr;
	int rollNo = 0;
	char grade = 'F';

public:
	Student();
	Student(char const n[], int rno, char g);
	static void read(Student s[], int& index);
	static void read_p(Student s[], int& index, char const n[], int rno, char g);
	static void sort_students(Student s[], int& index);
	void display();
	static void display_students(Student s[], int& index);

};

