#include<iostream>

#define delimiter "\n---------------------------------\n"
#define a std::cout
#define b std::endl;
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
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};//Память, выделемую для строки обязательно нужно занулить.
		a << "SizeConstructor:\t" << this << b
	}

	String(const char str[])
	{
		this->size=strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < str[i]; i++)
			this->str[i] = str[i];
		
		a << "Constructor:\t" << this << b
	}
	String(String&& other)noexcept :size(other.size), str(other.str)
	{
		//MoveConstructor должен выполнять поврхностное копирование (Shallow copy)
		/*this->size = other.size;
		this->str = other.str;*/

		//Зануляем другой объект, для того чтобы его память не смог удалить деструктор.
		other.size = 0;
		other.str = nullptr;
		/*this->str = nullptr;
		*this = std::move(other);*/
		a << "MoveConstructor: "<<this << b
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		a<< "CopyConstructor:\t" << this << b
	}
	~String()
	{
		delete[] str;
		a << "Destructor:\t" << this << b
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
		a << "CopyAssignmed:\t" << this << b
		return* this;
	}

	String& operator=(String&& other)/*: size(other.size)*/
	{
		if (this == &other)
			return*this;
		delete this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		a << "MoveAssignment: \t"<<this << b
			return*this;
	}
	//Class(const Class& other); //CopyConstructor
	//Class& operator=(const Class& other); //CopyAssignment
	//Class(Class&& other);      //MoveConstructor
	//Class& operator=(Class&& other);  //MoveAssignment
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
		a << "Size:\t" << size << b
		a << "Str:\t" << str << b
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
#define OPERATORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();
	a << str1 << b
	String str2(25);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	a << str3 << b

	String str4 = str3;
	a << str4 << b

	String str5;
	str5 = str3;
	a << str5 << b
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	a << delimiter << b
		String str3;
	str3 = str1 + str2;
	a << delimiter << b
	a << str3 << b
	a << delimiter << b
	str1 += str2;
	a << delimiter << b
	a << str1 << b
	a << delimiter << b
#endif // OPERATORS_CHECK

	//String str;
	//a <<"Введите строку: " << b
	////std::cin >> str;
	//getline(std::cin, str);
	//a << str << b
}