#include <string>
#include <vector>

using namespace std;

bool isValid(long long x, int n, vector<int> &times) {
    long long cnt = 0;
    for (int time : times) {
        cnt += x / time;
    }
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    int minTime = INT32_MAX;
    for (int time : times) {
        minTime = min(minTime, time);
    }
    
    long long lo = 1;
    long long hi = 1LL * minTime * n;
    long long res = -1;
    
    while (lo <= hi) {
        long long md = (lo + hi) / 2;
        if (isValid(md, n, times)) {
            res = md;
            hi = md - 1;
        } else {
            lo = md + 1;
        }
    }
    return res;
}