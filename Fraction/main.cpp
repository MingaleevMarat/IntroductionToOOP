//Fraction
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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "1argConstructor:\t" << this << std::endl;
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
	
	Fraction& operator*=(const Fraction& other)
	{
		return* this = *this * other;
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
	void print()const
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


//#define CONSTRUCTORS_CHECK
void main()
{
	using namespace std;
	setlocale(LC_ALL,"rus");
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

	double a = 2.5;
	double b = 3.4;
	double c=a*b;
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

}