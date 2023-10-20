import sys
sys.setrecursionlimit(10**5)

dPos = [[-1, 0], [1, 0], [0, -1], [0, 1]]

def solution(maps):
    r = len(maps)
    c = len(maps[0])
    visited = [[cell == 'X' for cell in line] for line in maps]
    answer = []
    
    def dfs(y, x):
        if visited[y][x]: return 0
        visited[y][x] = True
        days = int(maps[y][x])
        for dy, dx in dPos:
            ny = y + dy
            nx = x + dx
            if ny == -1 or ny == r or nx == -1 or nx == c: continue
            days += dfs(ny, nx)
        return days
    
    for i, line in enumerate(maps):
        for j, cell in enumerate(line):
            days = dfs(i, j)
            if days: answer.append(days)
    
    return sorted(answer) or [-1];