#include <iostream>
#include <list>

using namespace std;

int main() {
    cout << "[초기화] list<int> l = {1, 2, 3}\n: ";
    list<int> l = {1, 2, 3};
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[삽입] push_front(val) / insert(it, val)\n: ";
    l.push_front(4);
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 4);
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[삭제] remove(val) / erase(it)\n: ";
    l.remove(1);
    it = l.end();
    advance(it, -1);
    l.erase(it);
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[정렬 + 중복 제거] list.sort() / list.unique()\n: ";
    l.sort();
    l.unique();
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[리스트 병합] list.merge(list)\n: ";
    list<int> l1 = {1, 2, 3};
    l.merge(l1);
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[리스트 이동] list.splice(list)\n: ";
    list<int> l2 = {4, 5, 6};
    it = l.begin();
    l.splice(it, l2);
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;


    return 0;
}