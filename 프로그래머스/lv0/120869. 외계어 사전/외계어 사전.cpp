#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> mp;

bool permute(string cur, int visited, vector<string> &spell) {
    if (__builtin_popcount(visited) == spell.size()) {
        return (mp[cur]);
    }
    
    for (int i = 0; i < spell.size(); i++) {
        if (visited & (1 << i)) continue;
        if (permute(cur + spell[i], visited | (1 << i), spell)) return true;
    }
    return false;
}

int solution(vector<string> spell, vector<string> dic) {
    for (string &s : dic) {
        mp[s] = true;
    }
    
    int answer = permute({}, 0, spell) ? 1 : 2;
    return answer;
}