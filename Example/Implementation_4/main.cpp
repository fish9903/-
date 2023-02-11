#include <iostream>
#include <vector>

using namespace std;

// 오른쪽으로 90도 회전
vector<vector<int>> RotateRight(vector<vector<int>> a) {
    int n = a.size(); // 열
    int m = a[0].size(); // 행
    vector<vector<int>> result(n, vector<int>(m)); // 결과 리스트
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = a[i][j];
        }
    }
    return result;
}

bool check(vector<vector<int>> large, vector<vector<int>> key) {
    for (int i = 0; i < large.size() - key.size() - 1; i++) {
        for (int j = 0; j < large.size() - key.size() - 1; j++) {
            large[i][j] += key[i][j];
        }
    }
}

int main() {
    vector<vector<int>> key{
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 1}
    };
    vector<vector<int>> lock{
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int s = lock.size();
    vector<vector<int>> Large(lock.size() + 2*key.size() - 2, vector<int>(lock.size() + 2 * key.size() - 2));
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            Large[i + s - 1][j + s - 1] = lock[i][j];
        }
    }
    
    for (int i = 0; i < 4; i++) { // roate 4 times
        
        key = RotateRight(key);
    }

	return 0;
}