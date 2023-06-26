#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    for (int i = 0; ; i++) {
        bool isModified = false;
        for (int& num : arr) {
            if (num >= 50 && (num & 1) == 0) {
                num /= 2;
                isModified = true;
            } else if (num < 50 && num & 1) {
                num = num * 2 + 1;
                isModified = true;
            }
        }
        if (!isModified) return i;
    }
}