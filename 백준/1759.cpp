#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alphabet;
vector<char> result;

bool check(){
    int a = 0, b = 0;
    for(int i=0;i<L;i++){
        if(result[i] == 'a' ||
            result[i] == 'e' || 
            result[i] == 'i' ||
            result[i] == 'o' ||
            result[i] == 'u'){
                a++;
            }
        else{
            b++;
        }
    }

    if(a >= 1 && b >= 2) return true;
    else return false;
}

void dfs(int depth){
    if(result.size() == L){
        if(check()){
            for(int i=0;i<L;i++){
                cout << result[i];
            }
            cout << endl;
        }

        return;
    }

    for(int i=depth;i<C;i++){
        result.push_back(alphabet[i]);
        dfs(i + 1);
        result.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> C;
    for(int i=0;i<C;i++){
        char x;
        cin >> x;
        alphabet.push_back(x);
    }

    sort(alphabet.begin(), alphabet.end());

    // dfs
    dfs(0);

    return 0;
}