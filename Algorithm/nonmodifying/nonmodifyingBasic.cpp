#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point
{
    int x, y;

public:
    explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    int GetX() const { return x; }
    int GetY() const { return y; }
    void Print() const { cout << '(' << x << ',' << y << ')' << endl; }
};

bool XCompare(const Point &left, const Point &right)
{
    return left.GetX() < right.GetX();
}

bool YCompare(const Point &left, const Point &right)
{
    return left.GetY() < right.GetY();
}

bool AreaCompare(const Point &left, const Point &right)
{
    return left.GetX() * left.GetY() < right.GetX() * right.GetY();
}

bool Pred(int a)
{
    return 25 < a;
}

bool EqualPred(int left, int right)
{
    return abs(left - right) < 5; //오차 범위 0~4까지 허용
}

bool findPred(int n)
{
    return 35 < n;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(24);
    v2.push_back(34);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(30);

    for (vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    cout << "====================== count()======================\n";

    int n = count(v.begin(), v.end(), 30); // count는 반복자 위치의 (] 범위까지 3번째 매개변수에 해당하는 원소의 개수를 추출해준다.
    cout << "30의개수 : " << n << "\n";

    cout << "====================== count_if()======================\n";

    int n2 = count_if(v.begin(), v.end(), Pred);
    cout << "25보다 큰 수의 개수 : " << n2 << "\n";

    //순차열 비교를 위해선 equal()을 사용

    cout << "====================== equal()======================\n";

    if (equal(v.begin(), v.end(), v2.begin(), EqualPred)) // v의 원소열 개수 현재는 5개가 v2의 1~5개까지 같은 순차열인지 확인 기본은 같은것을 전제로 둔다
    {
        cout << "두 순차열은 같습니다. "
             << "\n";
    }
    else
    {
        cout << "두 순차열은 같지 않습니다."
             << "\n";
    }

    cout << "====================== find()======================\n";
    vector<int>::iterator find_iter;
    find_iter = find(v.begin(), v.end(), 20);
    if (find_iter != v.end())
        cout << "20을 찾았다 대박!\n";

    cout << "====================== find_if()======================\n";

    find_iter = find_if(v.begin(), v.end(), findPred);
    if (find_iter != v.end())
        cout << "조건보다 큰 첫 원소: " << *find_iter << "\n";

    cout << "====================== max()======================\n";
    int a = 10, b = 20;
    int r = max(a, b);
    cout << r << "\n";

    cout << "====================== max() 이항 조건자 없을경우 ======================\n";

    Point A(5, 8);
    Point B(3, 9);
    Point p3;
    p3 = max(A, B, AreaCompare); //넓이 비교
    p3.Print();                  // p3에는 넓이가 더 큰 A가 들어갔을것.

    cout << "====================== min()의 경우 작은 원소를 뽑아낸다. ======================\n";

    cout << "====================== max_element()======================\n";
    vector<int>::iterator max_element_Iter;
    max_element_Iter = max_element(v.begin(), v.end());
    cout << *max_element_Iter << "\n"; // max_element()는 반복자로 비교하고 반복자를 반환한다.
    cout << "====================== min_element()도 동일하다 조건자가 less에서 greater로 바뀌었다고 생각하면 된다. ======================\n";

    cout << "====================== mismatch(). ======================\n";
    pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
    iter_pair = mismatch(v.begin(), v.end(), v2.begin());
    cout << "v1: " << *iter_pair.first << ", "
         << "v2: " << *iter_pair.second << endl;
    // pair객체를 이용해 서로의 반복자 위치로 원소 값을 비교하는데 다른 값이 나오면 해당 반복자 위치들을 반환 해준다.

    cout << "====================== search(). ======================\n";
    vector<int>::iterator search_iter;
    search_iter = search(v.begin(), v.end(), v2.begin(), v2.end());

    if (search_iter != v.end()) //모든 원소가 같고 개수도 같아야한다.
    {
        cout << "같은 순차열 존재, 같은 순차열을 발견한 즉시 순차열의 첫번째 원소의 반복자 위치 반환"
             << "\n";
    }
    else
    {
        cout << "같은 순차열 확인 불가, 첫번째 매개변수의 반복자 end()반환"
             << "\n";
    }

    vector<int>::iterator search_n_iter;
    search_n_iter = search_n(v.begin(), v.end(), 2, 30);
    if (search_n_iter != v.end())
    {
        cout << "30원소 두번 연속으로 존재"
             << "\n";
    }
    else
    {
        cout << "30원소 두번 연속으로 없음"
             << "\n";
    }

    return 0;
}