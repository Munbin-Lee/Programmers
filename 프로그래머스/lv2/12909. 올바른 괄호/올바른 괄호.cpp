#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (char ch : s) {
        if (ch == '(') {
            st.emplace(ch);
        } else {
            if (st.empty()) return false;
            st.pop();
        }
    }
    bool answer = st.empty();
    return answer;
}