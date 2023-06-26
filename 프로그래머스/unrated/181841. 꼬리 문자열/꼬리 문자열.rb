def solution(str_list, ex)
    answer = ""
    for str in str_list
        answer += str if not str.include? ex
    end
    answer
end