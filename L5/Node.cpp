#include <iostream>
#include "Node.hpp"

//inserts node after the pointer provided
void Node::insert_node(Node* pointer, int data)
{
	Node* next_node = pointer->next;
	pointer->next = new Node(data);
	pointer->next->next = next_node;
}

Node::Node()
{}

Node::Node(int data) : data(data), next(nullptr)
{
}

void Node::insert_head(Node*& head, int data)
{
	if (!head) {
		head = new Node(data);
		return;
	}

	Node* curr = head;
	head = new Node(data);
	head->next = curr;
}

void Node::insert_tail(Node*& head, int data)
{
	if (!head) {
		head = new Node(data);
		return;
	}

	Node* curr = head;
	while (curr->next) {
		curr = curr->next;
	}

	curr->next = new Node(data);
}

void Node::insert_before(Node*& head, int data, int before)
{
	if (!head) {
		head = new Node(data);
		return;
	}

	if (head->data == before) {
		insert_head(head, data);
		return;
	}

	Node* curr = head;

	while (curr->next) {
		if (curr->next->data == before) {
			insert_node(curr, data);
			return;
		}
		curr = curr->next;
	}

	std::cout << "Element not found!\n";
}

void Node::insert_after(Node*& head, int data, int after)
{
	if (!head) {
		head = new Node(data);
		return;
	}

	Node* curr = head;

	while (curr) {
		if (curr->data == after) {
			insert_node(curr, data);
			curr = curr->next;
			return;
		}
		curr = curr->next;
	}

	std::cout << "Element not found\n";
}

void Node::delete_element(Node*& head, int data)
{
	if (!head) {
		std::cout << "List is empty!\n";
		return;
	}

	if (head->data == data) {
		Node* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		return;
	}

	Node* curr = head;

	while (curr->next) {
		if (curr->next->data == data) {
			Node* next_node = curr->next->next;
			delete curr->next;
			curr->next = next_node;
			return;
		}
		curr = curr->next;
	}

	std::cout << "Node not found\n";
}

void Node::display(Node*& head)
{
	if (!head) {
		std::cout << "List is empty\n";
		return;
	}

	Node* curr = head;

	while (curr) {
		std::cout << curr->data << " ";
		curr = curr->next;
	}

	std::cout << std::endl;
}
