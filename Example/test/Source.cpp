/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> map;
    // bfs
    bool check(int start, vector<bool>& visited) {
        if (map[start] == -1) {
            return true;
        }
        else if (visited[map[start]] == true) {
            // loop
            return false;
        }

        visited[start] = true; // true flag
        check(map[start], visited);

        // never reach here
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // check loop

        map.resize(numCourses, -1);

        for (int i = 0; i < prerequisites.size(); i++) {
            // make map
            map[prerequisites[i][0]] = prerequisites[i][1];
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            vector<bool> visited(numCourses, false);

            if (!check(prerequisites[i][0], visited)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> v = { {1, 0} };
    S.canFinish(2, v);

    return 0;
}
