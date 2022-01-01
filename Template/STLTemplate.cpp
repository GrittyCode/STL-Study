#include <iostream>
#include <string>

using namespace std;

template <typename RetType, typename ArgType>
class Functor
{
public:
    RetType operator()(ArgType data)
    {
        cout << data << endl;
        return RetType();
    }
};

template <typename T1, typename T2>
struct pair
{
    T1 first;
    T2 secnond;
    pair(const T1 &ft, const T2 &sd) : first(ft), secnond(sd) {}
};

int main(void)
{
    Functor<void, int> functor1;
    functor1(10);
    Functor<bool, string> functor2;
    functor2("Hello");

    pair<int, string> p2(1, "one");
    cout << p2.first << "," << p2.first << "\n";

    return 0;
}