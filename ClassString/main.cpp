#include<iostream>

#define delimiter "\n---------------------------------\n"
class String;
String operator+(const String& left, const String& right);
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
	explicit String(int size = 80):size(size), str(new char[size] {})
	{
		/*this->size = size;
		this->str = new char[size] {};*///Память, выделемую для строки обязательно нужно занулить.
		std::cout << "SizeConstructor:\t" << this << std::endl;
	}

	String(const char str[]):String(strlen(str)+1)
	{
		/*this->size=strlen(str) + 1;
		this->str = new char[size] {};*/
		for (int i = 0; i < str[i]; i++)
			this->str[i] = str[i];
		
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other):String(other.str)
	{
		/*this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];*/
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

	String& operator+=(const String& other)
	{
		return* this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}

	 char& operator[](int i)
	{
		return str[i];
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
//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define INPUT_CHECK
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

#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	std::cout << delimiter << std::endl;
	String str3 = str1 + str2;
	std::cout << delimiter << std::endl;
	std::cout << str3 << std::endl;
	std::cout << delimiter << std::endl;
	str1 += str2;
	std::cout << delimiter << std::endl;
	std::cout << str1 << std::endl;
	std::cout << delimiter << std::endl;
#endif // OPERATORS_CHECK

#ifdef INPUT_CHECK
	String str;
	std::cout << "Введите строку: " << std::endl;
	//std::cin >> str;
	getline(std::cin, str);
	std::cout << str << std::endl;
#endif // INPUT_CHECK

	String str1;
	str1.print();
	String str2 = "Hello";
	str2.print();
	String str3 = str2;
	str3.print();
	String str4();
	//str4.print(); функция, а не объект
	String str5{};
	str5.print();

	String str6("World");
	String str7{ "Planet" };

}