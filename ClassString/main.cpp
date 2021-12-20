#include"String.h"
#define delimiter "\n---------------------------------\n"

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
	std::cout << "¬ведите строку: " << std::endl;
	//std::cin >> str;
	getline(std::cin, str);
	std::cout << str << std::endl;
#endif // INPUT_CHECK

}