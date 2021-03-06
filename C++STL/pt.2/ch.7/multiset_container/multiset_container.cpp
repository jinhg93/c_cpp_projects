// 중복 원소를 컨테이너에 저장할 수 있는 set 컨테이너의 확장판

#include <iostream>
#include <set>

using namespace std;

void print(multiset<int> s){

    multiset<int>::iterator iter;

    for(iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

}

int main(){

    multiset<int> ms;
    multiset<int>::iterator iter;
    
    ms.insert(50);
    ms.insert(30);
    ms.insert(80);
    ms.insert(80); // 중복
    ms.insert(30); // 중복
    ms.insert(70);
    iter = ms.insert(10);

    // cout<< "iter의 원소 : "<< *iter << endl;

    print(ms);

    cout << "30 원소의 개수 : " << ms.count(30) << endl;

    iter = ms.find(30);
    cout << "iter: " << *iter <<endl; 

    //////////////////////////////////////////////////////
    multiset<int>::iterator lower_iter = ms.lower_bound(30);
    multiset<int>::iterator upper_iter = ms.upper_bound(30);

    cout << "lower_iter: " << *lower_iter << endl;
    cout << "upper_iter: " << *upper_iter << endl;

    cout << "구간 [lower_iter, upper_iter) 의 순차열: ";

    for(iter = lower_iter; iter != upper_iter ; iter++)
        cout << *iter << " ";
    cout << endl;
    
    ////////////////////////////////////////////////////////

    pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
    iter_pair = ms.equal_range(30);

    for(iter = iter_pair.first; iter != iter_pair.second ; iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}