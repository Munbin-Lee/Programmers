#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;
    for (auto &v : clothes) {
        mp[v[1]]++;
    }
    
    int answer = 1;
    for (auto [k, v] : mp) {
        answer *= v + 1;
    }
    return answer - 1;
}