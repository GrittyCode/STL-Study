#include <iostream>
#include <set>
#include <functional>

using namespace std;

void LowerBoundAndUpperBound()
{
    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n";

    set<int>::iterator iter_lower;
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30);
    iter_upper = s.upper_bound(30);

    cout << *iter_lower << "\n";
    cout << *iter_upper << "\n";

    iter_lower = s.lower_bound(55);
    iter_upper = s.upper_bound(55);

    if (iter_lower != iter_upper)
        cout << "55가 s에 있음!" << endl;
    else
        cout << "55가 s에 없음!" << endl;
}

void EqualRange()
{
    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n";
    
    pair<set<int>::iterator, set<int>::iterator> iter_pair;
    //반복자의 쌍을 생성

    iter_pair = s.equal_range(30);
    cout << *iter_pair.first << "\n";
    cout << *iter_pair.second << "\n";

    iter_pair = s.equal_range(55);
    if(iter_pair.first == iter_pair.second)
        cout << "해당 원소가 없슴!" << "\n";
    else
        cout << "해당 원소가 있슴!" << "\n";
}

int main(void)
{
    set<int> s;

    pair<set<int>::iterator, bool> pr;

    pr = s.insert(50);
    s.insert(40);
    s.insert(80);

    if (true == pr.second)
        cout << *pr.first << " 삽입 성공!" << endl;
    else
        cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    pr = s.insert(50);

    if (true == pr.second)
        cout << *pr.first << " 삽입 성공!" << endl;
    else
        cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

    //삽입은 실패했지만 반복자의 위치는 옮겨진다.

    s.insert(pr.first, 999);

    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    // s.insert(50) //중복된 원소(key) 삽입은 오류다.

    // pair로 inset의 올바른 동작인지 아닌지 판단 가능.

    // set<int,greater<int>> s2; //조건자를 오름차순으로 바꿀 수 있다.

    //원소의 개수를 반환하는 count 함수, set 컨테이너는 중복을 허용하지 않으므로 0,1밖에 결과가 없다.
    cout << s.count(50) << endl;

    iter = s.find(30); //원소를 검색하는 find() 함수

    if (iter != s.end())
        cout << *iter << "가 존재한다!" << endl;
    else
        cout << "그 값은 존재하지 않다." << endl;

    set<int, less<int>> s2;

    cout << (!s.key_comp()(30, 50) && !s.key_comp()(50, 30)) << endl;
    cout << (!s.key_comp()(30, 30) && !s.key_comp()(30, 30)) << endl;
    // find 메서드 또한 == 으로 연산하지 않고 a < b b < a를 둘다 false로 받아줄때 같다고 판단한다.

    cout << "============== LowerBoundUpperBound =================" << "\n";
    LowerBoundAndUpperBound();

    cout << "============== LowerBoundUpperBound =================" << "\n";
    EqualRange();

    //set은 연관 컨테이너 중 하나이다 또한, 노드 기반 컨테이너이다.
    //특정 정렬 기준에 의해 원소가 자동으로 정렬되는 컨테이너이다. 
    //이 컨테이너는 원소를 찾는데 중심인 컨테이너이다. 
    //균형 이진 트리로 구성되어 있어 원소를 찾는데 복잡도가 로그 시간 복잡도를 보장한다.
    //찾는데 제공된 메서드는, count(), find(), lower_bound(), upper_bound(),equal_range()가 있다.
    //삽입하는데는, insert() 메서드만이 존재하며, 정렬 기준에 맞춰 균형 이진 트리에 저장된다.
    //멤버 함수 begin(), end(),rbegin(),rend()가 존재하여 순차열의 시작과끝을 가리키는 반복자를 반환한다.
    
    return 0;
}