#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> st;

void solve(int len, const vector<int> &elements) {
    for (int i = 0; i < elements.size(); i++) {
        int sum = 0;
        for (int j = i, cnt = 0; cnt < len; j = (j + 1) % elements.size(), cnt++) {
            sum += elements[j];
        }
        st.emplace(sum);
    }
}

int solution(vector<int> elements) {
    for (int i = 0; i < elements.size(); i++) {
        solve(i, elements);
    }
    
    int answer = st.size();
    return answer;
}