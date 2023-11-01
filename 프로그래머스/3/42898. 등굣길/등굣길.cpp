#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;
vector<vector<int>> memo;

int dp(int y, int x) {
    int &m = memo[y][x];
    if (m != -1) return m;
    int fromUp = y == 1 ? 0 : dp(y - 1, x);
    int fromLeft = x == 1 ? 0 : dp(y, x - 1);
    return m = (fromUp + fromLeft) % MOD;
}

int solution(int c, int r, vector<vector<int>> puddles) {
    memo.resize(r + 1, vector<int> (c + 1, -1));
    memo[1][1] = 1;
    
    for (auto &puddle : puddles) {
        int y = puddle[1];
        int x = puddle[0];
        memo[y][x] = 0;
    }
    
    int answer = dp(r, c);
    return answer;
}