INF = 987654321

def solution(k, n, reqs)
    minWaitTime = INF
    (1..k).to_a.repeated_combination(n - k).each do |mentors|
        minWaitTime = [minWaitTime, getWaitTime(mentors, k, reqs)].min
    end
    return minWaitTime
end

def getWaitTime(mentors, k, reqs)
    endTimes = Array.new(k + 1) { Array.new([0]) }
    mentors.each do |type|
        endTimes[type].push(0)
    end
    
    waitTimeSum = 0
    
    reqs.each do |req|
        startTime, duration, type = req
        waitTime = endTimes[type][0] - startTime
        waitTimeSum += [waitTime, 0].max
        endTimes[type][0] += duration + [-waitTime, 0].max
        endTimes[type].sort!
    end
    return waitTimeSum
end