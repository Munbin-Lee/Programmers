def solve(babbling):
    i = 0
    prev = ""
    
    while i < len(babbling):
        visited = False
        for word in ("aya", "ye", "woo", "ma"):
            if word == prev: continue
            if not babbling[i:].startswith(word): continue
            visited = True
            i += len(word)
            prev = word
            break
        
        if not visited: return 0
    
    return 1

def solution(babblings):
    answer = 0
    
    for babbling in babblings:
        answer += solve(babbling)
    
    return answer