#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    using pr = pair<int, int>;
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    vector<int> answer(n, -1);
    
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first < numbers[i]) {
            auto [_, j] = pq.top();
            pq.pop();
            answer[j] = numbers[i];
        }
        
        pq.emplace(numbers[i], i);
    }
    
    return answer;
}