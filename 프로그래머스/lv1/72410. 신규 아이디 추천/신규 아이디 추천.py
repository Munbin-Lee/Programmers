import re

def solution(new_id):
    answer = new_id.lower()
    answer = re.sub('[^a-z0-9\-_\.]', '', answer)
    answer = re.sub('\.{2,}', '.', answer)
    answer = re.sub('^\.', '', answer)
    answer = re.sub('\.$', '', answer)
    
    if len(answer) == 0:
        answer = 'aaa'
    elif len(answer) >= 16:
        answer = answer[:15]
        answer = re.sub('\.$', '', answer)
    else:
        while len(answer) <= 2:
            answer += answer[-1]
    return answer