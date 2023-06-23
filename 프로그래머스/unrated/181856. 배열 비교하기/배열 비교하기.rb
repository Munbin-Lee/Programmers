def solution(arr1, arr2)
    return (arr1.length <=> arr2.length).nonzero? || arr1.sum <=> arr2.sum
end