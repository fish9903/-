#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

bool isPrime(int a){
    if(a == 1 || a == 0) return false;
    
    for(int i=2;i<=sqrt(a);i++){
        if(a % i == 0) return false;
    }
    return true;
}

set<int> set1;

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    // combination    
    do{
        for(int i=1;i<=numbers.length();i++) {
            string temp = numbers.substr(0, i);
            if(isPrime(stoi(temp))) {
                set1.insert(stoi(temp));
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    return set1.size();
}