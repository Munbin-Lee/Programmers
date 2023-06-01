#include <string>
#include <vector>

using namespace std;

int permute(int energy, int visited, const vector<vector<int>> &dungeons) {
    int maxCnt = __builtin_popcount(visited);
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited & (1 << i)) continue;
        if (dungeons[i][0] > energy) continue;
        maxCnt = max(maxCnt,
            permute(energy - dungeons[i][1], visited | (1 << i), dungeons));
    }
    return maxCnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = permute(k, 0, dungeons);
    return answer;
}