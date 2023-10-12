import heapq

def solution(n, k, enemies):
    # k번째 적까지 힙에 넣음
    q = enemies[:k]
    heapq.heapify(q)
    
    # 나머지 적들을 순회하면서 가장 적은 적은 pop
    for round, enemy in enumerate(enemies[k:]):
        n -= heapq.heappushpop(q, enemy)
        if n < 0:
            return round + k
    
    return len(enemies)