#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int noOvertime(int no, vector<int> works)
{
    int answer = 0;

    while (no != 0)
    {
        *max_element(works.begin(), works.end()) -= 1;
        no -= 1;

    }
    for (int i = 0; i < works.size(); i++)
    {
        answer += works[i] * works[i];
    }

    return answer;
}

int main()
{
    vector<int> works{ 4,3,3 };
    int testNo = 4;

    int testAnswer = noOvertime(testNo, works);

    cout << testAnswer;
}