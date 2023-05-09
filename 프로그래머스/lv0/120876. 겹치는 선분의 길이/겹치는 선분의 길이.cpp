#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<int>> lines) {
    unordered_map<int, int> isFilled;
    int answer = 0;
    for (auto &line : lines) {
        int lo = line[0];
        int hi = line[1];
        for (int i = lo; i < hi; i++) {
            int &fill = isFilled[i];
            if (fill == 0) {
                fill = 1;
            }
            else if (fill == 1) {
                fill = 2;
                answer++;
            }
        }
    }
    return answer;
}