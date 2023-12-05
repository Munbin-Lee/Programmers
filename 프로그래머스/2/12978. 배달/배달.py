from heapq import heappop, heappush

INF = 987654321

def solution(N, roads, K):
    paths = [[] for _ in range(N + 1)]
    
    for begin, end, dist in roads:
        paths[begin].append([dist, end])
        paths[end].append([dist, begin])
    
    min_costs = [INF] * (N + 1)
    min_costs[1] = 0
    hq = [[0, 1]]
    
    while hq:
        cost, cur = heappop(hq)
        for ncost, next in paths[cur]:
            ncost += cost
            if ncost >= min_costs[next]: continue
            min_costs[next] = ncost
            heappush(hq, [ncost, next])
    
    answer = 0
    
    for i in range(1, N + 1):
        if min_costs[i] > K: continue
        answer += 1
    
    return answer