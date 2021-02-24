#pragma once

class DNode
{
private:
	DNode* next = nullptr;
	DNode* prev = nullptr;
	int data = 0;
private:
	void insert_node(DNode*& pointer, int data);
public:
	DNode();
	DNode(int data);
	void insert_head(DNode*& head, int data);
	void insert_tail(DNode*& head, int data);
	void delete_tail(DNode*& head);
	void insert_index(DNode*& head, int data, int i);
	void delete_index(DNode*& head, int i);
	void insert_after(DNode*& head, int data, int after);
	void insert_before(DNode*& head, int data, int before);
	void display(DNode*& head);

};


class PolyNode
{
private:
	PolyNode* next = nullptr;
	PolyNode* prev = nullptr;
	int coef = 0;
	int power = 0;
public:
	PolyNode();
	PolyNode(int coef, int power);
	void read(PolyNode*& head);
	void add(PolyNode*& p1head, PolyNode*& p2head);
	void insert_tail(PolyNode*& head, int coef, int power);
	void display(PolyNode*& head);
};