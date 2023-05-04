#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(), array.end());
    int n = array.size();
    int answer = array[n / 2];
    return answer;
}