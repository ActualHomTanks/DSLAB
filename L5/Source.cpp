#include <iostream>
#include "Node.hpp"

int main()
{
	Node* head = nullptr;
	Node list;
	int meth = 0;

	std::cout << "1. AddHead  2. AddTail  3. InsertBefore  4. InsertTail  5. DeleteElement  6.Display\n";
	while (true) {
		std::cin >> meth;

		switch (meth) {
			case 1: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				list.insert_head(head, x);
				break;
			}
			case 2: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				list.insert_tail(head, x);
				break;
			}
			case 3: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				std::cout << "Enter element to search for:\n";
				int y = 0;
				std::cin >> y;
				list.insert_before(head, x, y);
				break;
			}
			case 4: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				std::cout << "Enter element to search for:\n";
				int y = 0;
				std::cin >> y;
				list.insert_after(head, x, y);
				break;
			}
			case 5: {
				std::cout << "Enter element to delete:\n";
				int x = 0;
				std::cin >> x;
				list.delete_element(head, x);
				break;
			}
			case 6: {
				std::cout << "LIST: \n";
				list.display(head);
				break;
			}
			default: std::cout << "Exiting\n"; return 0;
		}
	}

	return 0;
}