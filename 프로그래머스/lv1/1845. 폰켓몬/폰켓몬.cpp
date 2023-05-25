#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    unordered_map<int, bool> visited;
    int answer = 0;
    for (int num : nums) {
        if (visited[num]) continue;
        visited[num] = true;
        answer++;
    }
    answer = min(answer, n / 2);
    return answer;
}