#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

multiset<int> st;

void processOperation(string& operation) {
    istringstream sin(operation);
    char cmd; int num;
    sin >> cmd >> num;
    
    if (cmd == 'I') {
        st.emplace(num);
    } else if (cmd == 'D' && num == 1) {
        if (st.empty()) return;
        auto it = prev(st.end());
        st.erase(it);
    } else if (cmd == 'D' && num == -1) {
        if (st.empty()) return;
        auto it = st.begin();
        st.erase(it);
    }
}

vector<int> solution(vector<string> operations) {
    for (string& operation : operations) {
        processOperation(operation);
    }
    
    vector<int> answer(2);
    if (st.empty()) return answer;
    
    answer[0] = *st.rbegin();
    answer[1] = *st.begin();
    return answer;
}