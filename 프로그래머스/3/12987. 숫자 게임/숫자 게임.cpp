#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int answer = 0;
    
    for (int i = 0, j = 0; i < A.size() && j < B.size(); j++) {
        if (A[i] >= B[j]) continue;
        answer++; i++;
    }
    
    return answer;
}