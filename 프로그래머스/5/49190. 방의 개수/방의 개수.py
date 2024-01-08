from collections import defaultdict

def solution(arrows):
    dy = (-1, -1, 0, 1, 1, 1, 0, -1)
    dx = (0, 1, 1, 1, 0, -1, -1, -1)
    
    y, x = 0, 0
    answer = 0
    visited = defaultdict(lambda: defaultdict(bool))
    
    for arrow in arrows:
        for _ in range(2):
            ny = y + dy[arrow]
            nx = x + dx[arrow]
            
            if not visited[(ny, nx)]:
                visited[(ny, nx)][(y, x)] = True
                visited[(y, x)][(ny, nx)] = True
                y, x = ny, nx
                continue
            
            if not visited[(ny, nx)][(y, x)]:
                visited[(ny, nx)][(y, x)] = True
                visited[(y, x)][(ny, nx)] = True
                answer += 1
                y, x = ny, nx
                continue
            
            y, x = ny, nx
    
    return answer
                
        
        