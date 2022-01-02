#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>

using namespace std;

//v.begin() : 컨테이너의 시작 원소를 가리키는 반복자를반환
//v.end() : 컨테이너의 끝 표시 반복자를반환
//++iter 반복자를 다음 원소를 가리키도록 이동
//*iter iter가 가리키는 원소를 반환.
//depue도 동일하게 진행

int main(void)
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << endl; //반복자가 가르키는 원소를 역참조로 데이터를 뽑아온다.

    
    vector<int>::iterator iter2;

    iter2 = v.begin();

    iter2 += 2;

    cout << *iter2 << endl; //첫번째원소에서 2번째 떨어진 원소 역참조 -> 30 출력

    iter2 = iter2 + 2;

    cout << *iter2 << endl; //번째 떨어진 원소 역참조 -> 50 출력


    vector<int>::iterator iter3;
    iter3 = find(v.begin(),v.end(), 20);
    cout << *iter3 << endl;

    iter3 = find(v.begin(), v.end(), 100);
    if(iter3 == v.end())
    {
        cout << "100이 없음!" << endl; //100이없으면 iter == v.end()가 성립
    }

    sort(v.begin(), v.end()); //반복자를 통해 sort 이땐, 임의접근반복자를 요구하므로 vector와 deque만이 가능
    
    list<int> lt;
    lt.push_back(1);
    lt.push_back(3);
    lt.push_back(2);

    //sort(lt.begin(), lt.end()); //임의 접근 반복자가 아니므로 컴파일시 오류다.


    //함수 객체 STL
    sort(v.begin(), v.end(), less<int>()); //() operator x < y 정렬이므로 1 2 3 4 5 이렇게 오름차순 정렬이 진행
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << endl;
    }

    sort(v.begin(), v.end(), greater<int>()); //() operator x >= y 정렬이므로 5 4 3 2 1 이렇게 내림차순 정렬이 진행
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << endl;
    }
    
    return 0;
}