def solution(cards):
    def dfs(cur, visited):
        if visited & (1 << cur): return visited
        visited |= (1 << cur)
        next = cards[cur] - 1
        return dfs(next, visited)
    
    def bit_count(x):
        return bin(x).count('1')
    
    answer = 0
    for i in range(len(cards)):
        visited = dfs(i, 0)
        a = bit_count(visited)
        for j in range(len(cards)):
            visited2 = dfs(j, visited)
            b = bit_count(visited2 - visited)
            answer = max(answer, a * b)
    return answer