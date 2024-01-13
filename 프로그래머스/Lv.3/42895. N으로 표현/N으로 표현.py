from itertools import product

def solution(N, number):
    memo = [set() for _ in range(8)]
    
    num = 0
    
    for m in memo:
        num = num * 10 + N
        m.add(num)
    
    for i, m in enumerate(memo[:7]):
        if number in m: return i + 1
        
        for j in range(i + 1):
            for a, b in product(memo[j], memo[i - j]):
                for next in (a + b, a - b, a * b):
                    memo[i + 1].add(next)
                
                if b != 0:
                    memo[i + 1].add(a // b)
    
    if number in memo[7]: return 8
    
    return -1