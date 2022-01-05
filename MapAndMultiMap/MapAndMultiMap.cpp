#include <iostream>
#include <map>
#include <string>

using namespace std;

void MapFind()
{
    map<int, int> m;
    m[5] = 100;
    m[4] = 30;
    m[3] = 20;
    m[2] = 60;
    m[1] = 70;

    map<int, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << "," << iter->second << ") ";
    cout << endl;

    iter = m.find(5);

    if (iter != m.end())
        cout << "5 존재 "<< "\n";
    else
        cout << "5 존재 X " << "\n";

    map<int, int>::iterator lower_iter;
    map<int, int>::iterator upper_iter;

    lower_iter = m.lower_bound(5);
    upper_iter = m.upper_bound(5);

    if (lower_iter == upper_iter)
        cout << "5 존재 X"
             << "\n";
    else
        cout << "5 존재"
             << "\n";

    pair<map<int, int>::iterator, map<int, int>::iterator> range_iter;
    range_iter = m.equal_range(5);

    if (range_iter.first == range_iter.second)
        cout << "5 존재 X"<< "\n";
    else
        cout << "5 존재"<< "\n";
}

void MapGreater()
{
    map<int, string, greater<int>> m;

    m[5] = "five";
    m[3] = "three";
    m[8] = "eight";
    m[4] = "four";
    m[1] = "one";
    m[7] = "seven";
    m[9] = "nine";

    map<int, string, greater<int>>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << "," << iter->second << ") ";
    cout << endl;

    cout << m[9] << " ";
    cout << m[8] << " ";
    cout << m[7] << " ";
    cout << m[5] << " ";
    cout << m[4] << " ";
    cout << m[3] << " ";
    cout << m[1] << " " << endl;
}

void MultiMapFind()
{
    multimap<int,int> mm;
    mm.insert(pair<int,int> (5,100));
    mm.insert(pair<int,int> (5,200));
    mm.insert(pair<int,int> (3,160));
    mm.insert(pair<int,int> (3,170));
    mm.insert(pair<int,int> (3,322));
    mm.insert(pair<int,int> (2,2));
    mm.insert(pair<int,int> (1,1));
    mm.insert(pair<int,int> (10,10));


    multimap<int,int>::iterator iter;
    iter = mm.find(3); //중복된 값이 있어도 처음으로 발견된 key의 반복자 위치를 반환한다. 반복자가 없다면 mm.end()이다.
    if(iter != mm.end())
        cout << iter->first << "존재합니다." <<"값: " << iter->second << "\n"; //map의 반복자는 ->로 first,second를 접근 할 수 있게 operator가 설정 되 있다.
    else
        cout << "해당 원소는 존재하지 않습니다." << "\n";
    
    //중복된 키를 모두 뽑기 위해선 equal_range로 가능
    multimap<int,int>::iterator lower_iter;
    multimap<int,int>::iterator upper_iter;
    lower_iter = mm.lower_bound(3);
    upper_iter = mm.upper_bound(3);

    for(;lower_iter != upper_iter; lower_iter++)
    {
        cout << lower_iter->first << "," << lower_iter->second << " ";
    }
    cout << endl;

    pair<multimap<int,int>::iterator,multimap<int,int>::iterator> pair_iter;
    pair_iter = mm.equal_range(5);

    for(multimap<int,int>::iterator iter = pair_iter.first; iter != pair_iter.second; ++iter)
        cout << iter->first << "," << iter->second << " ";
    cout << endl;

}

int main(void)
{
    // key와value 모두 정수형으로 저장, 기본정렬은 less로
    map<int, int> m;

    m.insert(pair<int, int>(5, 100));
    m.insert(pair<int, int>(3, 20));
    m.insert(pair<int, int>(8, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(1, 70));
    m.insert(pair<int, int>(7, 100));

    pair<int, int> pr2(9, 50); //객체 생성 후 저장.
    m.insert(pr2);

    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
        cout << "(" << (*iter).first << "," << (*iter).second << ")"
             << " ";
    cout << endl;

    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << "," << iter->second << ")"
             << " ";
    cout << endl;
    //반복자는 -> 연산자 오버로딩이 되어 있으므로 포인터처럼 멤버를 -> 연산자로 접근 가능.

    pair<map<int, int>::iterator, bool> pr;
    pr = m.insert(pair<int, int>(5, 50));
    if (pr.first != m.end())
        cout << "삽입 성공!"
             << "\n";
    else
        cout << "KEY가 이미 존재한다. 키의 중첩을 원한다면 멀티맵을 사용해라."
             << "\n";

    m[5] = 200; // key가 존재한다면 key 5가 가르키는 원소를 200으로 갱신해준다.
    m[10] = 40;

    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << "," << iter->second << ")"
             << " ";
    cout << endl;

    //정렬 기준은 Key의 Less가 기준이다.

    cout << "========== MAP Greater =============== \n";
    MapGreater();

    cout << "========== MAP find,upper bound, lower bound, equal range =============== \n";
    MapFind();


    cout << "========== MULTI MAP =============== \n";
    MultiMapFind();

    return 0;


    //Map의 주요 특징, 연관 컨테이너, 노드기반 컨테이너이다.
    //Set과 다른 점은 pair을 이용해 Key와 Value가 존재하는 pair 쌍 객체로 구성되있다는 것.
    //Key를 이용해 원소를 찾거나 추가할 수 있다.
    //Set과 달리 [] 연산이 가능한데, map[Key] = vlaue로 값을 넣을수 있고 map[key]로 원소를 찾을 수 도있다.
    //그 외는 Set과 동일하고 MultiMap은 중복된 키가 존재 할 수 있다는 점을 제외하면 Map과 같다.
    //MultiMap의 경우 중복된 키가 존재하므로 []연산은 사용 불가능 하다.
}