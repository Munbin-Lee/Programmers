#include <string>
#include <vector>

using namespace std;

vector<int> memo = {-1, 1};

int factorial(int x) {
    if (memo[x]) return memo[x];
    return memo[x] = x * factorial(x - 1);
}

int binarySearch(int n) {
    int lo = 1;
    int hi = 10;
    int res;
    while (lo <= hi) {
        int md = (lo + hi) / 2;
        if (factorial(md) <= n) {
            res = md;
            lo = md + 1;
        } else {
            hi = md - 1;
        }
    }
    return res;
}

int solution(int n) {
    memo.resize(n + 1);
    int answer = binarySearch(n);
    return answer;
}