from collections import Counter

def solution(N, stages):
    count = [0] * (N + 2)
    
    for k, v in Counter(stages).items():
        count[k] = v
    
    suffix_sum = count[:]
    
    for i in range(N, 0, -1):
        suffix_sum[i] += suffix_sum[i + 1]
    
    def cmp(x):
        if suffix_sum[x] == 0: return 0
        return - count[x] / suffix_sum[x]
        
    answer = sorted(range(1, N + 1), key = cmp)
    return answer