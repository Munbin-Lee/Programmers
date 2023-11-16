#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<bool> isPrime;
unordered_map<int, bool> mp;

void eratos(int maxNum) {
    isPrime.resize(2);
    isPrime.resize(maxNum + 1, true);
    for (int i = 2; i * i <= maxNum; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= maxNum; j += i) {
            isPrime[j] = false;
        }
    }
}

void permute(int visited, string cur, const int maxDepth, const string &base) {
    if (cur.size() == maxDepth) {
        int num = stoi(cur);
        if (isPrime[num]) mp[num] = true;
        return;
    }
    
    for (int i = 0; i < base.size(); i++) {
        if (visited & (1 << i)) continue;
        permute(visited | (1 << i), cur + base[i], maxDepth, base);
    }
}

int solution(string numbers) {
    eratos(9999999);
    for (int i = 1; i <= numbers.size(); i++) {
        permute(0, {}, i, numbers);
    }
    int answer = mp.size();
    return answer;
}