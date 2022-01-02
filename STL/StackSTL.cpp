#include <iostream>
#include <stack>
#include<vector>
#include<string>

using namespace std;

template <typename T>
class STACK
{
    T *data;
    int idx;

public:
    STACK()
    {
        data = new T[100];
        idx = 0;
    }
    ~STACK() { delete[] data; }
    void push(T _tmp)
    {
        data[idx++] = _tmp;
    }

    void pop()
    {      
        idx--;
    }

    T top()
    {
        return data[idx - 1];
    }

    bool empty()
    {
        return idx == 0;
    }
};

int main(void)
{
    stack<int> st; // stack 컨테이너 생성
    st.push(10);
    st.push(20);
    st.push(30);

    STACK<int> ST;
    ST.push(100);
    ST.push(200);
    ST.push(300);

    STACK<string> stST;
    stST.push("A");
    stST.push("B");
    stST.push("C");

    cout << stST.top()<< endl;

    cout << st.top() << endl;
    st.pop(); // top 데이터 삭제
    cout << st.top() << endl;
    st.pop(); // top 데이터 삭제
    cout << st.top() << endl;
    st.pop(); // top 데이터 삭제

    cout << ST.top() << endl;
    ST.pop(); // top 데이터 삭제
    cout << ST.top() << endl;
    ST.pop(); // top 데이터 삭제
    cout << ST.top() << endl;
    ST.pop(); // top 데이터 삭제

    if (st.empty())
        cout << "stack 데이터 X" << endl;

    if(ST.empty())
        cout << "임의생성 STACK 데이터 X" << endl;

    stack<int,vector<int>> Vst; //vector 컨테이너를 이용한 stack 컨테이너 생성
    st.push(10); 
    st.push(20); 
    st.push(30);
     
    return 0;
}