from collections import defaultdict

def solution(edges):
    indegrees = defaultdict(list)
    outdegrees = defaultdict(list)
    
    for begin, end in edges:
        outdegrees[begin].append(end)
        indegrees[end].append(begin)
    
    answer = [0, 0, 0, 0]
    
    for cur in outdegrees.keys():
        if len(indegrees[cur]) == 0 and len(outdegrees[cur]) >= 2:
            answer[0] = cur
            answer[1] = len(outdegrees[cur])
            break
    
    for cur in indegrees.keys():        
        if len(outdegrees[cur]) == 0:
            answer[1] -= 1
            answer[2] += 1
            continue
        
        if len(indegrees[cur]) >= 2 and len(outdegrees[cur]) == 2:
            answer[1] -= 1
            answer[3] += 1
    
    return answer