#include <string>
#include <vector>
#include <array>

using namespace std;

array<string, 4> words = {"aya", "ye", "woo", "ma"};

bool isPrefix(const string &s, const string &pref, int idx) {
    if (s.size() < pref.size()) return false;
    
    for (int i = 0; i < pref.size(); i++) {
        if (s[idx + i] != pref[i]) return false;
    }
    return true;
}

bool canPronounce(const string &s, int idx) {
    if (idx == s.size()) return true;
    
    for (const string &word : words) {
        if (isPrefix(s, word, idx)) return canPronounce(s, idx + word.size());
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (const string &s : babbling) {
        if (canPronounce(s, 0)) answer++;
    }
    return answer;
}