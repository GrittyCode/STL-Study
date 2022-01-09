#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Pred(int a, int b)
{
    return abs(b - a) > 10;
}

struct PredStruct //함수객체
{
    bool operator()(int a, int b)
    {
        return abs(b - a) > 10;
    }
};


int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(90);

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int>::iterator iter;
    bool (*pred) (int a, int b);
    pred = Pred;

    
    iter = adjacent_find(v.begin(), v.end(), PredStruct()); //함수자, 함수, 함수포인터 (이항 조건자)로 가능
    //adjacent_find()란, 조건자에 맞는 인접한 원소가 존재하는지 확인해주는것. 만약 존재한다면 해당 원소의 반복자 위치 반환, 아니라면 v.end()반복자 반환

    if(iter != v.end())
        cout << *iter << endl;
    
    for(;iter != v.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;
    
    //adjacent 인접한
    return 0;
}