#include <string>
#include <vector>
#include <stack>

using namespace std;

int required[4] = {1, 3, 2, 1};
stack<int> st;

bool makeHamburger() {
    if (st.size() < 4) return false;
    
    int tops[4];
    for (int& top : tops) {
        top = st.top();
        st.pop();
    }
    
    bool res = true;
    for (int i = 0 ;i < 4; i++) {
        if (tops[i] != required[i]) res = false;
    }
    
    if (!res) {
        for (int i = 3; i >= 0; i--) {
            st.emplace(tops[i]);
        }
    }
    return res;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    for (int i : ingredient) {
        st.emplace(i);
        while (makeHamburger()) {
            answer++;
        }
    }
    return answer;
}