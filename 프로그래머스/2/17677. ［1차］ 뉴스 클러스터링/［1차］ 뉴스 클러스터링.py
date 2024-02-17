def solution(str1, str2):
    from collections import Counter
    
    def make_multiset(s):
        res = []
        for i in range(len(s)-1):
            pair = s[i:i+2]
            if pair.isalpha():                
                res.append(pair.lower())
        return res
    
    s1 = Counter(make_multiset(str1))
    s2 = Counter(make_multiset(str2))
    intersection = sum((s1 & s2).values())
    union = sum((s1 | s2).values())
    
    if union == 0:
        return 65536
    
    return int(intersection / union * 65536)
                
    