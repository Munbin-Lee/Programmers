#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end());
    int n = targets.size();
    int answer = 0;
    
    int mn = -1;
    int mx = 987654321;
    
    for (int i = 0; i < n;) {
        int tempMx = mx;
        int s = targets[i][0];
        int e = targets[i][1];
        mn = max(mn, s);
        mx = min(mx, e);
        //cout << s << ' '<<e<<" : "<<mn << ' '<<mx<<'\n';
        if (mx - mn <= 0) {
            mn = -1;
            mx = 987654321;
            //cout << tempMx << '\n';
            answer++;
            continue;
        }
        i++;
    }
    return answer+1;
}