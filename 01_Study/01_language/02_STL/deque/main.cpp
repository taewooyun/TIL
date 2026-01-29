#include <iostream>
#include <deque>

using namespace std;

int main() {
    cout << "[초기화] deque<int> dq";
    deque<int> dq;
    cout << endl;
    cout << endl;

    cout << "[삽입] dq.push_back() / dq.push_front()\n: ";
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    for (auto i : dq) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "[삽입] dq.pop_back() / dq.pop_front()\n: ";
    dq.pop_back();
    dq.pop_front();
    for (auto i : dq) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}