#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    int n = strlist.size();
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        answer[i] = strlist[i].size();
    }
    return answer;
}