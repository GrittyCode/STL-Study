#include<iostream>
#include<algorithm> //for_each 알고리즘(서버)를 사용하기위함.

using namespace std;

struct Functor1
{
    void operator() (int n)
    {
        cout << n << " ";
    }
};

struct Functor2
{
    void operator() (int n)
    {
        cout << n * n << " ";
    }
};

struct Functor3
{
    void operator() (int n)
    {
        cout << "정수 : "<< n << endl;
    }
};




class Adder
{
    int total;
public:
    explicit Adder(int n = 0) : total(n) {}
    int operator() (int n)
    {
        return total += n;
    }
};

int main(void)
{
    Adder add(0); //초기 값 0

    cout << add(10) << endl; // 10누적
    cout << add(20) << endl; // 20누적
    cout << add(30) << endl; // 30누적


    int arr[5] {1,2,3,4,5};

    for_each(arr, arr + 5 , Functor1()); //함수 객체를 전달
    cout << endl << endl;
    for_each(arr, arr + 5 , Functor2());
    cout << endl << endl;
    for_each(arr, arr + 5 , Functor3());

    return 0;
}