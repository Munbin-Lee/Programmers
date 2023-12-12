#include <functional>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    function<void(int, int)> dfs = [&](int cur, int plus) {
        if (pow(3, plus / 2) > cur) return;
        
        if (cur == 1) {
            answer += plus == 0;
            return;
        }
        
        if (cur % 3 == 0 && plus >= 2) {
            dfs(cur / 3, plus - 2);
        }
        dfs(cur - 1, plus + 1);
    };
    
    dfs(n - 2, 2);
    
    return answer;
}