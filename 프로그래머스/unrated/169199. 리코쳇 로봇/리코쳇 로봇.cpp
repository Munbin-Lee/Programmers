#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int r, c;
int sy, sx;
vector<vector<int>> visited;

bool slide(int& y, int& x, int dir, vector<string>& board) {
    int ty = y;
    int tx = x;
    
    while (true) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny == -1 || ny == r || nx == -1 || nx == c) break;
        if (board[ny][nx] == 'D') break;
        y = ny;
        x = nx;
    }
    
    return !(y == ty && x == tx);
}

int bfs(vector<string>& board) {
    queue<tuple<int, int, int>> q; // y, x, 이동횟수
    q.emplace(sy, sx, 0);
    
    while (!q.empty()) {
        auto [cy, cx, cnt] = q.front();
        q.pop();
        if (board[cy][cx] == 'G') return cnt;
        
        for (int i = 0; i < 4; i++) {
            int ny = cy;
            int nx = cx;
            if (!slide(ny, nx, i, board)) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.emplace(ny, nx, cnt + 1);
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    r = board.size();
    c = board[0].size();
    visited.resize(r, vector<int>(c));
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] != 'R') continue;
            sy = i;
            sx = j;
            visited[sy][sx] = true;
        }
    }
    
    return bfs(board);
}