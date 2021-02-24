#pragma once

class Node
{
private:
	Node* next = nullptr;
	int data = 0;
private:
	void insert_node(Node* pointer, int data);
public:
	Node();
	Node(int data);
	void insert_head(Node*& head, int data);
	void insert_tail(Node*& head, int data);
	void insert_before(Node*& head, int data, int before);
	void insert_after(Node*& head, int data, int after);
	void delete_element(Node*& head, int data);
	void display(Node*& head);
};

