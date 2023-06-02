def solution(numbers):
    ls = {
        "zero" : '0', "one" : '1', "two" : '2', "three" : '3', "four" : '4',
        "five" : '5', "six" : '6', "seven" : '7', "eight" : '8', "nine" : '8'
    }
    
    for k, v in enumerate(ls):
        numbers = numbers.replace(v, str(k));
        
    answer = int(numbers)
    return answer