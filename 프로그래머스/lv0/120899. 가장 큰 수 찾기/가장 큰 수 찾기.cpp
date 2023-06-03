#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int max = -1;
    int idx;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > max) {
            max = array[i];
            idx = i;
        }
    }
    return {max, idx};
}