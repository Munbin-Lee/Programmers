import re
from itertools import permutations

priority = {}

def toPostfix(expression):
    res = []
    stack = []
    for token in re.findall("\d+|[+\-*]", expression):
        if token.isdigit():
            res.append(int(token))
            continue
        while stack and priority[token] <= priority[stack[-1]]:
            res.append(stack.pop())
        stack.append(token)
    while stack:
        res.append(stack.pop())
    return res

def calculate(postfix):
    stack = []
    for token in postfix:
        if (type(token) == int):
            stack.append(token)
            continue
        b, a = stack.pop(), stack.pop()
        dict = {
            '+' : a + b,
            '-' : a - b,
            '*' : a * b,
        }
        stack.append(dict[token])
    return abs(stack[0])

def solution(expression):
    answer = 0
    for p in permutations("+-*"):
        for k, v in enumerate(p):
            priority[v] = k
        postfix = toPostfix(expression)
        answer = max(answer, calculate(postfix))
    return answer