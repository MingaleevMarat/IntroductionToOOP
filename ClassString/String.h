#pragma once
#include<iostream>
/// //////////////// Class declaration- ќбъ€вление класса///////////////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);
std::istream& getline(std::istream& is, String& obj);
class String
{
	int size;
	char* str;
public:

	const char* get_str()const;

	char* get_str();
	int get_size()const;
	explicit String(int size = 80);

	String(const char str[]);
	String(const String& other);
	~String();

	//                 Operators:

	String& operator=(const String& other);

	String& operator+=(const String& other);
	const char& operator[](int i)const;

	char& operator[](int i);

	//                 Meetods:

	void print()const;
};

////////////////// Class declaration end -  онец объ€влени€ класса///////////////