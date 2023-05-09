#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool cmp(int a, int b) {
    if (abs(n - a) == abs(n - b)) {
        return a > b;
    }
    return abs(n - a) < abs(n - b);
}

vector<int> solution(vector<int> numlist, int _n) {
    n = _n;
    sort(numlist.begin(), numlist.end(), cmp);
    return numlist;
}