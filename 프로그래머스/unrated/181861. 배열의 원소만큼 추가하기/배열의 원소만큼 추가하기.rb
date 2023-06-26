def solution(arr)
    answer = []
    for num in arr
        answer += [num] * num
    end
    answer
end