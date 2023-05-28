#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i : scoville) {
        pq.emplace(i);
    }
    
    int cnt = 0;
    while (true) {
        int a = pq.top(); pq.pop();
        if (a >= K) return cnt;
        if (pq.empty()) return -1;
        int b = pq.top(); pq.pop();
        pq.emplace(a + b * 2);
        cnt++;
    }
}