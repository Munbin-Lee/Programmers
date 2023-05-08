#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for (auto& query : queries) {
        int lo = query[0];
        int hi = query[1];
        auto it1 = my_string.begin();
        advance(it1, lo);
        auto it2 = my_string.begin();
        advance(it2, hi + 1);
        reverse(it1, it2);
    }
    return my_string;
}