#include <string>
#include <vector>

using namespace std;

const int MAX_NUM = 3000;
int res;
vector<bool> isPrime(MAX_NUM + 1, true);

void eratos() {
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX_NUM; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX_NUM; j += i) {
            isPrime[j] = false;
        }
    }
}

void solve(int cur, int idx, int cnt, vector<int> &nums) {
    if (cnt == 3) {
        if (isPrime[cur]) res++;
        return;
    }
    if (idx == nums.size()) return;
    solve(cur, idx + 1, cnt, nums);
    solve(cur + nums[idx], idx + 1, cnt + 1, nums);
}

int solution(vector<int> nums) {
    eratos();
    solve(0, 0, 0, nums);
    return res;
}