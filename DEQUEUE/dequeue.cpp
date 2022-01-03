#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main(void)
{
    vector<int> v(4,100);
    deque<int> dq(4,100);

    dq.push_back(10);
    dq.push_back(20);
    //vector와 다르게 앞에서도 넣어줄수있다.
    dq.push_front(100);
    dq.push_front(200);
    dq.push_front(300);

    dq.pop_back();
    //뒤에 있는 원소를 빼준다.

    dq.pop_front();
    //앞에 있는 원소를 빼준다.

    v.reserve(10);
    //dq는 한 메모리 블록에 연속으로 할당하는게 아닌, 여러 메모리 블록에 나뉘어 저장되므로 reserve를 제공 X
    //이러한 특성으로 인해 메모리 재할당과 같은 무거운 연산이 실행되지 않아 조금 더 효율적으로 동작한다.
    //나머지 특성과 기능은 벡터와 유사하다. ex)insert(),erase()

    return 0;
}