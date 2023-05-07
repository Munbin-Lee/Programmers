#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<char, int> um;

const int INF = 87654321;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    um cnts;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cnts[ch] = INF;
    }
    
    for (const string &s : keymap) {
        for (int i = 0; i < s.size(); i++) {
            char key = s[i];
            cnts[key] = min(cnts[key], i + 1);
        }
    }
    
    vector<int> answer;
    for (const string &target : targets) {
        int cnt = 0;
        for (char key : target) {
            cnt += cnts[key];
        }
        if (cnt >= INF) cnt = -1;
        answer.emplace_back(cnt);
    }
    return answer;
}