#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int odd = 0;
    for (int num : num_list) {
        if (num & 1) odd++;
    }
    int even = num_list.size() - odd;
    vector<int> answer = {even, odd};
    return answer;
}