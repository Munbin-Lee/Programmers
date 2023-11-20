#include <string>
#include <vector>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a < b;
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    const int n = sequence.size();

    vector<int> accum(n+1,0);
    for(int i = 0; i < n; ++i)
    {
        accum[i+1] = accum[i] + sequence[i];
    }

    vector<int> best{n+1,n+1,n+1};
    for(int e = n; e >= 0; --e)
    {
        auto it = lower_bound(accum.begin(),accum.begin() + e, accum[e] - k);
        if( accum[e] - *it == k)
        {
            int s = it - accum.begin();
            const int diff = accum[e] - accum[s];
            if(diff == k)
            {
                if ((e-s < best[0]) || (e-s == best[0] && s < best[1]))
                {
                    best = {e-s,s,e-1};
                }

            }
            else if(diff > k)
            {
                break;
            }
        }
    }

    answer = {best[1],best[2]};

    return answer;
}