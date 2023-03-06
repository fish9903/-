#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    int remain = a % b;
    
    while(remain > 0){
        a = b;
        b = remain;
        remain = a % b;
    }
    
    return b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA; // 철수 카드를 모두 나눌 수 있는 수
    int gcdB; // 영희 카드를 모두 나눌 수 있는 수
    int As = arrayA.size();
    int Bs = arrayB.size();
    if(As == 1 && Bs == 1){
        if(arrayA[0] != arrayB[0]) return max(arrayA[0], arrayB[0]);
        else return 0;
    }
    
    gcdA = gcd(arrayA[0], arrayA[1]);
    gcdB = gcd(arrayB[0], arrayB[1]);
    for(int i=2;i<As;i++){
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    if(gcdA == 1 && gcdB == 1) return 0;
    
    // '철수의 수'로 영희배열의 수들을 나눠보기
    for(int i=0;i<Bs;i++){
        if(arrayB[i] % gcdA == 0){ // 나눠진다면 gcdA는 실패
            gcdA = 0;
            break;
        }
    }   
    
    // '영희의 수'로 철수배열의 수들을 나눠보기
    for(int i=0;i<As;i++){
        if(arrayA[i] % gcdB == 0){ // 나눠진다면 gcdB는 실패
            gcdB = 0;
            break;
        }
    }   
    
    answer = max(gcdA, gcdB);
    
    return answer;
}