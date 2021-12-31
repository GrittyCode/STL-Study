#include <iostream>
#include <string>

using namespace std;

//템플릿 클래스 선언
template <typename T = int, int capT = 100> // int, 100 디폴트 매개변수 값 지정
class Array
{
    T *buf;
    int size;     //원소의 개수
    int capacity; // 저장 가능한 메모리 크기
public:
    explicit Array(int cap = 100) : buf(0), size(0), capacity(cap)
    {
        buf = new T[capacity];
    }

    ~Array() { delete[] buf; }

    void Add(T data)
    {
        buf[size++] = data; //현재 size에 data를 더 해준 후, 다음 size를 1 더해준다.
    }

    T operator[](int idx) const
    {
        return buf[idx];
    }

    int GetSize() const
    {
        return size;
    }
};

int main(void)
{
    Array<> iarr; //정수(클라이언트가 T 타입 결정) Array 객체 디폴트 값 int, 100 지정 Array<int,100> 과 같다
    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);

    for (int i = 0; i < iarr.GetSize(); ++i)
    {
        cout << iarr[i] << " "; //[] operator를 통해 buf[i]의 데이터를 가져온다.
    }

    cout << "\n";

    Array<double> darr; //디폴트 값 100 지정
    darr.Add(1.1);
    darr.Add(2.2);
    darr.Add(3.3);

    for (int i = 0; i < darr.GetSize(); ++i)
    {
        cout << darr[i] << " "; //[] operator를 통해 buf[i]의 데이터를 가져온다.
    }

    cout << "\n";

    Array<string, 10> sarr; // defalut값 사용 X
    sarr.Add("abc");
    sarr.Add("ABC");
    sarr.Add("Hello!");

    for (int i = 0; i < sarr.GetSize(); ++i)
    {
        cout << sarr[i] << " ";
    }
    return 0;
}