#include <string>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<int, int>;

int solution(int n, vector<vector<int>> edges) {
    vector<vector<int>> paths(n + 1);
    
    for (auto &edge : edges) {
        int a = edge[0];
        int b = edge[1];
        paths[a].emplace_back(b);
        paths[b].emplace_back(a);
    }
    
    vector<bool> visited(n + 1);
    visited[1] = true;
    
    queue<pr> q;
    q.emplace(0, 1);
    
    int maxDist = -1;
    int answer = 0;
    
    while (!q.empty()) {
        auto [dist, cur] = q.front();
        q.pop();
        
        if (dist > maxDist) {
            maxDist = dist;
            answer = 1;
        } else if (dist == maxDist) {
            answer++;
        }
        
        for (int next : paths[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.emplace(dist + 1, next);
        }
    }
    
    return answer;
}