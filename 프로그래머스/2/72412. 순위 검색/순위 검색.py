from collections import defaultdict
from bisect import bisect_left

scores = defaultdict(None)

def save(lang, role, level, food, score):
    if lang not in scores:
        scores[lang] = defaultdict(None)
    if role not in scores[lang]:
        scores[lang][role] = defaultdict(None)
    if level not in scores[lang][role]:
        scores[lang][role][level] = defaultdict(list)
    
    scores[lang][role][level][food].append(score)

def sort(lang = '-', role = '-', level = '-', food = '-'):
    if food == '-':
        for _food in ["chicken", "pizza"]:
            sort(lang, role, level, _food)
    if level == '-':
        for _level in ["junior", "senior"]:
            sort(lang, role, _level, food)
    if role == '-':
        for _role in ["backend", "frontend"]:
            sort(lang, _role, level, food)
    if lang == '-':
        for _lang in ["cpp", "java", "python"]:
            sort(_lang, role, level, food)
        
    try:
        scores[lang][role][level][food].sort()
    except:
        pass

def search(lang, role, level, food, score):
    answer = 0
    if food == '-':
        for _food in ["chicken", "pizza"]:
            answer += search(lang, role, level, _food, score)
        return answer
    if level == '-':
        for _level in ["junior", "senior"]:
            answer += search(lang, role, _level, food, score)
        return answer
    if role == '-':
        for _role in ["backend", "frontend"]:
            answer += search(lang, _role, level, food, score)
        return answer
    if lang == '-':
        for _lang in ["cpp", "java", "python"]:
            answer += search(_lang, role, level, food, score)
        return answer
    
    try:
        ls = scores[lang][role][level][food]
        idx = bisect_left(ls, score)
        return len(ls) - idx
    except:
        return 0

def solution(infoList, queries):
    answer = []
    for info in infoList:
        lang, role, level, food, score = info.split(' ')
        save(lang, role, level, food, int(score))
    sort()
    for query in queries:
        lang, role, level, fs = query.split(" and ")
        food, score = fs.split(' ')
        answer.append(search(lang, role, level, food, int(score)))
    return answer