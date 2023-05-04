#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    for (int i = 0; i < query.size(); i++) {
        int idx = query[i];
        if (i & 1) {
            arr = vector<int> (&arr[idx], &arr[arr.size()]);
        }
        else {
            arr = vector<int> (&arr[0], &arr[idx + 1]);
        }
    }
    return arr;
}