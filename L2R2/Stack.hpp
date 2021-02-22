#pragma once

#define MAX 10

class Stack
{
private:
	int top = -1;
	char arr[MAX];

public:
	Stack();
	void push(char n);
	char pop();
	bool empty();
	void display();
	
};

class IntStack
{
private:
	int top = -1;
	int arr[MAX];

public:
	IntStack();
	void push(int n);
	int pop();
	bool empty();
	void display();

};

