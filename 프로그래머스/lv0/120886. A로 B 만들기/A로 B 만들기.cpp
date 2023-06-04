#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string before, string after) {
    unordered_map<char, int> mp;
    for (char ch : before) {
        mp[ch]++;
    }
    
    for (char ch : after) {
        mp[ch]--;
    }
    
    for (auto [key, cnt] : mp) {
        if (cnt) return 0;
    }
    return 1;
}