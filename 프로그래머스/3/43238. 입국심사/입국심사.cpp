#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long lo = 1;
    long hi = 1'000'000'000'000'000'000;
    
    auto isValid = [&](long x) {
        long cnt = 0;
        
        for (int time : times) {
            cnt += x / time;
        }
        
        return cnt >= n;
    };
    
    while (lo < hi) {
        long md = lo + (hi - lo) / 2;
        
        if (isValid(md)) hi = md;
        else lo = md + 1;
    }
    
    return lo;
}