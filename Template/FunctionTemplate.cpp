#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    explicit Point(int _x, int _y) : x(_x), y(_y) {}
    void Print() const { cout << x << "," << y << endl; }
};

template <typename T>
void Print(T a)
{
    cout << a << endl;
}

template <> // cout등 인터페이스를 지원하지 못하는 특수 객체의 경우 따로 특수화해준다.
void Print(Point a)
{
    cout << "Print 특수화 버전" << endl;
    a.Print();
}

template <typename T>
void Print(T a, T b)
{
    cout << a << " " << b << "\n";
}

template <typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << ", " << b << "\n";
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T, int size>
void PrintArray(T *arr)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "[" << i << "]:" << arr[i] << endl;
    }

    cout << endl;
}

int main(void)
{
    Print(1, 10);
    Print(1.0, 10.0);
    Print("Hello ", "Peter.");

    Print<int>(1, 10);
    Print<double>(1.0, 10.0);
    Print<const char *>("Hello ", "Peter");

    Print(1, 1.12);
    Print("Hello", 10);
    Print(3, "SpiderMan");

    int n1 = 10, n2 = 20;
    double d1 = 10.5, d2 = 20.5;

    swap(n1, n2);
    cout << n1 << "," << n2 << "\n";

    swap(d1, d2);
    cout << d1 << "," << d2 << "\n";

    int arr1[5]{10, 20, 30, 40, 50};
    PrintArray<int, 5>(arr1);

    double arr2[5]{1.1, 2.2, 3.3, 4.4, 5.5};
    PrintArray<double, 5>(arr2);

    Point a(1, 3);
    Print("3SpiderMan is Coming");
    Print(a);

    return 0;
}