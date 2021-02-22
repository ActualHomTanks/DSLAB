#pragma once

class String
{
private:
	char* arr = nullptr;

private:

public:
	String();
	String(char const* const a);
	~String();
	int length() const;
	static int length(char const* const a);
	void concat(char const* const a);
	void concat(String const& str);
	int compare(char const* const a) const;
	int compare(String const& str) const;
	void insert_sub(char const* const a, int n);
	void insert_sub(String const& str, int n);
	int substring_index(String const& s);
	void delete_sub(char const* const a);
	void delete_sub(String const& str);
	void display() const;

};