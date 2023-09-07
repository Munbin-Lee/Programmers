def cmp(a, b):
    return len(a) > len(b)

def solution(s):
    visited = [False for i in range(100001)]
    answer = []
    
    for i in sorted(s[2:-2].split('},{'), key=len):
        for j in map(int, i.split(',')):
            if visited[j]:
                continue
            visited[j] = True
            answer.append(j)
    return answer