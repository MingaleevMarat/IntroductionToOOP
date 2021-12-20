#include<iostream>

#define delimiter "\n---------------------------------\n"


/// //////////////// Class declaration- Объявление класса///////////////////

class String;
String operator+(const String& left, const String& right);
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

////////////////// Class declaration end - Конец объявления класса///////////////





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

String::String (const char str[]) :String(strlen(str) + 1)
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


//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK
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

}