//Fraction
#pragma warning (disable: 4326)
#include<iostream>
class Fraction;
Fraction operator*(Fraction left, Fraction right);
class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)
			denominator = 1;
		this->denominator = denominator;
	}
	
		         //       Constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "1argConstructor:\t" << this << std::endl;
	}

	Fraction(double decimal)
	{
		decimal += 1e-11;
		integer = decimal;
		denominator = 1e+9;
		decimal -= integer;
		numerator = decimal * denominator;
		reduce();

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Fraction(int integer , int numerator , int denominator )
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << "Constructor:\t" << this << std::endl;

	}

	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//             Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssigment: \t" << this << std::endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return* this = *this * other;
	}

	Fraction& operator+=(const Fraction& other)
	{
		//return* this = *this + other;
	}
	
	//             Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	
	//           Metods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return* this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return* this;
	}

	Fraction& reduce()
	{
		if (numerator == 0)
			return* this;
		int more, less;
		int rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return* this;
	}
	Fraction inverted()
	{
		/*Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		to_improper();
		return Fraction(this->denominator, this->numerator);
	}
	/*void print()const
	{
		if (integer)
			std::cout << integer;
		if (numerator)		
			{
				if (integer)
					std::cout << "(";
				std::cout << numerator << "/" << denominator;
				if (integer)
					std::cout << ")";
			}
		else if (integer == 0)
			std::cout << 0;		
		std::cout << std::endl;
	}*/
	std::ostream& print(std::ostream& os)const
	{
		if (integer)
			os << integer;
		if (numerator)
		{
			if (integer)
				os << "(";
			os << numerator << "/" << denominator;
			if (integer)
				os << ")";
		}
		else if (integer == 0)
			os << 0;
		return os;
	}

};

Fraction operator*( Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
	(
		left.get_numerator()* right.get_numerator(),
			left.get_denominator() * right.get_denominator()
		);*/
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*result.to_proper();
	result.reduce();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/( Fraction left,  Fraction right)
{
	
	return left * right.inverted();
	
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	/*if (obj.get_integer())
		os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())
			os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())
			os << ")";
	}
	else if (obj.get_integer() == 0)
		os << 0;
	return os ;*/

	return obj.print(os);
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/

	obj = Fraction(); 

	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = "() /";
	is.getline(buffer, SIZE);
	char* number[3] = {};
	int n = 0;

	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = pch;
	}

	/*for (int i = 0; i < n; ++i)
	{
		std::cout << number[i] << "\t";
	}
	std::cout << std::endl;*/

	switch (n)
	{
	case 1:
		obj.set_integer(atoi(number[0]));

		break;

	case 2: 
		obj.set_numerator(atoi(number[0]));
		obj.set_denominator(atoi(number[1]));
		break;

	case 3:
		obj.set_integer(atoi(number[0]));
		obj.set_numerator(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
	}
	return is;
}
//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
// #define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define HOME_WORK
void main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATORS_CHECK

	double a = 2.5;
	double b = 3.4;
	double c = a * b;
	cout << c << endl;
	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	/*Fraction C=A*B;
	C.print();*/

	/*Fraction D(840, 3600);
	D.reduce();
	D.print();*/

	/*C = A / B;
	C.print();*/

	A *= B;
	A.print();

#endif // OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2; // No conversion
	double b = 3; // From less to more
	int c = b; // From more to less without data loss 
	int d = 4.5;// From more to less with data loss
	cout << d << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	double a = 2; // From 'int' to 'double'
	Fraction A = (Fraction)5;// From 'int' to 'Fraction'
				   // Single-argument constructor
	A.print();
	Fraction B;
	B = (Fraction)8;
	B.print();

	//Fraction C = 12; // explicit constructor невозможно вызвать так
	Fraction C(12);    // Но explicit constructor всегда можно вызвать так 
	Fraction D{ 13 }; // Или вот так.  
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	double b = 2;
	int c = b;
	// From  'double' to 'int'
	Fraction A(2);
	int a(A);
	// From 'Fraction' to 'int'
	cout << a << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER
#ifdef HOME_WORK
	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;

	double b = 2.76;
	Fraction B = b;
	B.print();
#endif // HOME_WORK

	/*Fraction A(2, 3, 4);
	cout << A << endl;*/

	Fraction A;
	cout << "Введите простую дробь: " << endl;
	cin >> A;
	cout << A << endl;
}