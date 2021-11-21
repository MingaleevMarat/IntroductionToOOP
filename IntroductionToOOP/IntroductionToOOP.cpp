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
};

//#define STRUCT_POINT
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

    Point A;
    A.set_x(2);
    A.set_y(3);
    cout << A.get_x() << "\t" << A.get_y() << endl;
}
