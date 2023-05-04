#include <string>
#include <vector>
#include <array>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    array<int, 4> dy = {0, 1, 0, -1};
    array<int, 4> dx = {1, 0, -1, 0};
    int y = 0;
    int x = 0;
    int dir = 0;
    
    for (int i = 1; i <= n * n; i++) {
        answer[y][x] = i;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny == -1 || ny == n || nx == -1 || nx == n || answer[ny][nx]) {
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        y = ny;
        x = nx;
    }
    return answer;
}