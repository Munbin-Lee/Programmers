#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    for (int &num : arr) {
        if (k & 1) num *= k;
        else num += k;
    }
    return arr;
}