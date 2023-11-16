from math import sqrt
from itertools import permutations
from collections import defaultdict

isPrime = []

def calcPrimes():
    global isPrime
    
    maxNum = 9999999
    isPrime = [True] * (maxNum + 1)
    isPrime[0] = isPrime[1] = False
    
    for i in range(2, int(sqrt(maxNum)) + 1):
        if not isPrime[i]: continue
        for j in range(i * i, maxNum + 1, i):
            isPrime[j] = False

def solution(numbers):
    calcPrimes()
    
    visited = defaultdict(bool)
    answer = 0
    
    for i in range(1, len(numbers) + 1):
        for perm in permutations(numbers, i):
            number = int(''.join(perm))
            if visited[number] or not isPrime[number] : continue
            visited[number] = True
            answer += 1
    
    return answer