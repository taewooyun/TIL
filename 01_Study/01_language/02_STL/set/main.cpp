#include <iostream>
#include <set>

using namespace std;

int main() {
    cout << "[초기화] set<int> s = {1, 2, 3}\n: ";
    set<int> s = {1, 2, 3};
    for(auto i: s) cout << i << " ";
    cout << endl << endl;
    
    cout << "[삽입] insert(t)\n: ";
    s.insert(3); // 중복X - 추가 안됨
    s.insert(4);
    for(auto i: s) cout << i << " ";
    cout << endl << endl;

    cout << "[삭제] erase(v) / clear()\n: ";
    s.erase(2); //
    // s.clear(); // 전체 삭제
    for(auto i: s) cout << i << " ";
    cout << endl << endl;

    cout << "[탐색] find(v) / count(v) / lower_bound(v) / upper_bound(v)\n:\n";
    s.find(3); // 값 존재시 반복자 반환(없으면 end())
    s.count(3); // 존재 여부 확인(0 또는 1 반환)
    auto it = s.lower_bound(3); // 해당 값 이상 첫 원소의 반복자 반환
    cout << "lower_bound(3) : " << *it << endl;
    it = s.upper_bound(3); // 해당 값 초과 첫 원소의 반복자 반환
    cout << "upper_bound(3) : " << *it;
    cout << endl << endl;


    return 0;
}