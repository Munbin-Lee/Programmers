#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

char last;
unordered_map<string, bool> isUsed;

bool isValidWord(const string &s) {
    if (last && s[0] != last) return false;
    if (isUsed[s]) return false;
    isUsed[s] = true;
    last = s[s.size() - 1];
    return true;
}

vector<int> solution(int n, vector<string> words) {
    int person = 1;
    int round = 1;
    for (const string &word : words) {
        if (!isValidWord(word)) return {person, round};
        person++;
        if (person > n) {
            person -= n;
            round++;
        }
    }
    return {0, 0};
}