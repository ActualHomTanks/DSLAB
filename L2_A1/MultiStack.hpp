#pragma once

#define topsize 10
#define boundarysize 10
#define arrsize 60

class MultiStack
{
private:
	int* top = nullptr;
	int* boundary = nullptr;
	int* a = nullptr;
	
public:
	MultiStack(int n);
	void push(int n, int sno);
	int pop(int sno);
	bool empty(int sno);
	void display(int sno);
	
};
