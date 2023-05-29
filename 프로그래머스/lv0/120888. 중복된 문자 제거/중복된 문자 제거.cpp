#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string my_string) {
    unordered_map<char, bool> visited;
    string answer;
    
    for (char ch : my_string) {
        if (visited[ch]) continue;
        visited[ch] = true;
        answer += ch;
    }
    return answer;
}