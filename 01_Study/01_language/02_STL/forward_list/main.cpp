#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    cout << "[초기화] forward_list<int> fl = {1, 2, 3, 4}\n: ";
    forward_list<int> fl = {1, 2, 3, 4};
    for(auto it : fl){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[삽입] push_front(val) / insert_after(it, val) / \n: ";
    fl.push_front(4);
    auto it = fl.before_begin();
    advance(it, 2);
    fl.insert_after(it, 4);
    for(auto it : fl){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[삭제] pop_front() / remove(val) / erase_after(it)\n: ";
    fl.pop_front();
    fl.remove(1);
    it = fl.begin();
    advance(it, 1);
    fl.erase_after(it);
    for(auto it : fl){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[정렬 + 중복 제거] sort() / unique()\n: ";
    fl.sort();
    fl.unique();
    for(auto it : fl){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[리스트 병합] merge(forward_list)\n: ";
    forward_list<int> fl1 = {1, 2, 3};
    fl.merge(fl1);
    for(auto it : fl){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[리스트 이동] splice_after(forward_list)\n: ";
    forward_list<int> fl2 = {4, 5, 6};
    it = fl.begin();
    fl.splice_after(it, fl2);
    for(auto it : fl){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}