#include <iostream>
#include "DNode.hpp"

void DNode::insert_node(DNode*& pointer, int data)
{
	DNode* next_node = pointer->next;
	pointer->next = new DNode(data);
	pointer->next->next = next_node;
	pointer->next->prev = pointer;
	next_node->prev = pointer->next;
}


DNode::DNode()
{
}


DNode::DNode(int data) : data(data)
{
}


void DNode::insert_head(DNode*& head, int data)
{
	if (!head) {
		head = new DNode(data);
		return;
	}

	DNode* next_node = head;
	head = new DNode(data);
	head->next = next_node;
	next_node->prev = head;
}


void DNode::insert_tail(DNode*& head, int data)
{
	if (!head) {
		head = new DNode(data);
		return;
	}

	DNode* curr = head;
	while (curr->next) {
		curr = curr->next;
	}

	curr->next = new DNode(data);
	curr->next->prev = curr;
}


void DNode::delete_tail(DNode*& head)
{
	if (!head) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	if (!head->next) {
		delete head;
		head = nullptr;
		return;
	}

	DNode* curr = head;
	while (curr->next) {
		curr = curr->next;
	}

	curr->prev->next = nullptr;
	delete curr;
	curr = nullptr;
}


void DNode::insert_index(DNode*& head, int data, int i)
{
	if (!head) {
		head = new DNode(data);
		return;
	}

	if (i == 0) {
		DNode* next_node = head;
		head = new DNode(data);
		head->next = next_node;
		next_node->prev = head;
		return;
	}

	i--;
	DNode* curr = head;

	while (i > 0 && curr->next) {
		curr = curr->next;
		i--;
	}

	if (i != 0) {
		std::cout << "Invalid index\n";
		return;
	}

	if (!curr->next) {
		insert_tail(head, data);
		return;
	}

	insert_node(curr, data);

}


void DNode::delete_index(DNode*& head, int i)
{
	if (!head) {
		std::cout << "List is Empty\n";
		return;
	}

	if (i == 0) {
		DNode* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
		return;
	}

	if (!head->next) {
		delete head;
		head = nullptr;
		return;
	}

	i--;
	DNode* curr = head->next;
	while (i > 0 && curr->next) {
		curr = curr->next;
		i--;
	}

	if (i != 0) {
		std::cout << "Invalid Index\n";
		return;
	}

	if (!curr->next) {
		delete_tail(head);
		return;
	}

	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	delete curr;
}


void DNode::insert_after(DNode*& head, int data, int after)
{
	if (!head) {
		std::cout << "List is Empty\n";
		return;
	}

	DNode* curr = head;
	while (curr->next) {
		if (curr->data == after) {
			insert_node(curr, data);
			return;
		}
		curr = curr->next;
	}

	if (curr->data) {
		insert_tail(head, data);
		return;
	}

	std::cout << "Element not found\n";
}


void DNode::insert_before(DNode*& head, int data, int before)
{
	if (!head) {
		std::cout << "List is Empty\n";
		return;
	}

	if (head->data == before) {
		DNode* temp = head;
		head = new DNode(data);
		head->next = temp;
		temp->prev = head;
		return;
	}

	DNode* curr = head;
	while (curr->next) {
		if (curr->next->data == before) {
			insert_node(curr, data);
			return;
		}
		curr = curr->next;
	}

	std::cout << "Element not found\n";
}


void DNode::display(DNode*& head)
{
	if (!head) {
		std::cout << "List is empty\n";
		return;
	}

	DNode* curr = head;

	while (curr) {
		std::cout << curr->data << " ";
		curr = curr->next;
	}

	std::cout << std::endl;
}



PolyNode::PolyNode()
{
}


PolyNode::PolyNode(int coef, int power) : coef(coef), power(power)
{
}


void PolyNode::read(PolyNode*& head)
{
	int c = 0, p = 0;

	while (true) {
		std::cout << "Enter coef and power of term: ";
		std::cin >> c >> p;

		if (c == 0) {
			continue;
		}
		else if (c == -999) {
			return;
		}

		insert_tail(head, c, p);
		std::cout << "Term added\n";
	}
}

void PolyNode::add(PolyNode*& p1head, PolyNode*& p2head)
{
	PolyNode* p1 = p1head;
	PolyNode* p2 = p2head;

	if (!p2) {
		std::cout << "Addition: ";
		display(p1);
		return;
	}
	else if (!p1) {
		std::cout << "Addition: ";
		display(p2);
		return;
	}

	PolyNode* p3 = nullptr;
	
	int meth = -1;

	while (p1 && p2) {
		if (p1->power == p2->power) {
			meth = 0;
		}
		else if (p1->power > p2->power) {
			meth = 1;
		}
		else {
			meth = 2;
		}

		switch (meth) {
			case 0: {
				insert_tail(p3, p1->coef + p2->coef, p1->power);
				p1 = p1->next;
				p2 = p2->next;
				break;
			}
			case 1: {
				insert_tail(p3, p1->coef, p1->power);
				p1 = p1->next;
				break;
			}
			case 2: {
				insert_tail(p3, p2->coef, p2->power);
				p2 = p2->next;
				break;
			}
			default: break;
		}
	}

	while (p1) {
		insert_tail(p3, p1->coef, p1->power);
		p1 = p1->next;
		break;
	}

	while (p2) {
		insert_tail(p3, p2->coef, p2->power);
		p2 = p2->next;
		break;
	}

	std::cout << "Addition: ";
	display(p3);
}


void PolyNode::insert_tail(PolyNode*& head, int coef, int power)
{
	if (!head) {
		head = new PolyNode(coef, power);
		return;
	}

	PolyNode* curr = head;
	while (curr->next) {
		curr = curr->next;
	}

	curr->next = new PolyNode(coef, power);
	curr->next->prev = curr;
}


void PolyNode::display(PolyNode*& head)
{
	if (!head) {
		return;
	}

	PolyNode* curr = head;

	while (curr->next) {
		if (curr->coef == 0) {
			curr = curr->next;
			continue;
		}

		std::cout << curr->coef << "x^" << curr->power;
		curr = curr->next;

		if (curr->coef > 0) {
			std::cout << " + ";
		}
		else {
			std::cout << " ";
		}
	}

	std::cout << curr->coef << "x^" << curr->power << '\n';
}
