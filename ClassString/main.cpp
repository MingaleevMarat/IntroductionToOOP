#include<iostream>


class String
{
	int size;
	char* str;
public:

	 const char* get_str()const
	{
		return str;
	}

	 char* get_str()
	 {
		 return str;
	 }
	int get_size()const
	{
		return size;
	}
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};//Память, выделемую для строки обязательно нужно занулить.
		std::cout << "SizeConstructor:\t" << this << std::endl;
	}

	String(const char str[])
	{
		this->size=strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < str[i]; i++)
			this->str[i] = str[i];
		
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	~String()
	{
		delete[] str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//                 Operators:
	
	String& operator=(const String& other)
	{
		if (this == &other)
			return* this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		std::cout << "CopyAssignmed:\t" << this << std::endl;
		return* this;
	}
	//                 Meetods:

	void print()const
	{
		std::cout << "Size:\t" << size << std::endl;
		std::cout << "Str:\t" << str << std::endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();
	std::cout << str1 << std::endl;
	String str2(25);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	std::cout << str3 << std::endl;

	String str4 = str3;
	std::cout << str4 << std::endl;

	String str5;
	str5 = str3;
	std::cout << str5 << std::endl;
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	std::cout << str3 << std::endl;
}