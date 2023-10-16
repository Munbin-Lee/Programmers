#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

long dfs(int idx, long visited, const vector<int> &cards) {
    if (visited & (1 << idx)) return visited;
    visited |= (1 << idx);
    int next = cards[idx] - 1;
    return dfs(next, visited, cards);
}

int solution(vector<int> cards) {
    size_t n = cards.size();
    int answer = 0;
    for (int i = 0; i < n; i++) {
        long visited = dfs(i, 0, cards);
        int a = __builtin_popcount(visited);
        for (int j = 0; j < n; j++) {
            long visited2 = dfs(j, visited, cards);
            int b = __builtin_popcount(visited2) - a;
            answer = max(answer, a * b);
        }
    }
    return answer;
}