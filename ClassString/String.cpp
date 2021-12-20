#include<iostream>
#include"String.h"

///////////////// Class definition - Определение класса////////////////////
// 
// :: Оператор разрешения видимости (Scope operator)
const char* String::get_str()const
{
	return str;
}

char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}
String::String(int size) :size(size), str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*///Память, выделемую для строки обязательно нужно занулить.
	std::cout << "SizeConstructor:\t" << this << std::endl;
}

String::String(const char str[]) :String(strlen(str) + 1)
{
	/*this->size=strlen(str) + 1;
	this->str = new char[size] {};*/
	for (int i = 0; i < str[i]; i++)
		this->str[i] = str[i];

	std::cout << "Constructor:\t" << this << std::endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];*/
	std::cout << "CopyConstructor:\t" << this << std::endl;
}
String::~String()
{
	delete[] str;
	std::cout << "Destructor:\t" << this << std::endl;
}

//                 Operators:

String& String::operator=(const String& other)
{
	if (this == &other)
		return*this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	std::cout << "CopyAssignmed:\t" << this << std::endl;
	return*this;
}

String& String::operator+=(const String& other)
{
	return*this = *this + other;
}
const char& String::operator[](int i)const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}

//                 Meetods:

void String::print()const
{
	std::cout << "Size:\t" << size << std::endl;
	std::cout << "Str:\t" << str << std::endl;
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator>>(std::istream& is, String& obj)
{
	//return is >> obj.get_str();
	const int SIZE = 10240;
	char buffer[SIZE] = {};
	is >> buffer;
	obj = buffer;
	return is;
}

std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}

///////// Class definition end - Конец определения класса////////////////