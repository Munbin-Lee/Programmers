#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int r, c;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
unordered_map<int, bool> visited;
vector<int> answer;

int Hash(int y, int x, int dir) {
    return y+x*5000000+dir*100000000000000;
    // return y + c * (x + 4 * dir);
}

void simulate(int y, int x, int dir, vector<string> &grid) {
    unordered_map<int, bool> trails;
    
    while (!visited[Hash(y, x, dir)]) {
        visited[Hash(y, x, dir)] = true;
        trails[Hash(y, x, dir)] = true;
        dir -= (grid[y][x] == 'L');
        dir += (grid[y][x] == 'R');
        dir = (dir + 4) % 4;
        y = (y + dy[dir] + r) % r;
        x = (x + dx[dir] + c) % c;
    }
    
    if (trails.empty()) return;
    
    answer.emplace_back(trails.size());
}

vector<int> solution(vector<string> grid) {
    r = grid.size();
    c = grid[0].size();
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                simulate(i, j, k, grid);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}