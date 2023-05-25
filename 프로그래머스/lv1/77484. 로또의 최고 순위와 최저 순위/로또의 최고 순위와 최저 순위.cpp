#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    unordered_map<int, bool> isWinNum;
    for (int win_num : win_nums) {
        isWinNum[win_num] = true;
    }
    
    int correct = 0;
    int deleted = 0;
    for (int num : lottos) {
        if (num == 0) deleted++;
        else if (isWinNum[num]) correct++;
    }
    
    int maxRank = min(7 - (correct + deleted), 6);
    int minRank = min(7 - correct, 6);
    return {maxRank, minRank};
}