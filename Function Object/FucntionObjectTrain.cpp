#include<iostream>
#include<functional>

using namespace std;

typedef less<int> Less;
typedef greater<int> gerator;

struct Plus
{
    int operator()(int a, int b)
    {
        return a + b;
    }
};


struct Minus
{
    int operator()(int a, int b)
    {
        return a - b;
    }
};

int main(void)
{
    Less l;
    gerator g;
    Plus p;
    Minus m;


    cout << l(10,20) << endl;
    cout << l(30,20) << endl;

    cout << l.operator()(10,20) << endl; //명시적 호출;

    cout << g.operator()(10,20) << endl;//명시적 호출;
    cout << g.operator()(20,10) << endl;
    cout << g(10,20) << endl;//암시적 호출

    cout << m(20,10) << endl;
    cout << p(20, 10) << endl;

    return 0;
}