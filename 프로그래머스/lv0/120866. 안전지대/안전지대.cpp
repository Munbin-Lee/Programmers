#include <string>
#include <vector>

using namespace std;

enum {
    SAFE = 0,
    MINE = 1,
    DANGER = 2
};

int dy[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};

int solution(vector<vector<int>> board) {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0 ; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] != MINE) continue;
            
            for (int d = 0; d < 8; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny == -1 || ny == r || nx == -1 || nx == c) continue;
                if (board[ny][nx] != SAFE) continue;
                board[ny][nx] = DANGER;
            }
        }
    }
    
    int answer = 0;
    for (auto &v : board) {
        for (auto i : v) {
            if (i == SAFE) answer++;
        }
    }
    return answer;
}