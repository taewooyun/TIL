#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "[초기화] vector<int> v = {1, 2, 3}\n: ";
    vector<int> v = {1, 2, 3};
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[끝 인덱스 값 삽입] push_back(4)\nvalue: ";
    v.push_back(4);
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[끝 인덱스 값 삭제] pop_back()\nvalue: ";
    v.pop_back();
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "[첫 인덱스 값 반환] v.front()\nvalue: ";
    cout << v.front() << endl << endl;
    cout << "[끝 인덱스 값 반환] v.back()\nvalue: ";
    cout << v.back() << endl << endl;

    cout << "[반복자 사용]\nvalue: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "[초기화] vector<int> v(5, 100)\nvalue: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;

    vector<vector<int>> matrix(3, vector<int>(4, 0));
    cout << "[2차원 벡터 초기화]\nvalue:\n";
    for(auto row: matrix){
        for(auto column: row){
            cout << column << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    return 0;
}