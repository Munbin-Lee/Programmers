#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int r = board.size();
    int c = board[0].size();
    
    vector<queue<int>> columns(c);
    
    for (int x = 0; x < c; x++) {
        for (int y = 0; y < r; y++) {
            if (!board[y][x]) continue;
            
            columns[x].emplace(board[y][x]);
        }
    }
    
    stack<int> basket;
    int answer = 0;
    
    for (int move : moves) {
        move--;
        
        if (columns[move].empty()) continue;
        
        int item = columns[move].front();
        columns[move].pop();
        
        if (!basket.empty() && basket.top() == item) {
            basket.pop();
            answer += 2;
            continue;
        }
        
        basket.emplace(item);
    }
    
    return answer;
}