#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using tp = tuple<int, int, int>; // cnt, pos, targets

int solution(string name) {
    size_t n = name.size();
    
    int cnt = 0;
    int targets = 0;
    
    for (int i = 0; i < n; i++) {
        char ch = name[i];
        
        int up = ch - 'A';
        int down = 'Z' + 1 - ch;
        int dist = min(up, down);
        
        if (!dist) continue;
        
        cnt += dist;
        targets |= (1 << i);
    }
    
    queue<tp> q;
    q.emplace(0, 0, targets);
    
    while (!q.empty()) {
        auto [_cnt, pos, _targets] = q.front();
        q.pop();
        
        _targets -= (_targets & (1 << pos));
        if (!_targets) return cnt + _cnt;
        
        int left = pos - 1;
        if (left == -1) left = n - 1;
        q.emplace(_cnt + 1, left, _targets);
        
        int right = pos + 1;
        if (right == n) right = 0;
        q.emplace(_cnt + 1, right, _targets);
    }
    
    return -1;
}