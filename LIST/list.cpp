#include <iostream>
#include <list>

using namespace std;

void Remove()
{
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    lt.remove(10); // 10의 원소들을 모두 삭제한다.

    for (list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter)
    {
        cout << *iter << " ";
    }

    // remove()의 경우 erase()와 같이 해당 값의 노드만을 제거하므로 속도가 빠르다. 유일하게 list만이 지원하는 메서드
    //반복자가 아닌 원소의 값으로 컨테이너의 원소를 제거 한다면 list 컨테이너 선택이 좋음
    cout << "\n";
}

bool Predicate(int n)
{
    return 10 <= n && n <= 30; // 10~30까지의 원소만이 true로 삭제된다. 즉 10~30인 원소는 리스트에서 삭제된다.
}

void RemoveIf()
{
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);
    lt.push_back(10);

    list<int>::iterator iter;

    for (list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << "\n";

    bool (*pre)(int);
    pre = Predicate;

    lt.remove_if(pre); //함수 포인터 사용 가능
    //함수자체로도 가능 lt.remove_if(Predicate)

    for (list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << "\n";
}

void Splice()
{
    list<int> lt1;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    list<int> lt2;

    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);

    list<int>::iterator iter = lt1.begin();
    iter++;
    iter++; // 30의 원소를 가르킨다.

    // splice 접착
    lt1.splice(iter, lt2); //반복자 위치의 뒤 노드부터 붙여주고 반복자위치 에서 붙여주는것이 끝난다.

    // 10 20 100 200 300 400 500 30 40 50이 될 것.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";
}

void SpliceVer2()
{
    list<int> lt1;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    list<int> lt2;

    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);

    list<int>::iterator iter = lt1.begin();
    iter++;
    iter++; // 30의 원소를 가르킨다.

    list<int>::iterator iter2 = lt2.begin();
    iter2++;
    // iter2 200을 가르킨다.

    // splice 접착
    lt1.splice(iter, lt2, iter2);
    // lt2에서 iter2가 가르키는 원소를 iter 위치에 하나 넣어준다.

    // 10 20 100 200 300 400 500 30 40 50이 될 것.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";
}

void SpliceVer3()
{
    list<int> lt1;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    list<int> lt2;

    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);

    list<int>::iterator iter = lt1.begin();
    iter++;
    iter++; // 30의 원소를 가르킨다.

    list<int>::iterator iter2 = lt2.begin();
    iter2++;
    // iter2 200을 가르킨다.

    // splice 접착
    lt1.splice(lt1.end(), lt2, lt2.begin(), lt2.end());
    // lt1의 end 반복자에서 lt2의 [begin, end)까지의 범위를 붙여준다.

    // 10 20 100 200 300 400 500 30 40 50이 될 것.
    for (iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";
}

void Reverse()
{
    list<int> lt1;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    lt1.reverse(); //이중 연결 리스트의 탐색경로를 서로 바꿈으로써 순차열을 리버스 시킨다.

    for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";
}

bool UniquePredict(int first, int second)
{
    return second - first <= 0; // 0보다 작거나 0이라면 true를 반환해 삭제
}

void Unique()
{
    list<int> lt1;

    lt1.push_back(10);
    lt1.push_back(10);

    lt1.push_back(20);
    lt1.push_back(20);

    lt1.push_back(30);
    lt1.push_back(30);

    lt1.push_back(40);
    lt1.push_back(40);

    lt1.push_back(50);
    lt1.push_back(50);
    lt1.push_back(10);

    for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";

    lt1.unique(); //인접한 원소를 유일하게 만든다.

    for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    //조건자가 없는 unique의 경우 같은 원소값이 인접하지 않을 경우 중복 될 수도 있다.
    //일반 unique()로 중복되는 원소값을 없애고 싶다면 sort()후 실행하면 가능하다.
    cout << "\n";
    cout << "========== 조건자 실행 =============== \n";
    lt1.unique(UniquePredict); // 조건자 실행

    for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    } // 10 제거
}

void Merge()
{
    list<int> lt1;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    list<int> lt2;

    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);

    lt1.merge(lt2); //기본적으로 정렬이 되있고, 내림차순 less 조건자를 쓰므로 오류없이 실행된다.

    for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";

    list<int> lt3;

    lt3.push_back(650);
    lt3.push_back(450);
    lt3.push_back(250);
    lt3.push_back(150);
    lt3.push_back(50);

    list<int> lt4;

    lt4.push_back(500);
    lt4.push_back(400);
    lt4.push_back(300);
    lt4.push_back(200);
    lt4.push_back(100);

    lt3.merge(lt4,greater<int>()); // <= 연산자로 오름 차순 정렬 merge로 바꿔줘 오류 없이 합병되도록 바꿔준다.

    cout << "=========== 오름 차순 Merge ==================\n";

    for (list<int>::iterator iter = lt3.begin(); iter != lt3.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";
}

int main(void)
{
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    list<int>::iterator iter = lt.begin();
    list<int>::iterator iter2;
    ++iter; // LIST의 경우 양방향 반복자 제공으로 ++ --를 지원
    ++iter;

    iter2 = lt.erase(iter); // 30 지움

    for (iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << " ";
    cout << "\n";

    cout << "iter2 : " << *iter2 << "\n";

    iter = iter2;
    iter2 = lt.insert(iter, 300); // iter2(40)이 가리키는 위치에 300을 삽입

    for (iter = lt.begin(); iter != lt.end(); ++iter)
    {
        cout << *iter << ' ';
    }
    cout << "\n";

    cout << "========== REMOVE =================\n";
    Remove();

    cout << "========== REMOVEIF =================\n";
    RemoveIf();

    cout << "========== SPLICE =================\n";
    Splice();

    cout << "========== SPLICE_Ver 2 =================\n";
    SpliceVer2();

    cout << "========== SPLICE_Ver 3 =================\n";
    SpliceVer3();

    cout << "========== Reverse =================\n";
    Reverse();

    cout << "========== Unique =================\n";
    Unique();

    cout << "LIST의 경우 자체 sort함수를 제공한다. lt.sort() 이렇게 실행하면 오름차순 정렬(< 연산)\n";
    cout << "내림차순 정렬을 원한다면, 조건자 사용 lt.sort(greater<int>()); \n";

    cout << "========== Merge =================\n";
    Merge();
    cout << "Merge의 경우, 오름차순 혹은 내림차순 혹은 사용자 정의 조건자에 부합하는 정렬이 되있어야지 오류 없이 list의 merge()함수가 실행된다. \n";
    return 0;

    //LIST 총평.
    //LIST는 vector, deque와 같은 시퀀스 컨테이너이지만 노드 기반 컨테이너이기도 하다.
    //그래서, 순차열 중간 삽입, 제거 등이 빈번하게 일어나는 작업에 용이한 컨테이너이다.
    //노드 기반 컨테이너므로 [], at()등은 지원하지 않지만 insert(), erase()등은 더 효율적이게 동작한다.
    //또한 list간의 병합, 결합등에 좋은 컨테이너이다. splice(), merge(), 자체 정렬 sort()등을 이용하여 
    //중간 삭제 및 중간 추가등에 효율적인 컨테이너로써 사용된다.
    
}