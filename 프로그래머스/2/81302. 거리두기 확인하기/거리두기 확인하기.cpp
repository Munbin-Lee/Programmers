#include <iostream>
#include <vector>

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool safe_dfs(int y, int x, int dist, const int sy, const int sx,
              const vector<string> &place) {
    if (dist == 3) return true;
    if (dist && place[y][x] == 'P') return false;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny == -1 || ny == 5 || nx == -1 || nx == 5) continue;
        if (ny == sy && nx == sx) continue;
        if (place[ny][nx] == 'X') continue;
        if (!safe_dfs(ny, nx, dist + 1, sy, sx, place)) return false;
    }
    
    return true;
}

int safe(const vector<string> &place) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] != 'P') continue;
            if (!safe_dfs(i, j, 0, i, j, place)) return 0;
        }
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer.reserve(places.size());
    
    for (auto &place : places) {
        answer.emplace_back(safe(place));
    }
    
    return answer;
}