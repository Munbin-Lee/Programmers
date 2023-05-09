#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pr;

double getSlope(pr l, vector<vector<int>> &dots) {
    auto [ i1, i2 ] = l;
    auto &p1 = dots[i1];
    auto &p2 = dots[i2];
    int x1 = p1[0];
    int y1 = p1[1];
    int x2 = p2[0];
    int y2 = p2[1];
    return 1.0 * (y1 - y2) / (x1 - x2);
}

bool isParallel(pr l1, pr l2, vector<vector<int>> &dots) {
    double slope1 = getSlope(l1, dots);
    double slope2 = getSlope(l2, dots);
    return abs(slope1 - slope2) < 1e-9;
}

int solution(vector<vector<int>> dots) {
    if (isParallel({0, 1}, {2, 3}, dots)) return 1;
    if (isParallel({0, 2}, {1, 3}, dots)) return 1;
    if (isParallel({0, 3}, {1, 2}, dots)) return 1;
    return 0;
}