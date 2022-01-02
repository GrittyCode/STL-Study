#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }

    cout << "\n";

    reverse_iterator<vector<int>::iterator> riter(v.end());
    reverse_iterator<vector<int>::iterator> end_riter(v.begin());

    for(; riter != end_riter; ++riter)
        cout << *riter << " ";

    cout << "\n";

    vector<int>::reverse_iterator riter2(v.rbegin()); // rbegin() rend()로 정의된 역방향 반복자 반환 메서드 
    for(; riter2 != v.rend(); ++riter2)
        cout<< *riter2 << " ";

    cout << "\n";

    cout << less<int>()(10,20) << "\n";
    //cout << not2(less<int>())(10,20) << "\n";
    cout << less<int>()(10,10) << "\n"; //not1은단항 조건자에 not2는 이항조건자에 사용됨. 
    //cout << not2(less<int>()) (10,10) << "\n";

    //not2 -> < 연산이면 >=연산으로 >= 연산이면 < 연산으로 반대되게 만들어준다.

    //할당기란 컨테이너 메모리 할당 정보와 정책을 캡슐화한 STL 구성 요소이다.


    return 0;
}