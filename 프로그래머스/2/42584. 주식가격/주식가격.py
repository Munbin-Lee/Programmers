from heapq import *

def solution(prices):
    n = len(prices)
    heap = []
    answer = [0] * n
    
    for index, price in enumerate(prices):
        answer[index] = n - 1 - index
        
        while heap and -heap[0][0] > price:
            _, pindex = heappop(heap)
            answer[pindex] = index - pindex
        
        heappush(heap, (-price, index))
    
    return answer