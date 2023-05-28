#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for (int h = n; h >= 0; h--) {
        if (citations[n - h] >= h) return h;
    }
}