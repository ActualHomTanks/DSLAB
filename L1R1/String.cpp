#include "String.hpp"
#include <iostream>


String::String()
{
}


String::String(char const* const a)
{
	int len = String::length(a);

	arr = new char[len + 1];

	for (int i = 0; i < len; i++) {
		arr[i] = a[i];
	}
	
	arr[len] = '\0';
}


String::~String()
{
	delete[] arr;
}


int String::length() const
{
	int len = 0;

	for (int i = 0; arr[i] != '\0'; i++) {
		len++;
	}

	return len;
}


int String::length(char const* const a)
{
	int len = 0;

	for (int i = 0; a[i] != '\0'; i++) {
		len++;
	}

	return len;
}


void String::concat(char const* const a)
{
	String str(a);
	this->concat(str);
}


void String::concat(String const& str)
{
	int len1 = this->length();
	int len2 = str.length();

	char* temp = new char[len1 + len2 + 1];

	for (int i = 0; i < len1; i++) {
		temp[i] = arr[i];
	}


	for (int i = len1; i < len1 + len2; i++) {
		temp[i] = str.arr[i - len1];
	}


	temp[len1 + len2] = '\0';

	delete[] arr;
	arr = temp;
}


int String::compare(char const* const a) const
{
	String s(a);
	int res = this->compare(s);

	return res;
}


int String::compare(String const& str) const
{
	int i = 0;
	while (arr[i] != '\0' && str.arr[i] != '\0') {
		if (arr[i] < str.arr[i]) {
			return -1;
		}
		else if (arr[i] > str.arr[i]) {
			return 1;
		}
		else i++;
	}

	if (arr[i] == '\0' && str.arr[i] == '\0') {
		return 0;
	}
	else if (arr[i] == '\0') {
		return -1;
	}
	else return 1;

}


void String::insert_sub(char const* const a, int n)
{
	String s(a);
	insert_sub(s, n);
}

void String::insert_sub(String const& str, int n)
{
	if (n > length() || n < 0) {
		std::cout << "Index is Out Of Bounds\n";
		return;
	}

	int sub_len = str.length();
	int total_len = this->length() + sub_len;

	char* temp = new char[total_len + 1];

	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}

	for (int i = n; i < n + sub_len; i++) {
		temp[i] = str.arr[i - n];
	}

	for (int i = n + sub_len; i < total_len; i++) {
		temp[i] = arr[i - sub_len];
	}

	temp[total_len] = '\0';

	delete[] arr;
	arr = temp;
}


int String::substring_index(String const& str)
{
	int sub_len = str.length();
	int sub_index = 0;
	bool found = false;

	int count = 0;
	for (int i = 0; i < length(); i++) {
		count = 0;
		for (int j = 0; j < sub_len && j < length() - sub_len; j++) {
			if (arr[i + j] == str.arr[j]) {
				count++;
			}
			else break;
		}

		if (count == sub_len) {
			sub_index = i;
			found = true;
			break;
		}
	}

	if (!found) {
		return -1;
	}
	else return sub_index;
}


void String::delete_sub(char const* const a)
{
	String s(a);
	delete_sub(s);
}

void String::delete_sub(String const& str)
{
	int sub_index = substring_index(str);

	if (sub_index < 0) {
		std::cout << "Substring not found\n";
		return;
	}

	char* temp = new char[length() - str.length() + 1];

	for (int i = 0; i < sub_index; i++) {
		temp[i] = arr[i];
	}

	for (int i = sub_index + str.length(); i < length(); i++) {
		temp[i - str.length()] = arr[i];
	}

	temp[length() - str.length()] = '\0';

	delete[] arr;
	arr = temp;
}

void String::display() const
{
	int len = this->length();

	for (int i = 0; i < len; i++) {
		std::cout << arr[i];
	}

	std::cout << std::endl;
}
