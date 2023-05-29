#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    int k = my_str.size();
    vector<string> answer;
    for (int lo = 0; lo < k; lo += n) {
        int hi = min(k, lo + n);
        string str(&my_str[lo], &my_str[hi]);
        answer.emplace_back(str);
    }
    return answer;
}