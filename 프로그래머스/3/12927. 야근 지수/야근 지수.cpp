#include <string>
#include <vector>
#include <queue>
using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++) pq.push(works[i]);
    while (n != 0) {
        n--;
        int top = pq.top(); pq.pop();
        if (top == 0) return 0;
        pq.push(--top);

    }
    while (!pq.empty()) {
        int top = pq.top(); pq.pop();
        answer += (top * top);
    }
    return answer;
}