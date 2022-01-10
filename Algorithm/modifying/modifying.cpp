#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Integer
{
    int data;

public:
    explicit Integer(int d = 0) : data(d) {}
    int operator()()
    {
        return data++;
    }
};

class Accumulation
{
    int total;

public:
    explicit Accumulation(int init = 0) : total(init) {}
    void operator()(int &r)
    {
        total += r;
        r = total;
    }
};

void Func(int &r)
{
    r += 5;
}

bool Pred(int n)
{
    return 1 <= n && n<= 5;
}

int main(void)
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2(5); // size 5 벡터 생성
    vector<int>::iterator iter;
    iter = copy(v1.begin(), v1.end(), v2.begin()); // end()위치를 반환해준다.

    cout << "================== copy ================== \n";

    for (vector<int>::iterator iters = v2.begin(); iters != iter; ++iters) // copy의 경우 덮어쓰기가 기본이므로 덮어쓰는 순차열이 길이가 더 길거나 같아야 된다.
    {
        cout << *iters << " ";
    }
    cout << "\n";

    cout << "================== copy_backward ================== \n";

    vector<int> v3(10);                                   // size 10 벡터 생성
    iter = copy_backward(v1.begin(), v1.end(), v3.end()); // 해당 순차열을 끝에서 부터 넣어준다.

    for (vector<int>::size_type i = 0; i < v3.size(); ++i) // copy의 경우 덮어쓰기가 기본이므로 덮어쓰는 순차열이 길이가 더 길거나 같아야 된다.
    {
        cout << v3[i] << " ";
    }
    cout << "\n";

    cout << "================== fill ================== \n";

    fill(v1.begin(), v1.end(), 0); // v1.begin ~ v1.end() - 1 반복자 위치까지 0으로 채워준다.
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    cout << "================== fill_n ================== \n";

    fill_n(v1.end() - 3, 3, 5); //시작 위치 , 반복 할 횟수, 넣을 원소
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    //초기화
    fill(v1.begin(), v1.end(), 0);

    cout << "================== for_each ================== \n";

    cout << " v : ";
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    //함수류를 사용해 각 원소들의 주소들로 원하는 계산을 진행 할 수 있다.
    for_each(v1.begin(), v1.end(), Func);
    cout << " v : ";
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    cout << "================== for_each 함수자 ================== \n";

    for_each(v1.begin(), v1.end(), Accumulation(0));
    cout << " v : ";
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    cout << "================== generate 함수자 ================== \n";
    // generate 함수자는 함수자의 매개변수로 순차열의원소를 전달받지 않기 때문에 원소가 가지고 있는 원 값 활용 X
    //단순히 원하는 일정한 값으로 만 채움.

    generate(v1.begin(), v1.end(), Integer(1));
    cout << " v : ";
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    cout << "================== swap ================== \n";

    int a = 10, b = 20;
    cout << a << b << endl;
    swap(a, b);
    cout << a << b << endl;

    cout << "================== iter_swap ================== \n";
    iter_swap(v1.begin(), v2.begin() + 1); //다른 벡터 컨테이너의 반복자 위치로도 교환 가능
    cout << " v : ";
    for (vector<int>::size_type i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";

    cout << "================== merge ================== \n";

    generate(v1.begin(), v1.end(), Integer(1));
    generate(v2.begin(), v2.end(), Integer(10));

    // merge는 오름차순 혹 내림차순으로 정렬된 순차열에서만 적용된다.

    vector<int> v4(20); // size 10
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    cout << " v4 : ";
    for (vector<int>::size_type i = 0; i < v4.size(); ++i)
    {
        cout << v4[i] << " ";
    }
    cout << "\n";

    cout << "================== replace ================== \n";
    replace(v4.begin(), v4.end(), 1, 9999); // begin ~ end - 1까지 1의 원소를 모두 9999로 변환
    cout << " v4 : ";
    for (vector<int>::size_type i = 0; i < v4.size(); ++i)
    {
        cout << v4[i] << " ";
    }
    cout << "\n";

    cout << "================== replace_if 단항 조건자 ================== \n";
    replace_if(v4.begin(),v4.end(),Pred,7777); // 1~5까지 원소를 7777로 변환
    cout << " v4 : ";
    for (vector<int>::size_type i = 0; i < v4.size(); ++i)
    {
        cout << v4[i] << " ";
    }
    cout << "\n";

    return 0;
}