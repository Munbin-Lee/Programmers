#include <string>
#include <vector>

using namespace std;

int dfs(int idx, int cur, vector<int> &numbers, int target) {
    if (idx == numbers.size()) return (cur == target);
    
    return dfs(idx+1, cur+numbers[idx], numbers, target)
         + dfs(idx+1, cur-numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    return dfs(0, 0, numbers, target);
}