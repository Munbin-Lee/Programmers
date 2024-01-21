#include <string>

using namespace std;

int dfs(int cur) {
    if (cur <= 1) return cur;
    
    return min(dfs(cur / 10) + cur % 10,
              dfs(cur / 10 + 1) + 10 - cur % 10);
}

int solution(int storey) {
    return dfs(storey);
}