from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    visited = [[False] * m for _ in range(n)]
    visited[0][0] = True
    deq = deque([[0, 0, 1]])
    
    while deq:
        cy, cx, dist = deq.popleft()
        if cy == n - 1 and cx == m - 1: return dist
    
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if ny == -1 or ny == n or nx == -1 or nx == m: continue
            if visited[ny][nx]: continue
            if maps[ny][nx] == 0: continue
            visited[ny][nx] = True
            deq.append([ny, nx, dist + 1])
    
    answer = 0
    return -1