#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int s = wallpaper.size();
    int ss = wallpaper[0].length();
    
    int left;
    int right;
    int up;
    int down;
    int first = 1;
    for(int i=0;i<s;i++){
        for(int j=0;j<ss;j++){
            if(wallpaper[i][j] == '#'){
                if(first){
                    left = j;
                    right = j;
                    up = i;
                    down = i;
                    first = 0;    
                }
                else{
                    if(j < left) left = j;
                    else if(j > right) right = j;
                    if(i < up) up = i;
                    else if(i > down) down = i;
                }
            }
        }
    }
    
    answer.push_back(up);
    answer.push_back(left);
    
    answer.push_back(down+1);
    answer.push_back(right+1);
    
    return answer;
}