#include <string>
#include <set>
#include <map>
#include <vector>

#define pii pair<int, int>

using namespace std;

set<vector<int>> visited;
map<char, int> m_dx, m_dy;

int solution(string dirs) {
    int answer = 0;

    pii start_pos = {0, 0};

    m_dx['U'] = -1;
    m_dx['D'] = 1;
    m_dy['R'] = 1;
    m_dy['L'] = -1;

    pii cur_pos = start_pos;
    pii temp_pos;
    for(int i=0;i<dirs.length();i++){
        temp_pos.first = cur_pos.first + m_dx[dirs[i]];
        temp_pos.second = cur_pos.second + m_dy[dirs[i]];

        if(temp_pos.first>=-5 && temp_pos.first<=5 && temp_pos.second>=-5 && temp_pos.second<=5){
            if(visited.count({cur_pos.first, cur_pos.second, temp_pos.first, temp_pos.second}) == 0 &&
              visited.count({temp_pos.first, temp_pos.second, cur_pos.first, cur_pos.second}) == 0){
                answer++;
                visited.insert({cur_pos.first, cur_pos.second, temp_pos.first, temp_pos.second});
            }
            cur_pos = temp_pos;
        }


    }

    return answer;
}