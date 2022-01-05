#include<iostream>
#include<set>
using namespace std;

int main(void)
{
    multiset<int> ms;
    multiset<int>::iterator iter;

    ms.insert(50);
    ms.insert(30);
    ms.insert(80);
    ms.insert(80);
    ms.insert(30);
    ms.insert(70);

    iter = ms.insert(10); //set이 pair<bool,반복자>를 반환하는 것과 달리 멀티셋은 중복이 허용되므로 
    //저장된 위치만을 가리키는 반복자를 반환

    cout << "iter의 원소: " << *iter << endl;

    for(iter = ms.begin() ; iter != ms.end(); iter++)
        cout << *iter << endl;
    cout << "\n";

    cout << "30 원소의 개수: " << ms.count(30) << "\n";

    iter = ms.find(30); //30의 반복자를 찾는다.
    cout << "iter: " << *iter << endl;

    multiset<int>::iterator lower_iter;
    multiset<int>::iterator upper_iter;

    lower_iter = ms.lower_bound(30);
    upper_iter = ms.upper_bound(30);

    cout << "lower_iter: " << *lower_iter << ", " << "upper_iter" << *upper_iter << endl;

    cout << "구간 [lower_iter, upper_iter)의 순차열: ";
    for(iter = lower_iter; iter != upper_iter; ++iter)
    {
        cout << *iter << " ";
    } 
    cout << endl;

    pair<multiset<int>::iterator,multiset<int>::iterator> pair_iter;

    pair_iter = ms.equal_range(30); //30의 원소 시작점과 끝점을 표시한다.
    if(pair_iter.first != pair_iter.second)
        cout << "해당 원소 존재" << "\n";
    else
        cout << "해당 원소 존재 X" << "\n";

    //MULITISET은 SET과 동일하지만, 중복된 원소를 포함 할 수 있다는 점만 다르다.

    return 0;
}