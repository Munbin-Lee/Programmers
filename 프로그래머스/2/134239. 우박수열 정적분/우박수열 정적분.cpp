#include <vector>

using namespace std;

int graph[10000];
double prefSum[10000];
int sizeGraph = 0;

void collatz(int k) {
    graph[sizeGraph++] = k;
    while (k != 1) {
        if (k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
        graph[sizeGraph++] = k;
    }
}

void calcPrefSum() {
    double sum = 0;
    for (int i = 1; i < sizeGraph; i++) {
        sum += 0.5 * (graph[i] + graph[i-1]);
        prefSum[i] = sum;
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    collatz(k);
    calcPrefSum();
    vector<double> answer;
    answer.reserve(ranges.size());
    
    for (auto &range : ranges) {
        int a = range[0];
        int b = sizeGraph + range[1] - 1;
        if (a > b) {
            answer.emplace_back(-1);
            continue;
        }
        answer.emplace_back(prefSum[b] - prefSum[a]);
    }
    
    return answer;
}