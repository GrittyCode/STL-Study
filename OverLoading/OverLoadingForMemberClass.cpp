#include<iostream>

using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0):x(_x),y(_y) {}
    void print() const {cout << x << ',' << y << endl;} //const 함수로서 print를 통해 변환 불가능
    const Point operator+(const Point& arg) const
    {
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;

        //pt.y = (*this).y; 화살표 연산자를 사용하지 않는다면 뒤와 같이 사용
        //this란 항상 호출된 객체를 가리키는 숨겨진 포인터이므로 ->로 호출해야한다. 
        return pt;
    }


    const Point operator++() //전위 ++ 연산 연산 후의 값을 return해준다.
    {
        ++x;
        ++y;
        return *this;
    }

    const Point operator++(int) //후위++ 연산 전의 값을 return해준다.
    {
        Point pt(x,y);
        ++x;
        ++y;
        return pt;
    }

    const Point operator--()
    {
        --x;
        --y;
        return *this;
    }

    const Point operator--(int)
    {
        Point pt(x,y);
        --x;
        --y;
        return pt;
    }

    bool operator==(const Point& arg) const
    {
        return this->x == arg.x && this->y == arg.y ? true : false;
    }

    bool operator!=(const Point& arg) const
    {
        return !(*this == arg);
    }

    //-- 전위 후위도 ++ 전위 후위와 같은 방식으로 정의 가능

    //const가 앞에 붙는다면 반환되는 값이 변경하지 못하는 값으로 반환된다는 뜻이고
    //const가 뒤에 붙는다면 반환되는 값이 해당 함수내에서 멤버변수를 변경 못하도록 막는것이다.

};



int main(void)
{
    Point p1(2,3), p2(2,3);
    Point result;

    result = ++p1;
    p1.print();
    result.print();

    result = p2++;
    p2.print();
    result.print();

    if(p1 == p2)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }

    return 0;

}