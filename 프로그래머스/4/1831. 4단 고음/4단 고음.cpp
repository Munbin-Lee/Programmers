#include <queue>
#include <cmath>

using namespace std;
using pr = pair<int, int>;

int solution(int n) {
    int answer = 0;
    
    queue<pr> q;
    q.emplace(n - 2, 2);
    
    while (!q.empty()) {
        auto [cur, plus] = q.front();
        q.pop();
        
        if (pow(3, plus / 2) > cur) continue;
        if (cur == 1) {
            answer += plus == 0;
            continue;
        }
        
        if (cur % 3 == 0 && plus >= 2) {
            q.emplace(cur / 3, plus - 2);
        }
        q.emplace(cur - 1, plus + 1);
    }
    
    return answer;
}