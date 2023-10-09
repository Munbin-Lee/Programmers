def solution(picks, minerals):
    fatigueTable = [
        [1, 1, 1],
        [5, 1, 1],
        [25, 5, 1]
    ]
    
    mineralDict = {
        'diamond' : 0,
        'iron' : 1,
        'stone' : 2
    }
    
    def parseMineral(mineral):
        return mineralDict[mineral]
    
    def dfs(idx, fatigue, picks, minerals):
        # 모든 광물을 캤을 경우
        
        if idx == len(minerals):
            return fatigue
        
        # 모든 곡괭이를 소모했을 경우
        
        if not sum(picks):
            return fatigue
        
        # 곡괭이 종류별로 DFS
        
        minFatigue = 987654321
        
        for i in range(3):
            if not picks[i]:
                continue
            
            picks[i] -= 1
            
            nextFatigue = fatigue
            for mineral in map(parseMineral, minerals[idx : idx + 5]):
                nextFatigue += fatigueTable[i][mineral]
            
            minFatigue = min(minFatigue, dfs(idx + 5, nextFatigue, picks, minerals))
            
            picks[i] += 1
        
        return minFatigue
            
            
    return dfs(0, 0, picks, minerals)