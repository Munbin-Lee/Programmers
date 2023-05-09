#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    int maxValue = -1;
    for (int n : array) {
        freq[n]++;
        if (freq[n] > maxFreq) {
            maxFreq = freq[n];
            maxValue = n;
        } else if (freq[n] == maxFreq) {
            maxValue = -1;
        }
    }
    return maxValue;
}