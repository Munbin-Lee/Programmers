from collections import deque

def solution(people, limit):
    deq = deque(sorted(people))
    answer = 0
    
    while deq:
        while deq and deq[0] + deq[-1] > limit:
            deq.pop()
            answer += 1
        
        if len(deq) >= 2:
            deq.popleft()
            deq.pop()
            answer += 1
        
        elif len(deq) == 1:
            deq.pop()
            answer += 1
    
    return answer