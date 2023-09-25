#include <string>
#include <vector>
#include <set>

using namespace std;

set<char> s_list;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0;i<skill.length();i++){
        s_list.insert(skill[i]);
    }
    
    for(int i=0;i<skill_trees.size();i++){
        vector<int> learned(skill.length(), 0); // 0: 아직 배우지 않음
        string target = skill_trees[i];
        int temp_index = 0;
        bool flag = true;
        
        for(int j=0;j<target.length();j++){
            if(s_list.count(target[j]) != 0){
                if(learned[temp_index] == 0){
                    if(skill[temp_index] == target[j]){
                        learned[temp_index] = 1;
                        temp_index++;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if(flag)
            answer++;
    }
    
    return answer;
}