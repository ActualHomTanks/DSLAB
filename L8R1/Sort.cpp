#include "Sort.hpp"

void bubble_sort(int* ar, int size)
{
	bool sorted = false;

	while (!sorted) {
		sorted = true;
		for (int i = 0; i < size - 1; i++) {
			if (ar[i + 1] < ar[i]) {
				int temp = ar[i + 1];
				ar[i + 1] = ar[i];
				ar[i] = temp;
				sorted = false;
			}
		}
	}
}


void selection_sort(int* ar, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int temp_index = i;
		int temp = ar[i];
		for (int j = i + 1; j < size; j++) {
			if (ar[j] < temp) {
				temp = ar[j];
				temp_index = j;
			}
		}

		ar[temp_index] = ar[i];
		ar[i] = temp;
	}
}


void insertion_sort(int* ar, int size)
{
	int i, key, j;
	for (i = 1; i < size; i++) {
		key = ar[i];
		j = i - 1;
		while (j >= 0 && ar[j] > key) {
			ar[j + 1] = ar[j];
			j = j - 1;
		}
		ar[j + 1] = key;
	}
}


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


int partition(int* ar, int low, int high)
{
	int pivot = ar[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (ar[j] < pivot) {
			i++;
			swap(ar[i], ar[j]);
		}
	}

	swap(ar[i + 1], ar[high]);
	return i + 1;
}

void quick_sort(int* ar, int low, int high)
{
	if (low < high) {
		int pi = partition(ar, low, high);
		quick_sort(ar, low, pi - 1);
		quick_sort(ar, pi + 1, high);
	}
}


void create_max_heap(int* ar, int size)
{
	for (int i = 1; i < size; i++) {
		if (ar[i] > ar[(i - 1) / 2]) {
			int j = i;

			while (ar[j] > ar[(j - 1) / 2]) {
				swap(ar[j], ar[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
}


void heap_sort(int* ar, int size)
{
	create_max_heap(ar, size);

	for (int i = size - 1; i > 0; i--) {
		swap(ar[0], ar[i]);

		int j = 0, index = 0;

		do {
			index = (2 * j + 1);

			if (ar[index] < ar[index + 1] && index < (i - 1)) {
				index++;
			}

			if (ar[j] < ar[index] && index < i) {
				swap(ar[j], ar[index]);
			}

			j = index;

		} while (index < i);
	}
}


int maximum(int* ar, int size)
{
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (max < ar[i]) {
			max = ar[i];
		}
	}

	return max;
}


int num_digits(int num)
{
	int count = 0;
	while (num > 0) {
		num = num / 10;
		count++;
	}

	return count;
}


void radix_sort(int ar*, int size)
{
	int max = maximum(ar, size);

	int passes = num_digits(max);

	
}