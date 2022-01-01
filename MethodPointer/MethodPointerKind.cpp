#include<iostream>

using namespace std;

void Print(int n)
{
    cout << "전역 함수 Print()" << n << endl;
}


namespace A
{
    void Print(int n)
    {
        cout << "namespace A 전역 함수: " << n << endl;
    }
}
class Point
{
    int x;
    int y;

public:
    explicit Point(int _x = 0, int _y = 0):x(_x),y(_y) { }
    void Print() const {cout << x << "," << y << endl;}
    void PrintInt(int n){cout << "테스트 정수" << n << endl;}
    static void Print(int n)
    {
       cout << "Point 클래스의 정적 멤버 함수 Print()" << n <<endl;
    }
};


int main(void)
{
    void (*pf)(int); //정적 함수 포인터 선언

    Print(10); //namespace에 없는 Print() 호출
    A::Print(10); //namespace A의 전역 함수 호출
    //Point::Print(10); //Point 클래스의 정적 멤버 함수 호출

    cout << endl;


    pf =Print;
    pf(10); // namespace에없는 전역 함수 호출

    pf = A::Print;
    pf(10); //namespace A의 전역 함수 호출

    pf = Point::Print;
    pf(10); //Point 정적 멤버 함수 호출 


    Point pt(2,3);
    Point *p = &pt; //포인트 클래스의 포인터 선언

    void (Point::*pf1)() const; //멤버 함수 포인터 선언
    pf1 = &Point::Print;

    void (Point::*pf2)(int); 
    pf2 = &Point::PrintInt;

    pt.Print();
    pt.PrintInt(10);
    cout << endl;

    (pt.*pf1) (); //객체로 멤버 함수 포인터를 이용한 호출
    (pt.*pf2) (10); //동일

    cout << endl;
    (p->*pf1)(); //주소로 멤버 함수 포인터를 이용한 호출
    (p->*pf2)(10); //동일

    return 0;
}