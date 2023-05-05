#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countOne(const string &s) {
    int cnt = 0;
    for (char ch : s) {
        if (ch == '1') cnt++;
    }
    return cnt;
}

string toBinary(int num) {
    string bin;
    while (num) {
        bin += (num % 2) + '0';
        num /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

vector<int> solution(string s) {
    int numTranspose = 0;
    int numRemovedZero = 0;
    while (s.size() != 1) {
        int one = countOne(s);
        int zero = s.size() - one;
        numRemovedZero += zero;
        s = toBinary(one);
        numTranspose++;
    }
    vector<int> answer = {numTranspose, numRemovedZero};
    return answer;
}