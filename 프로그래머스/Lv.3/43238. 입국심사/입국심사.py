def solution(n, times):
    lo = 1
    hi = 1e18
    
    def isValid(x):
        cnt = 0
        
        for time in times:
            cnt += x // time
        
        return cnt >= n
    
    while (lo < hi):
        md = (lo + hi) // 2
        
        if isValid(md): hi = md
        else: lo = md + 1
    
    return lo