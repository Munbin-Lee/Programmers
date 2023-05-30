#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    unordered_map<int, bool> mpLost, mpReserve;
    
    mpLost.reserve(lost.size());
    for (int i : lost) {
        mpLost[i - 1] = true;
    }
    
    mpReserve.reserve(reserve.size());
    for (int i : reserve) {
        if (mpLost[i - 1]) {
            mpLost[i - 1] = false;
        } else {
            mpReserve[i - 1] = true;
        }
    }
    
    int di[] = {-1, 1};
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!mpLost[i]) {
            answer++;
            continue;
        }
        for (int d : di) {
            int ni = i + d;
            if (ni == -1 || ni == n || !mpReserve[ni]) continue;
            mpReserve[ni] = false;
            answer++;
            break;
        }
    }
    return answer;
}