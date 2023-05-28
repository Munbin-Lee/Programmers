#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    int day = 0;
    int cnt = 0;
    vector<int> answer;
    answer.reserve(n);
    
    for (int i = 0; i < n; i++) {
        int progress = progresses[i] + speeds[i] * day;
        if (progress < 100) {
            day += ceil(1.0 * (100 - progress) / speeds[i]);
            if (cnt) answer.emplace_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    answer.emplace_back(cnt);
    return answer;
}