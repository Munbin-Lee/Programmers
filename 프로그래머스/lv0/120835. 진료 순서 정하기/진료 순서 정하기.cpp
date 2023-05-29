#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    int n = emergency.size();
    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++) {
        v[i] = {emergency[i], i};
    }
    sort(v.begin(), v.end(), greater<>());
    
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        answer[v[i].second] = i + 1;
    }
    return answer;
}