#include <string>
#include <vector>

using namespace std;

bool isValid(long x, int n, vector<int> &times) {
    long cnt = 0;
    for (int time : times) {
        cnt += x / time;
    }
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    int minTime = 987654321;
    
    for (int time : times) {
        minTime = min(minTime, time);
    }
    
    long lo = 1;
    long hi = 1'000'000'000'000'000'000;
    long long res = -1;
    
    while (lo <= hi) {
        long md = (lo + hi) / 2;
        if (isValid(md, n, times)) {
            res = md;
            hi = md - 1;
        } else {
            lo = md + 1;
        }
    }
    return res;
}