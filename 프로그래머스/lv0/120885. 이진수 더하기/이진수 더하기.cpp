#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    int n1 = bin1.size();
    int n2 = bin2.size();
    int n = max(n1, n2);
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    string answer;
    
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int a = i < n1 ? bin1[i] - '0' : 0;
        int b = i < n2 ? bin2[i] - '0' : 0;
        int sum = a + b + carry;
        carry = sum / 2;
        sum %= 2;
        answer += sum + '0';
    }
    if (carry) answer += '1';
    
    reverse(answer.begin(), answer.end());
    return answer;
}