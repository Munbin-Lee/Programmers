def solution(s):
    stack = []
    
    for ch in s:
        if not stack:
            stack.append(ch)
            continue
        
        if ch == stack[-1]:
            stack.pop()
            continue
        
        stack.append(ch)
    
    return int(not stack)