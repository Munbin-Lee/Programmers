def solution(n, results):
    indegrees = [[] for _ in range(n + 1)]
    outdegrees = [[] for _ in range(n + 1)]
    
    for winner, loser in results:
        indegrees[loser].append(winner)
        outdegrees[winner].append(loser)
    
    accumulatedIndegrees = [set() for i in range(n + 1)]
    visited = [False] * (n + 1)

    def dfs(x):
        if visited[x]: return accumulatedIndegrees[x].union([x])
        
        visited[x] = True
        
        for indegree in indegrees[x]:
            accumulatedIndegrees[x] = \
                accumulatedIndegrees[x].union(dfs(indegree))
        return accumulatedIndegrees[x].union([x])
    
    for i in range(1, n + 1):
        dfs(i)
    
    accumulatedOutdegrees = [set() for i in range(n + 1)]
    visited = [False] * (n + 1)
    
    def dfs(x):
        if visited[x]: return accumulatedOutdegrees[x].union([x])
        
        visited[x] = True
        
        for outdegree in outdegrees[x]:
            accumulatedOutdegrees[x] = \
                accumulatedOutdegrees[x].union(dfs(outdegree))
        return accumulatedOutdegrees[x].union([x])
    
    for i in range(1, n + 1):
        dfs(i)
        
    answer = 0
    
    for i in range(1, n + 1):
        if len(accumulatedIndegrees[i]) + \
            len(accumulatedOutdegrees[i]) != n - 1: continue
        
        answer += 1
    
    return answer