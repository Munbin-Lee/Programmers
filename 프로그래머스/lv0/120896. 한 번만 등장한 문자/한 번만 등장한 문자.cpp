#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    map<char, int> mp;
    for (char ch : s) {
        mp[ch]++;
    }
    
    string answer;
    for (auto [ch, cnt] : mp) {
        if (cnt == 1) answer += ch;
    }
    return answer;
}