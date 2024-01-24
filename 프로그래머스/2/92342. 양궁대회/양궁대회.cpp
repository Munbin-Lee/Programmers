#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> arrows(11, 0);
    vector<int> answer {-1};
    int maxScore = 0;
    
    function<void(int, int)> dfs = [&](int index, int leftArrows) {
        if (index == 11) {
            if (leftArrows) return;
            
            int score = 0;
            
            for (int i = 0; i <= 10; i++) {
                if (arrows[i] == 0 && info[i] == 0) continue;
                score += (10 - i) * ((arrows[i] > info[i]) ? 1 : -1);
            }
            
            if (score <= 0) return;
            if (score < maxScore) return;
            
            if (score == maxScore) {
                for (int i = 10; i >= 0; i--) {
                    if (arrows[i] < answer[i]) return;
                    
                    if (arrows[i] > answer[i]) {
                        answer = arrows;
                        return;
                    }
                }
                
                return;
            }
            
            maxScore = score;
            answer = arrows;
            return;
        }
        
        for (int i = 0; i <= leftArrows; i++) {
            arrows[index] = i;
            dfs(index + 1, leftArrows - i);
            arrows[index] = 0;
        }
    };
    
    dfs(0, n);
    
    return answer;
}