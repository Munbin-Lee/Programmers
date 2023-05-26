#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    string x = to_string(a);
    string y = to_string(b);
    return (x + y) > (y + x);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    if (numbers[0] == 0 && numbers.back() == 0) return "0";
    
    string answer;
    for (int number : numbers) {
        answer += to_string(number);
    }
    return answer;
}