#include <string>
#include <vector>

using namespace std;

vector<int> memo;

int dp(int x) {
    int &m = memo[x];
    if (m) return m;
    m = min(dp(x - 1) + 1, dp(x - 3) + 1);
    m = min(m, dp(x - 5) + 1);
    return m;
}

int solution(int hp) {
    if (hp == 0) return 0;
    
    memo = {0, 1, 2, 1, 2, 1};
    memo.resize(hp + 1);
    return dp(hp);
}