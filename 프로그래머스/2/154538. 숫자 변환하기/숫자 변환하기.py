from collections import deque

def solution(x, y, n):
    deq = deque([[y, 0]])
    
    while deq:
        cur, cnt = deq.popleft()
        
        if cur == x: return cnt
    
        if cur < x: continue
        
        deq.append([cur - n, cnt + 1])
        if cur % 2 == 0: deq.append([cur // 2, cnt + 1])
        if cur % 3 == 0: deq.append([cur // 3, cnt + 1])
        
    return -1