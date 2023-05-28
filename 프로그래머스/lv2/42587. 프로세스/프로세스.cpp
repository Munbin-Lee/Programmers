#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int n = priorities.size();
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++) {
        q.emplace(priorities[i], i);
        pq.emplace(priorities[i]);
    }
    
    int order = 1;
    while (true) {
        auto [cur, idx] = q.front();
        int mx = pq.top();
        if (cur != mx) {
            q.emplace(q.front());
            q.pop();
        } else {
            if (idx == location) return order;
            order++;
            q.pop();
            pq.pop();
        }
    }
}