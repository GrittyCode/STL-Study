#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//본 문은
// template 클래스 사용과 매개변수 default값, 특수 템플릿, 함수 포인터 함수 객체를 같이 사용하는 방법을 명시한다.

template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
    while (begin != end)
    {
        pf(*begin++);
    }
}

template <typename T>
void Print(T data)
{
    cout << data << " ";
}

template <typename T>
struct PrintFunctor
{
    string sep; //출력 구분자 정보

    explicit PrintFunctor(const string &s = " ") : sep(s) {}

    void operator()(T data) const
    {
        cout << data << sep;
    }
};

template <typename T>
class ObjectInfo
{
    T data;

public:
    ObjectInfo(const T &d) : data(d) {}

    void Print()
    {
        cout << "타입 : " << typeid(data).name() << endl;
        cout << "크기 : " << sizeof(data) << endl;
        cout << "값 : " << data << endl;
        cout << endl;
    }
};

template <>
class ObjectInfo<string>
{
    string data;

public:
    ObjectInfo(const string &d) : data(d) {}

    void Print()
    {
        // cout << "타입 : " << typeid(data).name() << endl;
        cout << "타입 : "
             << "string" << endl;
        cout << "크기 : " << sizeof(data) << endl;
        cout << "문자열 길이 : " << data.length() << endl; //길이 정보 추가
        cout << "값 : " << data << endl;
        cout << endl;
    }
};

int main(void)
{
    ObjectInfo<int> d1(100);
    d1.Print();

    ObjectInfo<double> d2(111.222333);
    d2.Print();

    ObjectInfo<string> d3("Hello, Peter Parker");
    d3.Print();

    int arr[5]{1, 2, 3, 4, 5};
    For_each(arr, arr + 5, Print<int>);

    cout << endl;

    string starr[5] = {"hello", "peter", "parker", "How", "are"};
    For_each(starr, starr + 5, Print<string>);

    cout << endl;

    //함수 포인터 사용
    void (*pf)(int);
    pf = Print<int>;

    For_each(arr, arr + 5, pf);

    //함수 객체 사용

    For_each(arr, arr + 5, PrintFunctor<int>()); //함수 객체 사용으로 " " 공백 자동 입력
    cout << endl;
    For_each(starr, starr + 5, PrintFunctor<string>("*\n"));

    return 0;
}