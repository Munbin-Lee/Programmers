#include <string>
#include <vector>

using namespace std;

const int mod = 1234567;

vector<int> memo;

int fibo(int n) {
    if (memo[n] != -1) return memo[n];
    return memo[n] = (fibo(n - 1) + fibo(n - 2)) % mod;
}

int solution(int n) {
    memo.resize(n + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    int answer = fibo(n);
    return answer;
}