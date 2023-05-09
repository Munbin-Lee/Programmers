#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    int n = score.size();
    for (int i = 0; i < n; i++) {
        score[i][0] += score[i][1];
        score[i][1] = i;
    }
    sort(score.begin(), score.end(), greater<>());
    
    int rank = 1;
    int prevSum = -1;
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        int sum = score[i][0];
        if (prevSum != sum) rank = i + 1;
        prevSum = sum;
        answer[score[i][1]] = rank;
    }
    return answer;
}