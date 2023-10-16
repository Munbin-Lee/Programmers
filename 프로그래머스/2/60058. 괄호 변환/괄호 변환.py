from collections import defaultdict

def solution(p):
    def divide(w):
        cnt = defaultdict(int)
        k = 0
        for k, v in enumerate(w):
            cnt[v] += 1
            if cnt['('] == cnt[')']:
                break
        return w[:k+1], w[k+1:]
    
    def isValid(w):
        stack = []
        for v in w:
            if not stack and v == ')':
                return False
            if v == ')':
                stack.pop()
                continue
            stack.append('(')
        return not stack
    
    def reverse(x):
        return ''.join([chr(ord(i) ^ ord('(') ^ ord(')')) for i in x])
    
    def validate(u, v):
        if isValid(u): return u + convert(v)
        return '(' + convert(v) + ')' + reverse(u[1:-1])
    
    def convert(w):
        if not w: return w
        u, v = divide(w)
        return validate(u, v)
    
    return convert(p)