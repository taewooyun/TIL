#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cout << "[초기화] map<string, int> m = {{\"apple\", 1}, {\"banana\", 2}}\n: ";
    map<string, int> m = {{"apple", 1}, {"banana", 2}};
    for(auto& it: m){
        cout << "{" << it.first << ":" << it.second << "}, ";
    }
    cout << endl << endl;

    cout << "[삽입] map[\"key\"] / map.insert({\"key\", value})\n: ";
    m["cherry"] = 3;
    m.insert({"durian", 4});
    for(auto& it: m){
        cout << "{" << it.first << ":" << it.second << "}, ";
    }
    cout << endl << endl;


    cout << "[삭제] map.erase(\"key\")\n: ";
    m.erase("banana");
    for(auto& it: m){
        cout << "{" << it.first << ":" << it.second << "}, ";
    }
    cout << endl << endl;

    cout << "[탐색] map.count(\"key\") / map.find(\"key\")\n:\n";
    for(auto& it: m){
        cout << "{" << it.first << ":" << it.second << "}, ";
    }
    if (m.count("apple")) cout << "apple 존재\n";
    auto it = m.find("banana");
    if (it == m.end()) cout << "not found : banana";
    else cout << "banana : " << it->second;
    cout << endl << endl;
    
    cout << "[빈도수 카운팅]\n: ";
    map<string, int> freq;
    for (string s : {"apple", "banana", "apple"}) {
        freq[s]++;
    }
    for(auto& it: m){
        cout << "{" << it.first << ":" << it.second << "}, ";
    }
    cout << endl << endl;

    cout << "[범위 기반 탐색]\n: ";
    map<int, string> range = {{10, "A"}, {20, "B"}, {30, "C"}, {40, "D"}};
    auto it1 = range.lower_bound(25);
    if (it1 != range.end()) cout << it1->first << " = " << it1->second;
    cout << endl << endl;

    cout << "[사용자 정의 정렬]\n: ";
    map<int, string, greater<int>> order = {
        {1, "one"}, {2, "two"}, {3, "three"}
    };
    for(auto& it: order){
        cout << "{" << it.first << ":" << it.second << "}, ";
    }
    cout << endl << endl;

    return 0;
}