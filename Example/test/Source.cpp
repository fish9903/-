#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

multiset<string> want_set;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int size = want.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < number[i]; j++) {
            want_set.insert(want[i]);
        }
    }

    size = discount.size();
    multiset<string> temp;
    for (int i = 0; i <= size - 10; i++) {
        for (int j = i; j < i + 10; j++) {
            temp.insert(discount[i]);
        }
        if (temp == want_set)
            answer++;
        temp.clear();
    }

    return answer;
}

int main() {
    vector<string> want = { "banana", "apple", "rice", "port", "pot" };
    vector<int> number = { 3, 2, 2, 2, 1 };
    vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
    solution(want, number, discount);

    multiset<int> c = { 1,1,2,3 };
    set<int> a = { 1,1,2,3 };
    set<int> b = { 3,2,1 };
    if (a == b) cout << "same" << endl;

    return 0;
}