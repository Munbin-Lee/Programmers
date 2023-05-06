#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int r = arr.size();
    int c = arr[0].size();
    int size = max(r, c);
    for (auto &i : arr) {
        i.resize(size);
    }
    arr.resize(size, vector<int>(size));
    return arr;
}