#include <iostream>
#include "Sort.hpp"

void print_array(int* ar, int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << " ";
	}

	std::cout << std::endl;
}

int main()
{
	int n = 11;
	int ar1[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };
	int ar2[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };
	int ar3[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };
	int ar4[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };
	int ar5[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };
	int ar6[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };
	int ar7[] = { 5, 7, 1, 10, 3, 2, 8, 11, 56, 23, 89 };

	std::cout << "Bubble Sort:\n";
	bubble_sort(ar1, n);
	print_array(ar1, n);

	std::cout << "Selection sort:\n";
	selection_sort(ar2, n);
	print_array(ar2, n);

	std::cout << "Insertion sort:\n";
	insertion_sort(ar3, n);
	print_array(ar3, n);

	std::cout << "Insertion sort:\n";
	quick_sort(ar4, 0, n - 1);
	print_array(ar4, n);

	std::cout << "Heap sort:\n";
	heap_sort(ar5, n);
	print_array(ar5, n);

}