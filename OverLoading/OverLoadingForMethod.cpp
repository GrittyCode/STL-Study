#include<iostream>

using namespace std;

struct FuncObject
{
    void operator() (int arg) const
    {
        cout << "정수 : " << arg << endl;
    }

    void operator() (int arg1, int arg2) const
    {
        cout << "정수 : " << arg1 << "정수 : " << arg2 << endl; 
    }
};

int main(void)
{
    

    FuncObject print;

    print(10);
    print(10,20);

    cout << endl;

    print.operator()(10);
    print.operator()(10,20);
    
    cout << endl;

    FuncObject() (10);
    FuncObject() (10,20);

    cout << endl;

    FuncObject().operator()(10);
    FuncObject().operator()(10,20);

}