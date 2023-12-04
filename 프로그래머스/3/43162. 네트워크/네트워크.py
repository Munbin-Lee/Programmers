roots = None

def union(a, b):
    a, b = sorted([find(a), find(b)])
    roots[a] = b

def find(x):
    if roots[x] != x:
        roots[x] = find(roots[x])
    
    return roots[x]

def solution(n, computers):
    global roots
    roots = list(range(n))
    
    for i, row in enumerate(computers):
        for j, connected in enumerate(row):
            if not connected: continue
            union(i, j)
    
    rootDict = {}
    for i in range(n):
        rootDict[find(i)] = True
    
    return len(rootDict)