#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> counts;
    
    for (int t : tangerine) {
        counts[t]++;
    }
    
    vector<int> sortedCounts;
    
    for (auto [index, count] : counts) {
        sortedCounts.emplace_back(count);
    }
    
    sort(sortedCounts.rbegin(), sortedCounts.rend());
    
    int answer = 0;
    
    for (int count : sortedCounts) {
        k -= count;
        answer += 1;
        
        if (k <= 0) break;
    }
    
    return answer;
}