#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hasCompleted;
    for (string &s : completion) {
        hasCompleted[s]++;
    }
    for (string &s : participant) {
        if (!hasCompleted[s]) return s;
        hasCompleted[s]--;
    }
    return {};
}