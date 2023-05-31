#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0;
    int y = 0;
    for (auto &size : sizes) {
        x = max(x, min(size[0], size[1]));
        y = max(y, max(size[0], size[1]));
    }
    
    int answer = x * y;
    return answer;
}