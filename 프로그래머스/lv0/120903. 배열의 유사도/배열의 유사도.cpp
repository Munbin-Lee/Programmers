#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    unordered_map<string, bool> visited;
    for (string &s : s1) {
        visited[s] = true;
    }
    
    int answer = 0;
    for (string &s : s2) {
        if (visited[s]) answer++;
    }
    return answer;
}