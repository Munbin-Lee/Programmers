#include <string>
#include <vector>

using namespace std;

vector<int> cnt(2);

bool same(int sz, int r, int c, const vector<vector<int>> &arr) {
    int base = arr[r][c];
    for (int i = r; i < r + sz; i++) {
        for (int j = c; j < c + sz; j++) {
            if (arr[i][j] != base) return false;
        }
    }
    cnt[base]++;
    return true;
}

void dfs(int sz, int r, int c, const vector<vector<int>> &arr) {
    if (same(sz, r, c, arr)) return;
    sz /= 2;
    dfs(sz, r, c, arr);
    dfs(sz, r + sz, c, arr);
    dfs(sz, r, c + sz, arr);
    dfs(sz, r + sz, c + sz, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    dfs(arr.size(), 0, 0, arr);
    return cnt;
}