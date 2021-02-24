#include <iostream>
#include "DNode.hpp"

int main()
{
	DNode* head = nullptr;
	DNode list;
	int meth = 0;

	PolyNode* p1 = nullptr;
	PolyNode* p2 = nullptr;
	PolyNode poly_list;
	/*poly_list.read(p1);
	std::cout << "polynomial 1 has been read\n";
	poly_list.read(p2);
	std::cout << "polynomial 2 has been read\n";*/

	poly_list.insert_tail(p1, 3, 2);
	poly_list.insert_tail(p1, 5, 1);
	poly_list.insert_tail(p1, -3, 0);

	poly_list.insert_tail(p2, 1, 2);
	poly_list.insert_tail(p2, -5, 1);
	poly_list.insert_tail(p2, 1, 0);

	poly_list.add(p1, p2);



	std::cout << "1. InsertTail  2. DeleteTail  3. InsertIndex  4. DeleteIndex  5. InsertAfter  6. InsertBefore  7. Display:\n";
	while (true) {
		std::cin >> meth;
		switch (meth) {
			case 1: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				list.insert_tail(head, x);
				std::cout << "Tail inserted\n";
				break;
			}
			case 2: {
				list.delete_tail(head);
				std::cout << "Tail deleted\n";
				break;
			}
			case 3: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				std::cout << "Enter index: ";
				int i = 0;
				std::cin >> i;
				list.insert_index(head, x, i);
				break;
			}
			case 4: {
				std::cout << "Enter index:\n";
				int y = 0;
				std::cin >> y;
				list.delete_index(head, y);
				break;
			}
			case 5: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				std::cout << "Enter element to search for:\n";
				int y = 0;
				std::cin >> y;
				list.insert_after(head, x, y);
				list.display(head);
				break;
			}
			case 6: {
				std::cout << "Enter element to push:\n";
				int x = 0;
				std::cin >> x;
				std::cout << "Enter element to search for:\n";
				int y = 0;
				std::cin >> y;
				list.insert_before(head, x, y);
				list.display(head);
				break;
			}
			case 7: {
				std::cout << "LIST: \n";
				list.display(head);
				break;
			}
			default: std::cout << "Exiting\n"; return 0;
		}
	}
}