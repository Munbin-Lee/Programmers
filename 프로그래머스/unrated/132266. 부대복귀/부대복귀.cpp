#include <string>
#include <vector>
#include <array>
#include <queue>

using namespace std;

const int MAX_N = 100001;

array<int, MAX_N> costs;
array<vector<int>, MAX_N> paths;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    for (auto& road : roads) {
        int a = road[0];
        int b = road[1];
        paths[a].emplace_back(b);
        paths[b].emplace_back(a);
    }
    
    costs.fill(-1);
    costs[destination] = 0;
    queue<pair<int, int>> q;
    q.emplace(destination, 0);
    
    while (!q.empty()) {
        auto [source, cost] = q.front();
        q.pop();
        for (int path : paths[source]) {
            if (costs[path] != -1) continue;
            costs[path] = cost + 1;
            q.emplace(path, cost + 1);
        }
    }
    
    vector<int> answer;
    answer.reserve(sources.size());
    
    for (int source : sources) {
        answer.emplace_back(costs[source]);
    }
    
    return answer;
}