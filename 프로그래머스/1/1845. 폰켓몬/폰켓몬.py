def solution(nums): 

    select = len(nums)/2
    types = len(set(nums)) 
    return min(select, types)