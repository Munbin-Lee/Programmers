#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool available(string &skill, string &skill_tree) {
    unordered_map<char, bool> disabled;
    
    for (int i = 1; i < skill.size(); i++) {
        disabled[skill[i]] = true;
    }
    
    int cur = 0;
    
    for (char ch : skill_tree) {
        if (disabled[ch]) return false;
        if (ch == skill[cur]) {
            cur++;
            disabled[skill[cur]] = false;
        }
    }
    
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string &skill_tree : skill_trees) {
        answer += available(skill, skill_tree);
    }
    
    return answer;
}