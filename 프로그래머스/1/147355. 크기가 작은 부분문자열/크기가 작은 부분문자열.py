def solution(t, p):
    answer = 0
    
    for i in range(len(t) - len(p) + 1):
        s = t[i : i + len(p)]
        
        if s <= p:
            answer += 1
    
    return answer;