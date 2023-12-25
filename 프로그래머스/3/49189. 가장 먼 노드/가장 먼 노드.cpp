#include <string>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<int, int>;

constexpr int INF = 987654321;

int solution(int n, vector<vector<int>> edges) {
    vector<vector<int>> paths(n + 1);
    
    for (auto &edge : edges) {
        int a = edge[0];
        int b = edge[1];
        paths[a].emplace_back(b);
        paths[b].emplace_back(a);
    }
    
    vector<int> dists(n + 1, INF);
    dists[1] = 0;
    
    queue<pr> q;
    q.emplace(0, 1);
    
    int maxDist = -1;
    int answer = 0;
    
    while (!q.empty()) {
        auto [dist, cur] = q.front();
        q.pop();
        
        for (int next : paths[cur]) {
            int ndist = dist + 1;
            if (ndist >= dists[next]) continue;
            if (ndist > maxDist) {
                maxDist = ndist;
                answer = 1;
            } else if (ndist == maxDist) {
                answer++;
            }
            dists[next] = ndist;
            q.emplace(ndist, next);
        }
    }
    
    return answer;
}