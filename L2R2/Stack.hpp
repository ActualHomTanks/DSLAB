#pragma once

#define MAX 100

class Stack
{
private:
	int top = -1;
	char arr[MAX];

public:
	Stack();
	void push(char n);
	char pop();
	char peek() const;
	bool empty() const;
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


class DoubleStack
{
private:
	int top = -1;
	double arr[MAX];

public:
	DoubleStack();
	void push(double n);
	double pop();
	bool empty();
	void display();

};


class StringStack
{
private:
	int top = -1;
	char arr[MAX][MAX];

public:
	StringStack();
	void push(char n[]);
	char* pop();
	bool empty();
	void display();

};

