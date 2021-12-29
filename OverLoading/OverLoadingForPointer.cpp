#include<iostream>

using namespace std;

class A
{

};

class B
{
public:
    operator A()
    {
        cout << "operator A()호출" << endl;
        return A();
    }

    operator int()
    {
        cout << "operator int()호출" << endl;
        return 10;
    }

    operator double()
    {
        cout << "operator double()호출" << endl;
        return 5.5;
    }
};



class Point
{
    int x;
    int y;
public:
    explicit Point(int _x = 0, int _y = 0): x(_x),y(_y) {} //explicit란 명시적으로만 생성자 호출 가능하게 해주는 것
    void Print() const {cout << x << ',' << y << endl;}
};


class PointPtr //스마트 포인터의 일종 ptr 객체를 통해 접근
{
    Point *ptr;
public:
    PointPtr(Point *p): ptr(p) {}
    ~PointPtr()
    {
        delete ptr;
    }

    Point* operator->() const
    {
        return ptr;
    }

    Point& operator*() const
    {
        return *ptr;
    }
};


int main(void)
{
    Point* p1 = new Point(2,3); //일반 포인터
    PointPtr p2 = new Point(5,5); //스마트 포인터

    Point p3;
    // explicit로 인해  p3 = 10; 불가능

    p3 = Point(10); 

    p1->Print(); 
    p2->Print(); //p2.operator->()->print()호출
    p3.Print();
    cout << endl;

    (*p1).Print();
    (*p2).Print(); //p2.operator*().print()호출


    A a;
    int n;
    double d;

    B b;
    a = b; //b.operator A() 암시적 호출
    n = b; //b.operator int() 암시적 호출
    d = b; //b.operator double() 암시적 호출



    return 0;
    
}