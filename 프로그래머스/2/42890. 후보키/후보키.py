from collections import defaultdict
from itertools import combinations

def solution(relations):
    candidates = []
    
    def isUnique(keys):
        for candidate in candidates:
            if all(c in keys for c in candidate):
                return False
        return True
    
    def isCandidate(keys):
        if not isUnique(keys):
            return False
        
        visited = defaultdict(bool)
        for relation in relations:
            s = ""
            for key in keys:
                s += relation[key]
            if visited[s]:
                return False
            visited[s] = True
        
        candidates.append(keys)
        return True
    
    answer = 0
    n = len(relations[0])
    
    for i in range(1, n+1):
        for c in combinations(range(n), i):
            answer += isCandidate(set(c))
    return answer