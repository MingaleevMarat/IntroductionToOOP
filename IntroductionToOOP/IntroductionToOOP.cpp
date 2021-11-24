// IntroductionToOOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define tab "\t"
class Point
{
    double x;
    double y;
public:
    //get методы должны быть константными
    //константным называется метод, который не изменяет объект, для которого вызывается.
    // Для константного объекта могут быть вызваны только константные методы.
    double get_x()const
    {
        return x;
   }
    double get_y()const
    {
        return y;
    }

    void set_x(double x)
    {
       this->x = x;
    }
    void set_y(double y)
    {
        this->y = y;
    }

    //                  Constructor:
    /*Point()
    {
        x = y = 0;
        std::cout << "DefaultConstructor:\t" << this << std::endl;
    }*/
    //Point(double x)
    //{
    //    this->x = x;
    //    this->y = 0; //this->y = double(); значение по умолчанию для типа double
    //    //double()- якобы вызываем конструктор по умолчанию для double.
    //    std::cout << "1argConstructor:" << this << std::endl;
    //}
    Point(double x=0, double y=0)
    {
        this->x = x;
        this->y = y;
        std::cout << "Constructor:\t" << this << std::endl;
    }

    Point(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
       std:: cout << "CopyConstructor: " << this << std::endl;
    }
    ~Point()
    {
        std::cout << "Destructor:\t" << this << std::endl;
    }

    //             Operators:
    void operator=(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        std::cout << "CopyAssignment: " << this << std::endl;
    }

    //           Methods:
    double distance(Point other)
    {
        //other-другой(другая точка).
        double x_distance = this->x - other.x;
        double y_distance = this->y - other.y;
        double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
        //sqrt-Square Root(Квадратный корень)
        return distance;
    }
    void print()const
    {
        std::cout << "X= " << x << "\tY= " << y << std::endl;
    }
};

double distance(Point A, Point B)
{
    double x_distance = A.get_x() - B.get_x();
    double y_distance = A.get_y() - B.get_y();
    return sqrt(x_distance * x_distance + y_distance * y_distance);
}


//#define STRUCT_POINT

//Point G;//Global object (Глобальный объект)
//int g;//Global variable (глобальная переменная) DEPRECATED

#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
int main()
{
    using namespace std;
    setlocale(LC_ALL, "Rus");
#ifdef STRUCT_POINT 
    Point A;
    A.x = 2;
    A.y = 3;
    cout << A.x << tab << A.y << endl;
    Point* pA = &A;
    cout << pA->x << tab << pA->y << endl;
#endif STRUCT_POINT
#ifdef CONSTRUCTORS_CHECK
    Point A;
   // A.set_x(2);
   // A.set_y(3);
    //cout << A.get_x() << "\t" << A.get_y() << endl;
    A.print();
    Point B(4, 5);
    B.print();
    Point C = 5;//Single-argument constructor
    C.print();

    Point D(8);//Single-argument constructor
    D.print();

    Point E = D;     //Copy constructor
    E.print();

    Point F(B);      //Copy constructor
    F.print();

    Point G;
    G = F;    //CopyAssignment (operator=)
    G.print();
    //Безымянное пространство имён:
    {
        int a=2;
    }
#endif CONSTRUCTORS_CHECK
#ifdef DISTANCE_CHEK   
    Point A(2, 3);
    Point B(3, 4);
    cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
    cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;

    cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
    cout << "Расстояние между точками B и А: " << distance(B, A) << endl;
#endif 

    
}
