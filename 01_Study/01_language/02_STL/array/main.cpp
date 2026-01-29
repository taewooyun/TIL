#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    cout << "[초기화] array<int, 5> arr = {1, 2, 3, 4, 5}\n: ";
    array<int, 5> arr = {3, 4, 2, 1, 5};
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl << endl;

    cout << "[반환] at(index) / front() / back()\n:\n";
    cout << "첫번째 원소: " << arr.front() << endl;
    cout << "마지막 원소: " << arr.back() << endl;
    cout << "세번째 원소: " << arr.at(2) << endl;

    cout << endl;

    cout << "[정렬] <algorithm> sort(it, it)\n: ";
    sort(arr.begin(), arr.end());
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl << endl;


    return 0;
}